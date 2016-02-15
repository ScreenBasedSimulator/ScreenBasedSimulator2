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
#include "patient/conditions/SEPatientCondition.h"
CDM_BIND_DECL(PericardialEffusionConditionData)

class DLL_DECL SEPericardialEffusionCondition : public SEPatientCondition
{
public:

	SEPericardialEffusionCondition();
	virtual ~SEPericardialEffusionCondition();
	SEPericardialEffusionCondition(const SEPericardialEffusionCondition& other);
	virtual void Copy(const SEPericardialEffusionCondition& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::PericardialEffusionConditionData& in);
	std::unique_ptr<CDM::PericardialEffusionConditionData> Unload() const;
protected:
	void Unload(CDM::PericardialEffusionConditionData& data) const;
public:
	virtual std::string GetName() const { return "PericardialEffusion"; }

	virtual bool HasAccumulatedVolume() const;
	virtual SEScalarVolume& GetAccumulatedVolume();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarVolume* m_AccumulatedVolume;
};