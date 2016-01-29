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
CDM_BIND_DECL(SubstanceCompartmentEffectData)

class DLL_DECL SESubstanceCompartmentEffect : public Loggable
{
public:
	SESubstanceCompartmentEffect(Logger* logger);
	virtual ~SESubstanceCompartmentEffect();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	bool Load(const CDM::SubstanceCompartmentEffectData& in);
	std::unique_ptr<CDM::SubstanceCompartmentEffectData> Unload() const;
protected:
	void Unload(CDM::SubstanceCompartmentEffectData& data) const;
public:

	virtual bool HasPartitionCoefficient() const;
	virtual SEScalar& GetPartitionCoefficient();
	virtual double GetPartitionCoefficient() const;

	virtual bool HasPermeabilitySurfaceAreaProduct() const;
	virtual SEScalar& GetPermeabilitySurfaceAreaProduct();
	virtual double GetPermeabilitySurfaceAreaProduct() const;

	virtual bool HasClearanceModifier() const;
	virtual SEScalar& GetClearanceModifier();
	virtual double GetClearanceModifier() const;

	virtual bool HasMassCleared() const;
	virtual SEScalarMass& GetMassCleared();
	virtual double GetMassCleared() const;

	virtual bool HasMassExcreted() const;
	virtual SEScalarMass& GetMassExcreted();
	virtual double GetMassExcreted() const;

protected:

	SEScalar*     m_PartitionCoefficient;
	SEScalar*     m_PermeabilitySurfaceAreaProduct;
	SEScalar*     m_ClearanceModifier;
	SEScalarMass* m_MassCleared;
	SEScalarMass* m_MassExcreted;
};