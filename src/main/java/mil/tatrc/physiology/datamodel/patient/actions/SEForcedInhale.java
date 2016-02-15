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
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;

public class SEForcedInhale extends SEConsciousRespirationCommand
{
	protected SEScalarFraction inspiratoryCapacityFraction;
	protected SEScalarTime period;
	
	public SEForcedInhale()
	{
		inspiratoryCapacityFraction = null;
		period = null;
	}
	
	public void copy(SEForcedInhale other)
	{
		if(this==other)
			return;
		
		inspiratoryCapacityFraction = other.inspiratoryCapacityFraction;
		period = other.period;
	}
	
	public SEConsciousRespirationCommand getCopy()
	{
		SEConsciousRespirationCommand command = new SEForcedInhale();
		command.copy(this);
		
		return command;
	}
	
	public void reset()
	{
		super.reset();
		
		if (inspiratoryCapacityFraction != null)
			inspiratoryCapacityFraction.invalidate();
		if (period != null)
			period.invalidate();
	}
	
	public boolean load(ForcedInhaleData in)
	{
		super.load(in);
		
		getInspiratoryCapacityFraction().load(in.getInspiratoryCapacityFraction());
		getPeriod().load(in.getPeriod());
		
		return true;
	}
	
	public ForcedInhaleData unload()
	{
		ForcedInhaleData data = CDMSerializer.objFactory.createForcedInhaleData();
		unload(data);
		
		return data;
	}
	
	protected void unload(ForcedInhaleData data)
	{
		super.unload(data);
		
		if (hasInspiratoryCapacityFraction())
			data.setInspiratoryCapacityFraction(inspiratoryCapacityFraction.unload());
		if (hasPeriod())
			data.setPeriod(period.unload());
	}
	
	public boolean hasInspiratoryCapacityFraction()
	{
		return inspiratoryCapacityFraction != null;
	}
	public SEScalarFraction getInspiratoryCapacityFraction()
	{
		if (inspiratoryCapacityFraction == null)
			inspiratoryCapacityFraction = new SEScalarFraction();
		return inspiratoryCapacityFraction;
	}
	
	public boolean hasPeriod()
	{
		return period != null;
	}
	public SEScalarTime getPeriod()
	{
		if (period == null)
			period = new SEScalarTime();
		return period;
	}
	
	public String toString()
	{
		if (inspiratoryCapacityFraction != null &&
			period != null)
		{
			return "Forced Inhale" 
					+ "\n\tInspiratory Capacity Fraction: " + getInspiratoryCapacityFraction()
					+ "\n\tPeriod: " + getPeriod();
		}
		else
			return "Action not specified properly";
	}
}
