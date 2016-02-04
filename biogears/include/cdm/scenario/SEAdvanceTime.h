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
#include "scenario/SEAction.h"
CDM_BIND_DECL(AdvanceTimeData)

class DLL_DECL SEAdvanceTime : public SEAction
{
public:

	SEAdvanceTime();
	virtual ~SEAdvanceTime();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::AdvanceTimeData& in);
	std::unique_ptr<CDM::AdvanceTimeData> Unload() const;
protected:
	void Unload(CDM::AdvanceTimeData& data) const;

public:

	virtual void ToString(std::ostream &str) const;

	virtual bool HasTime() const;
	virtual SEScalarTime& GetTime();
	virtual double GetTime(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	SEScalarTime *m_Time;
};                  