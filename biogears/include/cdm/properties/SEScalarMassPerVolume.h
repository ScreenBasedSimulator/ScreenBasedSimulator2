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

class DLL_DECL SEScalarMassPerVolume : public SEScalar
{

public:
	SEScalarMassPerVolume();
	virtual ~SEScalarMassPerVolume() {}

	std::unique_ptr<CDM::ScalarData> Unload() const;

	virtual bool IsValidUnit(const std::string& unit) const;
	virtual bool IsValidUnit(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual std::shared_ptr<CCompoundUnit>& GetCompoundUnit(const std::string& unit) const;

	static std::shared_ptr<CCompoundUnit> ug_Per_mL;// micro gram per mL
	static std::shared_ptr<CCompoundUnit> mg_Per_m3;// miligram per cubic meter
	static std::shared_ptr<CCompoundUnit> kg_Per_m3;// kilogram per cubic meter
	static std::shared_ptr<CCompoundUnit> ug_Per_L;// kilogram per Liter
	static std::shared_ptr<CCompoundUnit> g_Per_dL;// grams per deciLiter
	static std::shared_ptr<CCompoundUnit> g_Per_L;// grams per Liter
	static std::shared_ptr<CCompoundUnit> g_Per_mL;// grams per milliliter
	static std::shared_ptr<CCompoundUnit> g_Per_m3;// micro gram per mL
	static std::shared_ptr<CCompoundUnit> mg_Per_mL;// milligram per milliLiter
	static std::shared_ptr<CCompoundUnit> mg_Per_L;// milligram per Liter
	static std::shared_ptr<CCompoundUnit> mg_Per_dL;// milligram per deciliter
	static std::shared_ptr<CCompoundUnit> kg_Per_mL;// kilogram per milliLiter
};
