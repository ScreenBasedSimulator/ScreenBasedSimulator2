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

package mil.tatrc.physiology.datamodel.scenario.datarequests;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.AnatomyCompartmentDataRequestData;
import mil.tatrc.physiology.datamodel.bind.EnumAnatomy;
import mil.tatrc.physiology.datamodel.bind.EnumCompartmentType;
import mil.tatrc.physiology.datamodel.substance.SESubstance;
import mil.tatrc.physiology.datamodel.substance.SESubstanceManager;

public class SEAnatomyCompartmentDataRequest extends SEDataRequest
{
	protected EnumAnatomy         compartment;
	protected EnumCompartmentType type;
	protected SESubstance         substance;
	
	public SEAnatomyCompartmentDataRequest()
	{
		
	}
	
	public void reset()
	{
		super.reset();
		
		compartment = null;
		type = null;
		substance = null;
	}
	
	public boolean load(AnatomyCompartmentDataRequestData in, SESubstanceManager substances)
	{
		super.load(in);
		
		setCompartment(in.getCompartment());
		setType(in.getType());
		
		if (in.getSubstance() != null)
			setSubstance(substances.getSubstance(in.getSubstance()));
		return true;
	}
	
	public AnatomyCompartmentDataRequestData unload()
	{
		AnatomyCompartmentDataRequestData data = CDMSerializer.objFactory.createAnatomyCompartmentDataRequestData();
		unload(data);
		return data;
	}
	
	protected void unload(AnatomyCompartmentDataRequestData data)
	{
		super.unload(data);
		
		if (hasCompartment())
			data.setCompartment(compartment);
		if (hasType())
		    data.setType(type);
		if (hasSubstance())
			data.setSubstance(substance.getName());
	}
	
	/*
	 * Compartment
	 */
	public EnumAnatomy getCompartment()
	{
		return compartment;
	}
	public void setCompartment(EnumAnatomy compartment)
	{
		this.compartment = compartment;
	}
	public boolean hasCompartment()
	{
		return compartment == null ? false : true;
	}
	
	/*
     *  type
     */
    public EnumCompartmentType getType()
    {
        return type;
    }
    public void setType(EnumCompartmentType fluidType)
    {
        this.type = fluidType;
    }
    public boolean hasType()
    {
        return type == null ? false : true;
    }
	
	/*
	 * Substance
	 */
	public SESubstance getSubstance()
	{
		return substance;
	}
	public void setSubstance(SESubstance substance)
	{
		this.substance = substance;
	}
	public boolean hasSubstance()
	{
		return substance == null ? false : true;
	}
	public void invalidateSubstance()
	{
		substance = null;
	}
}
