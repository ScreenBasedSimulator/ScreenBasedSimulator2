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
#include "Eigen/Core"
#include "utils/TimingProfile.h"
#include "bind/enumCircuitModelType.hxx"
#include "bind/enumOpenClosed.hxx"
class SECircuit;
class SECircuitNode;
class SECircuitPath;
class SESubstance;
class CCompoundUnit;
CDM_BIND_DECL(CircuitCalculatorData)


class DLL_DECL SECircuitCalculator : public Loggable
{
public:

	SECircuitCalculator(Logger* logger);
	virtual ~SECircuitCalculator();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	void StateChange(SECircuit* Circuit);

	bool Load(const CDM::CircuitCalculatorData& in);
	std::unique_ptr<CDM::CircuitCalculatorData> Unload();

	void SetTimeStep(SEScalarTime* TimeStep);
	SEScalarTime* GetTimeStep();

	// Analysis of the Circuit dynamics
	void Process(SECircuit* Circuit);
	void PostProcess(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances=nullptr);

	static void PostProcessNode(SECircuitNode* Node, CDM::enumCircuitModelType::value ModelType, const std::vector<SESubstance*>* vSubstances = nullptr);
	static void PostProcessPath(SECircuitPath* Path, CDM::enumCircuitModelType::value ModelType);

protected:
	void Unload(CDM::CircuitCalculatorData& data);

	SECircuit*			m_Circuit;
	SEScalarTime*       m_TimeStep;
	std::stringstream	m_sError;
	TimingProfile		m_timer;

	SECircuitNode*                   m_ReferenceNode;
	std::vector<SECircuitNode*>*     m_Nodes;
	std::vector<SECircuitPath*>*     m_Paths;
	CDM::enumCircuitModelType::value m_ModelType;

	void PrintState();
	void PrintSubstances(std::vector<SESubstance*>* vSubstances);

	// Generalized Circuit Math //
	void ParseIn();
	void ParseOut();
	void Solve();
	void CalculateFluxes();
	void CalculatePotentials();
	void CalculateQuantities();

	void CheckCircuitSettings();
	void CheckNodeValues();
	void CheckPathElements();

	// Valve Support
	void CacheValvePaths();
	bool CheckAndModifyValves();
	void SetValveCombination(uint64_t dCombo);
	bool UniqueValveState();

	// Utility		
	int GetNodeIndex(SECircuitNode* node);
	int GetIndexWithoutRef(SECircuitNode* node);
	int GetPotentialSourceIndex(SECircuitPath* path);

	// Setup the Maths
	void AddToKnownVector(SECircuitNode* KCLAnalysisNode, double dValue);
	void AddToJacobianMatrix(SECircuitNode* KCLAnalysisNode, SECircuitNode* VariableNode, double dValue);
	void AddToJacobianMatrix(SECircuitNode* KCLAnalysisNode, SECircuitPath* VariablePath, double dValue);
	void PopulateJacobianMatrix(SECircuitNode* KCLAnalysisNode, SECircuitPath* CurrentPath, double dMultiplier, bool bSource=false);

    uint64_t GetCurrentValveState();
    bool FindAndFlipFirstFailingValve(const std::vector<SECircuitPath*> paths, std::function<bool(SECircuitPath*)> failureFunc);
    CDM::enumOpenClosed::value GetOppositeState(CDM::enumOpenClosed::value state);
    void FlipValveState(SECircuitPath* pPath);
    void SetPolarizedValveState(uint64_t state);

	//Ax=b
	Eigen::MatrixXd m_JacobianMatrix; //A
	Eigen::VectorXd m_VectorOfVariables; //x
	Eigen::VectorXd m_VectorOfKnowns; //b

	int  m_iRefIndex;
	int  m_iPressureSourceIndex;

	std::set<uint64_t> m_valveStates;
    std::vector<uint64_t> m_orderedPolarizedElementStates;
    unsigned int m_polarizedElementStateIndex = 0;

	std::vector<SECircuitPath*> m_vPolarizedElementPaths;
    std::vector<SECircuitPath*> m_vNonPolarizedElementPaths;
	std::vector<SECircuitPath*> m_vValvePaths;

	std::vector<SECircuitPath*> m_vPotentialSources;

	// Default Units
	void GetBaseUnits();

	std::shared_ptr<CCompoundUnit> m_PotentialUnit;
	std::shared_ptr<CCompoundUnit> m_FluxUnit;
	std::shared_ptr<CCompoundUnit> m_QuantityUnit;
	std::shared_ptr<CCompoundUnit> m_ResistanceUnit;
	std::shared_ptr<CCompoundUnit> m_CapacitanceUnit;
	std::shared_ptr<CCompoundUnit> m_InductanceUnit;

	virtual SECircuitNode* GetReferenceNode();
	virtual std::vector<SECircuitNode*>* GetNodes();
	virtual std::vector<SECircuitPath*>* GetPaths();
	void GetModelType();
	void GetCircuitParameters();

	void Validate();
};