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
#include "properties/SEFunction.h"

class DLL_DECL SEFunctionTimeVsVolume : public SEFunction
{
public:

	SEFunctionTimeVsVolume();
	virtual ~SEFunctionTimeVsVolume();

	std::unique_ptr<CDM::FunctionData> Unload() const;

	virtual double                                GetTimeValue(unsigned int index, const std::shared_ptr<CCompoundUnit>& unit);
	virtual std::vector<double>*			      GetTime();
	virtual void 			                      GetTime(std::vector<double>&, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void							      SetTime(std::vector<double>* abscissa, const std::shared_ptr<CCompoundUnit>& unit);
	virtual const std::shared_ptr<CCompoundUnit>& GetTimeUnit();
	virtual bool                                  IsValidTimeUnit(const std::shared_ptr<CCompoundUnit>& unit);
	virtual bool                                  IsValidAbscissaUnit(const std::shared_ptr<CCompoundUnit>& unit);

	virtual double                                GetVolumeValue(unsigned int index, const std::shared_ptr<CCompoundUnit>& unit);
	virtual std::vector<double>*			      GetVolume();
	virtual void			                      GetVolume(std::vector<double>&, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void							      SetVolume(std::vector<double>* ordinate, const std::shared_ptr<CCompoundUnit>& unit);
	virtual const std::shared_ptr<CCompoundUnit>& GetVolumeUnit();
	virtual bool                                  IsValidVolumeUnit(const std::shared_ptr<CCompoundUnit>& unit);
	virtual bool                                  IsValidOrdinateUnit(const std::shared_ptr<CCompoundUnit>& unit);

protected:

	virtual const std::shared_ptr<CCompoundUnit>& GetAbscissaCompoundUnit(const std::string& unit);
	virtual const std::shared_ptr<CCompoundUnit>& GetOrdinateCompoundUnit(const std::string& unit);

	static SEScalarTime m_Time;
	static SEScalarVolume m_Volume;
};