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
 * <p>Java class for ThermalApplicationData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="ThermalApplicationData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}EnvironmentActionData">
 *       &lt;sequence>
 *         &lt;element name="ActiveHeating" type="{uri:/mil/tatrc/physiology/datamodel}ActiveHeatingData" minOccurs="0"/>
 *         &lt;element name="ActiveCooling" type="{uri:/mil/tatrc/physiology/datamodel}ActiveCoolingData" minOccurs="0"/>
 *         &lt;element name="AppliedTemperature" type="{uri:/mil/tatrc/physiology/datamodel}AppliedTemperatureData" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "ThermalApplicationData", propOrder = {
    "activeHeating",
    "activeCooling",
    "appliedTemperature"
})
public class ThermalApplicationData
    extends EnvironmentActionData
{

    @XmlElement(name = "ActiveHeating")
    protected ActiveHeatingData activeHeating;
    @XmlElement(name = "ActiveCooling")
    protected ActiveCoolingData activeCooling;
    @XmlElement(name = "AppliedTemperature")
    protected AppliedTemperatureData appliedTemperature;

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

}