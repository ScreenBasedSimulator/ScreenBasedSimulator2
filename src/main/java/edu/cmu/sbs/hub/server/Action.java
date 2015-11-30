package edu.cmu.sbs.hub.server;

import com.github.kevinsawicki.http.HttpRequest;

public class Action {

    final private static String bioIP = "localhost";
    final private static int bioPort = 23333;
    final private static String injectionURL = "/patient/injection";
    final private static String machineURL = "/anesthesia_machine";


    public static boolean kill() {
        HttpRequest.post(getURL(bioIP, bioPort, injectionURL)).send("{drug_name:'Succinylcholine', dose: 200000.0, concentration: 100.0}").code();

        return true;
    }

    public static boolean revive() {

        // TODO revive

        return true;
    }

    public static boolean noOxygen() {
        HttpRequest.post(getURL(bioIP, bioPort, machineURL)).send("{oxygen_fraction:0, status: false}").code();
        return true;
    }

    public static boolean resumeOxygen() {
        HttpRequest.post(getURL(bioIP, bioPort, machineURL)).send("{oxygen_fraction:0.5, status: true}").code();
        return true;
    }

    private static String getURL(String ip, int port, String url) {
        return "http://" + ip + ":" + port + url;
    }
}
