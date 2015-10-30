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
#include "system/SESystem.h"
class SEEventHandler;
class SESubstanceManager;
class SEAnesthesiaMachineChamber;
class SEAnesthesiaMachineOxygenBottle;
class SEAnesthesiaMachineConfiguration;
class Serializer;
CDM_BIND_DECL(AnesthesiaMachineData)
#include "bind/enumOnOff.hxx"
#include "bind/enumAnesthesiaMachineEvent.hxx"
#include "bind/enumAnesthesiaMachineOxygenSource.hxx"
#include "bind/enumAnesthesiaMachinePrimaryGas.hxx"

class DLL_DECL SEAnesthesiaMachine : public SESystem
{
protected:
	friend SEAnesthesiaMachineConfiguration;
public:

	SEAnesthesiaMachine(SESubstanceManager& substances);
	virtual ~SEAnesthesiaMachine();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	void Copy(const SEAnesthesiaMachine& from);
	void Merge(const SEAnesthesiaMachine& from);

	bool Load(const CDM::AnesthesiaMachineData& in);
	std::unique_ptr<CDM::AnesthesiaMachineData> Unload() const;
protected:
	void Unload(CDM::AnesthesiaMachineData& data) const;

	/** @name LoadFile
	*   @brief Clear and set contents to this file
	*/
	bool LoadFile(const std::string& file, const Serializer& serlializer);

	/** @name StateChange
	*   @brief - This method is called when ever there is a state change
	*            Specically a new file has been loaded, configuration action, or the system reset
	*            Engine specific methodology can then update their logic.
	*/
	virtual void StateChange(){};
	void ProcessConfiguration(const SEAnesthesiaMachineConfiguration& config);
public:

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual void SetEvent(CDM::enumAnesthesiaMachineEvent::value state, bool active, const SEScalarTime& time);
	virtual bool IsEventActive(CDM::enumAnesthesiaMachineEvent::value state) const;
	virtual void ForwardEvents(SEEventHandler* handler);

	virtual CDM::enumOnOff::value GetState() const;
	virtual void SetState(CDM::enumOnOff::value name);
	virtual bool HasState() const;
	virtual void InvalidateState();

	virtual bool HasInletFlow() const;
	virtual SEScalarVolumePerTime& GetInletFlow();
	virtual double GetInletFlow(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasInspiratoryExpiratoryRatio() const;
	virtual SEScalar& GetInspiratoryExpiratoryRatio();
	virtual double GetInspiratoryExpiratoryRatio() const;
		
	virtual bool HasOxygenFraction() const;
	virtual SEScalarFraction& GetOxygenFraction();
	virtual double GetOxygenFraction() const;

	virtual CDM::enumAnesthesiaMachineOxygenSource::value GetOxygenSource() const;
	virtual void SetOxygenSource(CDM::enumAnesthesiaMachineOxygenSource::value name);
	virtual bool HasOxygenSource() const;
	virtual void InvalidateOxygenSource();

	virtual bool HasPositiveEndExpiredPressure() const;
	virtual SEScalarPressure& GetPositiveEndExpiredPressure();
	virtual double GetPositiveEndExpiredPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual CDM::enumAnesthesiaMachinePrimaryGas::value GetPrimaryGas() const;
	virtual void SetPrimaryGas(CDM::enumAnesthesiaMachinePrimaryGas::value name);
	virtual bool HasPrimaryGas() const;
	virtual void InvalidatePrimaryGas();
	
	virtual bool HasRespiratoryRate() const;
	virtual SEScalarFrequency& GetRespiratoryRate();
	virtual double GetRespiratoryRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasReliefValvePressure() const;
	virtual SEScalarPressure& GetReliefValvePressure();
	virtual double GetReliefValvePressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual CDM::enumOnOff::value GetVentilatorMask() const;
	virtual void SetVentilatorMask(CDM::enumOnOff::value onOff);
	virtual bool HasVentilatorMask() const;
	virtual void InvalidateVentilatorMask();

	virtual bool HasVentilatorPressure() const;
	virtual SEScalarPressure& GetVentilatorPressure();
	virtual double GetVentilatorPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftChamber() const;
	virtual SEAnesthesiaMachineChamber& GetLeftChamber();
	virtual const SEAnesthesiaMachineChamber* GetLeftChamber() const;
	virtual void RemoveLeftChamber();

	virtual bool HasRightChamber() const;
	virtual SEAnesthesiaMachineChamber& GetRightChamber();
	virtual const SEAnesthesiaMachineChamber* GetRightChamber() const;
	virtual void RemoveRightChamber();

	virtual bool HasOxygenBottleOne() const;
	virtual SEAnesthesiaMachineOxygenBottle& GetOxygenBottleOne();
	virtual const SEAnesthesiaMachineOxygenBottle* GetOxygenBottleOne() const;
	virtual void RemoveOxygenBottleOne();

	virtual bool HasOxygenBottleTwo() const;
	virtual SEAnesthesiaMachineOxygenBottle& GetOxygenBottleTwo();
	virtual const SEAnesthesiaMachineOxygenBottle* GetOxygenBottleTwo() const;
	virtual void RemoveOxygenBottleTwo();

protected:

	std::stringstream m_ss;
	SEEventHandler*   m_EventHandler;
	std::map<CDM::enumAnesthesiaMachineEvent::value, bool> m_EventState;

	CDM::enumOnOff::value                           m_State;
	SEScalarVolumePerTime*							m_InletFlow;
	SEScalar*										m_InspiratoryExpiratoryRatio;
	SEScalarFraction*								m_OxygenFraction;
	CDM::enumAnesthesiaMachineOxygenSource::value	m_OxygenSource;
	SEScalarPressure*								m_PositiveEndExpiredPressure;
	CDM::enumAnesthesiaMachinePrimaryGas::value		m_PrimaryGas;
	SEScalarFrequency*								m_RespiratoryRate;
	SEScalarPressure*								m_ReliefValvePressure;

	CDM::enumOnOff::value                           m_VentilatorMask;
	SEScalarPressure*                               m_VentilatorPressure;

	SEAnesthesiaMachineChamber*	                    m_LeftChamber;
	SEAnesthesiaMachineChamber*	                    m_RightChamber;

	SEAnesthesiaMachineOxygenBottle*	            m_OxygenBottleOne;
	SEAnesthesiaMachineOxygenBottle*	            m_OxygenBottleTwo;

	SESubstanceManager&                             m_Substances;
};
