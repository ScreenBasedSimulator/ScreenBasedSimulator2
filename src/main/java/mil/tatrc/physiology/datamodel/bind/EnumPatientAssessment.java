//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.2.8-b130911.1802 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2015.12.09 at 06:16:52 PM EST 
//


package mil.tatrc.physiology.datamodel.bind;

import javax.xml.bind.annotation.XmlEnum;
import javax.xml.bind.annotation.XmlEnumValue;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for enumPatientAssessment.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <p>
 * <pre>
 * &lt;simpleType name="enumPatientAssessment">
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string">
 *     &lt;enumeration value="PulmonaryFunctionTest"/>
 *     &lt;enumeration value="CompleteBloodCount"/>
 *     &lt;enumeration value="ComprehensiveMetabolicPanel"/>
 *     &lt;enumeration value="Urinalysis"/>
 *   &lt;/restriction>
 * &lt;/simpleType>
 * </pre>
 * 
 */
@XmlType(name = "enumPatientAssessment")
@XmlEnum
public enum EnumPatientAssessment {

    @XmlEnumValue("PulmonaryFunctionTest")
    PULMONARY_FUNCTION_TEST("PulmonaryFunctionTest"),
    @XmlEnumValue("CompleteBloodCount")
    COMPLETE_BLOOD_COUNT("CompleteBloodCount"),
    @XmlEnumValue("ComprehensiveMetabolicPanel")
    COMPREHENSIVE_METABOLIC_PANEL("ComprehensiveMetabolicPanel"),
    @XmlEnumValue("Urinalysis")
    URINALYSIS("Urinalysis");
    private final String value;

    EnumPatientAssessment(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static EnumPatientAssessment fromValue(String v) {
        for (EnumPatientAssessment c: EnumPatientAssessment.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}