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
#include "properties/SEScalar.h"

class DLL_DECL SEScalarVolumePerTime : public SEScalar
{

public:
	SEScalarVolumePerTime();
	virtual ~SEScalarVolumePerTime() {}

	std::unique_ptr<CDM::ScalarData> Unload() const;

	virtual bool IsValidUnit(const std::string& unit) const;
	virtual bool IsValidUnit(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual std::shared_ptr<CCompoundUnit>& GetCompoundUnit(const std::string& unit) const;

	static std::shared_ptr<CCompoundUnit> L_Per_s;// Liters per second
	static std::shared_ptr<CCompoundUnit> L_Per_day;// Liters per day
	static std::shared_ptr<CCompoundUnit> mL_Per_s;// mililiters per second
	static std::shared_ptr<CCompoundUnit> mL_Per_day;// mililiters per day
	static std::shared_ptr<CCompoundUnit> L_Per_min;// mililiters per minute
	static std::shared_ptr<CCompoundUnit> m3_Per_s; // cubic meters per second
	static std::shared_ptr<CCompoundUnit> mL_Per_min;// mililiters per minute
};
