using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using SimpleJSON;

public class parameterDisplay : MonoBehaviour {
	private Text Heartbeat;
	private Text drug_name;
	private string url = "localhost:26666/unity/status";
	string heart_label = "HeartRate: ";
	public string dplabel = "start";
	string drugname = "Drug Name";
	string dos = "Dosage";
	string heart = "null";
	string oxygen = "null";
	string diastolic_arterialpressure = "null";
	string systolic_arterial_pressure = "null";
	string respiration_rate = "null";

	// Use this for initialization
	void Start () {
		Heartbeat = GetComponent<Text>();
		drug_name = GetComponent<Text>();
	}

	// Update is called once per frame
	void FixedUpdate()
	{
//		System.Random rnd = new System.Random();
		Heartbeat.text = heart_label + heart +"\n";
//		drug_name.text = drugname;
	}

	IEnumerator RepeatedGet()
	{
		while (true) {
			WWW w = new WWW (url);
			yield return w;
			yield return new WaitForSeconds(1);
			if (w.error == null)
			{
				var HubResponse = JSON.Parse(w.text);
				dplabel = HubResponse["heart_rate"].Value;
				oxygen = HubResponse["oxygen_saturation"].Value;
//				oxygenStr = "Oxygen Level: " + oxygen;
				heart = HubResponse["heart_rate"];
				systolic_arterial_pressure = HubResponse["systolic_arterial_pressure"];
				diastolic_arterialpressure = HubResponse["diastolic_arterialpressure"];
				respiration_rate = HubResponse["respiration_rate"];
				//{"heart_rate":"72","respiration_rate":"16.2651","systolic_arterial_pressure":"106.976","diastolic_arterialpressure":"63.8783","oxygen_saturation":"0.968285"}
			}
			else
			{
				Debug.Log("error");
				//			content.text = w.text;
			}
		}
	}
}