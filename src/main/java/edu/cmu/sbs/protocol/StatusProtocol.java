package edu.cmu.sbs.protocol;

import java.util.Map;

public class StatusProtocol {

    /**
     * Protocal Example:
     *
     * Key Name       |Value         |Specification
     * ---------------|--------------|---------
     * hash           |sykwrvmb      |Unique hash ID for a specific patient
     * heartrate      |66.03         |double value round to two decimal places
     * resprate       |75.48         |double value round to two decimal places
     * systolicbp     |37.99         |double value round to two decimal places
     * diastolicbp    |120.91        |double value round to two decimal places
     * oxygen         |93.60         |double value round to two decimal places
     *
     * Specification:
     * > up to six key-values are transferred each time;
     * > NOT order-sensitive;
     *
     * */

    private Map<String, String> statusMap;
}
