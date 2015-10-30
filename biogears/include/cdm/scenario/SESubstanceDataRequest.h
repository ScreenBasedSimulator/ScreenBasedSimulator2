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
CDM_BIND_DECL(SubstanceDataRequestData)
class SESubstance;
class SESubstanceManager;
#include "bind/enumAnatomy.hxx"

class DLL_DECL SESubstanceDataRequest : public SEDataRequest
{
public:

	SESubstanceDataRequest();
	virtual ~SESubstanceDataRequest();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::SubstanceDataRequestData& in, const SESubstanceManager& substances);
	std::unique_ptr<CDM::SubstanceDataRequestData> Unload() const;
protected:
	void Unload(CDM::SubstanceDataRequestData& data) const;
public:

	virtual size_t HashCode() const;

	virtual CDM::enumAnatomy::value GetCompartment() const;
	virtual void SetCompartment(CDM::enumAnatomy::value name);
	virtual bool HasCompartment() const;
	virtual void InvalidateCompartment();

	virtual const SESubstance* GetSubstance() const;
	virtual void SetSubstance(SESubstance* name);
	virtual bool HasSubstance() const;
	virtual void InvalidateSubstance();

	virtual void Set(const SESubstance& substance, CDM::enumAnatomy::value cmpt, const std::string& name, const std::string&unit = "");

protected:

	CDM::enumAnatomy::value m_Compartment;
	const SESubstance*      m_Substance;

};                  