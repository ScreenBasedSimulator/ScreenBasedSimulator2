package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.datatype.Roster;
import edu.cmu.sbs.protocol.StatusProtocol;

public class Kiosk {

    final private Roster roster;

    public Kiosk() {
        this.roster = new Roster();
    }

    public void receive(StatusProtocol statusProtocol) {
        roster.updatePatientStatus(statusProtocol);

    }
}
