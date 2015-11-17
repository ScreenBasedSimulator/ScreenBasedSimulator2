package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.datatype.Patient;

import java.util.HashMap;

public class Roster {

    private HashMap<String, Patient> patientMap;

    public Roster() {

        this.patientMap = new HashMap<>();

        // Temporarily fix the bug of 'Patient does not exist' by adding a pre-exist patient
        // Should remove this after hub - unity can communicate
        Patient preExistingPatient = new Patient("PreExistingPatientHash", "PreExistingPatientName", Patient.Gender.FEMALE, 22, 100.0, 5.5);
        patientMap.put(preExistingPatient.patientHash, preExistingPatient);

    }

    public Patient locatePatient(String hash) {
        if (patientMap.containsKey(hash)) {
            return patientMap.get(hash);
        } else {
            throw new IllegalArgumentException("Patient \"" + hash + "\" does not exist!");
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
