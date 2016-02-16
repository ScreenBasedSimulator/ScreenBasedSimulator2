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

package mil.tatrc.physiology.datamodel.substance;

import java.util.ArrayList;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.utilities.StringUtils;

public class SESubstance
{
	protected EnumSubstanceState               state;
	protected String                           name;
	protected SEScalarMassPerVolume            density;
  protected SEScalarMassPerAmount            molarMass;
  // Liquid related-ish
  protected SESubstanceAerosolization        aerosolization;
  protected SEScalarMass                     massInBody;  
  protected SEScalarMass                     massInBlood;  
  protected SEScalarMass                     massInTissue;  
  protected SEScalarMassPerVolume            plasmaConcentration;
  protected SEScalarMass                     remainingSystemicMassCleared;
  // Gas related-ish
	protected SEScalarVolumePerTime            alveolarTransfer;
	protected SEScalarVolumePerTimePerPressure diffusingCapacity;
	protected SEScalarFraction                 endTidalConcentration;
	protected SEScalar                         relativeDiffusionCoefficient;
	protected SEScalarInversePressure          solubilityCoefficient;
	
	protected SESubstanceClearance             clearance;
	protected SESubstancePharmacokinetics      pk;
	protected SESubstancePharmacodynamics      pd;
	
	protected List<SESubstanceCompartmentEffect> compartmentEffects;
	
	public SESubstance()
	{
		
	}
	
	public void reset()
	{
		this.name=null;
		this.state=null;
		if(this.density!=null)
      this.density.invalidate();
    if(this.molarMass!=null)
			this.molarMass.invalidate();
		
		if(this.aerosolization!=null)
      this.aerosolization.reset();
		if(this.massInBody!=null)
      this.massInBody.invalidate();
		if(this.massInBlood!=null)
      this.massInBlood.invalidate();
		if(this.massInTissue!=null)
      this.massInTissue.invalidate();
    if(this.plasmaConcentration!=null)
      this.plasmaConcentration.invalidate();
		if(this.remainingSystemicMassCleared!=null)
      this.remainingSystemicMassCleared.invalidate();
    
		if(this.alveolarTransfer!=null)
			this.alveolarTransfer.invalidate();
		if(this.diffusingCapacity!=null)
      this.diffusingCapacity.invalidate();
    if(this.endTidalConcentration!=null)
			this.endTidalConcentration.invalidate();
		if(this.relativeDiffusionCoefficient!=null)
      this.relativeDiffusionCoefficient.invalidate();
    if(this.solubilityCoefficient!=null)
			this.solubilityCoefficient.invalidate();
		
    if(this.clearance!=null)
      this.clearance.reset();
    if(this.pk!=null)
      this.pk.reset();
    if(this.pd!=null)
      this.pd.reset();
    
		if(this.compartmentEffects!=null)
			this.compartmentEffects.clear();
	}
	
	public boolean load(SubstanceData data)
	{
		this.reset();
		if(data.getName()!=null)
			this.setName(data.getName());
		if(data.getState()!=null)
			this.setState(data.getState());
		if(data.getDensity()!=null)
      this.getDensity().load(data.getDensity());    
		if(data.getMolarMass()!=null)
			this.getMolarMass().load(data.getMolarMass());
	
		
		if(data.getAerosolization()!=null)
		  this.getAerosolization().load(data.getAerosolization());
		if(data.getMassInBody()!=null)
      this.getMassInBody().load(data.getMassInBody());
		if(data.getMassInBlood()!=null)
      this.getMassInBlood().load(data.getMassInBlood());
		if(data.getMassInTissue()!=null)
      this.getMassInTissue().load(data.getMassInTissue());
    if(data.getPlasmaConcentration()!=null)
      this.getPlasmaConcentration().load(data.getPlasmaConcentration());
		if(data.getRemainingSystemicMassCleared()!=null)
      this.getRemainingSystemicMassCleared().load(data.getRemainingSystemicMassCleared());
    
		if(data.getAlveolarTransfer()!=null)
		  this.getAlveolarTransfer().load(data.getAlveolarTransfer());
		if(data.getDiffusingCapacity()!=null)
		  this.getDiffusingCapacity().load(data.getDiffusingCapacity());
		if(data.getEndTidalConcentration()!=null)
		  this.getEndTidalConcentration().load(data.getEndTidalConcentration());
		if(data.getRelativeDiffusionCoefficient()!=null)
		  this.getRelativeDiffusionCoefficient().load(data.getRelativeDiffusionCoefficient());
		if(data.getSolubilityCoefficient()!=null)
		  this.getSolubilityCoefficient().load(data.getSolubilityCoefficient());

		if(data.getClearance()!=null)
      this.getClearance().load(data.getClearance());
    if(data.getPharmacokinetics()!=null)
      this.getPK().load(data.getPharmacokinetics());
		if(data.getPharmacodynamics()!=null)
      this.getPD().load(data.getPharmacodynamics());
    
		if(data.getCompartmentEffect()!=null)
		{			
			for(SubstanceCompartmentEffectData fxData : data.getCompartmentEffect())
			{
				this.createAnatomyEffect().load(fxData);
			}
		}
		
		return true;
	}
	
