/**************************************************************************************
Copyright 2015 Applied Research Associates, Inc.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the License
at:
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
 **************************************************************************************/

package mil.tatrc.physiology.datamodel.system.physiology;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.BloodChemistrySystemData;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.datamodel.system.SESystem;

public class SEBloodChemistrySystem extends SEPhysiologySystem implements SESystem
{
  protected SEScalarMassPerVolume          bloodDensity;
  protected SEScalar                       bloodPH;
  protected SEScalarHeatCapacitancePerMass bloodSpecificHeat;
  protected SEScalarFraction               carbonDioxideSaturation;
  protected SEScalarVolume                 extracellularFluidVolume;
  protected SEScalarVolume                 extravascularFluidVolume;
  protected SEScalarVolume                 intracellularFluidVolume;
  protected SEScalar                       intracellularFluidPH;  
  protected SEScalarFraction               hematocrit;
  protected SEScalarMass                   hemoglobinContent;
  protected SEScalarFraction               oxygenSaturation;
  protected SEScalarVolume                 plasmaVolume;
  protected SEScalarAmountPerVolume        redBloodCellCount;
  protected SEScalarFraction               shuntFraction;
  protected SEScalarFraction               volumeFractionNeutralLipidInPlasma;
  protected SEScalarFraction               volumeFractionNeutralPhospholipidInPlasma;
  protected SEScalarAmountPerVolume        whiteBloodCellCount;

  protected SEScalarMassPerVolume          albuminConcentration;
  protected SEScalarMassPerVolume          bloodUreaNitrogenConcentration;
  protected SEScalarMassPerVolume          bicarbonateConcentration;
  protected SEScalarMassPerVolume          calciumConcentration;
  protected SEScalarMassPerVolume          creatinineConcentration;
  protected SEScalarMassPerVolume          globulinConcentration;
  protected SEScalarMassPerVolume          glucoseConcentration;
  protected SEScalarMassPerVolume          hemoglobinConcentration;
  protected SEScalarMassPerVolume          insulinConcentration;
  protected SEScalarMassPerVolume          ketoneConcentration;
  protected SEScalarMassPerVolume          lactateConcentration;  
  protected SEScalarMassPerVolume          sodiumConcentration;
  protected SEScalarMassPerVolume          totalProteinConcentration;
  protected SEScalarMassPerVolume          tristearinConcentration;
  protected SEScalarMassPerVolume          ureaConcentration;

  protected SEScalarPressure               arterialCarbonDioxidePressure;
  protected SEScalarPressure               arterialOxygenPressure;
  protected SEScalarPressure               pulmonaryArterialOxygenPressure;
  protected SEScalarPressure               pulmonaryArterialCarbonDioxidePressure;
  protected SEScalarPressure               pulmonaryVenousOxygenPressure;
  protected SEScalarPressure               pulmonaryVenousCarbonDioxidePressure;
  protected SEScalarPressure               venousOxygenPressure;
  protected SEScalarPressure               venousCarbonDioxidePressure;

  protected SEScalarFraction 			         arterialBicarbonateCO2Fraction;
  protected SEScalarFraction 			         venousBicarbonateCO2Fraction;
  protected SEScalarFraction 			         arterialCarbaminohemoglobinCO2Fraction;
  protected SEScalarFraction 			         venousCarbaminohemoglobinCO2Fraction;
  protected SEScalarFraction 			         arterialFreeFloatingCO2Fraction;
  protected SEScalarFraction 			         venousFreeFloatingCO2Fraction;

  public SEBloodChemistrySystem()
  {
    bloodDensity = null;
    bloodPH = null;
    bloodSpecificHeat = null;
    carbonDioxideSaturation = null;
    extracellularFluidVolume = null;
    extravascularFluidVolume = null;
    intracellularFluidVolume = null;
    intracellularFluidPH = null;
    hematocrit = null;
    hemoglobinContent = null;
    oxygenSaturation = null;
    plasmaVolume = null;
    redBloodCellCount = null;
    shuntFraction = null;
    volumeFractionNeutralLipidInPlasma = null;
    volumeFractionNeutralPhospholipidInPlasma = null;
    whiteBloodCellCount = null;

    albuminConcentration = null;
    bicarbonateConcentration = null;
    bloodUreaNitrogenConcentration = null;
    calciumConcentration = null;
    creatinineConcentration = null;
    globulinConcentration = null;
    glucoseConcentration = null;
    hemoglobinConcentration = null;
    insulinConcentration = null;
    ketoneConcentration = null;
    lactateConcentration = null;
    sodiumConcentration = null;
    totalProteinConcentration = null;
    tristearinConcentration = null;
    ureaConcentration = null;

    arterialCarbonDioxidePressure = null;
    arterialOxygenPressure = null;
    pulmonaryArterialOxygenPressure = null;
    pulmonaryArterialCarbonDioxidePressure = null;
    pulmonaryVenousOxygenPressure = null;
    pulmonaryVenousCarbonDioxidePressure = null;
    venousOxygenPressure = null;
    venousCarbonDioxidePressure = null;

    arterialBicarbonateCO2Fraction = null;
    venousBicarbonateCO2Fraction = null;
    arterialCarbaminohemoglobinCO2Fraction = null;
    venousCarbaminohemoglobinCO2Fraction = null;
    arterialFreeFloatingCO2Fraction = null;
    venousFreeFloatingCO2Fraction = null;
  }

