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
CDM_BIND_DECL(FluidCompartmentData)

template <typename CompartmentEnumValue>
class SEFluidCompartment : public virtual SECompartment<CompartmentEnumValue>
{
public:

	virtual ~SEFluidCompartment(){};

	virtual bool HasInFlow() const = 0;
	virtual SEScalarVolumePerTime& GetInFlow() = 0;
	virtual double GetInFlow(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasOutFlow() const = 0;
	virtual SEScalarVolumePerTime& GetOutFlow() = 0;
	virtual double GetOutFlow(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasPressure() const = 0;
	virtual SEScalarPressure& GetPressure() = 0;
	virtual double GetPressure(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasVolume() const = 0;
	virtual SEScalarVolume& GetVolume() = 0;
	virtual double GetVolume(const std::shared_ptr<CCompoundUnit>& unit) const = 0;

	virtual bool HasUnstressedVolume() const = 0;
	virtual SEScalarVolume& GetUnstressedVolume() = 0;
	virtual double GetUnstressedVolume(const std::shared_ptr<CCompoundUnit>& unit) const = 0;
};