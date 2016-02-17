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
import mil.tatrc.physiology.datamodel.bind.EnergySystemData;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.datamodel.system.SESystem;

public class SEEnergySystem extends SEPhysiologySystem implements SESystem
{
  protected SEScalarVolumePerTime carbonDioxideProductionRate;
  protected SEScalarTemperature 	coreTemperature;
  protected SEScalarAmountPerTime creatinineProductionRate;
  protected SEScalar				      respiratoryQuotient;
  protected SEScalarAmountPerTime lactateProductionRate;
  protected SEScalarAmountPerTime ketoneProductionRate;
  protected SEScalarVolumePerTime oxygenConsumptionRate;
  protected SEScalarTemperature 	skinTemperature;
  protected SEScalarMassPerTime 	sweatRate;
  protected SEScalarPower 		    totalMetabolicRate;

  public SEEnergySystem()
  {
    carbonDioxideProductionRate = null;
    coreTemperature = null;
    creatinineProductionRate = null;
    respiratoryQuotient = null;
    lactateProductionRate = null;
    ketoneProductionRate = null;
    oxygenConsumptionRate = null;
    skinTemperature = null;
    sweatRate = null;
    totalMetabolicRate = null;
  }

  public void reset()
  {		
    if (carbonDioxideProductionRate != null)
      carbonDioxideProductionRate.invalidate();
    if (coreTemperature != null)
      coreTemperature.invalidate();
    if (creatinineProductionRate != null)
      creatinineProductionRate.invalidate();
    if (respiratoryQuotient != null)
      respiratoryQuotient.invalidate();
    if (lactateProductionRate != null)
      lactateProductionRate.invalidate();
    if (ketoneProductionRate != null)
      ketoneProductionRate.invalidate();
    if (oxygenConsumptionRate != null)
      oxygenConsumptionRate.invalidate();
    if (skinTemperature != null)
      skinTemperature.invalidate();
    if (sweatRate != null)
      sweatRate.invalidate();
    if (totalMetabolicRate != null)
      totalMetabolicRate.invalidate();
  }

  public boolean load(EnergySystemData in)
  {		
    if (in.getCarbonDioxideProductionRate() != null)
      getCarbonDioxideProductionRate().load(in.getCarbonDioxideProductionRate());
    if (in.getCoreTemperature() != null)
      getCoreTemperature().load(in.getCoreTemperature());
    if (in.getCreatinineProductionRate() != null)
      getCreatinineProductionRate().load(in.getCreatinineProductionRate());
    if (in.getRespiratoryQuotient() != null)
      getRespiratoryQuotient().load(in.getRespiratoryQuotient());
    if (in.getLactateProductionRate() != null)
      getLactateProductionRate().load(in.getLactateProductionRate());
    if (in.getKetoneProductionRate() != null)
      getKetoneProductionRate().load(in.getKetoneProductionRate());
    if (in.getOxygenConsumptionRate() != null)
      getOxygenConsumptionRate().load(in.getOxygenConsumptionRate());
    if (in.getSkinTemperature() != null)
      getSkinTemperature().load(in.getSkinTemperature());
    if (in.getSweatRate() != null)
      getSweatRate().load(in.getSweatRate());
    if (in.getTotalMetabolicRate() != null)
      getTotalMetabolicRate().load(in.getTotalMetabolicRate());

    return true;
  }

  public EnergySystemData unload()
  {
    EnergySystemData data = CDMSerializer.objFactory.createEnergySystemData();
    unload(data);
    return data;
  }

