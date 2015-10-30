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
#include "compartment/SETissueCompartmentSubstanceQuantity.h"
#include "circuit/compartment/SECircuitCompartmentSubstanceQuantity.h"
#include "circuit/compartment/SELiquidCircuitCompartmentSubstanceQuantity.h"

template <typename CompartmentEnumValue> class SETissueCircuitCompartment;

template <typename CompartmentEnumValue>
class SETissueCircuitCompartmentSubstanceQuantity : public virtual SETissueCompartmentSubstanceQuantity, public SECircuitCompartmentSubstanceQuantity
{
	friend SETissueCircuitCompartment <CompartmentEnumValue>;
public:

	SETissueCircuitCompartmentSubstanceQuantity(const SESubstance& substance, SETissueCircuitCompartment<CompartmentEnumValue>& pnt, const SaturationCalculator& satCalc);
	virtual ~SETissueCircuitCompartmentSubstanceQuantity();

	virtual bool Load(const CDM::TissueCompartmentSubstanceQuantityData& in);
	virtual std::unique_ptr<CDM::TissueCompartmentSubstanceQuantityData> Unload() const;
protected:
	void Unload(CDM::TissueCompartmentSubstanceQuantityData& data) const;
public:

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory
	virtual void FixUp() const; // reconnect up to circuit
	virtual void Balance(BalanceTissueBy e);

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual bool HasMass() const;
	virtual SEScalarMass& GetMass();
	virtual double GetMass(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTissueConcentration() const;
	virtual SEScalarMassPerVolume& GetTissueConcentration();
	virtual double GetTissueConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTissueMolarity() const;
	virtual const SEScalarAmountPerVolume& GetTissueMolarity();
	virtual double GetTissueMolarity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularConcentration() const;
	virtual SEScalarMassPerVolume& GetExtravascularConcentration();
	virtual double GetExtravascularConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularMolarity() const;
	virtual const SEScalarAmountPerVolume& GetExtravascularMolarity();
	virtual double GetExtravascularMolarity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularPartialPressure() const;
	virtual SEScalarPressure& GetExtravascularPartialPressure();
	virtual double GetExtravascularPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularSaturation() const;
	virtual SEScalarFraction& GetExtravascularSaturation();
	virtual double GetExtravascularSaturation(const std::shared_ptr<CCompoundUnit>& unit) const;


protected:
	bool m_IsO2;// Saturation is only calculated if substance is Oxygen
	bool m_IsCO2;// or CarbonDioxide
	const SaturationCalculator& m_SaturationCalculator;
	SETissueCircuitCompartment<CompartmentEnumValue>&    m_pnt;
	mutable std::vector<SECircuitNodeSubstanceQuantity*> m_nSubQs;

	SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue> m_extravascular;

	mutable SEScalarMassPerVolume*   m_TissueConcentration;
	mutable SEScalarAmountPerVolume* m_TissueMolarity;
	
};
#include "circuit/compartment/SETissueCircuitCompartmentSubstanceQuantity.inl"