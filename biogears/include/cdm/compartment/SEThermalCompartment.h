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
#include "compartment/SECompartment.h"
CDM_BIND_DECL(ThermalCompartmentData)
#include "bind/enumAnatomy.hxx"

template <typename CompartmentEnumValue>
class SEThermalCompartment : public virtual SECompartment<CompartmentEnumValue>
{
public:
	virtual ~SEThermalCompartment(){};

	virtual bool Load(const CDM::ThermalCompartmentData& in) = 0;
	virtual std::unique_ptr<CDM::ThermalCompartmentData> Unload() const = 0;

	virtual bool HasHeat() const = 0;
	virtual SEScalarEnergy& GetHeat() = 0;
	virtual double GetHeat(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
	
	virtual bool HasHeatTransferRateIn() const = 0;
	virtual SEScalarPower& GetHeatTransferRateIn() = 0;
	virtual double GetHeatTransferRateIn(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasHeatTransferRateOut() const = 0;
	virtual SEScalarPower& GetHeatTransferRateOut() = 0;
	virtual double GetHeatTransferRateOut(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasTemperature() const = 0;
	virtual SEScalarTemperature& GetTemperature() = 0;
	virtual double GetTemperature(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
};