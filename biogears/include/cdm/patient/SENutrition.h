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
CDM_BIND_DECL(NutritionData)
class SEPatient;

class DLL_DECL SENutrition : public Loggable
{
public:

	SENutrition(Logger* logger);
	virtual ~SENutrition();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	void Copy(const SENutrition& from);
	void Increment(const SENutrition& from);

	bool Load(const CDM::NutritionData& in);
	std::unique_ptr<CDM::NutritionData> Unload() const;
protected:
	void Unload(CDM::NutritionData& data) const;
public:
	
	/** @name LoadFile
	*   @brief Clear and set contents to this file
	*/
	bool LoadFile(const std::string& nutritionFile, Serializer& serlializer);
	
	virtual bool HasCarbohydrate() const;
	virtual SEScalarMass& GetCarbohydrate();
	virtual double GetCarbohydrate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCarbohydrateDigestionRate() const;
	virtual SEScalarMassPerTime& GetCarbohydrateDigestionRate();
	virtual double GetCarbohydrateDigestionRate(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasFat() const;
	virtual SEScalarMass& GetFat();
	virtual double GetFat(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasFatDigestionRate() const;
	virtual SEScalarMassPerTime& GetFatDigestionRate();
	virtual double GetFatDigestionRate(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasProtein() const;
	virtual SEScalarMass& GetProtein();
	virtual double GetProtein(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasProteinDigestionRate() const;
	virtual SEScalarMassPerTime& GetProteinDigestionRate();
	virtual double GetProteinDigestionRate(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasSodium() const;
	virtual SEScalarMass& GetSodium();
	virtual double GetSodium(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCalcium() const;
	virtual SEScalarMass& GetCalcium();
	virtual double GetCalcium(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasWater() const;
	virtual SEScalarVolume& GetWater();
	virtual double GetWater(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual double GetWeight(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual void ToString(std::ostream &str) const;
	
protected:

	SEScalarMass*          m_Carbohydrate;
	SEScalarMassPerTime*   m_CarbohydrateDigestionRate;
	SEScalarMass*          m_Fat;
	SEScalarMassPerTime*   m_FatDigestionRate;
	SEScalarMass*          m_Protein;
	SEScalarMassPerTime*   m_ProteinDigestionRate;
	SEScalarMass*          m_Calcium;
	SEScalarMass*          m_Sodium;
	SEScalarVolume*        m_Water;
};

inline std::ostream& operator<< (std::ostream& out, const SENutrition& n)
{
	n.ToString(out);
	return out;
}