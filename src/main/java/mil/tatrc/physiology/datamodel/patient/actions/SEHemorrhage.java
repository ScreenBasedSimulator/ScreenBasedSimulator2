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

package mil.tatrc.physiology.datamodel.patient.actions;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.EnumAnatomy;
import mil.tatrc.physiology.datamodel.bind.HemorrhageData;
import mil.tatrc.physiology.datamodel.properties.SEScalarVolumePerTime;

public class SEHemorrhage extends SEPatientAction
{
	protected EnumAnatomy compartment;
	protected SEScalarVolumePerTime rate;
	
	public SEHemorrhage()
	{
		compartment = null;
		rate = null;
	}
	
	public void copy(SEHemorrhage other)
	{
		if(this==other)
			return;
		super.copy(other);
		compartment = other.compartment;
		if (other.rate != null)
			getRate().set(other.getRate());
		else if (rate != null)
			rate.invalidate();
	}
	
	public void reset()
	{
		super.reset();
		compartment = null;
		if (rate != null)
			rate.invalidate();
	}
	
	public boolean load(HemorrhageData in)
	{
		super.load(in);
		getRate().load(in.getRate());
		compartment = in.getCompartment();
		return true;
	}
	
	public HemorrhageData unload()
	{
		HemorrhageData data = CDMSerializer.objFactory.createHemorrhageData();
		unload(data);
		return data;
	}
	
	protected void unload(HemorrhageData data)
	{
		super.unload(data);
		if (rate != null)
			data.setRate(rate.unload());
		if (hasCompartment())
			data.setCompartment(compartment);
	}
	
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
	
	public boolean hasRate()
	{
		return rate == null ? false : rate.isValid();
	}
	public SEScalarVolumePerTime getRate()
	{
		if (rate == null)
			rate = new SEScalarVolumePerTime();
		return rate;
	}
	
	public String toString()
	{
		if (rate != null)
			return "Hemorrhage" 
					+ "\n\tRate: " + getRate() 
					+ "\n\tCompartment: " + getCompartment();
		else
			return "Action not specified properly";
	}
}



