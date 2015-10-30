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
CDM_BIND_DECL(ConsciousRespirationData)
class SEConsciousRespirationCommand;
class SESubstanceManager;

class DLL_DECL SEConsciousRespiration : public SEPatientAction
{
public:

	SEConsciousRespiration();
	virtual ~SEConsciousRespiration();
	SEConsciousRespiration(const SEConsciousRespiration& other);
	virtual void Copy(const SEConsciousRespiration& other);
	virtual void Append(const SEConsciousRespiration& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::ConsciousRespirationData& in, const SESubstanceManager& substances);
	std::unique_ptr<CDM::ConsciousRespirationData> Unload() const;
protected:
	void Unload(CDM::ConsciousRespirationData& data) const;
public:

	// Get the active command
	virtual SEConsciousRespirationCommand* GetActiveCommand();
	/// When the active command has been processed, remove it
	virtual void RemoveActiveCommand();

	virtual void ToString(std::ostream &str) const;
protected:

	std::vector<SEConsciousRespirationCommand*> m_Commands;
};  