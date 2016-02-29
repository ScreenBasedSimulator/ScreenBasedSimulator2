using UnityEngine;
using System.Collections;

public class ControlNurse : MonoBehaviour {

	GameObject nurse;
	GameObject aneStore;

	Animator animator;
	Animator animator2;
	
	// Use this for initialization
	void Start () {
		nurse = GameObject.Find("/Characters/Surgeon_C_OR");
		aneStore = GameObject.Find ("/Props/Props_Big/AneStore");

		animator = GetComponent<Animator>();
		animator2 = aneStore.GetComponent<Animator> ();

		nurse.transform.localScale = new Vector3(0, 0, 0);
		aneStore.transform.localScale = new Vector3 (0, 0, 0);
	}
	
	// Update is called once per frame
	void Update () {
		if (Input.GetKey(KeyCode.Return)){
			nurse.transform.localScale = new Vector3(1, 1, 1);
			aneStore.transform.localScale = new Vector3 (1, 1, 1);
			animator.SetBool("begin_walk", true);
			animator2.SetBool("begin_move", true);
		}
	}
}
