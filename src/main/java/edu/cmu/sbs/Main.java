package edu.cmu.sbs;

import edu.cmu.sbs.hub.Kiosk;
import edu.cmu.sbs.hub.server.Reception;

public class Main {

    public static void main(String[] args) {
        Kiosk kiosk = new Kiosk();
        Reception server = new Reception(kiosk);
    }
}
