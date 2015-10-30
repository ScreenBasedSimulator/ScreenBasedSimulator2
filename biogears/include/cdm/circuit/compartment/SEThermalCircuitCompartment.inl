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
#include "circuit/compartment/SEThermalCircuitCompartment.h"
#include "bind/ThermalCompartmentData.hxx"
#include "properties/SEScalarEnergy.h"
#include "bind/ScalarEnergyData.hxx"
#include "properties/SEScalarPower.h"
#include "bind/ScalarPowerData.hxx"
#include "properties/SEScalarTemperature.h"
#include "bind/ScalarTemperatureData.hxx"

template <typename CompartmentEnumValue>
SEThermalCircuitCompartment<CompartmentEnumValue>::SEThermalCircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext) : SECircuitCompartment<CompartmentEnumValue>(type, math, getNext)
{
	m_Heat = nullptr;
	m_HeatTransferRateIn = nullptr;
	m_HeatTransferRateOut = nullptr;
	m_Temperature = nullptr;
}

template <typename CompartmentEnumValue>
SEThermalCircuitCompartment<CompartmentEnumValue>::~SEThermalCircuitCompartment()
{
	Clear();
}

template <typename CompartmentEnumValue>
void SEThermalCircuitCompartment<CompartmentEnumValue>::Clear()
{
	SECircuitCompartment<CompartmentEnumValue>::Clear();
	SAFE_DELETE(m_Heat);
	SAFE_DELETE(m_HeatTransferRateIn);
	SAFE_DELETE(m_HeatTransferRateOut);
	SAFE_DELETE(m_Temperature);
}

template <typename CompartmentEnumValue>
void SEThermalCircuitCompartment<CompartmentEnumValue>::Reset()
{
	SECircuitCompartment<CompartmentEnumValue>::Reset();
	if (m_Heat != nullptr)
		m_Heat->Invalidate();
	if (m_HeatTransferRateIn != nullptr)
		m_HeatTransferRateIn->Invalidate();
	if (m_HeatTransferRateOut != nullptr)
		m_HeatTransferRateOut->Invalidate();
	if (m_Temperature != nullptr)
		m_Temperature->Invalidate();
}

template <typename CompartmentEnumValue>
const SEScalar* SEThermalCircuitCompartment<CompartmentEnumValue>::GetScalar(const std::string& name)
{
	if (name.compare("Heat") == 0)
		return &GetHeat();
	if (name.compare("HeatTransferRateIn") == 0)
		return &GetHeatTransferRateIn();
	if (name.compare("HeatTransferRateOut") == 0)
		return &GetHeatTransferRateOut();
	if (name.compare("Temperature") == 0)
		return &GetTemperature();
	return nullptr;
}

template <typename CompartmentEnumValue>
bool SEThermalCircuitCompartment<CompartmentEnumValue>::Load(const CDM::ThermalCompartmentData& in)
{
	if (in.Heat().present())
		GetHeat().Load(in.Heat().get());
	if (in.HeatTransferRateIn().present())
		GetHeatTransferRateIn().Load(in.HeatTransferRateIn().get());
	if (in.HeatTransferRateOut().present())
		GetHeatTransferRateOut().Load(in.HeatTransferRateOut().get());
	if (in.Temperature().present())
		GetTemperature().Load(in.Temperature().get());
	return true;
}
template <typename CompartmentEnumValue>
std::unique_ptr<CDM::ThermalCompartmentData>  SEThermalCircuitCompartment<CompartmentEnumValue>::Unload() const
{
	std::unique_ptr<CDM::ThermalCompartmentData> data(new CDM::ThermalCompartmentData());
	Unload(*data);
	return data;
}
template <typename CompartmentEnumValue>
void SEThermalCircuitCompartment<CompartmentEnumValue>::Unload(CDM::ThermalCompartmentData& data) const
{
	if (m_Heat != nullptr)
		data.Heat(*(CDM::ScalarEnergyData*)(m_Heat->Unload().get()));
	if (m_HeatTransferRateIn != nullptr)
		data.HeatTransferRateIn(*(CDM::ScalarPowerData*)(m_HeatTransferRateIn->Unload().get()));
	if (m_HeatTransferRateOut != nullptr)
		data.HeatTransferRateOut(*(CDM::ScalarPowerData*)(m_HeatTransferRateOut->Unload().get()));
	if (m_Temperature != nullptr)
		data.Temperature(*(CDM::ScalarTemperatureData*)(m_Temperature->Unload().get()));
};

template <typename CompartmentEnumValue>
void SEThermalCircuitCompartment<CompartmentEnumValue>::FixUp()
{
	SECircuitCompartment<CompartmentEnumValue>::FixUp();
}

template <typename CompartmentEnumValue>
bool SEThermalCircuitCompartment<CompartmentEnumValue>::HasHeat() const
{
	return this->m_Nodes.size() != 0;
}
template <typename CompartmentEnumValue>
SEScalarEnergy& SEThermalCircuitCompartment<CompartmentEnumValue>::GetHeat()
{
	if (this->m_Nodes.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << " does not have any heat data";
		this->Fatal(this->m_ss);
	}
	if (this->m_Nodes.size() == 1)
		return this->m_GetNext ? *this->m_Nodes[0]->GetNextHeat() : *this->m_Nodes[0]->GetHeat();
	// Sum the nodes with Heat
	if (m_Heat == nullptr)
		m_Heat = new SEScalarEnergy();
	m_Heat->Invalidate();
	for (SECircuitNode* n : this->m_Nodes)
		m_Heat->Increment(this->m_GetNext ? n->GetNextHeat() : n->GetHeat());
	return *m_Heat;
}
template <typename CompartmentEnumValue>
double SEThermalCircuitCompartment<CompartmentEnumValue>::GetHeat(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Nodes.empty())
		return SEScalar::dNaN();
	double d = 0;
	for (SECircuitNode* n : this->m_Nodes)
		d += this->m_GetNext ? n->GetNextHeat()->GetValue(unit) : n->GetHeat()->GetValue(unit);
	return d;
}