  public void reset()
  {
    if (bloodDensity != null)
      bloodDensity.invalidate();
    if (bloodPH != null)
      bloodPH.invalidate();
    if (bloodSpecificHeat != null)
      bloodSpecificHeat.invalidate();
    if (carbonDioxideSaturation != null)
      carbonDioxideSaturation.invalidate();
    if (carbonDioxideSaturation != null)
      carbonDioxideSaturation.invalidate();
    if (extracellularFluidVolume != null)
      extracellularFluidVolume.invalidate();
    if (extravascularFluidVolume != null)
      extravascularFluidVolume.invalidate();
    if (intracellularFluidVolume != null)
      intracellularFluidVolume.invalidate();
    if (hematocrit != null)
      hematocrit.invalidate();
    if (hemoglobinContent != null)
      hemoglobinContent.invalidate();
    if (oxygenSaturation != null)
      oxygenSaturation.invalidate();
    if (plasmaVolume != null)
      plasmaVolume.invalidate();
    if (redBloodCellCount != null)
      redBloodCellCount.invalidate();
    if (shuntFraction != null)
      shuntFraction.invalidate();
    if (volumeFractionNeutralLipidInPlasma != null)
      volumeFractionNeutralLipidInPlasma.invalidate();
    if (volumeFractionNeutralPhospholipidInPlasma != null)
      volumeFractionNeutralPhospholipidInPlasma.invalidate();
    if (whiteBloodCellCount != null)
      whiteBloodCellCount.invalidate();

    if (albuminConcentration != null)
      albuminConcentration.invalidate();
    if (bicarbonateConcentration != null)
      bicarbonateConcentration.invalidate();
    if (bloodUreaNitrogenConcentration != null)
      bloodUreaNitrogenConcentration.invalidate();
    if (calciumConcentration != null)
      calciumConcentration.invalidate();
    if (creatinineConcentration != null)
      creatinineConcentration.invalidate();
    if (globulinConcentration != null)
      globulinConcentration.invalidate();
    if (glucoseConcentration != null)
      glucoseConcentration.invalidate();
    if (hemoglobinConcentration != null)
      hemoglobinConcentration.invalidate();
    if (insulinConcentration != null)
      insulinConcentration.invalidate();
    if (ketoneConcentration != null)
      ketoneConcentration.invalidate();
    if (lactateConcentration != null)
      lactateConcentration.invalidate();
    if (sodiumConcentration != null)
      sodiumConcentration.invalidate();
    if (totalProteinConcentration != null)
      totalProteinConcentration.invalidate();
    if (tristearinConcentration != null)
      tristearinConcentration.invalidate();
    if (ureaConcentration != null)
      ureaConcentration.invalidate();

    if (arterialCarbonDioxidePressure != null)
      arterialCarbonDioxidePressure.invalidate();
    if (arterialOxygenPressure != null)
      arterialOxygenPressure.invalidate();
    if (pulmonaryArterialOxygenPressure != null)
      pulmonaryArterialOxygenPressure.invalidate();
    if (pulmonaryArterialCarbonDioxidePressure != null)
      pulmonaryArterialCarbonDioxidePressure.invalidate();
    if (pulmonaryVenousOxygenPressure != null)
      pulmonaryVenousOxygenPressure.invalidate();
    if (pulmonaryVenousCarbonDioxidePressure != null)
      pulmonaryVenousCarbonDioxidePressure.invalidate();
    if (venousOxygenPressure != null)
      venousOxygenPressure.invalidate();
    if (venousCarbonDioxidePressure != null)
      venousCarbonDioxidePressure.invalidate();

    if (arterialBicarbonateCO2Fraction != null)
      arterialBicarbonateCO2Fraction.invalidate();
    if (venousBicarbonateCO2Fraction != null)
      venousBicarbonateCO2Fraction.invalidate();
    if (arterialCarbaminohemoglobinCO2Fraction != null)
      arterialCarbaminohemoglobinCO2Fraction.invalidate();
    if (venousCarbaminohemoglobinCO2Fraction != null)
      venousCarbaminohemoglobinCO2Fraction.invalidate();
    if (arterialFreeFloatingCO2Fraction != null)
      arterialFreeFloatingCO2Fraction.invalidate();
    if (venousFreeFloatingCO2Fraction != null)
      venousFreeFloatingCO2Fraction.invalidate();
  }

