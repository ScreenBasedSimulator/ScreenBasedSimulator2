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
import mil.tatrc.physiology.datamodel.bind.PericardialEffusionConditionData;
import mil.tatrc.physiology.datamodel.properties.SEScalarVolume;

public class PericardialEffusionCondition extends SEPatientCondition
{
	protected SEScalarVolume accumulatedVolume;
	
	public PericardialEffusionCondition()
	{
		accumulatedVolume = null;
	}
	
	public void reset()
	{
		super.reset();
		if (accumulatedVolume != null)
			accumulatedVolume.invalidate();
	}
	
	public void copy(PericardialEffusionCondition other)
	{
		if(this==other)
			return;
		super.copy(other);
		if (other.accumulatedVolume != null)
			getAccumulatedVolume().set(other.getAccumulatedVolume());
		else if (accumulatedVolume != null)
			accumulatedVolume.invalidate();
	}
	
	public boolean load(PericardialEffusionConditionData in) 
	{
		super.load(in);
		getAccumulatedVolume().load(in.getAccumulatedVolume());
		return true;
	}
	
	public PericardialEffusionConditionData unload() 
	{
		PericardialEffusionConditionData to = CDMSerializer.objFactory.createPericardialEffusionConditionData();
		unload(to);
		return to;
	}
	
	protected void unload(PericardialEffusionConditionData data)
	{
		super.unload(data);
		if (accumulatedVolume != null)
			data.setAccumulatedVolume(accumulatedVolume.unload());
	}
	
	public boolean hasAccumulatedVolume()
	{
		return accumulatedVolume == null ? false : accumulatedVolume.isValid();
	}
	public SEScalarVolume getAccumulatedVolume()
	{
		if (accumulatedVolume == null)
			accumulatedVolume = new SEScalarVolume();
		return accumulatedVolume;
	}
	
	public String toString()
	{
		return "Pericardial Effusion" 
				+ "\n\tAccumulated Volume: " + getAccumulatedVolume();
	}

	
}
