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
class SESubstance;
CDM_BIND_DECL(SubstanceCompoundComponentData)

class DLL_DECL SESubstanceCompoundComponent : public Loggable
{
public:

	SESubstanceCompoundComponent(const SESubstance& substance);
	virtual ~SESubstanceCompoundComponent();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::SubstanceCompoundComponentData& in);
	std::unique_ptr<CDM::SubstanceCompoundComponentData> Unload() const;
protected:
	void Unload(CDM::SubstanceCompoundComponentData& data) const;
public:
	
	virtual bool HasConcentration() const;
	virtual SEScalarMassPerVolume& GetConcentration();	
	virtual double GetConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual SESubstance& GetSubstance() const;
	
protected: 

	const SESubstance&     m_Substance;
	SEScalarMassPerVolume* m_Concentration;
	
};