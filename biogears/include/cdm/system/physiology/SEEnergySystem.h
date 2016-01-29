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

#pragma once
#include "system/SESystem.h"
CDM_BIND_DECL(EnergySystemData)

class DLL_DECL SEEnergySystem : public SESystem
{
public:

	SEEnergySystem(Logger* logger);
	virtual ~SEEnergySystem();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);
	
	bool Load(const CDM::EnergySystemData& in);
	std::unique_ptr<CDM::EnergySystemData> Unload() const;
protected:
	void Unload(CDM::EnergySystemData& data) const;
public:
	
	virtual bool HasCarbonDioxideProductionRate() const;
	virtual SEScalarVolumePerTime& GetCarbonDioxideProductionRate();
	virtual double GetCarbonDioxideProductionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCoreTemperature() const;
	virtual SEScalarTemperature& GetCoreTemperature();
	virtual double GetCoreTemperature(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCreatinineProductionRate() const;
	virtual SEScalarAmountPerTime& GetCreatinineProductionRate();
	virtual double GetCreatinineProductionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasFatigueLevel() const;
	virtual SEScalarFraction& GetFatigueLevel();
	virtual double GetFatigueLevel(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRespiratoryQuotient() const;
	virtual SEScalar& GetRespiratoryQuotient();
	virtual double GetRespiratoryQuotient() const;

	virtual bool HasLactateProductionRate() const;
	virtual SEScalarAmountPerTime& GetLactateProductionRate();
	virtual double GetLactateProductionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasKetoneProductionRate() const;
	virtual SEScalarAmountPerTime& GetKetoneProductionRate();
	virtual double GetKetoneProductionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExerciseMeanArterialPressureDelta() const;
	virtual SEScalarPressure& GetExerciseMeanArterialPressureDelta();
	virtual double GetExerciseMeanArterialPressureDelta(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasOxygenConsumptionRate() const;
	virtual SEScalarVolumePerTime& GetOxygenConsumptionRate();
	virtual double GetOxygenConsumptionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSkinTemperature() const;
	virtual SEScalarTemperature& GetSkinTemperature();
	virtual double GetSkinTemperature(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSweatRate() const;
	virtual SEScalarMassPerTime& GetSweatRate();
	virtual double GetSweatRate(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasTotalMetabolicRate() const;
	virtual SEScalarPower& GetTotalMetabolicRate();
	virtual double GetTotalMetabolicRate(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	SEScalarVolumePerTime*  m_CarbonDioxideProductionRate;
	SEScalarTemperature*	m_CoreTemperature;
	SEScalarAmountPerTime*  m_CreatinineProductionRate;
	SEScalarFraction*		m_FatigueLevel;
	SEScalar*				m_RespiratoryQuotient;
	SEScalarAmountPerTime*	m_LactateProductionRate;
	SEScalarAmountPerTime*	m_KetoneProductionRate;
	SEScalarPressure*		m_ExerciseMeanArterialPressureDelta;
	SEScalarVolumePerTime*	m_OxygenConsumptionRate;
	SEScalarTemperature*	m_SkinTemperature;
	SEScalarMassPerTime*	m_SweatRate;
	SEScalarPower*			m_TotalMetabolicRate;
	
};
