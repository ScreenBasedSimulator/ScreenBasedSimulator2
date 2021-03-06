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
import mil.tatrc.physiology.datamodel.bind.ChronicBradycardiaData;

public class ChronicBradycardia extends ChronicArrhythmia
{
	public ChronicBradycardia()
	{
		
	}
	
	public void reset()
	{
		super.reset();
	}
	
	public void copy(ChronicBradycardia other)
	{
		if(this==other)
			return;
		super.copy(other);		
	}
	
	public boolean load(ChronicBradycardiaData in) 
	{
		super.load(in);
		return true;
	}
	
	public ChronicBradycardiaData unload() 
	{
		ChronicBradycardiaData to = CDMSerializer.objFactory.createChronicBradycardiaData();
		unload(to);
		return to;
	}
	
	protected void unload(ChronicBradycardiaData data)
	{
		super.unload(data);
	}
	
	public String toString()
	{
		return "Chronic Bradycardia" 
				+ "\n\tHeart Rate Baseline: " + getHeartRateBaseline();
	}

	
}
