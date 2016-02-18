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
import mil.tatrc.physiology.datamodel.bind.RespiratorySystemData;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.datamodel.system.SESystem;

public class SERespiratorySystem extends SEPhysiologySystem implements SESystem
{
  
	protected SEScalarFraction     		endTidalCarbonDioxideFraction;
	protected SEScalar      			inspiratoryExpiratoryRatio;
	protected SEScalarFlowCompliance	pulmonaryCompliance;
	protected SEScalarFlowResistance  	pulmonaryResistance;
	protected SEScalarPressure        	respirationDriverPressure;
	protected SEScalarFrequency     	respirationRate;
	protected SEScalar					specificVentilation;
	protected SEScalarVolume        	tidalVolume;
	protected SEScalarVolumePerTime 	totalAlveolarVentilation;
	protected SEScalarVolumePerTime 	totalDeadSpaceVentilation;
	protected SEScalarVolume	   		totalLungVolume;
	protected SEScalarVolumePerTime 	totalPulmonaryVentilation;
	protected SEScalarPressure			transpulmonaryPressure;
	
	
	public SERespiratorySystem()
	{		
		endTidalCarbonDioxideFraction = null;
		inspiratoryExpiratoryRatio = null;
		pulmonaryCompliance = null;
		pulmonaryResistance = null;
		respirationDriverPressure = null;
		respirationRate = null;
		specificVentilation = null;
		tidalVolume = null;
		totalAlveolarVentilation = null;
		totalDeadSpaceVentilation = null;
		totalLungVolume = null;
		totalPulmonaryVentilation = null;
		transpulmonaryPressure = null;
	}
	
	public void reset()
	{
		if (endTidalCarbonDioxideFraction != null)
			endTidalCarbonDioxideFraction.invalidate();
		if (inspiratoryExpiratoryRatio != null)
			inspiratoryExpiratoryRatio.invalidate();
		if (pulmonaryCompliance != null)
			pulmonaryCompliance.invalidate();
		if (pulmonaryResistance != null)
			pulmonaryResistance.invalidate();
		if (respirationDriverPressure != null)
			respirationDriverPressure.invalidate();
		if (respirationRate != null)
			respirationRate.invalidate();
		if (specificVentilation != null)
			specificVentilation.invalidate();
		if (tidalVolume != null)
			tidalVolume.invalidate();
		if (totalAlveolarVentilation != null)
			totalAlveolarVentilation.invalidate();
		if (totalDeadSpaceVentilation != null)
			totalDeadSpaceVentilation.invalidate();
		if (totalLungVolume != null)
			totalLungVolume.invalidate();
		if (totalPulmonaryVentilation != null)
			totalPulmonaryVentilation.invalidate();
		if (transpulmonaryPressure != null)
			transpulmonaryPressure.invalidate();
	}
	
	public boolean load(RespiratorySystemData in)
	{
		if (in.getEndTidalCarbonDioxideFraction() != null)
			getEndTidalCarbonDioxideFraction().load(in.getEndTidalCarbonDioxideFraction());
		if (in.getInspiratoryExpiratoryRatio() != null)
			getInspiratoryExpiratoryRatio().load(in.getInspiratoryExpiratoryRatio()); 
		if (in.getPulmonaryCompliance() != null)
			getPulmonaryCompliance().load(in.getPulmonaryCompliance()); 
		if (in.getRespirationDriverPressure() != null)
			getRespirationDriverPressure().load(in.getRespirationDriverPressure());
		if (in.getRespirationRate() != null)
      getRespirationRate().load(in.getRespirationRate());
		if (in.getSpecificVentilation() != null)
			getSpecificVentilation().load(in.getSpecificVentilation());
		if (in.getTidalVolume() != null)
			getTidalVolume().load(in.getTidalVolume()); 
		if (in.getTotalAlveolarVentilation() != null)
			getTotalAlveolarVentilation().load(in.getTotalAlveolarVentilation());
		if (in.getTotalDeadSpaceVentilation() != null)
			getTotalDeadSpaceVentilation().load(in.getTotalDeadSpaceVentilation());
		if (in.getTotalLungVolume() != null)
			getTotalLungVolume().load(in.getTotalLungVolume());
		if (in.getTotalPulmonaryVentilation() != null)
			getTotalPulmonaryVentilation().load(in.getTotalPulmonaryVentilation()); 
		if (in.getTranspulmonaryPressure() != null)
			getTranspulmonaryPressure().load(in.getTranspulmonaryPressure());		

		return true;
	}
	
