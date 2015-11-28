#pragma strict

private var drugname: String;
private var dos : String;


function Start () {
 drugname = " drug name:";
 dos = " dos:";
}

function OnGUI () {
	GUI.Label(Rect(10,10,Screen.width,50),"pls input the drugname and dos");
	if(GUI.Button(Rect(10,120,100,50),"submit"))
	{
	//
	}
	
	drugname = GUI.TextField(Rect(60,40,200,30),drugname,15);
	dos = GUI.TextField(Rect(60,80,200,30),dos,15);
}