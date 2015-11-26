using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using SimpleJSON;

public class Menu : MonoBehaviour {
	public string url = "128.237.199.121:8088/unity/status";

	void Start(){
		StartCoroutine(RepeatedGet());
	}

	void OnGUI(){
		if (GUI.Button(new Rect(100, 100, 100, 25), "naloxone, 10")){
			int dose = 10;
			WWWForm form = new WWWForm();
			// csrf token may be needed depending on the hub implementation
//			form.AddField("csrfmiddlewaretoken", "F3eot2lqMZVc2hD6g1xyVkhLDNaQiAe9");
			form.AddField("drug name", "naloxone");
			form.AddField("dose", dose);
			WWW w = new WWW(url, form);
			StartCoroutine (WaitForRequest(w));
		}

	}
	
	IEnumerator WaitForRequest(WWW www)
	{
		yield return www;
		// show response if necessary
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
			var jsonBooks = JSON.Parse(w.text);
			// need to get the hub response format correct
			Debug.Log ("heart rate:" + jsonBooks["metricMap"]["heart_rate"].Value);
		}
	}
}