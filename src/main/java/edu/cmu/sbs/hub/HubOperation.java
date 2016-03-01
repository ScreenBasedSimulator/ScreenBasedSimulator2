package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.server.Reception;

public class HubOperation {

    private Kiosk kiosk;
    private Reception server;

    public HubOperation() {
        kiosk = new Kiosk();
        server = new Reception(kiosk);
    }


    public void updatePatientStatus(String patientHash, String HEART_RATE, String RESPIRATION_RATE, String SYSTOLIC_ARTERIAL_PRESSURE, String DIASTOLIC_ARTERIAL_PRESSURE, String OXYGEN_SATURATION) {

    }

    public void updatePatientStatus(String patientHash, double HEART_RATE, double RESPIRATION_RATE, double SYSTOLIC_ARTERIAL_PRESSURE, double DIASTOLIC_ARTERIAL_PRESSURE, double OXYGEN_SATURATION) {
        updatePatientStatus(patientHash, Double.toString(HEART_RATE), Double.toString(RESPIRATION_RATE), Double.toString(SYSTOLIC_ARTERIAL_PRESSURE), Double.toString(DIASTOLIC_ARTERIAL_PRESSURE), Double.toString(OXYGEN_SATURATION));
    }

    public void patientDied(String patientHash) {

    }

    // TODO add more apis
}
