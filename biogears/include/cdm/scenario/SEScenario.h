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
CDM_BIND_DECL(ScenarioData)
class SESubstanceManager;
class SEAction;
class SECondition;
class SEDataRequest;
class PhysiologyEngineConfiguration;

class DLL_DECL SEScenario : public Loggable
{
public:

	SEScenario(SESubstanceManager& substances);
	virtual ~SEScenario();
	
	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::ScenarioData& in);
	std::unique_ptr<CDM::ScenarioData> Unload() const;
protected:
	void Unload(CDM::ScenarioData& data)const;

public:
	bool LoadScenarioFile(const std::string& scenarioFile);
	bool IsValid() const;

	virtual std::string GetName() const;
	virtual void SetName(const std::string& name);
	virtual bool HasName() const;
	virtual void InvalidateName();

	virtual std::string GetDescription() const;
	virtual void SetDescription(const std::string& desc);
	virtual bool HasDescription() const;
	virtual void InvalidateDescription();

	virtual bool HasConfiguration() const;
	virtual PhysiologyEngineConfiguration* GetConfiguration() const;
	virtual void SetConfiguration(PhysiologyEngineConfiguration* config);

	virtual std::string GetPatientFile() const;
	virtual void SetPatientFile(const std::string& patientFile);
	virtual bool HasPatientFile() const;
	virtual void InvalidatePatientFile();

	virtual const std::vector<SEAction*>& GetActions() const;

	virtual const std::vector<SECondition*>& GetConditions() const;

	virtual const std::vector<SEDataRequest*>& GetRequestedData() const;

	virtual double GetSamplesPerSecond() const;

protected:
	std::string                    m_Name;
	std::string                    m_Description;
	bool                           m_myConfig; // my config to delete
	PhysiologyEngineConfiguration* m_Configuration;
	std::string                    m_PatientFile;
	std::vector<SEAction*>         m_Actions;
	std::vector<SECondition*>      m_Conditions;
	std::vector<SEDataRequest*>    m_RequestedData;
	double                         m_SamplesPerSecond;
	
	SESubstanceManager&      m_Substances;
};