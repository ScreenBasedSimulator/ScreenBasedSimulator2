package edu.cmu.sbs.hub.server;

import edu.cmu.sbs.hub.datatype.Patient;

public class Action {
    public static final String KILL = "kill";
    public static final String REVIVE = "revive";
    public static final String OXYGENOFF = "noOxygen";
    public static final String OXYGENON = "resumeOxygen";
    public static final String INJECT = "inject";

    public Action() {
    }

    public static boolean kill(Patient patient) {
        patient.getEngine().bolusDrug("Succinylcholine", 200.0);
        return true;
    }

    public static boolean revive(Patient patient) {

        // TODO revive

        return true;
    }

    public static boolean noOxygen(Patient patient) {
        patient.getEngine().setAnesthesiaMachine("off");
        return true;
    }

    public static boolean resumeOxygen(Patient patient) {
        patient.getEngine().setAnesthesiaMachine("active");
        return true;
    }

    public static boolean inject(Patient patient, String drugName, Double dose) {
        patient.getEngine().bolusDrug(drugName, dose);
        return true;
    }
}
