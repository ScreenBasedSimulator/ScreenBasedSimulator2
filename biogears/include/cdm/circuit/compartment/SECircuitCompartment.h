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
#include "compartment/SECompartment.h"
#include "circuit/SECircuitNode.h"
#include "circuit/SECircuitPath.h"

template <typename CompartmentEnumValue>
class SECircuitCompartment : public virtual SECompartment<CompartmentEnumValue>, protected Loggable
{
public:
	
	SECircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext);
	virtual ~SECircuitCompartment();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values
	virtual void FixUp(); //analyze and cache for optimization

	virtual CompartmentEnumValue GetType(){ return m_Type; }

	virtual void SetPrimaryNode(SECircuitNode& node);
	virtual SECircuitNode* GetPrimaryNode() { return m_PrimaryNode; }

	virtual void AddNode(SECircuitNode& node);
	virtual const std::vector<SECircuitNode*>& GetNodes(){ return m_Nodes; }
	
	virtual void AddPath(SECircuitPath& path);	
	virtual const std::vector<SECircuitPath*>& GetPaths(){ return m_Paths.m_AllPaths; }

protected:
	CompartmentEnumValue	                m_Type;
	const bool&                             m_GetNext;//true will get next, false will get current from circuit
	SECircuitNode*                          m_PrimaryNode;
	SECircuitCompartmentPaths               m_Paths;
	std::vector<SECircuitNode*>             m_Nodes;
	std::vector<SECircuitNode*>             m_allNodes;//Even nodes without volume
	const GeneralMath&                      m_math;

	std::stringstream m_ss;
};
#include "circuit/compartment/SECircuitCompartment.inl"