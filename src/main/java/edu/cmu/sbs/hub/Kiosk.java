package edu.cmu.sbs.hub;

import java.util.NoSuchElementException;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.Patient.PatientBuilder;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Kiosk {

    final public Roster roster;
    private Logger logger = LoggerFactory.getLogger("Kiosk");

    public Kiosk() {
        this.roster = new Roster();
    }

    //public void receive(StatusProtocol statusProtocol) throws PatientNotFoundException {
    //    roster.locatePatient(statusProtocol.getPatientHash()).updateStatus(statusProtocol.toEnumMap());
    //}

    public Patient locatePatient(String hash) throws NoSuchElementException {
        return roster.locatePatient(hash);
    }

    public Patient createPatient(String request) {
        PatientBuilder builder = new PatientBuilder();
        Patient patient = builder.build();
        roster.checkInPatient(patient);
        return patient;
    }

    // TODO complete parse Patient from request string
    @Deprecated
    private Patient parsePatient(String request) {
        return Patient.generateRandomPatient();
    }
}