	public RespiratorySystemData unload()
	{
		RespiratorySystemData data = CDMSerializer.objFactory.createRespiratorySystemData();
		unload(data);
		return data;
	}
	
	protected void unload(RespiratorySystemData data)
	{
		if (endTidalCarbonDioxideFraction != null)
			data.setEndTidalCarbonDioxideFraction(endTidalCarbonDioxideFraction.unload());		
		if (inspiratoryExpiratoryRatio != null)
			data.setInspiratoryExpiratoryRatio(inspiratoryExpiratoryRatio.unload());		
		if (pulmonaryCompliance != null)
			data.setPulmonaryCompliance(pulmonaryCompliance.unload());
		if (pulmonaryResistance != null)
			data.setPulmonaryResistance(pulmonaryResistance.unload());	
		if (respirationDriverPressure != null)
      data.setRespirationDriverPressure(respirationDriverPressure.unload());
		if (respirationRate != null)
			data.setRespirationRate(respirationRate.unload());
		if (specificVentilation != null)
			data.setSpecificVentilation(specificVentilation.unload());		
		if (tidalVolume != null)
			data.setTidalVolume(tidalVolume.unload());
		if (totalAlveolarVentilation != null)
			data.setTotalAlveolarVentilation(totalAlveolarVentilation.unload());
		if (totalDeadSpaceVentilation != null)
			data.setTotalDeadSpaceVentilation(totalDeadSpaceVentilation.unload());
		if (totalLungVolume != null)
			data.setTotalLungVolume(totalLungVolume.unload());		
		if (totalPulmonaryVentilation != null)
			data.setTotalPulmonaryVentilation(totalPulmonaryVentilation.unload());
		if (transpulmonaryPressure != null)
			data.setTranspulmonaryPressure(transpulmonaryPressure.unload());
	}
	
	/*
	 * End Tidal Carbon Dioxide Fraction
	 */
	public boolean hasEndTidalCarbonDioxideFraction()
	{
		return endTidalCarbonDioxideFraction == null ? false : endTidalCarbonDioxideFraction.isValid();
	}
	public SEScalarFraction getEndTidalCarbonDioxideFraction()
	{
		if (endTidalCarbonDioxideFraction == null)
			endTidalCarbonDioxideFraction = new SEScalarFraction();
		return endTidalCarbonDioxideFraction;
	}
	
	
	/*
	 * Inspiratory Expiratory Ratio
	 */
	public boolean hasInspiratoryExpiratoryRatio()
	{
		return inspiratoryExpiratoryRatio == null ? false : inspiratoryExpiratoryRatio.isValid();
	}
	public SEScalar getInspiratoryExpiratoryRatio()
	{
		if (inspiratoryExpiratoryRatio == null)
			inspiratoryExpiratoryRatio = new SEScalar();
		return inspiratoryExpiratoryRatio;
	}
	
	
	/*
	 * Pulmonary Compliance
	 */
	public boolean hasPulmonaryCompliance()
	{
		return pulmonaryCompliance == null ? false : pulmonaryCompliance.isValid();
	}
	public SEScalarFlowCompliance getPulmonaryCompliance()
	{
		if (pulmonaryCompliance == null)
			pulmonaryCompliance = new SEScalarFlowCompliance();
		return pulmonaryCompliance;
	}
	
