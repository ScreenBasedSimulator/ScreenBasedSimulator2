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
CDM_BIND_DECL(ChronicObstructivePulmonaryDiseaseData)

class DLL_DECL SEChronicObstructivePulmonaryDisease : public SEPatientCondition
{
public:

	SEChronicObstructivePulmonaryDisease();
	virtual ~SEChronicObstructivePulmonaryDisease();
	SEChronicObstructivePulmonaryDisease(const SEChronicObstructivePulmonaryDisease& other);
	virtual void Copy(const SEChronicObstructivePulmonaryDisease& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::ChronicObstructivePulmonaryDiseaseData& in);
	std::unique_ptr<CDM::ChronicObstructivePulmonaryDiseaseData> Unload() const;
protected:
	void Unload(CDM::ChronicObstructivePulmonaryDiseaseData& data) const;
public:
	virtual std::string GetName() const { return "ChronicObstructivePulmonaryDisease"; }

	virtual bool HasBronchitisSeverity() const;
	virtual SEScalarFraction& GetBronchitisSeverity();

	virtual bool HasEmphysemaSeverity() const;
	virtual SEScalarFraction& GetEmphysemaSeverity();

	virtual void ToString(std::ostream &str) const;

protected:
	SEScalarFraction*     m_BronchitisSeverity;
	SEScalarFraction*     m_EmphysemaSeverity;
};
