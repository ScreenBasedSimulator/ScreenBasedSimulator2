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

#include "stdafx.h"
#include "circuit/SECircuitNodeSubstanceQuantity.h"
#include "bind/GasCompartmentSubstanceQuantityData.hxx"
#include "substance/SESubstance.h"
#include "properties/SEScalarMass.h"
#include "bind/ScalarMassData.hxx"
#include "properties/SEScalarMassPerVolume.h"
#include "bind/ScalarMassPerVolumeData.hxx"
#include "properties/SEScalarPressure.h"
#include "bind/ScalarPressureData.hxx"
#include "properties/SEScalarFraction.h"
#include "bind/ScalarFractionData.hxx"
#include "properties/SEScalarVolume.h"
#include "bind/ScalarVolumeData.hxx"

template <typename CompartmentEnumValue>
SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::SEGasCircuitCompartmentSubstanceQuantity(const SESubstance& substance, SEGasCircuitCompartment<CompartmentEnumValue>& pnt) : m_pnt(pnt), SECircuitCompartmentSubstanceQuantity(substance)
{
	m_PartialPressure = nullptr;
	m_Volume = nullptr;
	m_VolumeFraction = nullptr;
	FixUp();
}

template <typename CompartmentEnumValue>
SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::~SEGasCircuitCompartmentSubstanceQuantity()
{
	Clear();	
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Clear()
{
	SECircuitCompartmentSubstanceQuantity::Clear();

	SAFE_DELETE(m_PartialPressure);
	SAFE_DELETE(m_Volume);
	SAFE_DELETE(m_VolumeFraction);
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Reset()
{
	SECircuitCompartmentSubstanceQuantity::Reset();

	if (m_PartialPressure != nullptr)
		m_PartialPressure->Invalidate();
	if (m_Volume != nullptr)
		m_Volume->Invalidate();
	if (m_VolumeFraction != nullptr)
		m_VolumeFraction->Invalidate();
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::FixUp() const
{
	m_nSubQs.clear();
	for (SECircuitNode* node : m_pnt.m_Nodes)
		m_nSubQs.push_back(node->GetSubstanceQuantity((SESubstance*)&m_Substance));
}

template <typename CompartmentEnumValue>
const SEScalar* SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name.compare("PartialPressure") == 0)
		return &GetPartialPressure();
	if (name.compare("Volume") == 0)
		return &GetVolume();
	if (name.compare("VolumeFraction") == 0)
		return &GetVolumeFraction();
	return nullptr;
}

template <typename CompartmentEnumValue>
bool SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Load(const CDM::GasCompartmentSubstanceQuantityData& in)
{
	if (in.PartialPressure().present())
	{
		GetPartialPressure();
		m_PartialPressure->Load(in.PartialPressure().get());
	}
	if (in.Volume().present())
		GetVolume().Load(in.Volume().get());
	if (in.VolumeFraction().present())
		GetVolumeFraction().Load(in.VolumeFraction().get());
	return true;
}
template <typename CompartmentEnumValue>
std::unique_ptr<CDM::GasCompartmentSubstanceQuantityData> SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::GasCompartmentSubstanceQuantityData> data(new CDM::GasCompartmentSubstanceQuantityData());
	Unload(*data);
	return data;
}
template <typename CompartmentEnumValue>
void SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Unload(CDM::GasCompartmentSubstanceQuantityData& data) const
{
	if (HasPartialPressure())
		data.PartialPressure(*(CDM::ScalarPressureData*)(m_PartialPressure->Unload().get()));
	if (HasVolume())
		data.Volume(*(CDM::ScalarVolumeData*)(m_Volume->Unload().get()));
	if (HasVolumeFraction())
		data.VolumeFraction(*(CDM::ScalarFractionData*)(m_VolumeFraction->Unload().get()));
}

