using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using SimpleJSON	;

public class Getinformation : MonoBehaviour {
	
	//	private Rigidbody rb;
	private string url = "localhost:26666/unity/status";
	private string report_url = "localhost:26666/unity/report";
	//	public Rigidbody projectile;
	//	public Text content;
	public int i;
	public string dplabel = "start";
	string drugname = "Drug Name";
	string dos = "Dosage";
	string heart = "null";
	string oxygen = "null";
	string diastolic_arterialpressure = "null";
	string systolic_arterial_pressure = "null";
	string respiration_rate = "null";
	private string gameStatus = "gaming";
	private bool game_over_sign = false;
	private string game_over = "false"; 

	void Start(){
		StartCoroutine(RepeatedGet());
//		OpenWebpage();
		
	}
	string oxygenStr = "Oxygen Level: ";
	private GUIStyle guiStyle = new GUIStyle();
	void OnGUI () {
		guiStyle.fontSize = 20;
		guiStyle.normal.textColor = Color.white;
		GUI.contentColor = Color.black;

		if (gameStatus == "gaming")
		{
//			GUI.Label(new Rect(10,10,Screen.width,50),"Please input the drugname and dosage");
	//		GUI.Label(new Rect(100, 100, 100, 25), "Client");
			if(GUI.Button(new Rect(10,120,100,30),"Submit"))
			{
				Debug.Log("Submit input to hub");
				StartCoroutine(SendDrug(drugname, dos));
				Debug.Log("FInished Submit input to hub");
			}
			//GUI.Label (new Rect (10,150,160,20), "Anesthesia Machine");

//			if(GUI.Button(new Rect(10,170,100,30),"Turn ON "))
//			{
//				Debug.Log("Turn ON anesthesia machine");
//				StartCoroutine(SendAnesthesiaMachine("on"));
//			}
//			if(GUI.Button(new Rect(110,170,100,30),"Turn OFF"))
//			{
//				Debug.Log("Turn OFF anesthesia machine");
//				StartCoroutine(SendAnesthesiaMachine("off"));
//			}

			// call code
			if(GUI.Button(new Rect(600, 10, 100, 30), "Call Code"))
			{
				Debug.Log ("Call code");
				StartCoroutine(SendCallCode("blue"));
			}

			// Debrief message
			if (GUI.Button (new Rect (600, 40, 100, 30), "Debrief")) 
			{
				Debug.Log ("Debrief");
				gameStatus = "debrief";
				
				// open a url in browser
				Application.OpenURL("http://unity3d.com/");

				// To open a html in unity, we need to parse & render the http response while Unity
				// does not have a built-in HTML parser/renderer
				// There is a HtmlTexturePlugin which depends on Webkit that is available natively in OSX
				// but not Windows
				// Another solution available in Windows:
				// http://labs.awesomium.com/unity3d-integration-tutorial-part-1/
				// See also: http://www.andrewnoske.com/wiki/Unity_-_Web_Interaction
				// Here I d
			}

//			GUI.Label(new Rect(40,200,Screen.width,50),"Patient Status:");
//			GUI.Label(new Rect(40,220,Screen.width,50),oxygenStr,guiStyle);
//			GUI.Label(new Rect(40,240,Screen.width,50),"Heart Rate: "  +  heart,guiStyle);
//			GUI.Label(new Rect(40,260,Screen.width,50),"Arterial Pressure: " + systolic_arterial_pressure + "/" + diastolic_arterialpressure,guiStyle);
//			GUI.Label (new Rect (40, 280, Screen.width, 50), "Respiration Rate: " + respiration_rate,guiStyle);
//			drugname = GUI.TextField(new Rect(60,40,200,30),drugname,15);
//			dos = GUI.TextField(new Rect(60,80,200,30),dos,15);
		}
		if (gameStatus == "debrief") 
		{
//			GUI.Label(new Rect(70,50,40,50),"Score:");
//			GUI.Label(new Rect(110,50,40,50),"100");
//			string debrief = "you did good!\nblablabla\nblabla\n\nblablabla\nbla";
//			GUI.TextField(new Rect(100, 100, 400, 200), debrief, 100);
		}
	}

	IEnumerator RepeatedGet()
	{
		while (true) {
			WWW w = new WWW (url);
			WWW k = new WWW (report_url);
			yield return w;
			yield return new WaitForSeconds(1);
			if (w.error == null)
			{
				var HubResponse = JSON.Parse(w.text);
				dplabel = HubResponse["heart_rate"].Value;
				oxygen = HubResponse["oxygen_saturation"].Value;
				oxygenStr = "Oxygen Level: " + oxygen;
				heart = HubResponse["heart_rate"];
				systolic_arterial_pressure = HubResponse["systolic_arterial_pressure"];
				diastolic_arterialpressure = HubResponse["diastolic_arterialpressure"];
				respiration_rate = HubResponse["respiration_rate"];
				//{"heart_rate":"72","respiration_rate":"16.2651","systolic_arterial_pressure":"106.976","diastolic_arterialpressure":"63.8783","oxygen_saturation":"0.968285"}


				var report_response = JSON.Parse(k.text);  //Game_over Sign
				game_over = report_response ["GameOver"];
				if (game_over.Equals ("true")) {
					game_over_sign = true;
				}

			}
			else
			{
				Debug.Log("error");
				//			content.text = w.text;
			}
		}
	}
	IEnumerator SendDrug(string drugName, string dose){
		Debug.Log(drugName);
		Debug.Log(dose);

		// Create a form object for sending high score data to the server
		WWWForm form = new WWWForm();
		// Assuming the perl script manages high scores for different games
		form.AddField( "drug_name", drugName );
		// The name of the player submitting the scores
		form.AddField( "dose", dose );
		
		// Create a download object
		WWW download = new WWW( "http://localhost:26666/unity/action/inject", form );
		
		// Wait until the download is done
		yield return download;
		
		if(!string.IsNullOrEmpty(download.error)) {
			print( "Error downloading: " + download.error );
		} else {
			// show the highscores
			Debug.Log(download.text);
		}
	}

	IEnumerator SendAnesthesiaMachine(string status) {
		Debug.Log("Adjusting Anesthedia Machine");
		// Create a form object for sending high score data to the server
		WWWForm form = new WWWForm();
		// Assuming the perl script manages high scores for different games
		form.AddField( "status", status);
		
		// Create a download object
		WWW download = new WWW( "http://localhost:26666/unity/action/oxygen", form );
		
		// Wait until the download is done
		yield return download;
		
		if(!string.IsNullOrEmpty(download.error)) {
			print( "Error downloading: " + download.error );
		} else {
			// show the highscores
			Debug.Log(download.text);
		}
	}

	IEnumerator SendCallCode(string code) {
		Debug.Log("Call Code");
		// Create a form object for sending high score data to the server
		WWWForm form = new WWWForm();
		// Assuming the perl script manages high scores for different games
		form.AddField( "code", code);
		
		// Create a download object
		WWW download = new WWW( "http://localhost:26666/unity/action/call_code", form );
		
		// Wait until the download is done
		yield return download;
		
		if(!string.IsNullOrEmpty(download.error)) {
			print( "Error downloading: " + download.error );
		} else {
			// show the highscores
			Debug.Log(download.text);
		}
	}
	



}