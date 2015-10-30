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
CDM_BIND_DECL(TissueCompartmentSubstanceQuantityData)
#include "compartment/SELiquidCompartmentSubstanceQuantity.h"

enum class BalanceTissueBy { Mass, TissueConcentration, ExtravascularConcentration, ExtravascularPartialPressure };

class DLL_DECL SETissueCompartmentSubstanceQuantity : public virtual SECompartmentSubstanceQuantity
{
public:
	virtual ~SETissueCompartmentSubstanceQuantity(){};

	virtual bool Load(const CDM::TissueCompartmentSubstanceQuantityData& in) = 0;
	virtual std::unique_ptr<CDM::TissueCompartmentSubstanceQuantityData> Unload() const = 0;

	virtual void Balance(BalanceTissueBy e) = 0;// Balance Substance based on a specific property

	virtual bool HasMass() const = 0;
	virtual SEScalarMass& GetMass() = 0;
	virtual double GetMass(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasTissueConcentration() const = 0;
	virtual SEScalarMassPerVolume& GetTissueConcentration() = 0;
	virtual double GetTissueConcentration(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasTissueMolarity() const = 0;
	virtual const SEScalarAmountPerVolume& GetTissueMolarity() = 0;
	virtual double GetTissueMolarity(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularConcentration() const = 0;
	virtual SEScalarMassPerVolume& GetExtravascularConcentration() = 0;
	virtual double GetExtravascularConcentration(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularMolarity() const = 0;
	virtual const SEScalarAmountPerVolume& GetExtravascularMolarity() = 0;
	virtual double GetExtravascularMolarity(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularPartialPressure() const = 0;
	virtual SEScalarPressure& GetExtravascularPartialPressure() = 0;
	virtual double GetExtravascularPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasExtravascularSaturation() const = 0;
	virtual SEScalarFraction& GetExtravascularSaturation() = 0;
	virtual double GetExtravascularSaturation(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
};