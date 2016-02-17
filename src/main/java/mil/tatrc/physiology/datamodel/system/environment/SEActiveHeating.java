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
import mil.tatrc.physiology.datamodel.bind.ActiveHeatingData;
import mil.tatrc.physiology.datamodel.properties.SEScalarArea;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarPower;

public class SEActiveHeating
{
	protected SEScalarPower       heatingPower;
	protected SEScalarArea        heatedSurfaceArea;
  protected SEScalarFraction    heatedSurfaceAreaFraction;
	
	public SEActiveHeating() 
	{
	  heatingPower=null;
	  heatedSurfaceArea=null;
	  heatedSurfaceAreaFraction=null;
	}
	
	public void copy(SEActiveHeating other)
	{
		if(this==other)
			return;
		if (other.heatingPower != null)
			getHeatingPower().set(other.getHeatingPower());
		else if (heatingPower != null)
		  heatingPower.invalidate();
		if (other.heatedSurfaceArea != null)
      getHeatedSurfaceArea().set(other.getHeatedSurfaceArea());
    else if (heatedSurfaceArea != null)
      heatedSurfaceArea.invalidate();
		if (other.heatedSurfaceAreaFraction != null)
      getHeatedSurfaceAreaFraction().set(other.getHeatedSurfaceAreaFraction());
    else if (heatedSurfaceAreaFraction != null)
      heatedSurfaceAreaFraction.invalidate();
	}
	
	public void reset()
	{
		if (heatingPower != null)
		  heatingPower.invalidate();
		if (heatedSurfaceArea != null)
		  heatedSurfaceArea.invalidate();
		if (heatedSurfaceAreaFraction != null)
		  heatedSurfaceAreaFraction.invalidate();		
	}

	
	public boolean load(ActiveHeatingData in)
	{		
	  getHeatingPower().load(in.getHeatingPower());
	  if(in.getHeatedSurfaceArea()!=null)
	    getHeatedSurfaceArea().load(in.getHeatedSurfaceArea());
	  if(in.getHeatedSurfaceAreaFraction()!=null)
	    getHeatedSurfaceAreaFraction().load(in.getHeatedSurfaceAreaFraction());		
		return true;
	}
	
	public ActiveHeatingData unload()
	{
	  ActiveHeatingData data = CDMSerializer.objFactory.createActiveHeatingData();
		unload(data);
		return data;
	}
	
	protected void unload(ActiveHeatingData data)
	{
	  data.setHeatingPower(this.heatingPower.unload());
	  if(hasHeatedSurfaceArea())
	    data.setHeatedSurfaceArea(this.heatedSurfaceArea.unload());
	  if(hasHeatedSurfaceAreaFraction())
	    data.setHeatedSurfaceAreaFraction(this.heatedSurfaceAreaFraction.unload());
	}
	
	public boolean hasHeatingPower()
	{
		return heatingPower == null ? false : heatingPower.isValid();
	}
	public SEScalarPower getHeatingPower()
	{
		if (heatingPower == null)
		  heatingPower = new SEScalarPower();
		return heatingPower;
	}
	
	public boolean hasHeatedSurfaceArea()
  {
    return heatedSurfaceArea == null ? false : heatedSurfaceArea.isValid();
  }
  public SEScalarArea getHeatedSurfaceArea()
  {
    if (heatedSurfaceArea == null)
      heatedSurfaceArea = new SEScalarArea();
    return heatedSurfaceArea;
  }
  
  public boolean hasHeatedSurfaceAreaFraction()
  {
    return heatedSurfaceAreaFraction == null ? false : heatedSurfaceAreaFraction.isValid();
  }
  public SEScalarFraction getHeatedSurfaceAreaFraction()
  {
    if (heatedSurfaceAreaFraction == null)
      heatedSurfaceAreaFraction = new SEScalarFraction();
    return heatedSurfaceAreaFraction;
  }
  
	public String toString() 
	{
      return "Thermal Application:" 
          + "\n\tActiveHeating: " + (this.hasHeatingPower()?this.getHeatingPower():"None")
          + "\n\tHeatedSurfaceArea: " + (this.hasHeatedSurfaceArea()?this.getHeatedSurfaceArea():"None")
          + "\n\tHeatedSurfaceAreaFraction: " + (this.hasHeatedSurfaceAreaFraction()?this.getHeatedSurfaceAreaFraction():"None")
         ;
	}
}
