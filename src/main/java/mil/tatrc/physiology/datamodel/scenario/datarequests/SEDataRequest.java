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

package mil.tatrc.physiology.datamodel.scenario.datarequests;

import java.io.Serializable;

import mil.tatrc.physiology.datamodel.bind.DataRequestData;

public abstract class SEDataRequest implements Serializable
{
	protected String name;
	protected String unit;
	
	public SEDataRequest() 
	{
		name = "";
		unit = null;
	}
	
	public void reset()
	{
		name = "";
		unit = null;
	}
	
	public boolean load(DataRequestData in)
	{
		reset();
		name = in.getName();
		if (in.getUnit() != null)							
			unit = in.getUnit();	
		return true;
	}
	
	public abstract DataRequestData unload();
	
	protected void unload(DataRequestData data)
	{
		data.setName(name);
		if (hasUnit())
			data.setUnit(unit);
	}
	
	public String getName()
	{
		return name;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public boolean hasName()
	{
		return name==null||name.isEmpty() ? false : true;
	}
	
	public String getUnit()
	{
		return unit;
	}
	public void setUnit(String unit)
	{
		this.unit = unit;
	}
	public boolean hasUnit()
	{
		return unit==null||unit.isEmpty() ? false : true;
	}
	
}
