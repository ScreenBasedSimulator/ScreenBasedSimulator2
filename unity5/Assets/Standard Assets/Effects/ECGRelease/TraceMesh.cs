using UnityEngine;
using System.Collections;

public class TraceMesh : MonoBehaviour {

	//	------------------------------------------
	//	-- Declare all the variables we require --
	//  ------------------------------------------

	//	The following variables are used to describe the scripts we need to access to get the values we need to plot

	private ManagerCirculation managerCirculation;

	//	The following variables are used to describe how we draw the trace

	private float traceHeight = 0.25f;
	public int traceWidth = 5;							//	Time the trace runs for before restarting in whole seconds related to traceWidth
	private float traceWidthHalved;						//	Used to offset the trace into the centre
	public float traceLineWidth = 0.005f;				//	the line width we require
	private float tracePlotInterval;					//	The distance between plots per sample on the horizontal axis
	private float traceHeightOffset;					//	Distance to offset the vertices from the given mVolt height sample


	//	The following variables are what we need to plot. They are gained by accessing the scipts detailed above

	private float traceVoltage = 0.0f;					//	Detected mVolts for display
	private float traceLastVoltage = 0.0f;				//	Detected last readings mVolts for display

	//	The following variables are used to describe how we make the trace and the mesh we use to form it ...

	private Mesh mesh;									//	The mesh we draw
	private MeshFilter mf;								//	the meshfilter for the mesh we draw
	private int traceQuadCount;							// 	Total number of quads we are making - needs to be 1 or above
	private int traceVerticesCount;						//	The number of vertices used across the whole trace ie the length of the vertices array
	private int traceTriangleCount;						//	The number of triangles we need to make the trace
	private int traceNormalCount;						//	The number of normals we are using
	private int traceQuadCounter = 0;					//	Used for the purposes of drawing the plots over time
	private Vector3[] traceVertices;					//	Storage: Vertex positions
	private Vector3[] traceNormals;						//	Storage: Vertex normals
	private int[] traceTriangles;						//	Storage: Vertex triangles
	private Color[] traceColors;						//	Storage: Vertex colors
	public float traceColorRed = 0.0f;					//	The Red component of the Color() for the vertices
	public float traceColorGreen = 1.0f;				//	The Green component of the Color() for the vertices
	public float traceColorBlue = 0.0f; 				//	The Blue component of the Color() for the vertices
	
	//	The following variables are used to form the 4 points that will make up each quad from the two amplitude values we get from the physiological scripts

	private float vectorPX;								// 	Used to calculate a vector between the quad start and end points
	private float vectorPY;								//	""
	private float vectorLength;							//	Used to calculate the normal
	private float vectorNX;								//	""
	private float vectorNY;								//	""
	private float P1X;									//	Bottom left X position
	private float P2X;									//	Top left X position
	private float P3X;									//	Bottom right X position
	private float P4X;									//	Top right X position
	private float P1Y;									//	Bottom left Y position
	private float P2Y;									//	Top left Y position
	private float P3Y;									//	Bottom right Y position
	private float P4Y;									//	top right Y position


	//	The following are variables we use for other purposes

	private int index;
	
	//	------------------------------------------------------------------------------------------------------------------------------------------------------------
	//	------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	//	--------------------------
	//	-- Create the functions --
	//	--------------------------

	// Used this for initialization

	void Start () 
	{
		tracePlotInterval = 0.01f; 											//	Note we use 50 samples per second as the physiology engine uses fixed update
		traceHeightOffset = traceLineWidth * 0.5f;							//	Calculate how far we draw the line above and beyond the baseline value per linewidth
		traceWidthHalved = traceWidth * 0.25f;								//	Used to centre the trace on the GameObject

		//mesh = GetComponent<MeshFilter>().mesh;

		CreateMesh();
		managerCirculation = GetComponent<ManagerCirculation>();
		traceQuadCounter = 0;
	}

	
	// Update is called once per frame

	void FixedUpdate () 
	{
		GetTraceValues();
		UpdateMesh();
	}


	//	Create the mesh and the initial quads. Note we don't weld the joins as there is no need with the amount of quads we actually draw in relation to the space we draw them in
	
