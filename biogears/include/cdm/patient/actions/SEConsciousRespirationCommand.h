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
#include "bind/enumBeginBreathingCommandType.hxx"
CDM_BIND_DECL(ConsciousRespirationCommandData)

class DLL_DECL SEConsciousRespirationCommand
{
public:

	SEConsciousRespirationCommand();
	virtual ~SEConsciousRespirationCommand();
	SEConsciousRespirationCommand(const SEConsciousRespirationCommand& other);
	virtual SEConsciousRespirationCommand* Copy() = 0;
	virtual void Copy(const SEConsciousRespirationCommand& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::ConsciousRespirationCommandData& in);	
protected:
	void Unload(CDM::ConsciousRespirationCommandData& data) const;
public:

	virtual std::string GetComment() const;
	virtual void SetComment(const std::string& comment);
	virtual bool HasComment() const;
	virtual void InvalidateComment();

	virtual CDM::enumBeginBreathingCommandType::value GetBeginType() const;
	virtual void SetBeginType(CDM::enumBeginBreathingCommandType::value t);
	virtual bool HasBeginType() const;
	virtual void InvalidateBeginType();

	virtual void ToString(std::ostream &str) const = 0;
protected:

	std::string                               m_Comment;
	CDM::enumBeginBreathingCommandType::value m_BeginType;
};  