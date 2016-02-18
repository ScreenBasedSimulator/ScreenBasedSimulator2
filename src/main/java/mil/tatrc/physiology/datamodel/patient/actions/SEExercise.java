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
import mil.tatrc.physiology.datamodel.bind.ExerciseData;
import mil.tatrc.physiology.datamodel.properties.SEScalar;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;

public class SEExercise extends SEPatientAction
{
	protected SEScalarFraction intensity;
	protected SEScalar         borgScale;
	
	public SEExercise()
	{
		intensity=null;
		borgScale=null;
	}
	
	public void copy(SEExercise other)
	{
		if(this==other)
			return;
		super.copy(other);
		if (other.intensity != null)
			getIntensity().set(other.getIntensity());
		else if (intensity != null)
		  intensity.invalidate();
		if (other.borgScale != null)
      getBorgScale().set(other.getBorgScale());
    else if (borgScale != null)
      borgScale.invalidate();
	}
	
	public void reset()
	{
		super.reset();
		if (intensity != null)
		  intensity.invalidate();
		if (borgScale != null)
		  borgScale.invalidate();
	}
	
	public boolean load(ExerciseData in)
	{
		super.load(in);
		getIntensity().load(in.getIntensity());
		getBorgScale().load(in.getBorgScale());
		return true;
	}
	
	public ExerciseData unload() 
	{
		ExerciseData data = CDMSerializer.objFactory.createExerciseData();
		unload(data);
		return data;
	}
	
	protected void unload(ExerciseData data)
	{
		super.unload(data);
		if (intensity != null)
			data.setIntensity(intensity.unload());
		if (borgScale != null)
      data.setBorgScale(borgScale.unload());
	}
	
	public boolean hasIntensity()
	{
		return intensity == null ? false : intensity.isValid();
	}
	public SEScalarFraction getIntensity()
	{
		if (intensity == null)
		  intensity = new SEScalarFraction();
		return intensity;
	}
	
	public boolean hasBorgScale()
  {
    return borgScale == null ? false : borgScale.isValid();
  }
  public SEScalar getBorgScale()
  {
    if (borgScale == null)
      borgScale = new SEScalar();
    return borgScale;
  }
	
	public String toString() 
	{
		if (hasIntensity())
			return "Exercise" 
					+ "\n\tIntensity: " + getIntensity(); 
		else if (hasBorgScale())
      return "Exercise" 
          + "\n\tBorg Scale: " + getBorgScale(); 
		else
			return "Action not properly specified";
	}
}
