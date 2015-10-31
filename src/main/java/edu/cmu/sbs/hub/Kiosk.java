package edu.cmu.sbs.hub;

import edu.cmu.sbs.protocol.StatusProtocol;

public class Kiosk {

    final private Roster roster;

    public Kiosk() {
        this.roster = new Roster();
    }

    public void receive(StatusProtocol statusProtocol) {
        roster.locatePatient(statusProtocol.getPatientHash()).updateStatus(statusProtocol.toEnumMap());
    }
}
