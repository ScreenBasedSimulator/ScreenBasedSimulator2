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

import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.MassUnit;

public abstract class SESubstanceCompartmentEffect
{
	protected SEScalarMass             massCleared;//
	protected SEScalarMass             massExcreted;//
	protected SEScalar                 partitionCoefficient;//s
	protected SEScalar                 permeabilitySurfaceAreaProduct;
	protected SEScalar                 clearanceModifier;//
	
	
	public SESubstanceCompartmentEffect()
	{

	}
	
	public void reset()
	{		
		if(this.massCleared!=null)
			this.massCleared.invalidate();
		if(this.massExcreted!=null)
			this.massExcreted.invalidate();
		if(this.partitionCoefficient!=null)
			this.partitionCoefficient.invalidate();	
		if(this.permeabilitySurfaceAreaProduct!=null)
			this.permeabilitySurfaceAreaProduct.invalidate();	
		if(this.clearanceModifier!=null)
			this.clearanceModifier.invalidate();
	}
	
	public boolean load(SubstanceCompartmentEffectData data)
	{
		if(data.getMassCleared()!=null)
			this.getMassCleared().load(data.getMassCleared());
		if(data.getMassExcreted()!=null)
			this.getMassExcreted().load(data.getMassExcreted());
		if(data.getPartitionCoefficient()!=null)
			this.getPartitionCoefficient().load(data.getPartitionCoefficient());
		if(data.getPermeabilitySurfaceAreaProduct()!=null)
			this.getPermeabilitySurfaceAreaProduct().load(data.getPermeabilitySurfaceAreaProduct());
		if(data.getClearanceModifier()!=null)
			this.getClearanceModifier().load(data.getClearanceModifier());	
		
		return true;
	}
	
	public abstract SubstanceAnatomyEffectData unload();
	
	protected void unload(SubstanceCompartmentEffectData to)
	{
		if(hasMassCleared())
			to.setMassCleared(this.massCleared.unload());
		if(hasMassExcreted())
			to.setMassExcreted(this.massExcreted.unload());
		if(hasPartitionCoefficient())
			to.setPartitionCoefficient(this.partitionCoefficient.unload());
		if(hasPermeabilitySurfaceAreaProduct())
			to.setPermeabilitySurfaceAreaProduct(this.permeabilitySurfaceAreaProduct.unload());
		if(hasClearanceModifier())
			to.setClearanceModifier(this.clearanceModifier.unload());
	}

	public SEScalarMass getMassCleared() 
	{ 
		if(this.massCleared==null)
			this.massCleared=new SEScalarMass();
		return this.massCleared;
	}
	public boolean      hasMassCleared() {return this.massCleared==null?false:this.massCleared.isValid();}
	
	public SEScalarMass getMassExcreted() 
	{ 
		if(this.massExcreted==null)
			this.massExcreted=new SEScalarMass();
		return this.massExcreted;
	}
	public boolean      hasMassExcreted() {return this.massExcreted==null?false:this.massExcreted.isValid();}
	
	public SEScalar getPartitionCoefficient() 
	{ 
		if(this.partitionCoefficient==null)
			this.partitionCoefficient=new SEScalar();
		return this.partitionCoefficient;
	}
	public boolean      hasPartitionCoefficient() {return this.partitionCoefficient==null?false:this.partitionCoefficient.isValid();}
	
	public SEScalar getPermeabilitySurfaceAreaProduct() 
	{ 
		if(this.permeabilitySurfaceAreaProduct==null)
			this.permeabilitySurfaceAreaProduct=new SEScalar();
		return this.permeabilitySurfaceAreaProduct;
	}
	public boolean      hasPermeabilitySurfaceAreaProduct() {return this.permeabilitySurfaceAreaProduct==null?false:this.permeabilitySurfaceAreaProduct.isValid();}
	
	public SEScalar getClearanceModifier() 
	{ 
		if(this.clearanceModifier==null)
			this.clearanceModifier=new SEScalar();
		return this.clearanceModifier;
	}
	public boolean      hasClearanceModifier() {return this.clearanceModifier==null?false:this.clearanceModifier.isValid();}
}
