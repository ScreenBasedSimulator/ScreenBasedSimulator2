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
import mil.tatrc.physiology.datamodel.bind.ActiveCoolingData;
import mil.tatrc.physiology.datamodel.properties.SEScalarArea;
import mil.tatrc.physiology.datamodel.properties.SEScalarFraction;
import mil.tatrc.physiology.datamodel.properties.SEScalarPower;

public class SEActiveCooling
{
	protected SEScalarPower       coolingPower;
	protected SEScalarArea        cooledSurfaceArea;
  protected SEScalarFraction    cooledSurfaceAreaFraction;
	
	public SEActiveCooling() 
	{	  
	  coolingPower=null;
	  cooledSurfaceArea=null;
	  cooledSurfaceAreaFraction=null;
	}
	
	public void copy(SEActiveCooling other)
	{
		if(this==other)
			return;
		if (other.coolingPower != null)
      getCoolingPower().set(other.getCoolingPower());
    else if (coolingPower != null)
      coolingPower.invalidate();
		if (other.cooledSurfaceArea != null)
      getCooledSurfaceArea().set(other.getCooledSurfaceArea());
    else if (cooledSurfaceArea != null)
      cooledSurfaceArea.invalidate();
		if (other.cooledSurfaceAreaFraction != null)
      getCooledSurfaceAreaFraction().set(other.getCooledSurfaceAreaFraction());
    else if (cooledSurfaceAreaFraction != null)
      cooledSurfaceAreaFraction.invalidate();    
	}
	
	public void reset()
	{
		if (coolingPower != null)
		  coolingPower.invalidate();
		if (cooledSurfaceArea != null)
		  cooledSurfaceArea.invalidate();
		if (cooledSurfaceAreaFraction != null)
		  cooledSurfaceAreaFraction.invalidate();		
	}

	
	public boolean load(ActiveCoolingData in)
	{
      getCoolingPower().load(in.getCoolingPower());
      if(in.getCooledSurfaceArea()!=null)
        getCooledSurfaceArea().load(in.getCooledSurfaceArea());
      if(in.getCooledSurfaceAreaFraction()!=null)
        getCooledSurfaceAreaFraction().load(in.getCooledSurfaceAreaFraction());
		
		return true;
	}
	
	public ActiveCoolingData unload()
	{
	  ActiveCoolingData data = CDMSerializer.objFactory.createActiveCoolingData();
		unload(data);
		return data;
	}
	
	protected void unload(ActiveCoolingData data)
	{		
	  data.setCoolingPower(this.coolingPower.unload());
	  if(hasCooledSurfaceArea())
	    data.setCooledSurfaceArea(this.cooledSurfaceArea.unload());
	  if(hasCooledSurfaceAreaFraction())
	    data.setCooledSurfaceAreaFraction(this.cooledSurfaceAreaFraction.unload());
	}
  
  public boolean hasCoolingPower()
  {
    return coolingPower == null ? false : coolingPower.isValid();
  }
  public SEScalarPower getCoolingPower()
  {
    if (coolingPower == null)
      coolingPower = new SEScalarPower();
    return coolingPower;
  }
  public boolean hasCooledSurfaceArea()
  {
    return cooledSurfaceArea == null ? false : cooledSurfaceArea.isValid();
  }
  public SEScalarArea getCooledSurfaceArea()
  {
    if (cooledSurfaceArea == null)
      cooledSurfaceArea = new SEScalarArea();
    return cooledSurfaceArea;
  }
  public boolean hasCooledSurfaceAreaFraction()
  {
    return cooledSurfaceAreaFraction == null ? false : cooledSurfaceAreaFraction.isValid();
  }
  public SEScalarFraction getCooledSurfaceAreaFraction()
  {
    if (cooledSurfaceAreaFraction == null)
      cooledSurfaceAreaFraction = new SEScalarFraction();
    return cooledSurfaceAreaFraction;
  }
 
	
	public String toString() 
	{
      return "Active Cooling:"          
          + "\n\tCoolingPower: " + (this.hasCoolingPower()?this.getCoolingPower():"None")
          + "\n\tCooledSurfaceArea: " + (this.hasCooledSurfaceArea()?this.getCooledSurfaceArea():"None")
          + "\n\tCooledSurfaceAreaFraction: " + (this.hasCooledSurfaceAreaFraction()?this.getCooledSurfaceAreaFraction():"None")
          ;
	}
}
