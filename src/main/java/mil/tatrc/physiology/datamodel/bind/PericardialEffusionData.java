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
 * <p>Java class for PericardialEffusionData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="PericardialEffusionData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}PatientActionData">
 *       &lt;sequence>
 *         &lt;element name="EffusionRate" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumePerTimeData"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "PericardialEffusionData", propOrder = {
    "effusionRate"
})
public class PericardialEffusionData
    extends PatientActionData
{

    @XmlElement(name = "EffusionRate", required = true)
    protected ScalarVolumePerTimeData effusionRate;

    /**
     * Gets the value of the effusionRate property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public ScalarVolumePerTimeData getEffusionRate() {
        return effusionRate;
    }

    /**
     * Sets the value of the effusionRate property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public void setEffusionRate(ScalarVolumePerTimeData value) {
        this.effusionRate = value;
    }

}
