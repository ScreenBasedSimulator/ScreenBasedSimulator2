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

package mil.tatrc.physiology.datamodel.system.environment.actions;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.EnvironmentChangeData;
import mil.tatrc.physiology.datamodel.substance.SESubstanceManager;
import mil.tatrc.physiology.datamodel.system.environment.SEEnvironmentalConditions;

public class SEEnvironmentChange extends SEEnvironmentAction
{
	protected SEEnvironmentalConditions conditions;
	protected String                    conditionsFile;
  
	public SEEnvironmentChange()
	{
		this.conditions=new SEEnvironmentalConditions();
	}
	
	public SEEnvironmentChange(SEEnvironmentChange other)
	{
		this();
		copy(other);		
	}
	
	public void copy(SEEnvironmentChange other)
	{
	  if(this==other)
      return;
    super.copy(other);
		this.conditions.copy(other.conditions);
		this.conditionsFile=other.conditionsFile;
	}
	
	public void reset()
	{
		super.reset();
		this.conditions.reset();
		this.conditionsFile="";
	}
	
	public boolean load(EnvironmentChangeData in, SESubstanceManager substances)
	{
		super.load(in);
		if(in.getConditions()!=null)
			this.conditions.load(in.getConditions(),substances);
		else if(in.getConditionsFile()!=null)
		  this.conditionsFile=in.getConditionsFile();
		return true;
	}
	
	public EnvironmentChangeData unload()
	{
		EnvironmentChangeData data = CDMSerializer.objFactory.createEnvironmentChangeData();
		unload(data);
		return data;
	}
	
	protected void unload(EnvironmentChangeData data)
	{
		super.unload(data);
		if(this.hasConditions())
		  data.setConditions(this.conditions.unload());
		else if(this.hasConditionsFile())
		  data.setConditionsFile(this.conditionsFile);
	}
	
	boolean hasConditions()
	{
	  return this.conditions!=null;
	}
	SEEnvironmentalConditions getConditions()
	{
		return this.conditions;
	}
	
	boolean hasConditionsFile()
	{
	  return this.conditionsFile!=null&&!this.conditionsFile.isEmpty();
	}
	String getConditionsFile()
	{
	  return this.conditionsFile;
	}
	void setConditionsFile(String s)
	{
	  this.conditionsFile = s;
	}
	
	public String toString()
	{
		if (conditions != null)
			return "Envrioment Change:" 
					+ "\n\tSurroundingType: " + (this.conditions.hasSurroundingType()?this.conditions.getSurroundingType():"None")
					+ "\n\tAirDensity: " + (this.conditions.hasAirDensity()?this.conditions.getAirDensity():"None")
					+ "\n\tAirVelocity: " + (this.conditions.hasAirVelocity()?this.conditions.getAirVelocity():"None")
					+ "\n\tAmbientTemperature: " + (this.conditions.hasAmbientTemperature()?this.conditions.getAmbientTemperature():"None")
					+ "\n\tAtmosphericPressure: " + (this.conditions.hasAtmosphericPressure()?this.conditions.getAtmosphericPressure():"None")
      		+ "\n\tClothingResistance: " + (this.conditions.hasClothingResistance()?this.conditions.getClothingResistance():"None")
      		+ "\n\tEmissivity: " + (this.conditions.hasEmissivity()?this.conditions.getEmissivity():"None")
      		+ "\n\tMeanRadiantTemperature: " + (this.conditions.hasMeanRadiantTemperature()?this.conditions.getMeanRadiantTemperature():"None")
      		+ "\n\tRelativeHumidity: " + (this.conditions.hasRelativeHumidity()?this.conditions.getRelativeHumidity():"None")
      		+ "\n\tRespirationAmbientTemperature: " + (this.conditions.hasRespirationAmbientTemperature()?this.conditions.getRespirationAmbientTemperature():"None");
		if(this.hasConditionsFile())
		  return "Envrioment Change:"
		      + "\n\tConditionsFile: "+this.conditionsFile;
		else
			return "Action not specified properly";
	}
}