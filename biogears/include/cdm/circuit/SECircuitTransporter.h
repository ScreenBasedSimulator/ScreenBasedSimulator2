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
CDM_BIND_DECL(CircuitTransporterData)
class SECircuit;
class SECircuitNode;
class SECircuitPath;
class SESubstance;
class CCompoundUnit;
class GeneralMath;

#include "bind/enumOnOff.hxx"
#include "bind/enumCompartmentType.hxx"

class DLL_DECL SECircuitTransporter : public Loggable
{
public:
	
	SECircuitTransporter(const GeneralMath& math);
	virtual ~SECircuitTransporter();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::CircuitTransporterData& in);
	std::unique_ptr<CDM::CircuitTransporterData> Unload();
protected:
	void Unload(CDM::CircuitTransporterData& data);

public:
	// Transport of Substances across the circuit
	void   CalculateSubstanceTransport(SECircuit* Circuit, CDM::enumCompartmentType type, const std::vector<SESubstance*>* vSubstances, double timestep);
	double CalculateSubstanceTotalForACircuit(SECircuit* Circuit, const SESubstance& sub, const std::shared_ptr<CCompoundUnit>& unit);
	void   CalculateSubstanceVolumeFromMass(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances);
	void   CalculateMassFromSubstanceVolume(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances);
	void   CalculateNodalMasses(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances, double timestep);
	void   CalculateNodalSubstanceVolumes(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances, double timestep);
	void   CalculateNodalConcentration(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances);
	void   CalculateNodalVolumeFraction(SECircuit* Circuit, const std::vector<SESubstance*>* vSubstances);
	

	double CalculateMassFromPartialPressure(SESubstance* sub, SECircuitNode* node);
	void   CalculatePartialPressureInLiquid(SECircuit* circuit, const std::vector<SESubstance*>* vSubstances);
	void   CalculatePartialPressureInGas(SECircuit* circuit, const std::vector<SESubstance*>* vSubstances);

protected:

	void GetFlowPaths(SECircuit* Circuit, SECircuitNode* node, std::vector<SECircuitPath*>* paths, bool flowIn);// Paths flowing in to/out of provided node
	void GetPathsWithVolumeFraction(SECircuit* Circuit, std::vector<SECircuitPath*>* searchPaths, SESubstance* sub, std::vector<SECircuitPath*>& foundPaths, std::vector<SECircuitNode*>& foundNodes);
	void GetPathsWithConcentration(SECircuit* Circuit, std::vector<SECircuitPath*>* searchPaths, SESubstance* sub, std::vector<SECircuitPath*>& foundPaths, std::vector<SECircuitNode*>& foundNodes);

	const GeneralMath& m_math;
};
