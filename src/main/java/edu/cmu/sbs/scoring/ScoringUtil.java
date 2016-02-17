package edu.cmu.sbs.hub;

import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.EnumMap;
import java.util.Map;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.PatientStatus;
import edu.cmu.sbs.hub.datatype.PatientStatus.Metric;

/**
 * The class for evaluating patient status
 * @author yifuw
 *
 */
public class ScoringUtil {
	
	public static final double GAME_OVER_THRESHOLD = 50.0d;
	
	private Patient patient;
	private Patient model;
	private Map<Metric, Double> weightMap = new EnumMap<>(Metric.class);
	private long startTime = System.currentTimeMillis();
	
	public ScoringUtil() {
		//add weight parameters
		weightMap.put(PatientStatus.Metric.HEART_RATE, 1.0 / 20);
		weightMap.put(PatientStatus.Metric.SYSTOLIC_ARTERIAL_PRESSURE, 1.0 / 100);
		weightMap.put(PatientStatus.Metric.DIASTOLIC_ARTERIALPRESSURE, 1.0 / 20);
		weightMap.put(PatientStatus.Metric.OXYGEN_SATURATION, 1.0 / 120);
		weightMap.put(PatientStatus.Metric.RESPIRATION_RATE, 1.0 / 100);
	}
	
	public void setPatient(Patient patient) {
		this.patient = patient;
	}
	
	public void setModel(Patient model) {
		this.model = model;
	}
	
	public Patient getPatient() {
		return patient;
	}
	
	public Patient getModel() {
		return model;
	}
	
	/**
	 * normalize 5 fields of score, and calculate sum of difference
	 * @return sum of normalized difference
	 */
	public double getScore() {
		if(patient == null || model == null) {
			return 0.0;
		}
		
		double sumDifference = 0.0;
		Map<Metric, String> patientStatusMap = patient.getStatus().getMetricMap();
		Map<Metric, String> modelStatusMap = model.getStatus().getMetricMap();
		
		for (Metric metric : modelStatusMap.keySet()) {
			sumDifference += Math.abs(
					Double.valueOf(patientStatusMap.get(metric)) - 
					Double.valueOf(modelStatusMap.get(metric))) * weightMap.get(metric);
			/*System.out.println(metric.toString() + " " + Math.abs(
					Double.valueOf(patientStatusMap.get(metric)) - 
					Double.valueOf(modelStatusMap.get(metric))) * weightMap.get(metric));*/
		}		
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
				patient.patientHash,
				patient.name,
				patient.gender,
				patient.age,
				patient.weight,
				patient.height,
				patient.getStatus().toString());
	}
	
	//testing scoring function
	public static void main(String[] args) throws InterruptedException {
		//set patient status
		ScoringUtil scoringUtil = new ScoringUtil();
		
		//set model status
		EnumMap<Metric, String> modelParamMap = new EnumMap<>(Metric.class);
		modelParamMap.put(PatientStatus.Metric.HEART_RATE, "72.0");
		modelParamMap.put(PatientStatus.Metric.SYSTOLIC_ARTERIAL_PRESSURE, "64");
		modelParamMap.put(PatientStatus.Metric.DIASTOLIC_ARTERIALPRESSURE, "105");
		modelParamMap.put(PatientStatus.Metric.OXYGEN_SATURATION, "97");
		modelParamMap.put(PatientStatus.Metric.RESPIRATION_RATE, "100");
		Patient patientModel = new Patient("model", "model", Patient.Gender.MALE, 0, 0.0, 0.0);
		patientModel.updateStatus(modelParamMap);
		scoringUtil.setModel(patientModel);
		
		//set new Patient every second, until game over
		Patient initialPatient = Patient.generateRandomPatient();
		initialPatient.updateStatus(PatientStatus.getRandomFakeStatus().getStatus());
		scoringUtil.setPatient(initialPatient);
		while(!scoringUtil.isGameOver()) {
			System.out.println("Score: " + scoringUtil.getScore());
			Patient randomPatient = Patient.generateRandomPatient();
			randomPatient.updateStatus(PatientStatus.getRandomFakeStatus().getStatus());
			scoringUtil.setPatient(randomPatient);
			Thread.sleep(1000);
		}
		
		//print final score
		System.out.println(scoringUtil.getReport());
	}
	
}
