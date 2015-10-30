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
#include "circuit/compartment/SETissueCircuitCompartmentSubstanceQuantity.h"
#include "circuit/SECircuitNodeSubstanceQuantity.h"
#include "substance/SESubstance.h"
#include "properties/SEScalarMass.h"
#include "bind/ScalarMassData.hxx"
#include "properties/SEScalarMassPerVolume.h"
#include "bind/ScalarMassPerVolumeData.hxx"

template <typename CompartmentEnumValue>
SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::SETissueCircuitCompartmentSubstanceQuantity(const SESubstance& substance, SETissueCircuitCompartment<CompartmentEnumValue>& pnt, const SaturationCalculator& satCalc) : m_pnt(pnt),
                                                                                                                                                                                                                                           m_SaturationCalculator(satCalc),
																																																									       m_extravascular(substance, pnt.m_Extravascular, satCalc),
                                                                                                                                                                                                                                           SECircuitCompartmentSubstanceQuantity(substance)
{
	FixUp();
	m_IsO2 = m_Substance.GetName() == "Oxygen";
	m_IsCO2 = m_Substance.GetName() == "CarbonDioxide";
	m_extravascular.SaturateAtBalance(false);//Tissue does not call the saturation calculator when balancing

	m_TissueConcentration = nullptr;
	m_TissueMolarity = nullptr;
}

