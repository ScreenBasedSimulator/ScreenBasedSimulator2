//
// This file was generated by the JavaTM Architecture for XML Binding(JAXB) Reference Implementation, v2.2.8-b130911.1802 
// See <a href="http://java.sun.com/xml/jaxb">http://java.sun.com/xml/jaxb</a> 
// Any modifications to this file will be lost upon recompilation of the source schema. 
// Generated on: 2015.12.09 at 06:16:52 PM EST 
//


package mil.tatrc.physiology.datamodel.bind;

import java.util.ArrayList;
import java.util.List;
import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlAttribute;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for SubstanceData complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="SubstanceData">
 *   &lt;complexContent>
 *     &lt;extension base="{uri:/mil/tatrc/physiology/datamodel}ObjectData">
 *       &lt;sequence>
 *         &lt;element name="Name" type="{http://www.w3.org/2001/XMLSchema}string"/>
 *         &lt;element name="Density" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData" minOccurs="0"/>
 *         &lt;element name="MolarMass" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerAmountData" minOccurs="0"/>
 *         &lt;element name="Aerosolization" type="{uri:/mil/tatrc/physiology/datamodel}SubstanceAerosolizationData" minOccurs="0"/>
 *         &lt;element name="MassInBody" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="MassInBlood" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="MassInTissue" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="PlasmaConcentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassPerVolumeData" minOccurs="0"/>
 *         &lt;element name="RemainingSystemicMassCleared" type="{uri:/mil/tatrc/physiology/datamodel}ScalarMassData" minOccurs="0"/>
 *         &lt;element name="AlveolarTransfer" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumePerTimeData" minOccurs="0"/>
 *         &lt;element name="DiffusingCapacity" type="{uri:/mil/tatrc/physiology/datamodel}ScalarVolumePerTimePerPressureData" minOccurs="0"/>
 *         &lt;element name="EndTidalConcentration" type="{uri:/mil/tatrc/physiology/datamodel}ScalarFractionData" minOccurs="0"/>
 *         &lt;element name="RelativeDiffusionCoefficient" type="{uri:/mil/tatrc/physiology/datamodel}ScalarData" minOccurs="0"/>
 *         &lt;element name="SolubilityCoefficient" type="{uri:/mil/tatrc/physiology/datamodel}ScalarInversePressureData" minOccurs="0"/>
 *         &lt;element name="Clearance" type="{uri:/mil/tatrc/physiology/datamodel}SubstanceClearanceData" minOccurs="0"/>
 *         &lt;element name="Pharmacokinetics" type="{uri:/mil/tatrc/physiology/datamodel}SubstancePharmacokineticsData" minOccurs="0"/>
 *         &lt;element name="Pharmacodynamics" type="{uri:/mil/tatrc/physiology/datamodel}SubstancePharmacodynamicsData" minOccurs="0"/>
 *         &lt;element name="CompartmentEffect" type="{uri:/mil/tatrc/physiology/datamodel}SubstanceCompartmentEffectData" maxOccurs="unbounded" minOccurs="0"/>
 *       &lt;/sequence>
 *       &lt;attribute name="State" type="{uri:/mil/tatrc/physiology/datamodel}enumSubstanceState" />
 *     &lt;/extension>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "SubstanceData", propOrder = {
    "name",
    "density",
    "molarMass",
    "aerosolization",
    "massInBody",
    "massInBlood",
    "massInTissue",
    "plasmaConcentration",
    "remainingSystemicMassCleared",
    "alveolarTransfer",
    "diffusingCapacity",
    "endTidalConcentration",
    "relativeDiffusionCoefficient",
    "solubilityCoefficient",
    "clearance",
    "pharmacokinetics",
    "pharmacodynamics",
    "compartmentEffect"
})
public class SubstanceData
    extends ObjectData
{

    @XmlElement(name = "Name", required = true)
    protected String name;
    @XmlElement(name = "Density")
    protected ScalarMassPerVolumeData density;
    @XmlElement(name = "MolarMass")
    protected ScalarMassPerAmountData molarMass;
    @XmlElement(name = "Aerosolization")
    protected SubstanceAerosolizationData aerosolization;
    @XmlElement(name = "MassInBody")
    protected ScalarMassData massInBody;
    @XmlElement(name = "MassInBlood")
    protected ScalarMassData massInBlood;
    @XmlElement(name = "MassInTissue")
    protected ScalarMassData massInTissue;
    @XmlElement(name = "PlasmaConcentration")
    protected ScalarMassPerVolumeData plasmaConcentration;
    @XmlElement(name = "RemainingSystemicMassCleared")
    protected ScalarMassData remainingSystemicMassCleared;
    @XmlElement(name = "AlveolarTransfer")
    protected ScalarVolumePerTimeData alveolarTransfer;
    @XmlElement(name = "DiffusingCapacity")
    protected ScalarVolumePerTimePerPressureData diffusingCapacity;
    @XmlElement(name = "EndTidalConcentration")
    protected ScalarFractionData endTidalConcentration;
    @XmlElement(name = "RelativeDiffusionCoefficient")
    protected ScalarData relativeDiffusionCoefficient;
    @XmlElement(name = "SolubilityCoefficient")
    protected ScalarInversePressureData solubilityCoefficient;
    @XmlElement(name = "Clearance")
    protected SubstanceClearanceData clearance;
    @XmlElement(name = "Pharmacokinetics")
    protected SubstancePharmacokineticsData pharmacokinetics;
    @XmlElement(name = "Pharmacodynamics")
    protected SubstancePharmacodynamicsData pharmacodynamics;
    @XmlElement(name = "CompartmentEffect")
    protected List<SubstanceCompartmentEffectData> compartmentEffect;
    @XmlAttribute(name = "State")
    protected EnumSubstanceState state;

    /**
     * Gets the value of the name property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getName() {
        return name;
    }

    /**
     * Sets the value of the name property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setName(String value) {
        this.name = value;
    }

    /**
     * Gets the value of the density property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getDensity() {
        return density;
    }

    /**
     * Sets the value of the density property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setDensity(ScalarMassPerVolumeData value) {
        this.density = value;
    }

    /**
     * Gets the value of the molarMass property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerAmountData }
     *     
     */
    public ScalarMassPerAmountData getMolarMass() {
        return molarMass;
    }

    /**
     * Sets the value of the molarMass property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerAmountData }
     *     
     */
    public void setMolarMass(ScalarMassPerAmountData value) {
        this.molarMass = value;
    }

    /**
     * Gets the value of the aerosolization property.
     * 
     * @return
     *     possible object is
     *     {@link SubstanceAerosolizationData }
     *     
     */
    public SubstanceAerosolizationData getAerosolization() {
        return aerosolization;
    }

    /**
     * Sets the value of the aerosolization property.
     * 
     * @param value
     *     allowed object is
     *     {@link SubstanceAerosolizationData }
     *     
     */
    public void setAerosolization(SubstanceAerosolizationData value) {
        this.aerosolization = value;
    }

    /**
     * Gets the value of the massInBody property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassData }
     *     
     */
    public ScalarMassData getMassInBody() {
        return massInBody;
    }

    /**
     * Sets the value of the massInBody property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassData }
     *     
     */
    public void setMassInBody(ScalarMassData value) {
        this.massInBody = value;
    }

    /**
     * Gets the value of the massInBlood property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassData }
     *     
     */
    public ScalarMassData getMassInBlood() {
        return massInBlood;
    }

    /**
     * Sets the value of the massInBlood property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassData }
     *     
     */
    public void setMassInBlood(ScalarMassData value) {
        this.massInBlood = value;
    }

    /**
     * Gets the value of the massInTissue property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassData }
     *     
     */
    public ScalarMassData getMassInTissue() {
        return massInTissue;
    }

    /**
     * Sets the value of the massInTissue property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassData }
     *     
     */
    public void setMassInTissue(ScalarMassData value) {
        this.massInTissue = value;
    }

    /**
     * Gets the value of the plasmaConcentration property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public ScalarMassPerVolumeData getPlasmaConcentration() {
        return plasmaConcentration;
    }

    /**
     * Sets the value of the plasmaConcentration property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassPerVolumeData }
     *     
     */
    public void setPlasmaConcentration(ScalarMassPerVolumeData value) {
        this.plasmaConcentration = value;
    }

    /**
     * Gets the value of the remainingSystemicMassCleared property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarMassData }
     *     
     */
    public ScalarMassData getRemainingSystemicMassCleared() {
        return remainingSystemicMassCleared;
    }

    /**
     * Sets the value of the remainingSystemicMassCleared property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarMassData }
     *     
     */
    public void setRemainingSystemicMassCleared(ScalarMassData value) {
        this.remainingSystemicMassCleared = value;
    }

    /**
     * Gets the value of the alveolarTransfer property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public ScalarVolumePerTimeData getAlveolarTransfer() {
        return alveolarTransfer;
    }

    /**
     * Sets the value of the alveolarTransfer property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumePerTimeData }
     *     
     */
    public void setAlveolarTransfer(ScalarVolumePerTimeData value) {
        this.alveolarTransfer = value;
    }

    /**
     * Gets the value of the diffusingCapacity property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarVolumePerTimePerPressureData }
     *     
     */
    public ScalarVolumePerTimePerPressureData getDiffusingCapacity() {
        return diffusingCapacity;
    }

    /**
     * Sets the value of the diffusingCapacity property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarVolumePerTimePerPressureData }
     *     
     */
    public void setDiffusingCapacity(ScalarVolumePerTimePerPressureData value) {
        this.diffusingCapacity = value;
    }

    /**
     * Gets the value of the endTidalConcentration property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarFractionData }
     *     
     */
    public ScalarFractionData getEndTidalConcentration() {
        return endTidalConcentration;
    }

    /**
     * Sets the value of the endTidalConcentration property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarFractionData }
     *     
     */
    public void setEndTidalConcentration(ScalarFractionData value) {
        this.endTidalConcentration = value;
    }

    /**
     * Gets the value of the relativeDiffusionCoefficient property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarData }
     *     
     */
    public ScalarData getRelativeDiffusionCoefficient() {
        return relativeDiffusionCoefficient;
    }

    /**
     * Sets the value of the relativeDiffusionCoefficient property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarData }
     *     
     */
    public void setRelativeDiffusionCoefficient(ScalarData value) {
        this.relativeDiffusionCoefficient = value;
    }

    /**
     * Gets the value of the solubilityCoefficient property.
     * 
     * @return
     *     possible object is
     *     {@link ScalarInversePressureData }
     *     
     */
    public ScalarInversePressureData getSolubilityCoefficient() {
        return solubilityCoefficient;
    }

    /**
     * Sets the value of the solubilityCoefficient property.
     * 
     * @param value
     *     allowed object is
     *     {@link ScalarInversePressureData }
     *     
     */
    public void setSolubilityCoefficient(ScalarInversePressureData value) {
        this.solubilityCoefficient = value;
    }

    /**
     * Gets the value of the clearance property.
     * 
     * @return
     *     possible object is
     *     {@link SubstanceClearanceData }
     *     
     */
    public SubstanceClearanceData getClearance() {
        return clearance;
    }

    /**
     * Sets the value of the clearance property.
     * 
     * @param value
     *     allowed object is
     *     {@link SubstanceClearanceData }
     *     
     */
    public void setClearance(SubstanceClearanceData value) {
        this.clearance = value;
    }

    /**
     * Gets the value of the pharmacokinetics property.
     * 
     * @return
     *     possible object is
     *     {@link SubstancePharmacokineticsData }
     *     
     */
    public SubstancePharmacokineticsData getPharmacokinetics() {
        return pharmacokinetics;
    }

    /**
     * Sets the value of the pharmacokinetics property.
     * 
     * @param value
     *     allowed object is
     *     {@link SubstancePharmacokineticsData }
     *     
     */
    public void setPharmacokinetics(SubstancePharmacokineticsData value) {
        this.pharmacokinetics = value;
    }

    /**
     * Gets the value of the pharmacodynamics property.
     * 
     * @return
     *     possible object is
     *     {@link SubstancePharmacodynamicsData }
     *     
     */
    public SubstancePharmacodynamicsData getPharmacodynamics() {
        return pharmacodynamics;
    }

    /**
     * Sets the value of the pharmacodynamics property.
     * 
     * @param value
     *     allowed object is
     *     {@link SubstancePharmacodynamicsData }
     *     
     */
    public void setPharmacodynamics(SubstancePharmacodynamicsData value) {
        this.pharmacodynamics = value;
    }

    /**
     * Gets the value of the compartmentEffect property.
     * 
     * <p>
     * This accessor method returns a reference to the live list,
     * not a snapshot. Therefore any modification you make to the
     * returned list will be present inside the JAXB object.
     * This is why there is not a <CODE>set</CODE> method for the compartmentEffect property.
     * 
     * <p>
     * For example, to add a new item, do as follows:
     * <pre>
     *    getCompartmentEffect().add(newItem);
     * </pre>
     * 
     * 
     * <p>
     * Objects of the following type(s) are allowed in the list
     * {@link SubstanceCompartmentEffectData }
     * 
     * 
     */
    public List<SubstanceCompartmentEffectData> getCompartmentEffect() {
        if (compartmentEffect == null) {
            compartmentEffect = new ArrayList<SubstanceCompartmentEffectData>();
        }
        return this.compartmentEffect;
    }

    /**
     * Gets the value of the state property.
     * 
     * @return
     *     possible object is
     *     {@link EnumSubstanceState }
     *     
     */
    public EnumSubstanceState getState() {
        return state;
    }

    /**
     * Sets the value of the state property.
     * 
     * @param value
     *     allowed object is
     *     {@link EnumSubstanceState }
     *     
     */
    public void setState(EnumSubstanceState value) {
        this.state = value;
    }

}