  public boolean load(BloodChemistrySystemData in)
  {
    if (in.getBloodDensity() != null)
      getBloodDensity().load(in.getBloodDensity());
    if (in.getBloodPH() != null)
      getBloodPH().load(in.getBloodPH());
    if (in.getBloodSpecificHeat() != null)
      getBloodSpecificHeat().load(in.getBloodSpecificHeat());
    if (in.getCarbonDioxideSaturation() != null)
      getCarbonDioxideSaturation().load(in.getCarbonDioxideSaturation());
    if (in.getExtracellularFluidVolume() != null)
      getExtracellularFluidVolume().load(in.getExtracellularFluidVolume());
    if (in.getExtravascularFluidVolume() != null)
      getExtravascularFluidVolume().load(in.getExtravascularFluidVolume());
    if (in.getIntracellularFluidVolume() != null)
      getIntracellularFluidVolume().load(in.getIntracellularFluidVolume());
    if (in.getIntracellularFluidPH() != null)
      getIntracellularFluidPH().load(in.getIntracellularFluidPH());
    if (in.getHematocrit() != null)
      getHematocrit().load(in.getHematocrit());
    if (in.getHemoglobinContent() != null)
      getHemoglobinContent().load(in.getHemoglobinContent());
    if (in.getOxygenSaturation() != null)
      getOxygenSaturation().load(in.getOxygenSaturation());
    if (in.getPlasmaVolume() != null)
      getPlasmaVolume().load(in.getPlasmaVolume());  
    if (in.getRedBloodCellCount() != null)
      getRedBloodCellCount().load(in.getRedBloodCellCount());
    if (in.getShuntFraction() != null)
      getShuntFraction().load(in.getShuntFraction());
    if (in.getVolumeFractionNeutralLipidInPlasma() != null)
      getVolumeFractionNeutralLipidInPlasma().load(in.getVolumeFractionNeutralLipidInPlasma());
    if (in.getVolumeFractionNeutralPhospholipidInPlasma() != null)
      getVolumeFractionNeutralPhospholipidInPlasma().load(in.getVolumeFractionNeutralPhospholipidInPlasma());
    if (in.getWhiteBloodCellCount() != null)
      getWhiteBloodCellCount().load(in.getWhiteBloodCellCount());

    if (in.getAlbuminConcentration() != null)
      getAlbuminConcentration().load(in.getAlbuminConcentration());
    if (in.getBicarbonateConcentration() != null)
      getBicarbonateConcentration().load(in.getBicarbonateConcentration());
    if (in.getBloodUreaNitrogenConcentration() != null)
      getBloodUreaNitrogenConcentration().load(in.getBloodUreaNitrogenConcentration());
    if (in.getCalciumConcentration() != null)
      getCalciumConcentration().load(in.getCalciumConcentration());
    if (in.getCreatinineConcentration() != null)
      getCreatinineConcentration().load(in.getCreatinineConcentration());
    if (in.getGlobulinConcentration() != null)
      getGlobulinConcentration().load(in.getGlobulinConcentration());
    if (in.getGlucoseConcentration() != null)
      getGlucoseConcentration().load(in.getGlucoseConcentration());
    if (in.getHemoglobinConcentration() != null)
      getHemoglobinConcentration().load(in.getHemoglobinConcentration());
    if (in.getInsulinConcentration() != null)
      getInsulinConcentration().load(in.getInsulinConcentration());    
    if (in.getKetoneConcentration() != null)
      getKetoneConcentration().load(in.getKetoneConcentration());
    if (in.getLactateConcentration() != null)
      getLactateConcentration().load(in.getLactateConcentration());
    if (in.getSodiumConcentration() != null)
      getSodiumConcentration().load(in.getSodiumConcentration());
    if (in.getTotalProteinConcentration() != null)
      getTotalProteinConcentration().load(in.getTotalProteinConcentration());
    if (in.getTristearinConcentration() != null)
      getTristearinConcentration().load(in.getTristearinConcentration());
    if (in.getUreaConcentration() != null)
      getUreaConcentration().load(in.getUreaConcentration());

    if (in.getArterialCarbonDioxidePressure() != null)
      getArterialCarbonDioxidePressure().load(in.getArterialCarbonDioxidePressure());
    if (in.getArterialOxygenPressure() != null)
      getArterialOxygenPressure().load(in.getArterialOxygenPressure());
    if (in.getPulmonaryArterialCarbonDioxidePressure() != null)
      getPulmonaryArterialCarbonDioxidePressure().load(in.getPulmonaryArterialCarbonDioxidePressure());
    if (in.getPulmonaryArterialOxygenPressure() != null)
      getPulmonaryArterialOxygenPressure().load(in.getPulmonaryArterialOxygenPressure());   
    if (in.getPulmonaryVenousCarbonDioxidePressure() != null)
      getPulmonaryVenousCarbonDioxidePressure().load(in.getPulmonaryVenousCarbonDioxidePressure());  
    if (in.getPulmonaryVenousOxygenPressure() != null)
      getPulmonaryVenousOxygenPressure().load(in.getPulmonaryVenousOxygenPressure());
    if (in.getVenousOxygenPressure() != null)
      getVenousOxygenPressure().load(in.getVenousOxygenPressure());
    if (in.getVenousCarbonDioxidePressure() != null)
      getVenousCarbonDioxidePressure().load(in.getVenousCarbonDioxidePressure());

    if (in.getArterialBicarbonateCO2Fraction() != null)
      getArterialBicarbonateCO2Fraction().load(in.getArterialBicarbonateCO2Fraction());
    if (in.getVenousBicarbonateCO2Fraction() != null)
      getVenousBicarbonateCO2Fraction().load(in.getVenousBicarbonateCO2Fraction());
    if (in.getArterialCarbaminohemoglobinCO2Fraction() != null)
      getArterialCarbaminohemoglobinCO2Fraction().load(in.getArterialCarbaminohemoglobinCO2Fraction());
    if (in.getVenousCarbaminohemoglobinCO2Fraction() != null)
      getVenousCarbaminohemoglobinCO2Fraction().load(in.getVenousCarbaminohemoglobinCO2Fraction());
    if (in.getArterialFreeFloatingCO2Fraction() != null)
      getArterialFreeFloatingCO2Fraction().load(in.getArterialFreeFloatingCO2Fraction());
    if (in.getVenousFreeFloatingCO2Fraction() != null)
      getVenousFreeFloatingCO2Fraction().load(in.getVenousFreeFloatingCO2Fraction());

    return true;
  }