	/*
	 * Pulmonary Resistance
	 */
	public boolean hasPulmonaryResistance()
	{
		return pulmonaryResistance == null ? false : pulmonaryResistance.isValid();
	}
	public SEScalarFlowResistance getPulmonaryResistance()
	{
		if (pulmonaryResistance == null)
			pulmonaryResistance = new SEScalarFlowResistance();
		return pulmonaryResistance;
	}
	
	/*
	 * Respiration Rate
	 */
	public boolean hasRespirationDriverPressure()
	{
		return respirationDriverPressure == null ? false : respirationDriverPressure.isValid();
	}
	public SEScalarPressure getRespirationDriverPressure()
	{
		if (respirationDriverPressure == null)
		  respirationDriverPressure = new SEScalarPressure();
		return respirationDriverPressure;
	}
	
	public boolean hasRespirationRate()
  {
    return respirationRate == null ? false : respirationRate.isValid();
  }
  public SEScalarFrequency getRespirationRate()
  {
    if (respirationRate == null)
      respirationRate = new SEScalarFrequency();
    return respirationRate;
  }
	
	/*
	 * Specific Ventilation
	 */
	public boolean hasSpecificVentilation()
	{
		return specificVentilation == null ? false : specificVentilation.isValid();
	}
	public SEScalar getSpecificVentilation()
	{
		if (specificVentilation == null)
			specificVentilation = new SEScalar();
		return specificVentilation;
	}
	
	/*
	 * Tidal Volume
	 */
	public boolean hasTidalVolume()
	{
		return tidalVolume == null ? false : tidalVolume.isValid();
	}
	public SEScalarVolume getTidalVolume()
	{
		if (tidalVolume == null)
			tidalVolume = new SEScalarVolume();
		return tidalVolume;
	}
	
	/*
	 * Total Alveolar Ventilation
	 */
	public boolean hasTotalAlveolarVentilation()
	{
		return totalAlveolarVentilation == null ? false : totalAlveolarVentilation.isValid();
	}
	public SEScalarVolumePerTime getTotalAlveolarVentilation()
	{
		if (totalAlveolarVentilation == null)
			totalAlveolarVentilation = new SEScalarVolumePerTime();
		return totalAlveolarVentilation;
	}
	
	/*
	 * Total Dead Space Ventilation
	 */
	public boolean hasTotalDeadSpaceVentilation()
	{
		return totalDeadSpaceVentilation == null ? false : totalDeadSpaceVentilation.isValid();
	}
	public SEScalarVolumePerTime getTotalDeadSpaceVentilation()
	{
		if (totalDeadSpaceVentilation == null)
			totalDeadSpaceVentilation = new SEScalarVolumePerTime();
		return totalDeadSpaceVentilation;
	}
	
	/*
	 * Total Lung Volume
	 */
	public boolean hasTotalLungVolume()
	{
		return totalLungVolume == null ? false : totalLungVolume.isValid();
	}
	public SEScalarVolume getTotalLungVolume()
	{
		if (totalLungVolume == null)
			totalLungVolume = new SEScalarVolume();
		return totalLungVolume;
	}
	
	/*
	 * Total Pulmonary Ventilation
	 */
	public boolean hasTotalPulmonaryVentilation()
	{
		return totalPulmonaryVentilation == null ? false : totalPulmonaryVentilation.isValid();
	}
	public SEScalarVolumePerTime getTotalPulmonaryVentilation()
	{
		if (totalPulmonaryVentilation == null)
			totalPulmonaryVentilation = new SEScalarVolumePerTime();
		return totalPulmonaryVentilation;
	}
	
	/*
	 * Transpulmonary Pressure
	 */
	public boolean hasTranspulmonaryPressure()
	{
		return transpulmonaryPressure == null ? false : transpulmonaryPressure.isValid();
	}
	public SEScalarPressure getTranspulmonaryPressure()
	{
		if (transpulmonaryPressure == null)
			transpulmonaryPressure = new SEScalarPressure();
		return transpulmonaryPressure;
	}
}
