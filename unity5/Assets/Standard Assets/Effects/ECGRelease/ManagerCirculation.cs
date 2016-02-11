using UnityEngine;
using System.Collections;

// 	This script works out the voltage output for the heart as the various chambers relax and contract.
//	It also makes the audio beep for every heartbeat which can easily be removed or commented out (found in:= public IEnumerator QRSWave)
//	This voltage is then read from the tracemesh script to plot the Y component of the trace with X being the time.
//
//	To change the heart rate then reduce: intervalP - a 1.0f interval will give you a heartrate of 60 beats per sec which is a default normal resting rate
//	Changing it down to 0.5f will give you a heartrate of 120 which should realistically be considered the top end of what you'd expect to normally reach
//	during periods of stress and exertion. Any rate highter than this will start to break the standard wave form up and you would get merging of the various
//	waves between each heartbeat - it is worth noting that the QRS (the big spike) and the interval to the next rise after that do decrease with higher heartrates
//	but generally the waveform should visualise as a consistent shape across the various heartrates with the variation between the spacing between each waveform.


public class ManagerCirculation : MonoBehaviour {

	//	The sound files that we use

	// public AudioSource
	// public AudioSource

	//	Trigger variables for the stimulation of the nodes which control the pace setting of the hearts electical conduction system
	
	public bool triggerSANode = false; 				// 	Whether we need to stimulate the atria
	private bool triggerAVNode = false; 			// 	Whether we need to stimulate the ventricles
	public bool playSound = true;					//	Whether we have sound with the trace
	public bool stateSystole = false;				//	Whether the heart is working (true) or stopped (false)

	//	Heart voltage values for the formulation of the ECG trace

	public float voltageSum;						// 	Sum voltage measured
	public float voltageSumPrevious;				// 	Last sum voltage recorded
	private float voltageP;							// 	Atrial contraction voltage
	private float voltageQRS;						// 	Ventricular contraction
	private float voltageT;							// 	Ventricular relaxation (repolarisation)
	private float voltageU;							// 	Purkinjee repolarisation
	private float voltageOsborn;					//	Osborn wave

	// Heart timings in millisecs for the various conduction pathways

	public float intervalP = 1.0f;					
	private float durationLeftAtrium;				//	Duration for the electical output from the Left Atrium
	private float durationRightAtrium;				//	Duration for the electrical output from the Right Atrium
	private float durationAcrossAtria;				//	Duration for the transmission from the Right to the Left atrium						
	private float segmentST;

	private float[] intervalArrayP;                	// Array of the last 5 RR intervals from which we determine the heartrate

	private float heartRate = 60.0f;
	public float invertUWave = 2.0f;
	public float addJWave = 0.0f;
	public float patientMovement = 0.0f;		// Amount of patient movement


	void Awake ()
	{
		intervalArrayP = new float[5];
		triggerSANode = false;
		triggerAVNode = false;
	}

	void Start () 
	{
		triggerSANode = true;		// start new heartbeat
	}


	void Update () 
	{
		if (stateSystole)					//	If the heart is stopped then stop all voltage output from all the heart's chambers
		{
			triggerSANode = false;			//	No atrial contraction
			triggerAVNode = false;			//	No ventricular contraction
			voltageP = 0.0f;
			voltageQRS = 0.0f;
			voltageT = 0.0f;
			voltageU = 0.0f;
			voltageOsborn = 0.0f;
		}
		else                                		//	If the heart is not stopped see if we have atrial or ventricular stimulation
		{
			if (triggerSANode)						// Do we need to start a new heartbeat
			{
				StartCoroutine (PWave());			// Trigger Atrial Contraction
				StartCoroutine (PInterval());		// Prepare subsequent beat		
				triggerSANode = false;
			}
			if (triggerAVNode)
			{
				StartCoroutine(QRSWave());
				triggerAVNode = false;
			}
		}
	}


	void FixedUpdate () 		
	{
		voltageSumPrevious = voltageSum;
		voltageSum = voltageP + voltageQRS + voltageT + voltageU + voltageOsborn + (patientMovement *(-0.5f + Random.value)); // total voltage across all chambers	
	}


