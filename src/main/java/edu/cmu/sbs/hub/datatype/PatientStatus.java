package edu.cmu.sbs.hub.datatype;

import com.google.gson.Gson;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.EnumMap;
import java.util.Map;

public class PatientStatus {

    private static Gson gson = new Gson();
    private static Logger logger = LoggerFactory.getLogger("PatientStatus");

    private final Patient patient;
    Map<Metric, String> metricMap = new EnumMap<>(Metric.class);

    public PatientStatus(EnumMap<Metric, String> metricMap, Patient patient) {
        //validateEnumMap(metricMap);
        this.metricMap = metricMap;
        this.patient = patient;
    }

    public static PatientStatus getRandomFakeStatus() {
        logger.info("RandomFakeStatus invoked");
        
        EnumMap<Metric, String> metricDoubleMap = new EnumMap<>(Metric.class);
        metricDoubleMap.put(Metric.HEART_RATE, 50 + 20 * Math.random() + "");
        metricDoubleMap.put(Metric.SYSTOLIC_ARTERIAL_PRESSURE, Math.random() * 100 + "");
        metricDoubleMap.put(Metric.DIASTOLIC_ARTERIAL_PRESSURE, Math.random() * 20 + 100 + "");
        metricDoubleMap.put(Metric.OXYGEN_SATURATION, Math.random() * 120 + "");
        metricDoubleMap.put(Metric.RESPIRATION_RATE, 60.0 + Math.random() * 20 + "");
        return new PatientStatus(metricDoubleMap, Patient.generateRandomPatient());
    }

    public static void main(String[] args) {
        for (int i = 0; i < 20; i++) {
            getRandomFakeStatus();
        }
    }

    public EnumMap<Metric, String> getStatus() {
        return new EnumMap<>(metricMap);
    }

    public void updateStatus(EnumMap<Metric, String> metricMap) {
        for (Metric metric : metricMap.keySet()) {
            this.metricMap.put(metric, metricMap.get(metric));
        }
        logger.info(patient + " is successfully updated");
    }

    public Map<Metric, String> getMetricMap() {
        return metricMap;
    }

    @Override
    public String toString() {
        return gson.toJson(metricMap);
    }

    public enum Metric {
        HEART_RATE, RESPIRATION_RATE, SYSTOLIC_ARTERIAL_PRESSURE, DIASTOLIC_ARTERIAL_PRESSURE, OXYGEN_SATURATION;

        @Override
        public String toString() {
            return this.name().toLowerCase();
        }
    }
}
