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
CDM_BIND_DECL(DrugSystemData)
#include "bind/enumOnOff.hxx"
#include "bind/enumPupilState.hxx"

class DLL_DECL SEDrugSystem : public SESystem
{
public:

	SEDrugSystem(Logger* logger);
	virtual ~SEDrugSystem();

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
	
	bool Load(const CDM::DrugSystemData& in);
	std::unique_ptr<CDM::DrugSystemData> Unload() const;
protected:
	void Unload(CDM::DrugSystemData& data) const;
public:

	virtual bool HasBronchodilationLevel() const;
	virtual SEScalarFraction& GetBronchodilationLevel();
	virtual double GetBronchodilationLevel() const;

	virtual bool HasHeartRateChange() const;
	virtual SEScalarFrequency& GetHeartRateChange();
	virtual double GetHeartRateChange(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMeanBloodPressureChange() const;
	virtual SEScalarPressure& GetMeanBloodPressureChange();
	virtual double GetMeanBloodPressureChange(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasNeuromuscularBlockLevel() const;
	virtual SEScalarFraction& GetNeuromuscularBlockLevel();
	virtual double GetNeuromuscularBlockLevel() const;

	virtual bool HasPulsePressureChange() const;
	virtual SEScalarPressure& GetPulsePressureChange();
	virtual double GetPulsePressureChange(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual CDM::enumPupilState::value GetPupilState() const;
	virtual void SetPupilState(CDM::enumPupilState::value type);
	virtual bool HasPupilState() const;
	virtual void InvalidatePupilState();

	virtual bool HasRespirationRateChange() const;
	virtual SEScalarFrequency& GetRespirationRateChange();
	virtual double GetRespirationRateChange(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSedationLevel() const;
	virtual SEScalarFraction& GetSedationLevel();
	virtual double GetSedationLevel() const;

	virtual bool HasTidalVolumeChange() const;
	virtual SEScalarVolume& GetTidalVolumeChange();
	virtual double GetTidalVolumeChange(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	SEScalarFraction*          m_BronchodilationLevel;
	SEScalarFrequency*         m_HeartRateChange;
	SEScalarPressure*          m_MeanBloodPressureChange;
	SEScalarFraction*          m_NeuromuscularBlockLevel;
	SEScalarPressure*          m_PulsePressureChange;
	CDM::enumPupilState::value m_PupilState;
	SEScalarFrequency*         m_RespirationRateChange;
	SEScalarFraction*          m_SedationLevel;
	SEScalarVolume*            m_TidalVolumeChange;
};