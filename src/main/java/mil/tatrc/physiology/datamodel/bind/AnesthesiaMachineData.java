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
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for AnesthesiaMachineData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="AnesthesiaMachineData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}SystemData">
 *       &lt;sequence>
 *         &lt;element name="InletFlow" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumePerTimeData" minOccurs="0"/>
 *         &lt;element name="InspiratoryExpiratoryRatio" type="{uri:/mil/tatrc/physiology/datamodel}ScalarData" minOccurs="0"/>
 *         &lt;element name="OxygenFraction" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *         &lt;element name="OxygenSource" type="{uri:/mil/tatrc/physiology/datamodel}enumAnesthesiaMachineOxygenSource" minOccurs="0"/>
 *         &lt;element name="PositiveEndExpiredPressure" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPressureData" minOccurs="0"/>
 *         &lt;element name="PrimaryGas" type="{uri:/mil/tatrc/physiology/datamodel}enumAnesthesiaMachinePrimaryGas" minOccurs="0"/>
 *         &lt;element name="ReliefValvePressure" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPressureData" minOccurs="0"/>
 *         &lt;element name="RespiratoryRate" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFrequencyData" minOccurs="0"/>
 *         &lt;element name="VentilatorMask" type="{uri:/mil/tatrc/physiology/datamodel}enumOnOff" minOccurs="0"/>
 *         &lt;element name="VentilatorPressure" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPressureData" minOccurs="0"/>
 *         &lt;element name="LeftChamber" type="{uri:/mil/tatrc/physiology/datamodel}AnesthesiaMachineChamberData" minOccurs="0"/>
 *         &lt;element name="RightChamber" type="{uri:/mil/tatrc/physiology/datamodel}AnesthesiaMachineChamberData" minOccurs="0"/>
 *         &lt;element name="OxygenBottleOne" type="{uri:/mil/tatrc/physiology/datamodel}AnesthesiaMachineOxygenBottleData" minOccurs="0"/>
 *         &lt;element name="OxygenBottleTwo" type="{uri:/mil/tatrc/physiology/datamodel}AnesthesiaMachineOxygenBottleData" minOccurs="0"/>
 *       &lt;/sequence>
 *       &lt;attribute name="State" type="{uri:/mil/tatrc/physiology/datamodel}enumOnOff" />
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "AnesthesiaMachineData", propOrder = {
    "inletFlow",
    "inspiratoryExpiratoryRatio",
    "oxygenFraction",
    "oxygenSource",
    "positiveEndExpiredPressure",
    "primaryGas",
    "reliefValvePressure",
    "respiratoryRate",
    "ventilatorMask",
    "ventilatorPressure",
    "leftChamber",
    "rightChamber",
    "oxygenBottleOne",
    "oxygenBottleTwo"
})
public class AnesthesiaMachineData
    extends SystemData
{

    @XmlElement(name = "InletFlow")
    protected ScalarVolumePerTimeData inletFlow;
    @XmlElement(name = "InspiratoryExpiratoryRatio")
    protected ScalarData inspiratoryExpiratoryRatio;
    @XmlElement(name = "OxygenFraction")
    protected ScalarFractionData oxygenFraction;
    @XmlElement(name = "OxygenSource")
    @XmlSchemaType(name = "string")
    protected EnumAnesthesiaMachineOxygenSource oxygenSource;
    @XmlElement(name = "PositiveEndExpiredPressure")
    protected ScalarPressureData positiveEndExpiredPressure;
    @XmlElement(name = "PrimaryGas")
    @XmlSchemaType(name = "string")
    protected EnumAnesthesiaMachinePrimaryGas primaryGas;
    @XmlElement(name = "ReliefValvePressure")
    protected ScalarPressureData reliefValvePressure;
    @XmlElement(name = "RespiratoryRate")
    protected ScalarFrequencyData respiratoryRate;
    @XmlElement(name = "VentilatorMask")
    @XmlSchemaType(name = "string")
    protected EnumOnOff ventilatorMask;
    @XmlElement(name = "VentilatorPressure")
    protected ScalarPressureData ventilatorPressure;
    @XmlElement(name = "LeftChamber")
    protected AnesthesiaMachineChamberData leftChamber;
    @XmlElement(name = "RightChamber")
    protected AnesthesiaMachineChamberData rightChamber;
    @XmlElement(name = "OxygenBottleOne")
    protected AnesthesiaMachineOxygenBottleData oxygenBottleOne;
    @XmlElement(name = "OxygenBottleTwo")
    protected AnesthesiaMachineOxygenBottleData oxygenBottleTwo;
    @XmlAttribute(name = "State")
    protected EnumOnOff state;

    /**
     * Gets the value of the inletFlow property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public ScalarVolumePerTimeData getInletFlow() {
        return inletFlow;
    }

    /**
     * Sets the value of the inletFlow property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public void setInletFlow(ScalarVolumePerTimeData value) {
        this.inletFlow = value;
    }

    /**
     * Gets the value of the inspiratoryExpiratoryRatio property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarData }
     *     
     */
    public ScalarData getInspiratoryExpiratoryRatio() {
        return inspiratoryExpiratoryRatio;
    }

    /**
     * Sets the value of the inspiratoryExpiratoryRatio property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarData }
     *     
     */
    public void setInspiratoryExpiratoryRatio(ScalarData value) {
        this.inspiratoryExpiratoryRatio = value;
    }

    /**
     * Gets the value of the oxygenFraction property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getOxygenFraction() {
        return oxygenFraction;
    }

    /**
     * Sets the value of the oxygenFraction property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setOxygenFraction(ScalarFractionData value) {
        this.oxygenFraction = value;
    }

    /**
     * Gets the value of the oxygenSource property.
     * 
     * @return
     *     possible object is
     *     {@link EnumAnesthesiaMachineOxygenSource }
     *     
     */
    public EnumAnesthesiaMachineOxygenSource getOxygenSource() {
        return oxygenSource;
    }

    /**
     * Sets the value of the oxygenSource property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumAnesthesiaMachineOxygenSource }
     *     
     */
    public void setOxygenSource(EnumAnesthesiaMachineOxygenSource value) {
        this.oxygenSource = value;
    }

    /**
     * Gets the value of the positiveEndExpiredPressure property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPressureData }
     *     
     */
    public ScalarPressureData getPositiveEndExpiredPressure() {
        return positiveEndExpiredPressure;
    }

    /**
     * Sets the value of the positiveEndExpiredPressure property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPressureData }
     *     
     */
    public void setPositiveEndExpiredPressure(ScalarPressureData value) {
        this.positiveEndExpiredPressure = value;
    }

    /**
     * Gets the value of the primaryGas property.
     * 
     * @return
     *     possible object is
     *     {@link EnumAnesthesiaMachinePrimaryGas }
     *     
     */
    public EnumAnesthesiaMachinePrimaryGas getPrimaryGas() {
        return primaryGas;
    }

    /**
     * Sets the value of the primaryGas property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumAnesthesiaMachinePrimaryGas }
     *     
     */
    public void setPrimaryGas(EnumAnesthesiaMachinePrimaryGas value) {
        this.primaryGas = value;
    }

    /**
     * Gets the value of the reliefValvePressure property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPressureData }
     *     
     */
    public ScalarPressureData getReliefValvePressure() {
        return reliefValvePressure;
    }

    /**
     * Sets the value of the reliefValvePressure property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPressureData }
     *     
     */
    public void setReliefValvePressure(ScalarPressureData value) {
        this.reliefValvePressure = value;
    }

    /**
     * Gets the value of the respiratoryRate property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFrequencyData }
     *     
     */
    public ScalarFrequencyData getRespiratoryRate() {
        return respiratoryRate;
    }

    /**
     * Sets the value of the respiratoryRate property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFrequencyData }
     *     
     */
    public void setRespiratoryRate(ScalarFrequencyData value) {
        this.respiratoryRate = value;
    }

    /**
     * Gets the value of the ventilatorMask property.
     * 
     * @return
     *     possible object is
     *     {@link EnumOnOff }
     *     
     */
    public EnumOnOff getVentilatorMask() {
        return ventilatorMask;
    }

    /**
     * Sets the value of the ventilatorMask property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumOnOff }
     *     
     */
    public void setVentilatorMask(EnumOnOff value) {
        this.ventilatorMask = value;
    }

    /**
     * Gets the value of the ventilatorPressure property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPressureData }
     *     
     */
    public ScalarPressureData getVentilatorPressure() {
        return ventilatorPressure;
    }

    /**
     * Sets the value of the ventilatorPressure property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPressureData }
     *     
     */
    public void setVentilatorPressure(ScalarPressureData value) {
        this.ventilatorPressure = value;
    }

    /**
     * Gets the value of the leftChamber property.
     * 
     * @return
     *     possible object is
     *     {@link AnesthesiaMachineChamberData }
     *     
     */
    public AnesthesiaMachineChamberData getLeftChamber() {
        return leftChamber;
    }

    /**
     * Sets the value of the leftChamber property.
     * 
     * @param value
     *     allowed object is
     *     {@link AnesthesiaMachineChamberData }
     *     
     */
    public void setLeftChamber(AnesthesiaMachineChamberData value) {
        this.leftChamber = value;
    }

    /**
     * Gets the value of the rightChamber property.
     * 
     * @return
     *     possible object is
     *     {@link AnesthesiaMachineChamberData }
     *     
     */
    public AnesthesiaMachineChamberData getRightChamber() {
        return rightChamber;
    }

    /**
     * Sets the value of the rightChamber property.
     * 
     * @param value
     *     allowed object is
     *     {@link AnesthesiaMachineChamberData }
     *     
     */
    public void setRightChamber(AnesthesiaMachineChamberData value) {
        this.rightChamber = value;
    }

    /**
     * Gets the value of the oxygenBottleOne property.
     * 
     * @return
     *     possible object is
     *     {@link AnesthesiaMachineOxygenBottleData }
     *     
     */
    public AnesthesiaMachineOxygenBottleData getOxygenBottleOne() {
        return oxygenBottleOne;
    }

    /**
     * Sets the value of the oxygenBottleOne property.
     * 
     * @param value
     *     allowed object is
     *     {@link AnesthesiaMachineOxygenBottleData }
     *     
     */
    public void setOxygenBottleOne(AnesthesiaMachineOxygenBottleData value) {
        this.oxygenBottleOne = value;
    }

    /**
     * Gets the value of the oxygenBottleTwo property.
     * 
     * @return
     *     possible object is
     *     {@link AnesthesiaMachineOxygenBottleData }
     *     
     */
    public AnesthesiaMachineOxygenBottleData getOxygenBottleTwo() {
        return oxygenBottleTwo;
    }

    /**
     * Sets the value of the oxygenBottleTwo property.
     * 
     * @param value
     *     allowed object is
     *     {@link AnesthesiaMachineOxygenBottleData }
     *     
     */
    public void setOxygenBottleTwo(AnesthesiaMachineOxygenBottleData value) {
        this.oxygenBottleTwo = value;
    }

    /**
     * Gets the value of the state property.
     * 
     * @return
     *     possible object is
     *     {@link EnumOnOff }
     *     
     */
    public EnumOnOff getState() {
        return state;
    }

    /**
     * Sets the value of the state property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumOnOff }
     *     
     */
    public void setState(EnumOnOff value) {
        this.state = value;
    }

}
