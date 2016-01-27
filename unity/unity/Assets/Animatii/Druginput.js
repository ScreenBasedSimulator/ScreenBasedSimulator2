#pragma strict

public var drugname: String;
public var dos : String;
public var heart : String;
public var oxygen : String;
public var test : String;


//function Start () {
// drugname = " drug name:";
// dos = " dos:";
// heart = "null";
// oxygen = "null";
// 
//}
//
//function OnGUI () {
//	GUI.Label(Rect(10,10,Screen.width,50),"pls input the drugname and dos");
//	if(GUI.Button(Rect(10,120,100,50),"submit"))
//	{
//		
//		oxygen = GameObject.Find("Main Camera").GetComponent(Getinformation).oxygen_level;
//		heart = GameObject.Find("Main Camera").GetComponent(Getinformation).dplabel;
//		
//	// 
//	}
//	GUI.Label(Rect(40,200,Screen.width,50),"patient status:");
//	GUI.Label(Rect(40,220,Screen.width,50),"oxygen_level: " + oxygen);
//	GUI.Label(Rect(40,240,Screen.width,50),"heart_rate: "  +  heart);
//	
//	drugname = GUI.TextField(Rect(60,40,200,30),drugname,15);
//	dos = GUI.TextField(Rect(60,80,200,30),dos,15);
//}