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
#include "compartment/inhaler/SEInhalerCompartments.h"
#include "circuit/compartment/SEGasCircuitCompartment.h"
class KelmanEquation;

using SEInhalerCircuitCompartment = SEGasCircuitCompartment<CDM::enumInhaler::value>;

class DLL_DECL SEInhalerCircuitCompartments : public virtual SEInhalerCompartments, public Loggable
{
public:

	SEInhalerCircuitCompartments(Logger* logger);
	virtual ~SEInhalerCircuitCompartments();

	virtual bool Load(const CDM::InhalerCompartmentsData& in);
	virtual std::unique_ptr<CDM::InhalerCompartmentsData> Unload() const;
protected:
	void Unload(CDM::InhalerCompartmentsData& data) const;
public:

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values
	virtual void FixUp(); // Connect all compartment to the circuit

	virtual void PullNext(bool b){ m_PullNext = b; }
	virtual void SetKelmanEquasion(const KelmanEquation& kelman, const SESubstance& oxygen);

	virtual bool                               HasCompartment(CDM::enumInhaler::value anatomy);
	virtual SEInhalerCompartment&              GetCompartment(CDM::enumInhaler::value anatomy);
	virtual const SEInhalerCompartment*        GetCompartment(CDM::enumInhaler::value anatomy) const;
	virtual SEInhalerCircuitCompartment&       GetCircuitCompartment(CDM::enumInhaler::value anatomy);
	virtual const SEInhalerCircuitCompartment* GetCircuitCompartment(CDM::enumInhaler::value anatomy) const;
	
protected:

	bool m_PullNext;
	std::stringstream m_ss;
	std::map<CDM::enumInhaler::value, SEInhalerCircuitCompartment*>     m_Compartments;
};