//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.2.8-b130911.1802 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2015.12.09 at 06:16:52 PM EST 
//


package mil.tatrc.physiology.datamodel.bind;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlElementRef;
import javax.xml.bind.annotation.XmlIDREF;
import javax.xml.bind.annotation.XmlSchemaType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for CircuitData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="CircuitData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}ObjectData">
 *       &lt;sequence>
 *         &lt;element name="ReferenceNode" type="{http://www.w3.org/2001/XMLSchema}IDREF"/>
 *         &lt;element name="Node" type="{http://www.w3.org/2001/XMLSchema}IDREF" maxOccurs="unbounded"/>
 *         &lt;element name="Path" type="{http://www.w3.org/2001/XMLSchema}IDREF" maxOccurs="unbounded"/>
 *       &lt;/sequence>
 *       &lt;attribute name="ModelType" type="{uri:/mil/tatrc/physiology/datamodel}enumCircuitModelType" default="Fluid" />
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "CircuitData", propOrder = {
    "referenceNode",
    "node",
    "path"
})
public class CircuitData
    extends ObjectData
{

    @XmlElement(name = "ReferenceNode", required = true)
    @XmlIDREF
    @XmlSchemaType(name = "IDREF")
    protected Object referenceNode;
    @XmlElementRef(name = "Node", namespace = "uri:/mil/tatrc/physiology/datamodel", type = JAXBElement.class)
    protected List<JAXBElement<Object>> node;
    @XmlElementRef(name = "Path", namespace = "uri:/mil/tatrc/physiology/datamodel", type = JAXBElement.class)
    protected List<JAXBElement<Object>> path;
    @XmlAttribute(name = "ModelType")
    protected EnumCircuitModelType modelType;

    /**
     * Gets the value of the referenceNode property.
     * 
     * @return
     *     possible object is
     *     {@link Object }
     *     
     */
    public Object getReferenceNode() {
        return referenceNode;
    }

    /**
     * Sets the value of the referenceNode property.
     * 
     * @param value
     *     allowed object is
     *     {@link Object }
     *     
     */
    public void setReferenceNode(Object value) {
        this.referenceNode = value;
    }

    /**
     * Gets the value of the node property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the node property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getNode().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link JAXBElement }{@code <}{@link Object }{@code >}
     * 
     * 
     */
    public List<JAXBElement<Object>> getNode() {
        if (node == null) {
            node = new ArrayList<JAXBElement<Object>>();
        }
        return this.node;
    }

    /**
     * Gets the value of the path property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the path property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getPath().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link JAXBElement }{@code <}{@link Object }{@code >}
     * 
     * 
     */
    public List<JAXBElement<Object>> getPath() {
        if (path == null) {
            path = new ArrayList<JAXBElement<Object>>();
        }
        return this.path;
    }

    /**
     * Gets the value of the modelType property.
     * 
     * @return
     *     possible object is
     *     {@link EnumCircuitModelType }
     *     
     */
    public EnumCircuitModelType getModelType() {
        if (modelType == null) {
            return EnumCircuitModelType.FLUID;
        } else {
            return modelType;
        }
    }

    /**
     * Sets the value of the modelType property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumCircuitModelType }
     *     
     */
    public void setModelType(EnumCircuitModelType value) {
        this.modelType = value;
    }

}
