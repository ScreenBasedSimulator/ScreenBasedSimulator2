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

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.properties.*;

public class SESubstanceCompoundComponent
{
	protected SEScalarMassPerVolume  concentration;
	protected SESubstance            substance;
	
	public SESubstanceCompoundComponent(SESubstance s)
	{
		if(s==null)
			throw new RuntimeException("Must provide a valid substance");
		this.substance=s;
	}
	
	public void reset()
	{
		if(this.concentration!=null)
			this.concentration.invalidate();
	}
	
	public boolean load(SubstanceCompoundComponentData data)
	{
		this.reset();
		if(data.getConcentration()!=null)
			this.getConcentration().load(data.getConcentration());
		return true;
	}
	
	public SubstanceCompoundComponentData unload()
	{
		SubstanceCompoundComponentData to = CDMSerializer.objFactory.createSubstanceCompoundComponentData();
		unload(to);
		return to;
	}
	
	protected void unload(SubstanceCompoundComponentData to)
	{
		if(hasConcentration())
			to.setConcentration(this.concentration.unload());		
		to.setSubstanceName(this.substance.getName());
	}
	
	public SEScalarMassPerVolume getConcentration() 
	{ 
		if(this.concentration==null)
			this.concentration=new SEScalarMassPerVolume();
		return this.concentration;
	}
	public boolean hasConcentration() {return this.concentration==null?false:this.concentration.isValid();}
	
	public SESubstance getSubstance() 
	{ 
		return this.substance;
	}
}
