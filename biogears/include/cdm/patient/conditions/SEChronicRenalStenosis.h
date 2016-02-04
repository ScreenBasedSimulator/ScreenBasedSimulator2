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
CDM_BIND_DECL(ChronicRenalStenosisData)

class DLL_DECL SEChronicRenalStenosis : public SEPatientCondition
{
public:

	SEChronicRenalStenosis();
	virtual ~SEChronicRenalStenosis();
	SEChronicRenalStenosis(const SEChronicRenalStenosis& other);
	virtual void Copy(const SEChronicRenalStenosis& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::ChronicRenalStenosisData& in);
	std::unique_ptr<CDM::ChronicRenalStenosisData> Unload() const;
protected:
	void Unload(CDM::ChronicRenalStenosisData& data) const;
public:
	virtual std::string GetName() const { return "ChronicRenalStenosis"; }

	virtual bool HasLeftKidneyOcclusionFraction() const;
	virtual SEScalarFraction& GetLeftKidneyOcclusionFraction();

	virtual bool HasRightKidneyOcclusionFraction() const;
	virtual SEScalarFraction& GetRightKidneyOcclusionFraction();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*           m_LeftKidneyOcclusionFraction;
	SEScalarFraction*           m_RightKidneyOcclusionFraction;
};