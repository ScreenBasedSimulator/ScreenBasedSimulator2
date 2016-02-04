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
CDM_BIND_DECL(RespiratorySystemData)

class DLL_DECL SERespiratorySystem : public SESystem
{
public:

	SERespiratorySystem(Logger* logger);
	virtual ~SERespiratorySystem();

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
	
	bool Load(const CDM::RespiratorySystemData& in);
	std::unique_ptr<CDM::RespiratorySystemData> Unload() const;
protected:
	void Unload(CDM::RespiratorySystemData& data) const;
public:

	virtual bool HasEndTidalCarbonDioxideFraction() const;
	virtual SEScalarFraction& GetEndTidalCarbonDioxideFraction();
	virtual double GetEndTidalCarbonDioxideFraction() const;

	virtual bool HasInspiratoryExpiratoryRatio() const;
	virtual SEScalar& GetInspiratoryExpiratoryRatio();
	virtual double GetInspiratoryExpiratoryRatio() const;

	virtual bool HasPulmonaryCompliance() const;
	virtual SEScalarFlowCompliance& GetPulmonaryCompliance();
	virtual double GetPulmonaryCompliance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryResistance() const;
	virtual SEScalarFlowResistance& GetPulmonaryResistance();
	virtual double GetPulmonaryResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRespirationDriverPressure() const;
	virtual SEScalarPressure& GetRespirationDriverPressure();
	virtual double GetRespirationDriverPressure() const;
	
	virtual bool HasRespirationRate() const;
	virtual SEScalarFrequency& GetRespirationRate();
	virtual double GetRespirationRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSpecificVentilation() const;
	virtual SEScalar& GetSpecificVentilation();
	virtual double GetSpecificVentilation() const;

	virtual bool HasTidalVolume() const;
	virtual SEScalarVolume& GetTidalVolume();
	virtual double GetTidalVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTotalAlveolarVentilation() const;
	virtual SEScalarVolumePerTime& GetTotalAlveolarVentilation();
	virtual double GetTotalAlveolarVentilation(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTotalDeadSpaceVentilation() const;
	virtual SEScalarVolumePerTime& GetTotalDeadSpaceVentilation();
	virtual double GetTotalDeadSpaceVentilation(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTotalPulmonaryVentilation() const;
	virtual SEScalarVolumePerTime& GetTotalPulmonaryVentilation();
	virtual double GetTotalPulmonaryVentilation(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTotalLungVolume() const;
	virtual SEScalarVolume& GetTotalLungVolume();
	virtual double GetTotalLungVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTranspulmonaryPressure() const;
	virtual SEScalarPressure& GetTranspulmonaryPressure();
	virtual double GetTranspulmonaryPressure(const std::shared_ptr<CCompoundUnit>& unit) const;


protected:

	SEScalarFraction*			m_EndTidalCarbonDioxideFraction;
	SEScalar*					m_InspiratoryExpiratoryRatio;
	SEScalarFlowCompliance*		m_PulmonaryCompliance;
	SEScalarFlowResistance*		m_PulmonaryResistance;
	SEScalarPressure*           m_RespirationDriverPressure;
	SEScalarFrequency*			m_RespirationRate;
	SEScalar*					m_SpecificVentilation;
	SEScalarVolume*				m_TidalVolume;
	SEScalarVolumePerTime*		m_TotalAlveolarVentilation;
	SEScalarVolumePerTime*		m_TotalDeadSpaceVentilation;
	SEScalarVolume*				m_TotalLungVolume;
	SEScalarVolumePerTime*		m_TotalPulmonaryVentilation;
	SEScalarPressure*			m_TranspulmonaryPressure;
};