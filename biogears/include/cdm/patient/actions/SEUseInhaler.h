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
#include "patient/actions/SEConsciousRespirationCommand.h"
CDM_BIND_DECL(UseInhalerData)
class SESubstance;

class DLL_DECL SEUseInhaler : public SEConsciousRespirationCommand
{
public:

	SEUseInhaler();
	virtual ~SEUseInhaler();
	SEUseInhaler(const SEUseInhaler& other);
	virtual SEUseInhaler* Copy();
	virtual void Copy(const SEUseInhaler& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::UseInhalerData& in);
	std::unique_ptr<CDM::UseInhalerData> Unload() const;
protected:
	void Unload(CDM::UseInhalerData& data) const;
public:

	virtual void ToString(std::ostream &str) const;
protected:

};  
