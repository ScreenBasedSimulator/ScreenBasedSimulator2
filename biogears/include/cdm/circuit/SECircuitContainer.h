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
class SECircuit;
class SECircuitNode;
class SECircuitPath;
class SEInterCircuitConnection;
CDM_BIND_DECL(CircuitContainerData)

class DLL_DECL SECircuitContainer : public Loggable
{
public:

	SECircuitContainer(Logger* logger);
	virtual ~SECircuitContainer();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::CircuitContainerData& in);
	std::unique_ptr<CDM::CircuitContainerData> Unload();
protected:
	void Unload(CDM::CircuitContainerData& data);

public:

	// TODO CreateCircuit should be re written to set child circuit parent to this

	virtual SECircuitNode* CreateNode();
	virtual void AddNode(SECircuitNode* node);
	virtual bool HasNode();
	virtual std::vector<SECircuitNode*>* GetNodes();
	virtual SECircuitNode* GetNode(int eID);
	virtual SECircuitNode* GetNode(const std::string& name);
	virtual void RemoveNode(SECircuitNode* node);

	virtual SECircuitPath* CreatePath(SECircuitNode* source, SECircuitNode* target);
	virtual void AddPath(SECircuitPath* path);
	virtual bool HasPath();
	virtual std::vector<SECircuitPath*>* GetPaths();
	virtual SECircuitPath* GetPath(int eID);
	virtual SECircuitPath* GetPath(const std::string& path);
	virtual void RemovePath(SECircuitPath* path);

	virtual SECircuit* CreateCircuit();
	virtual bool HasCircuit();
	virtual std::vector<SECircuit*>* GetCircuits();

	virtual SEInterCircuitConnection* CreateInterCircuitConnection();
	virtual bool HasInterCircuitConnections();
	virtual std::vector<SEInterCircuitConnection*>* GetInterCircuitConnections();

protected:

	std::vector<SECircuitNode*>               m_Nodes;
	std::vector<SECircuitPath*>               m_Paths;
	std::vector<SECircuit*>                   m_Circuits;
	std::vector<SEInterCircuitConnection*>	  m_InterCircuitConnections;
};