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
 * <p>Java class for EnvironmentData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="EnvironmentData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}SystemData">
 *       &lt;sequence>
 *         &lt;element name="Conditions" type="{uri:/mil/tatrc/physiology/datamodel}EnvironmentalConditionsData" minOccurs="0"/>
 *         &lt;element name="ActiveHeating" type="{uri:/mil/tatrc/physiology/datamodel}ActiveHeatingData" minOccurs="0"/>
 *         &lt;element name="ActiveCooling" type="{uri:/mil/tatrc/physiology/datamodel}ActiveCoolingData" minOccurs="0"/>
 *         &lt;element name="AppliedTemperature" type="{uri:/mil/tatrc/physiology/datamodel}AppliedTemperatureData" minOccurs="0"/>
 *         &lt;element name="ConvectiveHeatLoss" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPowerData" minOccurs="0"/>
 *         &lt;element name="ConvectiveHeatTranferCoefficient" type="{uri:/mil/tatrc/physiology/datamodel}ScalarHeatConductancePerAreaData" minOccurs="0"/>
 *         &lt;element name="EvaporativeHeatLoss" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPowerData" minOccurs="0"/>
 *         &lt;element name="EvaporativeHeatTranferCoefficient" type="{uri:/mil/tatrc/physiology/datamodel}ScalarHeatConductancePerAreaData" minOccurs="0"/>
 *         &lt;element name="RadiativeHeatLoss" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPowerData" minOccurs="0"/>
 *         &lt;element name="RadiativeHeatTranferCoefficient" type="{uri:/mil/tatrc/physiology/datamodel}ScalarHeatConductancePerAreaData" minOccurs="0"/>
 *         &lt;element name="RespirationHeatLoss" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPowerData" minOccurs="0"/>
 *         &lt;element name="SkinHeatLoss" type="{uri:/mil/tatrc/physiology/datamodel}ScalarPowerData" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "EnvironmentData", propOrder = {
    "conditions",
    "activeHeating",
    "activeCooling",
    "appliedTemperature",
    "convectiveHeatLoss",
    "convectiveHeatTranferCoefficient",
    "evaporativeHeatLoss",
    "evaporativeHeatTranferCoefficient",
    "radiativeHeatLoss",
    "radiativeHeatTranferCoefficient",
    "respirationHeatLoss",
    "skinHeatLoss"
})
public class EnvironmentData
    extends SystemData
{

    @XmlElement(name = "Conditions")
    protected EnvironmentalConditionsData conditions;
    @XmlElement(name = "ActiveHeating")
    protected ActiveHeatingData activeHeating;
    @XmlElement(name = "ActiveCooling")
    protected ActiveCoolingData activeCooling;
    @XmlElement(name = "AppliedTemperature")
    protected AppliedTemperatureData appliedTemperature;
    @XmlElement(name = "ConvectiveHeatLoss")
    protected ScalarPowerData convectiveHeatLoss;
    @XmlElement(name = "ConvectiveHeatTranferCoefficient")
    protected ScalarHeatConductancePerAreaData convectiveHeatTranferCoefficient;
    @XmlElement(name = "EvaporativeHeatLoss")
    protected ScalarPowerData evaporativeHeatLoss;
    @XmlElement(name = "EvaporativeHeatTranferCoefficient")
    protected ScalarHeatConductancePerAreaData evaporativeHeatTranferCoefficient;
    @XmlElement(name = "RadiativeHeatLoss")
    protected ScalarPowerData radiativeHeatLoss;
    @XmlElement(name = "RadiativeHeatTranferCoefficient")
    protected ScalarHeatConductancePerAreaData radiativeHeatTranferCoefficient;
    @XmlElement(name = "RespirationHeatLoss")
    protected ScalarPowerData respirationHeatLoss;
    @XmlElement(name = "SkinHeatLoss")
    protected ScalarPowerData skinHeatLoss;

    /**
     * Gets the value of the conditions property.
     * 
     * @return
     *     possible object is
     *     {@link EnvironmentalConditionsData }
     *     
     */
    public EnvironmentalConditionsData getConditions() {
        return conditions;
    }

    /**
     * Sets the value of the conditions property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnvironmentalConditionsData }
     *     
     */
    public void setConditions(EnvironmentalConditionsData value) {
        this.conditions = value;
    }

    /**
     * Gets the value of the activeHeating property.
     * 
     * @return
     *     possible object is
     *     {@link ActiveHeatingData }
     *     
     */
    public ActiveHeatingData getActiveHeating() {
        return activeHeating;
    }

    /**
     * Sets the value of the activeHeating property.
     * 
     * @param value
     *     allowed object is
     *     {@link ActiveHeatingData }
     *     
     */
    public void setActiveHeating(ActiveHeatingData value) {
        this.activeHeating = value;
    }

    /**
     * Gets the value of the activeCooling property.
     * 
     * @return
     *     possible object is
     *     {@link ActiveCoolingData }
     *     
     */
    public ActiveCoolingData getActiveCooling() {
        return activeCooling;
    }

    /**
     * Sets the value of the activeCooling property.
     * 
     * @param value
     *     allowed object is
     *     {@link ActiveCoolingData }
     *     
     */
    public void setActiveCooling(ActiveCoolingData value) {
        this.activeCooling = value;
    }

    /**
     * Gets the value of the appliedTemperature property.
     * 
     * @return
     *     possible object is
     *     {@link AppliedTemperatureData }
     *     
     */
    public AppliedTemperatureData getAppliedTemperature() {
        return appliedTemperature;
    }

    /**
     * Sets the value of the appliedTemperature property.
     * 
     * @param value
     *     allowed object is
     *     {@link AppliedTemperatureData }
     *     
     */
    public void setAppliedTemperature(AppliedTemperatureData value) {
        this.appliedTemperature = value;
    }

    /**
     * Gets the value of the convectiveHeatLoss property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPowerData }
     *     
     */
    public ScalarPowerData getConvectiveHeatLoss() {
        return convectiveHeatLoss;
    }

    /**
     * Sets the value of the convectiveHeatLoss property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPowerData }
     *     
     */
    public void setConvectiveHeatLoss(ScalarPowerData value) {
        this.convectiveHeatLoss = value;
    }

    /**
     * Gets the value of the convectiveHeatTranferCoefficient property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarHeatConductancePerAreaData }
     *     
     */
    public ScalarHeatConductancePerAreaData getConvectiveHeatTranferCoefficient() {
        return convectiveHeatTranferCoefficient;
    }

    /**
     * Sets the value of the convectiveHeatTranferCoefficient property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarHeatConductancePerAreaData }
     *     
     */
    public void setConvectiveHeatTranferCoefficient(ScalarHeatConductancePerAreaData value) {
        this.convectiveHeatTranferCoefficient = value;
    }

    /**
     * Gets the value of the evaporativeHeatLoss property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPowerData }
     *     
     */
    public ScalarPowerData getEvaporativeHeatLoss() {
        return evaporativeHeatLoss;
    }

    /**
     * Sets the value of the evaporativeHeatLoss property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPowerData }
     *     
     */
    public void setEvaporativeHeatLoss(ScalarPowerData value) {
        this.evaporativeHeatLoss = value;
    }

    /**
     * Gets the value of the evaporativeHeatTranferCoefficient property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarHeatConductancePerAreaData }
     *     
     */
    public ScalarHeatConductancePerAreaData getEvaporativeHeatTranferCoefficient() {
        return evaporativeHeatTranferCoefficient;
    }

    /**
     * Sets the value of the evaporativeHeatTranferCoefficient property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarHeatConductancePerAreaData }
     *     
     */
    public void setEvaporativeHeatTranferCoefficient(ScalarHeatConductancePerAreaData value) {
        this.evaporativeHeatTranferCoefficient = value;
    }

    /**
     * Gets the value of the radiativeHeatLoss property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPowerData }
     *     
     */
    public ScalarPowerData getRadiativeHeatLoss() {
        return radiativeHeatLoss;
    }

    /**
     * Sets the value of the radiativeHeatLoss property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPowerData }
     *     
     */
    public void setRadiativeHeatLoss(ScalarPowerData value) {
        this.radiativeHeatLoss = value;
    }

    /**
     * Gets the value of the radiativeHeatTranferCoefficient property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarHeatConductancePerAreaData }
     *     
     */
    public ScalarHeatConductancePerAreaData getRadiativeHeatTranferCoefficient() {
        return radiativeHeatTranferCoefficient;
    }

    /**
     * Sets the value of the radiativeHeatTranferCoefficient property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarHeatConductancePerAreaData }
     *     
     */
    public void setRadiativeHeatTranferCoefficient(ScalarHeatConductancePerAreaData value) {
        this.radiativeHeatTranferCoefficient = value;
    }

    /**
     * Gets the value of the respirationHeatLoss property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPowerData }
     *     
     */
    public ScalarPowerData getRespirationHeatLoss() {
        return respirationHeatLoss;
    }

    /**
     * Sets the value of the respirationHeatLoss property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPowerData }
     *     
     */
    public void setRespirationHeatLoss(ScalarPowerData value) {
        this.respirationHeatLoss = value;
    }

    /**
     * Gets the value of the skinHeatLoss property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarPowerData }
     *     
     */
    public ScalarPowerData getSkinHeatLoss() {
        return skinHeatLoss;
    }

    /**
     * Sets the value of the skinHeatLoss property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarPowerData }
     *     
     */
    public void setSkinHeatLoss(ScalarPowerData value) {
        this.skinHeatLoss = value;
    }

}
