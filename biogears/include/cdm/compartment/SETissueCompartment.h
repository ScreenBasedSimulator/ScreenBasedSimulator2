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
#include "compartment/SEFluidCompartment.h"
CDM_BIND_DECL(TissueCompartmentData)
#include "bind/enumAnatomy.hxx"
class SETissueCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SETissueCompartment : public virtual SECompartment<CompartmentEnumValue>
{
public:
	virtual ~SETissueCompartment(){};

	virtual bool Load(const CDM::TissueCompartmentData& in) = 0;
	virtual std::unique_ptr<CDM::TissueCompartmentData> Unload() const = 0;

	virtual SEScalarVolume& GetTissueVolume() = 0;
	virtual bool HasTissueVolume() const = 0;
	virtual double GetTissueVolume(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularInFlow() const = 0;
	virtual SEScalarVolumePerTime& GetExtravascularInFlow() = 0;
	virtual double GetExtravascularInFlow(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularOutFlow() const = 0;
	virtual SEScalarVolumePerTime& GetExtravascularOutFlow() = 0;
	virtual double GetExtravascularOutFlow(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularPressure() const = 0;
	virtual SEScalarPressure& GetExtravascularPressure() = 0;
	virtual double GetExtravascularPressure(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularVolume() const = 0;
	virtual SEScalarVolume& GetExtravascularVolume() = 0;
	virtual double GetExtravascularVolume(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularUnstressedVolume() const = 0;
	virtual SEScalarVolume& GetExtravascularUnstressedVolume() = 0;
	virtual double GetExtravascularUnstressedVolume(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasMetabolicFraction() const = 0;
	virtual SEScalarFraction& GetMetabolicFraction() = 0;
	virtual double GetMetabolicFraction(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasSubstanceQuantities() const = 0;
	virtual bool HasSubstanceQuantity(const SESubstance& substance) const = 0;
	virtual SETissueCompartmentSubstanceQuantity& GetSubstanceQuantity(const SESubstance& substance) = 0;
	virtual const SETissueCompartmentSubstanceQuantity* GetSubstanceQuantity(const SESubstance& substance) const = 0;
	virtual const std::vector<SETissueCompartmentSubstanceQuantity*>* GetSubstanceQuantities() = 0;
	virtual const std::vector<const SETissueCompartmentSubstanceQuantity*>* GetSubstanceQuantities() const = 0;
	virtual void RemoveSubstanceQuantity(const SESubstance& substance) = 0;
};