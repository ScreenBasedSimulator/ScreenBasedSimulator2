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
#include "SEFluidCompartment.h"
CDM_BIND_DECL(GasCompartmentData)
class SESubstance;
class SEGasCompartmentSubstanceQuantity;

enum class BalanceGasBy { Volume, VolumeFraction };

template <typename CompartmentEnumValue>
class SEGasCompartment : public virtual SEFluidCompartment<CompartmentEnumValue>
{
public:
	virtual ~SEGasCompartment(){};

	virtual void Balance(BalanceGasBy e) = 0;// Balance all substances based on a specific property

	virtual bool Load(const CDM::GasCompartmentData& in) = 0;
	virtual std::unique_ptr<CDM::GasCompartmentData> Unload() const = 0;


	virtual bool HasSubstanceQuantities() const = 0;
	virtual bool HasSubstanceQuantity(const SESubstance& substance) const = 0;
	virtual SEGasCompartmentSubstanceQuantity& GetSubstanceQuantity(const SESubstance& substance) = 0;
	virtual const SEGasCompartmentSubstanceQuantity* GetSubstanceQuantity(const SESubstance& substance) const = 0;
	virtual const std::vector<SEGasCompartmentSubstanceQuantity*>* GetSubstanceQuantities() = 0;
	virtual const std::vector<const SEGasCompartmentSubstanceQuantity*>* GetSubstanceQuantities() const = 0;
	virtual void RemoveSubstanceQuantity(const SESubstance& substance) = 0;

};