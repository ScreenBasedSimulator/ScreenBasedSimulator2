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


import java.util.ArrayList;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.GasCompartmentData;
import mil.tatrc.physiology.datamodel.substance.SESubstance;

public class SEGasCompartment<T> extends SEFluidCompartment<T>
{
	protected List<SEGasCompartmentSubstanceQuantity> substanceQuantities;
	
	public SEGasCompartment()
	{
		this.substanceQuantities=new ArrayList<SEGasCompartmentSubstanceQuantity>();
	}
	
	public void reset()
	{
	  super.reset();
		for (SEGasCompartmentSubstanceQuantity sq : this.substanceQuantities)
			sq.reset();
	}
	
	public boolean load(GasCompartmentData in)
	{
		super.load(in);
	
		//SESubstance* substance;
		//SECompartmentSubstanceQuantity* subQ;
		//for(int i = 0; i < in.getSubstanceQuantity().size(); i++)
		//{
		// TODO Look up the substance somehow, pass in.get managers in.get load?
		//std::cout<<in.get.SubstanceQuantity()[i].Name()<<std::endl;
		//substance = new SESubstance();//SubstanceManagerSubstance(in.get.SubstanceQuantity[i].name());
		//subQ = new SECompartmentSubstanceQuantity(*substance);
		//m_SubstanceQuantities.push_back(subQ);
		//}
		return true;
	}
	
	public GasCompartmentData unload()
	{
		GasCompartmentData to = CDMSerializer.objFactory.createGasCompartmentData();
		unload(to);
		return to;		
	}
	
	protected void unload(GasCompartmentData data)
	{
	  super.unload(data);
		
		// TODO SUb Q
	}
	
	public boolean hasSubstanceQuantity()
	{
		return substanceQuantities.size() > 0 ? true : false;
	}
	public boolean hasSubstanceQuantity(SESubstance substance)
	{
		for (SEGasCompartmentSubstanceQuantity csq : substanceQuantities)
		{
			if (csq.getSubstance() == substance)
				return true;
		}
		return false;
	}
	public SEGasCompartmentSubstanceQuantity getSubstanceQuantity(SESubstance substance)
	{
		for (SEGasCompartmentSubstanceQuantity csq : substanceQuantities)
		{
			if (substance == csq.getSubstance())
				return csq;
		}
		SEGasCompartmentSubstanceQuantity csq = new SEGasCompartmentSubstanceQuantity(substance);
		substanceQuantities.add(csq);
		return csq;
	}
	public List<SEGasCompartmentSubstanceQuantity> getSubstanceQuantities()
	{
		return substanceQuantities;
	}
	public void removeSubstanceQuantity(SESubstance substance)
	{
		for (SEGasCompartmentSubstanceQuantity csq : substanceQuantities)
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
		for (SEGasCompartmentSubstanceQuantity csq : substanceQuantities)
		{
			if (csq.getSubstance().getName().equals(substanceName))
			{
				substanceQuantities.remove(csq);
				return;
			}
		}
	}
}
