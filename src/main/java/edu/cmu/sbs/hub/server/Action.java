package edu.cmu.sbs.hub.server;

import com.github.kevinsawicki.http.HttpRequest;

public class Action {

    final private static String bioIP = "localhost";
    final private static int bioPort = 23333;
    final private static String bioURL = "/patient/injection";


    public static boolean inject() {
        HttpRequest.post(getURL(bioIP, bioPort, bioURL)).send("{drug_name:'Succinylcholine', dose: 200.0, concentration: 12.0}").code();

        return true;
    }

    private static String getURL(String ip, int port, String url) {
        return "http://" + ip + ":" + port + url;
    }
}
