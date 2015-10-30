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
#include "circuit/compartment/SELiquidCircuitCompartmentSubstanceQuantity.h"
#include "bind/LiquidCompartmentSubstanceQuantityData.hxx"
#include "circuit/SECircuitNodeSubstanceQuantity.h"
#include "substance/SESubstance.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerAmount.h"
#include "properties/SEScalarAmountPerVolume.h"
#include "properties/SEScalarMassPerVolume.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarFraction.h"
#include "properties/SEScalarVolume.h"

template <typename CompartmentEnumValue>
SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::SELiquidCircuitCompartmentSubstanceQuantity(const SESubstance& substance, SEFluidCircuitCompartment<CompartmentEnumValue>& pnt, const SaturationCalculator& satCalc) : m_pnt(pnt),
                                                                                                                                                                                                                                         m_SaturationCalculator(satCalc),
																																																							             SECircuitCompartmentSubstanceQuantity(substance)
{
	FixUp();
	m_IsO2 = m_Substance.GetName() == "Oxygen";
	m_IsCO2 = m_Substance.GetName() == "CarbonDioxide";
	m_Saturate = true;

	m_Mass = nullptr;
	m_Concentration = nullptr;
	m_Molarity = nullptr;
	m_PartialPressure = nullptr;
	m_Saturation = nullptr;
}

