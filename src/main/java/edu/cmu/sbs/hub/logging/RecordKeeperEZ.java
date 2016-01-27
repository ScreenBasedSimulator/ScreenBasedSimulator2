package edu.cmu.sbs.hub.logging;

import edu.cmu.sbs.hub.datatype.Patient;

import java.util.ArrayList;
import java.util.HashMap;

public class RecordKeeperEZ {

    //reserved for multiple patients implementation
    HashMap<Patient, ArrayList<String>> index = new HashMap<>();
    Patient preExistingPatient = null;

    public RecordKeeperEZ() {
    }

    public void registerPatient(Patient patient) {
        index.put(patient, new ArrayList<>());
        preExistingPatient = patient;
    }

    public void log(String action) {
        index.get(preExistingPatient).add(action);
    }


    //TODO Finish generateReport method
    public String generateReport() {
        StringBuilder sb = new StringBuilder();
        return "";
    }
}
