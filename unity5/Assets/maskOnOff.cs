using UnityEngine;
using System.Collections;

public class maskOnOff : MonoBehaviour {
	bool flag;
	GameObject gameObject;
	// Use this for initialization
	void Start () {
		flag = false;
	}
	
	// Update is called once per frame
	void Update () {
		if(Input.GetButtonDown("putMask")){
			gameObject.GetComponent<Renderer>().enabled = flag;
			flag = flag ? false: true;
		}
	}
}
