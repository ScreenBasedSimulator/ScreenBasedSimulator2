//demo_video url: https://youtu.be/F86WbKHpSBo ; https://youtu.be/rpJaWQKK75c
-------------------------------------------------------------------------------
codes below are for controling car
-------------------------------------------------------------------------------
ouusing UnityEngine;
using System.Collections;

public class Car : MonoBehaviour
{
    public GameObject smokeEffect;
    public GameObject fireEffect;
    public GameObject explosionEffect;
    int health;

	// Use this for initialization
	void Start () {

        health = 20;
        smokeEffect.SetActive(false);
        fireEffect.SetActive(false);
        explosionEffect.SetActive(false);

	}

    public void GotShot(){
        health--;
        if (health <= 10)
        {
            smokeEffect.SetActive(true);
        }
        if (health <= 0)
        {
            fireEffect.SetActive(true);
            if (health == 0)
            {
                explosionEffect.SetActive(true);
                this.GetComponent<Rigidbody>().AddForce(this.transform.up * 300);
            }
        }
    }
	
	// Update is called once per frame
	void Update () {
	
	}
}

-------------------------------------------------------------------------------
codes below are for controling shooter
-------------------------------------------------------------------------------
using UnityEngine;
using System.Collections;

public class Shooting : MonoBehaviour {

    public GameObject shootingEffect;
    public AudioClip shootingSound;
    public float Timer;

	// Use this for initialization
	void Start () {
        shootingEffect.SetActive(false);
        Timer = 0;
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetButton("Fire1"))
        {
            Timer += Time.deltaTime;
            if (Timer >= 0.1f)
            {
                Camera.main.GetComponent<AudioSource>().PlayOneShot(shootingSound);
                shootingEffect.SetActive(true);
                RaycastHit hit;

                Ray MonRay = new Ray(Camera.main.transform.position, Camera.main.transform.forward);

                if (Physics.Raycast(MonRay, out hit, 10f))
                {
                    if (hit.collider.gameObject.tag == "Car")
                        hit.collider.SendMessage("GotShot");
                }
            }
        }
        if (Input.GetButtonUp("Fire1")){

            Timer = 0;
            shootingEffect.SetActive(false);

        }
	}
}
