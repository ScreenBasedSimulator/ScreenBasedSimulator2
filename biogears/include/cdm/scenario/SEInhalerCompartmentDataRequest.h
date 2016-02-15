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
#include "scenario/SEDataRequest.h"
#include "CommonDataModel.h"
CDM_BIND_DECL(InhalerCompartmentDataRequestData)
#include "bind/enumInhaler.hxx"
class SESubstance;
class SESubstanceManager;

class DLL_DECL SEInhalerCompartmentDataRequest : public SEDataRequest
{
public:

	SEInhalerCompartmentDataRequest();
	virtual ~SEInhalerCompartmentDataRequest();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::InhalerCompartmentDataRequestData& in, const SESubstanceManager& substances);
	std::unique_ptr<CDM::InhalerCompartmentDataRequestData> Unload() const;
protected:
	void Unload(CDM::InhalerCompartmentDataRequestData& data) const;
public:

	virtual CDM::enumInhaler::value GetCompartment() const;
	virtual void SetCompartment(CDM::enumInhaler::value name);
	virtual bool HasCompartment() const;
	virtual void InvalidateCompartment();

	virtual const SESubstance* GetSubstance() const;
	virtual void SetSubstance(SESubstance* name);
	virtual bool HasSubstance() const;
	virtual void InvalidateSubstance();

	virtual void Set(CDM::enumInhaler::value cmpt, const SESubstance& substance, const std::string& name, const std::string&unit = "");
	virtual void Set(CDM::enumInhaler::value cmpt, const SESubstance& substance, const std::string& name, const std::shared_ptr<CCompoundUnit>& unit);

protected:

	CDM::enumInhaler::value m_Compartment;
	const SESubstance*                m_Substance;

};                  