using UnityEngine;
using System.Collections;

public class Menu : MonoBehaviour {

	//
	public string IP = "127.0.0.1";
	public int Port = 25001;
	
	void OnGUI(){
		if (Network.peerType == NetworkPeerType.Disconnected) {
			if (GUI.Button(new Rect(100, 100, 100, 25), "Start Client")){
				Network.Connect(IP, Port);
			}
			if (GUI.Button(new Rect(100, 125, 100, 25), "Start Server")){
				Network.InitializeServer(1, Port, false);
			}
		}
		else{
			if (Network.peerType == NetworkPeerType.Client) {
				GUI.Label(new Rect(100, 100, 100, 25), "Client");
				if (GUI.Button(new Rect(100, 125, 100, 25), "Logout")){
					Network.Disconnect(250);
				}
			}
			if (Network.peerType == NetworkPeerType.Server) {
				GUI.Label(new Rect(100, 100, 100, 25), "Server");
				GUI.Label(new Rect(100, 125, 100, 25), "Connections: " + Network.connections.Length);
				if (GUI.Button(new Rect(100, 150, 100, 25), "coolGet")){
					string url = "http://127.0.0.1:8000/grumblr/";
					WWWForm form = new WWWForm;
					form.AddField("1", "3");
					form.AddField("2", "6");
					WWW www = new WWW(url, form);
					StartCoroutine(WaitForRequest(www));
				}
			}
		}
	}
	
	IEnumerator WaitForRequest(WWW www)
	{
		yield return www;
			// check for errors
		if (www.error == null)
		{
			Debug.Log("WWW Ok!: " + www.text);
		} else {
			Debug.Log("WWW Error: "+ www.error);
		}    
	}    

}
