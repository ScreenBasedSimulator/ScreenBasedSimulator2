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

package mil.tatrc.physiology.datamodel.compartment;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.LiquidCompartmentSubstanceQuantityData;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.AmountPerVolumeUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.MassPerAmountUnit;
import mil.tatrc.physiology.datamodel.properties.SEScalarAmountPerVolume;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarMass;
import mil.tatrc.physiology.datamodel.properties.SEScalarMassPerVolume;
import mil.tatrc.physiology.datamodel.properties.SEScalarPressure;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.MassPerVolumeUnit;
import mil.tatrc.physiology.datamodel.substance.SESubstance;

public class SELiquidCompartmentSubstanceQuantity extends SECompartmentSubstanceQuantity
{
  protected SEScalarMassPerVolume   concentration;
  protected SEScalarMass            mass;
  protected SEScalarAmountPerVolume molarity;
  protected SEScalarPressure        partialPressure;
  protected SEScalarFraction        saturation;
  protected SESubstance             substance;



  public SELiquidCompartmentSubstanceQuantity(SESubstance substance)
  {
    concentration = null;
    mass = null;
    molarity = null;
    partialPressure = null;
    saturation = null;
    this.substance = substance;
  }

  public void reset()
  {
    super.reset();
    if (concentration != null)
      concentration.invalidate();
    if (mass != null)
      mass.invalidate();
    if (molarity != null)
      molarity.invalidate();
    if (partialPressure != null)
      partialPressure.invalidate();
    if (saturation != null)
      saturation.invalidate();
  }

  public boolean load(LiquidCompartmentSubstanceQuantityData in)
  {
    super.load(in);
    if (in.getConcentration() != null) 
      getConcentration().load(in.getConcentration()); 
    if (in.getMass() != null) 
      getMass().load(in.getMass()); 
    if (in.getPartialPressure() != null) 
      getPartialPressure().load(in.getPartialPressure()); 
    if (in.getSaturation() != null) 
      getSaturation().load(in.getSaturation()); 
  
    return true;
  }

  public LiquidCompartmentSubstanceQuantityData unload()
  {
    LiquidCompartmentSubstanceQuantityData data = CDMSerializer.objFactory.createLiquidCompartmentSubstanceQuantityData();
    unload(data);
    return data;
  }

  protected void unload(LiquidCompartmentSubstanceQuantityData data)
  {
    super.unload(data);
    if (hasConcentration())
      data.setConcentration(concentration.unload());
    if (hasMass())
      data.setMass(mass.unload());
    if (hasPartialPressure())
      data.setPartialPressure(partialPressure.unload());
    if (hasSaturation())
      data.setSaturation(saturation.unload());	 
  }	

  public boolean hasConcentration()
  {
    return concentration == null ? false : concentration.isValid();
  }
  public SEScalarMassPerVolume getConcentration()
  {
    if (concentration == null)
      concentration = new SEScalarMassPerVolume();
    return concentration;
  }

  public boolean hasMass()
  {
    return mass == null ? false : mass.isValid();
  }
  public SEScalarMass getMass()
  {
    if (mass == null)
      mass = new SEScalarMass();
    return mass;
  }
  
  public boolean hasMolarity()
  {
    return molarity == null ? false : molarity.isValid();
  }
  public SEScalarAmountPerVolume getMolarity()
  {
    if (molarity == null)
      molarity = new SEScalarAmountPerVolume();
    molarity.setValue(getConcentration().getValue(MassPerVolumeUnit.ug_Per_mL)/substance.getMolarMass().getValue(MassPerAmountUnit.ug_Per_mol),AmountPerVolumeUnit.mol_Per_mL);
    return molarity;
  }

  public boolean hasPartialPressure()
  {
    return partialPressure == null ? false : partialPressure.isValid();
  }
  public SEScalarPressure getPartialPressure()
  {
    if (partialPressure == null)
      partialPressure = new SEScalarPressure();
    return partialPressure;
  }

  public boolean hasSaturation()
  {
    return saturation == null ? false : saturation.isValid();
  }
  public SEScalarFraction getSaturation()
  {
    if (saturation == null)
      saturation = new SEScalarFraction();
    return saturation;
  }

  public SESubstance getSubstance()
  {
    return substance;
  }
}
