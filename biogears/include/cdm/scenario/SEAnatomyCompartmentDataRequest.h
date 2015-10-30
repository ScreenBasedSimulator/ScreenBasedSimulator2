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
CDM_BIND_DECL(AnatomyCompartmentDataRequestData)
#include "bind/enumAnatomy.hxx"
#include "bind/enumCompartmentType.hxx"
class SESubstance;
class SESubstanceManager;

class DLL_DECL SEAnatomyCompartmentDataRequest : public SEDataRequest
{
public:

	SEAnatomyCompartmentDataRequest();
	virtual ~SEAnatomyCompartmentDataRequest();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::AnatomyCompartmentDataRequestData& in, const SESubstanceManager& substances);
	std::unique_ptr<CDM::AnatomyCompartmentDataRequestData> Unload() const;
protected:
	void Unload(CDM::AnatomyCompartmentDataRequestData& data) const;
public:

	virtual size_t HashCode();

	virtual CDM::enumAnatomy::value GetCompartment() const;
	virtual void SetCompartment(CDM::enumAnatomy::value name);
	virtual bool HasCompartment() const;
	virtual void InvalidateCompartment();

	virtual CDM::enumCompartmentType::value GetType() const;
	virtual void SetType(CDM::enumCompartmentType::value name);
	virtual bool HasType() const;
	virtual void InvalidateType();

	virtual const SESubstance* GetSubstance() const;
	virtual void SetSubstance(const SESubstance* sub);
	virtual bool HasSubstance() const;
	virtual void InvalidateSubstance();

	virtual void Set(CDM::enumAnatomy::value cmpt, CDM::enumCompartmentType::value type, const std::string& name, const std::string&unit = "");
	virtual void Set(CDM::enumAnatomy::value cmpt, CDM::enumCompartmentType::value type, const std::string& name, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void Set(CDM::enumAnatomy::value cmpt, CDM::enumCompartmentType::value type, const SESubstance& substance, const std::string& name, const std::string&unit = "");
	virtual void Set(CDM::enumAnatomy::value cmpt, CDM::enumCompartmentType::value type, const SESubstance& substance, const std::string& name, const std::shared_ptr<CCompoundUnit>& unit);


protected:
	CDM::enumAnatomy::value             m_Compartment;
	CDM::enumCompartmentType::value     m_Type;
	const SESubstance*                  m_Substance;

};                  