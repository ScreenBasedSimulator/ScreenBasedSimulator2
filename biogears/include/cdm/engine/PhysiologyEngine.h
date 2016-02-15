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
class SEScenario;
class SEEventHandler;

class SEPatient;
class SEPatientAssessment;

class SECondition;

class SEEnvironment;

class SEAnatomyCompartments;

class SEAction;

class SESubstanceManager;
class SEBloodChemistrySystem;
class SECardiovascularSystem;
class SEEndocrineSystem;
class SEEnergySystem;
class SERenalSystem;
class SEGastrointestinalSystem;
class SERespiratorySystem;
class SEDrugSystem;

class SEAnesthesiaMachine;
class SEAnesthesiaMachineCompartments;
class SEInhaler;
class SEInhalerCompartments;
class SEElectroCardioGram;

class PhysiologyEngineTrack;
class CCompoundUnit;

class SEScenarioCustomExec;

#include "bind/enumAnatomy.hxx"
#include "bind/enumAnesthesiaMachine.hxx"

/** 
 * @brief
 * Base exception class that all CDM classes throw when an error occurs
 */
struct PhysiologyEngineException : public CommonDataModelException
{
	PhysiologyEngineException()
		: CommonDataModelException( "Physiology Engine Error" ) {}

	PhysiologyEngineException(const std::string& _Message)
		: CommonDataModelException(_Message) {}
};

class DLL_DECL PhysiologyEngine
{
public:
	virtual ~PhysiologyEngine() {}

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// This will set the current time back to 0, and ready the engine to start over
	/// with everthing reinitialized. 
	/// Input data, like the patient file, will be kept
	//--------------------------------------------------------------------------------------------------
	virtual void Reset() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// This will reinitialize/nullptr out ALL data associated with the engine
	/// Including inputs like the patient file, substances etc
	//--------------------------------------------------------------------------------------------------
	virtual void Clear() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Check to see that the engine has been configured and set up properly
	//--------------------------------------------------------------------------------------------------
	virtual bool IsValid() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Retrieve the Logger associated with this engine
	//--------------------------------------------------------------------------------------------------
	virtual Logger* GetLogger() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Retrieve the PhysiologyEngineTrack associated with tracking data from this engine to a file
	//--------------------------------------------------------------------------------------------------
	virtual PhysiologyEngineTrack* GetEngineTrack() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// locates the xml patient file and reads in the values. 
	///
	/// This will create an engine that you can send instructions (patient,actions,conditions) to dynamically.
	/// The return value will indicate success failure of the creation of the engine.  
	/// Some combinations of patients and conditions may prevent the engine from stabilizing
	///
	//--------------------------------------------------------------------------------------------------
	virtual bool InitializeEngine(const std::string& patientFile, const std::vector<const SECondition*>* conditions = nullptr) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	///
	/// This will create an engine that you can send instructions (patient,actions,conditions) to dynamically.
	/// The return value will indicate success failure of the creation of the engine.  
	/// Some combinations of patients and conditions may prevent the engine from stabilizing
	///
	//--------------------------------------------------------------------------------------------------
	virtual bool InitializeEngine(const SEPatient& patient, const std::vector<const SECondition*>* conditions = nullptr) = 0;
	
	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// returns the engine time step that is used when advancing time. 
	///
	//--------------------------------------------------------------------------------------------------
	virtual double GetTimeStep(const std::shared_ptr<CCompoundUnit>& unit) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// returns the current internal engine time. 
	///
	//--------------------------------------------------------------------------------------------------
	virtual double GetEngineTime(const std::shared_ptr<CCompoundUnit>& unit) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// returns the current scenario time. 
	/// The engine may run a certain time to get to a steady state,
	//  this does not account for that time, the scenario starts from steady state
	///
	//--------------------------------------------------------------------------------------------------
	virtual double GetScenarioTime(const std::shared_ptr<CCompoundUnit>& unit) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// executes one pass through the time loop of the engine at the fixed timestep
	///
	/// Events, errors, and warning as are logged to file not errors are returned
	/// through the API at this time. Under some unstable conditions or error states the engine enters a 
	/// frozen state. In this state the engine does not execute the time loop just returns from the beginning
	/// of the function. The call \ref IsFrozen is available to query the state of the engine.
	///
	//--------------------------------------------------------------------------------------------------
	virtual void AdvanceModelTime() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// executes time loop of the engine beginning at the current time
	///  and running for the duration specified in the call at the fixed timestep
	///
	/// Events, errors, and warning as are logged to file not errors are returned
	/// through the API at this time. Under some unstable conditions or error states the engine enters a 
	/// frozen state. In this state the engine does not execute the time loop just returns from the beginning
	/// of the function. The call \ref IsFrozen is available to query the state of the engine.
	///
	//--------------------------------------------------------------------------------------------------
	virtual void AdvanceModelTime(double time, const std::shared_ptr<CCompoundUnit>& unit) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Execute the provided action.
	/// true will be returned if the engine supports the action
	/// false will be returned if the engine does not support the action
	///
	//--------------------------------------------------------------------------------------------------
	virtual bool ProcessAction(const SEAction& action) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Retrieves the associated substance manager.
	///
	//--------------------------------------------------------------------------------------------------
	virtual SESubstanceManager& GetSubstanceManager() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Add a callback object that will be called whenever a pateint or anesthesia machine event changes state
	//--------------------------------------------------------------------------------------------------
	virtual void SetEventHandler(SEEventHandler* handler) = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the patient object used by the engine 
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEPatient& GetPatient() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Determines the assessment type and fills the data object with current data. 
	///
	/// Assessments can be queried at any point in the calculation and as many times are desired. 
	///  (Link the to Assessment objects descriptions).
	///
	//--------------------------------------------------------------------------------------------------
	virtual bool GetPatientAssessment(SEPatientAssessment& assessment) = 0; 

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the environment object used by the engine 
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEEnvironment* GetEnvironment() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief	
	/// Retrieves anatomical organs that contains such data as:
	/// flows, pressure, volume as well as substance mass, concentration, volumes and volume fractions.
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEAnatomyCompartments* GetAnatomyCompartments() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Blood Chemistry System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEBloodChemistrySystem* GetBloodChemistrySystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Cardiovascular System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SECardiovascularSystem* GetCardiovascularSystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Endocrine System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEEndocrineSystem* GetEndocrineSystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Energy System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEEnergySystem* GetEnergySystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Renal System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SERenalSystem* GetRenalSystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Gastrointestinal System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEGastrointestinalSystem* GetGastrointestinalSystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Respiratory System
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SERespiratorySystem* GetRespiratorySystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the drug system	
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEDrugSystem* GetDrugSystem() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Anesthesia machine
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEAnesthesiaMachine* GetAnesthesiaMachine() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Retrieves the anesthesia machine compartments, providing such data as:
	/// flows, pressure, volume as well as substance volumes and volume fractions.
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEAnesthesiaMachineCompartments* GetAnesthesiaMachineCompartments() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Electrocardiogram machine
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEElectroCardioGram* GetElectroCardioGram() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Returns the current state of the Inhaler
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEInhaler* GetInhaler() = 0;

	//--------------------------------------------------------------------------------------------------
	/// \brief
	/// Retrieves the inhaler compartments, providing such data as:
	/// flows, pressure, volume as well as substance volumes and volume fractions.
	///
	//--------------------------------------------------------------------------------------------------
	virtual const SEInhalerCompartments* GetInhalerCompartments() = 0;
};
