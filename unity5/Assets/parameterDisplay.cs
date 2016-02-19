using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using SimpleJSON;

public class parameterDisplay : MonoBehaviour {
	//public callMachine call_machine;
	private Text Heartbeat;
	private Text drug_name;
	private string url = "localhost:26666/unity/status";
	string heart_label = "HeartRate: ";
	public string dplabel = "start";
	string drugname = "Drug Name: ";
	string oxygen_level = "Oxygen Level : ";
	string dos = "Dosage";
	string heart = "null";
	string oxygen = "null";
	string diastolic_arterialpressure = "null";
	string systolic_arterial_pressure = "null";
	string respiration_rate = "null";
	string respiration_rate_name = "Respiration Rate: ";
	string arterial_pressure_name = "Arterial Pressure: ";

	//all signs
	string heart_sign = "";
	string respiration_rate_sign = "";
	string arterial_pressure_sign = "";
	string oxygen_level_sign = "";

	//all flag
	bool hear_rate_flag = false;
	bool respiration_rate_flag = false;
	bool arterial_pressure_flag = false;
	bool oxygen_level_flag = false;




	// Use this for initialization
	void Start () {
		Heartbeat = GetComponent<Text>();
	}

	// Update is called once per frame
	void FixedUpdate()
	{	

		var call_machine = GameObject.FindObjectOfType(typeof(callMachine)) as callMachine;
		hear_rate_flag = call_machine.heart_rate;
		if (hear_rate_flag) {
			heart_sign = heart_label + heart;
		} else {
			heart_sign = "";
		}

		Heartbeat.text =  heart_sign + "\n" + oxygen_level + oxygen +"\n" + 
			arterial_pressure_name + diastolic_arterialpressure +"\n"
			+ respiration_rate_name + respiration_rate ;

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