	void CreateMesh ()
	{
		//	Initialise the mesh 

		mesh = new Mesh();
		mf = GetComponent<MeshFilter>();
		mf.mesh = mesh;

		//	Set up the variables

		traceQuadCount = 50 * traceWidth;					//	How may quads we draw ie 50 per second that the trace cycle runs for
		traceTriangleCount = traceQuadCount * 6;			//	How many triangles we need ie 2 triangles per quad each comprising of 6 vertices
		traceVerticesCount = traceQuadCount * 4; 			//	Each quad needs 4 distinct vertices to describe it's position

		//	Set up the arrays for the mesh (note no UVs are kept as this is a vertex lit mesh where the color is interpolation of the colors of the component triangle points)

		traceVertices = new Vector3[traceVerticesCount];	//	Where we store the vertices of the trace
		traceNormals = new Vector3[traceVerticesCount];		//	Where we store the normals (facing direction) of the vertices for the quads we are making
		traceTriangles = new int[traceTriangleCount];		//	Where we store the triangles that make up the quads we are making
		traceColors = new Color[traceVerticesCount];		//	Where we store the color of the vertices

		//	Assign the initial values to the arrays

		index = 0;

		for (int n = 0; n < traceQuadCount; n++)
		{
			traceVertices[index] = new Vector3((tracePlotInterval * n) - traceWidthHalved, -traceHeightOffset, 0.0f);				// 	Bottom Left	
			traceColors[index] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);										//	""
			traceVertices[index + 1] = new Vector3((tracePlotInterval * n) - traceWidthHalved, traceHeightOffset, 0.0f);			//	Top left
			traceColors[index + 1] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);									//	""
			traceVertices[index + 2] = new Vector3((tracePlotInterval * (n + 1)) - traceWidthHalved,-traceHeightOffset, 0.0f);		//	Bottom Right
			traceColors[index + 2] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);									//	""
			traceVertices[index + 3] = new Vector3((tracePlotInterval * (n + 1)) - traceWidthHalved, traceHeightOffset, 0.0f);		//	Top Right
			traceColors[index + 3] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);									//	""
			index += 4;																												//	Move onto the next quad
		}

		index = 0;

		for (int n = 0; n < traceQuadCount; n++)			//	How the triangles are described:	
		{
			traceTriangles[index] = n * 4;					// 	1 - - - - 3  	ie: 
			traceTriangles[index + 1] = (n * 4) + 1;		// 	| .		  |		left triangle has three points: 0, 1 and 2
			traceTriangles[index + 2] = (n * 4) + 2;		//	|   .	  |		right triangle has three points: 2, 1 and 3
			traceTriangles[index + 3] = (n * 4) + 2;		//	|	  .   |
			traceTriangles[index + 4] = (n * 4) + 1;		//	|	    . |		note:	
			traceTriangles[index + 5] = (n * 4) + 3;		//	0 - - - - 2		we describe these 'clockwise'
			
			index += 6;
		}

		//	Now we need to assign the arrays we have made to the mesh
		
		mesh.vertices = traceVertices;
		mesh.normals = traceNormals;
		mesh.triangles = traceTriangles;
		mesh.colors = traceColors;
	}
	
	
	//	Get the values we need to display
	
	void GetTraceValues ()
	{
		//	Access the values from the appropriate scripts
		
		traceVoltage = managerCirculation.voltageSum;
		traceLastVoltage = managerCirculation.voltageSumPrevious;
		
		//	Scale those values for display
		
		traceVoltage *= 0.1f * traceHeight;
		traceLastVoltage *=	0.1f * traceHeight;
	}
	
	
	//	Update the mesh
	
	void UpdateMesh ()			// TODO; maybe better to take current position - traceQuadCount and then color back from there to the present or similiar
	{
		traceVertices = mesh.vertices;															//	Get the current vertices
		traceColors = mesh.colors;																//	Get the current colours
		
		//	Change the current readings
		
		vectorPX = traceVoltage - traceLastVoltage;												//	Calculate the perpendicular to the vector for the start and end points
		vectorPY = -tracePlotInterval;															//	""
		vectorLength = Mathf.Sqrt((vectorPX * vectorPX) + (vectorPY * vectorPY));				//	Then normalise that vector	
		vectorNX = vectorPX / vectorLength;														//	""
		vectorNY = vectorPY / vectorLength;														//	""
		
		P1X = (tracePlotInterval * traceQuadCounter) + (vectorNX * traceHeightOffset) - traceWidthHalved;			//	Calculate the 4 points for the quad by
		P1Y = (traceLastVoltage) + (vectorNY * traceHeightOffset);													//	adding normalised vector and multiplying
		P2X = (tracePlotInterval * traceQuadCounter) - (vectorNX * traceHeightOffset) - traceWidthHalved;			//	it by half the line width we require.
		P2Y = (traceLastVoltage) - (vectorNY * traceHeightOffset);													//	""
		P3X = (tracePlotInterval * (traceQuadCounter + 1)) + (vectorNX * traceHeightOffset) - traceWidthHalved;		//	""
		P3Y = (traceVoltage) + (vectorNY * traceHeightOffset);														//	""
		P4X = (tracePlotInterval * (traceQuadCounter + 1)) - (vectorNX * traceHeightOffset) - traceWidthHalved;		//	""
		P4Y = (traceVoltage) - (vectorNY * traceHeightOffset);
		
		traceVertices[traceQuadCounter * 4] = new Vector3(P1X, P1Y, 0.0f);						// 	Bottom Left
		traceVertices[traceQuadCounter * 4 + 1] = new Vector3(P2X, P2Y, 0.0f);					//	Top left
		traceVertices[traceQuadCounter * 4 + 2] = new Vector3(P3X, P3Y, 0.0f);					//	Bottom Right
		traceVertices[traceQuadCounter * 4 + 3] = new Vector3(P4X, P4Y, 0.0f);					//	Top Right
		traceColors[traceQuadCounter * 4] = new Color(1, 1, 1, 1);								// 	Bottom Left
		traceColors[traceQuadCounter * 4 + 1] = new Color(1, 1, 1, 1);							//	Top left
		traceColors[traceQuadCounter * 4 + 2] = new Color(1, 1, 1, 1);							//	Bottom Right
		traceColors[traceQuadCounter * 4 + 3] = new Color(1, 1, 1, 1);							//	Top Right
		
		//	Change the color on the previous quad to the standard trace colour
		
		if (traceQuadCounter - 1 < 0)															//	The first drawn quad on the line previous entry is the last drawn quad on the lin
		{
			traceColors[(traceQuadCount - 1) * 4] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
			traceColors[((traceQuadCount - 1) * 4) + 1] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
			traceColors[((traceQuadCount - 1) * 4) + 2] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
			traceColors[((traceQuadCount - 1) * 4) + 3] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
		}
		else                                                                                    //  The other quads don't need this adjustment
		{
			traceColors[(traceQuadCounter - 1) * 4] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
			traceColors[(traceQuadCounter - 1) * 4 + 1] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
			traceColors[(traceQuadCounter - 1) * 4 + 2] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
			traceColors[(traceQuadCounter - 1) * 4 + 3] = new Color(traceColorRed, traceColorGreen, traceColorBlue, 1);
		}

		//	Set up a color gradient on the quads in front of the current reading to show trace fading
		
		index = traceQuadCounter + 1;

		//float fadeConstant  = 1 / (traceWidth * 1);
		
		for (int n = 0; n < traceWidth * 10.0f; n++)												//	We start the fading out "10 multiplied by the cycle duration secs-1" quads ahead
		{
			if (index  + 1 > traceQuadCount)
			{
				index = 0;
			}
			
			float fadeColor = Mathf.Clamp(n * 0.1f - 1.0f, 0.0f, 1.0f);								//	And we fade from our main trace colour towards black

			traceColors[index * 4] = new Color(traceColorRed, traceColorGreen, traceColorBlue, fadeColor);
			traceColors[index * 4 + 1] = new Color(traceColorRed, traceColorGreen, traceColorBlue, fadeColor);
			traceColors[index * 4 + 2] = new Color(traceColorRed, traceColorGreen, traceColorBlue, fadeColor);
			traceColors[index * 4 + 3] = new Color(traceColorRed, traceColorGreen, traceColorBlue, fadeColor);
			
			index ++;
		}
		
		traceQuadCounter ++;
		
		if (traceQuadCounter  + 1 > traceQuadCount)
		{
			traceQuadCounter = 0;
		}
		
		//	Apply all the change data back to the mesh 
		
		mesh.vertices = traceVertices;
		mesh.colors = traceColors;
	}
}


