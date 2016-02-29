using UnityEngine;
using System.Collections;

public class clickPatient : MonoBehaviour {
	private string stringToEdit ="啊你居然点击了病人";
	public GUIText mText;
	public bool isClick;
	//对话标示贴图
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
		Ray mRay=Camera.main.ScreenPointToRay(Input.mousePosition);
		RaycastHit mHi;

		if(Physics.Raycast(mRay,out mHi))
		{

			//如果击中了NPC
			if(mHi.collider.gameObject.tag=="patient")
			{
				//进入对话状态
				Debug.Log("hehe");
				isClick = true;


			}
			else{
				isClick = false;
			}


		}
	}
	

	void OnGUI() {
		if (isClick) {

			GUI.Label (new Rect (500, 100, 300, 100), "what do you want to do!!!!!!!");
			if (GUI.Button(new Rect(500, 150, 100,100), "kill him"))
				Debug.Log("Clicked the button with an image");
		}
	}
}
