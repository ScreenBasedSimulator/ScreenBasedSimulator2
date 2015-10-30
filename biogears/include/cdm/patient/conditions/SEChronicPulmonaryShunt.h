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
CDM_BIND_DECL(ChronicPulmonaryShuntData)

class DLL_DECL SEChronicPulmonaryShunt : public SEPatientCondition
{
public:

	SEChronicPulmonaryShunt();
	virtual ~SEChronicPulmonaryShunt();
	SEChronicPulmonaryShunt(const SEChronicPulmonaryShunt& other);
	virtual void Copy(const SEChronicPulmonaryShunt& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::ChronicPulmonaryShuntData& in);
	std::unique_ptr<CDM::ChronicPulmonaryShuntData> Unload() const;
protected:
	void Unload(CDM::ChronicPulmonaryShuntData& data) const;
public:
	virtual std::string GetName() const { return "ChronicPulmonaryShunt"; }

	virtual bool HasShuntFraction() const;
	virtual SEScalarFraction& GetShuntFraction();	

	virtual void ToString(std::ostream &str) const;

protected:
	
	SEScalarFraction*           m_ShuntFraction;
};      