using UnityEngine;
using System.Collections;
using UnityEngine.UI;
using SimpleJSON	;
using UnityEngine;
using UnityEditor;

public class Monitor : MonoBehaviour {

	// Use this for initialization
	bool gui_switch = false;
	public  bool windowSwitch= false;
	public bool heart_rate = false;
	private Rect windowRect = new Rect(200, 80, 200, 100);
	public float interact_distance = 5f;
	void Start () {
		GameObject.Find ("Parameter_Text").transform.localScale = new Vector3(0, 0, 0);
	}
		
	void OnMouseDown() {
		GameObject.Find ("Parameter_Text").transform.localScale = new Vector3 (0.1f, 0.1f, 0.1f);
		gui_switch = true;
		windowSwitch = true;
	
	}
	static void CreateWizard () {
		Transform[] transforms = Selection.GetTransforms(SelectionMode.Deep |
			SelectionMode.ExcludePrefab | SelectionMode.Editable);

		if (transforms.Length > 0 &&
			EditorUtility.DisplayDialog("Question",
				"Do you want to connect All Equipments?","Connect 2", "Connect 3")) {
			foreach (Transform transform in transforms) {
				RaycastHit hit;
				if (Physics.Raycast(transform.position, -Vector3.up, out hit)) {
					transform.position = hit.point;
					Vector3 randomized = Random.onUnitSphere;
					randomized = new Vector3(randomized.x, 0F, randomized.z);
					transform.rotation = Quaternion.LookRotation(randomized, hit.normal);
				}
			}
		}
	}
	void OnGUI(){
		GUI.enabled = gui_switch;
		GUI.Label (new Rect (10,150,160,20), "Heart rate Switch");

		if (windowSwitch == true){
			windowRect = GUI.Window(0, windowRect, WindowContain, "Heart Rate Switch");
		}
	}
	public void WindowContain( int windowID)
	{	
		if (GUI.Button(new Rect(40, 40, 40, 20), "on"))
		{	
			heart_rate = true;
		}
		if (GUI.Button(new Rect(90, 40, 40, 20), "off"))
		{	
			heart_rate = false;
		}
		if (GUI.Button(new Rect(65, 70, 40, 20), "close"))
		{	
			windowSwitch = false;
		}
	}

}
