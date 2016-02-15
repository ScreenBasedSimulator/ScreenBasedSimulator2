package edu.cmu.sbs.hub.server;

import com.github.kevinsawicki.http.HttpRequest;

public class Action {

    final private String bioIP = "localhost";
    final private int bioPort = 23333;
    final private String injectionURL = "/patient/injection";
    final private String machineURL = "/anesthesia_machine";

    public Action() {
    }

    public boolean kill() {
        HttpRequest.post(getURL(bioIP, bioPort, injectionURL)).send("{\"drug_name\":\"Succinylcholine\", \"dose\": 200.0, \"concentration\": 12.0}").code();

        return true;
    }

    public boolean revive() {

        // TODO revive

        return true;
    }

    public boolean noOxygen() {
        HttpRequest
        		.post(getURL(bioIP, bioPort, machineURL))
        		.send("{\"oxygen_fraction\":0, \"status\": false}")
        		.code();
        return true;
    }

    public boolean resumeOxygen() {
        HttpRequest
        		.post(getURL(bioIP, bioPort, machineURL))
        		.send("{\"oxygen_fraction\":0.8, \"status\": true}")
        		.code();
        return true;
    }

    public boolean inject(String drugName, Double dose) {
        HttpRequest
    			.post(getURL(bioIP, bioPort, injectionURL))
                .send(String.format("{\"drug_name\":\"%s\", \"dose\": %f, \"concentration\": 200.0}", drugName, dose))
                .code();
    	return true;
    }

    private String getURL(String ip, int port, String url) {
        return "http://" + ip + ":" + port + url;
    }
}
