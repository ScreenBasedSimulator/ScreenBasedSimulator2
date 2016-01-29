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
#include "patient/conditions/SEChronicArrhythmia.h"
CDM_BIND_DECL(ChronicBradycardiaData)

class DLL_DECL SEChronicBradycardia : public SEChronicArrhythmia
{
public:

	SEChronicBradycardia();
	virtual ~SEChronicBradycardia();
	SEChronicBradycardia(const SEChronicBradycardia& other);
	virtual void Copy(const SEChronicBradycardia& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::ChronicBradycardiaData& in);
	std::unique_ptr<CDM::ChronicBradycardiaData> Unload() const;
protected:
	void Unload(CDM::ChronicBradycardiaData& data) const;
public:
	virtual std::string GetName() const{ return "ChronicBradycardia"; }

	virtual void ToString(std::ostream &str) const;

protected:
};      