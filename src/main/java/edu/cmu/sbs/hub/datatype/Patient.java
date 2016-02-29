package edu.cmu.sbs.hub.datatype;

import edu.cmu.sbs.biogears.PatientSimulator;
import org.apache.commons.lang3.RandomStringUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Patient {

    private static Logger logger = LoggerFactory.getLogger("Patient");

    public final String patientHash;
    public final String name;
    public final Gender gender;
    public final int age;
    public final double weight;
    public final double height;
    private final PatientSimulator patientBioEngine;
    private PatientStatus status;
    private boolean alive = true;

    public static class PatientBuilder {
        private String name = "John Doe";
        private Gender gender = Gender.MALE;
        private int age = 40;
        private double weight;
        private double height;
        private boolean isStatic = false;
        public PatientBuilder setName(String name) {
            this.name = name;
            return this;
        }
        public PatientBuilder setGender(Gender gender) {
            this.gender = gender;
            return this;
        }
        public PatientBuilder setAge(int age) {
            this.age = age;
            return this;
        }
        public PatientBuilder setWeight(double weight) {
            this.weight = weight;
            return this;
        }
        public PatientBuilder setHeight(double height) {
            this.height = height;
            return this;
        }
        
        public PatientBuilder isStatic(boolean isStatic) {
            this.isStatic = isStatic;
            return this;
        }
        
        public Patient build() {
            return new Patient(name, gender, age, weight, height, isStatic);
        }
    }
    
    private Patient(String name, Gender gender, int age, double weight, double height, boolean isStatic) {
        this.patientHash = RandomStringUtils.random(8, "qwertyuiopasdfghjklzxcvbnm1234567890");
        this.name = name;
        this.gender = gender;
        this.age = age;
        this.weight = weight;
        this.height = height;
        
        if (!isStatic) {
            patientBioEngine = new PatientSimulator(patientHash);
        } else {
            patientBioEngine = null;
        }
    }

    // TODO poll status from engine
    public void update() {

    }

    public PatientSimulator getEngine() {
        return patientBioEngine;
    }

    public boolean isAlive() {
        return alive;
    }

    public void die() {
        alive = false;
    }

    public PatientStatus getStatus() {
        if (name.equals("PatientAlpha")) {
            return PatientStatus.getRandomFakeStatus();
        }

        return status;
    }

    public void setStatus(PatientStatus status) {
        this.status = status;
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

    public static Patient generateRandomPatient() {
        // TODO Auto-generated method stub
        return null;
    }

}
