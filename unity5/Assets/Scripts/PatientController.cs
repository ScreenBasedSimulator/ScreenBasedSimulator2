using UnityEngine;
using System.Collections;

public class PatientController : MonoBehaviour
{
	private string stringToEdit = "啊你居然点击了病人";
	private GUIText mText;
	private bool isClick;
	private string prevText;
	void Start ()
	{
	
	}


	void Update ()
	{
		Ray mRay = Camera.main.ScreenPointToRay (Input.mousePosition);
		RaycastHit mHi;
		if (Physics.Raycast (mRay, out mHi)) {
			if (prevText != mHi.collider.gameObject.tag) {
				prevText = mHi.collider.gameObject.tag;
				Debug.Log (prevText);
			}

			if (mHi.collider.gameObject.tag == "Patient") {
				Debug.Log ("hehe");
				isClick = true;
			} else {
				isClick = false;
			}

		}
	}


	void OnGUI ()
	{
		if (isClick) {

			GUI.Label (new Rect (500, 100, 300, 100), "what do you want to do!!!!!!!");
			if (GUI.Button (new Rect (500, 150, 100, 100), "kill him"))
				Debug.Log ("Clicked the button with an image");
		}
	}
}
