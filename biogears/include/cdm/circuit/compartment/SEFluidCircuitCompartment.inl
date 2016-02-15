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
#include "circuit/compartment/SEFluidCircuitCompartment.h"
#include "bind/FluidCompartmentData.hxx"
#include "substance/SESubstance.h"
#include "properties/SEScalarPressure.h"
#include "bind/ScalarPressureData.hxx"
#include "properties/SEScalarVolume.h"
#include "bind/ScalarVolumeData.hxx"
#include "properties/SEScalarVolumePerTime.h"
#include "bind/ScalarVolumePerTimeData.hxx"

template <typename CompartmentEnumValue>
SEFluidCircuitCompartment<CompartmentEnumValue>::SEFluidCircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext) : SECircuitCompartment<CompartmentEnumValue>(type, math.GetLogger(), getNext)
{
	m_InFlow = nullptr;
	m_OutFlow = nullptr;
	m_Pressure = nullptr;
	m_Volume = nullptr;
	m_UnstressedVolume = nullptr;
}

template <typename CompartmentEnumValue>
SEFluidCircuitCompartment<CompartmentEnumValue>::~SEFluidCircuitCompartment()
{
	Clear();
}

template <typename CompartmentEnumValue>
void SEFluidCircuitCompartment<CompartmentEnumValue>::Clear()
{
	SECircuitCompartment<CompartmentEnumValue>::Clear();
	SAFE_DELETE(m_InFlow);
	SAFE_DELETE(m_OutFlow);
	SAFE_DELETE(m_Pressure);
	SAFE_DELETE(m_Volume);
	SAFE_DELETE(m_UnstressedVolume);
}

template <typename CompartmentEnumValue>
void SEFluidCircuitCompartment<CompartmentEnumValue>::Reset()
{
	SECircuitCompartment<CompartmentEnumValue>::Reset();
	if (m_InFlow != nullptr)
		m_InFlow->Invalidate();
	if (m_OutFlow != nullptr)
		m_OutFlow->Invalidate();
	if (m_Pressure != nullptr)
		m_Pressure->Invalidate();
	if (m_Volume != nullptr)
		m_Volume->Invalidate();
	if (m_UnstressedVolume != nullptr)
		m_UnstressedVolume->Invalidate();
}

template <typename CompartmentEnumValue>
const SEScalar* SEFluidCircuitCompartment<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name.compare("InFlow") == 0)
		return &GetInFlow();
	if (name.compare("OutFlow") == 0)
		return &GetOutFlow();
	if (name.compare("Pressure") == 0)
		return &GetPressure();
	if (name.compare("Volume") == 0)
		return &GetVolume();
	if (name.compare("UnstressedVolume") == 0)
		return &GetUnstressedVolume();
	return nullptr;
}

template <typename CompartmentEnumValue>
bool SEFluidCircuitCompartment<CompartmentEnumValue>::Load(const CDM::FluidCompartmentData& in)
{
	if (in.InFlow().present())
		GetInFlow().Load(in.InFlow().get());
	if (in.OutFlow().present())
		GetOutFlow().Load(in.OutFlow().get());
	if (in.Pressure().present())
		GetPressure().Load(in.Pressure().get());
	if (in.Volume().present())
		GetVolume().Load(in.Volume().get());
	if (in.UnstressedVolume().present())
		GetUnstressedVolume().Load(in.UnstressedVolume().get());

	return true;
}

template <typename CompartmentEnumValue>
std::unique_ptr<CDM::FluidCompartmentData>  SEFluidCircuitCompartment<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::FluidCompartmentData> data(new CDM::FluidCompartmentData());
	Unload(*data);
	return data;
}

template <typename CompartmentEnumValue>
void SEFluidCircuitCompartment<CompartmentEnumValue>::Unload(CDM::FluidCompartmentData& data) const
{
	if (m_InFlow != nullptr)
		data.InFlow(*(CDM::ScalarVolumePerTimeData*)(m_InFlow->Unload().get()));
	if (m_OutFlow != nullptr)
		data.OutFlow(*(CDM::ScalarVolumePerTimeData*)(m_OutFlow->Unload().get()));
	if (m_Pressure != nullptr)
		data.Pressure(*(CDM::ScalarPressureData*)(m_Pressure->Unload().get()));
	if (m_Volume != nullptr)
		data.Volume(*(CDM::ScalarVolumeData*)(m_Volume->Unload().get()));
	if (m_UnstressedVolume != nullptr)
		data.UnstressedVolume(*(CDM::ScalarVolumeData*)(m_UnstressedVolume->Unload().get()));
};

