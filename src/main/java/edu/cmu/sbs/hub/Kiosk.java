package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.Patient.PatientBuilder;
import edu.cmu.sbs.hub.datatype.exception.IllegalProtocol;
import edu.cmu.sbs.hub.datatype.exception.PatientNotFoundException;

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

    public Patient locatePatient(String hash) throws PatientNotFoundException {
        return roster.locatePatient(hash);
    }

    public Patient createPatient(String request) throws IllegalProtocol {
        PatientBuilder builder = new PatientBuilder();
        Patient patient = builder.build();
        roster.checkInPatient(patient);
        return patient;
    }

    // TODO complete parse Patient from request string
    @Deprecated
    private Patient parsePatient(String request) throws IllegalProtocol {
        return Patient.generateRandomPatient();
    }
}
