using UnityEngine;
using System.Collections;

public class ControlNurse : MonoBehaviour {
	
	Animator animator;
	Animator animator2;
	
	// Use this for initialization
	void Start () {
		animator = GetComponent<Animator>();
		animator2 = GameObject.Find ("/Props/Props_Big/AneStore").GetComponent<Animator> ();
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey(KeyCode.Return)){
			//			print("Return has been pressed");
			animator.SetBool("begin_walk", true);
//			print (animator2.avatar);
			animator2.SetBool("begin_move", true);
		}
	}
}
