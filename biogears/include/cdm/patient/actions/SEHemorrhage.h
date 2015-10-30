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
#include "patient/actions/SEPatientAction.h"
CDM_BIND_DECL(HemorrhageData)
#include "bind/enumAnatomy.hxx"

class DLL_DECL SEHemorrhage : public SEPatientAction
{
public:

	SEHemorrhage();
	virtual ~SEHemorrhage();
	SEHemorrhage(const SEHemorrhage& other);
	virtual void Copy(const SEHemorrhage& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::HemorrhageData& in);
	std::unique_ptr<CDM::HemorrhageData> Unload()const;
protected:
	void Unload(CDM::HemorrhageData& data) const;
public:

	virtual CDM::enumAnatomy::value GetCompartment() const;
	virtual void SetCompartment(CDM::enumAnatomy::value name);
	virtual bool HasCompartment() const;
	virtual void InvalidateCompartment();

	virtual bool HasRate() const;
	virtual SEScalarVolumePerTime& GetRate();	

	virtual void ToString(std::ostream &str) const;

protected:
	CDM::enumAnatomy::value m_Compartment;
	SEScalarVolumePerTime*  m_Rate;
	
};    