  public BloodChemistrySystemData unload()
  {
    BloodChemistrySystemData data = CDMSerializer.objFactory.createBloodChemistrySystemData();
    unload(data);
    return data;
  }

  protected void unload(BloodChemistrySystemData data)
  {
    if (bloodDensity != null)
      data.setBloodDensity(bloodDensity.unload());
    if (bloodPH != null)
      data.setBloodPH(bloodPH.unload());
    if (bloodSpecificHeat != null)
      data.setBloodSpecificHeat(bloodSpecificHeat.unload());
    if (carbonDioxideSaturation != null)
      data.setCarbonDioxideSaturation(carbonDioxideSaturation.unload());
    if (extracellularFluidVolume != null)
      data.setExtracellularFluidVolume(extracellularFluidVolume.unload());
    if (extravascularFluidVolume != null)
      data.setExtravascularFluidVolume(extravascularFluidVolume.unload());
    if (intracellularFluidVolume != null)
      data.setIntracellularFluidVolume(intracellularFluidVolume.unload());
    if (intracellularFluidPH != null)
      data.setIntracellularFluidPH(intracellularFluidPH.unload());
    if (hematocrit != null)
      data.setHematocrit(hematocrit.unload());
    if (hemoglobinContent != null)
      data.setHemoglobinContent(hemoglobinContent.unload());
    if (oxygenSaturation != null)
      data.setOxygenSaturation(oxygenSaturation.unload());
    if (plasmaVolume != null)
      data.setPlasmaVolume(plasmaVolume.unload());
    if (redBloodCellCount != null)
      data.setRedBloodCellCount(redBloodCellCount.unload());
    if (shuntFraction != null)
      data.setShuntFraction(shuntFraction.unload());
    if (volumeFractionNeutralLipidInPlasma != null)
      data.setVolumeFractionNeutralLipidInPlasma(volumeFractionNeutralLipidInPlasma.unload());
    if (volumeFractionNeutralPhospholipidInPlasma != null)
      data.setVolumeFractionNeutralPhospholipidInPlasma(volumeFractionNeutralPhospholipidInPlasma.unload());
    if (whiteBloodCellCount != null)
      data.setWhiteBloodCellCount(whiteBloodCellCount.unload());

    if (albuminConcentration != null)
      data.setAlbuminConcentration(albuminConcentration.unload());
    if (bicarbonateConcentration != null)
      data.setBicarbonateConcentration(bicarbonateConcentration.unload());
    if (bloodUreaNitrogenConcentration != null)
      data.setBloodUreaNitrogenConcentration(bloodUreaNitrogenConcentration.unload());
    if (calciumConcentration != null)
      data.setCalciumConcentration(calciumConcentration.unload());
    if (creatinineConcentration != null)
      data.setCreatinineConcentration(creatinineConcentration.unload());
    if (globulinConcentration != null)
      data.setGlobulinConcentration(globulinConcentration.unload());
    if (glucoseConcentration != null)
      data.setGlucoseConcentration(glucoseConcentration.unload());
    if (hemoglobinConcentration != null)
      data.setHemoglobinConcentration(hemoglobinConcentration.unload());
    if (insulinConcentration != null)
      data.setInsulinConcentration(insulinConcentration.unload());
    if (ketoneConcentration != null)
      data.setKetoneConcentration(ketoneConcentration.unload());
    if (lactateConcentration != null)
      data.setLactateConcentration(lactateConcentration.unload());
    if (sodiumConcentration != null)
      data.setSodiumConcentration(sodiumConcentration.unload());
    if (totalProteinConcentration != null)
      data.setTotalProteinConcentration(totalProteinConcentration.unload());
    if (tristearinConcentration != null)
      data.setTristearinConcentration(tristearinConcentration.unload());
    if (ureaConcentration != null)
      data.setUreaConcentration(ureaConcentration.unload());

    if (arterialCarbonDioxidePressure != null)
      data.setArterialCarbonDioxidePressure(arterialCarbonDioxidePressure.unload());
    if (arterialOxygenPressure != null)
      data.setArterialOxygenPressure(arterialOxygenPressure.unload());
    if (pulmonaryArterialOxygenPressure != null)
      data.setPulmonaryArterialOxygenPressure(pulmonaryArterialOxygenPressure.unload());
    if (pulmonaryArterialCarbonDioxidePressure != null)
      data.setPulmonaryArterialCarbonDioxidePressure(pulmonaryArterialCarbonDioxidePressure.unload());
    if (pulmonaryVenousOxygenPressure != null)
      data.setPulmonaryVenousOxygenPressure(pulmonaryVenousOxygenPressure.unload());
    if (pulmonaryVenousCarbonDioxidePressure != null)
      data.setPulmonaryVenousCarbonDioxidePressure(pulmonaryVenousCarbonDioxidePressure.unload());
    if (venousOxygenPressure != null)
      data.setVenousOxygenPressure(venousOxygenPressure.unload());
    if (venousCarbonDioxidePressure != null)
      data.setVenousCarbonDioxidePressure(venousCarbonDioxidePressure.unload());

    if (getArterialBicarbonateCO2Fraction() != null)
      data.setArterialBicarbonateCO2Fraction(arterialBicarbonateCO2Fraction.unload());
    if (getVenousBicarbonateCO2Fraction() != null)
      data.setVenousBicarbonateCO2Fraction(venousBicarbonateCO2Fraction.unload());
    if (getArterialCarbaminohemoglobinCO2Fraction() != null)
      data.setArterialCarbaminohemoglobinCO2Fraction(arterialCarbaminohemoglobinCO2Fraction.unload());
    if (getVenousCarbaminohemoglobinCO2Fraction() != null)
      data.setVenousCarbaminohemoglobinCO2Fraction(venousCarbaminohemoglobinCO2Fraction.unload());
    if (getArterialFreeFloatingCO2Fraction() != null)
      data.setArterialFreeFloatingCO2Fraction(arterialFreeFloatingCO2Fraction.unload());
    if (getVenousFreeFloatingCO2Fraction() != null)
      data.setVenousFreeFloatingCO2Fraction(venousFreeFloatingCO2Fraction.unload());
  }

