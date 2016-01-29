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
class CCompoundUnit;
class SESubstance;
class SECircuitContainer;
class SECircuitNode;
class SECircuitPath;
CDM_BIND_DECL(CircuitData)
#include "bind/enumCircuitModelType.hxx"

class DLL_DECL SECircuit : public Loggable
{
public:

	SECircuit(Logger* logger);
	SECircuit(SECircuitContainer& parent);
	virtual ~SECircuit();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	void StateChange();
	bool IsInitialized();

	void PrintState(bool bWaitForKeyPress);
	void PrintSubstanceValues(std::vector<SESubstance*>* vSubstances, bool bWaitForKeyPress);

	bool Load(const CDM::CircuitData& in);
	std::unique_ptr<CDM::CircuitData> Unload();

	std::vector<SECircuitPath*>* GetTargetPaths(SECircuitNode* node);
	std::vector<SECircuitPath*>* GetSourcePaths(SECircuitNode* node);

	// Data Model Definitions
	virtual bool HasReferenceNode();
	virtual SECircuitNode* GetReferenceNode();
	virtual void SetReferenceNode(SECircuitNode* node);

	virtual bool HasModelType();
	virtual CDM::enumCircuitModelType::value GetModelType();
	virtual void SetModelType(CDM::enumCircuitModelType::value);

	void SetNextAndCurrentFromBaselines();
	void SetBaselinesFromNext();

	virtual void SetBaseUnits(const std::shared_ptr<CCompoundUnit>& PotentialUnit,
		const std::shared_ptr<CCompoundUnit>& FluxUnit,
		const std::shared_ptr<CCompoundUnit>& QuantityUnit,
		const std::shared_ptr<CCompoundUnit>& ResistanceUnit,
		const std::shared_ptr<CCompoundUnit>& CapacitanceUnit,
		const std::shared_ptr<CCompoundUnit>& InductanceUnit);

	virtual void GetBaseUnits(std::shared_ptr<CCompoundUnit>& PotentialUnit,
		std::shared_ptr<CCompoundUnit>& FluxUnit,
		std::shared_ptr<CCompoundUnit>& QuantityUnit,
		std::shared_ptr<CCompoundUnit>& ResistanceUnit,
		std::shared_ptr<CCompoundUnit>& CapacitanceUnit,
		std::shared_ptr<CCompoundUnit>& InductanceUnit);

	// Nodes //

	virtual SECircuitNode* CreateNode();
	virtual SECircuitNode* CreateNode(const std::string& name);
	virtual SECircuitNode* CreateNode(const std::string& name, int eID);	

	virtual void AddNode(SECircuitNode* node);
	virtual void RemoveNode(SECircuitNode* node);
	virtual SECircuitNode* GetNode(int eID);
	virtual SECircuitNode* GetNode(const std::string& name);

	virtual bool HasNodes();	
	virtual std::vector<SECircuitNode*>* GetNodes();
	virtual void SetNodes(std::vector<SECircuitNode*> Nodes);
	
	// Paths //

	virtual SECircuitPath* CreatePath(SECircuitNode* src, SECircuitNode* tgt);
	virtual SECircuitPath* CreatePath(const std::string& name, SECircuitNode* src, SECircuitNode* tgt);
	virtual SECircuitPath* CreatePath(const std::string& name, int eID, SECircuitNode* src, SECircuitNode* tgt);
	
	virtual void AddPath(SECircuitPath* path);		
	virtual SECircuitPath* GetPath(int eID);
	virtual SECircuitPath* GetPath(const std::string& path);
	virtual void RemovePath(SECircuitPath* path);
	
	virtual bool HasPaths();
	virtual std::vector<SECircuitPath*>* GetPaths();
	virtual void SetPaths(std::vector<SECircuitPath*> Paths);
	
	// Volumes
	void CalculateTotalVolume(SEScalarVolume& volume);
	void CalculateNextTotalVolume(SEScalarVolume& volume);
	void VolumesToNodes();
	void VolumesToPaths();

	//Combining Circuits
	void CombineCircuits(SECircuit* MasterCircuit, SECircuit* SlaveCircuit);

	int GetNodeIndex(SECircuitNode* node);

    std::vector<SECircuitPath*> GetValvePaths();
	std::vector<SECircuitPath*> GetPolarizedElementPaths();
    std::vector<SECircuitPath*> GetNonPolarizedValvePaths();

protected:

	void Unload(CDM::CircuitData& data);

	SECircuitContainer* m_Container;

	// TODO support Mappings on a SECircuit as well
	SECircuitNode*                   m_ReferenceNode;
	std::vector<SECircuitNode*>      m_Nodes;
	std::vector<SECircuitPath*>      m_Paths;
	CDM::enumCircuitModelType::value m_ModelType;

	// Default Units
	std::shared_ptr<CCompoundUnit> m_PotentialUnit;
	std::shared_ptr<CCompoundUnit> m_FluxUnit;
	std::shared_ptr<CCompoundUnit> m_QuantityUnit;
	std::shared_ptr<CCompoundUnit> m_ResistanceUnit;
	std::shared_ptr<CCompoundUnit> m_CapacitanceUnit;
	std::shared_ptr<CCompoundUnit> m_InductanceUnit;

	void PrintState();
	void PrintSubstanceValues(std::vector<SESubstance*>* vSubstances);

	std::stringstream m_sError;

	// Get the paths that have a give node as target, and as a source
	// We will cache this data into a map, so we don't have to analyze the circuit each call
	typedef std::map<SECircuitNode*, std::vector<SECircuitPath*>*> Node2PathsMap;
	Node2PathsMap m_TargetPathMap;
	Node2PathsMap m_SourcePathMap;

	void CacheNodeIndex();
	void CachePolarizedElementPaths();
	void CacheValvePaths();

	typedef std::map<SECircuitNode*, int> NodeIndexMap;
	NodeIndexMap m_NodeIndex;

	std::vector<SECircuitPath*> m_vPolarizedElementPaths;
	std::vector<SECircuitPath*> m_vValvePaths;
	bool m_bInitialized;
};