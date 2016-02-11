using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class displayDynamically : MonoBehaviour {
    private Text Heartbeat;
    string heartrate = "HeartRate: ";
	// Use this for initialization
	void Start () {
        Heartbeat = GetComponent<Text>();
	}
	
	// Update is called once per frame
    void FixedUpdate()
    {
        System.Random rnd = new System.Random();
        Heartbeat.text = heartrate + rnd.Next(60, 80).ToString();
	}
}
