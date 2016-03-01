package edu.cmu.sbs.hub.obsolete;

import com.google.gson.Gson;

public class Injection {

    private static Gson gson = new Gson();

    private String drugName;
    private double dose;
    private double concentration;

    public Injection(String drugName, double dose, double concentration) {
        this.drugName = drugName;
        this.dose = dose;
        this.concentration = concentration;
    }

    public static void main(String[] args) {
        Injection injection = new Injection("1231231", 120.0, 200.0);
        System.out.println(injection);
    }

    // TODO fix to comply Biogears protocol
    @Override
    public String toString() {
        return gson.toJson(this);
    }
}
