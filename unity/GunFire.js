function Update() {
	if(Input.GetButtonDown("Fire1")) {
		var gunsound : AudioSource = GetComponent.<AudioSource>();
		gunsound.Play();
		GetComponent.<Animation>().Play("GunShot");
	}
}
