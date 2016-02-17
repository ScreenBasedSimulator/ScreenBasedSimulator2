package edu.cmu.sbs.hub.server;

import edu.cmu.sbs.biogears.PatientSimulator;

public class Action {
    private final PatientSimulator m_patient = new PatientSimulator();

    public Action() {
    }

    public boolean kill() {
        m_patient.bolusDrug("Succinylcholine", 200.0);
        return true;
    }

    public boolean revive() {

        // TODO revive

        return true;
    }

    public boolean noOxygen() {
        m_patient.setAnesthesiaMachine("off");
        return true;
    }

    public boolean resumeOxygen() {
        m_patient.setAnesthesiaMachine("active");
        return true;
    }

    public boolean inject(String drugName, Double dose) {
        m_patient.bolusDrug(drugName, dose);
        return true;
    }
}
