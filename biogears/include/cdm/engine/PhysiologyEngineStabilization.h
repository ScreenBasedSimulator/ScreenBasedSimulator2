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
class PhysiologyEngine;
class PhysiologyEngineTrack;
class PhysiologyEngineConfiguration; 
class SECondition;

CDM_BIND_DECL(PhysiologyEngineStabilizationData)
class DLL_DECL PhysiologyEngineStabilization : public Loggable
{
public:
	PhysiologyEngineStabilization(Logger* logger);
	virtual ~PhysiologyEngineStabilization();

	virtual void Reset();
	virtual void Clear();

	bool Load(const CDM::PhysiologyEngineStabilizationData& in);
	std::unique_ptr<CDM::PhysiologyEngineStabilizationData> Unload() const;
protected:
	void Unload(CDM::PhysiologyEngineStabilizationData& data) const;
public:

	virtual bool StabilizeRestingState(PhysiologyEngine& engine)=0;
	virtual bool StabilizeConditions(PhysiologyEngine& engine, const std::vector<const SECondition*>& conditions)=0;
	
	virtual void LogProgress(bool b);

	virtual void CancelStabilization();

	virtual void TrackStabilization(bool b);
	virtual bool IsTrackingStabilization();

	virtual bool HasStabilizationDuration();
	virtual SEScalarTime& GetStabilizationDuration();

protected:

	bool m_Cancelled;
	bool m_LogProgress;
	bool m_TrackingStabilization;
	double m_currentTime_s;
	std::stringstream m_ss;

	SEScalarTime* m_StabilizationDuration;
};
