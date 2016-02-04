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
#include "SECompartmentSubstanceQuantity.h"
CDM_BIND_DECL(LiquidCompartmentSubstanceQuantityData)

enum class BalanceLiquidBy { Mass, Concentration, PartialPressure };

class DLL_DECL SELiquidCompartmentSubstanceQuantity : public virtual SECompartmentSubstanceQuantity
{
public:
	virtual ~SELiquidCompartmentSubstanceQuantity(){};

	virtual bool Load(const CDM::LiquidCompartmentSubstanceQuantityData& in) = 0;
	virtual std::unique_ptr<CDM::LiquidCompartmentSubstanceQuantityData> Unload() const = 0;

	virtual void Balance(BalanceLiquidBy e) = 0;// Balance Substance based on a specific property

	virtual bool HasConcentration() const = 0;
	virtual SEScalarMassPerVolume& GetConcentration() = 0;
	virtual double GetConcentration(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasMass() const = 0;
	virtual SEScalarMass& GetMass() = 0;
	virtual double GetMass(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
	
	virtual bool HasMolarity() const = 0;
	virtual const SEScalarAmountPerVolume& GetMolarity() = 0;
	virtual double GetMolarity(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
	
	virtual bool HasPartialPressure() const = 0;
	virtual SEScalarPressure& GetPartialPressure() = 0;
	virtual double GetPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasSaturation() const = 0;
	virtual SEScalarFraction& GetSaturation() = 0;
	virtual double GetSaturation(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

protected:
	
};