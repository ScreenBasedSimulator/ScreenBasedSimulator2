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
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for SubstancePharmacodynamicsData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SubstancePharmacodynamicsData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}ObjectData">
 *       &lt;sequence>
 *         &lt;element name="Bronchodilation" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="DiastolicPressureModifier" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="EC50" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData"/>
 *         &lt;element name="HeartRateModifier" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="NeuromuscularBlock" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="PupilState" type="{uri:/mil/tatrc/physiology/datamodel}enumPupilState"/>
 *         &lt;element name="RespirationRateModifier" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="Sedation" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="SystolicPressureModifier" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *         &lt;element name="TidalVolumeModifier" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SubstancePharmacodynamicsData", propOrder = {
    "bronchodilation",
    "diastolicPressureModifier",
    "ec50",
    "heartRateModifier",
    "neuromuscularBlock",
    "pupilState",
    "respirationRateModifier",
    "sedation",
    "systolicPressureModifier",
    "tidalVolumeModifier"
})
public class SubstancePharmacodynamicsData
    extends ObjectData
{

    @XmlElement(name = "Bronchodilation", required = true)
    protected ScalarFractionData bronchodilation;
    @XmlElement(name = "DiastolicPressureModifier", required = true)
    protected ScalarFractionData diastolicPressureModifier;
    @XmlElement(name = "EC50", required = true)
    protected ScalarMassPerVolumeData ec50;
    @XmlElement(name = "HeartRateModifier", required = true)
    protected ScalarFractionData heartRateModifier;
    @XmlElement(name = "NeuromuscularBlock", required = true)
    protected ScalarFractionData neuromuscularBlock;
    @XmlElement(name = "PupilState", required = true)
    @XmlSchemaType(name = "string")
    protected EnumPupilState pupilState;
    @XmlElement(name = "RespirationRateModifier", required = true)
    protected ScalarFractionData respirationRateModifier;
    @XmlElement(name = "Sedation", required = true)
    protected ScalarFractionData sedation;
    @XmlElement(name = "SystolicPressureModifier", required = true)
    protected ScalarFractionData systolicPressureModifier;
    @XmlElement(name = "TidalVolumeModifier", required = true)
    protected ScalarFractionData tidalVolumeModifier;

    /**
     * Gets the value of the bronchodilation property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getBronchodilation() {
        return bronchodilation;
    }

    /**
     * Sets the value of the bronchodilation property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setBronchodilation(ScalarFractionData value) {
        this.bronchodilation = value;
    }

    /**
     * Gets the value of the diastolicPressureModifier property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getDiastolicPressureModifier() {
        return diastolicPressureModifier;
    }

    /**
     * Sets the value of the diastolicPressureModifier property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setDiastolicPressureModifier(ScalarFractionData value) {
        this.diastolicPressureModifier = value;
    }

    /**
     * Gets the value of the ec50 property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getEC50() {
        return ec50;
    }

    /**
     * Sets the value of the ec50 property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setEC50(ScalarMassPerVolumeData value) {
        this.ec50 = value;
    }

    /**
     * Gets the value of the heartRateModifier property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getHeartRateModifier() {
        return heartRateModifier;
    }

    /**
     * Sets the value of the heartRateModifier property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setHeartRateModifier(ScalarFractionData value) {
        this.heartRateModifier = value;
    }

    /**
     * Gets the value of the neuromuscularBlock property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getNeuromuscularBlock() {
        return neuromuscularBlock;
    }

    /**
     * Sets the value of the neuromuscularBlock property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setNeuromuscularBlock(ScalarFractionData value) {
        this.neuromuscularBlock = value;
    }

    /**
     * Gets the value of the pupilState property.
     * 
     * @return
     *     possible object is
     *     {@link EnumPupilState }
     *     
     */
    public EnumPupilState getPupilState() {
        return pupilState;
    }

    /**
     * Sets the value of the pupilState property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumPupilState }
     *     
     */
    public void setPupilState(EnumPupilState value) {
        this.pupilState = value;
    }

    /**
     * Gets the value of the respirationRateModifier property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getRespirationRateModifier() {
        return respirationRateModifier;
    }

    /**
     * Sets the value of the respirationRateModifier property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setRespirationRateModifier(ScalarFractionData value) {
        this.respirationRateModifier = value;
    }

    /**
     * Gets the value of the sedation property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getSedation() {
        return sedation;
    }

    /**
     * Sets the value of the sedation property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setSedation(ScalarFractionData value) {
        this.sedation = value;
    }

    /**
     * Gets the value of the systolicPressureModifier property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getSystolicPressureModifier() {
        return systolicPressureModifier;
    }

    /**
     * Sets the value of the systolicPressureModifier property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setSystolicPressureModifier(ScalarFractionData value) {
        this.systolicPressureModifier = value;
    }

    /**
     * Gets the value of the tidalVolumeModifier property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getTidalVolumeModifier() {
        return tidalVolumeModifier;
    }

    /**
     * Sets the value of the tidalVolumeModifier property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setTidalVolumeModifier(ScalarFractionData value) {
        this.tidalVolumeModifier = value;
    }

}
