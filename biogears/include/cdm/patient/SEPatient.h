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
class SEEventHandler;
class Serializer;
class SENutrition;
CDM_BIND_DECL(PatientData)
#include "bind/enumPatientEvent.hxx"
#include "bind/enumGender.hxx"

class DLL_DECL SEPatient : public Loggable
{
public:

	SEPatient(Logger* logger);
	virtual ~SEPatient();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	virtual void Copy(const SEPatient& from);

	bool Load(const CDM::PatientData& in);
	std::unique_ptr<CDM::PatientData> Unload() const;
protected:
	void Unload(CDM::PatientData& data) const;
public:
	bool LoadPatientFile(const std::string& patientFile, Serializer& serlializer);

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual void SetEvent(CDM::enumPatientEvent::value type, bool active, const SEScalarTime& time);
	virtual bool IsEventActive(CDM::enumPatientEvent::value state) const;
	/** @name ForwardEvents
	 *  @brief - Set a callback class to invoke when any event changes
	 *  @details - Note that the handler callback can and will be called in the middle of a time step
	 *             So system and compartment objects may not be completely up to date when called.
	 *             Use the PhysiologyEngineInterface::SetEventHandler to ensure that all engine 
	 *             data is up to date at the time the callback is invoked
	 */
	virtual void ForwardEvents(SEEventHandler* handler) const;
	
	virtual std::string GetName() const;
	virtual void SetName(const std::string& name);
	virtual bool HasName() const;
	virtual void InvalidateName();

	virtual CDM::enumGender::value GetGender() const;
	virtual void SetGender(CDM::enumGender::value gender);
	virtual bool HasGender() const;
	virtual void InvalidateGender();
	