	public SubstanceData unload()
	{
		SubstanceData to = CDMSerializer.objFactory.createSubstanceData();
		unload(to);
		return to;
	}
	
	protected void unload(SubstanceData to)
	{
		if(hasName())
			to.setName(this.name);
		if(hasState())
			to.setState(this.state);
		if(hasDensity())
      to.setDensity(this.density.unload());    
		if(hasMolarMass())
			to.setMolarMass(this.molarMass.unload());
		
		if(hasAerosolization())
		  to.setAerosolization(this.aerosolization.unload());
		if(hasMassInBody())
      to.setMassInBody(this.massInBody.unload());
		if(hasMassInBlood())
      to.setMassInBlood(this.massInBlood.unload());
		if(hasMassInTissue())
      to.setMassInTissue(this.massInTissue.unload());
    if(hasPlasmaConcentration())
      to.setPlasmaConcentration(this.plasmaConcentration.unload());
    if(hasRemainingSystemicMassCleared())
      to.setRemainingSystemicMassCleared(this.remainingSystemicMassCleared.unload());
     
		if(hasAlveolarTransfer())
			to.setAlveolarTransfer(this.alveolarTransfer.unload());
		if(hasDiffusingCapacity())
      to.setDiffusingCapacity(this.diffusingCapacity.unload());
    if(hasEndTidalConcentration())
			to.setEndTidalConcentration(this.endTidalConcentration.unload());
		if(hasRelativeDiffusionCoefficient())
      to.setRelativeDiffusionCoefficient(this.relativeDiffusionCoefficient.unload());
    if(hasSolubilityCoefficient())
			to.setSolubilityCoefficient(this.solubilityCoefficient.unload());
		
    if(hasClearance())
      to.setClearance(this.clearance.unload());
    if(hasPK())
      to.setPharmacokinetics(this.pk.unload());
    if(hasPD())
      to.setPharmacodynamics(this.pd.unload());    
	
		if(hasCompartmentEffect())
		{
			for(SESubstanceCompartmentEffect fx : this.getCompartmentEffects())
				to.getCompartmentEffect().add(fx.unload());
		}
	}
	
	public String  getName() { return this.name;}
	public void    setName(String name){this.name=name;}
	public boolean hasName(){return StringUtils.exists(this.name);}
	
	public EnumSubstanceState  getState() { return this.state;}
	public void                setState(EnumSubstanceState state){this.state=state;}
	public boolean             hasState(){return this.state==null?false:true;}
	
	public SEScalarMassPerVolume getDensity() 
  { 
    if(this.density==null)
      this.density=new SEScalarMassPerVolume();
    return this.density;
  }
  public boolean hasDensity() {return this.density==null?false:this.density.isValid();}
  
	public SEScalarMassPerAmount getMolarMass() 
	{ 
		if(this.molarMass==null)
			this.molarMass=new SEScalarMassPerAmount();
		return this.molarMass;
	}
	public boolean hasMolarMass() {return this.molarMass==null?false:this.molarMass.isValid();}
	
	////////////////
	// Liquid-ish //
	////////////////
	
	public SESubstanceAerosolization getAerosolization()
	{
	  if(this.aerosolization==null)
	    this.aerosolization = new SESubstanceAerosolization();
	  return this.aerosolization;
	}
	public boolean hasAerosolization() { return this.aerosolization!=null; }
	public void removeAerosolization() { this.aerosolization = null; }
	
	public SEScalarMass getMassInBody() 
  { 
    if(this.massInBody==null)
      this.massInBody=new SEScalarMass();
    return this.massInBody;
  }
  public boolean hasMassInBody() {return this.massInBody==null?false:this.massInBody.isValid();}
  
  public SEScalarMass getMassInBlood() 
  { 
    if(this.massInBlood==null)
      this.massInBlood=new SEScalarMass();
    return this.massInBlood;
  }
  public boolean hasMassInBlood() {return this.massInBlood==null?false:this.massInBlood.isValid();}
  
  public SEScalarMass getMassInTissue() 
  { 
    if(this.massInTissue==null)
      this.massInTissue=new SEScalarMass();
    return this.massInTissue;
  }
  public boolean hasMassInTissue() {return this.massInTissue==null?false:this.massInTissue.isValid();}
  
  public SEScalarMassPerVolume getPlasmaConcentration() 
  { 
    if(this.plasmaConcentration==null)
      this.plasmaConcentration=new SEScalarMassPerVolume();
    return this.plasmaConcentration;
  }
  public boolean hasPlasmaConcentration() {return this.plasmaConcentration==null?false:this.plasmaConcentration.isValid();}
  
