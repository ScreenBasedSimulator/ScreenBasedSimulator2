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
CDM_BIND_DECL(LiquidCompartmentData)
class SESubstance;
class SELiquidCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SELiquidCompartment : public virtual SEFluidCompartment<CompartmentEnumValue>
{
public:
	virtual ~SELiquidCompartment(){};

	virtual bool Load(const CDM::LiquidCompartmentData& in) = 0;
	virtual std::unique_ptr<CDM::LiquidCompartmentData> Unload() const = 0;

	virtual bool HasPH() const = 0;
	virtual const SEScalar& GetPH() = 0;
	virtual double GetPH(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasSubstanceQuantities() const = 0;
	virtual bool HasSubstanceQuantity(const SESubstance& substance) const = 0;
	virtual SELiquidCompartmentSubstanceQuantity& GetSubstanceQuantity(const SESubstance& substance) = 0;
	virtual const SELiquidCompartmentSubstanceQuantity* GetSubstanceQuantity(const SESubstance& substance) const = 0;
	virtual const std::vector<SELiquidCompartmentSubstanceQuantity*>* GetSubstanceQuantities() = 0;
	virtual const std::vector<const SELiquidCompartmentSubstanceQuantity*>* GetSubstanceQuantities() const = 0;
	virtual void RemoveSubstanceQuantity(const SESubstance& substance) = 0;

protected:

	

	
};