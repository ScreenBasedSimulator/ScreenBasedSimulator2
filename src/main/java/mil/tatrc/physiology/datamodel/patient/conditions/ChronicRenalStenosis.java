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
import mil.tatrc.physiology.datamodel.bind.ChronicRenalStenosisData;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;

public class ChronicRenalStenosis extends SEPatientCondition
{
	protected SEScalarFraction leftKidneyOcclusionFraction;
	protected SEScalarFraction rightKidneyOcclusionFraction;
	
	public ChronicRenalStenosis()
	{
		leftKidneyOcclusionFraction = null;
		rightKidneyOcclusionFraction = null;
	}
	
	public void reset()
	{
		super.reset();
		if (leftKidneyOcclusionFraction != null)
			leftKidneyOcclusionFraction.invalidate();
		if (rightKidneyOcclusionFraction != null)
			rightKidneyOcclusionFraction.invalidate();
	}
	
	public void copy(ChronicRenalStenosis other)
	{
		if(this==other)
			return;
		super.copy(other);
		if (other.leftKidneyOcclusionFraction != null)
			getLeftKidneyOcclusionFraction().set(other.getLeftKidneyOcclusionFraction());
		else if (leftKidneyOcclusionFraction != null)
			leftKidneyOcclusionFraction.invalidate();
		
		if (other.rightKidneyOcclusionFraction != null)
			getRightKidneyOcclusionFraction().set(other.getRightKidneyOcclusionFraction());
		else if (rightKidneyOcclusionFraction != null)
			rightKidneyOcclusionFraction.invalidate();
	}
	
	public boolean load(ChronicRenalStenosisData in) 
	{
		super.load(in);
		getLeftKidneyOcclusionFraction().load(in.getLeftKidneyOcclusionFraction());
		getRightKidneyOcclusionFraction().load(in.getRightKidneyOcclusionFraction());
		return true;
	}
	
	public ChronicRenalStenosisData unload() 
	{
		ChronicRenalStenosisData to = CDMSerializer.objFactory.createChronicRenalStenosisData();
		unload(to);
		return to;
	}
	
	protected void unload(ChronicRenalStenosisData data)
	{
		super.unload(data);
		if (leftKidneyOcclusionFraction != null)
			data.setLeftKidneyOcclusionFraction(leftKidneyOcclusionFraction.unload());
		if (rightKidneyOcclusionFraction != null)
			data.setRightKidneyOcclusionFraction(rightKidneyOcclusionFraction.unload());
	}
	
	public boolean hasLeftKidneyOcclusionFraction()
	{
		return leftKidneyOcclusionFraction == null ? false : leftKidneyOcclusionFraction.isValid();
	}
	public SEScalarFraction getLeftKidneyOcclusionFraction()
	{
		if (leftKidneyOcclusionFraction == null)
			leftKidneyOcclusionFraction = new SEScalarFraction();
		return leftKidneyOcclusionFraction;
	}
	
	public boolean hasRightKidneyOcclusionFraction()
	{
		return rightKidneyOcclusionFraction == null ? false : rightKidneyOcclusionFraction.isValid();
	}
	public SEScalarFraction getRightKidneyOcclusionFraction()
	{
		if (rightKidneyOcclusionFraction == null)
			rightKidneyOcclusionFraction = new SEScalarFraction();
		return rightKidneyOcclusionFraction;
	}
	
	public String toString()
	{
		return "Chronic Renal Stenosis" 
				+ "\n\tLeftKidneyOcclusionFraction: " + getLeftKidneyOcclusionFraction()
				+ "\n\tRightKidneyOcclusionFraction: " + getRightKidneyOcclusionFraction();
	}

	
}
