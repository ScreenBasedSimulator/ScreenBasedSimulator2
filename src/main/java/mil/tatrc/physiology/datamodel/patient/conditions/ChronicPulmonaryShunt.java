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

package mil.tatrc.physiology.datamodel.patient.conditions;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.ChronicPulmonaryShuntData;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;

public class ChronicPulmonaryShunt extends SEPatientCondition
{
	protected SEScalarFraction shuntFraction;
	
	public ChronicPulmonaryShunt()
	{
		shuntFraction = null;
	}
	
	public void reset()
	{
		super.reset();
		if (shuntFraction != null)
			shuntFraction.invalidate();
	}
	
	public void copy(ChronicPulmonaryShunt other)
	{
		if(this==other)
			return;
		super.copy(other);
		if (other.shuntFraction != null)
			getShuntFraction().set(other.getShuntFraction());
		else if (shuntFraction != null)
			shuntFraction.invalidate();
	}
	
	public boolean load(ChronicPulmonaryShuntData in) 
	{
		super.load(in);
		getShuntFraction().load(in.getShuntFraction());
		return true;
	}
	
	public ChronicPulmonaryShuntData unload() 
	{
		ChronicPulmonaryShuntData to = CDMSerializer.objFactory.createChronicPulmonaryShuntData();
		unload(to);
		return to;
	}
	
	protected void unload(ChronicPulmonaryShuntData data)
	{
		super.unload(data);
		if (shuntFraction != null)
			data.setShuntFraction(shuntFraction.unload());
	}
	
	public boolean hasShuntFraction()
	{
		return shuntFraction == null ? false : shuntFraction.isValid();
	}
	public SEScalarFraction getShuntFraction()
	{
		if (shuntFraction == null)
			shuntFraction = new SEScalarFraction();
		return shuntFraction;
	}
	
	public String toString()
	{
		return "Chronic Pulmonary Shunt" 
				+ "\n\tShunt Fraction: " + getShuntFraction();
	}

	
}
