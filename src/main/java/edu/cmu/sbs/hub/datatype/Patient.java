package edu.cmu.sbs.hub.datatype;

import org.apache.commons.lang3.RandomStringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.EnumMap;

public class Patient {

    private static Logger logger = LoggerFactory.getLogger("Patient");

    public final String patientHash;
    public final String name;
    public final Gender gender;
    public final int age;
    public final double weight;
    public final double height;
    private PatientStatus status;

    public Patient(String patientHash, String name, Gender gender, int age, double weight, double height) {
        this.patientHash = patientHash;
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.weight = weight;
        this.height = height;
    }

    public static Patient generateRandomPatient() {
        logger.info("RandomPatient invoked");
        return new Patient(RandomStringUtils.random(8, "qwertyuiopasdfghjklzxcvbnm1234567890"), RandomStringUtils.random(5, "abcdefghijkmon"), Gender.FEMALE, ((int) (Math.random() * 50 + 10)), Math.random() * 50 + 10, Math.random() * 9 + 2);
    }

    public void updateStatus(EnumMap<PatientStatus.Metric, String> metricMap) {
        if (status == null) {
            status = new PatientStatus(metricMap, this);
        }
        status.updateStatus(metricMap);
    }

    public PatientStatus getStatus() {
        if (name.equals("PatientAlpha")) {
            return PatientStatus.getRandomFakeStatus();
        }

        return status;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;

        Patient patient = (Patient) o;

        return patientHash.equals(patient.patientHash);

    }

    @Override
    public int hashCode() {
        return patientHash.hashCode();
    }

    @Override
    public String toString() {
        return "Patient{" +
                "height=" + height +
                ", weight=" + weight +
                ", age=" + age +
                ", gender=" + gender +
                ", name='" + name + '\'' +
                '}';
    }

    public enum Gender {
        FEMALE, MALE
    }

}
