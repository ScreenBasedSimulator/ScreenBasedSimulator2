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

#include "stdafx.h"
#include "bind/enumAnatomy.hxx"
#include "circuit/compartment/SECircuitCompartment.h"
#include "circuit/SECircuitNode.h"
#include "circuit/SECircuitPath.h"

template <typename CompartmentEnumValue>
SECircuitCompartment<CompartmentEnumValue>::SECircuitCompartment(CompartmentEnumValue type, const GeneralMath& math, const bool& getNext) : Loggable(math.GetLogger()), m_math(math), m_GetNext(getNext)
{
	m_PrimaryNode = nullptr;
	m_Type = type;
}

template <typename CompartmentEnumValue>
SECircuitCompartment<CompartmentEnumValue>::~SECircuitCompartment()
{
	Clear();
}

template <typename CompartmentEnumValue>
void SECircuitCompartment<CompartmentEnumValue>::Clear()
{
	
}

template <typename CompartmentEnumValue>
void SECircuitCompartment<CompartmentEnumValue>::Reset()
{
	
}

template <typename CompartmentEnumValue>
void SECircuitCompartment<CompartmentEnumValue>::SetPrimaryNode(SECircuitNode& node)
{
	m_PrimaryNode = &node;
	AddNode(node);
}

template <typename CompartmentEnumValue>
void SECircuitCompartment<CompartmentEnumValue>::AddNode(SECircuitNode& node)
{
	if (std::find(m_allNodes.begin(), m_allNodes.end(), &node) == m_allNodes.end())
		m_allNodes.push_back(&node);
	if (!node.HasVolumeBaseline())
		return;// does not go in m_Nodes
	if (std::find(m_Nodes.begin(), m_Nodes.end(), &node) == m_Nodes.end())
		m_Nodes.push_back(&node);
}

template <typename CompartmentEnumValue>
void SECircuitCompartment<CompartmentEnumValue>::AddPath(SECircuitPath& path)
{
	if (std::find(m_Paths.m_AllPaths.begin(), m_Paths.m_AllPaths.end(), &path) == m_Paths.m_AllPaths.end())
		m_Paths.m_AllPaths.push_back(&path);
}

template <typename CompartmentEnumValue>
void SECircuitCompartment<CompartmentEnumValue>::FixUp()
{
	if (m_allNodes.size() == 1)
		SetPrimaryNode(*m_allNodes[0]);

	for (SECircuitPath* path : m_Paths.m_AllPaths)
	{
		bool hasSrc = std::find(m_allNodes.begin(), m_allNodes.end(), path->GetSourceNode()) != m_allNodes.end();
		bool hasTgt = std::find(m_allNodes.begin(), m_allNodes.end(), path->GetTargetNode()) != m_allNodes.end();
		if (hasSrc&&hasTgt)
		{
			m_Paths.m_InternalPaths.push_back(path);
			continue;
		}
		if (hasSrc&&!hasTgt)
		{
			m_Paths.m_OutgoingPaths.push_back(path);
			continue;
		}
		if (!hasSrc&&hasTgt)
		{
			m_Paths.m_IncomingPaths.push_back(path);
			continue;
		}
		else
		{
			if (m_Type != CDM::enumAnatomy::PulmonaryShunt &&
				m_Type != CDM::enumAnatomy::LeftPulmonaryShunt &&
				m_Type != CDM::enumAnatomy::RightPulmonaryShunt)
			{// Shunts are flow only
				m_ss << m_Type << " Compartment does not contain either node from " << path->GetName() << ", it's external to this compartment!";
				Warning(m_ss);
			}
		}
	}
}
