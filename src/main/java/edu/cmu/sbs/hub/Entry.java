package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.server.Reception;

public class Entry {

    public static void main(String[] args) {
        Kiosk kiosk = new Kiosk();
        Reception server = new Reception(kiosk);
    }
}
