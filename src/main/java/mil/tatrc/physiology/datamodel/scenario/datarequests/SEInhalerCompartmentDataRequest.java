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
import mil.tatrc.physiology.datamodel.bind.EnumInhaler;
import mil.tatrc.physiology.datamodel.bind.InhalerCompartmentDataRequestData;
import mil.tatrc.physiology.datamodel.substance.SESubstance;
import mil.tatrc.physiology.datamodel.substance.SESubstanceManager;

public class SEInhalerCompartmentDataRequest extends SEDataRequest
{
	protected EnumInhaler compartment;
	protected SESubstance substance;
	
	public SEInhalerCompartmentDataRequest()
	{
		
	}
	
	public void reset()
	{
		super.reset();
		
		compartment = null;
		substance = null;
	}
	
	public boolean load(InhalerCompartmentDataRequestData in, SESubstanceManager substances)
	{
		super.load(in);
		
		setCompartment(in.getCompartment());
		if (in.getSubstance() != null)
            setSubstance(substances.getSubstance(in.getSubstance()));
		
		return true;
	}
	
	public InhalerCompartmentDataRequestData unload()
	{
		InhalerCompartmentDataRequestData data = CDMSerializer.objFactory.createInhalerCompartmentDataRequestData();
		unload(data);
		return data;
	}
	
	protected void unload(InhalerCompartmentDataRequestData data)
	{
		super.unload(data);
		
		if (hasCompartment())
			data.setCompartment(compartment);
		if (hasSubstance())
            data.setSubstance(substance.getName());
	}
	
	public EnumInhaler getCompartment()
	{
		return compartment;
	}
	public void setCompartment(EnumInhaler compartment)
	{
		this.compartment = compartment;
	}
	public boolean hasCompartment()
	{
		return compartment == null ? false : true;
	}
	
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