template <typename CompartmentEnumValue>
bool SEThermalCircuitCompartment<CompartmentEnumValue>::HasHeatTransferRateIn() const
{
	return this->m_Paths.m_AllPaths.size() != 0;
}
template <typename CompartmentEnumValue>
SEScalarPower& SEThermalCircuitCompartment<CompartmentEnumValue>::GetHeatTransferRateIn()
{
	if (this->m_Paths.m_AllPaths.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << " does not have any heat transfer rate data";
		this->Fatal(this->m_ss);
	}
	if (m_HeatTransferRateIn == nullptr)
		m_HeatTransferRateIn = new SEScalarPower();
	m_HeatTransferRateIn->SetValue(CalculateInFlow_W(), SEScalarPower::W);
	return *m_HeatTransferRateIn;
}
template <typename CompartmentEnumValue>
double SEThermalCircuitCompartment<CompartmentEnumValue>::GetHeatTransferRateIn(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Paths.m_AllPaths.empty())
		return SEScalar::dNaN();
	return Convert(CalculateInFlow_W(), SEScalarPower::W, unit);
}

template <typename CompartmentEnumValue>
bool SEThermalCircuitCompartment<CompartmentEnumValue>::HasHeatTransferRateOut() const
{
	return this->m_Paths.m_AllPaths.size() != 0;
}
template <typename CompartmentEnumValue>
SEScalarPower& SEThermalCircuitCompartment<CompartmentEnumValue>::GetHeatTransferRateOut()
{
	if (this->m_Paths.m_AllPaths.empty())
	{
		this->m_ss << "Compartment " << this->m_Type << " does not have any heat transfer rate out data";
		this->Fatal(this->m_ss);
	}
	if (m_HeatTransferRateOut == nullptr)
		m_HeatTransferRateOut = new SEScalarPower();
	m_HeatTransferRateOut->SetValue(CalculateOutFlow_W(),SEScalarPower::W);
	return *m_HeatTransferRateOut;
}
template <typename CompartmentEnumValue>
double SEThermalCircuitCompartment<CompartmentEnumValue>::GetHeatTransferRateOut(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_Paths.m_AllPaths.empty())
		return SEScalar::dNaN();
	return Convert(CalculateOutFlow_W(), SEScalarPower::W, unit);
}

template <typename CompartmentEnumValue>
double SEThermalCircuitCompartment<CompartmentEnumValue>::CalculateInFlow_W() const
{
	double flow_W = 0;

	SEScalarPower* f;
	for (SECircuitPath* p : this->m_Paths.m_IncomingPaths)
	{// Positive flow on an incoming path, is flow into the compartment
		f = this->m_GetNext ? p->GetNextHeatTransferRate() : p->GetHeatTransferRate();
		if (f->IsPositive() || f->IsZero())
			flow_W += f->GetValue(SEScalarPower::W);
	}
	for (SECircuitPath* p : this->m_Paths.m_OutgoingPaths)
	{// Negative flow on an outgoing path, is flow into the compartment
		f = this->m_GetNext ? p->GetNextHeatTransferRate() : p->GetHeatTransferRate();
		if (f->IsNegative() || f->IsZero())
			flow_W  += - f->GetValue(SEScalarPower::W);
	}

	return flow_W;
}

template <typename CompartmentEnumValue>
double SEThermalCircuitCompartment<CompartmentEnumValue>::CalculateOutFlow_W() const
{
	double flow_W = 0;

	SEScalarPower* f;
	for (SECircuitPath* p : this->m_Paths.m_IncomingPaths)
	{// Negative flow on an incoming path, is flow out of the compartment
		f = this->m_GetNext ? p->GetNextHeatTransferRate() : p->GetHeatTransferRate();
		if (f->IsNegative() || f->IsZero())
			flow_W += -f->GetValue(SEScalarPower::W);
	}
	for (SECircuitPath* p : this->m_Paths.m_OutgoingPaths)
	{// Positive flow on an outgoing path, is flow out of the compartment
		f = this->m_GetNext ? p->GetNextHeatTransferRate() : p->GetHeatTransferRate();
		if (f->IsPositive() || f->IsZero())
			flow_W += f->GetValue(SEScalarPower::W);
	}

	return flow_W;
}

template <typename CompartmentEnumValue>
bool SEThermalCircuitCompartment<CompartmentEnumValue>::HasTemperature() const
{
	if (this->m_PrimaryNode == nullptr)
		return false;
	return this->m_PrimaryNode->HasNextTemperature();
}
template <typename CompartmentEnumValue>
SEScalarTemperature& SEThermalCircuitCompartment<CompartmentEnumValue>::GetTemperature()
{
	if (this->m_PrimaryNode == nullptr)
		this->Fatal("Primary node not set, cannot retrieve compartment temperature");
	return this->m_GetNext ? *this->m_PrimaryNode->GetNextTemperature() : *this->m_PrimaryNode->GetTemperature();
}
template <typename CompartmentEnumValue>
double SEThermalCircuitCompartment<CompartmentEnumValue>::GetTemperature(const std::shared_ptr<CCompoundUnit>& unit) const
{
	if (this->m_PrimaryNode == nullptr)
		this->Fatal("Primary node not set, cannot retrieve compartment temperature");
	return this->m_GetNext ? this->m_PrimaryNode->GetNextTemperature()->GetValue(unit) : this->m_PrimaryNode->GetTemperature()->GetValue(unit);
}
