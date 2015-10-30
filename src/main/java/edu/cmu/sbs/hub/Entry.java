package edu.cmu.sbs.hub;

import edu.cmu.sbs.hub.server.HttpServer;

public class Entry {

    public static void main(String[] args) {
        Kiosk kiosk = new Kiosk();
        HttpServer server = new HttpServer(kiosk);
    }
}
