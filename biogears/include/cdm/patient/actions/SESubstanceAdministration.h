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
CDM_BIND_DECL(SubstanceAdministrationData)

class DLL_DECL SESubstanceAdministration : public SEPatientAction
{
public:

	SESubstanceAdministration();
	virtual ~SESubstanceAdministration();
	SESubstanceAdministration(const SESubstanceAdministration& other);
	virtual void Copy(const SESubstanceAdministration& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::SubstanceAdministrationData& in);
protected:
	void Unload(CDM::SubstanceAdministrationData& data) const;
public:

protected:
};               