  protected void unload(EnergySystemData data)
  {		
    if (hasCarbonDioxideProductionRate())
      data.setCarbonDioxideProductionRate(carbonDioxideProductionRate.unload());
    if (hasCoreTemperature())
      data.setCoreTemperature(coreTemperature.unload());
    if (hasCreatinineProductionRate())
      data.setCreatinineProductionRate(creatinineProductionRate.unload());
    if (hasRespiratoryQuotient())
      data.setRespiratoryQuotient(respiratoryQuotient.unload());
    if (hasLactateProductionRate())
      data.setLactateProductionRate(lactateProductionRate.unload());
    if (hasKetoneProductionRate())
      data.setKetoneProductionRate(ketoneProductionRate.unload());
    if (hasOxygenConsumptionRate())
      data.setOxygenConsumptionRate(oxygenConsumptionRate.unload());
    if (hasSkinTemperature())
      data.setSkinTemperature(skinTemperature.unload());
    if (hasSweatRate())
      data.setSweatRate(sweatRate.unload());
    if (hasTotalMetabolicRate())
      data.setTotalMetabolicRate(totalMetabolicRate.unload());
  }

  public boolean hasCarbonDioxideProductionRate()
  {
    return carbonDioxideProductionRate == null ? false : carbonDioxideProductionRate.isValid();
  }
  public SEScalarVolumePerTime getCarbonDioxideProductionRate()
  {
    if (carbonDioxideProductionRate == null)
      carbonDioxideProductionRate = new SEScalarVolumePerTime();
    return carbonDioxideProductionRate;
  }

  public boolean hasCoreTemperature()
  {
    return coreTemperature == null ? false : coreTemperature.isValid();
  }
  public SEScalarTemperature getCoreTemperature()
  {
    if (coreTemperature == null)
      coreTemperature = new SEScalarTemperature();
    return coreTemperature;
  }

  public boolean hasCreatinineProductionRate()
  {
    return creatinineProductionRate == null ? false : creatinineProductionRate.isValid();
  }
  public SEScalarAmountPerTime getCreatinineProductionRate()
  {
    if (creatinineProductionRate == null)
      creatinineProductionRate = new SEScalarAmountPerTime();
    return creatinineProductionRate;
  }

  public boolean hasRespiratoryQuotient()
  {
    return respiratoryQuotient == null ? false : respiratoryQuotient.isValid();
  }
  public SEScalar getRespiratoryQuotient()
  {
    if (respiratoryQuotient == null)
      respiratoryQuotient = new SEScalar();
    return respiratoryQuotient;
  }

  public boolean hasLactateProductionRate()
  {
    return lactateProductionRate == null ? false : lactateProductionRate.isValid();
  }
  public SEScalarAmountPerTime getLactateProductionRate()
  {
    if (lactateProductionRate == null)
      lactateProductionRate = new SEScalarAmountPerTime();
    return lactateProductionRate;
  }

  public boolean hasKetoneProductionRate()
  {
    return ketoneProductionRate == null ? false : ketoneProductionRate.isValid();
  }
  public SEScalarAmountPerTime getKetoneProductionRate()
  {
    if (ketoneProductionRate == null)
      ketoneProductionRate = new SEScalarAmountPerTime();
    return ketoneProductionRate;
  }

  public boolean hasOxygenConsumptionRate()
  {
    return oxygenConsumptionRate == null ? false : oxygenConsumptionRate.isValid();
  }
  public SEScalarVolumePerTime getOxygenConsumptionRate()
  {
    if (oxygenConsumptionRate == null)
      oxygenConsumptionRate = new SEScalarVolumePerTime();
    return oxygenConsumptionRate;
  }

  public boolean hasSkinTemperature()
  {
    return skinTemperature == null ? false : skinTemperature.isValid();
  }
  public SEScalarTemperature getSkinTemperature()
  {
    if (skinTemperature == null)
      skinTemperature = new SEScalarTemperature();
    return skinTemperature;
  }

  public boolean hasSweatRate()
  {
    return sweatRate == null ? false : sweatRate.isValid();
  }
  public SEScalarMassPerTime getSweatRate()
  {
    if (sweatRate == null)
      sweatRate = new SEScalarMassPerTime();
    return sweatRate;
  }

  public boolean hasTotalMetabolicRate()
  {
    return totalMetabolicRate == null ? false : totalMetabolicRate.isValid();
  }
  public SEScalarPower getTotalMetabolicRate()
  {
    if (totalMetabolicRate == null)
      totalMetabolicRate = new SEScalarPower();
    return totalMetabolicRate;
  }
}
