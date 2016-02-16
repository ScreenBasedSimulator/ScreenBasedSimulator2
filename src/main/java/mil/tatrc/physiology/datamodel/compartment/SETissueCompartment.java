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

import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.TissueCompartmentData;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarPressure;
import mil.tatrc.physiology.datamodel.properties.SEScalarVolume;
import mil.tatrc.physiology.datamodel.properties.SEScalarVolumePerTime;
import mil.tatrc.physiology.datamodel.substance.SESubstance;

public class SETissueCompartment<T> extends SECompartment<T>
{
	protected SEScalarVolume        tissueVolume;
	
	protected SEScalarVolumePerTime extravascularInFlow;
  protected SEScalarVolumePerTime extravascularOutFlow;
  protected SEScalarPressure      extravascularPressure;  
  protected SEScalarVolume        extravascularVolume;
  protected SEScalarVolume        extravascularUnstressedVolume;
  
	protected SEScalarFraction      metabolicFraction;
	
	protected List<SETissueCompartmentSubstanceQuantity> substanceQuantities = new ArrayList<SETissueCompartmentSubstanceQuantity>();
	
	public SETissueCompartment()
	{
	  tissueVolume = null;
		extravascularInFlow = null;
    extravascularOutFlow = null;
    extravascularPressure = null;    
    extravascularVolume = null;
    extravascularUnstressedVolume = null;
		metabolicFraction = null;
	}
	
	public void reset()
	{
	  super.reset();
		if (tissueVolume != null)
		  tissueVolume.invalidate();
		
		if (extravascularPressure != null)
      extravascularPressure.invalidate();
    if (extravascularInFlow != null)
      extravascularInFlow.invalidate();
    if (extravascularOutFlow != null)
      extravascularOutFlow.invalidate();
    if (extravascularVolume != null)
      extravascularVolume.invalidate();
    if (extravascularUnstressedVolume != null)
      extravascularUnstressedVolume.invalidate();
    
		if (metabolicFraction != null)
			metabolicFraction.invalidate();
	}
	
	public boolean load(TissueCompartmentData in)
	{
		super.load(in);
		if (in.getTissueVolume() != null) 
		   getTissueVolume().load(in.getTissueVolume()); 
		
		if (in.getExtravascularPressure() != null) 
      getExtravascularPressure().load(in.getExtravascularPressure()); 
   if (in.getExtravascularInFlow() != null) 
      getExtravascularInFlow().load(in.getExtravascularInFlow()); 
   if (in.getExtravascularOutFlow() != null) 
     getExtravascularOutFlow().load(in.getExtravascularOutFlow()); 
   if (in.getExtravascularVolume() != null) 
      getExtravascularVolume().load(in.getExtravascularVolume()); 
   if (in.getExtravascularUnstressedVolume() != null) 
      getExtravascularUnstressedVolume().load(in.getExtravascularUnstressedVolume()); 
   
		if (in.getMetabolicFraction() != null)
			getMetabolicFraction().load(in.getMetabolicFraction());

		return true;
	}
	
	public TissueCompartmentData unload()
	{
		TissueCompartmentData to = CDMSerializer.objFactory.createTissueCompartmentData();
		unload(to);
		return to;		
	}
	
	protected void unload(TissueCompartmentData data)
	{
	  super.unload(data);
		if (tissueVolume != null)
			data.setTissueVolume(tissueVolume.unload());
		
		if (extravascularPressure != null)
      data.setExtravascularPressure(extravascularPressure.unload());
    if (extravascularInFlow != null)
      data.setExtravascularInFlow(extravascularInFlow.unload());
    if (extravascularOutFlow != null)
      data.setExtravascularOutFlow(extravascularOutFlow.unload());
    if (extravascularVolume != null)
      data.setExtravascularVolume(extravascularVolume.unload());
    if (extravascularUnstressedVolume != null)
      data.setExtravascularUnstressedVolume(extravascularUnstressedVolume.unload());  
    
		if (metabolicFraction != null)
			data.setMetabolicFraction(metabolicFraction.unload());
	}

