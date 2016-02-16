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
import mil.tatrc.physiology.datamodel.bind.EnumOnOff;
import mil.tatrc.physiology.datamodel.bind.EnumPneumothoraxType;
import mil.tatrc.physiology.datamodel.bind.EnumSide;
import mil.tatrc.physiology.datamodel.bind.TensionPneumothoraxData;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;

public class SETensionPneumothorax extends SEPatientAction
{
	protected EnumPneumothoraxType type;
	protected EnumSide side;
	protected SEScalarFraction severity;
	protected EnumOnOff state;
	
	public SETensionPneumothorax()
	{
		type = null;
		side = null;
		severity = null;
		state = EnumOnOff.ON;
	}
	
	public void copy(SETensionPneumothorax other)
	{
		if(this==other)
			return;
		super.copy(other);
		type = other.type;
		side = other.side;
		state = other.state;
		if (other.severity != null)
			getSeverity().set(other.severity);
		else if (severity != null)
			severity.invalidate();
	}
	
	public void reset()
	{
		super.reset();
		type = null;
		side = null;
		state = EnumOnOff.ON;
		if (severity != null)
			severity.invalidate();
	}
	
	public boolean load(TensionPneumothoraxData in)
	{
		super.load(in);
		getSeverity().load(in.getSeverity());
		type = in.getType();
		side = in.getSide();
		return true;
	}
	
	public TensionPneumothoraxData unload()
	{
		TensionPneumothoraxData data = CDMSerializer.objFactory.createTensionPneumothoraxData();
		unload(data);
		return data;
	}
	
	protected void unload(TensionPneumothoraxData data)
	{
		super.unload(data);
		if (severity != null)
			data.setSeverity(severity.unload());
		if (hasType())
			data.setType(type);
		if (hasSide())
			data.setSide(side);
	}
	
	public EnumPneumothoraxType getType()
	{
		return type;
	}
	public void setType(EnumPneumothoraxType type)
	{
		this.type = type;
	}
	public boolean hasType()
	{
		return type == null ? false : true;
	}
	
	public EnumSide getSide()
	{
		return side;
	}
	public void setSide(EnumSide side)
	{
		this.side = side;
	}
	public boolean hasSide()
	{
		return side == null ? false : true;
	}
	
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
	
	public EnumOnOff getState()
	{
		return state;
	}
	public void setState(EnumOnOff onOrOff)
	{
		state = onOrOff;
	}
	public boolean hasState()
	{
		return state == null ? false : true;
	}
	
	public String toString() 
	{
		if (severity != null)
			return "Pneumothorax" 
					+ "\n\tSeverity: " + getSeverity()
					+ "\n\tType : " + getType() 
					+ "\n\tSide : " + getSide();
		else
			return "Action not specified properly";
	}

}