  public SEScalarMass getRemainingSystemicMassCleared() 
  { 
    if(this.remainingSystemicMassCleared==null)
      this.remainingSystemicMassCleared=new SEScalarMass();
    return this.remainingSystemicMassCleared;
  }
  public boolean hasRemainingSystemicMassCleared() {return this.remainingSystemicMassCleared==null?false:this.remainingSystemicMassCleared.isValid();}

  /////////////
	// Gas-ish //
  /////////////
  
	public SEScalarVolumePerTime getAlveolarTransfer() 
	{ 
		if(this.alveolarTransfer==null)
			this.alveolarTransfer=new SEScalarVolumePerTime();
		return this.alveolarTransfer;
	}
	public boolean hasAlveolarTransfer() {return this.alveolarTransfer==null?false:this.alveolarTransfer.isValid();}
	
	public SEScalarVolumePerTimePerPressure getDiffusingCapacity() 
  { 
    if(this.diffusingCapacity==null)
      this.diffusingCapacity=new SEScalarVolumePerTimePerPressure();
    return this.diffusingCapacity;
  }
  public boolean hasDiffusingCapacity() {return this.diffusingCapacity==null?false:this.diffusingCapacity.isValid();}
  
	public SEScalarFraction getEndTidalConcentration() 
	{ 
		if(this.endTidalConcentration==null)
			this.endTidalConcentration=new SEScalarFraction();
		return this.endTidalConcentration;
	}
	public boolean hasEndTidalConcentration() {return this.endTidalConcentration==null?false:this.endTidalConcentration.isValid();}
	
	public SEScalarInversePressure getSolubilityCoefficient() 
	{ 
		if(this.solubilityCoefficient==null)
			this.solubilityCoefficient=new SEScalarInversePressure();
		return this.solubilityCoefficient;
	}
	public boolean hasSolubilityCoefficient() {return this.solubilityCoefficient==null?false:this.solubilityCoefficient.isValid();}
	
	public SEScalar getRelativeDiffusionCoefficient() 
	{ 
		if(this.relativeDiffusionCoefficient==null)
			this.relativeDiffusionCoefficient=new SEScalar();
		return this.relativeDiffusionCoefficient;
	}
	public boolean hasRelativeDiffusionCoefficient() {return this.relativeDiffusionCoefficient==null?false:this.relativeDiffusionCoefficient.isValid();}
	
	///////////////
	// Clearance //
	///////////////

	public SESubstanceClearance getClearance()
	{
	  if(this.clearance==null)
	    this.clearance = new SESubstanceClearance();
	  return this.clearance;
	}
	public boolean hasClearance() { return this.clearance!=null; }
	public void removeClearance() { this.clearance = null; }

	///////////
	// PK/PD //
	///////////
	
	public SESubstancePharmacokinetics getPK()
  {
    if(this.pk==null)
      this.pk = new SESubstancePharmacokinetics();
    return this.pk;
  }
  public boolean hasPK() { return this.pk!=null; }
  public void removePK() { this.pk = null; }
  
  public SESubstancePharmacodynamics getPD()
  {
    if(this.pd==null)
      this.pd = new SESubstancePharmacodynamics();
    return this.pd;
  }
  public boolean hasPD() { return this.pd!=null; }
  public void removePD() { this.pd = null; }
	
	public SESubstanceAnatomyEffect createAnatomyEffect() 
	{ 
		SESubstanceAnatomyEffect fx=new SESubstanceAnatomyEffect();
		this.getCompartmentEffects().add(fx);
		return fx;
	}	
	public List<SESubstanceCompartmentEffect> getCompartmentEffects() 
	{ 
		if(this.compartmentEffects==null)
			this.compartmentEffects=new ArrayList<SESubstanceCompartmentEffect>();
		return this.compartmentEffects;
	}	
	public boolean hasCompartmentEffect() {return this.compartmentEffects==null?false:this.compartmentEffects.size()>0;}
	public boolean hasCompartmentEffect(EnumAnatomy cmpt)
	{
		if(this.compartmentEffects==null)
			return false;
		for(SESubstanceCompartmentEffect fx : this.compartmentEffects)
		{
			if(fx instanceof SESubstanceAnatomyEffect)
			{
				SESubstanceAnatomyEffect afx = (SESubstanceAnatomyEffect)fx;
				if(afx.getAnatomyCompartment().equals(cmpt))
				{
					return true;
				}
			}			
		}
		return false;
	}
	public SESubstanceAnatomyEffect getAnatomyEffect(EnumAnatomy cmpt)
	{
		for(SESubstanceCompartmentEffect fx : this.getCompartmentEffects())
		{
			if(fx instanceof SESubstanceAnatomyEffect)
			{
				SESubstanceAnatomyEffect afx = (SESubstanceAnatomyEffect)fx;
				if(afx.getAnatomyCompartment().equals(cmpt))
				{
					return afx;
				}
			}			
		}
		SESubstanceAnatomyEffect afx = new SESubstanceAnatomyEffect();
		afx.setAnatomyCompartment(cmpt);
		this.getCompartmentEffects().add(afx);
		return afx;
	}
}
