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

#include "engine/PhysiologyEngineStabilization.h"
#include "properties/SEScalarTime.h"

CDM_BIND_DECL(PhysiologyEngineTimedConditionStabilizationData)
class DLL_DECL PhysiologyEngineTimedStabilizationCriteria : public Loggable
{
public:

	PhysiologyEngineTimedStabilizationCriteria(Logger* logger);
	virtual ~PhysiologyEngineTimedStabilizationCriteria();

	void Reset();
	void Clear();

	bool Load(const CDM::PhysiologyEngineTimedConditionStabilizationData& in);
	std::unique_ptr<CDM::PhysiologyEngineTimedConditionStabilizationData> Unload() const;
protected:
	void Unload(CDM::PhysiologyEngineTimedConditionStabilizationData& data) const;
public:

	std::string GetName() const;
	void SetName(const std::string& name);
	bool HasName() const;
	void InvalidateName();

	bool HasTime();
	SEScalarTime& GetTime();
	const SEScalarTime& GetTime() const;


protected:
	std::string    m_Name;
	SEScalarTime   m_Time;
	
};

CDM_BIND_DECL(PhysiologyEngineTimedStabilizationData)
class DLL_DECL PhysiologyEngineTimedStabilization : public PhysiologyEngineStabilization
{
public:
	PhysiologyEngineTimedStabilization(Logger* logger);
	virtual ~PhysiologyEngineTimedStabilization();

	void Reset();
	void Clear();

	bool Load(const CDM::PhysiologyEngineTimedStabilizationData& in);
	std::unique_ptr<CDM::PhysiologyEngineTimedStabilizationData> Unload() const;
protected:
	void Unload(CDM::PhysiologyEngineTimedStabilizationData& data) const;
public:

	bool StabilizeRestingState(PhysiologyEngine& engine);
	bool StabilizeConditions(PhysiologyEngine& engine, const std::vector<const SECondition*>& conditions);

	SEScalarTime& GetRestingStabilizationTime();
	double GetRestingStabilizationTime(const std::shared_ptr<CCompoundUnit>& unit) const;

	void RemoveConditionCriteria(const std::string& name);
	void AddConditionCriteria(PhysiologyEngineTimedStabilizationCriteria& criteria);
	const std::vector<PhysiologyEngineTimedStabilizationCriteria*>& GetConditionCriteria() const;
	PhysiologyEngineTimedStabilizationCriteria* GetConditionCriteria(const std::string& name) const;

protected:

	bool Stabilize(PhysiologyEngine& engine, const SEScalarTime& time);

	SEScalarTime m_RestingStabilizationTime;
	std::vector<PhysiologyEngineTimedStabilizationCriteria*> m_ConditionCriteria;
};
