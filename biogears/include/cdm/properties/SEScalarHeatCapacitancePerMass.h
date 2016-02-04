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

class DLL_DECL SEScalarHeatCapacitancePerMass : public SEScalar
{

public:
	SEScalarHeatCapacitancePerMass();
	virtual ~SEScalarHeatCapacitancePerMass() {}

	std::unique_ptr<CDM::ScalarData> Unload() const;

	virtual bool IsValidUnit(const std::string& unit) const;
	virtual bool IsValidUnit(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual std::shared_ptr<CCompoundUnit>& GetCompoundUnit(const std::string& unit) const;

	static std::shared_ptr<CCompoundUnit> J_Per_K_kg; // Joule/kelvin
	static std::shared_ptr<CCompoundUnit> kJ_Per_K_kg; // Joule/degrees C
	static std::shared_ptr<CCompoundUnit> kcal_Per_K_kg; // kcal/kelvin
	static std::shared_ptr<CCompoundUnit> kcal_Per_C_kg; // kcal/degrees C
};