template <typename CompartmentEnumValue>
bool SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasPartialPressure() const
{
	if (m_nSubQs.empty())
		FixUp();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		if (sq->HasNextPartialPressure())
			return true;
	if (m_PartialPressure != nullptr && m_PartialPressure->IsValid())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarPressure& SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetPartialPressure()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextPartialPressure() : *m_nSubQs[0]->GetPartialPressure();
	if (m_PartialPressure == nullptr)
		m_PartialPressure = new SEScalarPressure();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	m_pnt.m_math.CalculatePartialPressureInGas(GetVolumeFraction(), m_pnt.GetPressure(), *m_PartialPressure);// we wouldn't need this line
	return *m_PartialPressure;
}
template <typename CompartmentEnumValue>
double SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? m_nSubQs[0]->GetNextPartialPressure()->GetValue(unit) : m_nSubQs[0]->GetPartialPressure()->GetValue(unit);
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	if (m_PartialPressure == nullptr)
		m_PartialPressure = new SEScalarPressure();
	if (m_VolumeFraction == nullptr)
		m_VolumeFraction = new SEScalarFraction();// in a const method, gotta call other const methods
	m_VolumeFraction->SetValue(GetVolumeFraction(SEScalar::nullUnit));
	m_pnt.m_math.CalculatePartialPressureInGas(*m_VolumeFraction, m_pnt.GetPressure(), *m_PartialPressure);
	return m_PartialPressure->GetValue(unit);
	// If no node subQ, then we hold the value, and we can use this
	//if (m_PartialPressure == nullptr)
	//	return SEScalar::dNaN();
	//return m_PartialPressure->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasVolume() const
{
	if (m_nSubQs.empty())
		FixUp();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		if (sq->HasNextVolume())
			return true;
	if (m_Volume != nullptr && m_Volume->IsValid())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarVolume& SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetVolume()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextVolume() : *m_nSubQs[0]->GetVolume();
	if (m_Volume == nullptr)
		m_Volume = new SEScalarVolume();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	// we would just return *m_Volume
	m_Volume->Invalidate();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		m_Volume->Increment(m_pnt.m_GetNext ? sq->GetNextVolume() : sq->GetVolume());
	return *m_Volume;
}
template <typename CompartmentEnumValue>
double SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetVolume(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? m_nSubQs[0]->GetNextVolume()->GetValue(unit) : m_nSubQs[0]->GetVolume()->GetValue(unit);
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	double d = 0;
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
	{
		if (m_pnt.m_GetNext)
		{
			if (!sq->HasNextVolume())
				d = SEScalar::dNaN();
			else
				d += sq->GetNextVolume()->GetValue(unit);
		}
		else
		{
			if (!sq->HasVolume())
				d = SEScalar::dNaN();
			else
				d += sq->GetVolume()->GetValue(unit);
		}
	}
	return d;
	// If no node subQ, then we hold the value, and we can use this
	//if (m_Volume == nullptr)
	//	return SEScalar::dNaN();
	//return m_Volume->GetValue(unit);
}


template <typename CompartmentEnumValue>
bool SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasVolumeFraction() const
{
	if (m_nSubQs.empty())
		FixUp();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		if (sq->HasNextVolumeFraction())
			return true;
	if (m_VolumeFraction != nullptr && m_VolumeFraction->IsValid())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarFraction& SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetVolumeFraction()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextVolumeFraction() : *m_nSubQs[0]->GetVolumeFraction();
	if (m_VolumeFraction == nullptr)
		m_VolumeFraction = new SEScalarFraction();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	m_VolumeFraction->SetValue(GetVolume(SEScalarVolume::mL) / m_pnt.GetVolume(SEScalarVolume::mL));// we wouldn't need this line
	return *m_VolumeFraction;
}
template <typename CompartmentEnumValue>
double SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetVolumeFraction(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? m_nSubQs[0]->GetNextVolumeFraction()->GetValue(unit) : m_nSubQs[0]->GetVolumeFraction()->GetValue(unit);
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	return GetVolume(SEScalarVolume::mL) / m_pnt.GetVolume(SEScalarVolume::mL);
	// If no node subQ, then we hold the value, and we can use this
	//if (m_VolumeFraction == nullptr)
	//	return SEScalar::dNaN();
	//return m_VolumeFraction->GetValue(unit);
}
