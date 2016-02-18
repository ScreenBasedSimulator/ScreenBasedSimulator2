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
import mil.tatrc.physiology.datamodel.substance.SESubstanceCompartmentEffect;

public class SESubstanceAnatomyEffect extends SESubstanceCompartmentEffect
{
	protected EnumAnatomy              anatomyCompartment;
	
	
	public SESubstanceAnatomyEffect()
	{
		
	}
	
	public void reset()
	{
		super.reset();
		this.anatomyCompartment=null;
	}
	
	public boolean load(SubstanceAnatomyEffectData data)
	{
		super.load(data);
		if(data.getAnatomyCompartment()!=null)
			this.setAnatomyCompartment(data.getAnatomyCompartment());
		return true;
	}
	
	public SubstanceAnatomyEffectData unload()
	{
		SubstanceAnatomyEffectData to = CDMSerializer.objFactory.createSubstanceAnatomyEffectData();
		unload(to);
		return to;
	}
	
	protected void unload(SubstanceAnatomyEffectData to)
	{
		super.unload(to);
		if(hasAnatomyCompartment())
			to.setAnatomyCompartment(this.anatomyCompartment);		
	}
	
	public EnumAnatomy  getAnatomyCompartment() { return this.anatomyCompartment;}
	public void         setAnatomyCompartment(EnumAnatomy anatomyCompartment){this.anatomyCompartment=anatomyCompartment;}
	public boolean      hasAnatomyCompartment(){return this.anatomyCompartment==null?false:true;}
}
