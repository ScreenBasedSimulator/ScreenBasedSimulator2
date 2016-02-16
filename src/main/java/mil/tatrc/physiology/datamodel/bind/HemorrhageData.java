//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.2.8-b130911.1802 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2015.12.09 at 06:16:52 PM EST 
//


package mil.tatrc.physiology.datamodel.bind;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for HemorrhageData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="HemorrhageData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}PatientActionData">
 *       &lt;sequence>
 *         &lt;element name="Rate" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumePerTimeData"/>
 *       &lt;/sequence>
 *       &lt;attribute name="Compartment" use="required" type="{uri:/mil/tatrc/physiology/datamodel}enumAnatomy" />
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "HemorrhageData", propOrder = {
    "rate"
})
public class HemorrhageData
    extends PatientActionData
{

    @XmlElement(name = "Rate", required = true)
    protected ScalarVolumePerTimeData rate;
    @XmlAttribute(name = "Compartment", required = true)
    protected EnumAnatomy compartment;

    /**
     * Gets the value of the rate property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public ScalarVolumePerTimeData getRate() {
        return rate;
    }

    /**
     * Sets the value of the rate property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public void setRate(ScalarVolumePerTimeData value) {
        this.rate = value;
    }

    /**
     * Gets the value of the compartment property.
     * 
     * @return
     *     possible object is
     *     {@link EnumAnatomy }
     *     
     */
    public EnumAnatomy getCompartment() {
        return compartment;
    }

    /**
     * Sets the value of the compartment property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumAnatomy }
     *     
     */
    public void setCompartment(EnumAnatomy value) {
        this.compartment = value;
    }

}
