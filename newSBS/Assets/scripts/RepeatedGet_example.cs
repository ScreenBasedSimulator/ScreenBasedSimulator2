using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using SimpleJSON	;

public class RepeatedGet_example : MonoBehaviour {

	//
	public string IP = "127.0.0.1";
	public int Port = 25001;
//	private Rigidbody rb;
	public string url = "128.237.199.121:8081/unity/status";
//	public Rigidbody projectile;
//	public Text content;
	public int i;
    string dplabel = "start";
    string oxygen_level = "null";

	void Start(){
		StartCoroutine(RepeatedGet());

	}
/*
    void OnGUI()
    {
        string c = "a";
        if (Network.peerType == NetworkPeerType.Disconnected)
        {
            if (GUI.Button(new Rect(100, 100, 300, 25), "heart_rate: "+dplabel))
            {
                //Network.Connect(IP, Port);
            }
            if (GUI.Button(new Rect(100, 125, 300, 25), "oxygen_saturation" + oxygen_level))
            {
                Network.InitializeServer(1, Port, false);
            }
        }
        else
        {
            if (Network.peerType == NetworkPeerType.Client)
            {
                GUI.Label(new Rect(100, 100, 100, 25), "Client");
                if (GUI.Button(new Rect(100, 125, 100, 25), "Logout"))
                {
                    Network.Disconnect(250);
                }
            }
            if (Network.peerType == NetworkPeerType.Server)
            {
                GUI.Label(new Rect(100, 100, 100, 25), "Server");
                GUI.Label(new Rect(100, 125, 100, 25), "Connections: " + Network.connections.Length);

                if (GUI.Button(new Rect(100, 150, 100, 25), "coolGet"))
                {
                    Debug.Log(url);
                    WWW www = new WWW(url);
                    //StartCoroutine(WaitForRequest(www));
                }
                //				StartCoroutine(RepeatedGet());
                //				rb = GetComponent<Rigidbody>()
            }
        }
    }
	*/
    IEnumerator RepeatedGet()
	{
		while (true) {
			Debug.Log ("repeated action:");
			print(url);
			WWW w = new WWW (url);
			yield return w;
			print(Time.time);
			yield return new WaitForSeconds(1);
			print (Time.time);
            if (w.error == null)
            {
                Debug.Log("WWW Ok!: " + w.text);
                var HubResponse = JSON.Parse(w.text);
                Debug.Log("hear rate:" + HubResponse["metricMap"]["heart_rate"].Value);
                dplabel = HubResponse["metricMap"]["heart_rate"].Value;
                oxygen_level = HubResponse["metricMap"]["oxygen_saturation"].Value;

            }
            else
            {
                Debug.Log("error");
                //			content.text = w.text;
            }
		}
	}


}