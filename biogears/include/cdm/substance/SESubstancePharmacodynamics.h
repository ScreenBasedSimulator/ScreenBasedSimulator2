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
CDM_BIND_DECL(SubstancePharmacodynamicsData)
#include "bind/enumPupilState.hxx"

class DLL_DECL SESubstancePharmacodynamics : Loggable
{
public:

	SESubstancePharmacodynamics(Logger* logger);
	virtual ~SESubstancePharmacodynamics();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	bool Load(const CDM::SubstancePharmacodynamicsData& in);
	std::unique_ptr<CDM::SubstancePharmacodynamicsData> Unload() const;
protected:
	void Unload(CDM::SubstancePharmacodynamicsData& data) const;
public:
	
	virtual bool HasBronchodilation() const;
	virtual SEScalarFraction& GetBronchodilation();
	virtual double GetBronchodilation() const;

	virtual bool HasDiastolicPressureModifier() const;
	virtual SEScalarFraction& GetDiastolicPressureModifier();
	virtual double GetDiastolicPressureModifier() const;

	virtual bool HasEC50() const;
	virtual SEScalarMassPerVolume& GetEC50();
	virtual double GetEC50() const;

	virtual bool HasHeartRateModifier() const;
	virtual SEScalarFraction& GetHeartRateModifier();
	virtual double GetHeartRateModifier() const;

	virtual bool HasNeuromuscularBlock() const;
	virtual SEScalarFraction& GetNeuromuscularBlock();
	virtual double GetNeuromuscularBlock() const;

	virtual CDM::enumPupilState::value GetPupilState() const;
	virtual void SetPupilState(CDM::enumPupilState::value type);
	virtual bool HasPupilState() const;
	virtual void InvalidatePupilState();

	virtual bool HasRespirationRateModifier() const;
	virtual SEScalarFraction& GetRespirationRateModifier();
	virtual double GetRespirationRateModifier() const;

	virtual bool HasSedation() const;
	virtual SEScalarFraction& GetSedation();
	virtual double GetSedation() const;

	virtual bool HasSystolicPressureModifier() const;
	virtual SEScalarFraction& GetSystolicPressureModifier();
	virtual double GetSystolicPressureModifier() const;

	virtual bool HasTidalVolumeModifier() const;
	virtual SEScalarFraction& GetTidalVolumeModifier();
	virtual double GetTidalVolumeModifier() const;

protected:
	virtual void CalculateDerived();

	SEScalarFraction*          m_Bronchodilation;
	SEScalarFraction*          m_DiastolicPressureModifier;
	SEScalarMassPerVolume*     m_EC50;
	SEScalarFraction*          m_HeartRateModifier;
	SEScalarFraction*          m_NeuromuscularBlock;
	CDM::enumPupilState::value m_PupilState;
	SEScalarFraction*          m_RespirationRateModifier;
	SEScalarFraction*          m_Sedation;
	SEScalarFraction*          m_SystolicPressureModifier;
	SEScalarFraction*          m_TidalVolumeModifier;
};