  public boolean hasBloodDensity()
  {
    return bloodDensity == null ? false : bloodDensity.isValid();
  }
  public SEScalarMassPerVolume getBloodDensity()
  {
    if (bloodDensity == null)
      bloodDensity = new SEScalarMassPerVolume();
    return bloodDensity;
  }

  public boolean hasBloodPH()
  {
    return bloodPH == null ? false : bloodPH.isValid();
  }
  public SEScalar getBloodPH()
  {
    if (bloodPH == null)
      bloodPH = new SEScalar();
    return bloodPH;  }

  public boolean hasBloodSpecificHeat()
  {
    return bloodSpecificHeat == null ? false : bloodSpecificHeat.isValid();
  }
  public SEScalarHeatCapacitancePerMass getBloodSpecificHeat()
  {
    if (bloodSpecificHeat == null)
      bloodSpecificHeat = new SEScalarHeatCapacitancePerMass();
    return bloodSpecificHeat;
  }

  public boolean hasCarbonDioxideSaturation()
  {
    return carbonDioxideSaturation == null ? false : carbonDioxideSaturation.isValid();
  }
  public SEScalarFraction getCarbonDioxideSaturation()
  {
    if (carbonDioxideSaturation == null)
      carbonDioxideSaturation = new SEScalarFraction();
    return carbonDioxideSaturation;
  }

  public boolean hasExtracellularFluidVolume()
  {
    return extracellularFluidVolume == null ? false : extracellularFluidVolume.isValid();
  }
  public SEScalarVolume getExtracellularFluidVolume()
  {
    if (extracellularFluidVolume == null)
      extracellularFluidVolume = new SEScalarVolume();
    return extracellularFluidVolume;
  }

  public boolean hasExtravascularFluidVolume()
  {
    return extravascularFluidVolume == null ? false : extravascularFluidVolume.isValid();
  }
  public SEScalarVolume getExtravascularFluidVolume()
  {
    if (extravascularFluidVolume == null)
      extravascularFluidVolume = new SEScalarVolume();
    return extravascularFluidVolume;
  }

  public boolean hasIntracellularFluidVolume()
  {
    return intracellularFluidVolume == null ? false : intracellularFluidVolume.isValid();
  }
  public SEScalarVolume getIntracellularFluidVolume()
  {
    if (intracellularFluidVolume == null)
      intracellularFluidVolume = new SEScalarVolume();
    return intracellularFluidVolume;
  }

  public boolean hasIntracellularFluidPH()
  {
    return intracellularFluidPH == null ? false : intracellularFluidPH.isValid();
  }
  public SEScalar getIntracellularFluidPH()
  {
    if (intracellularFluidPH == null)
      intracellularFluidPH = new SEScalar();
    return intracellularFluidPH;
  }

