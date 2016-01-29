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
#include "compartment/SELiquidCompartment.h"
#include "circuit/compartment/SEFluidCircuitCompartment.h"
class SESubstance;
class KelmanEquation;
template <typename CompartmentEnumValue> class SELiquidCircuitCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SELiquidCircuitCompartment : public virtual SELiquidCompartment<CompartmentEnumValue>, public SEFluidCircuitCompartment<CompartmentEnumValue>
{
	friend SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>;
public:

	SELiquidCircuitCompartment(CompartmentEnumValue type, const SaturationCalculator& satCalc, const bool& getNext);
	virtual ~SELiquidCircuitCompartment();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory
	virtual void FixUp(); //analyze and cache for optimization

	virtual bool Load(const CDM::LiquidCompartmentData& in);
	virtual std::unique_ptr<CDM::LiquidCompartmentData> Unload() const;
protected:
	void Unload(CDM::LiquidCompartmentData& data) const;
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

	virtual void AddChildCompartment(SELiquidCircuitCompartment<CompartmentEnumValue>& cmpt);

	virtual bool HasPH() const;
	virtual const SEScalar& GetPH();
	virtual double GetPH(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSubstanceQuantities() const;
	virtual bool HasSubstanceQuantity(const SESubstance& substance) const;
	virtual SELiquidCompartmentSubstanceQuantity& GetSubstanceQuantity(const SESubstance& substance);
	virtual const SELiquidCompartmentSubstanceQuantity* GetSubstanceQuantity(const SESubstance& substance) const;
	virtual const std::vector<SELiquidCompartmentSubstanceQuantity*>* GetSubstanceQuantities();
	virtual const std::vector<const SELiquidCompartmentSubstanceQuantity*>* GetSubstanceQuantities() const;
	virtual void RemoveSubstanceQuantity(const SESubstance& substance);

protected:
	const SaturationCalculator& m_SaturationCalculator;
	mutable const SELiquidCompartmentSubstanceQuantity* m_CO2SubQ; // Used for pH calculation
	mutable const SELiquidCompartmentSubstanceQuantity* m_HCO3SubQ; // Used for pH calculation

	SEScalar* m_pH;

	std::vector<SELiquidCompartmentSubstanceQuantity*> m_SubstanceQuantities;
	std::vector<const SELiquidCompartmentSubstanceQuantity*> m_cSubstanceQuantities;
};
#include "circuit/compartment/SELiquidCircuitCompartment.inl"
