using UnityEngine;
using System.Collections;

public class ControlAneStore : MonoBehaviour {

	Animator animator;
	
	// Use this for initialization
	void Start () {
		animator = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey(KeyCode.Return)){
						print("Return on ane store has been pressed");
			animator.SetBool("begin_move", true);
		}
	}
}