template <typename CompartmentEnumValue>
bool SEFluidCircuitCompartment<CompartmentEnumValue>::HasPressure() const
{
	if (this->m_PrimaryNode == nullptr)
		return false;
	return this->m_PrimaryNode->HasNextPressure();
}
template <typename CompartmentEnumValue>
SEScalarPressure& SEFluidCircuitCompartment<CompartmentEnumValue>::GetPressure()
{
	if (this->m_PrimaryNode == nullptr)
	{
		this->m_ss << this->m_Type<<" Primary node not set, cannot retrieve compartment pressure";
		this->Fatal(this->m_ss);
	}
	return this->m_GetNext ? *this->m_PrimaryNode->GetNextPressure() : *this->m_PrimaryNode->GetPressure();
}
template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::GetPressure(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_PrimaryNode == nullptr)
		this->Fatal("Primary node not set, cannot retrieve compartment pressure");
	return this->m_GetNext ? this->m_PrimaryNode->GetNextPressure()->GetValue(unit) : this->m_PrimaryNode->GetPressure()->GetValue(unit);
}

template <typename CompartmentEnumValue>
bool SEFluidCircuitCompartment<CompartmentEnumValue>::HasInFlow() const
{
	return this->m_Paths.m_AllPaths.size() != 0;
}
template <typename CompartmentEnumValue>
SEScalarVolumePerTime& SEFluidCircuitCompartment<CompartmentEnumValue>::GetInFlow()
{
	if (this->m_Paths.m_AllPaths.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << " does not have any in flow data";
		this->Fatal(this->m_ss);
	}
	if (m_InFlow == nullptr)
		m_InFlow = new SEScalarVolumePerTime();
	m_InFlow->SetValue(CalculateInFlow_mL_Per_s(), SEScalarVolumePerTime::mL_Per_s);
	return *m_InFlow;
}
template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::GetInFlow(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Paths.m_AllPaths.empty())
		return SEScalar::dNaN();
	return Convert(CalculateInFlow_mL_Per_s(), SEScalarVolumePerTime::mL_Per_s, unit);
}

template <typename CompartmentEnumValue>
bool SEFluidCircuitCompartment<CompartmentEnumValue>::HasOutFlow() const
{
	return this->m_Paths.m_AllPaths.size() != 0;
}
template <typename CompartmentEnumValue>
SEScalarVolumePerTime& SEFluidCircuitCompartment<CompartmentEnumValue>::GetOutFlow()
{
	if (this->m_Paths.m_AllPaths.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << "does not have any out flow data";
		this->Fatal(this->m_ss);
	}
	if (m_OutFlow == nullptr)
		m_OutFlow = new SEScalarVolumePerTime();
	m_OutFlow->SetValue(CalculateOutFlow_mL_Per_s(), SEScalarVolumePerTime::mL_Per_s);
	return *m_OutFlow;
}
template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::GetOutFlow(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Paths.m_AllPaths.empty())
		return SEScalar::dNaN();	
	return Convert(CalculateOutFlow_mL_Per_s(), SEScalarVolumePerTime::mL_Per_s, unit);
}

template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::CalculateInFlow_mL_Per_s() const
{
	double flow_mL_Per_s = 0;

	SEScalarVolumePerTime* f;
	for (SECircuitPath* p : this->m_Paths.m_IncomingPaths)
	{// Positive flow on an incoming path, is flow into the compartment
		f = this->m_GetNext ? p->GetNextFlow() : p->GetFlow();
		if (f->IsPositive() || f->IsZero())
			flow_mL_Per_s += f->GetValue(SEScalarVolumePerTime::mL_Per_s);
	}
	for (SECircuitPath* p : this->m_Paths.m_OutgoingPaths)
	{// Negative flow on an outgoing path, is flow into the compartment
		f = this->m_GetNext ? p->GetNextFlow() : p->GetFlow();
		if (f->IsNegative() || f->IsZero())
			flow_mL_Per_s += -f->GetValue(SEScalarVolumePerTime::mL_Per_s);
	}

	if (flow_mL_Per_s < 0)
		flow_mL_Per_s = 0;// This number is something like x.e-12, which we treat as 0
	
	return flow_mL_Per_s;
}

