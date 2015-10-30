package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.datatype.Patient;
import edu.cmu.sbs.hub.datatype.Roster;
import edu.cmu.sbs.protocol.StatusProtocol;


public class Kiosk {

    final private Roster roster;

    public Kiosk() {
        this.roster = new Roster();
    }

    public void receive(StatusProtocol statusProtocol) {
        Patient patient = roster.locatePatient(statusProtocol.statusMap.get("hash"));


    }
}