template <typename CompartmentEnumValue>
SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::~SELiquidCircuitCompartmentSubstanceQuantity()
{
	Clear();	
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Clear()
{
	SECircuitCompartmentSubstanceQuantity::Clear();
	SAFE_DELETE(m_Mass);
	SAFE_DELETE(m_Concentration);
	SAFE_DELETE(m_Molarity);
	SAFE_DELETE(m_PartialPressure);
	SAFE_DELETE(m_Saturation);
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Reset()
{
	SECircuitCompartmentSubstanceQuantity::Reset();
	if (m_Mass != nullptr)
		m_Mass->Invalidate();
	if (m_Concentration != nullptr)
		m_Concentration->Invalidate();
	if (m_Molarity != nullptr)
		m_Molarity->Invalidate();
	if (m_PartialPressure != nullptr)
		m_PartialPressure->Invalidate();
	if (m_Saturation != nullptr)
		m_Saturation->Invalidate();
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::FixUp() const
{
	m_nSubQs.clear();
	for (SECircuitNode* node : m_pnt.m_Nodes)
		m_nSubQs.push_back(node->GetSubstanceQuantity((SESubstance*)&m_Substance));
}

template <typename CompartmentEnumValue>
const SEScalar* SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name.compare("Mass") == 0)
		return &GetMass();
	if (name.compare("Concentration") == 0)
		return &GetConcentration();
	if (name.compare("Molarity") == 0)
		return &GetMolarity();
	if (name.compare("PartialPressure") == 0)
		return &GetPartialPressure();
	if (name.compare("Saturation") == 0)
		return &GetSaturation();
	return nullptr;
}

template <typename CompartmentEnumValue>
void SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Balance(BalanceLiquidBy by)
{
	double totalVolume_mL = 0;
	for (SECircuitNode* n : m_pnt.m_Nodes)
	{
		if (n->HasNextVolume())
			totalVolume_mL += n->GetNextVolume()->GetValue(SEScalarVolume::mL);
	}
	switch (by)
	{
		case BalanceLiquidBy::Mass:
		{
			double mass_ug;// This is the new value to balance to
			if (m_nSubQs.size() == 1)
				mass_ug = m_pnt.m_GetNext ?
				m_nSubQs[0]->GetNextMass()->GetValue(SEScalarMass::ug) :
				m_nSubQs[0]->GetMass()->GetValue(SEScalarMass::ug);
			else if (m_Mass != nullptr)
				mass_ug = m_Mass->GetValue(SEScalarMass::ug);
			else
				SECircuitCompartmentSubstanceQuantity::Fatal("Updating Circuit with mass, but no mass provided");

			if (mass_ug < 0)
			{
				if (SEScalar::IsZero(mass_ug,1e-4))
					mass_ug = 0;
				else
				{
					std::stringstream ss;
					ss << "Cannot balance a negtive mass " << mass_ug << "(ug)";
					Fatal(ss);
				}
			}

			SECircuitNode* n;
			SECircuitNodeSubstanceQuantity* subQ;
			for (size_t i = 0; i < m_nSubQs.size(); i++)
			{
				n = m_pnt.m_Nodes[i];				
				subQ = m_nSubQs[i];
				double newMass_ug = totalVolume_mL==0 ? 0 : n->GetNextVolume()->GetValue(SEScalarVolume::mL) / totalVolume_mL * mass_ug;
				subQ->GetNextMass()->SetValue(newMass_ug, SEScalarMass::ug);
				m_pnt.m_math.CalculateConcentration(*subQ->GetNextMass(), *n->GetNextVolume(), *subQ->GetNextConcentration());
				if (m_Substance.GetState() == CDM::enumSubstanceState::Gas)
				{
					m_pnt.m_math.CalculatePartialPressureInLiquid(m_Substance, *subQ->GetNextConcentration(), *subQ->GetNextPartialPressure());
					if (m_Saturate)
					{
						if (m_IsO2)
							m_SaturationCalculator.CalculateOxygenSaturation(*n);
						if (m_IsCO2)
							m_SaturationCalculator.CalculateCarbonDioxideSaturation(*n);
					}
				}
			}
			break;
		}
		case BalanceLiquidBy::Concentration:
		{
			double concentration_ug_Per_mL;// This is the new value to balance to
			if (m_nSubQs.size() == 1)
				concentration_ug_Per_mL = m_pnt.m_GetNext ?
				m_nSubQs[0]->GetNextConcentration()->GetValue(SEScalarMassPerVolume::ug_Per_mL) :
				m_nSubQs[0]->GetConcentration()->GetValue(SEScalarMassPerVolume::ug_Per_mL);
			else if (m_Concentration != nullptr)
				concentration_ug_Per_mL = m_Concentration->GetValue(SEScalarMassPerVolume::ug_Per_mL);
			else
				SECircuitCompartmentSubstanceQuantity::Fatal("Updating Circuit with concentration, but no concentration provided");

			if (concentration_ug_Per_mL < 0)
			{
				if (SEScalar::IsZero(concentration_ug_Per_mL,1e-8))
					concentration_ug_Per_mL = 0;
				else
					Fatal("Cannot balance a negtive concentration");
			}

			SECircuitNode* n;
			SECircuitNodeSubstanceQuantity* subQ;
			for (size_t i = 0; i < m_nSubQs.size(); i++)
			{
				n = m_pnt.m_Nodes[i];
				subQ = m_nSubQs[i];
				subQ->GetNextConcentration()->SetValue(concentration_ug_Per_mL, SEScalarMassPerVolume::ug_Per_mL);
				subQ->GetNextMass()->SetValue(concentration_ug_Per_mL * n->GetNextVolume()->GetValue(SEScalarVolume::mL), SEScalarMass::ug);
				if (m_Substance.GetState() == CDM::enumSubstanceState::Gas)
				{
					m_pnt.m_math.CalculatePartialPressureInLiquid(m_Substance, *subQ->GetNextConcentration(), *subQ->GetNextPartialPressure());
					if (m_Saturate)
					{
						if (m_IsO2)
							m_SaturationCalculator.CalculateOxygenSaturation(*n);
						if (m_IsCO2)
							m_SaturationCalculator.CalculateCarbonDioxideSaturation(*n);
					}
				}
			}
			break;
		}
		case BalanceLiquidBy::PartialPressure:
		{
			if (m_Substance.GetState() != CDM::enumSubstanceState::Gas)
				SECircuitCompartmentSubstanceQuantity::Fatal("Updating Circuit with partial pressure, but substance is not a gas");
			double partialPressure_mmHg;// This is the new value to balance to
			if (m_nSubQs.size() == 1)
				partialPressure_mmHg = m_pnt.m_GetNext ?
				m_nSubQs[0]->GetNextPartialPressure()->GetValue(SEScalarPressure::mmHg) :
				m_nSubQs[0]->GetPartialPressure()->GetValue(SEScalarPressure::mmHg);
			else if (m_PartialPressure != nullptr)
				partialPressure_mmHg = m_PartialPressure->GetValue(SEScalarPressure::mmHg);
			else
				SECircuitCompartmentSubstanceQuantity::Fatal("Updating Circuit with partial pressure, but no partial pressure provided");				
			SECircuitNode* n;
			SECircuitNodeSubstanceQuantity* subQ;
			for (size_t i = 0; i < m_nSubQs.size(); i++)
			{
				n = m_pnt.m_Nodes[i];
				subQ = m_nSubQs[i];
				subQ->GetNextPartialPressure()->SetValue(partialPressure_mmHg, SEScalarPressure::mmHg);
				n->SetSubstanceMassFromPartialPressure((SESubstance*)&m_Substance);
				m_pnt.m_math.CalculateConcentration(*subQ->GetNextMass(), *n->GetNextVolume(), *subQ->GetNextConcentration());
				if (m_Saturate)
				{
					if (m_IsO2)
						m_SaturationCalculator.CalculateOxygenSaturation(*n);
					if (m_IsCO2)
						m_SaturationCalculator.CalculateCarbonDioxideSaturation(*n);
				}
			}
			break;
		}
	}
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Load(const CDM::LiquidCompartmentSubstanceQuantityData& in)
{
	if (in.Mass().present())
		GetMass().Load(in.Mass().get());
	if (in.Concentration().present())
		GetConcentration().Load(in.Concentration().get());
	if (in.PartialPressure().present())
	{
		GetPartialPressure();
		m_PartialPressure->Load(in.PartialPressure().get());
	}
	if (in.Saturation().present())
	{
		GetSaturation();
		m_Saturation->Load(in.Saturation().get());
	}
	return true;
}
template <typename CompartmentEnumValue>
std::unique_ptr<CDM::LiquidCompartmentSubstanceQuantityData> SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::LiquidCompartmentSubstanceQuantityData> data(new CDM::LiquidCompartmentSubstanceQuantityData());
	Unload(*data);
	return data;
}
template <typename CompartmentEnumValue>
void SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Unload(CDM::LiquidCompartmentSubstanceQuantityData& data) const
{
	if (HasMass())
		data.Mass(*(CDM::ScalarMassData*)(m_Mass->Unload().get()));
	if (HasConcentration())
		data.Concentration(*(CDM::ScalarMassPerVolumeData*)(m_Concentration->Unload().get()));
	if (HasPartialPressure())
		data.PartialPressure(*(CDM::ScalarPressureData*)(m_PartialPressure->Unload().get()));
	if (HasSaturation())
		data.Saturation(*(CDM::ScalarFractionData*)(m_Saturation->Unload().get()));
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasConcentration() const
{
	if (m_nSubQs.empty())
		FixUp();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		if (sq->HasNextConcentration())
			return true;
	if (m_Concentration != nullptr && m_Concentration->IsValid())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarMassPerVolume& SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetConcentration()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextConcentration() : *m_nSubQs[0]->GetConcentration();
	if (m_Concentration == nullptr)
		m_Concentration = new SEScalarMassPerVolume();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	if (HasMass())// If we don't have mass, return what we have
		m_pnt.m_math.CalculateConcentration(GetMass(), m_pnt.GetVolume(), *m_Concentration);// we wouldn't need this line
	return *m_Concentration;
}
template <typename CompartmentEnumValue>
double SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetConcentration(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
	{
		if (m_pnt.m_GetNext)
		{
			if (!m_nSubQs[0]->GetNextConcentration()->IsValid())
				return SEScalar::dNaN();
			m_nSubQs[0]->GetNextConcentration()->GetValue(unit);
		}
		else
		{
			if (!m_nSubQs[0]->GetConcentration()->IsValid())
				return SEScalar::dNaN();
			m_nSubQs[0]->GetConcentration()->GetValue(unit);
		}
	}
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	if (HasMass() && m_pnt.HasVolume())
	{
		if (m_Concentration == nullptr)
			m_Concentration = new SEScalarMassPerVolume();
		m_Concentration->SetValue(GetMass(SEScalarMass::ug) / m_pnt.GetVolume(SEScalarVolume::mL), SEScalarMassPerVolume::ug_Per_mL);		
		return m_Concentration->GetValue(unit);
	}
	if (m_Concentration != nullptr)
		return m_Concentration->GetValue(unit);
	return SEScalar::dNaN();
	// If no node subQ, then we hold the value, and we can use this
	//if (m_Concentration == nullptr)
	//	return SEScalar::dNaN();
	//return m_Concentration->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasMass() const
{
	if (m_nSubQs.empty())
		FixUp();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		if (sq->HasNextMass())
			return true;
	if (m_Mass != nullptr && m_Mass->IsValid())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarMass& SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetMass()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextMass() : *m_nSubQs[0]->GetMass();
	if (m_Mass == nullptr)
		m_Mass = new SEScalarMass(); 
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	// we would just return *m_Mass
	m_Mass->Invalidate();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		m_Mass->Increment(m_pnt.m_GetNext ? sq->GetNextMass() : sq->GetMass());
	return *m_Mass;
}
template <typename CompartmentEnumValue>
double SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetMass(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? m_nSubQs[0]->GetNextMass()->GetValue(unit) : m_nSubQs[0]->GetMass()->GetValue(unit);
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	double d = 0;
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		d += m_pnt.m_GetNext ? sq->GetNextMass()->GetValue(unit) : sq->GetMass()->GetValue(unit);
	return d;
	// If no node subQ, then we hold the value, and we can use this
	//if (m_Mass == nullptr)
	//	return SEScalar::dNaN();
	//return m_Mass->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasMolarity() const
{
	return HasConcentration();
}
template <typename CompartmentEnumValue>
const SEScalarAmountPerVolume& SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetMolarity()
{
	if (m_Molarity == nullptr)
		m_Molarity = new SEScalarAmountPerVolume();
	m_Molarity->SetValue(GetConcentration(SEScalarMassPerVolume::ug_Per_L) / m_Substance.GetMolarMass(SEScalarMassPerAmount::ug_Per_mmol), SEScalarAmountPerVolume::mmol_Per_L);
	return *m_Molarity;
}
template <typename CompartmentEnumValue>
double SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetMolarity(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return Convert(GetConcentration(SEScalarMassPerVolume::ug_Per_mL) / m_Substance.GetMolarMass(SEScalarMassPerAmount::ug_Per_mmol), SEScalarAmountPerVolume::mmol_Per_mL, unit);
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasPartialPressure() const
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
SEScalarPressure& SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetPartialPressure()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextPartialPressure() : *m_nSubQs[0]->GetPartialPressure();
	if (m_PartialPressure == nullptr)
		m_PartialPressure = new SEScalarPressure();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	m_pnt.m_math.CalculatePartialPressureInLiquid(m_Substance, GetConcentration(), *m_PartialPressure);// we wouldn't need this line
	return *m_PartialPressure;
}
template <typename CompartmentEnumValue>
double SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? m_nSubQs[0]->GetNextPartialPressure()->GetValue(unit) : m_nSubQs[0]->GetPartialPressure()->GetValue(unit);
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	if (m_PartialPressure == nullptr)
		m_PartialPressure = new SEScalarPressure();
	if (m_Concentration == nullptr)
		m_Concentration = new SEScalarMassPerVolume();// inside a const method, you can only call other const methods
	m_Concentration->SetValue(GetConcentration(SEScalarMassPerVolume::ug_Per_mL), SEScalarMassPerVolume::ug_Per_mL);
	m_pnt.m_math.CalculatePartialPressureInLiquid(m_Substance, *m_Concentration, *m_PartialPressure);
	return m_PartialPressure->GetValue(unit);
	// If no node subQ, then we hold the value, and we can use this
	//if (m_PartialPressure == nullptr)
	//	return SEScalar::dNaN();
	//return m_PartialPressure->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasSaturation() const
{
	if (!m_IsO2 && !m_IsCO2)
		return false;
	if (m_nSubQs.empty())
		FixUp();
	for (SECircuitNodeSubstanceQuantity* sq : m_nSubQs)
		if (sq->HasNextSaturation())
			return true;
	if (m_Saturation != nullptr && m_Saturation->IsValid())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarFraction& SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetSaturation()
{
	if (!m_IsO2 && !m_IsCO2)
		SECircuitCompartmentSubstanceQuantity::Fatal("Substance does not support saturation data");
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? *m_nSubQs[0]->GetNextSaturation() : *m_nSubQs[0]->GetSaturation();
	if (m_Saturation == nullptr)
		m_Saturation = new SEScalarFraction();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	double d = 0;
	for (size_t i = 0; i < m_pnt.m_Nodes.size(); i++)
		d += m_pnt.m_Nodes[i]->GetNextVolume()->GetValue(SEScalarVolume::mL)*m_nSubQs[i]->GetNextSaturation()->GetValue();
	m_Saturation->SetValue(d / m_pnt.GetVolume(SEScalarVolume::mL));
	return *m_Saturation;
}
template <typename CompartmentEnumValue>
double SELiquidCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetSaturation(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (!m_IsO2 && !m_IsCO2)
		SECircuitCompartmentSubstanceQuantity::Fatal("Substance does not support saturation data");
	if (m_nSubQs.empty())
		FixUp();
	if (m_nSubQs.size() == 1)
		return m_pnt.m_GetNext ? m_nSubQs[0]->GetNextSaturation()->GetValue(unit) : m_nSubQs[0]->GetSaturation()->GetValue(unit);
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	double d = 0;
	for (size_t i = 0; i < m_pnt.m_Nodes.size(); i++)
		d += m_pnt.m_Nodes[i]->GetNextVolume()->GetValue(SEScalarVolume::mL)*m_nSubQs[i]->GetNextSaturation()->GetValue();
	return d / m_pnt.GetVolume(SEScalarVolume::mL);
	// If no node subQ, then we hold the value, and we can use this
	//if (m_Saturation == nullptr)
	//	return SEScalar::dNaN();
	//return m_Saturation->GetValue(unit);
}
