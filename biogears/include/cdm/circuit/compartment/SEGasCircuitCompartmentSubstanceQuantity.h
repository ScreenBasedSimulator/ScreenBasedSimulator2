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
#include "circuit/compartment/SECircuitCompartmentSubstanceQuantity.h"
#include "compartment/SEGasCompartmentSubstanceQuantity.h"

template <typename CompartmentEnumValue> class SEGasCircuitCompartment;

template <typename CompartmentEnumValue>
class SEGasCircuitCompartmentSubstanceQuantity : public virtual SEGasCompartmentSubstanceQuantity, public SECircuitCompartmentSubstanceQuantity
{
	friend SEGasCircuitCompartment<CompartmentEnumValue>;
public:

	SEGasCircuitCompartmentSubstanceQuantity(const SESubstance& substance, SEGasCircuitCompartment<CompartmentEnumValue>& pnt);
	virtual ~SEGasCircuitCompartmentSubstanceQuantity();

	virtual bool Load(const CDM::GasCompartmentSubstanceQuantityData& in);
	virtual std::unique_ptr<CDM::GasCompartmentSubstanceQuantityData> Unload() const;
protected:
	void Unload(CDM::GasCompartmentSubstanceQuantityData& data) const;
public:

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory
	virtual void FixUp()  const; // reconnect up to circuit

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual bool HasPartialPressure() const;
	virtual SEScalarPressure& GetPartialPressure();
	virtual double GetPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVolume() const;
	virtual SEScalarVolume& GetVolume();
	virtual double GetVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVolumeFraction() const;
	virtual SEScalarFraction& GetVolumeFraction();
	virtual double GetVolumeFraction(const std::shared_ptr<CCompoundUnit>& unit) const;
	
protected:
	SEGasCircuitCompartment<CompartmentEnumValue>& m_pnt;
	mutable std::vector<SECircuitNodeSubstanceQuantity*>   m_nSubQs;

	mutable SEScalarPressure*  m_PartialPressure;
	mutable SEScalarVolume*    m_Volume;
	mutable SEScalarFraction*  m_VolumeFraction;
};
#include "circuit/compartment/SEGasCircuitCompartmentSubstanceQuantity.inl"
