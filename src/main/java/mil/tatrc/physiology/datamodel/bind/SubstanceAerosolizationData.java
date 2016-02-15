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
 * <p>Java class for SubstanceAerosolizationData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SubstanceAerosolizationData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}ObjectData">
 *       &lt;sequence>
 *         &lt;element name="DropletDensity" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData"/>
 *         &lt;element name="DropletDiameter" type="{uri:/mil/tatrc/physiology/datamodel}ScalarLengthData"/>
 *       &lt;/sequence>
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SubstanceAerosolizationData", propOrder = {
    "dropletDensity",
    "dropletDiameter"
})
public class SubstanceAerosolizationData
    extends ObjectData
{

    @XmlElement(name = "DropletDensity", required = true)
    protected ScalarMassPerVolumeData dropletDensity;
    @XmlElement(name = "DropletDiameter", required = true)
    protected ScalarLengthData dropletDiameter;

    /**
     * Gets the value of the dropletDensity property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getDropletDensity() {
        return dropletDensity;
    }

    /**
     * Sets the value of the dropletDensity property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setDropletDensity(ScalarMassPerVolumeData value) {
        this.dropletDensity = value;
    }

    /**
     * Gets the value of the dropletDiameter property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarLengthData }
     *     
     */
    public ScalarLengthData getDropletDiameter() {
        return dropletDiameter;
    }

    /**
     * Sets the value of the dropletDiameter property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarLengthData }
     *     
     */
    public void setDropletDiameter(ScalarLengthData value) {
        this.dropletDiameter = value;
    }

}
