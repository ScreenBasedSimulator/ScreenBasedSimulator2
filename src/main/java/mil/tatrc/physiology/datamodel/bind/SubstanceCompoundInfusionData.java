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
 * <p>Java class for SubstanceCompoundInfusionData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SubstanceCompoundInfusionData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}SubstanceAdministrationData">
 *       &lt;sequence>
 *         &lt;element name="SubstanceCompound" type="{http://www.w3.org/2001/XMLSchema}string"/>
 *         &lt;element name="BagVolume" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumeData"/>
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
@XmlType(name = "SubstanceCompoundInfusionData", propOrder = {
    "substanceCompound",
    "bagVolume",
    "rate"
})
public class SubstanceCompoundInfusionData
    extends SubstanceAdministrationData
{

    @XmlElement(name = "SubstanceCompound", required = true)
    protected String substanceCompound;
    @XmlElement(name = "BagVolume", required = true)
    protected ScalarVolumeData bagVolume;
    @XmlElement(name = "Rate", required = true)
    protected ScalarVolumePerTimeData rate;

    /**
     * Gets the value of the substanceCompound property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getSubstanceCompound() {
        return substanceCompound;
    }

    /**
     * Sets the value of the substanceCompound property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setSubstanceCompound(String value) {
        this.substanceCompound = value;
    }

    /**
     * Gets the value of the bagVolume property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumeData }
     *     
     */
    public ScalarVolumeData getBagVolume() {
        return bagVolume;
    }

    /**
     * Sets the value of the bagVolume property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumeData }
     *     
     */
    public void setBagVolume(ScalarVolumeData value) {
        this.bagVolume = value;
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
