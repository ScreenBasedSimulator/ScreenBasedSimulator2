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
#include "patient/assessments/SEPatientAssessment.h"
class SEPatient;
class SERespiratorySystem;
CDM_BIND_DECL(PulmonaryFunctionTestData)

class DLL_DECL SEPulmonaryFunctionTest : public SEPatientAssessment
{
public:

	SEPulmonaryFunctionTest(Logger* logger);
	virtual ~SEPulmonaryFunctionTest();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::PulmonaryFunctionTestData& in);
	std::unique_ptr<CDM::PulmonaryFunctionTestData> Unload();
protected:
	void Unload(CDM::PulmonaryFunctionTestData& data);
public:

	virtual int GetNumberOfPlotPoints(){ return m_NumberOfPlotPoints; }
	virtual void SetNumberOfPlotPoints(int n){ m_NumberOfPlotPoints = n; }

	virtual bool HasExpiratoryReserveVolume();
	virtual SEScalarVolume& GetExpiratoryReserveVolume();

	virtual bool HasForcedVitalCapacity();
	virtual SEScalarVolume&	GetForcedVitalCapacity();

	virtual bool HasForcedExpiratoryVolume();
	virtual SEScalarVolume&	GetForcedExpiratoryVolume();

	virtual bool HasForcedExpiratoryFlow();
	virtual SEScalarVolumePerTime&	GetForcedExpiratoryFlow();

	virtual bool HasFunctionalResidualCapacity();
	virtual SEScalarVolume&	GetFunctionalResidualCapacity();

	virtual bool HasInspiratoryCapacity();
	virtual SEScalarVolume&	GetInspiratoryCapacity();

	virtual bool HasInspiratoryReserveVolume();
	virtual SEScalarVolume& GetInspiratoryReserveVolume();

	virtual bool HasMaximumVoluntaryVentilation();
	virtual SEScalarVolume& GetMaximumVoluntaryVentilation();

	virtual bool HasPeakExpiratoryFlow();
	virtual SEScalarVolumePerTime&	GetPeakExpiratoryFlow();

	virtual bool HasResidualVolume();
	virtual SEScalarVolume&	GetResidualVolume();

	virtual bool HasSlowVitalCapacity();
	virtual SEScalarVolume&	GetSlowVitalCapacity();

	virtual bool HasTotalLungCapacity();
	virtual SEScalarVolume&	GetTotalLungCapacity();

	virtual bool HasVitalCapacity();
	virtual SEScalarVolume&	GetVitalCapacity();

	virtual bool HasLungVolumePlot();
	virtual SEFunctionTimeVsVolume&	GetLungVolumePlot();

protected:

	int                             m_NumberOfPlotPoints;
	SEScalarVolume*					m_ExpiratoryReserveVolume;
	SEScalarVolume*					m_ForcedVitalCapacity;
	SEScalarVolume*					m_ForcedExpiratoryVolume;
	SEScalarVolumePerTime*			m_ForcedExpiratoryFlow;
	SEScalarVolume*					m_FunctionalResidualCapacity;
	SEScalarVolume*					m_InspiratoryCapacity;
	SEScalarVolume*					m_InspiratoryReserveVolume;
	SEScalarVolume*					m_MaximumVoluntaryVentilation;
	SEScalarVolumePerTime*			m_PeakExpiratoryFlow;
	SEScalarVolume*					m_ResidualVolume;
	SEScalarVolume*					m_SlowVitalCapacity;
	SEScalarVolume*					m_TotalLungCapacity;
	SEScalarVolume*					m_VitalCapacity;
	
	SEFunctionTimeVsVolume*			m_LungVolumePlot;
};  