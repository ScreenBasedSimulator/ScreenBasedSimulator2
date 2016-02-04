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
#include "circuit/compartment/SETissueCircuitCompartment.h"
#include "bind/TissueCompartmentSubstanceQuantityData.hxx"
#include "bind/TissueCompartmentData.hxx"
#include "circuit/compartment/SETissueCircuitCompartmentSubstanceQuantity.h"
#include "bind/TissueCompartmentSubstanceQuantityData.hxx"
#include "properties/SEScalarPressure.h"
#include "bind/ScalarPressureData.hxx"
#include "properties/SEScalarVolume.h"
#include "bind/ScalarVolumeData.hxx"
#include "properties/SEScalarVolumePerTime.h"
#include "bind/ScalarVolumePerTimeData.hxx"
#include "properties/SEScalarFraction.h"
#include "bind/ScalarFractionData.hxx"

template <typename CompartmentEnumValue>
SETissueCircuitCompartment<CompartmentEnumValue>::SETissueCircuitCompartment(CompartmentEnumValue type, const SaturationCalculator& satCalc, const bool& getNext) : SECircuitCompartment<CompartmentEnumValue>(type, satCalc.GetLogger(), getNext),
																																				                    m_SaturationCalculator(satCalc),
																																						            m_Extravascular(this->m_Type, this->GetLogger(), this->m_GetNext)
{
	m_MetabolicFraction = nullptr;
	m_TissueVolume = nullptr;
}

