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
CDM_BIND_DECL(CardiovascularSystemData)
#include "bind/enumHeartRhythm.hxx"

class DLL_DECL SECardiovascularSystem : public SESystem
{
public:

	SECardiovascularSystem(Logger* logger);
	virtual ~SECardiovascularSystem();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);
	
	bool Load(const CDM::CardiovascularSystemData& in);
	std::unique_ptr<CDM::CardiovascularSystemData> Unload() const;
protected:
	void Unload(CDM::CardiovascularSystemData& data) const;
public:

	virtual void SetStartOfCardiacCycle(bool cycleStart){ m_StartOfCardiacCycle = cycleStart; }
	virtual bool IsStartOfCardiacCycle() const { return m_StartOfCardiacCycle; }

	virtual bool HasArterialPressure() const;
	virtual SEScalarPressure& GetArterialPressure();
	virtual double GetArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasBloodVolume() const;
	virtual SEScalarVolume& GetBloodVolume();
	virtual double GetBloodVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCardiacOutput() const;
	virtual SEScalarVolumePerTime& GetCardiacOutput();
	virtual double GetCardiacOutput(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCentralVenousPressure() const;
	virtual SEScalarPressure& GetCentralVenousPressure();
	virtual double GetCentralVenousPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasDiastolicArterialPressure() const;
	virtual SEScalarPressure& GetDiastolicArterialPressure();
	virtual double GetDiastolicArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasHeartEjectionFraction() const;
	virtual SEScalarFraction& GetHeartEjectionFraction();
	virtual double GetHeartEjectionFraction() const;

	virtual bool HasHeartRate() const;
	virtual SEScalarFrequency& GetHeartRate();
	virtual double GetHeartRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual CDM::enumHeartRhythm::value GetHeartRhythm() const;
	virtual void SetHeartRhythm(CDM::enumHeartRhythm::value Rhythm);
	virtual bool HasHeartRhythm() const;
	virtual void InvalidateHeartRhythm();

	virtual bool HasHeartStrokeVolume() const;
	virtual SEScalarVolume& GetHeartStrokeVolume();
	virtual double GetHeartStrokeVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMeanArterialPressure() const;
	virtual SEScalarPressure& GetMeanArterialPressure();
	virtual double GetMeanArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMeanArterialCarbonDioxidePartialPressure() const;
	virtual SEScalarPressure& GetMeanArterialCarbonDioxidePartialPressure();
	virtual double GetMeanArterialCarbonDioxidePartialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMeanArterialCarbonDioxidePartialPressureDelta() const;
	virtual SEScalarPressure& GetMeanArterialCarbonDioxidePartialPressureDelta();
	virtual double GetMeanArterialCarbonDioxidePartialPressureDelta(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasMeanCentralVenousPressure() const;
	virtual SEScalarPressure& GetMeanCentralVenousPressure();
	virtual double GetMeanCentralVenousPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMeanSkinFlow() const;
	virtual SEScalarVolumePerTime& GetMeanSkinFlow();
	virtual double GetMeanSkinFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryArterialPressure() const;
	virtual SEScalarPressure& GetPulmonaryArterialPressure();
	virtual double GetPulmonaryArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryCapillariesWedgePressure() const;
	virtual SEScalarPressure& GetPulmonaryCapillariesWedgePressure();
	virtual double GetPulmonaryCapillariesWedgePressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryDiastolicArterialPressure() const;
	virtual SEScalarPressure& GetPulmonaryDiastolicArterialPressure();
	virtual double GetPulmonaryDiastolicArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryMeanArterialPressure() const;
	virtual SEScalarPressure& GetPulmonaryMeanArterialPressure();
	virtual double GetPulmonaryMeanArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryMeanCapillaryFlow() const;
	virtual SEScalarVolumePerTime& GetPulmonaryMeanCapillaryFlow();
	virtual double GetPulmonaryMeanCapillaryFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryMeanShuntFlow() const;
	virtual SEScalarVolumePerTime& GetPulmonaryMeanShuntFlow();
	virtual double GetPulmonaryMeanShuntFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonarySystolicArterialPressure() const;
	virtual SEScalarPressure& GetPulmonarySystolicArterialPressure();
	virtual double GetPulmonarySystolicArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulsePressure() const;
	virtual SEScalarPressure& GetPulsePressure();
	virtual double GetPulsePressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSystolicArterialPressure() const;
	virtual SEScalarPressure& GetSystolicArterialPressure();
	virtual double GetSystolicArterialPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSystemicVascularResistance() const;
	virtual SEScalarFlowResistance& GetSystemicVascularResistance();
	virtual double GetSystemicVascularResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	bool						m_StartOfCardiacCycle;

	SEScalarPressure*           m_ArterialPressure;
	SEScalarVolume*             m_BloodVolume;
	SEScalarVolumePerTime*      m_CardiacOutput;
	SEScalarPressure*           m_CentralVenousPressure;
	SEScalarPressure*           m_DiastolicArterialPressure;
	SEScalarFraction*           m_HeartEjectionFraction;
	SEScalarFrequency*          m_HeartRate;
	CDM::enumHeartRhythm::value m_HeartRhythm;
	SEScalarVolume*             m_HeartStrokeVolume;	
	SEScalarPressure*           m_MeanArterialPressure;
	SEScalarPressure*           m_MeanArterialCarbonDioxidePartialPressure;
	SEScalarPressure*           m_MeanArterialCarbonDioxidePartialPressureDelta;
	SEScalarPressure*           m_MeanCentralVenousPressure;
	SEScalarVolumePerTime*      m_MeanSkinFlow;
	SEScalarPressure*           m_PulmonaryArterialPressure;
	SEScalarPressure*           m_PulmonaryCapillariesWedgePressure;
	SEScalarPressure*           m_PulmonaryDiastolicArterialPressure;
	SEScalarPressure*           m_PulmonaryMeanArterialPressure;
	SEScalarVolumePerTime*      m_PulmonaryMeanCapillaryFlow;
	SEScalarVolumePerTime*      m_PulmonaryMeanShuntFlow;
	SEScalarPressure*           m_PulmonarySystolicArterialPressure;
	SEScalarPressure*           m_PulsePressure;
	SEScalarPressure*           m_SystolicArterialPressure;
	SEScalarFlowResistance*     m_SystemicVascularResistance;
};