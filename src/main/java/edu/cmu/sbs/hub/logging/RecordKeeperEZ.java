package edu.cmu.sbs.hub.logging;

import edu.cmu.sbs.hub.datatype.Patient;

import java.util.ArrayList;
import java.util.HashMap;

public class RecordKeeperEZ {

    HashMap<Patient, ArrayList<String>> index = new HashMap<>();

    public RecordKeeperEZ() {
    }

    public void registerPatient(Patient patient) {
        index.put(patient, new ArrayList<>());
    }

    public void log(Patient patient, String action) {
        index.get(patient).add(action);
    }
}
