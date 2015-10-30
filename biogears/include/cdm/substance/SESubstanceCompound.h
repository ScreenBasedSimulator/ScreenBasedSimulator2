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
class SESubstanceManager;
class SESubstanceCompoundComponent;
CDM_BIND_DECL(SubstanceCompoundData)

class DLL_DECL SESubstanceCompound : public Loggable
{
public:

	SESubstanceCompound(Logger* logger);
	virtual ~SESubstanceCompound();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::SubstanceCompoundData& in, const SESubstanceManager& subMgr);
	std::unique_ptr<CDM::SubstanceCompoundData> Unload() const;
protected:
	void Unload(CDM::SubstanceCompoundData& data) const;
public:
	
	virtual std::string GetName() const;
	virtual void SetName(const std::string& name);
	virtual bool HasName() const;
	virtual void InvalidateName();

	bool HasComponent() const;
	bool HasComponent(const SESubstance& substance) const;
	const std::vector<SESubstanceCompoundComponent*>& GetComponents();	
	const std::vector<const SESubstanceCompoundComponent*>& GetComponents() const;
	const SESubstanceCompoundComponent& GetComponent(const SESubstance& substance);
	const SESubstanceCompoundComponent* GetComponent(const SESubstance& substance) const;
	void RemoveComponent(const SESubstance& substance);

protected: 

	std::string m_Name;

	std::vector<SESubstanceCompoundComponent*>       m_Components;
	std::vector<const SESubstanceCompoundComponent*> m_cComponents;
};