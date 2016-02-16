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
import mil.tatrc.physiology.datamodel.bind.TissueCompartmentSubstanceQuantityData;
import mil.tatrc.physiology.datamodel.properties.SEScalarAmountPerVolume;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarMass;
import mil.tatrc.physiology.datamodel.properties.SEScalarMassPerVolume;
import mil.tatrc.physiology.datamodel.properties.SEScalarPressure;
import mil.tatrc.physiology.datamodel.substance.SESubstance;

public class SETissueCompartmentSubstanceQuantity extends SECompartmentSubstanceQuantity
{
  protected SESubstance             substance;
  
  protected SEScalarMass            mass;
  
  protected SEScalarMassPerVolume   tissueConcentration;
  protected SEScalarAmountPerVolume tissueMolarity;
  
  protected SEScalarMassPerVolume   extravascularConcentration;
  protected SEScalarAmountPerVolume extravascularMolarity;
  protected SEScalarPressure        extravascularPartialPressure;
  protected SEScalarFraction        extravascularSaturation;

  public SETissueCompartmentSubstanceQuantity(SESubstance substance)
  {

    this.substance = substance;
    
    mass = null;
    
    tissueConcentration = null;
    tissueMolarity = null;
    
    extravascularConcentration = null;
    extravascularMolarity = null;
    extravascularPartialPressure = null;
    extravascularSaturation = null;
  }

  public void reset()
  {
    super.reset();
    if (mass != null)
      mass.invalidate();
    
    if (tissueConcentration != null)
      tissueConcentration.invalidate();
    if (tissueMolarity != null)
      tissueMolarity.invalidate();
   
    if (extravascularConcentration != null)
      extravascularConcentration.invalidate();
    if (extravascularMolarity != null)
      extravascularMolarity.invalidate();
    if (extravascularPartialPressure != null)
      extravascularPartialPressure.invalidate();
    if (extravascularSaturation != null)
      extravascularSaturation.invalidate();
  }

  public boolean load(TissueCompartmentSubstanceQuantityData in)
  {
    super.load(in);
    if (in.getMass() != null) 
      getMass().load(in.getMass()); 
    
    if (in.getTissueConcentration() != null) 
      getTissueConcentration().load(in.getTissueConcentration()); 
    if (in.getTissueMolarity() != null) 
      getTissueMolarity().load(in.getTissueMolarity()); 
    
    if (in.getExtravascularConcentration() != null) 
      getExtravascularConcentration().load(in.getExtravascularConcentration()); 
    if (in.getExtravascularMolarity() != null) 
      getExtravascularMolarity().load(in.getExtravascularMolarity()); 
    if (in.getExtravascularPartialPressure() != null) 
      getExtravascularPartialPressure().load(in.getExtravascularPartialPressure()); 
    if (in.getExtravascularSaturation() != null) 
      getExtravascularSaturation().load(in.getExtravascularSaturation()); 
  
    return true;
  }

  public TissueCompartmentSubstanceQuantityData unload()
  {
    TissueCompartmentSubstanceQuantityData data = CDMSerializer.objFactory.createTissueCompartmentSubstanceQuantityData();
    unload(data);
    return data;
  }

  protected void unload(TissueCompartmentSubstanceQuantityData data)
  {
    super.unload(data);
    if (hasMass())
      data.setMass(mass.unload());
    
    if (hasTissueConcentration())
      data.setTissueConcentration(tissueConcentration.unload());
    if (hasTissueMolarity())
      data.setTissueMolarity(tissueMolarity.unload());
    
        
    if (hasExtravascularConcentration())
      data.setExtravascularConcentration(extravascularConcentration.unload());
    if (hasExtravascularMolarity())
      data.setExtravascularMolarity(extravascularMolarity.unload());
    if (hasExtravascularPartialPressure())
      data.setExtravascularPartialPressure(extravascularPartialPressure.unload());
    if (hasExtravascularSaturation())
      data.setExtravascularSaturation(extravascularSaturation.unload());	 
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
  
  public boolean hasTissueConcentration()
  {
    return tissueConcentration == null ? false : tissueConcentration.isValid();
  }
  public SEScalarMassPerVolume getTissueConcentration()
  {
    if (tissueConcentration == null)
      tissueConcentration = new SEScalarMassPerVolume();
    return tissueConcentration;
  }

  public boolean hasTissueMolarity()
  {
    return tissueMolarity == null ? false : tissueMolarity.isValid();
  }
  public SEScalarAmountPerVolume getTissueMolarity()
  {
    if (tissueMolarity == null)
      tissueMolarity = new SEScalarAmountPerVolume();
    return tissueMolarity;
  }

  public boolean hasExtravascularConcentration()
  {
    return extravascularConcentration == null ? false : extravascularConcentration.isValid();
  }
  public SEScalarMassPerVolume getExtravascularConcentration()
  {
    if (extravascularConcentration == null)
      extravascularConcentration = new SEScalarMassPerVolume();
    return extravascularConcentration;
  }

  public boolean hasExtravascularMolarity()
  {
    return extravascularMolarity == null ? false : extravascularMolarity.isValid();
  }
  public SEScalarAmountPerVolume getExtravascularMolarity()
  {
    if (extravascularMolarity == null)
      extravascularMolarity = new SEScalarAmountPerVolume();
    return extravascularMolarity;
  }

  public boolean hasExtravascularPartialPressure()
  {
    return extravascularPartialPressure == null ? false : extravascularPartialPressure.isValid();
  }
  public SEScalarPressure getExtravascularPartialPressure()
  {
    if (extravascularPartialPressure == null)
      extravascularPartialPressure = new SEScalarPressure();
    return extravascularPartialPressure;
  }

  public boolean hasExtravascularSaturation()
  {
    return extravascularSaturation == null ? false : extravascularSaturation.isValid();
  }
  public SEScalarFraction getExtravascularSaturation()
  {
    if (extravascularSaturation == null)
      extravascularSaturation = new SEScalarFraction();
    return extravascularSaturation;
  }

  public SESubstance getSubstance()
  {
    return substance;
  }
}