	virtual bool HasAge() const;
	virtual SEScalarTime& GetAge();
	virtual double GetAge(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasWeight() const;
	virtual SEScalarMass& GetWeight();
	virtual double GetWeight(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasHeight() const;
	virtual SEScalarLength& GetHeight();
	virtual double GetHeight(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasBasalMetabolicRate() const;
	virtual SEScalarPower& GetBasalMetabolicRate();
	virtual double GetBasalMetabolicRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasBodyFatFraction() const;
	virtual SEScalarFraction& GetBodyFatFraction();
	virtual double GetBodyFatFraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCarinaToTeethDistance() const;
	virtual SEScalarLength& GetCarinaToTeethDistance();
	virtual double GetCarinaToTeethDistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCentralControllerCO2PressureSetPoint() const;
	virtual SEScalarPressure& GetCentralControllerCO2PressureSetPoint();
	virtual double GetCentralControllerCO2PressureSetPoint(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasDiastolicArterialPressureBaseline() const;
	virtual SEScalarPressure& GetDiastolicArterialPressureBaseline();
	virtual double GetDiastolicArterialPressureBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasExpiratoryReserveVolume() const;
	virtual SEScalarVolume& GetExpiratoryReserveVolume();
	virtual double GetExpiratoryReserveVolume(const std::shared_ptr<CCompoundUnit>& unit) const;
    
	virtual bool HasFunctionalResidualCapacity() const;
	virtual SEScalarVolume& GetFunctionalResidualCapacity();
	virtual double GetFunctionalResidualCapacity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasHeartRateBaseline() const;
	virtual SEScalarFrequency& GetHeartRateBaseline();
	virtual double GetHeartRateBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasHeartRateMaximum() const;
	virtual SEScalarFrequency& GetHeartRateMaximum();
	virtual double GetHeartRateMaximum(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasHeartRateMinimum() const;
	virtual SEScalarFrequency& GetHeartRateMinimum();
	virtual double GetHeartRateMinimum(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasInspiratoryCapacity() const;
	virtual SEScalarVolume& GetInspiratoryCapacity();
	virtual double GetInspiratoryCapacity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasInspiratoryReserveVolume() const;
	virtual SEScalarVolume& GetInspiratoryReserveVolume();
	virtual double GetInspiratoryReserveVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftHeartElastanceMaximum() const;
	virtual SEScalarFlowElastance& GetLeftHeartElastanceMaximum();
	virtual double GetLeftHeartElastanceMaximum(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftHeartElastanceMinimum() const;
	virtual SEScalarFlowElastance& GetLeftHeartElastanceMinimum();
	virtual double GetLeftHeartElastanceMinimum(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasMeanArterialPressureBaseline() const;
	virtual SEScalarPressure& GetMeanArterialPressureBaseline();
	virtual double GetMeanArterialPressureBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;
		
	virtual bool HasPeripheralControllerCO2PressureSetPoint() const;
	virtual SEScalarPressure& GetPeripheralControllerCO2PressureSetPoint();
	virtual double GetPeripheralControllerCO2PressureSetPoint(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasPulmonaryVentilationRateMaximum() const;
	virtual SEScalarVolumePerTime& GetPulmonaryVentilationRateMaximum();
	virtual double GetPulmonaryVentilationRateMaximum(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasResidualVolume() const;
	virtual SEScalarVolume& GetResidualVolume();
	virtual double GetResidualVolume(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasRespirationRateBaseline() const;
	virtual SEScalarFrequency& GetRespirationRateBaseline();
	virtual double GetRespirationRateBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightHeartElastanceMaximum() const;
	virtual SEScalarFlowElastance& GetRightHeartElastanceMaximum();
	virtual double GetRightHeartElastanceMaximum(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightHeartElastanceMinimum() const;
	virtual SEScalarFlowElastance& GetRightHeartElastanceMinimum();
	virtual double GetRightHeartElastanceMinimum(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasRightLungRatio() const;
	virtual SEScalarFraction& GetRightLungRatio();
	virtual double GetRightLungRatio() const;

	virtual bool HasSkinSurfaceArea() const;
	virtual SEScalarArea& GetSkinSurfaceArea();
	virtual double GetSkinSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasSystolicArterialPressureBaseline() const;
	virtual SEScalarPressure& GetSystolicArterialPressureBaseline();
	virtual double GetSystolicArterialPressureBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTidalVolumeBaseline() const;
	virtual SEScalarVolume& GetTidalVolumeBaseline();
	virtual double GetTidalVolumeBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasTotalBloodVolumeBaseline() const;
	virtual SEScalarVolume& GetTotalBloodVolumeBaseline();
	virtual double GetTotalBloodVolumeBaseline(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasTotalLungCapacity() const;
	virtual SEScalarVolume& GetTotalLungCapacity();
	virtual double GetTotalLungCapacity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVitalCapacity() const;
	virtual SEScalarVolume& GetVitalCapacity();
	virtual double GetVitalCapacity(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	std::stringstream          m_ss;
	mutable SEEventHandler*    m_EventHandler;
	std::map<CDM::enumPatientEvent::value, bool> m_EventState;	

	std::string                m_Name;
	CDM::enumGender::value     m_Gender;
	SEScalarTime*              m_Age;
	SEScalarMass*              m_Weight;
	SEScalarLength*            m_Height;
							   
	SEScalarPower*			   m_BasalMetabolicRate;
	SEScalarFraction*		   m_BodyFatFraction;
	SEScalarLength*            m_CarinaToTeethDistance;
	SEScalarPressure*          m_CentralControllerCO2PressureSetPoint;
	SEScalarPressure*          m_DiastolicArterialPressureBaseline;
	SEScalarVolume*            m_ExpiratoryReserveVolume;
	SEScalarVolume*            m_FunctionalResidualCapacity;
	SEScalarFrequency*         m_HeartRateBaseline;
	SEScalarFrequency*         m_HeartRateMaximum;
	SEScalarFrequency*         m_HeartRateMinimum;
	SEScalarVolume*            m_InspiratoryCapacity;
	SEScalarVolume*            m_InspiratoryReserveVolume;
	SEScalarFlowElastance*	   m_LeftHeartElastanceMaximum;
	SEScalarFlowElastance*	   m_LeftHeartElastanceMinimum;
	SEScalarPressure*          m_MeanArterialPressureBaseline;
	SEScalarPressure*          m_PeripheralControllerCO2PressureSetPoint;
	SEScalarVolumePerTime*	   m_PulmonaryVentilationRateMaximum;
	SEScalarVolume*            m_ResidualVolume;
	SEScalarFrequency*         m_RespirationRateBaseline;
	SEScalarFlowElastance*	   m_RightHeartElastanceMaximum;
	SEScalarFlowElastance*	   m_RightHeartElastanceMinimum;
	SEScalarFraction*          m_RightLungRatio;	
	SEScalarArea*			   m_SkinSurfaceArea;
	SEScalarPressure*		   m_SystolicArterialPressureBaseline;
	SEScalarVolume*			   m_TidalVolumeBaseline;
	SEScalarVolume*            m_TotalBloodVolumeBaseline;
	SEScalarVolume*            m_TotalLungCapacity;
	SEScalarVolume*            m_VitalCapacity;
};