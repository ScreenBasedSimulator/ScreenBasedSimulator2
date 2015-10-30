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
#include "compartment/SELiquidCompartmentSubstanceQuantity.h"
#include "circuit/compartment/SECircuitCompartmentSubstanceQuantity.h"

template <typename CompartmentEnumValue> class SEFluidCircuitCompartment;
template <typename CompartmentEnumValue> class SETissueCircuitCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SELiquidCircuitCompartmentSubstanceQuantity : public virtual SELiquidCompartmentSubstanceQuantity, public SECircuitCompartmentSubstanceQuantity
{
	friend SETissueCircuitCompartmentSubstanceQuantity < CompartmentEnumValue > ;
public:

	SELiquidCircuitCompartmentSubstanceQuantity(const SESubstance& substance, SEFluidCircuitCompartment<CompartmentEnumValue>& pnt, const SaturationCalculator& satCalc);
	virtual ~SELiquidCircuitCompartmentSubstanceQuantity();

	virtual bool Load(const CDM::LiquidCompartmentSubstanceQuantityData& in);
	virtual std::unique_ptr<CDM::LiquidCompartmentSubstanceQuantityData> Unload() const;
protected:
	void Unload(CDM::LiquidCompartmentSubstanceQuantityData& data) const;
public:

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory
	virtual void FixUp() const; // reconnect up to circuit
	virtual void Balance(BalanceLiquidBy e);
	virtual void SaturateAtBalance(bool b){ m_Saturate = b; }//Sometimes you want to saturate (in blood), sometimes you don't (in tissue)

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual bool HasConcentration() const;
	virtual SEScalarMassPerVolume& GetConcentration();
	virtual double GetConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasMass() const;
	virtual SEScalarMass& GetMass();	
	virtual double GetMass(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMolarity() const;
	virtual const SEScalarAmountPerVolume& GetMolarity();
	virtual double GetMolarity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPartialPressure() const;
	virtual SEScalarPressure& GetPartialPressure();
	virtual double GetPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSaturation() const;
	virtual SEScalarFraction& GetSaturation();
	virtual double GetSaturation(const std::shared_ptr<CCompoundUnit>& unit) const;
	
protected:
	const SaturationCalculator& m_SaturationCalculator;
	SEFluidCircuitCompartment<CompartmentEnumValue>&     m_pnt;
	mutable std::vector<SECircuitNodeSubstanceQuantity*> m_nSubQs;

	bool m_IsO2;// Saturation is only calculated if substance is Oxygen
	bool m_IsCO2;// or CarbonDioxide
	bool m_Saturate;//Tissue Extravascular should not saturate

	mutable SEScalarMassPerVolume*   m_Concentration;
	mutable SEScalarAmountPerVolume* m_Molarity;
	mutable SEScalarMass*            m_Mass;
	mutable SEScalarPressure*        m_PartialPressure;
	mutable SEScalarFraction*        m_Saturation;
};
#include "circuit/compartment/SELiquidCircuitCompartmentSubstanceQuantity.inl"