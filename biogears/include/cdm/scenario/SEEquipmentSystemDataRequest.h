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
#include "scenario/SEDataRequest.h"
CDM_BIND_DECL(EquipmentSystemDataRequestData)

class DLL_DECL SEEquipmentSystemDataRequest : public SEDataRequest
{
public:

	SEEquipmentSystemDataRequest();
	virtual ~SEEquipmentSystemDataRequest();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::EquipmentSystemDataRequestData& in);
	std::unique_ptr<CDM::EquipmentSystemDataRequestData> Unload() const;
protected:
	void Unload(CDM::EquipmentSystemDataRequestData& data) const;
public:

protected:

};                  