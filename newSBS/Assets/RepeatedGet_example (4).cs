using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using SimpleJSON;

public class Menu : MonoBehaviour {

	//
	public string IP = "127.0.0.1";
	public int Port = 25001;
//	private Rigidbody rb;
	public string url = "128.237.199.121:8088/unity/status";
//	public Rigidbody projectile;
//	public Text content;
	public int i;

	void Start(){
		StartCoroutine(RepeatedGet());

	}

	IEnumerator RepeatedGet()
	{
		while (true) {
			Debug.Log ("repeated action:");
			print(url);
			WWW w = new WWW (url);
			yield return w;
			print(Time.time);
			yield return new WaitForSeconds(3);
			print (Time.time);
			if (w.error == null) {
				Debug.Log ("WWW Ok!: " + w.text);
			} else {
				Debug.Log ("WWW Error: " + w.error);
			}    
//			content.text = w.text;
			var jsonBooks = JSON.Parse(w.text);
			Debug.Log ("heart rate:" + jsonBooks["metricMap"]["heart_rate"].Value);
		}
	}


}