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

#include "bind/enumCircuitModelType.hxx"

class SECircuit;
class SECircuitNode;
class SECircuitPath;
class SESubstance;
class SECircuitContainer;
class CCompoundUnit;

CDM_BIND_DECL(InterCircuitConnectionData)

class DLL_DECL SEInterCircuitConnection : public Loggable
{
public:

	SEInterCircuitConnection(Logger* logger);
	virtual ~SEInterCircuitConnection();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::InterCircuitConnectionData& in);
	std::unique_ptr<CDM::InterCircuitConnectionData> Unload();

	virtual unsigned int GetID();
	virtual void SetID(unsigned int ID);
	virtual bool HasID();
	virtual void InvalidateID();

	virtual std::string GetName();
	virtual void SetName(const std::string& name);
	virtual bool HasName();
	virtual void InvalidateName();

	virtual SECircuitNode* GetSourceCircuitNode();
	virtual void SetSourceCircuitNode(SECircuitNode* Node);

	virtual SECircuitNode* GetTargetCircuitNode();
	virtual void SetTargetCircuitNode(SECircuitNode* Node);

	virtual SECircuitPath* GetPath();
	virtual void SetPath(SECircuitPath* Path);

	virtual SECircuitNode* GetNode();
	virtual void SetNode(SECircuitNode* Node);

	virtual SECircuit* GetSourceCircuit();
	virtual void SetSourceCircuit(SECircuit* Circuit);

	virtual SECircuit* GetTargetCircuit();
	virtual void SetTargetCircuit(SECircuit* Circuit);

	virtual double GetPotentialSetting(std::shared_ptr<CCompoundUnit> Unit);
	virtual double GetFluxSetting(std::shared_ptr<CCompoundUnit> Unit);

	void CreateInterCircuitConnection(
		const std::string& name,
		SECircuit* Circuit1, SECircuitNode* Circuit1Node,
		SECircuit* Circuit2, SECircuitNode* Circuit2Node);
	void RemoveInterCircuitConnection();

	void PreProcess();
	void Process();
	void PostProcess(const std::vector<SESubstance*>* vSubstances = nullptr);

	void SetActive(bool bActive);
	bool IsActive();

	void SetInitilized(bool bInitialized);
	bool IsInitialized();

protected:

	void Unload(CDM::InterCircuitConnectionData& data);

	void CreateInterCircuitConnection();

	SECircuitContainer* m_Container;
	std::stringstream m_sError;

	bool m_bActive;

	unsigned int		m_ID;
	std::string			m_Name;
	SECircuit*			m_SourceCircuit;
	SECircuit*			m_TargetCircuit;
	SECircuitNode*		m_SourceCircuitNode;
	SECircuitNode*		m_TargetCircuitNode;
	SECircuitPath*		m_SourcePath;
	SECircuitPath*		m_TargetPath;
	SECircuitNode*		m_Node;
	double				m_dFluxSetting;      //TODO: Make this a value-unit pair and remove m_FluxUnit
	double				m_dPotentialSetting; //TODO: Make this a value-unit pair and remove m_PotentialUnit
	std::shared_ptr<CCompoundUnit> m_PotentialUnit;
	std::shared_ptr<CCompoundUnit> m_FluxUnit;
	CDM::enumCircuitModelType::value m_ModelType;
	bool				m_bInitialized;
};
