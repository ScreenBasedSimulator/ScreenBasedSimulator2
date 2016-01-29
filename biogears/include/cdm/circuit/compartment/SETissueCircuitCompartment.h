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
#include "compartment/SETissueCompartment.h"
#include "circuit/compartment/SEFluidCircuitCompartment.h"
template <typename CompartmentEnumValue> class SETissueCircuitCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SETissueCircuitCompartment : public virtual SETissueCompartment<CompartmentEnumValue>, public SECircuitCompartment<CompartmentEnumValue>
{
	friend SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>;
public:

	SETissueCircuitCompartment(CompartmentEnumValue type, const SaturationCalculator& satCalc, const bool& getNext);
	virtual ~SETissueCircuitCompartment();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values
	virtual void FixUp(); //analyze and cache for optimization

	virtual bool Load(const CDM::TissueCompartmentData& in);
	virtual std::unique_ptr<CDM::TissueCompartmentData> Unload() const;
protected:
	void Unload(CDM::TissueCompartmentData& data) const;
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

	virtual void AddNode(SECircuitNode& node);
	virtual void AddPath(SECircuitPath& path);
	virtual void SetPrimaryNode(SECircuitNode& node);
	virtual void AddChildCompartment(SETissueCircuitCompartment<CompartmentEnumValue>& cmpt);

	virtual SEScalarVolume& GetTissueVolume();
	virtual bool HasTissueVolume() const;
	virtual double GetTissueVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularInFlow() const;
	virtual SEScalarVolumePerTime& GetExtravascularInFlow();
	virtual double GetExtravascularInFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularOutFlow() const;
	virtual SEScalarVolumePerTime& GetExtravascularOutFlow();
	virtual double GetExtravascularOutFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularPressure() const;
	virtual SEScalarPressure& GetExtravascularPressure();
	virtual double GetExtravascularPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularVolume() const;
	virtual SEScalarVolume& GetExtravascularVolume();
	virtual double GetExtravascularVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExtravascularUnstressedVolume() const;
	virtual SEScalarVolume& GetExtravascularUnstressedVolume();
	virtual double GetExtravascularUnstressedVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMetabolicFraction() const;
	virtual SEScalarFraction& GetMetabolicFraction();
	virtual double GetMetabolicFraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSubstanceQuantities() const;
	virtual bool HasSubstanceQuantity(const SESubstance& substance) const;
	virtual SETissueCompartmentSubstanceQuantity& GetSubstanceQuantity(const SESubstance& substance);
	virtual const SETissueCompartmentSubstanceQuantity* GetSubstanceQuantity(const SESubstance& substance) const;
	virtual const std::vector<SETissueCompartmentSubstanceQuantity*>* GetSubstanceQuantities();
	virtual const std::vector<const SETissueCompartmentSubstanceQuantity*>* GetSubstanceQuantities() const;
	virtual void RemoveSubstanceQuantity(const SESubstance& substance);

protected:
	SEScalarFraction*							     m_MetabolicFraction;
	SEScalarVolume*								     m_TissueVolume;
	SEFluidCircuitCompartment<CompartmentEnumValue>  m_Extravascular;

	const SaturationCalculator&                      m_SaturationCalculator;

	std::vector<SETissueCompartmentSubstanceQuantity*> m_SubstanceQuantities;
	std::vector<const SETissueCompartmentSubstanceQuantity*> m_cSubstanceQuantities;
};
#include "circuit/compartment/SETissueCircuitCompartment.inl"