  public boolean hasHematocrit()
  {
    return hematocrit == null ? false : hematocrit.isValid();
  }
  public SEScalarFraction getHematocrit()
  {
    if (hematocrit == null)
      hematocrit = new SEScalarFraction();
    return hematocrit;  }

  public boolean hasHemoglobinContent()
  {
    return hemoglobinContent == null ? false : hemoglobinContent.isValid();
  }
  public SEScalarMass getHemoglobinContent()
  {
    if (hemoglobinContent == null)
      hemoglobinContent = new SEScalarMass();
    return hemoglobinContent;  }

  public boolean hasOxygenSaturation()
  {
    return oxygenSaturation == null ? false : oxygenSaturation.isValid();
  }
  public SEScalarFraction getOxygenSaturation()
  {
    if (oxygenSaturation == null)
      oxygenSaturation = new SEScalarFraction();
    return oxygenSaturation;  }

  public boolean hasPlasmaVolume()
  {
    return plasmaVolume == null ? false : plasmaVolume.isValid();
  }
  public SEScalarVolume getPlasmaVolume()
  {
    if (plasmaVolume == null)
      plasmaVolume = new SEScalarVolume();
    return plasmaVolume;
  }

  public boolean hasRedBloodCellCount()
  {
    return redBloodCellCount == null ? false : redBloodCellCount.isValid();
  }
  public SEScalarAmountPerVolume getRedBloodCellCount()
  {
    if (redBloodCellCount == null)
      redBloodCellCount = new SEScalarAmountPerVolume();
    return redBloodCellCount;  }

  public boolean hasShuntFraction()
  {
    return shuntFraction == null ? false : shuntFraction.isValid();
  }
  public SEScalarFraction getShuntFraction()
  {
    if (shuntFraction == null)
      shuntFraction = new SEScalarFraction();
    return shuntFraction;  }

  public boolean hasVolumeFractionNeutralLipidInPlasma()
  {
    return volumeFractionNeutralLipidInPlasma == null ? false : volumeFractionNeutralLipidInPlasma.isValid();
  }
  public SEScalarFraction getVolumeFractionNeutralLipidInPlasma()
  {
    if (volumeFractionNeutralLipidInPlasma == null)
      volumeFractionNeutralLipidInPlasma = new SEScalarFraction();
    return volumeFractionNeutralLipidInPlasma;
  }

  public boolean hasVolumeFractionNeutralPhospholipidInPlasma()
  {
    return volumeFractionNeutralPhospholipidInPlasma == null ? false : volumeFractionNeutralPhospholipidInPlasma.isValid();
  }
  public SEScalarFraction getVolumeFractionNeutralPhospholipidInPlasma()
  {
    if (volumeFractionNeutralPhospholipidInPlasma == null)
      volumeFractionNeutralPhospholipidInPlasma = new SEScalarFraction();
    return volumeFractionNeutralPhospholipidInPlasma;
  }

  public boolean hasWhiteBloodCellCount()
  {
    return whiteBloodCellCount == null ? false : whiteBloodCellCount.isValid();
  }
  public SEScalarAmountPerVolume getWhiteBloodCellCount()
  {
    if (whiteBloodCellCount == null)
      whiteBloodCellCount = new SEScalarAmountPerVolume();
    return whiteBloodCellCount;
  }

  public boolean hasAlbuminConcentration()
  {
    return albuminConcentration == null ? false : albuminConcentration.isValid();
  }
  public SEScalarMassPerVolume getAlbuminConcentration()
  {
    if (albuminConcentration == null)
      albuminConcentration = new SEScalarMassPerVolume();
    return albuminConcentration;
  }

  public boolean hasBicarbonateConcentration()
  {
    return bicarbonateConcentration == null ? false : bicarbonateConcentration.isValid();
  }
  public SEScalarMassPerVolume getBicarbonateConcentration()
  {
    if (bicarbonateConcentration == null)
      bicarbonateConcentration = new SEScalarMassPerVolume();
    return bicarbonateConcentration;  }

  public boolean hasBloodUreaNitrogenConcentration()
  {
    return bloodUreaNitrogenConcentration == null ? false : bloodUreaNitrogenConcentration.isValid();
  }
  public SEScalarMassPerVolume getBloodUreaNitrogenConcentration()
  {
    if (bloodUreaNitrogenConcentration == null)
      bloodUreaNitrogenConcentration = new SEScalarMassPerVolume();
    return bloodUreaNitrogenConcentration;
  }

  public boolean hasCalciumConcentration()
  {
    return calciumConcentration == null ? false : calciumConcentration.isValid();
  }
  public SEScalarMassPerVolume getCalciumConcentration()
  {
    if (calciumConcentration == null)
      calciumConcentration = new SEScalarMassPerVolume();
    return calciumConcentration;
  }

  public boolean hasCreatinineConcentration()
  {
    return creatinineConcentration == null ? false : creatinineConcentration.isValid();
  }
  public SEScalarMassPerVolume getCreatinineConcentration()
  {
    if (creatinineConcentration == null)
      creatinineConcentration = new SEScalarMassPerVolume();
    return creatinineConcentration;
  }