template <typename CompartmentEnumValue>
SETissueCircuitCompartment<CompartmentEnumValue>::~SETissueCircuitCompartment()
{
	Clear();
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::Clear()
{
	SECircuitCompartment<CompartmentEnumValue>::Clear();

	SAFE_DELETE(m_MetabolicFraction);
	SAFE_DELETE(m_TissueVolume);
	m_Extravascular.Clear();

	DELETE_VECTOR(m_SubstanceQuantities);
	m_cSubstanceQuantities.clear();
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::Reset()
{
	SECircuitCompartment<CompartmentEnumValue>::Reset();

	if (m_MetabolicFraction != nullptr)
		m_MetabolicFraction->Invalidate();
	if (m_TissueVolume != nullptr)
		m_TissueVolume->Invalidate();
	m_Extravascular.Reset();

	for (SETissueCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		subQ->Reset();
}

template <typename CompartmentEnumValue>
const SEScalar* SETissueCircuitCompartment<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name.compare("MetabolicFraction") == 0)
		return &GetMetabolicFraction();
	if (name.compare("TissueVolume") == 0)
		return &GetTissueVolume();
	if (name.compare("ExtravascularInFlow") == 0)
		return &GetExtravascularInFlow();
	if (name.compare("ExtravascularOutFlow") == 0)
		return &GetExtravascularOutFlow();
	if (name.compare("ExtravascularPressure") == 0)
		return &GetExtravascularPressure();
	if (name.compare("ExtravascularVolume") == 0)
		return &GetExtravascularVolume();
	if (name.compare("ExtravascularUnstressedVolume") == 0)
		return &GetExtravascularUnstressedVolume();
	return nullptr;
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::Load(const CDM::TissueCompartmentData& in)
{
	if (in.MetabolicFraction().present())
		GetMetabolicFraction().Load(in.MetabolicFraction().get());
	if (in.TissueVolume().present())
		GetTissueVolume().Load(in.TissueVolume().get());
	if (in.ExtravascularInFlow().present())
		GetExtravascularInFlow().Load(in.ExtravascularInFlow().get());
	if (in.ExtravascularOutFlow().present())
		GetExtravascularOutFlow().Load(in.ExtravascularOutFlow().get());
	if (in.ExtravascularPressure().present())
		GetExtravascularPressure().Load(in.ExtravascularPressure().get());
	if (in.ExtravascularVolume().present())
		GetExtravascularVolume().Load(in.ExtravascularVolume().get());
	if (in.ExtravascularUnstressedVolume().present())
		GetExtravascularUnstressedVolume().Load(in.ExtravascularUnstressedVolume().get());

	//SESubstance* substance;
	//SECompartmentSubstanceQuantity* subQ;
	//for (size_t i = 0; i < in.SubstanceQuantity.size(); i++)
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
std::unique_ptr<CDM::TissueCompartmentData>  SETissueCircuitCompartment<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::TissueCompartmentData> data(new CDM::TissueCompartmentData());
	Unload(*data);
	return data;
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::Unload(CDM::TissueCompartmentData& data) const
{
	if (m_MetabolicFraction != nullptr)
		data.MetabolicFraction(*(CDM::ScalarFractionData*)(m_MetabolicFraction->Unload().get()));
	if (m_TissueVolume != nullptr)
		data.TissueVolume(*(CDM::ScalarVolumeData*)(m_TissueVolume->Unload().get()));
	if (m_Extravascular.HasInFlow())
		data.ExtravascularInFlow(*(CDM::ScalarVolumePerTimeData*)(m_Extravascular.m_InFlow->Unload().get()));
	if (m_Extravascular.HasOutFlow())
		data.ExtravascularOutFlow(*(CDM::ScalarVolumePerTimeData*)(m_Extravascular.m_OutFlow->Unload().get()));
	if (m_Extravascular.HasPressure())
		data.ExtravascularPressure(*(CDM::ScalarPressureData*)(m_Extravascular.m_Pressure->Unload().get()));
	if (m_Extravascular.HasVolume())
		data.ExtravascularVolume(*(CDM::ScalarVolumeData*)(m_Extravascular.m_Volume->Unload().get()));
	if (m_Extravascular.HasUnstressedVolume())
		data.ExtravascularUnstressedVolume(*(CDM::ScalarVolumeData*)(m_Extravascular.m_UnstressedVolume->Unload().get()));

	// TODO Unload the list of Substance Quantities
};

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::AddNode(SECircuitNode& node)
{
	SECircuitCompartment<CompartmentEnumValue>::AddNode(node);
	m_Extravascular.AddNode(node);
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::AddPath(SECircuitPath& path)
{
	SECircuitCompartment<CompartmentEnumValue>::AddPath(path);
	m_Extravascular.AddPath(path);
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::SetPrimaryNode(SECircuitNode& node)
{
	SECircuitCompartment<CompartmentEnumValue>::SetPrimaryNode(node);
	m_Extravascular.SetPrimaryNode(node);
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::FixUp()
{
	SECircuitCompartment<CompartmentEnumValue>::FixUp();
	if (this->m_PrimaryNode != nullptr)
	{
		for (SECircuitNodeSubstanceQuantity* subQ : *this->m_PrimaryNode->GetSubstanceQuantities())
			dynamic_cast<SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>&>(this->GetSubstanceQuantity(*subQ->GetSubstance())).FixUp();
	}
	m_Extravascular.FixUp();
}

template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::AddChildCompartment(SETissueCircuitCompartment<CompartmentEnumValue>& cmpt)
{
	for (SECircuitNode* n : cmpt.m_allNodes)
		SECircuitCompartment<CompartmentEnumValue>::AddNode(*n);
	for (SECircuitPath* p : cmpt.GetPaths())
		SECircuitCompartment<CompartmentEnumValue>::AddPath(*p);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasMetabolicFraction() const
{
	return m_MetabolicFraction == nullptr ? false : m_MetabolicFraction->IsValid();
}
template <typename CompartmentEnumValue>
SEScalarFraction& SETissueCircuitCompartment<CompartmentEnumValue>::GetMetabolicFraction()
{
	if (m_MetabolicFraction == nullptr)
		m_MetabolicFraction = new SEScalarFraction();
	return *m_MetabolicFraction;
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetMetabolicFraction(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (m_MetabolicFraction == nullptr)
		return SEScalar::dNaN();
	return m_MetabolicFraction->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasTissueVolume() const
{
	return this->m_Nodes.size() != 0;
}
template <typename CompartmentEnumValue>
SEScalarVolume& SETissueCircuitCompartment<CompartmentEnumValue>::GetTissueVolume()
{
	if (this->m_Nodes.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << " does not have any tissue volume data";
		this->Fatal(this->m_ss);
	}
	// The tissue volume on the node is only the volume of the structure.
	// We need to add the extravasular/fluid volume to this tissue volume
	//**NOTE THERE IS NOT A WAY TO PUSH ANY VOLUME CHANGES BACK TO THE CIRCUIT!!**
	// Sum the nodes with volume
	if (m_TissueVolume == nullptr)
		m_TissueVolume = new SEScalarVolume();
	m_TissueVolume->Invalidate();
	for (SECircuitNode* n : this->m_Nodes)
	{
		m_TissueVolume->Increment(n->GetTissueVolume());
		m_TissueVolume->Increment(this->m_GetNext ? n->GetNextVolume() : n->GetVolume());
	}
	return *m_TissueVolume;
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetTissueVolume(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Nodes.empty())
		return SEScalar::dNaN();
	double d = 0;
	for (SECircuitNode* n : this->m_Nodes)
	{
		d += n->GetTissueVolume()->GetValue(unit);
		d += this->m_GetNext ? n->GetNextVolume()->GetValue(unit) : n->GetVolume()->GetValue(unit);
	}
	return d;
}


template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasExtravascularInFlow() const
{
	return m_Extravascular.HasInFlow();
}
template <typename CompartmentEnumValue>
SEScalarVolumePerTime& SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularInFlow()
{
	return m_Extravascular.GetInFlow();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularInFlow(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_Extravascular.GetInFlow(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasExtravascularOutFlow() const
{
	return m_Extravascular.HasOutFlow();
}
template <typename CompartmentEnumValue>
SEScalarVolumePerTime& SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularOutFlow()
{
	return m_Extravascular.GetOutFlow();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularOutFlow(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_Extravascular.GetOutFlow(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasExtravascularPressure() const
{
	return m_Extravascular.HasPressure();
}
template <typename CompartmentEnumValue>
SEScalarPressure& SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularPressure()
{
	return m_Extravascular.GetPressure();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularPressure(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_Extravascular.GetPressure(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasExtravascularVolume() const
{
	return m_Extravascular.HasVolume();
}
template <typename CompartmentEnumValue>
SEScalarVolume& SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularVolume()
{
	return m_Extravascular.GetVolume();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularVolume(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_Extravascular.GetVolume(unit);
}

template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasExtravascularUnstressedVolume() const
{
	return m_Extravascular.HasUnstressedVolume();
}
template <typename CompartmentEnumValue>
SEScalarVolume& SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularUnstressedVolume()
{
	return m_Extravascular.GetUnstressedVolume();
}
template <typename CompartmentEnumValue>
double SETissueCircuitCompartment<CompartmentEnumValue>::GetExtravascularUnstressedVolume(const std::shared_ptr<CCompoundUnit>& unit) const
{
	return m_Extravascular.GetUnstressedVolume(unit);
}


template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasSubstanceQuantities() const
{
	return m_SubstanceQuantities.size() > 0 ? true : false;
}
template <typename CompartmentEnumValue>
bool SETissueCircuitCompartment<CompartmentEnumValue>::HasSubstanceQuantity(const SESubstance& substance) const
{
	for (SETissueCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return true;
	return false;
}
template <typename CompartmentEnumValue>
SETissueCompartmentSubstanceQuantity& SETissueCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantity(const SESubstance& substance)
{
	for (SETissueCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return *subQ;
	SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>* sq = new SETissueCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>(substance, *this, m_SaturationCalculator);
	m_SubstanceQuantities.push_back(sq);
	m_cSubstanceQuantities.push_back(sq);
	return *sq;
}
template <typename CompartmentEnumValue>
const SETissueCompartmentSubstanceQuantity* SETissueCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantity(const SESubstance& substance) const
{
	for (SETissueCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return subQ;
	return nullptr;
}
template <typename CompartmentEnumValue>
const std::vector<SETissueCompartmentSubstanceQuantity*>* SETissueCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantities()
{
	return &m_SubstanceQuantities;
}
template <typename CompartmentEnumValue>
const std::vector<const SETissueCompartmentSubstanceQuantity*>* SETissueCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantities() const
{
	return &m_cSubstanceQuantities;
}
template <typename CompartmentEnumValue>
void SETissueCircuitCompartment<CompartmentEnumValue>::RemoveSubstanceQuantity(const SESubstance& substance)
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
