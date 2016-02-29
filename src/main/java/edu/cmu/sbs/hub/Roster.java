package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.exception.PatientNotFoundException;
import edu.cmu.sbs.hub.logging.RecordKeeperEZ;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.HashMap;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

public class Roster {

    final public RecordKeeperEZ recordKeeperEZ = new RecordKeeperEZ();
    final private Logger logger = LoggerFactory.getLogger(this.getClass());
    private HashMap<String, Patient> patientMap;

    public Roster() {
        this.patientMap = new HashMap<>();
        startPollingService();
    }

    private void startPollingService() {
        ScheduledExecutorService executorService = Executors.newSingleThreadScheduledExecutor();
        executorService.scheduleAtFixedRate((Runnable) () -> patientMap.values().forEach(Patient::update), 0, 300, TimeUnit.MILLISECONDS);
    }

    public Patient locatePatient(String hash) throws PatientNotFoundException {
        if (patientMap.containsKey(hash)) {
            return patientMap.get(hash);
        } else {
            logger.error("Patient " + hash + " does not exist!");
            throw new PatientNotFoundException("Patient " + hash + " does not exist!");
        }
    }

    public void checkInPatient(Patient patient) {
        if (patientMap.containsKey(patient.patientHash)) {
            patientMap.put(patient.patientHash, patient);
            recordKeeperEZ.registerPatient(patient);
        } else {
            logger.error("Patient Already checked in");
        }
    }


}