  public boolean hasGlucoseConcentration()
  {
    return glucoseConcentration == null ? false : glucoseConcentration.isValid();
  }
  public SEScalarMassPerVolume getGlucoseConcentration()
  {
    if (glucoseConcentration == null)
      glucoseConcentration = new SEScalarMassPerVolume();
    return glucoseConcentration;
  }

  public boolean hasGlobulinConcentration()
  {
    return globulinConcentration == null ? false : globulinConcentration.isValid();
  }
  public SEScalarMassPerVolume getGlobulinConcentration()
  {
    if (globulinConcentration == null)
      globulinConcentration = new SEScalarMassPerVolume();
    return globulinConcentration;
  }

  public boolean hasHemoglobinConcentration()
  {
    return hemoglobinConcentration == null ? false : hemoglobinConcentration.isValid();
  }
  public SEScalarMassPerVolume getHemoglobinConcentration()
  {
    if (hemoglobinConcentration == null)
      hemoglobinConcentration = new SEScalarMassPerVolume();
    return hemoglobinConcentration;
  }

  public boolean hasInsulinConcentration()
  {
    return insulinConcentration == null ? false : insulinConcentration.isValid();
  }
  public SEScalarMassPerVolume getInsulinConcentration()
  {
    if (insulinConcentration == null)
      insulinConcentration = new SEScalarMassPerVolume();
    return insulinConcentration;
  }

  public boolean hasKetoneConcentration()
  {
    return ketoneConcentration == null ? false : ketoneConcentration.isValid();
  }
  public SEScalarMassPerVolume getKetoneConcentration()
  {
    if (ketoneConcentration == null)
      ketoneConcentration = new SEScalarMassPerVolume();
    return ketoneConcentration;
  }

  public boolean hasLactateConcentration()
  {
    return lactateConcentration == null ? false : lactateConcentration.isValid();
  }
  public SEScalarMassPerVolume getLactateConcentration()
  {
    if (lactateConcentration == null)
      lactateConcentration = new SEScalarMassPerVolume();
    return lactateConcentration;
  }

  public boolean hasSodiumConcentration()
  {
    return sodiumConcentration == null ? false : sodiumConcentration.isValid();
  }
  public SEScalarMassPerVolume getSodiumConcentration()
  {
    if (sodiumConcentration == null)
      sodiumConcentration = new SEScalarMassPerVolume();
    return sodiumConcentration;  }

  public boolean hasTotalProteinConcentration()
  {
    return totalProteinConcentration == null ? false : totalProteinConcentration.isValid();
  }
  public SEScalarMassPerVolume getTotalProteinConcentration()
  {
    if (totalProteinConcentration == null)
      totalProteinConcentration = new SEScalarMassPerVolume();
    return totalProteinConcentration;
  }

  public boolean hasTristearinConcentration()
  {
    return tristearinConcentration == null ? false : tristearinConcentration.isValid();
  }
  public SEScalarMassPerVolume getTristearinConcentration()
  {
    if (tristearinConcentration == null)
      tristearinConcentration = new SEScalarMassPerVolume();
    return tristearinConcentration;
  }

  public boolean hasUreaConcentration()
  {
    return ureaConcentration == null ? false : ureaConcentration.isValid();
  }
  public SEScalarMassPerVolume getUreaConcentration()
  {
    if (ureaConcentration == null)
      ureaConcentration = new SEScalarMassPerVolume();
    return ureaConcentration;  }

  public boolean hasArterialCarbonDioxidePressure()
  {
    return arterialCarbonDioxidePressure == null ? false : arterialCarbonDioxidePressure.isValid();
  }
  public SEScalarPressure getArterialCarbonDioxidePressure()
  {
    if (arterialCarbonDioxidePressure == null)
      arterialCarbonDioxidePressure = new SEScalarPressure();
    return arterialCarbonDioxidePressure;
  }

  public boolean hasArterialOxygenPressure()
  {
    return arterialOxygenPressure == null ? false : arterialOxygenPressure.isValid();
  }
  public SEScalarPressure getArterialOxygenPressure()
  {
    if (arterialOxygenPressure == null)
      arterialOxygenPressure = new SEScalarPressure();
    return arterialOxygenPressure;
  }

  public boolean hasPulmonaryArterialCarbonDioxidePressure()
  {
    return pulmonaryArterialCarbonDioxidePressure == null ? false : pulmonaryArterialCarbonDioxidePressure.isValid();
  }
  public SEScalarPressure getPulmonaryArterialCarbonDioxidePressure()
  {
    if (pulmonaryArterialCarbonDioxidePressure == null)
      pulmonaryArterialCarbonDioxidePressure = new SEScalarPressure();
    return pulmonaryArterialCarbonDioxidePressure;
  }

