package edu.cmu.sbs.hub.datatype;

import com.google.gson.Gson;

import java.util.Arrays;
import java.util.EnumMap;
import java.util.Map;

public class PatientStatus {

    private final Patient patient;

    private static Gson gson = new Gson();

    public enum Metric {
        HEARTRATE, RESPRATE, SYSTOLICBP, DIASTOLICBP, OXYGEN;

        @Override
        public String toString() {
            return this.name().toLowerCase();
        }
    }

    Map<Metric, String> metricMap = new EnumMap<>(Metric.class);

    public PatientStatus(EnumMap<Metric, String> metricMap, Patient patient) {
//        validateEnumMap(metricMap);
        this.metricMap = metricMap;
        this.patient = patient;
    }

    public EnumMap<Metric, String> getStatus() {
        return new EnumMap<>(metricMap);
    }

    public void updateStatus(EnumMap<Metric, String> metricMap) {
        for (Metric metric : metricMap.keySet()) {
            this.metricMap.put(metric, metricMap.get(metric));
        }
    }

    public static void validateEnumMap(EnumMap<Metric, String> metricMap) {
        if (metricMap.size() != 4 || metricMap.keySet().containsAll(Arrays.asList(Metric.values()))) {
            throw new IllegalArgumentException("Map is not complete");
        }
    }

    @Override
    public String toString() {
//        StringBuilder sb = new StringBuilder();
//        sb.append("hash").append(",").append(patient.patientHash).append("\n");
//        for (Metric metric : Metric.values()) {
//            sb.append(metric.toString()).append(",").append(metricMap.get(metric)).append("\n");
//        }
//        return sb.toString();
        return gson.toJson(metricMap);
    }

    @Deprecated
    public static PatientStatus getRandomFakeStatus() {
        System.out.println("Test Method invoked " + new Object() {
        }.getClass().getEnclosingMethod().getName());
        EnumMap<Metric, String> metricDoubleMap = new EnumMap<>(Metric.class);
        metricDoubleMap.put(Metric.HEARTRATE, 50 + 20 * Math.random() + "");
        metricDoubleMap.put(Metric.SYSTOLICBP, Math.random() * 100 + "");
        metricDoubleMap.put(Metric.DIASTOLICBP, Math.random() * 20 + 100 + "");
        metricDoubleMap.put(Metric.OXYGEN, Math.random() * 120 + "");
        metricDoubleMap.put(Metric.RESPRATE, 60.0 + Math.random() * 20 + "");
        return new PatientStatus(metricDoubleMap, Patient.generateRandomPatient());
    }

    public static void main(String[] args) {
        for (int i = 0; i < 20; i++) {
            getRandomFakeStatus();
        }
    }
}
