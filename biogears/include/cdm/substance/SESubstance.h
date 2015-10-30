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
CDM_BIND_DECL(SubstanceData)
#include "bind/enumAnatomy.hxx"
#include "bind/enumSubstanceState.hxx"

#include "substance/SESubstanceAerosolization.h"
#include "substance/SESubstanceClearance.h"
#include "substance/SESubstancePharmacokinetics.h"
#include "substance/SESubstancePharmacodynamics.h"
#include "substance/SESubstanceCompartmentEffect.h"

class DLL_DECL SESubstance : public Loggable
{
public:

	SESubstance(Logger* logger);
	virtual ~SESubstance();

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

	bool Load(const CDM::SubstanceData& in);
	std::unique_ptr<CDM::SubstanceData> Unload() const;
protected:
	void Unload(CDM::SubstanceData& data) const;
public:
	
	virtual std::string GetName() const;
	virtual void SetName(const std::string& name);
	virtual bool HasName() const;
	virtual void InvalidateName();

	virtual CDM::enumSubstanceState::value GetState() const;
	virtual void SetState(CDM::enumSubstanceState::value state);
	virtual bool HasState() const;
	virtual void InvalidateState();

	virtual bool HasDensity() const;
	virtual SEScalarMassPerVolume& GetDensity();
	virtual double GetDensity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMolarMass() const;
	virtual SEScalarMassPerAmount& GetMolarMass();
	virtual double GetMolarMass(const std::shared_ptr<CCompoundUnit>& unit) const;

	// Liquid-ish
	virtual bool HasAerosolization() const;
	virtual SESubstanceAerosolization& GetAerosolization();
	virtual const SESubstanceAerosolization* GetAerosolization() const;
	virtual void RemoveAerosolization();

	virtual bool HasMassInBody() const;
	virtual SEScalarMass& GetMassInBody();
	virtual double GetMassInBody(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMassInBlood() const;
	virtual SEScalarMass& GetMassInBlood();
	virtual double GetMassInBlood(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMassInTissue() const;
	virtual SEScalarMass& GetMassInTissue();
	virtual double GetMassInTissue(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPlasmaConcentration() const;
	virtual SEScalarMassPerVolume& GetPlasmaConcentration();
	virtual double GetPlasmaConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRemainingSystemicMassCleared() const;
	virtual SEScalarMass& GetRemainingSystemicMassCleared();
	virtual double GetRemainingSystemicMassCleared(const std::shared_ptr<CCompoundUnit>& unit) const;

	// Gas-ish
	virtual bool HasAlveolarTransfer() const;
	virtual SEScalarVolumePerTime& GetAlveolarTransfer();
	virtual double GetAlveolarTransfer(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasDiffusingCapacity() const;
	virtual SEScalarVolumePerTimePerPressure& GetDiffusingCapacity();
	virtual double GetDiffusingCapacity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasEndTidalConcentration() const;
	virtual SEScalarFraction& GetEndTidalConcentration();
	virtual double GetEndTidalConcentration() const;

	virtual bool HasRelativeDiffusionCoefficient() const;
	virtual SEScalar& GetRelativeDiffusionCoefficient();
	virtual double GetRelativeDiffusionCoefficient() const;

	virtual bool HasSolubilityCoefficient() const;
	virtual SEScalarInversePressure& GetSolubilityCoefficient();
	virtual double GetSolubilityCoefficient(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasClearance() const;
	virtual SESubstanceClearance& GetClearance();
	virtual const SESubstanceClearance* GetClearance() const;
	virtual void RemoveClearance();

	virtual bool HasPK() const;
	virtual SESubstancePharmacokinetics& GetPK();
	virtual const SESubstancePharmacokinetics* GetPK() const;
	virtual void RemovePK();

	virtual bool HasPD() const;
	virtual SESubstancePharmacodynamics& GetPD();
	virtual const SESubstancePharmacodynamics* GetPD() const;
	virtual void RemovePD();

	virtual bool HasAnatomyEffect() const;
	virtual bool HasAnatomyEffect(CDM::enumAnatomy::value cmpt) const;
	virtual const std::vector<SESubstanceAnatomyEffect*>& GetAnatomyEffects();
	virtual const std::vector<const SESubstanceAnatomyEffect*>& GetAnatomyEffects() const;
	virtual SESubstanceAnatomyEffect& GetAnatomyEffect(CDM::enumAnatomy::value cmpt);
	virtual const SESubstanceAnatomyEffect* GetAnatomyEffect(CDM::enumAnatomy::value cmpt) const ;
	virtual void RemoveAnatomyEffect(CDM::enumAnatomy::value cmpt);
	
protected: 

	std::string                       m_Name;
	CDM::enumSubstanceState::value    m_State;
	SEScalarMassPerVolume*            m_Density;
	SEScalarMassPerAmount*            m_MolarMass;

	SESubstanceAerosolization*        m_Aerosolization;
	SEScalarMass*				      m_MassInBody;
	SEScalarMass*				      m_MassInBlood;
	SEScalarMass*				      m_MassInTissue;
	SEScalarMassPerVolume*   	      m_PlasmaConcentration;
	SEScalarMass*				      m_RemainingSystemicMassCleared;

	SEScalarVolumePerTime*            m_AlveolarTransfer;
	SEScalarVolumePerTimePerPressure* m_DiffusingCapacity;
	SEScalarFraction*			      m_EndTidalConcentration;
	SEScalar*					      m_RelativeDiffusionCoefficient;
	SEScalarInversePressure*          m_SolubilityCoefficient;

	SESubstanceClearance*             m_Clearance;
	SESubstancePharmacokinetics*      m_PK;
	SESubstancePharmacodynamics*      m_PD;

	std::vector<SESubstanceAnatomyEffect*> m_AnatomyEffects;
	std::vector<const SESubstanceAnatomyEffect*> m_cAnatomyEffects;
};