template <typename CompartmentEnumValue>
SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::~SETissueCircuitCompartmentSubstanceQuantity()
{
	Clear();	
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Clear()
{
	SECircuitCompartmentSubstanceQuantity::Clear();

	SAFE_DELETE(m_TissueConcentration);
	SAFE_DELETE(m_TissueMolarity);
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Reset()
{
	SECircuitCompartmentSubstanceQuantity::Reset();

	if (m_TissueConcentration != nullptr)
		m_TissueConcentration->Invalidate();
	if (m_TissueMolarity != nullptr)
		m_TissueMolarity->Invalidate();
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::FixUp() const
{
	m_nSubQs.clear();
	for (SECircuitNode* node : m_pnt.m_Nodes)
		m_nSubQs.push_back(node->GetSubstanceQuantity((SESubstance*)&m_Substance));
}

template <typename CompartmentEnumValue>
const SEScalar* SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name.compare("Mass") == 0)
		return &m_extravascular.GetMass();
	if (name.compare("TissueConcentration") == 0)
		return &GetTissueConcentration();
	if (name.compare("TissueMolarity") == 0)
		return &GetTissueMolarity();
	if (name.compare("ExtravascularConcentration") == 0)
		return &m_extravascular.GetConcentration();
	if (name.compare("ExtravascularMolarity") == 0)
		return &m_extravascular.GetMolarity();
	if (name.compare("ExtravascularPartialPressure") == 0)
		return &m_extravascular.GetPartialPressure();
	if (name.compare("ExtravascularSaturation") == 0)
		return &m_extravascular.GetSaturation();
	return nullptr;
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Balance(BalanceTissueBy by)
{
	switch (by)
	{// Note Tissue Concentration is always caluclated, so I don't bother balancing it here
		case BalanceTissueBy::Mass:
		{
			m_extravascular.Balance(BalanceLiquidBy::Mass);
			break;
		}
		case BalanceTissueBy::TissueConcentration:
		{
			// Calculate the new mass from the provided tissue concentration
			//(gutExtravascularVolume_mL + gutTissueVolume_mL) * tissueConcentration_ug_Per_mL
			double mass_ug = m_pnt.GetTissueVolume(SEScalarVolume::mL) * m_TissueConcentration->GetValue(SEScalarMassPerVolume::ug_Per_mL);
			m_extravascular.GetMass().SetValue(mass_ug, SEScalarMass::ug);
			m_extravascular.Balance(BalanceLiquidBy::Mass);
			break;
		}
		case BalanceTissueBy::ExtravascularConcentration:
		{
			m_extravascular.Balance(BalanceLiquidBy::Concentration);
			break;
		}
		case BalanceTissueBy::ExtravascularPartialPressure:
		{
			m_extravascular.Balance(BalanceLiquidBy::PartialPressure);
			break;
		}
	}
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Load(const CDM::TissueCompartmentSubstanceQuantityData& in)
{
	/*if (in.Mass().present())
		GetMass().Load(in.Mass().get());
	if (in.TissueConcentration().present())
		GetTissueConcentration().Load(in.TissueConcentration().get());


	if (in.ExtravascularConcentration().present())
		GetExtravascularConcentration().Load(in.ExtravascularConcentration().get());
	if (in.ExtravascularPartialPressure().present())
		GetExtravascularPartialPressure().Load(in.ExtravascularPartialPressure().get());
	if (in.ExtravascularSaturation().present())
		GetExtravascularSaturation().Load(in.ExtravascularSaturation().get());*/
	return true;
}
template <typename CompartmentEnumValue>
std::unique_ptr<CDM::TissueCompartmentSubstanceQuantityData> SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::TissueCompartmentSubstanceQuantityData> data(new CDM::TissueCompartmentSubstanceQuantityData());
	Unload(*data);
	return data;
}
template <typename CompartmentEnumValue>
void SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::Unload(CDM::TissueCompartmentSubstanceQuantityData& data) const
{
	/*if (HasMass())
		data.Mass(*(CDM::ScalarMassData*)(m_Mass->Unload().get()));

	if (HasTissueConcentration())
		data.TissueConcentration(*(CDM::ScalarMassPerVolumeData*)(m_TissueConcentration->Unload().get()));

	if (HasExtravascularConcentration())
		data.ExtravascularConcentration(*(CDM::ScalarMassPerVolumeData*)(m_ExtravascularConcentration->Unload().get()));
	if (HasExtravascularPartialPressure())
		data.ExtravascularPartialPressure(*(CDM::ScalarPressureData*)(m_ExtravascularPartialPressure->Unload().get()));
	if (HasExtravascularSaturation())
		data.ExtravascularSaturation(*(CDM::ScalarFractionData*)(m_ExtravascularSaturation->Unload().get()));*/
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasMass() const
{
	return m_extravascular.HasMass();
}
template <typename CompartmentEnumValue>
SEScalarMass& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetMass()
{
	return m_extravascular.GetMass();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetMass(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_extravascular.GetMass(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasTissueConcentration() const
{
	if (m_nSubQs.empty())
		FixUp(); 
	if (m_TissueConcentration != nullptr && m_TissueConcentration->IsValid())
		return true;
	if (m_pnt.HasTissueVolume() && HasMass())
		return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarMassPerVolume& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetTissueConcentration()
{
	if (m_nSubQs.empty())
		FixUp();
	if (m_TissueConcentration == nullptr)
		m_TissueConcentration = new SEScalarMassPerVolume();
	// Until we get rid of SECircuitNodeSubstanceQuantity* we have to calculate when called
	if (HasMass() && m_pnt.HasTissueVolume())// If we don't have mass, return what we have
		m_pnt.m_math.CalculateConcentration(GetMass(), m_pnt.GetTissueVolume(), *m_TissueConcentration);// we wouldn't need this line
	return *m_TissueConcentration;
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetTissueConcentration(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_nSubQs.empty())
		FixUp();
	if (HasMass() && m_pnt.HasTissueVolume())
	{
		if (m_TissueConcentration == nullptr)
			m_TissueConcentration = new SEScalarMassPerVolume();
		if (m_extravascular.m_Mass == nullptr)
			m_extravascular.m_Mass = new SEScalarMass();// inside a const method, you can only call other const methods
		m_extravascular.m_Mass->SetValue(GetMass(SEScalarMass::ug), SEScalarMass::ug);
		m_pnt.m_math.CalculateConcentration(*m_extravascular.m_Mass, m_pnt.GetTissueVolume(), *m_TissueConcentration);
		return m_TissueConcentration->GetValue(unit);
	}
	if (m_TissueConcentration != nullptr && m_TissueConcentration->IsValid())
		return m_TissueConcentration->GetValue(unit);
	return SEScalar::dNaN();
	// If no node subQ, then we hold the value, and we can use this
	//if (m_Concentration == nullptr)
	//	return SEScalar::dNaN();
	//return m_Concentration->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasTissueMolarity() const
{
	return HasTissueConcentration();
}
template <typename CompartmentEnumValue>
const SEScalarAmountPerVolume& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetTissueMolarity()
{
	if (m_TissueMolarity == nullptr)
		m_TissueMolarity = new SEScalarAmountPerVolume();
	m_TissueMolarity->SetValue(GetTissueConcentration(SEScalarMassPerVolume::ug_Per_L) / m_Substance.GetMolarMass(SEScalarMassPerAmount::ug_Per_mmol), SEScalarAmountPerVolume::mmol_Per_L);
	return *m_TissueMolarity;
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetTissueMolarity(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return Convert(GetTissueConcentration(SEScalarMassPerVolume::ug_Per_mL) / m_Substance.GetMolarMass(SEScalarMassPerAmount::ug_Per_mmol), SEScalarAmountPerVolume::mmol_Per_mL, unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasExtravascularConcentration() const
{
	return m_extravascular.HasConcentration();
}
template <typename CompartmentEnumValue>
SEScalarMassPerVolume& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularConcentration()
{
	return m_extravascular.GetConcentration();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularConcentration(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_extravascular.GetConcentration(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasExtravascularMolarity() const
{
	return m_extravascular.HasMolarity();
}
template <typename CompartmentEnumValue>
const SEScalarAmountPerVolume& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularMolarity()
{
	return m_extravascular.GetMolarity();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularMolarity(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_extravascular.GetMolarity(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasExtravascularPartialPressure() const
{
	return m_extravascular.HasPartialPressure();
}
template <typename CompartmentEnumValue>
SEScalarPressure& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularPartialPressure()
{
	return m_extravascular.GetPartialPressure();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularPartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_extravascular.GetPartialPressure(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::HasExtravascularSaturation() const
{
	return m_extravascular.HasSaturation();
}
template <typename CompartmentEnumValue>
SEScalarFraction& SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularSaturation()
{
	return m_extravascular.GetSaturation();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>::GetExtravascularSaturation(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_extravascular.GetSaturation(unit);
}
