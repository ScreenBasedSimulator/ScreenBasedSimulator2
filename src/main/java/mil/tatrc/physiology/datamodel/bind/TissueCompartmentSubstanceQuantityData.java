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
 * <p>Java class for TissueCompartmentSubstanceQuantityData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="TissueCompartmentSubstanceQuantityData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}CompartmentSubstanceQuantityData">
 *       &lt;sequence>
 *         &lt;element name="Mass" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="TissueConcentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData" minOccurs="0"/>
 *         &lt;element name="TissueMolarity" type="{uri:/mil/tatrc/physiology/datamodel}ScalarAmountPerVolumeData" minOccurs="0"/>
 *         &lt;element name="ExtravascularConcentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData" minOccurs="0"/>
 *         &lt;element name="ExtravascularMolarity" type="{uri:/mil/tatrc/physiology/datamodel}ScalarAmountPerVolumeData" minOccurs="0"/>
 *         &lt;element name="ExtravascularPartialPressure" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPressureData" minOccurs="0"/>
 *         &lt;element name="ExtravascularSaturation" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "TissueCompartmentSubstanceQuantityData", propOrder = {
    "mass",
    "tissueConcentration",
    "tissueMolarity",
    "extravascularConcentration",
    "extravascularMolarity",
    "extravascularPartialPressure",
    "extravascularSaturation"
})
public class TissueCompartmentSubstanceQuantityData
    extends CompartmentSubstanceQuantityData
{

    @XmlElement(name = "Mass")
    protected ScalarMassData mass;
    @XmlElement(name = "TissueConcentration")
    protected ScalarMassPerVolumeData tissueConcentration;
    @XmlElement(name = "TissueMolarity")
    protected ScalarAmountPerVolumeData tissueMolarity;
    @XmlElement(name = "ExtravascularConcentration")
    protected ScalarMassPerVolumeData extravascularConcentration;
    @XmlElement(name = "ExtravascularMolarity")
    protected ScalarAmountPerVolumeData extravascularMolarity;
    @XmlElement(name = "ExtravascularPartialPressure")
    protected ScalarPressureData extravascularPartialPressure;
    @XmlElement(name = "ExtravascularSaturation")
    protected ScalarFractionData extravascularSaturation;

    /**
     * Gets the value of the mass property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassData }
     *     
     */
    public ScalarMassData getMass() {
        return mass;
    }

    /**
     * Sets the value of the mass property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassData }
     *     
     */
    public void setMass(ScalarMassData value) {
        this.mass = value;
    }

    /**
     * Gets the value of the tissueConcentration property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getTissueConcentration() {
        return tissueConcentration;
    }

    /**
     * Sets the value of the tissueConcentration property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setTissueConcentration(ScalarMassPerVolumeData value) {
        this.tissueConcentration = value;
    }

    /**
     * Gets the value of the tissueMolarity property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarAmountPerVolumeData }
     *     
     */
    public ScalarAmountPerVolumeData getTissueMolarity() {
        return tissueMolarity;
    }

    /**
     * Sets the value of the tissueMolarity property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarAmountPerVolumeData }
     *     
     */
    public void setTissueMolarity(ScalarAmountPerVolumeData value) {
        this.tissueMolarity = value;
    }

    /**
     * Gets the value of the extravascularConcentration property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getExtravascularConcentration() {
        return extravascularConcentration;
    }

    /**
     * Sets the value of the extravascularConcentration property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setExtravascularConcentration(ScalarMassPerVolumeData value) {
        this.extravascularConcentration = value;
    }

    /**
     * Gets the value of the extravascularMolarity property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarAmountPerVolumeData }
     *     
     */
    public ScalarAmountPerVolumeData getExtravascularMolarity() {
        return extravascularMolarity;
    }

    /**
     * Sets the value of the extravascularMolarity property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarAmountPerVolumeData }
     *     
     */
    public void setExtravascularMolarity(ScalarAmountPerVolumeData value) {
        this.extravascularMolarity = value;
    }

    /**
     * Gets the value of the extravascularPartialPressure property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPressureData }
     *     
     */
    public ScalarPressureData getExtravascularPartialPressure() {
        return extravascularPartialPressure;
    }

    /**
     * Sets the value of the extravascularPartialPressure property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPressureData }
     *     
     */
    public void setExtravascularPartialPressure(ScalarPressureData value) {
        this.extravascularPartialPressure = value;
    }

    /**
     * Gets the value of the extravascularSaturation property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getExtravascularSaturation() {
        return extravascularSaturation;
    }

    /**
     * Sets the value of the extravascularSaturation property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setExtravascularSaturation(ScalarFractionData value) {
        this.extravascularSaturation = value;
    }

}