	public SEScalarVolume getTissueVolume() 
	{
		if (tissueVolume == null)
		  tissueVolume = new SEScalarVolume();
		return tissueVolume;
	}
	public boolean hasTissueVolume()
	{
		return tissueVolume == null ? false : tissueVolume.isValid();
	}

	public SEScalarVolumePerTime getExtravascularInFlow() 
  {
    if (extravascularInFlow == null)
      extravascularInFlow = new SEScalarVolumePerTime();
    return extravascularInFlow;
  }
  public boolean hasExtravascularInFlow()
  {
    return extravascularInFlow == null ? false : extravascularInFlow.isValid();
  }
  
  public SEScalarVolumePerTime getExtravascularOutFlow() 
  {
    if (extravascularOutFlow == null)
      extravascularOutFlow = new SEScalarVolumePerTime();
    return extravascularOutFlow;
  }
  public boolean hasExtravascularOutFlow()
  {
    return extravascularOutFlow == null ? false : extravascularOutFlow.isValid();
  }
  
  public SEScalarPressure getExtravascularPressure() 
  {
    if (extravascularPressure == null)
      extravascularPressure = new SEScalarPressure();
    return extravascularPressure;
  }
  public boolean hasExtravascularPressure()
  {
    return extravascularPressure == null ? false : extravascularPressure.isValid();
  }
  
  public SEScalarVolume getExtravascularVolume() 
  {
    if (extravascularVolume == null)
      extravascularVolume = new SEScalarVolume();
    return extravascularVolume;
  }
  public boolean hasExtravascularVolume()
  {
    return extravascularVolume == null ? false : extravascularVolume.isValid();
  }
  
  public SEScalarVolume getExtravascularUnstressedVolume() 
  {
    if (extravascularUnstressedVolume == null)
      extravascularUnstressedVolume = new SEScalarVolume();
    return extravascularUnstressedVolume;
  }
  public boolean hasUExtravascularnstressedVolume()
  {
    return extravascularUnstressedVolume == null ? false : extravascularUnstressedVolume.isValid();
  }
	
	public SEScalarFraction getMetabolicFraction()
	{
		if (metabolicFraction == null)
			metabolicFraction = new SEScalarFraction();
		return metabolicFraction;
	}
	public boolean hasMetabolicFraction()
	{
		return metabolicFraction == null ? false : metabolicFraction.isValid();
	}
	
	public boolean hasSubstanceQuantity()
  {
    return substanceQuantities.size() > 0 ? true : false;
  }
  public boolean hasSubstanceQuantity(SESubstance substance)
  {
    for (SETissueCompartmentSubstanceQuantity csq : substanceQuantities)
    {
      if (csq.getSubstance() == substance)
        return true;
    }
    return false;
  }
  public SETissueCompartmentSubstanceQuantity getSubstanceQuantity(SESubstance substance)
  {
    for (SETissueCompartmentSubstanceQuantity csq : substanceQuantities)
    {
      if (substance == csq.getSubstance())
        return csq;
    }
    SETissueCompartmentSubstanceQuantity csq = new SETissueCompartmentSubstanceQuantity(substance);
    substanceQuantities.add(csq);
    return csq;
  }
  public List<SETissueCompartmentSubstanceQuantity> getSubstanceQuantities()
  {
    return substanceQuantities;
  }
  public void removeSubstanceQuantity(SESubstance substance)
  {
    for (SETissueCompartmentSubstanceQuantity csq : substanceQuantities)
    {
      if (csq.getSubstance() == substance)
      {
        substanceQuantities.remove(csq);
        return;
      }
    }
  }
  public void removeSubstanceQuantity(String substanceName)
  {
    for (SETissueCompartmentSubstanceQuantity csq : substanceQuantities)
    {
      if (csq.getSubstance().getName().equals(substanceName))
      {
        substanceQuantities.remove(csq);
        return;
      }
    }
  }
}
