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
CDM_BIND_DECL(AnesthesiaMachineCompartmentData)
CDM_BIND_DECL(AnesthesiaMachineCompartmentsData)
#include "bind/enumAnesthesiaMachine.hxx"
#include "../SEGasCompartment.h"

using SEAnesthesiaMachineCompartment = SEGasCompartment<CDM::enumAnesthesiaMachine::value>;

class DLL_DECL SEAnesthesiaMachineCompartments
{
public:
	virtual ~SEAnesthesiaMachineCompartments(){};

	virtual void Clear() = 0; //clear memory
	virtual void Reset() = 0; //reset values
	
	virtual bool Load(const CDM::AnesthesiaMachineCompartmentsData& in) = 0;
	virtual std::unique_ptr<CDM::AnesthesiaMachineCompartmentsData> Unload() const = 0;

	virtual bool                                  HasCompartment(CDM::enumAnesthesiaMachine::value type) = 0;
	virtual SEAnesthesiaMachineCompartment&       GetCompartment(CDM::enumAnesthesiaMachine::value type) = 0;
	virtual const SEAnesthesiaMachineCompartment* GetCompartment(CDM::enumAnesthesiaMachine::value type) const = 0;
	
protected:
	

	
};
