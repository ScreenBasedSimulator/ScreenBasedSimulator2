using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class Menu : MonoBehaviour {

	//
	public string IP = "127.0.0.1";
	public int Port = 25001;
//	private Rigidbody rb;
	public string url = "http://google.com";
//	public Rigidbody projectile;
//	public Text content;
	public int i;

	void Start(){
		StartCoroutine(RepeatedGet());

	}

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

					WWW www = new WWW(url);
					StartCoroutine(WaitForRequest(www));
				}
//				StartCoroutine(RepeatedGet());
//				rb = GetComponent<Rigidbody>()
			}
		}
	}
	
	IEnumerator WaitForRequest(WWW www)
	{
		yield return www;
		yield return new WaitForSeconds(3);
			// check for errors
		if (www.error == null)
		{
			Debug.Log("WWW Ok!: " + www.text);
		} else {
			Debug.Log("WWW Error: "+ www.error);
		}    
//		content.text = www.text;    
	}    

	IEnumerator RepeatedGet()
	{
		while (true) {
			Debug.Log ("repeated action:");
			string url = "http://google.com";
			WWW w = new WWW (url);
			yield return w;
			print(Time.time);
			yield return new WaitForSeconds (1);
			print (Time.time);
			if (w.error == null) {
				Debug.Log ("WWW Ok!: " + w.text);
			} else {
				Debug.Log ("WWW Error: " + w.error);
			}    
//		content.text = w.text;;
		}
	}
	void Test(){
//		Rigidbody instance = Instantiate(projectile);
//		instance.velocity = Random.insideUnitSphere * 5;
		i++;
		Debug.Log(i);
	}
}
