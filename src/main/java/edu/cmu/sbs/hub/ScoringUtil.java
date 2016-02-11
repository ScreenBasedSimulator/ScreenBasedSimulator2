package edu.cmu.sbs.hub;

import java.util.EnumMap;
import java.util.Map;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.PatientStatus;
import edu.cmu.sbs.hub.datatype.Patient.Gender;
import edu.cmu.sbs.hub.datatype.PatientStatus.Metric;

/**
 * The class for evaluating patient status
 * @author yifuw
 *
 */
public class ScoringUtil {
    /**
     * Protocal Example:
     *
     * Key Name                        |Value         |Specification
     * --------------------------------|--------------|----------------------------------------
     * hash                  (Required)|sykwrvmb      |Unique hash ID for a specific patient
     * heart_rate                      |66.03         |double value round to two decimal places
     * respiration_rate                |75.48         |double value round to two decimal places
     * systolic_arterial_pressure      |37.99         |double value round to two decimal places
     * diastolic_arterial_pressure     |120.91        |double value round to two decimal places
     * oxygen_saturation               |93.60         |double value round to two decimal places
     *
     * Specifications:
     * > up to six key-values are transferred each time;
     * > NOT order-sensitive;
     * > Only hash key is required
     *
     * */
	
	private PatientStatus patientStatus;
	private PatientStatus modelStatus;
	private Map<Metric, Double> weightMap = new EnumMap<>(Metric.class);
	
	public ScoringUtil() {
		//add weight parameters
		weightMap.put(PatientStatus.Metric.HEART_RATE, 1.0 / 20);
		weightMap.put(PatientStatus.Metric.SYSTOLIC_ARTERIAL_PRESSURE, 1.0 / 100);
		weightMap.put(PatientStatus.Metric.DIASTOLIC_ARTERIALPRESSURE, 1.0 / 20);
		weightMap.put(PatientStatus.Metric.OXYGEN_SATURATION, 1.0 / 120);
		weightMap.put(PatientStatus.Metric.RESPIRATION_RATE, 1.0 / 100);
	}
	
	public void setCurrentStatus(PatientStatus patientStatus) {
		this.patientStatus = patientStatus;
	}
	
	public void setModelStatus(PatientStatus modelStatus) {
		this.modelStatus = modelStatus;
	}
	
	public PatientStatus getCurrentStatus() {
		return patientStatus;
	}
	
	public PatientStatus getModelStatus() {
		return modelStatus;
	}
	
	/**
	 * normalize 5 fields of score, and calculate sum of difference
	 * @return sum of normalized difference
	 */
	public double getScore() {
		if(patientStatus == null || modelStatus == null) {
			return 0.0;
		}
		
		double sumDifference = 0.0;
		Map<Metric, String> patientStatusMap = patientStatus.getMetricMap();
		Map<Metric, String> modelStatusMap = modelStatus.getMetricMap();
		
		for (Metric metric : modelStatusMap.keySet()) {
			sumDifference += Math.abs(
					Double.valueOf(patientStatusMap.get(metric)) - 
					Double.valueOf(modelStatusMap.get(metric))) * weightMap.get(metric);
			System.out.println(metric.toString() + " " + Math.abs(
					Double.valueOf(patientStatusMap.get(metric)) - 
					Double.valueOf(modelStatusMap.get(metric))) * weightMap.get(metric));
		}		
		//return score in 0 - 100 range
	    return (1.0 - sumDifference / 5.0) * 100;
	}
	
	//test scoring function
	public static void main(String[] args) {
		//set patient status
		ScoringUtil scoringUtil = new ScoringUtil();
		scoringUtil.setCurrentStatus(PatientStatus.getRandomFakeStatus());
		
		//set model status
		EnumMap<Metric, String> modelParamMap = new EnumMap<>(Metric.class);
		modelParamMap.put(PatientStatus.Metric.HEART_RATE, "72.0");
		modelParamMap.put(PatientStatus.Metric.SYSTOLIC_ARTERIAL_PRESSURE, "64");
		modelParamMap.put(PatientStatus.Metric.DIASTOLIC_ARTERIALPRESSURE, "105");
		modelParamMap.put(PatientStatus.Metric.OXYGEN_SATURATION, "97");
		modelParamMap.put(PatientStatus.Metric.RESPIRATION_RATE, "100");
		Patient patientModel = new Patient("model", "model", Patient.Gender.MALE, 0, 0.0, 0.0);
		scoringUtil.setModelStatus(new PatientStatus(modelParamMap, patientModel));
		
		//print final score
		System.out.println("Score: " + scoringUtil.getScore());
	}
	
}
