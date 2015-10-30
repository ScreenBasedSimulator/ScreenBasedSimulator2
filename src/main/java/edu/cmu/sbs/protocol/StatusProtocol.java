package edu.cmu.sbs.protocol;

import edu.cmu.sbs.hub.datatype.PatientStatus;

import java.util.EnumMap;
import java.util.HashMap;
import java.util.Map;

public class StatusProtocol {

    /**
     * Protocal Example:
     *
     * Key Name        |Value         |Specification
     * ----------------|--------------|---------
     * hash  (Required)|sykwrvmb      |Unique hash ID for a specific patient
     * heartrate       |66.03         |double value round to two decimal places
     * resprate        |75.48         |double value round to two decimal places
     * systolicbp      |37.99         |double value round to two decimal places
     * diastolicbp     |120.91        |double value round to two decimal places
     * oxygen          |93.60         |double value round to two decimal places
     *
     * Specification:
     * > up to six key-values are transferred each time;
     * > NOT order-sensitive;
     * > Only hash key is required
     *
     * */

    public Map<String, String> statusMap;

    public boolean validate() {

        // TODO statusMap validation. check if the status comply specification

        return false;
    }

    public EnumMap<PatientStatus.Metric, String> toEnumMap() {
        EnumMap<PatientStatus.Metric, String> enumMap = new EnumMap<>(PatientStatus.Metric.class);
        for (String key : statusMap.keySet()) {
            try {
                enumMap.put(PatientStatus.Metric.valueOf(key.toUpperCase()), statusMap.get(key));
            } catch (IllegalArgumentException e) {
                e.printStackTrace();
            }
        }

        return enumMap;
    }
}
