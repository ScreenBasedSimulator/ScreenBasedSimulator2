using UnityEngine;
using System.Collections;
using System;
using System.Runtime.InteropServices;
using System.Text;

public class HTMLTexturePlugin : MonoBehaviour
{
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_start( int textID, int width, int height, string url );
	//	creates the offscreen window and webview
	//	url: initial URL to display, use null for none
	//	width, height: currently must be a power of 2 (i.e. 128, 256, 512, 1024) due to my using GL_TEXTURE2D
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_stop();
	// releases all windows and webview; use on quit
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_update ( int texID );
	// makes bitmap of the webview and loads it into openGL with the given texture ID
	
	//
	// browser functions
	//
	// as you'd expect, handles any URL, HTML and CSS that webkit can
	//
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_setURL( int texID, string url);
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_getURL( int texID, StringBuilder url, int stringCapacity);
	// to get the current URL, you need to pass in a StringBuilder and its capacity (to
	// avoid buffer overflow errors)
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_goBack( int texID );
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_goForward( int texID );
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_sendJavascript( int texID, string js);
	// sends a string to the webview's javascript interpreter
	// will return a string result as soon as I get the Marshall class figured out
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_sendJavascript( int texID, string js, StringBuilder result, int stringCapacity);
	// sends a string to the webview's javascript interpreter
	// will return a string result 
	
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_sendKeypress( int texID, string s);
	
	
	//
	// these functions simulate a mouse event in the webview
	//
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_mousemoved( int texID, int _x, int _y );
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_mousedown( int texID,  int _x, int _y );
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_mouseup( int texID, int _x, int _y );
	
	//	[DllImport ("htmlTexture")]
	[DllImport ("__Internal")]
	private static extern void htmlTexture_leftclick( int texID, int _x, int _y );
	// leftclick = a mousemoved, mousedown, and mouseup 
	
	// 
	// End of the plugin interface 
	// 
	
	// Your code goes here!
	public int width =512;
	public int height = 512;
	Texture2D m_Texture = null;
	
	
	void Start() {
		m_Texture = new Texture2D (width, height, TextureFormat.ARGB32, false);
		if (m_Texture == null)
			Debug.Log("Texture error.");
		m_Texture.Apply();
		HTMLTexturePlugin.htmlTexture_start(m_Texture.GetInstanceID(), width, height, "www.google.com");
		// put the texture on something
		if (transform == null)
			Debug.Log("transorm null.");
		if (transform.GetComponent<Renderer>() == null)
			Debug.Log("render null.");
		transform.GetComponent<Renderer>().sharedMaterial.mainTexture = m_Texture;
	}
	
	void Update() {
		HTMLTexturePlugin.htmlTexture_update( m_Texture.GetInstanceID() );
	}
	
	void OnApplicationQuit() {
		HTMLTexturePlugin.htmlTexture_stop();
	}
	
	void OnMouseUp()
	{
		RaycastHit hit;
		if (Physics.Raycast (Camera.main.ScreenPointToRay(Input.mousePosition), out hit))
		{
			int x = width - (int) (hit.textureCoord.x * width); 
			int y = height - (int) (hit.textureCoord.y * height); 
			HTMLTexturePlugin.htmlTexture_mouseup(m_Texture.GetInstanceID(), x, y );
		}
	}
}