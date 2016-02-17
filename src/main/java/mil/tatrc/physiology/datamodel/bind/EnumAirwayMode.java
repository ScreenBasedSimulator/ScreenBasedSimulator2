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
 * <p>Java class for enumAirwayMode.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * <p>
 * <pre>
 * &lt;simpleType name="enumAirwayMode">
 *   &lt;restriction base="{http://www.w3.org/2001/XMLSchema}string">
 *     &lt;enumeration value="Free"/>
 *     &lt;enumeration value="Mask"/>
 *     &lt;enumeration value="Tube"/>
 *   &lt;/restriction>
 * &lt;/simpleType>
 * </pre>
 * 
 */
@XmlType(name = "enumAirwayMode")
@XmlEnum
public enum EnumAirwayMode {

    @XmlEnumValue("Free")
    FREE("Free"),
    @XmlEnumValue("Mask")
    MASK("Mask"),
    @XmlEnumValue("Tube")
    TUBE("Tube");
    private final String value;

    EnumAirwayMode(String v) {
        value = v;
    }

    public String value() {
        return value;
    }

    public static EnumAirwayMode fromValue(String v) {
        for (EnumAirwayMode c: EnumAirwayMode.values()) {
            if (c.value.equals(v)) {
                return c;
            }
        }
        throw new IllegalArgumentException(v);
    }

}
