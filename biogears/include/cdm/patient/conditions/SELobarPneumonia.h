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
CDM_BIND_DECL(LobarPneumoniaData)
#include "bind/enumSide.hxx"

class DLL_DECL SELobarPneumonia : public SEPatientCondition
{
public:

	SELobarPneumonia();
	virtual ~SELobarPneumonia();
	SELobarPneumonia(const SELobarPneumonia& other);
	virtual void Copy(const SELobarPneumonia& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::LobarPneumoniaData& in);
	std::unique_ptr<CDM::LobarPneumoniaData> Unload() const;
protected:
	void Unload(CDM::LobarPneumoniaData& data) const;
public:
	virtual std::string GetName() const { return "LobarPneumonia"; }

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();	

	virtual bool HasLeftLungAffected() const;
	virtual SEScalarFraction& GetLeftLungAffected();

	virtual bool HasRightLungAffected() const;
	virtual SEScalarFraction& GetRightLungAffected();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
	SEScalarFraction*     m_LeftLungAffected;
	SEScalarFraction*     m_RightLungAffected;
};      
