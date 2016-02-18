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
import mil.tatrc.physiology.datamodel.bind.EndotrachealIntubationData;
import mil.tatrc.physiology.datamodel.properties.SEScalarLength;

public class SEEndotrachealIntubation extends SEIntubation
{
	protected SEScalarLength depth;
	
	public SEEndotrachealIntubation()
	{
		depth = null;
	}
	
	public SEEndotrachealIntubation(SEEndotrachealIntubation other)
	{
		this();
		copy(other);
	}
	
	public void copy(SEEndotrachealIntubation other)
	{
		if (other.depth != null)
			getDepth().set(other.depth);
		else if (depth != null)
			depth.invalidate();
	}
	
	public void reset()
	{
		super.reset();
		if (depth != null)
			depth.invalidate();
	}
	
	public boolean load(EndotrachealIntubationData in)
	{
		super.load(in);
		getDepth().load(in.getDepth());
		return true;
	}
	
	public EndotrachealIntubationData unload()
	{
		EndotrachealIntubationData data = CDMSerializer.objFactory.createEndotrachealIntubationData();
		unload(data);
		return data;
	}
	
	protected void unload(EndotrachealIntubationData data)
	{
		super.unload(data);
		if (depth != null)
			data.setDepth(depth.unload());
	}
	
	public boolean hasDepth()
	{
		return depth == null ? false : depth.isValid();
	}
	public SEScalarLength getDepth()
	{
		if (depth == null)
			depth = new SEScalarLength();
		return depth;
	}
	
	public String toString()
	{
		if (depth != null)
			return "Endotracheal Tube Movement" 
					+ "\n\tDepth: " + getDepth();
		else
			return "Action not specified properly";
	}
}