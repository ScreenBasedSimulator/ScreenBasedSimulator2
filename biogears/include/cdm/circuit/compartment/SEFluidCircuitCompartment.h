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
#include "SECircuitCompartment.h"
#include "compartment/SEFluidCompartment.h"
template <typename CompartmentEnumValue> class SETissueCircuitCompartment;
template <typename CompartmentEnumValue> class SELiquidCircuitCompartmentSubstanceQuantity;
template <typename CompartmentEnumValue> class SETissueCircuitCompartmentSubstanceQuantity;

template <typename CompartmentEnumValue>
class SEFluidCircuitCompartment : public virtual SEFluidCompartment<CompartmentEnumValue>, public SECircuitCompartment<CompartmentEnumValue>
{
	friend SETissueCircuitCompartment <CompartmentEnumValue>;
	friend SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>;
	friend SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>;
public:

	SEFluidCircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext);
	virtual ~SEFluidCircuitCompartment();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::FluidCompartmentData& in);
	std::unique_ptr<CDM::FluidCompartmentData> Unload() const;
protected:
	void Unload(CDM::FluidCompartmentData& data) const;
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

	virtual bool HasInFlow() const;
	virtual SEScalarVolumePerTime& GetInFlow();
	virtual double GetInFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasOutFlow() const;
	virtual SEScalarVolumePerTime& GetOutFlow();
	virtual double GetOutFlow(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasPressure() const;
	virtual SEScalarPressure& GetPressure();
	virtual double GetPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVolume() const;
	virtual SEScalarVolume& GetVolume();
	virtual double GetVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasUnstressedVolume() const;
	virtual SEScalarVolume& GetUnstressedVolume();
	virtual double GetUnstressedVolume(const std::shared_ptr<CCompoundUnit>& unit) const;


protected:
	virtual double CalculateInFlow_mL_Per_s() const;
	virtual double CalculateOutFlow_mL_Per_s() const;

	SEScalarVolumePerTime* m_InFlow;
	SEScalarVolumePerTime* m_OutFlow;
	SEScalarPressure*      m_Pressure;
	SEScalarVolume*        m_UnstressedVolume;
	SEScalarVolume*        m_Volume;
};
#include "circuit/compartment/SEFluidCircuitCompartment.inl"