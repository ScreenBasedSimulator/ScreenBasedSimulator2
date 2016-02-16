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
import javax.xml.bind.annotation.XmlIDREF;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CircuitNodeSubstanceQuantityData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CircuitNodeSubstanceQuantityData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}ObjectData">
 *       &lt;sequence>
 *         &lt;element name="SubstanceRef" type="{http://www.w3.org/2001/XMLSchema}IDREF" minOccurs="0"/>
 *         &lt;element name="Concentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData" minOccurs="0"/>
 *         &lt;element name="NextConcentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData" minOccurs="0"/>
 *         &lt;element name="KidneyClearanceFactor" type="{uri:/mil/tatrc/physiology/datamodel}ScalarData" minOccurs="0"/>
 *         &lt;element name="LiverClearanceFactor" type="{uri:/mil/tatrc/physiology/datamodel}ScalarData" minOccurs="0"/>
 *         &lt;element name="Mass" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="NextMass" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="MetabolicFactor" type="{uri:/mil/tatrc/physiology/datamodel}ScalarData" minOccurs="0"/>
 *         &lt;element name="PartialPressure" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPressureData" minOccurs="0"/>
 *         &lt;element name="NextPartialPressure" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPressureData" minOccurs="0"/>
 *         &lt;element name="Saturation" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *         &lt;element name="NextSaturation" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *         &lt;element name="Volume" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumeData" minOccurs="0"/>
 *         &lt;element name="NextVolume" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumeData" minOccurs="0"/>
 *         &lt;element name="VolumeFraction" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *         &lt;element name="NextVolumeFraction" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CircuitNodeSubstanceQuantityData", propOrder = {
    "substanceRef",
    "concentration",
    "nextConcentration",
    "kidneyClearanceFactor",
    "liverClearanceFactor",
    "mass",
    "nextMass",
    "metabolicFactor",
    "partialPressure",
    "nextPartialPressure",
    "saturation",
    "nextSaturation",
    "volume",
    "nextVolume",
    "volumeFraction",
    "nextVolumeFraction"
})
public class CircuitNodeSubstanceQuantityData
    extends ObjectData
{

    @XmlElement(name = "SubstanceRef")
    @XmlIDREF
    @XmlSchemaType(name = "IDREF")
    protected Object substanceRef;
    @XmlElement(name = "Concentration")
    protected ScalarMassPerVolumeData concentration;
    @XmlElement(name = "NextConcentration")
    protected ScalarMassPerVolumeData nextConcentration;
    @XmlElement(name = "KidneyClearanceFactor")
    protected ScalarData kidneyClearanceFactor;
    @XmlElement(name = "LiverClearanceFactor")
    protected ScalarData liverClearanceFactor;
    @XmlElement(name = "Mass")
    protected ScalarMassData mass;
    @XmlElement(name = "NextMass")
    protected ScalarMassData nextMass;
    @XmlElement(name = "MetabolicFactor")
    protected ScalarData metabolicFactor;
    @XmlElement(name = "PartialPressure")
    protected ScalarPressureData partialPressure;
    @XmlElement(name = "NextPartialPressure")
    protected ScalarPressureData nextPartialPressure;
    @XmlElement(name = "Saturation")
    protected ScalarFractionData saturation;
    @XmlElement(name = "NextSaturation")
    protected ScalarFractionData nextSaturation;
    @XmlElement(name = "Volume")
    protected ScalarVolumeData volume;
    @XmlElement(name = "NextVolume")
    protected ScalarVolumeData nextVolume;
    @XmlElement(name = "VolumeFraction")
    protected ScalarFractionData volumeFraction;
    @XmlElement(name = "NextVolumeFraction")
    protected ScalarFractionData nextVolumeFraction;

    /**
     * Gets the value of the substanceRef property.
     * 
     * @return
     *     possible object is
     *     {@link Object }
     *     
     */
    public Object getSubstanceRef() {
        return substanceRef;
    }

    /**
     * Sets the value of the substanceRef property.
     * 
     * @param value
     *     allowed object is
     *     {@link Object }
     *     
     */
    public void setSubstanceRef(Object value) {
        this.substanceRef = value;
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
     * Gets the value of the nextConcentration property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getNextConcentration() {
        return nextConcentration;
    }

    /**
     * Sets the value of the nextConcentration property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setNextConcentration(ScalarMassPerVolumeData value) {
        this.nextConcentration = value;
    }

    /**
     * Gets the value of the kidneyClearanceFactor property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarData }
     *     
     */
    public ScalarData getKidneyClearanceFactor() {
        return kidneyClearanceFactor;
    }

    /**
     * Sets the value of the kidneyClearanceFactor property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarData }
     *     
     */
    public void setKidneyClearanceFactor(ScalarData value) {
        this.kidneyClearanceFactor = value;
    }

    /**
     * Gets the value of the liverClearanceFactor property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarData }
     *     
     */
    public ScalarData getLiverClearanceFactor() {
        return liverClearanceFactor;
    }

    /**
     * Sets the value of the liverClearanceFactor property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarData }
     *     
     */
    public void setLiverClearanceFactor(ScalarData value) {
        this.liverClearanceFactor = value;
    }

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
     * Gets the value of the nextMass property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassData }
     *     
     */
    public ScalarMassData getNextMass() {
        return nextMass;
    }

    /**
     * Sets the value of the nextMass property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassData }
     *     
     */
    public void setNextMass(ScalarMassData value) {
        this.nextMass = value;
    }

    /**
     * Gets the value of the metabolicFactor property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarData }
     *     
     */
    public ScalarData getMetabolicFactor() {
        return metabolicFactor;
    }

    /**
     * Sets the value of the metabolicFactor property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarData }
     *     
     */
    public void setMetabolicFactor(ScalarData value) {
        this.metabolicFactor = value;
    }

    /**
     * Gets the value of the partialPressure property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPressureData }
     *     
     */
    public ScalarPressureData getPartialPressure() {
        return partialPressure;
    }

    /**
     * Sets the value of the partialPressure property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPressureData }
     *     
     */
    public void setPartialPressure(ScalarPressureData value) {
        this.partialPressure = value;
    }

    /**
     * Gets the value of the nextPartialPressure property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPressureData }
     *     
     */
    public ScalarPressureData getNextPartialPressure() {
        return nextPartialPressure;
    }

    /**
     * Sets the value of the nextPartialPressure property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPressureData }
     *     
     */
    public void setNextPartialPressure(ScalarPressureData value) {
        this.nextPartialPressure = value;
    }

    /**
     * Gets the value of the saturation property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getSaturation() {
        return saturation;
    }

    /**
     * Sets the value of the saturation property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setSaturation(ScalarFractionData value) {
        this.saturation = value;
    }

    /**
     * Gets the value of the nextSaturation property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getNextSaturation() {
        return nextSaturation;
    }

    /**
     * Sets the value of the nextSaturation property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setNextSaturation(ScalarFractionData value) {
        this.nextSaturation = value;
    }

    /**
     * Gets the value of the volume property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumeData }
     *     
     */
    public ScalarVolumeData getVolume() {
        return volume;
    }

    /**
     * Sets the value of the volume property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumeData }
     *     
     */
    public void setVolume(ScalarVolumeData value) {
        this.volume = value;
    }

    /**
     * Gets the value of the nextVolume property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumeData }
     *     
     */
    public ScalarVolumeData getNextVolume() {
        return nextVolume;
    }

    /**
     * Sets the value of the nextVolume property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumeData }
     *     
     */
    public void setNextVolume(ScalarVolumeData value) {
        this.nextVolume = value;
    }

    /**
     * Gets the value of the volumeFraction property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getVolumeFraction() {
        return volumeFraction;
    }

    /**
     * Sets the value of the volumeFraction property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setVolumeFraction(ScalarFractionData value) {
        this.volumeFraction = value;
    }

    /**
     * Gets the value of the nextVolumeFraction property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getNextVolumeFraction() {
        return nextVolumeFraction;
    }

    /**
     * Sets the value of the nextVolumeFraction property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setNextVolumeFraction(ScalarFractionData value) {
        this.nextVolumeFraction = value;
    }

}
