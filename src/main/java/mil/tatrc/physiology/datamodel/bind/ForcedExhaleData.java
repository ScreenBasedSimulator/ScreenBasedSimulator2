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
 * <p>Java class for ForcedExhaleData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="ForcedExhaleData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}ConsciousRespirationCommandData">
 *       &lt;sequence>
 *         &lt;element name="ExpiratoryReserveVolumeFraction" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="Period" type="{uri:/mil/tatrc/physiology/datamodel}ScalarTimeData"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "ForcedExhaleData", propOrder = {
    "expiratoryReserveVolumeFraction",
    "period"
})
public class ForcedExhaleData
    extends ConsciousRespirationCommandData
{

    @XmlElement(name = "ExpiratoryReserveVolumeFraction", required = true)
    protected ScalarFractionData expiratoryReserveVolumeFraction;
    @XmlElement(name = "Period", required = true)
    protected ScalarTimeData period;

    /**
     * Gets the value of the expiratoryReserveVolumeFraction property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getExpiratoryReserveVolumeFraction() {
        return expiratoryReserveVolumeFraction;
    }

    /**
     * Sets the value of the expiratoryReserveVolumeFraction property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setExpiratoryReserveVolumeFraction(ScalarFractionData value) {
        this.expiratoryReserveVolumeFraction = value;
    }

    /**
     * Gets the value of the period property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarTimeData }
     *     
     */
    public ScalarTimeData getPeriod() {
        return period;
    }

    /**
     * Sets the value of the period property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarTimeData }
     *     
     */
    public void setPeriod(ScalarTimeData value) {
        this.period = value;
    }

}
