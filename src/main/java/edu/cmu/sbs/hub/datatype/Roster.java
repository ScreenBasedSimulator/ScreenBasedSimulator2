package edu.cmu.sbs.hub.datatype;

import java.util.HashMap;

public class Roster {

    private HashMap<String, Patient> patientMap;

    public Roster() {
        this.patientMap = new HashMap<>();
    }

    public Patient locatePatient(String hash) {
        if (patientMap.containsKey(hash)) {
            return patientMap.get(hash);
        } else {
            throw new IllegalArgumentException("Patient does not exist!");
        }
    }

    public void checkInPatient(Patient patient) {
         if (patientMap.containsKey(patient.patientHash)) {
             patientMap.put(patient.patientHash, patient);
         } else {
             throw new IllegalArgumentException("Patient Already Exist!");
         }
    }
}
