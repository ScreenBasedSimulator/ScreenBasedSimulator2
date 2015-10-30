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
class SESubstanceManager;
class SEAction;
#include "scenario/SEPatientActionCollection.h"
#include "scenario/SEAnesthesiaMachineActionCollection.h"
#include "scenario/SEEnvironmentActionCollection.h"
#include "scenario/SEInhalerActionCollection.h"

class DLL_DECL SEActionManager : public Loggable
{
public:

	SEActionManager(SESubstanceManager&);
	~SEActionManager();

	void Clear();
	void Reset();

	bool ProcessAction(const SEAction& action);

	bool HasActions() const;
	const std::vector<SEAction*>& GetActions() const { return m_Actions; }

	SEEnvironmentActionCollection& GetEnvironmentActions() { return m_EnvironmentActions; }
	SEPatientActionCollection& GetPatientActions() { return m_PatientActions; }
	SEAnesthesiaMachineActionCollection& GetAnesthesiaMachineActions() { return m_AnesthesiaMachineActions; }
	SEInhalerActionCollection& GetInhalerActions() { return m_InhalerActions; }

protected:

	std::vector<SEAction*>              m_Actions;
	SEEnvironmentActionCollection       m_EnvironmentActions;
	SEPatientActionCollection           m_PatientActions;
	SEAnesthesiaMachineActionCollection m_AnesthesiaMachineActions;
	SEInhalerActionCollection           m_InhalerActions;

	std::vector<std::unique_ptr<CDM::ActionData>> m_ProcessedActions;


	SESubstanceManager& m_Substances;

	std::stringstream m_ss;
};