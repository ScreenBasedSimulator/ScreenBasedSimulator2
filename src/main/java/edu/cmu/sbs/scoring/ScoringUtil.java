package edu.cmu.sbs.scoring;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.PatientStatus;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.HashMap;
import java.util.Map;

/**
 * The class for evaluating patient status
 * @author yifuw
 *
 */
public class ScoringUtil {
	
	public static final double GAME_OVER_THRESHOLD = 50.0d;
	
	private Patient patient;
	private Patient standardPatient;
	private Map<String, Double> weightMap = new HashMap<>();
	private long startTime = System.currentTimeMillis();
	
	public ScoringUtil() {
		//add weight parameters
		weightMap.put("HEART_RATE", 1.0 / 20);
		weightMap.put("SYSTOLIC_ARTERIAL_PRESSURE", 1.0 / 100);
		weightMap.put("DIASTOLIC_ARTERIAL_PRESSURE", 1.0 / 20);
		weightMap.put("OXYGEN_SATURATION", 1.0 / 120);
		weightMap.put("RESPIRATION_RATE", 1.0 / 100);
		
	}

	//testing scoring function
	public static void main(String[] args) throws InterruptedException {
		//set patient status
		ScoringUtil scoringUtil = new ScoringUtil();

		//set model status
//		EnumMap<Metric, String> modelParamMap = new EnumMap<>(Metric.class);
//		modelParamMap.put(PatientStatus.Metric.HEART_RATE, "72.0");
//		modelParamMap.put(PatientStatus.Metric.SYSTOLIC_ARTERIAL_PRESSURE, "64");
//		modelParamMap.put(PatientStatus.Metric.DIASTOLIC_ARTERIAL_PRESSURE, "105");
//		modelParamMap.put(PatientStatus.Metric.OXYGEN_SATURATION, "97");
//		modelParamMap.put(PatientStatus.Metric.RESPIRATION_RATE, "100");
//		Patient patientModel = new Patient("model", "model", Patient.Gender.MALE, 0, 0.0, 0.0);
//		patientModel.updateStatus(modelParamMap);
//		scoringUtil.setModel(patientModel);
		
		
		        
//
//		//set new Patient every second, until game over
//		Patient initialPatient = Patient.generateRandomPatient();
//		initialPatient.updateStatus(PatientStatus.getRandomFakeStatus().getStatus());
//		scoringUtil.setPatient(initialPatient);
//		while (!scoringUtil.isGameOver()) {
//			System.out.println("Score: " + scoringUtil.getScore());
//			Patient randomPatient = Patient.generateRandomPatient();
//			randomPatient.updateStatus(PatientStatus.getRandomFakeStatus().getStatus());
//			scoringUtil.setPatient(randomPatient);
//			Thread.sleep(1000);
//		}

		//print final score
		System.out.println(scoringUtil.getReport());
	}
	
	public Patient getPatient() {
		return patient;
	}

	public void setPatient(Patient patient) {
		this.patient = patient;
	}
	
	public void setStandartPatient(Patient standardPatient) {
	    this.standardPatient = standardPatient;
	    return;
	}
	
	/**
	 * normalize 5 fields of score, and calculate sum of difference
	 * @return sum of normalized difference
	 */
	public double getScore() {
		if (patient == null || standardPatient == null) {
			return 0.0;
		}

		PatientStatus patientStatus =  patient.getStatus();
		PatientStatus goldenStatus = standardPatient.getStatus();
		double sumDifference = 0.0;
		
		sumDifference += (patientStatus.HEART_RATE -goldenStatus.HEART_RATE)* weightMap.get("HEART_RATE");
		sumDifference += (patientStatus.SYSTOLIC_ARTERIAL_PRESSURE -goldenStatus.SYSTOLIC_ARTERIAL_PRESSURE)* weightMap.get("SYSTOLIC_ARTERIAL_PRESSURE");
		sumDifference += (patientStatus.DIASTOLIC_ARTERIAL_PRESSURE -goldenStatus.DIASTOLIC_ARTERIAL_PRESSURE)* weightMap.get("DIASTOLIC_ARTERIAL_PRESSURE");
		sumDifference += (patientStatus.OXYGEN_SATURATION -goldenStatus.OXYGEN_SATURATION)* weightMap.get("OXYGEN_SATURATION");
		sumDifference += (patientStatus.RESPIRATION_RATE -goldenStatus.RESPIRATION_RATE)* weightMap.get("RESPIRATION_RATE");
		
		//return score in 0 - 100 range
	    return (1.0 - sumDifference / 5.0) * 100;
	}
	
	/**
	 * this function returns a boolean value indicates if the game is over
	 * game will over when current score drops below GAME_OVER_THRESHOLD
	 * @return
	 */
	public boolean isGameOver() {
		if(getScore() < GAME_OVER_THRESHOLD) {
			return true;
		}
		return false;
	}
	
	/**
	 * Return text report in json format
	 * @return
	 */
	public String getReport() {
		long endTime = System.currentTimeMillis();
		NumberFormat formatter = new DecimalFormat("#0.00");
		return String.format("{\"GameOver\":\"%s\",\"TotalTime\":\"%s\",\"Score\":\"%f\",\"PatientInfo\":{\"patientHash\":\"%s\",\"name\":\"%s\",\"gender\":\"%s\",\"age\":\"%d\",\"weight\":\"%f\",\"height\":\"%f\"}, \"PatientStatus\":%s}",
				(isGameOver() ? "true" : "false"),
				formatter.format((endTime - startTime) / 1000d),
				getScore(),
				patient.getUUID(),
				patient.name,
				patient.gender,
				patient.age,
				patient.weight,
				patient.height,
				patient.getStatus().toString());
	}
	
}