  public boolean hasPulmonaryArterialOxygenPressure()
  {
    return pulmonaryArterialOxygenPressure == null ? false : pulmonaryArterialOxygenPressure.isValid();
  }
  public SEScalarPressure getPulmonaryArterialOxygenPressure()
  {
    if (pulmonaryArterialOxygenPressure == null)
      pulmonaryArterialOxygenPressure = new SEScalarPressure();
    return pulmonaryArterialOxygenPressure;
  }

  public boolean hasPulmonaryVenousCarbonDioxidePressure()
  {
    return pulmonaryVenousCarbonDioxidePressure == null ? false : pulmonaryVenousCarbonDioxidePressure.isValid();
  }
  public SEScalarPressure getPulmonaryVenousCarbonDioxidePressure()
  {
    if (pulmonaryVenousCarbonDioxidePressure == null)
      pulmonaryVenousCarbonDioxidePressure = new SEScalarPressure();
    return pulmonaryVenousCarbonDioxidePressure;
  }

  public boolean hasPulmonaryVenousOxygenPressure()
  {
    return pulmonaryVenousOxygenPressure == null ? false : pulmonaryVenousOxygenPressure.isValid();
  }
  public SEScalarPressure getPulmonaryVenousOxygenPressure()
  {
    if (pulmonaryVenousOxygenPressure == null)
      pulmonaryVenousOxygenPressure = new SEScalarPressure();
    return pulmonaryVenousOxygenPressure;  }

  public boolean hasVenousCarbonDioxidePressure()
  {
    return venousCarbonDioxidePressure == null ? false : venousCarbonDioxidePressure.isValid();
  }
  public SEScalarPressure getVenousCarbonDioxidePressure()
  {
    if (venousCarbonDioxidePressure == null)
      venousCarbonDioxidePressure = new SEScalarPressure();
    return venousCarbonDioxidePressure;
  }

  public boolean hasVenousOxygenPressure()
  {
    return venousOxygenPressure == null ? false : venousOxygenPressure.isValid();
  }
  public SEScalarPressure getVenousOxygenPressure()
  {
    if (venousOxygenPressure == null)
      venousOxygenPressure = new SEScalarPressure();
    return venousOxygenPressure;  }

  public boolean hasArterialBicarbonateCO2Fraction()
  {
    return arterialBicarbonateCO2Fraction == null ? false : arterialBicarbonateCO2Fraction.isValid();
  }
  public SEScalarFraction getArterialBicarbonateCO2Fraction()
  {
    if (arterialBicarbonateCO2Fraction == null)
      arterialBicarbonateCO2Fraction = new SEScalarFraction();
    return arterialBicarbonateCO2Fraction;
  }

  public boolean hasVenousBicarbonateCO2Fraction()
  {
    return venousBicarbonateCO2Fraction == null ? false : venousBicarbonateCO2Fraction.isValid();
  }
  public SEScalarFraction getVenousBicarbonateCO2Fraction()
  {
    if (venousBicarbonateCO2Fraction == null)
      venousBicarbonateCO2Fraction = new SEScalarFraction();
    return venousBicarbonateCO2Fraction;
  }

  public boolean hasArterialCarbaminohemoglobinCO2Fraction()
  {
    return arterialCarbaminohemoglobinCO2Fraction == null ? false : arterialCarbaminohemoglobinCO2Fraction.isValid();
  }
  public SEScalarFraction getArterialCarbaminohemoglobinCO2Fraction()
  {
    if (arterialCarbaminohemoglobinCO2Fraction == null)
      arterialCarbaminohemoglobinCO2Fraction = new SEScalarFraction();
    return arterialCarbaminohemoglobinCO2Fraction;
  }

  public boolean hasVenousCarbaminohemoglobinCO2Fraction()
  {
    return venousCarbaminohemoglobinCO2Fraction == null ? false : venousCarbaminohemoglobinCO2Fraction.isValid();
  }
  public SEScalarFraction getVenousCarbaminohemoglobinCO2Fraction()
  {
    if (venousCarbaminohemoglobinCO2Fraction == null)
      venousCarbaminohemoglobinCO2Fraction = new SEScalarFraction();
    return venousCarbaminohemoglobinCO2Fraction;
  }

  public boolean hasArterialFreeFloatingCO2Fraction()
  {
    return arterialFreeFloatingCO2Fraction == null ? false : arterialFreeFloatingCO2Fraction.isValid();
  }
  public SEScalarFraction getArterialFreeFloatingCO2Fraction()
  {
    if (arterialFreeFloatingCO2Fraction == null)
      arterialFreeFloatingCO2Fraction = new SEScalarFraction();
    return arterialFreeFloatingCO2Fraction;
  }

  public boolean hasVenousFreeFloatingCO2Fraction()
  {
    return venousFreeFloatingCO2Fraction == null ? false : venousFreeFloatingCO2Fraction.isValid();
  }
  public SEScalarFraction getVenousFreeFloatingCO2Fraction()
  {
    if (venousFreeFloatingCO2Fraction == null)
      venousFreeFloatingCO2Fraction = new SEScalarFraction();
    return venousFreeFloatingCO2Fraction;
  }
}
