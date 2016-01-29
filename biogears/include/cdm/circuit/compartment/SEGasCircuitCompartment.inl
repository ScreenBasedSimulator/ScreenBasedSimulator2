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
#include "circuit/compartment/SEGasCircuitCompartment.h"
#include "bind/GasCompartmentData.hxx"
#include "circuit/compartment/SEGasCircuitCompartmentSubstanceQuantity.h"
#include "bind/GasCompartmentSubstanceQuantityData.hxx"
#include "substance/SESubstance.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerTime.h"
#include "properties/SEScalarFraction.h"
#include "properties/SEScalarMass.h"
#include "properties/SEScalarMassPerVolume.h"

template <typename CompartmentEnumValue>
SEGasCircuitCompartment<CompartmentEnumValue>::SEGasCircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext) : SEFluidCircuitCompartment<CompartmentEnumValue>(type, math.GetLogger(), getNext)
{
	
}

template <typename CompartmentEnumValue>
SEGasCircuitCompartment<CompartmentEnumValue>::~SEGasCircuitCompartment()
{
	Clear();
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::Clear()
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Clear();

	DELETE_VECTOR(m_SubstanceQuantities);
	m_cSubstanceQuantities.clear();
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::Reset()
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Reset();

	for (SEGasCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		subQ->Reset();
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::FixUp()
{
	SECircuitCompartment<CompartmentEnumValue>::FixUp();
	// Make sure we have cmpt subQ for each node subQ
	if (this->m_PrimaryNode != nullptr)
	{
		for (SECircuitNodeSubstanceQuantity* subQ : *this->m_PrimaryNode->GetSubstanceQuantities())
			dynamic_cast<SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>&>(this->GetSubstanceQuantity(*subQ->GetSubstance())).FixUp();
	}
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::AddChildCompartment(SEGasCircuitCompartment<CompartmentEnumValue>& cmpt)
{
	for (SECircuitNode* n : cmpt.m_allNodes)
		SECircuitCompartment<CompartmentEnumValue>::AddNode(*n);
	for (SECircuitPath* p : cmpt.GetPaths())
		SECircuitCompartment<CompartmentEnumValue>::AddPath(*p);
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::Balance(BalanceGasBy by)
{
	switch (by)
	{
		case BalanceGasBy::Volume:
		{
			if (this->m_Nodes.size() > 1)
			{
				// NOTE THIS ASSUMES THAT ALL COMPARTMENT SUBSTANCE QUANTITIES VOLUME (i.e. the actual scalar on the Compartment referenced below)
				// ARE UP TO DATE. IF YOU ONLY UPDATED 1 SUBSTANCE AND CALLED BALANCE, THE OTHER SUBSTANCE VOLUMES VERY WELL COULD BE OUT OF DATA
				// RESULTING IN A BAD PUSH TO THE CIRCUIT, SO I AM GOING TO DISABLE THIS UNTIL FURTHER NOTICE!
				///\todo Balancing a GasCompartment by Volume where compartment is mapped to multiple nodes is unimplimented
				this->Fatal("Balancing a GasCompartment by Volume where compartment is mapped to multiple nodes is unimplimented");

				// Distribute the new substance volumes by the old volume fraction to the nodes
				for (SEGasCompartmentSubstanceQuantity* cSubQ : m_SubstanceQuantities)
				{
					double subTotalVolume_mL = dynamic_cast<SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>*>(cSubQ)->m_Volume->GetValue(SEScalarVolume::mL);
					// Get the current total sub vol across all nodes
					double nTotalSubVol_mL = 0;
					for (SECircuitNode* n : this->m_Nodes)
					{
						nTotalSubVol_mL += n->GetSubstanceQuantity(((SESubstance*)&cSubQ->GetSubstance()))->GetNextVolume()->GetValue(SEScalarVolume::mL);
					}
					// Weight the provided volume across the nodes
					for (SECircuitNode* n : this->m_Nodes)
					{
						for (SECircuitNodeSubstanceQuantity* nSubQ : *n->GetSubstanceQuantities())
						{
							double nSubVol_mL = nSubQ->GetNextVolume()->GetValue(SEScalarVolume::mL);
							nSubQ->GetNextVolume()->SetValue(nSubVol_mL / nTotalSubVol_mL * subTotalVolume_mL);
						}
					}
				}
			}
			for (SECircuitNode* n : this->m_Nodes)
			{
				double totalNodeVolume_mL = 0;				
				// First set the total volume of the node based on the substance volumes
				for (SECircuitNodeSubstanceQuantity* nSubQ : *n->GetSubstanceQuantities())
				{
					if (nSubQ->HasNextVolume())
						totalNodeVolume_mL += nSubQ->GetNextVolume()->GetValue(SEScalarVolume::mL);
				}
				n->GetNextVolume()->SetValue(totalNodeVolume_mL, SEScalarVolume::mL);
				// Now calculate the volume fractions and partial pressures for each substance
				for (SECircuitNodeSubstanceQuantity* nSubQ : *n->GetSubstanceQuantities())
				{
					if (!nSubQ->HasNextVolume())
						continue;
					double subVol_mL = nSubQ->GetNextVolume()->GetValue(SEScalarVolume::mL);
					nSubQ->GetNextVolumeFraction()->SetValue(subVol_mL / totalNodeVolume_mL);
					this->m_math.CalculatePartialPressureInGas(*nSubQ->GetNextVolumeFraction(), *n->GetNextPressure(), *nSubQ->GetNextPartialPressure());
				}
			}
			break;
		}
		case BalanceGasBy::VolumeFraction:
		{
			// If you change all the substance volume FRACTIONS, 
			// I would have to assume the total volume keeps and compute new substance volumes 
			// (while ensuring the volume fractions all add up to 1).			
			this->Fatal("Balancing a GasCompartment by VolumeFraction is unimplimented");
		}
	}
}

template <typename CompartmentEnumValue>
const SEScalar* SEGasCircuitCompartment<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	return SEFluidCircuitCompartment<CompartmentEnumValue>::GetScalar(name);
}

template <typename CompartmentEnumValue>
bool SEGasCircuitCompartment<CompartmentEnumValue>::Load(const CDM::GasCompartmentData& in)
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Load(in);

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
std::unique_ptr<CDM::GasCompartmentData>  SEGasCircuitCompartment<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::GasCompartmentData> data(new CDM::GasCompartmentData());
	Unload(*data);
	return data;
}

template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::Unload(CDM::GasCompartmentData& data) const
{
	SEFluidCircuitCompartment<CompartmentEnumValue>::Unload(data);

	// TODO Unload the list of Substance Quantities
};

template <typename CompartmentEnumValue>
bool SEGasCircuitCompartment<CompartmentEnumValue>::HasSubstanceQuantities() const
{
	return m_SubstanceQuantities.size() > 0 ? true : false;
}
template <typename CompartmentEnumValue>
bool SEGasCircuitCompartment<CompartmentEnumValue>::HasSubstanceQuantity(const SESubstance& substance) const
{
	for (SEGasCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return true;
	return false;
}
template <typename CompartmentEnumValue>
SEGasCompartmentSubstanceQuantity& SEGasCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantity(const SESubstance& substance)
{
	for (SEGasCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return *subQ;
	SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>* sq = new SEGasCircuitCompartmentSubstanceQuantity<CompartmentEnumValue>(substance, *this);
	m_SubstanceQuantities.push_back(sq);
	m_cSubstanceQuantities.push_back(sq);
	return *sq;
}
template <typename CompartmentEnumValue>
const SEGasCompartmentSubstanceQuantity* SEGasCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantity(const SESubstance& substance) const
{
	for (SEGasCompartmentSubstanceQuantity* subQ : m_SubstanceQuantities)
		if (&subQ->GetSubstance() == &substance)
			return subQ;
	return nullptr;
}
template <typename CompartmentEnumValue>
const std::vector<SEGasCompartmentSubstanceQuantity*>* SEGasCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantities()
{
	return &m_SubstanceQuantities;
}
template <typename CompartmentEnumValue>
const std::vector<const SEGasCompartmentSubstanceQuantity*>* SEGasCircuitCompartment<CompartmentEnumValue>::GetSubstanceQuantities() const
{
	return &m_cSubstanceQuantities;
}
template <typename CompartmentEnumValue>
void SEGasCircuitCompartment<CompartmentEnumValue>::RemoveSubstanceQuantity(const SESubstance& substance)
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
