package edu.cmu.sbs.hub.datatype;

import com.google.gson.Gson;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class PatientStatus {
    public final double HEART_RATE;
    public final double SYSTOLIC_ARTERIAL_PRESSURE;
    public final double DIASTOLIC_ARTERIAL_PRESSURE;
    public final double OXYGEN_SATURATION;
    public final double RESPIRATION_RATE;
    
    private static Gson gson = new Gson();
    public static class PatientStatusBuilder {
        private double heartRate = 72;
        private double systolicArterialPressure = 64;
        private double diastolicArterialPressure = 105;
        private double oxygenSaturation = 97;
        private double respirationRate = 100;
        public PatientStatusBuilder setHeartRate(double heartRate) {
            this.heartRate = heartRate;
            return this;
        }
        public PatientStatusBuilder setSystolicArterialPressure(double systolicArterialPressure) {
            this.systolicArterialPressure = systolicArterialPressure;
            return this;
        }
        public PatientStatusBuilder setDiastolicArterialPressure(double diastolicArterialPressure) {
            this.diastolicArterialPressure = diastolicArterialPressure;
            return this;
        }
        public PatientStatusBuilder setOxygenSaturation(double oxygenSaturation) {
            this.oxygenSaturation = oxygenSaturation;
            return this;
        }
        public PatientStatusBuilder setRespirationRate(double respirationRate) {
            this.respirationRate = respirationRate;
            return this;
        }
        public PatientStatus build() {
            return new PatientStatus(heartRate, systolicArterialPressure,
                    diastolicArterialPressure, oxygenSaturation, respirationRate);
        }
    }
    private static Logger logger = LoggerFactory.getLogger("PatientStatus");


    private PatientStatus(double heartRate, double systolicArterialPressure,
            double diastolicArterialPressure, double oxygenSaturation, double respirationRate) {
        this.HEART_RATE = heartRate;
        this.SYSTOLIC_ARTERIAL_PRESSURE = systolicArterialPressure;
        this.DIASTOLIC_ARTERIAL_PRESSURE = diastolicArterialPressure;
        this.OXYGEN_SATURATION = oxygenSaturation;
        this.RESPIRATION_RATE = respirationRate;
    }

    public static PatientStatus getRandomFakeStatus() {
        logger.info("RandomFakeStatus invoked");
        PatientStatusBuilder builder= new PatientStatusBuilder();
        
        return builder.setHeartRate(50 + 20 * Math.random())
               .setSystolicArterialPressure(50 + 20 * Math.random())
               .setDiastolicArterialPressure(Math.random() * 20 + 100)
               .setOxygenSaturation(Math.random() * 50+50)
               .setRespirationRate(60.0 + Math.random() * 20)
               .build();
    }
    
    public static void main(String[] args) {
        for (int i = 0; i < 20; i++) {
            getRandomFakeStatus();
        }
    }


    @Override
    public String toString() {
        return gson.toJson(this);
    }
}
