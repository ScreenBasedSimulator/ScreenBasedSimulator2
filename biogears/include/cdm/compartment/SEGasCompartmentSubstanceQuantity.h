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
CDM_BIND_DECL(GasCompartmentSubstanceQuantityData)

class DLL_DECL SEGasCompartmentSubstanceQuantity : public virtual SECompartmentSubstanceQuantity
{
public:
	virtual ~SEGasCompartmentSubstanceQuantity(){};

	virtual bool Load(const CDM::GasCompartmentSubstanceQuantityData& in) = 0;
	virtual std::unique_ptr<CDM::GasCompartmentSubstanceQuantityData> Unload() const = 0;

	virtual bool HasPartialPressure() const = 0;
	virtual SEScalarPressure& GetPartialPressure() = 0;
	virtual double GetPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
	
	virtual bool HasVolume() const = 0;
	virtual SEScalarVolume& GetVolume() = 0;
	virtual double GetVolume(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasVolumeFraction() const = 0;
	virtual SEScalarFraction& GetVolumeFraction() = 0;
	virtual double GetVolumeFraction(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
};