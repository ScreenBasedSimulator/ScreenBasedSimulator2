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
CDM_BIND_DECL(InhalerCompartmentData)
CDM_BIND_DECL(InhalerCompartmentsData)
#include "bind/enumInhaler.hxx"
#include "../SEGasCompartment.h"

using SEInhalerCompartment = SEGasCompartment<CDM::enumInhaler::value>;

class DLL_DECL SEInhalerCompartments
{
public:
	virtual ~SEInhalerCompartments(){};

	virtual void Clear() = 0; //clear memory
	virtual void Reset() = 0; //reset values
	
	virtual bool Load(const CDM::InhalerCompartmentsData& in) = 0;
	virtual std::unique_ptr<CDM::InhalerCompartmentsData> Unload() const = 0;

	virtual bool                        HasCompartment(CDM::enumInhaler::value type) = 0;
	virtual SEInhalerCompartment&       GetCompartment(CDM::enumInhaler::value type) = 0;
	virtual const SEInhalerCompartment* GetCompartment(CDM::enumInhaler::value type) const = 0;
	
protected:
	

	
};
