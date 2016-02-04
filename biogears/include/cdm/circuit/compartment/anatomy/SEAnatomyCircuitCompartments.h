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
#include "compartment/anatomy/SEAnatomyCompartments.h"
#include "circuit/compartment/SEGasCircuitCompartment.h"
#include "circuit/compartment/SELiquidCircuitCompartment.h"
#include "circuit/compartment/SEThermalCircuitCompartment.h"
#include "circuit/compartment/SETissueCircuitCompartment.h"
class SaturationCalculator;

using SEAnatomyCircuitCompartment        = SECircuitCompartment<CDM::enumAnatomy::value>;
using SEAnatomyGasCircuitCompartment     = SEGasCircuitCompartment<CDM::enumAnatomy::value>;
using SEAnatomyThermalCircuitCompartment = SEThermalCircuitCompartment<CDM::enumAnatomy::value>;
using SEAnatomyTissueCircuitCompartment  = SETissueCircuitCompartment<CDM::enumAnatomy::value>;
using SEAnatomyLiquidCircuitCompartment  = SELiquidCircuitCompartment<CDM::enumAnatomy::value>;

using SEAnatomyGasCircuitCompartmentSubstanceQuantity     = SEGasCircuitCompartmentSubstanceQuantity<CDM::enumAnatomy::value>;
using SEAnatomyTissueCircuitCompartmentSubstanceQuantity  = SETissueCircuitCompartmentSubstanceQuantity<CDM::enumAnatomy::value>;
using SEAnatomyLiquidCircuitCompartmentSubstanceQuantity  = SELiquidCircuitCompartmentSubstanceQuantity<CDM::enumAnatomy::value>;

class DLL_DECL SEAnatomyCircuitCompartments : public virtual SEAnatomyCompartments, public Loggable
{
public:

	SEAnatomyCircuitCompartments(SaturationCalculator& satCalc);
	virtual ~SEAnatomyCircuitCompartments();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values
	virtual void FixUp(); // Connect all compartment to the circuit

	virtual void PullNext(bool b){ m_PullNext = b; }

	virtual bool Load(const CDM::AnatomyCompartmentsData& in);
	virtual std::unique_ptr<CDM::AnatomyCompartmentsData> Unload() const;
protected:
	void Unload(CDM::AnatomyCompartmentsData& data) const;
public:

	virtual SEAnatomyCompartment&                     GetCompartment(CDM::enumAnatomy::value anatomy, CDM::enumCompartmentType type);
	virtual SEAnatomyCircuitCompartment&              GetCircuitCompartment(CDM::enumAnatomy::value anatomy, CDM::enumCompartmentType type);

	virtual bool                                      HasChymeCompartment(CDM::enumAnatomy::value anatomy);
	virtual SEAnatomyLiquidCompartment&               GetChymeCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyLiquidCompartment*         GetChymeCompartment(CDM::enumAnatomy::value anatomy) const;
	virtual SEAnatomyLiquidCircuitCompartment&        GetChymeCircuitCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyLiquidCircuitCompartment*  GetChymeCircuitCompartment(CDM::enumAnatomy::value anatomy) const;

	virtual bool                                      HasPulmonaryCompartment(CDM::enumAnatomy::value anatomy);
	virtual SEAnatomyGasCompartment&                  GetPulmonaryCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyGasCompartment*            GetPulmonaryCompartment(CDM::enumAnatomy::value anatomy) const;
	virtual SEAnatomyGasCircuitCompartment&           GetPulmonaryCircuitCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyGasCircuitCompartment*     GetPulmonaryCircuitCompartment(CDM::enumAnatomy::value anatomy) const;

	virtual bool                                      HasTemperatureCompartment(CDM::enumAnatomy::value anatomy);
	virtual SEAnatomyThermalCompartment&              GetTemperatureCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyThermalCompartment*        GetTemperatureCompartment(CDM::enumAnatomy::value anatomy) const;
	virtual SEAnatomyThermalCircuitCompartment&       GetTemperatureCircuitCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyThermalCircuitCompartment* GetTemperatureCircuitCompartment(CDM::enumAnatomy::value anatomy) const;

	virtual bool                                      HasTissueCompartment(CDM::enumAnatomy::value anatomy);
	virtual SEAnatomyTissueCompartment&               GetTissueCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyTissueCompartment*         GetTissueCompartment(CDM::enumAnatomy::value anatomy) const;
	virtual SEAnatomyTissueCircuitCompartment&        GetTissueCircuitCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyTissueCircuitCompartment*  GetTissueCircuitCompartment(CDM::enumAnatomy::value anatomy) const;

	virtual bool                                      HasUrineCompartment(CDM::enumAnatomy::value anatomy);
	virtual SEAnatomyLiquidCompartment&               GetUrineCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyLiquidCompartment*         GetUrineCompartment(CDM::enumAnatomy::value anatomy) const;
	virtual SEAnatomyLiquidCircuitCompartment&        GetUrineCircuitCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyLiquidCircuitCompartment*  GetUrineCircuitCompartment(CDM::enumAnatomy::value anatomy) const;

	virtual bool                                      HasVascularCompartment(CDM::enumAnatomy::value anatomy);
	virtual SEAnatomyLiquidCompartment&               GetVascularCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyLiquidCompartment*         GetVascularCompartment(CDM::enumAnatomy::value anatomy) const;
	virtual SEAnatomyLiquidCircuitCompartment&        GetVascularCircuitCompartment(CDM::enumAnatomy::value anatomy);
	virtual const SEAnatomyLiquidCircuitCompartment*  GetVascularCircuitCompartment(CDM::enumAnatomy::value anatomy) const;

	virtual void MapNodeToCompartment(SECircuitNode& node, CDM::enumAnatomy::value anatomy);
	virtual CDM::enumAnatomy::value GetNodeCompartment(SECircuitNode& node);

protected:

	bool m_PullNext;
	std::stringstream m_ss;
	SaturationCalculator& m_SaturationCalculator;
	std::map<SECircuitNode*, CDM::enumAnatomy::value> m_NodeToCompartment;

	std::map<CDM::enumAnatomy::value, SEAnatomyLiquidCircuitCompartment*>  m_ChymeCompartments;
	std::map<CDM::enumAnatomy::value, SEAnatomyGasCircuitCompartment*>     m_PulmonaryCompartments;
	std::map<CDM::enumAnatomy::value, SEAnatomyThermalCircuitCompartment*> m_TemperatureCompartments;
	std::map<CDM::enumAnatomy::value, SEAnatomyTissueCircuitCompartment*>  m_TissueCompartments;
	std::map<CDM::enumAnatomy::value, SEAnatomyLiquidCircuitCompartment*>  m_UrineCompartments;
	std::map<CDM::enumAnatomy::value, SEAnatomyLiquidCircuitCompartment*>  m_VascularCompartments;
};
