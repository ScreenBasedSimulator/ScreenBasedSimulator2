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
#include "compartment/SEGasCompartment.h"
#include "circuit/compartment/SEFluidCircuitCompartment.h"
class SESubstance;
template <typename CompartmentEnumValue> class SEGasCircuitCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SEGasCircuitCompartment : public virtual SEGasCompartment<CompartmentEnumValue>, public SEFluidCircuitCompartment<CompartmentEnumValue>
{
	friend SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>;
public:

	SEGasCircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext);
	virtual ~SEGasCircuitCompartment();

	virtual bool Load(const CDM::GasCompartmentData& in);
	virtual std::unique_ptr<CDM::GasCompartmentData> Unload() const;
protected:
	void Unload(CDM::GasCompartmentData& data) const;
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

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory
	virtual void FixUp(); //analyze and cache for optimization
	virtual void Balance(BalanceGasBy e);// Balance all substances based on a specific property

	virtual void AddChildCompartment(SEGasCircuitCompartment<CompartmentEnumValue>& cmpt);

	virtual bool HasSubstanceQuantities() const;
	virtual bool HasSubstanceQuantity(const SESubstance& substance) const;
	virtual SEGasCompartmentSubstanceQuantity& GetSubstanceQuantity(const SESubstance& substance);
	virtual const SEGasCompartmentSubstanceQuantity* GetSubstanceQuantity(const SESubstance& substance) const;
	virtual const std::vector<SEGasCompartmentSubstanceQuantity*>* GetSubstanceQuantities();
	virtual const std::vector<const SEGasCompartmentSubstanceQuantity*>* GetSubstanceQuantities() const;
	virtual void RemoveSubstanceQuantity(const SESubstance& substance);

protected:
	std::vector<SEGasCompartmentSubstanceQuantity*>       m_SubstanceQuantities;
	std::vector<const SEGasCompartmentSubstanceQuantity*> m_cSubstanceQuantities;

};
#include "circuit/compartment/SEGasCircuitCompartment.inl"