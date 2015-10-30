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
class Serializer;
CDM_BIND_DECL(MealData)
#include "patient/SENutrition.h"

class DLL_DECL SEMeal : public SENutrition
{
public:

	SEMeal(Logger* logger);
	virtual ~SEMeal();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	void Copy(const SEMeal& other);

	bool Load(const CDM::MealData& in);
	std::unique_ptr<CDM::MealData> Unload() const;
protected:
	void Unload(CDM::MealData& data) const;
public:
	
	bool LoadFile(const std::string& MealFile, Serializer& serlializer);
	
	virtual bool HasElapsedTime() const;
	virtual SEScalarTime& GetElapsedTime();
	virtual double GetElapsedTime(const std::shared_ptr<CCompoundUnit>& unit) const;
	
protected:

	SEScalarTime*    m_ElapsedTime;
};