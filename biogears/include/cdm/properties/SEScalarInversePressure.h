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

class DLL_DECL SEScalarInversePressure : public SEScalar
{

public:
	SEScalarInversePressure();
	virtual ~SEScalarInversePressure() {}

	std::unique_ptr<CDM::ScalarData> Unload() const;

	virtual bool IsValidUnit(const std::string& unit) const;
	virtual bool IsValidUnit(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual std::shared_ptr<CCompoundUnit>& GetCompoundUnit(const std::string& unit) const;

	static std::shared_ptr<CCompoundUnit> Inverse_Pa; //Inverse_Pascals
	static std::shared_ptr<CCompoundUnit> Inverse_mmHg;// Inverse_milimeters of Mercury
	static std::shared_ptr<CCompoundUnit> Inverse_cmH2O;// Inverse_centimeters of H20
	static std::shared_ptr<CCompoundUnit> Inverse_atm;// Inverse_atmospheres
};
