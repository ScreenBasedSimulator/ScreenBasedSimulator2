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

package mil.tatrc.physiology.datamodel.substance;

import java.util.ArrayList;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.utilities.StringUtils;

public class SESubstanceAerosolization
{

	protected SEScalarMassPerVolume        dropletDensity;
	protected SEScalarLength               dropletDiameter;
	
	public SESubstanceAerosolization()
	{
		
	}
	
	public void reset()
	{
		if(this.dropletDensity!=null)
      this.dropletDensity.invalidate();
    if(this.dropletDiameter!=null)
      this.dropletDiameter.invalidate();
	}
	
	public boolean isValid()
	{
	  if(!hasDropletDensity() || !hasDropletDiameter())
      return false;
	  return true;
	}
	
	public boolean load(SubstanceAerosolizationData data)
	{
		this.reset();
	
		if(data.getDropletDensity()!=null)
		  this.getDropletDensity().load(data.getDropletDensity());
		if(data.getDropletDiameter()!=null)
		  this.getDropletDiameter().load(data.getDropletDiameter());
		
		return true;
	}
	
	public SubstanceAerosolizationData unload()
	{
	  if(!isValid())
	    return null;
		SubstanceAerosolizationData to = CDMSerializer.objFactory.createSubstanceAerosolizationData();
		unload(to);
		return to;
	}
	
	protected void unload(SubstanceAerosolizationData to)
	{
	  if(hasDropletDensity())
	    to.setDropletDensity(this.dropletDensity.unload());
	  if(hasDropletDiameter())
	    to.setDropletDiameter(this.dropletDiameter.unload());
	}
	
	public SEScalarMassPerVolume getDropletDensity() 
  { 
    if(this.dropletDensity==null)
      this.dropletDensity=new SEScalarMassPerVolume();
    return this.dropletDensity;
  }
  public boolean hasDropletDensity() {return this.dropletDensity==null?false:this.dropletDensity.isValid();}
  
  
  public SEScalarLength getDropletDiameter() 
  { 
    if(this.dropletDiameter==null)
      this.dropletDiameter=new SEScalarLength();
    return this.dropletDiameter;
  }
  public boolean hasDropletDiameter() {return this.dropletDiameter==null?false:this.dropletDiameter.isValid();}
}
