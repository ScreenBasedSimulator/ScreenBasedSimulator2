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
CDM_BIND_DECL(EnvironmentalConditionsData)
#include "bind/enumSurroundingType.hxx"
class SESubstance;
class SESubstanceFraction;
class SESubstanceManager;
class SEEnvironmentChange;
class SEInitialEnvironment;

class DLL_DECL SEEnvironmentalConditions : public Loggable
{
protected:
	friend SEEnvironmentChange;
	friend SEInitialEnvironment;
public:

	SEEnvironmentalConditions(SESubstanceManager& substances);
	virtual ~SEEnvironmentalConditions();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual void Copy(const SEEnvironmentalConditions& from);
	virtual void Merge(const SEEnvironmentalConditions& from);

	bool Load(const CDM::EnvironmentalConditionsData& in);
	std::unique_ptr<CDM::EnvironmentalConditionsData> Unload() const;
protected:
	void Unload(CDM::EnvironmentalConditionsData& data) const;
public:

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual bool LoadFile(const std::string& environmentFile);

	virtual CDM::enumSurroundingType::value GetSurroundingType() const;
	virtual void SetSurroundingType(CDM::enumSurroundingType::value name);
	virtual bool HasSurroundingType() const;
	virtual void InvalidateSurroundingType();

	virtual bool HasAirDensity() const;
	virtual SEScalarMassPerVolume& GetAirDensity();
	virtual double GetAirDensity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasAirVelocity() const;
	virtual SEScalarLengthPerTime& GetAirVelocity();
	virtual double GetAirVelocity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasAmbientTemperature() const;
	virtual SEScalarTemperature& GetAmbientTemperature();
	virtual double GetAmbientTemperature(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasAtmosphericPressure() const;
	virtual SEScalarPressure& GetAtmosphericPressure();
	virtual double GetAtmosphericPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasClothingResistance() const;
	virtual SEScalarHeatResistanceArea& GetClothingResistance();
	virtual double GetClothingResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasEmissivity() const;
	virtual SEScalarFraction& GetEmissivity();
	virtual double GetEmissivity() const;

	virtual bool HasMeanRadiantTemperature() const;
	virtual SEScalarTemperature& GetMeanRadiantTemperature();
	virtual double GetMeanRadiantTemperature(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRelativeHumidity() const;
	virtual SEScalarFraction& GetRelativeHumidity();
	virtual double GetRelativeHumidity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRespirationAmbientTemperature() const;
	virtual SEScalarTemperature& GetRespirationAmbientTemperature();
	virtual double GetRespirationAmbientTemperature(const std::shared_ptr<CCompoundUnit>& unit) const;

	bool HasAmbientSubstance() const;
	bool HasAmbientSubstance(const SESubstance& substance) const;
	const std::vector<SESubstanceFraction*>& GetAmbientSubstances();
	const std::vector<const SESubstanceFraction*>& GetAmbientSubstances() const;
	SESubstanceFraction& GetAmbientSubstance(SESubstance& substance);
	const SESubstanceFraction* GetAmbientSubstance(const SESubstance& substance) const;
	void RemoveAmbientSubstance(const SESubstance& substance);
	void RemoveAmbientSubstances();

protected:

	CDM::enumSurroundingType::value   m_SurroundingType;
	
	SEScalarMassPerVolume*	          m_AirDensity;
	SEScalarLengthPerTime*	          m_AirVelocity;
	SEScalarTemperature*              m_AmbientTemperature;
	SEScalarPressure*	              m_AtmosphericPressure;
	SEScalarHeatResistanceArea*	      m_ClothingResistance;
	SEScalarFraction*	              m_Emissivity;
	SEScalarTemperature*	          m_MeanRadiantTemperature;
	SEScalarFraction*                 m_RelativeHumidity;
	SEScalarTemperature*	          m_RespirationAmbientTemperature;

	std::vector<SESubstanceFraction*>       m_AmbientSubstances;
	std::vector<const SESubstanceFraction*> m_cAmbientSubstances;

	SESubstanceManager&               m_Substances;
};                  
