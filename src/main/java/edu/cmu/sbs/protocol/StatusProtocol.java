package edu.cmu.sbs.protocol;

import edu.cmu.sbs.hub.datatype.PatientStatus;

import java.net.ProtocolException;
import java.util.EnumMap;
import java.util.Map;

public class StatusProtocol {

    /**
     * Protocal Example:
     *
     * Key Name                        |Value         |Specification
     * --------------------------------|--------------|----------------------------------------
     * hash                  (Required)|sykwrvmb      |Unique hash ID for a specific patient
     * heart_rate                      |66.03         |double value round to two decimal places
     * respiration_rate                |75.48         |double value round to two decimal places
     * systolic_arterial_pressure      |37.99         |double value round to two decimal places
     * diastolic_arterial_pressure     |120.91        |double value round to two decimal places
     * oxygen_saturation               |93.60         |double value round to two decimal places
     *
     * Specifications:
     * > up to six key-values are transferred each time;
     * > NOT order-sensitive;
     * > Only hash key is required
     *
     * */

    public Map<String, String> statusMap;

    /**
     * Validate boolean.
     *
     * @return the boolean
     * @throws ProtocolException the protocol exception
     */
    public boolean validate() throws ProtocolException {

        return true;

        // TODO statusMap validation. check if the status comply with specifications
    }

    public EnumMap<PatientStatus.Metric, String> toEnumMap() {
        try {
            validate();

            EnumMap<PatientStatus.Metric, String> enumMap = new EnumMap<>(PatientStatus.Metric.class);
            for (String key : statusMap.keySet()) {
                enumMap.put(PatientStatus.Metric.valueOf(key.toUpperCase()), statusMap.get(key));
            }
            return enumMap;

        } catch (ProtocolException e) {
            e.printStackTrace();
            return new EnumMap<>(PatientStatus.Metric.class);
        } catch (IllegalArgumentException e) {
            e.printStackTrace();
            return new EnumMap<>(PatientStatus.Metric.class);
        }
    }

    public String getPatientHash() {
        try {
            validate();

            return statusMap.get("hash");
        } catch (ProtocolException e) {
            e.printStackTrace();
            return "";
        }
    }
}
