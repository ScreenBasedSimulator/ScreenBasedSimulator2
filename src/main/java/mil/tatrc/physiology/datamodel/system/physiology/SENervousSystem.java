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

package mil.tatrc.physiology.datamodel.system.physiology;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.NervousSystemData;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.datamodel.system.SESystem;

public class SENervousSystem extends SEPhysiologySystem implements SESystem
{
  protected SEScalar					baroreceptorHeartRateScale;
  protected SEScalar					baroreceptorHeartElastanceScale;
  protected SEScalar					baroreceptorResistanceScale;
  protected SEScalar					baroreceptorComplianceScale;
  
  public SENervousSystem()
  {
	baroreceptorHeartRateScale=null;
	baroreceptorHeartElastanceScale=null;
	baroreceptorResistanceScale=null;
	baroreceptorComplianceScale=null;
  }

  public void reset()
  {		
	if(baroreceptorHeartRateScale!=null)
		baroreceptorHeartRateScale.invalidate();
	if(baroreceptorHeartElastanceScale!=null)
		baroreceptorHeartElastanceScale.invalidate();
	if(baroreceptorResistanceScale!=null)
		baroreceptorResistanceScale.invalidate();
	if(baroreceptorComplianceScale!=null)
		baroreceptorComplianceScale.invalidate();
  }

  public boolean load(NervousSystemData in)
  {		
	if (in.getBaroreceptorHeartRateScale() != null)
      getBaroreceptorHeartRateScale().load(in.getBaroreceptorHeartRateScale());
	if (in.getBaroreceptorHeartElastanceScale() != null)
      getBaroreceptorHeartElastanceScale().load(in.getBaroreceptorHeartElastanceScale());
	if (in.getBaroreceptorResistanceScale() != null)
      getBaroreceptorResistanceScale().load(in.getBaroreceptorResistanceScale());
	if (in.getBaroreceptorComplianceScale() != null)
      getBaroreceptorComplianceScale().load(in.getBaroreceptorComplianceScale());
  
    return true;
  }

  public NervousSystemData unload()
  {
    NervousSystemData data = CDMSerializer.objFactory.createNervousSystemData();
    unload(data);
    return data;
  }

  protected void unload(NervousSystemData data)
  {		
	if (getBaroreceptorHeartRateScale() != null)
      data.setBaroreceptorHeartRateScale(baroreceptorHeartRateScale.unload());
	if (getBaroreceptorHeartElastanceScale() != null)
      data.setBaroreceptorHeartElastanceScale(baroreceptorHeartElastanceScale.unload());
	if (getBaroreceptorResistanceScale() != null)
      data.setBaroreceptorResistanceScale(baroreceptorResistanceScale.unload());
	if (getBaroreceptorComplianceScale() != null)
      data.setBaroreceptorComplianceScale(baroreceptorComplianceScale.unload());
  
  }
  
  public boolean hasBaroreceptorHeartRateScale()
  {
    return baroreceptorHeartRateScale == null ? false : baroreceptorHeartRateScale.isValid();
  }
  public SEScalar getBaroreceptorHeartRateScale()
  {
    if (baroreceptorHeartRateScale == null)
      baroreceptorHeartRateScale = new SEScalar();
    return baroreceptorHeartRateScale;
  }
  
  public boolean hasBaroreceptorHeartElastanceScale()
  {
    return baroreceptorHeartElastanceScale == null ? false : baroreceptorHeartElastanceScale.isValid();
  }
  public SEScalar getBaroreceptorHeartElastanceScale()
  {
    if (baroreceptorHeartElastanceScale == null)
      baroreceptorHeartElastanceScale = new SEScalar();
    return baroreceptorHeartElastanceScale;
  }
  
  public boolean hasBaroreceptorResistanceScale()
  {
    return baroreceptorResistanceScale == null ? false : baroreceptorResistanceScale.isValid();
  }
  public SEScalar getBaroreceptorResistanceScale()
  {
    if (baroreceptorResistanceScale == null)
      baroreceptorResistanceScale = new SEScalar();
    return baroreceptorResistanceScale;
  }
  
  public boolean hasBaroreceptorComplianceScale()
  {
    return baroreceptorComplianceScale == null ? false : baroreceptorComplianceScale.isValid();
  }
  public SEScalar getBaroreceptorComplianceScale()
  {
    if (baroreceptorComplianceScale == null)
      baroreceptorComplianceScale = new SEScalar();
    return baroreceptorComplianceScale;
  }
}
