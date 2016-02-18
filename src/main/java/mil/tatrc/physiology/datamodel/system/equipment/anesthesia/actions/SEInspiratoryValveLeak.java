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

package mil.tatrc.physiology.datamodel.system.equipment.anesthesia.actions;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.EnumOnOff;
import mil.tatrc.physiology.datamodel.bind.InspiratoryValveLeakData;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;

public class SEInspiratoryValveLeak extends SEAnesthesiaMachineAction
{
	protected SEScalarFraction severity;
	
	public SEInspiratoryValveLeak()
	{
		severity = null;
	}
	
	public void reset()
	{
		super.reset();
		if (severity != null)
			severity.invalidate();
	}
	
	public boolean load(InspiratoryValveLeakData in)
	{
		super.load(in);
		getSeverity().load(in.getSeverity());
		return true;
	}
	
	public InspiratoryValveLeakData unload()
	{
		InspiratoryValveLeakData data = CDMSerializer.objFactory.createInspiratoryValveLeakData();
		unload(data);
		return data;
	}
	
	protected void unload(InspiratoryValveLeakData data)
	{
		super.unload(data);
		if (hasSeverity())
			data.setSeverity(severity.unload());
	}
	
	/*
	 * Severity
	 */
	public boolean hasSeverity()
	{
		return severity == null ? false : severity.isValid();
	}
	public SEScalarFraction getSeverity()
	{
		if (severity == null)
			severity = new SEScalarFraction();
		return severity;
	}
	
	public String toString()
	{
		if (severity != null)
			return "Inspiratory Valve Leak"
					+ "\n\tSeverity: " + getSeverity();
		else
			return "Action not specified properly";
	}
}
