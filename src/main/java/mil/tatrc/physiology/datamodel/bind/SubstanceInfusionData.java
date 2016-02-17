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
 * <p>Java class for SubstanceInfusionData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SubstanceInfusionData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}SubstanceAdministrationData">
 *       &lt;sequence>
 *         &lt;element name="Substance" type="{http://www.w3.org/2001/XMLSchema}string"/>
 *         &lt;element name="Concentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData"/>
 *         &lt;element name="Rate" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumePerTimeData"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SubstanceInfusionData", propOrder = {
    "substance",
    "concentration",
    "rate"
})
public class SubstanceInfusionData
    extends SubstanceAdministrationData
{

    @XmlElement(name = "Substance", required = true)
    protected String substance;
    @XmlElement(name = "Concentration", required = true)
    protected ScalarMassPerVolumeData concentration;
    @XmlElement(name = "Rate", required = true)
    protected ScalarVolumePerTimeData rate;

    /**
     * Gets the value of the substance property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSubstance() {
        return substance;
    }

    /**
     * Sets the value of the substance property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSubstance(String value) {
        this.substance = value;
    }

    /**
     * Gets the value of the concentration property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getConcentration() {
        return concentration;
    }

    /**
     * Sets the value of the concentration property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setConcentration(ScalarMassPerVolumeData value) {
        this.concentration = value;
    }

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

}