	public IEnumerator PInterval () // Distance between each P wave therefore setting the heartrate - ie time to next beat
	{
		heartRate = 0.0f;	
		for (var n = 0; n < 4; n++)						
		{
			intervalArrayP[n] = intervalArrayP [n+1];		// We move the last 4 P interval readings and ...
			heartRate += intervalArrayP[n];					// Total all the P intervals
		}
		intervalArrayP[4] = intervalP;						// Add this one to it
		heartRate += intervalArrayP[4];						// Add this one to the total
		heartRate *= 0.2f;									// Divide the total by the number of readings to return the average over the 5 readings
		yield return new WaitForSeconds(intervalP);			// Wait for the next pulse
		triggerSANode = true;								//
	}
	
	
	public IEnumerator PWave ()			// Duration = 0.08 seconds - atrial contraction - relaxation hidden in QRS
	{
		float i = 0.0f;
		
		float rate = 12.5f; // rate for 0.16 secs
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageP = Mathf.SmoothStep(0.0f, 1.5f, i);
			yield return new WaitForFixedUpdate(); 
		}

		i = 0.0f;
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageP = Mathf.SmoothStep(1.5f, 0.0f, i);
			yield return new WaitForFixedUpdate();
		}
		yield return new WaitForSeconds(0.02f); 		// this is effectively the PR segment ie 0.05 to 0.12 secs
		triggerAVNode = true;	
	}
	
	public IEnumerator QRSWave ()			// Duration = 0.08 to 0.12 seconds - ventricular contraction - 0.04 + 0.08 * intervalP clamped between 0.08 and 0.12
	{
		float i = 0.0f;						
			
		float rate; // rate 
		
		float complexTimer;
		
		complexTimer = 0.08f; 				// Could Mathf.Clamp(0.04f + 0.08f * intervalP, 0.08f, 0.12f) but longer time reduceds aesthetic look for simple representation
		rate = 25; 						
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageQRS = Mathf.SmoothStep(0.0f, -1.0f, i);
			yield return new WaitForFixedUpdate();
		}
		
		i = 0.0f;
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageQRS = Mathf.Lerp(-1.0f, 8.0f, i);
			yield return new WaitForFixedUpdate();
		}

		//	The following line plays the audio beep that is played with every heartbeat

		if (playSound)
		{
			this.gameObject.GetComponent<AudioSource>().Play();					//	Delete or comment out this line for no sound
		}

		//	End of audio declaration

		i = 0.0f;
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageQRS = Mathf.Lerp(8.0f, -2.0f, i);
			yield return new WaitForFixedUpdate();
		}
		
		i = 0.0f;
		
		rate = 100.0f;

		StartCoroutine (JWave());

		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageQRS = Mathf.Lerp(-2.0f, 0.0f, i);
			yield return new WaitForFixedUpdate();
		}

		yield return new WaitForSeconds(complexTimer * 0.5f);      // ST segment 0.08 to 0.12
		StartCoroutine (TWave());	
	}
	
	
	public IEnumerator JWave ()
	{
		float i = 0.0f;
		
		float rate = 25.0f; // rate for 0.04 secs
		
		float tempCoreSqrd;
		
		tempCoreSqrd = addJWave * addJWave; 
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageOsborn = Mathf.SmoothStep(0.0f, 6.0f * tempCoreSqrd, i);
			yield return new WaitForFixedUpdate();
		}
		
		i = 0.0f;
		
		rate = 25.0f;
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageOsborn = Mathf.SmoothStep(6.0f * tempCoreSqrd, 0.0f, i);
			yield return new WaitForFixedUpdate();
		}
	}
	
	
	public IEnumerator TWave ()			// Duration = 0.16 seconds - ventricular repolarisation
	{
		float i = 0.0f;
		
		float rate = 6.25f; // rate for 0.16 secs
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageT = Mathf.SmoothStep(0.0f, 2.0f, i);
			yield return new WaitForFixedUpdate();
		}
		
		i = 0.0f;
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageT = Mathf.SmoothStep(2.0f, 0.0f, i);
			yield return new WaitForFixedUpdate();
		}
		StartCoroutine (UWave());
	}
	
	public IEnumerator UWave ()
	{
		float i = 0.0f;
		
		float rate = 25.0f; // rate for 0.08 secs
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageU = Mathf.SmoothStep(0.0f, 2.0f - invertUWave, i);
			yield return new WaitForFixedUpdate();
		}
		
		i = 0.0f;
		
		while (i < 1.0f) 
		{
			i += Time.deltaTime * rate;			
			voltageU = Mathf.SmoothStep(2.0f - invertUWave, 0.0f, i);
			yield return new WaitForFixedUpdate();
		}
	}
}
