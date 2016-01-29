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
CDM_BIND_DECL(AnatomyCompartmentsData)
#include "bind/enumAnatomy.hxx"
#include "bind/enumCompartmentType.hxx"
#include "../SEGasCompartment.h"
#include "../SELiquidCompartment.h"
#include "../SEThermalCompartment.h"
#include "../SETissueCompartment.h"

class SESubstanceAnatomyEffect;

using SEAnatomyCompartment        = SECompartment<CDM::enumAnatomy::value>;
using SEAnatomyGasCompartment     = SEGasCompartment<CDM::enumAnatomy::value>;
using SEAnatomyThermalCompartment = SEThermalCompartment<CDM::enumAnatomy::value>;
using SEAnatomyTissueCompartment  = SETissueCompartment<CDM::enumAnatomy::value>;
using SEAnatomyLiquidCompartment  = SELiquidCompartment<CDM::enumAnatomy::value>;

class DLL_DECL SEAnatomyCompartments
{
public:
	virtual ~SEAnatomyCompartments(){};

	virtual void Clear() = 0; //clear memory
	virtual void Reset() = 0; //reset values

	virtual bool Load(const CDM::AnatomyCompartmentsData& in) = 0;
	virtual std::unique_ptr<CDM::AnatomyCompartmentsData> Unload() const = 0;

	virtual SEAnatomyCompartment&              GetCompartment(CDM::enumAnatomy::value anatomy, CDM::enumCompartmentType type) = 0;

	virtual bool                               HasChymeCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual SEAnatomyLiquidCompartment&        GetChymeCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual const SEAnatomyLiquidCompartment*  GetChymeCompartment(CDM::enumAnatomy::value anatomy) const = 0;
	
	virtual bool                               HasPulmonaryCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual SEAnatomyGasCompartment&           GetPulmonaryCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual const SEAnatomyGasCompartment*     GetPulmonaryCompartment(CDM::enumAnatomy::value anatomy) const = 0;

	virtual bool                               HasTemperatureCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual SEAnatomyThermalCompartment&       GetTemperatureCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual const SEAnatomyThermalCompartment* GetTemperatureCompartment(CDM::enumAnatomy::value anatomy) const = 0;

	virtual bool                               HasTissueCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual SEAnatomyTissueCompartment&        GetTissueCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual const SEAnatomyTissueCompartment*  GetTissueCompartment(CDM::enumAnatomy::value anatomy) const = 0;

	virtual bool                               HasUrineCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual SEAnatomyLiquidCompartment&        GetUrineCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual const SEAnatomyLiquidCompartment*  GetUrineCompartment(CDM::enumAnatomy::value anatomy) const = 0;

	virtual bool                               HasVascularCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual SEAnatomyLiquidCompartment&        GetVascularCompartment(CDM::enumAnatomy::value anatomy) = 0;
	virtual const SEAnatomyLiquidCompartment*  GetVascularCompartment(CDM::enumAnatomy::value anatomy) const = 0;

	static void CalculatePerfusionLimitedDiffusion(SEAnatomyTissueCompartment& tissue, SEAnatomyLiquidCompartment& vascular, const SESubstanceAnatomyEffect& fx, const SESubstance& sub, double timestep_s);
	static void CalculatePermeabilityLimitedDiffusion(SEAnatomyTissueCompartment& tissue, SEAnatomyLiquidCompartment& vascular, const SESubstanceAnatomyEffect& fx, const SESubstance& sub, double timestep_s);
	static void CalculatePartialPressureGradientDiffusion(SEAnatomyGasCompartment& pulmonary, SEAnatomyLiquidCompartment& vascular, SESubstance& sub, double DiffusingCapacityO2_mLPers_mmHg, double timestep_s);
	static void CalculatePartialPressureGradientDiffusion(SEAnatomyLiquidCompartment& vascular, SEAnatomyTissueCompartment& tissue, SESubstance& sub, double DiffusingCapacityO2_mLPers_mmHg, double timestep_s);

	static void CalculateGenericClearance(double VolumeCleared_mL, SEAnatomyLiquidCompartment& cmpt, SESubstance& sub, SEScalarMass* cleared = nullptr);
	static void CalculateGenericClearance(double VolumeCleared_mL, SEAnatomyTissueCompartment& cmpt, SESubstance& sub, SEScalarMass* cleared = nullptr);
	static void CalculateGenericExcretion(double VascularFlow_mL_Per_s, SEAnatomyTissueCompartment& cmpt, SESubstance& sub, double FractionExcreted, double timestep_s, SEScalarMass* excreted = nullptr);
};
