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
#include "circuit/compartment/SELiquidCircuitCompartment.h"
#include "bind/LiquidCompartmentData.hxx"
#include "circuit/compartment/SELiquidCircuitCompartmentSubstanceQuantity.h"
#include "bind/LiquidCompartmentSubstanceQuantityData.hxx"
#include "substance/SESubstance.h"
#include "properties/SEScalarPressure.h"
#include "bind/ScalarPressureData.hxx"
#include "properties/SEScalarVolume.h"
#include "bind/ScalarVolumeData.hxx"
#include "properties/SEScalarVolumePerTime.h"
#include "bind/ScalarFractionData.hxx"
#include "bind/ScalarVolumePerTimeData.hxx"

template <typename CompartmentEnumValue>
SELiquidCircuitCompartment<CompartmentEnumValue>::SELiquidCircuitCompartment(CompartmentEnumValue type, const SaturationCalculator& satCalc, const bool& getNext) : SEFluidCircuitCompartment<CompartmentEnumValue>(type, satCalc.GetLogger(), getNext),
																																				                    m_SaturationCalculator(satCalc)
{
	m_CO2SubQ = nullptr;
	m_HCO3SubQ = nullptr;
	m_pH = nullptr;
}

template <typename CompartmentEnumValue>
SELiquidCircuitCompartment<CompartmentEnumValue>::~SELiquidCircuitCompartment()
{
	Clear();
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartment<CompartmentEnumValue>::Clear()
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Clear();

	m_CO2SubQ = nullptr;
	m_HCO3SubQ = nullptr;
	SAFE_DELETE(m_pH);
	DELETE_VECTOR(m_SubstanceQuantities);
	m_cSubstanceQuantities.clear();
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartment<CompartmentEnumValue>::Reset()
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Reset();

	INVALIDATE_PROPERTY(m_pH);
	for (SELiquidCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		subQ->Reset();
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartment<CompartmentEnumValue>::FixUp()
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::FixUp();
	if (this->m_PrimaryNode != nullptr)
	{
		for (SECircuitNodeSubstanceQuantity* subQ : *this->m_PrimaryNode->GetSubstanceQuantities())
			dynamic_cast<SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>&>(this->GetSubstanceQuantity(*subQ->GetSubstance())).FixUp();
	}
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartment<CompartmentEnumValue>::AddChildCompartment(SELiquidCircuitCompartment<CompartmentEnumValue>& cmpt)
{
	for (SECircuitNode* n : cmpt.m_allNodes)
		SECircuitCompartment<CompartmentEnumValue>::AddNode(*n);
	for (SECircuitPath* p : cmpt.GetPaths())
		SECircuitCompartment<CompartmentEnumValue>::AddPath(*p);
}

template <typename CompartmentEnumValue>
const SEScalar* SELiquidCircuitCompartment<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name == "pH")
		return &GetPH();
	return SEFluidCircuitCompartment<CompartmentEnumValue>::GetScalar(name);
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartment<CompartmentEnumValue>::Load(const CDM::LiquidCompartmentData& in)
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Load(in);

	if (in.pH().present())
	{
		GetPH();
		m_pH->Load(in.pH().get());
	}
	//SESubstance* substance;
	//SECompartmentSubstanceQuantity* subQ;
	for (size_t i = 0; i < in.SubstanceQuantity().size(); i++)
	{
		// TODO Look up the substance somehow, pass in managers in load?
		//std::cout<<in.SubstanceQuantity()[i].Name()<<std::endl;
		//substance = new SESubstance();//SubstanceManager.getSubstance(in.SubstanceQuantity[i].name());
		//subQ = new SECompartmentSubstanceQuantity(*substance);
		//m_SubstanceQuantities.push_back(subQ);
		//m_cSubstanceQuantities.push_back(subQ);
	}
	return true;
}
template <typename CompartmentEnumValue>
std::unique_ptr<CDM::LiquidCompartmentData>  SELiquidCircuitCompartment<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::LiquidCompartmentData> data(new CDM::LiquidCompartmentData());
	Unload(*data);
	return data;
}
template <typename CompartmentEnumValue>
void SELiquidCircuitCompartment<CompartmentEnumValue>::Unload(CDM::LiquidCompartmentData& data) const
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Unload(data);
	if (m_pH != nullptr)
		data.pH(*(CDM::ScalarData*)(m_pH->Unload().get()));
	// TODO Unload the list of Substance Quantities
};

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartment<CompartmentEnumValue>::HasPH() const
{
	if (m_HCO3SubQ != nullptr && m_HCO3SubQ->HasMolarity() &&
		m_CO2SubQ != nullptr && m_CO2SubQ->HasPartialPressure())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
const SEScalar& SELiquidCircuitCompartment<CompartmentEnumValue>::GetPH()
{
	if (m_pH == nullptr)
		m_pH = new SEScalar();
	m_pH->SetValue(GetPH(SEScalar::nullUnit));
	return *m_pH;
}
template <typename CompartmentEnumValue>
double SELiquidCircuitCompartment<CompartmentEnumValue>::GetPH(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_HCO3SubQ == nullptr)
		m_HCO3SubQ = GetSubstanceQuantity(*m_SaturationCalculator.m_HCO3);
	if (m_CO2SubQ == nullptr)
		m_CO2SubQ = GetSubstanceQuantity(*m_SaturationCalculator.m_CO2);
	if (m_HCO3SubQ != nullptr && m_CO2SubQ != nullptr)
		return m_SaturationCalculator.CalculateBloodPH(m_CO2SubQ->GetPartialPressure(SEScalarPressure::mmHg), m_HCO3SubQ->GetMolarity(SEScalarAmountPerVolume::mmol_Per_L));
	return SEScalar::dNaN();
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartment<CompartmentEnumValue>::HasSubstanceQuantities() const
{
	return m_SubstanceQuantities.size() > 0 ? true : false;
}
template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartment<CompartmentEnumValue>::HasSubstanceQuantity(const SESubstance& substance) const
{
	for (SELiquidCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return true;
	return false;
}
template <typename CompartmentEnumValue>
SELiquidCompartmentSubstanceQuantity& SELiquidCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantity(const SESubstance& substance)
{
	for (SELiquidCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return *subQ;

	SEFluidCircuitCompartment<CompartmentEnumValue>* fluid = this;
	SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>* sq = new SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>(substance, *fluid, m_SaturationCalculator);
	m_SubstanceQuantities.push_back(sq);
	m_cSubstanceQuantities.push_back(sq);
	return *sq;
}
template <typename CompartmentEnumValue>
const SELiquidCompartmentSubstanceQuantity* SELiquidCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantity(const SESubstance& substance) const
{
	for (SELiquidCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return subQ;
	return nullptr;
}
template <typename CompartmentEnumValue>
const std::vector<SELiquidCompartmentSubstanceQuantity*>* SELiquidCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantities()
{
	return &m_SubstanceQuantities;
}
template <typename CompartmentEnumValue>
const std::vector<const SELiquidCompartmentSubstanceQuantity*>* SELiquidCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantities() const
{
	return &m_cSubstanceQuantities;
}
template <typename CompartmentEnumValue>
void SELiquidCircuitCompartment<CompartmentEnumValue>::RemoveSubstanceQuantity(const SESubstance& substance)
{
	for (auto sq = m_SubstanceQuantities.begin(); sq != m_SubstanceQuantities.end(); ++sq)
	{
		if (&(*sq)->GetSubstance() == &substance)
		{
			m_SubstanceQuantities.erase(sq);
			SAFE_DELETE(*sq);
			return;
		}
	}
	for (auto sq = m_cSubstanceQuantities.begin(); sq != m_cSubstanceQuantities.end(); ++sq)
	{
		if (&(*sq)->GetSubstance() == &substance)
		{
			m_cSubstanceQuantities.erase(sq);
			return;
		}
	}
}

