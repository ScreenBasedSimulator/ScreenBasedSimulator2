//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.2.8-b130911.1802 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2015.12.09 at 06:16:52 PM EST 
//


package mil.tatrc.physiology.datamodel.bind;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for ExpiratoryValveLeakData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="ExpiratoryValveLeakData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}AnesthesiaMachineActionData">
 *       &lt;sequence>
 *         &lt;element name="Severity" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "ExpiratoryValveLeakData", propOrder = {
    "severity"
})
public class ExpiratoryValveLeakData
    extends AnesthesiaMachineActionData
{

    @XmlElement(name = "Severity", required = true)
    protected ScalarFractionData severity;

    /**
     * Gets the value of the severity property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getSeverity() {
        return severity;
    }

    /**
     * Sets the value of the severity property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setSeverity(ScalarFractionData value) {
        this.severity = value;
    }

}
