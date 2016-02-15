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

#include "bind/enumAnatomy.hxx"
#include "bind/enumAnesthesiaMachine.hxx"
#include "bind/enumInhaler.hxx"
#include "properties/SEScalar.h"
#include "compartment/SEGasCompartment.h"
#include "compartment/SEGasCompartmentSubstanceQuantity.h"
#include "compartment/SELiquidCompartment.h"
#include "compartment/SELiquidCompartmentSubstanceQuantity.h"
#include "compartment/SETissueCompartment.h"
#include "compartment/SETissueCompartmentSubstanceQuantity.h"

#include "utils/DataTrack.h"
class SESystem; 
class SEDataRequest;
class PhysiologyEngine;

enum class CompartmentUpdate {None,
							  InFlow, OutFlow,
                              Volume,TissueVolume,ExtravascularVolume,
							  VolumeFraction,
                              Mass, pH,
							  Concentration, TissueConcentration, ExtravascularConcentration,
                              Molarity, TissueMolarity, ExtravascularMolarity,
                              PartialPressure, ExtravascularPartialPressure,
                              Saturation, ExtravascularSaturation};
class SEDataRequestScalar
{
public:
	SEDataRequestScalar()
	{
		Heading.clear();
		Scalar = nullptr;

		UpdateProperty = CompartmentUpdate::None;
		AnesthesiaCmpt = nullptr;
		AnesthesiaSubstance = nullptr;
        InhalerCmpt = nullptr;
		InhalerSubstance = nullptr;
		PulmonaryCmpt = nullptr;
		PulmonarySubstance = nullptr;
		VascularCmpt = nullptr;
		VascularSubstance = nullptr;
		TissueCmpt = nullptr;
		TissueSubstance = nullptr;
	}
	SEDataRequestScalar(const std::string& name, const SEScalar& scalar)
	{
		Heading = name;
		Scalar  = &scalar;
	}
	void UpdateScalar();

	std::string     Heading;
	const SEScalar* Scalar;

	// Compartment related variables
	CompartmentUpdate                                      UpdateProperty;
	SEGasCompartment<CDM::enumAnesthesiaMachine::value>*   AnesthesiaCmpt;
	SEGasCompartmentSubstanceQuantity*                     AnesthesiaSubstance;
    SEGasCompartment<CDM::enumInhaler::value>*             InhalerCmpt;
    SEGasCompartmentSubstanceQuantity*                     InhalerSubstance;
	SEGasCompartment<CDM::enumAnatomy::value>*             PulmonaryCmpt;
	SEGasCompartmentSubstanceQuantity*                     PulmonarySubstance;
	SELiquidCompartment<CDM::enumAnatomy::value>*          VascularCmpt;
	SELiquidCompartmentSubstanceQuantity*                  VascularSubstance;
	SETissueCompartment<CDM::enumAnatomy::value>*          TissueCmpt;
	SETissueCompartmentSubstanceQuantity*                  TissueSubstance;
};

class DLL_DECL PhysiologyEngineTrack : public Loggable
{
public:
	PhysiologyEngineTrack(PhysiologyEngine& engine);
	virtual ~PhysiologyEngineTrack();
		
	DataTrack& GetDataTrack();
	std::string GetResultFileName(){ return m_ResultsFile; }

	void ConnectRequest(SEDataRequest& dr, SEDataRequestScalar& ds);

	virtual void RequestData(const std::vector<SEDataRequest*>& requests, const std::string& resultsFile);

	virtual void TrackData(double currentTime_s);
	virtual void PullData();
	virtual void ProcessRequest(SEDataRequest& dr);
	
protected:

	PhysiologyEngine&            m_Engine;
	std::vector<SEDataRequest*>  m_Requests;
	
	DataTrack                    m_DataTrack;

	std::vector<SESystem*>       m_PhysiologySystems;

	std::vector<SESystem*>       m_EquipmentSystems;

	std::stringstream                             m_ss;
	std::string                                   m_ResultsFile;
	std::ofstream                                 m_ResultsStream;		
	std::map<const SEDataRequest*,SEDataRequestScalar*> m_Request2Scalar;
};