template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::CalculateOutFlow_mL_Per_s() const
{
	double flow_mL_Per_s = 0;

	SEScalarVolumePerTime* f;
	for (SECircuitPath* p : this->m_Paths.m_IncomingPaths)
	{// Negative flow on an incoming path, is flow out of the compartment
		f = this->m_GetNext ? p->GetNextFlow() : p->GetFlow();
		if (f->IsNegative() || f->IsZero())
			flow_mL_Per_s += -f->GetValue(SEScalarVolumePerTime::mL_Per_s);
	}
	for (SECircuitPath* p : this->m_Paths.m_OutgoingPaths)
	{// Positive flow on an outgoing path, is flow out of the compartment
		f = this->m_GetNext ? p->GetNextFlow() : p->GetFlow();
		if (f->IsPositive() || f->IsZero())
			flow_mL_Per_s += f->GetValue(SEScalarVolumePerTime::mL_Per_s);
	}

	if (flow_mL_Per_s < 0)
		flow_mL_Per_s = 0;// This number is something like x.e-12, which we treat as 0

	return flow_mL_Per_s;
}

template <typename CompartmentEnumValue>
bool SEFluidCircuitCompartment<CompartmentEnumValue>::HasVolume() const
{
	return !this->m_Nodes.empty();
}
template <typename CompartmentEnumValue>
SEScalarVolume& SEFluidCircuitCompartment<CompartmentEnumValue>::GetVolume()
{
	if (this->m_Nodes.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << " does not have any volume data";
		this->Fatal(this->m_ss);
	}
	if (this->m_Nodes.size() == 1)
		return this->m_GetNext ? *this->m_Nodes[0]->GetNextVolume() : *this->m_Nodes[0]->GetVolume();
	// Sum the nodes with volume
	/**NOTE THERE IS NOT A WAY TO PUSH ANY VOLUME CHANGES OF COMPARTMENTS WITH MULTIPLE NODES, BACK TO THE CIRCUIT!!**/
	if(m_Volume==nullptr)
		m_Volume=new SEScalarVolume();
	m_Volume->Invalidate();
	for (SECircuitNode* n : this->m_Nodes)
		m_Volume->Increment(this->m_GetNext ? n->GetNextVolume() : n->GetVolume());
	return *m_Volume;
}
template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::GetVolume(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Nodes.empty())
		return SEScalar::dNaN();
	double d = 0;
	for (SECircuitNode* n : this->m_Nodes)
	{
		if (this->m_GetNext)
		{
			if (!n->HasNextVolume())
				d = SEScalar::dNaN();
			else
				d += n->GetNextVolume()->GetValue(unit);
		}
		else
		{
			if (!n->HasVolume())
				d = SEScalar::dNaN();
			else
				d += n->GetVolume()->GetValue(unit);
		}
	}
	return d;
}

template <typename CompartmentEnumValue>
bool SEFluidCircuitCompartment<CompartmentEnumValue>::HasUnstressedVolume() const
{
	if (this->m_Nodes.empty())
		return false;
	for (SECircuitNode* n : this->m_Nodes)
		if (n->HasUnstressedVolume())
			return true;
	return false;
}
template <typename CompartmentEnumValue>
SEScalarVolume& SEFluidCircuitCompartment<CompartmentEnumValue>::GetUnstressedVolume()
{
	if (this->m_Nodes.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << "does not have any unstressed volume data";
		this->Fatal(this->m_ss);
	}
	if (this->m_Nodes.size() == 1)
		return *this->m_Nodes[0]->GetUnstressedVolume();
	// Sum the nodes with volume
	if (m_UnstressedVolume == nullptr)
		m_UnstressedVolume = new SEScalarVolume();
	m_UnstressedVolume->Invalidate();
	for (SECircuitNode* n : this->m_Nodes)
		m_UnstressedVolume->Increment(n->GetUnstressedVolume());
	return *m_UnstressedVolume;
}
template <typename CompartmentEnumValue>
double SEFluidCircuitCompartment<CompartmentEnumValue>::GetUnstressedVolume(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Nodes.empty())
		return SEScalar::dNaN();
	double d = 0;
	for (SECircuitNode* n : this->m_Nodes)
	{
		if (!n->HasUnstressedVolume())
			d = SEScalar::dNaN();
		else
			d += n->GetUnstressedVolume()->GetValue(unit);
	}
	return d;
}
