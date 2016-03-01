using UnityEngine;
using System.Collections;

public class GameController : MonoBehaviour
{

	public GameObject nurse;
	public GameObject aneStore;

	Animator nurseAnimator;
	Animator aneStoreAnimator;
	
	// Use this for initialization
	void Start ()
	{
		nurseAnimator = nurse.GetComponent<Animator> ();
		aneStoreAnimator = aneStore.GetComponent<Animator> ();

		// Hide nurse and aneStore at the beginning
		nurse.transform.localScale = new Vector3 (0, 0, 0);
		aneStore.transform.localScale = new Vector3 (0, 0, 0);
	}
	
	// Update is called once per frame
	void Update ()
	{
		if (Input.GetKey (KeyCode.Return)) {
			// Show the nurse and the aneStore
			nurse.transform.localScale = new Vector3 (1, 1, 1);
			aneStore.transform.localScale = new Vector3 (1, 1, 1);

			nurseAnimator.SetBool ("begin_walk", true);
			aneStoreAnimator.SetBool ("begin_move", true);
		}
	}
}
