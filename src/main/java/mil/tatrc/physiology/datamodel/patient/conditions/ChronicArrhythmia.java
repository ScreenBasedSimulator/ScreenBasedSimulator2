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

import mil.tatrc.physiology.datamodel.bind.ChronicArrhythmiaData;
import mil.tatrc.physiology.datamodel.properties.SEScalarFrequency;

public abstract class ChronicArrhythmia extends SEPatientCondition
{
	protected SEScalarFrequency heartRateBaseline;
	
	public ChronicArrhythmia()
	{
		heartRateBaseline = null;
	}
	
	public void reset()
	{
		super.reset();
		if (heartRateBaseline != null)
			heartRateBaseline.invalidate();
	}
	
	public void copy(ChronicArrhythmia other)
	{
		if(this==other)
			return;
		super.copy(other);
		if (other.heartRateBaseline != null)
			getHeartRateBaseline().set(other.getHeartRateBaseline());
		else if (heartRateBaseline != null)
			heartRateBaseline.invalidate();
	}
	
	public boolean load(ChronicArrhythmiaData in) 
	{
		super.load(in);
		getHeartRateBaseline().load(in.getHeartRateBaseline());
		return true;
	}
	
	protected void unload(ChronicArrhythmiaData data)
	{
		super.unload(data);
		if (heartRateBaseline != null)
			data.setHeartRateBaseline(heartRateBaseline.unload());
	}
	
	public boolean hasHeartRateBaseline()
	{
		return heartRateBaseline == null ? false : heartRateBaseline.isValid();
	}
	public SEScalarFrequency getHeartRateBaseline()
	{
		if (heartRateBaseline == null)
			heartRateBaseline = new SEScalarFrequency();
		return heartRateBaseline;
	}
}
