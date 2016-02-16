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

package mil.tatrc.physiology.datamodel.system.environment;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.AppliedTemperatureData;
import mil.tatrc.physiology.datamodel.bind.EnumOnOff;
import mil.tatrc.physiology.datamodel.properties.SEScalarArea;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarTemperature;

public class SEAppliedTemperature
{
	protected SEScalarTemperature appliedTemperature;
	protected SEScalarArea        appliedSurfaceArea;
  protected SEScalarFraction    appliedSurfaceAreaFraction;
  protected EnumOnOff           applyTemperature;
	
	public SEAppliedTemperature() 
	{
	 appliedTemperature=null;
	  appliedSurfaceArea=null;
	  appliedSurfaceAreaFraction=null;
	  applyTemperature=EnumOnOff.ON;
	}
	
	public void copy(SEAppliedTemperature other)
	{
		if(this==other)
			return;
		if (other.appliedTemperature != null)
      getAppliedTemperature().set(other.getAppliedTemperature());
    else if (appliedTemperature != null)
      appliedTemperature.invalidate();
		if (other.appliedSurfaceArea != null)
      getAppliedSurfaceArea().set(other.getAppliedSurfaceArea());
    else if (appliedSurfaceArea != null)
      appliedSurfaceArea.invalidate();
		if (other.appliedSurfaceAreaFraction != null)
      getAppliedSurfaceAreaFraction().set(other.getAppliedSurfaceAreaFraction());
    else if (appliedSurfaceAreaFraction != null)
      appliedSurfaceAreaFraction.invalidate();
		applyTemperature=other.applyTemperature;
	}
	
	public void reset()
	{
		if (appliedTemperature != null)
		  appliedTemperature.invalidate();
		if (appliedSurfaceArea != null)
		  appliedSurfaceArea.invalidate();
		if (appliedSurfaceAreaFraction != null)
		  appliedSurfaceAreaFraction.invalidate();
    applyTemperature=EnumOnOff.ON;
	}

	
	public boolean load(AppliedTemperatureData in)
	{
		getAppliedTemperature().load(in.getAppliedTemperature());
      if(in.getAppliedSurfaceArea()!=null)
        getAppliedSurfaceArea().load(in.getAppliedSurfaceArea());
      if(in.getAppliedSurfaceAreaFraction()!=null)
        getAppliedSurfaceAreaFraction().load(in.getAppliedSurfaceAreaFraction());
      applyTemperature = in.getState();
    
		return true;
	}
	
	public AppliedTemperatureData unload()
	{
	  AppliedTemperatureData data = CDMSerializer.objFactory.createAppliedTemperatureData();
		unload(data);
		return data;
	}
	
	protected void unload(AppliedTemperatureData data)
	{
      data.setAppliedTemperature(this.appliedTemperature.unload());
      if(hasAppliedSurfaceArea())
        data.setAppliedSurfaceArea(this.appliedSurfaceArea.unload());
      if(hasAppliedSurfaceAreaFraction())
        data.setAppliedSurfaceAreaFraction(this.appliedSurfaceAreaFraction.unload());
      data.setState(this.applyTemperature);
	}
	
  
  public boolean hasAppliedTemperature()
  {
    return appliedTemperature == null ? false : appliedTemperature.isValid();
  }
  public SEScalarTemperature getAppliedTemperature()
  {
    if (appliedTemperature == null)
      appliedTemperature = new SEScalarTemperature();
    return appliedTemperature;
  }
  
  public boolean hasAppliedSurfaceArea()
  {
    return appliedSurfaceArea == null ? false : appliedSurfaceArea.isValid();
  }
  public SEScalarArea getAppliedSurfaceArea()
  {
    if (appliedSurfaceArea == null)
      appliedSurfaceArea = new SEScalarArea();
    return appliedSurfaceArea;
  }
  
  public boolean hasAppliedSurfaceAreaFraction()
  {
    return appliedSurfaceAreaFraction == null ? false : appliedSurfaceAreaFraction.isValid();
  }
  public SEScalarFraction getAppliedSurfaceAreaFraction()
  {
    if (appliedSurfaceAreaFraction == null)
      appliedSurfaceAreaFraction = new SEScalarFraction();
    return appliedSurfaceAreaFraction;
  }
  
  public void SetAppliedTemperatureState(EnumOnOff onOff)
  {
    this.applyTemperature=onOff;
  }
  public EnumOnOff GetAppliedTemperatureState()
  {
    return this.applyTemperature;
  }
	
	public String toString() 
	{
      return "Thermal Application:" 
          + "\n\tAppliedTemperature: " + (this.hasAppliedTemperature()?this.getAppliedTemperature():"None")
          + "\n\tAppliedSurfaceArea: " + (this.hasAppliedSurfaceArea()?this.getAppliedSurfaceArea():"None")
          + "\n\tAppliedSurfaceAreaFraction: " + (this.hasAppliedSurfaceAreaFraction()?this.getAppliedSurfaceAreaFraction():"None")
          + "\n\tAppliedTemperatureState: " + this.applyTemperature.name();
	}
}
