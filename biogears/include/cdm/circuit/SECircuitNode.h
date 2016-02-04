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
class SECircuit;
class SESubstance;
class  SECircuitNodeSubstanceQuantity;
CDM_BIND_DECL(CircuitNodeData)
#include "bind/enumCircuitModelType.hxx"
#include "bind/enumCompartmentType.hxx"

class SECircuitCalculator;
class SEInterCircuitConnection;
class DLL_DECL SECircuitNode : public Loggable
{
friend SECircuit;
friend SECircuitCalculator;
friend SEInterCircuitConnection;
public:

	SECircuitNode(Logger* logger);
	virtual ~SECircuitNode();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::CircuitNodeData& in);
	std::unique_ptr<CDM::CircuitNodeData> Unload();
protected:
	void Unload(CDM::CircuitNodeData& data);

	/////////////////////
	// Potential Types //
	/////////////////////

	virtual bool HasPotential(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetPotential(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextPotential(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextPotential(CDM::enumCircuitModelType::value Type);


	////////////////////
	// Quantity Types //
	////////////////////

	virtual bool HasQuantity(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetQuantity(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextQuantity(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextQuantity(CDM::enumCircuitModelType::value Type);

	virtual bool HasQuantityBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetQuantityBaseline(CDM::enumCircuitModelType::value Type);

public:

	virtual unsigned int GetID();
	virtual void SetID(unsigned int value);
	virtual bool HasID();
	virtual void InvalidateID();

	virtual std::string GetName();
	virtual void SetName(const std::string& value);
	virtual bool HasName();
	virtual void InvalidateName();

	virtual bool HasResistanceEffectModifier();
	virtual SEScalar* GetResistanceEffectModifier();

	virtual void SetIsInterConnectedNode(bool);
	virtual bool GetIsInterConnectedNode();

	/////////////////////
	// Potential Types //
	/////////////////////

	virtual bool HasPressure();
	virtual SEScalarPressure* GetPressure();	
	virtual bool HasNextPressure();
	virtual SEScalarPressure* GetNextPressure();

	virtual bool HasTemperature();
	virtual SEScalarTemperature* GetTemperature();
	virtual bool HasNextTemperature();
	virtual SEScalarTemperature* GetNextTemperature();

	virtual bool HasVoltage();
	virtual SEScalarElectricPotential* GetVoltage();
	virtual bool HasNextVoltage();
	virtual SEScalarElectricPotential* GetNextVoltage();

	////////////////////
	// Quantity Types //
	////////////////////

	virtual bool HasVolume();
	virtual SEScalarVolume* GetVolume();	
	virtual bool HasNextVolume();
	virtual SEScalarVolume* GetNextVolume();
	virtual bool HasVolumeBaseline();
	virtual SEScalarVolume* GetVolumeBaseline();	
	virtual bool HasUnstressedVolume();
	virtual SEScalarVolume* GetUnstressedVolume();	

	virtual bool HasHeat();
	virtual SEScalarEnergy* GetHeat();
	virtual bool HasNextHeat();
	virtual SEScalarEnergy* GetNextHeat();
	virtual bool HasHeatBaseline();
	virtual SEScalarEnergy* GetHeatBaseline();

	virtual bool HasElectricCharge();
	virtual SEScalarElectricCharge* GetElectricCharge();
	virtual bool HasNextElectricCharge();
	virtual SEScalarElectricCharge* GetNextElectricCharge();
	virtual bool HasElectricChargeBaseline();
	virtual SEScalarElectricCharge* GetElectricChargeBaseline();

	//////////////
	// Tracking //
	//////////////

	virtual bool HasTissueConcentrationAcidicPhospohlipids();
	virtual SEScalarMassPerMass* GetTissueConcentrationAcidicPhospohlipids();

	virtual bool HasTissueToPlasmaAAGRatio();
	virtual SEScalar* GetTissueToPlasmaAAGRatio();

	virtual bool HasTissueToPlasmaAlbuminRatio();
	virtual SEScalar* GetTissueToPlasmaAlbuminRatio();

	virtual bool HasTissueToPlasmaLipoproteinRatio();
	virtual SEScalar* GetTissueToPlasmaLipoproteinRatio();

	virtual bool HasTissueVolume();
	virtual SEScalarVolume* GetTissueVolume();

	virtual bool HasVolumeFractionExtracellularWater();
	virtual SEScalarFraction* GetVolumeFractionExtracellularWater();

	virtual bool HasVolumeFractionIntracellularWater();
	virtual SEScalarFraction* GetVolumeFractionIntracellularWater();

	virtual bool HasVolumeFractionNeutralLipids();
	virtual SEScalarFraction* GetVolumeFractionNeutralLipids();

	virtual bool HasVolumeFractionNeutralPhospholipids();
	virtual SEScalarFraction* GetVolumeFractionNeutralPhospholipids();

	////////////////////////
	// Substance Tracking //
	////////////////////////

	bool HasSubstanceQuantities();
	bool HasSubstanceQuantity(SESubstance* substance);
	const std::vector<SECircuitNodeSubstanceQuantity*>* GetSubstanceQuantities();
	// This will create a SubstanceQuantity for this substance
	// If this compartment does not have a SubstanceQuantity for this substance already
	SECircuitNodeSubstanceQuantity* GetSubstanceQuantity(SESubstance* substance);
	void InitializeSubstanceQuantity(SESubstance* substance, CDM::enumCompartmentType type);
	void RemoveSubstanceQuantity(SESubstance* substance);

	void SetSubstanceMassFromPartialPressure(SESubstance* sub);
	void UpdateVolumeFraction(SESubstance* Sub);

protected:
	bool                       m_IsInterConnectedNode;
	unsigned int			   m_ID;
	std::string				   m_Name;

	SEScalar*				   m_ResistanceEffectModifier;

	/////////////////////
	// Potential Types //
	/////////////////////
	SEScalarPressure*		   m_Pressure;
	SEScalarPressure*		   m_NextPressure;
							   
	SEScalarTemperature*	   m_Temperature;
	SEScalarTemperature*	   m_NextTemperature;

	SEScalarElectricPotential* m_Voltage;
	SEScalarElectricPotential* m_NextVoltage;

	////////////////////
	// Quantity Types //
	////////////////////
	SEScalarVolume*			   m_Volume;
	SEScalarVolume*			   m_NextVolume;
	SEScalarVolume*			   m_VolumeBaseline;
	SEScalarVolume*			   m_UnstressedVolume;
						       
	SEScalarEnergy*			   m_Heat;
	SEScalarEnergy*			   m_NextHeat;
	SEScalarEnergy*			   m_HeatBaseline;
						    
	SEScalarElectricCharge*    m_ElectricCharge;
	SEScalarElectricCharge*    m_NextElectricCharge;
	SEScalarElectricCharge*    m_ElectricChargeBaseline;

	//////////////
	// Tracking //
	//////////////

	SEScalarMassPerMass*       m_TissueConcentrationAcidicPhospohlipids;
	SEScalar*                  m_TissueToPlasmaAAGRatio;
	SEScalar*                  m_TissueToPlasmaAlbuminRatio;
	SEScalar*                  m_TissueToPlasmaLipoproteinRatio;
	SEScalarVolume*	           m_TissueVolume;
	SEScalarFraction*          m_VolumeFractionExtracellularWater;
	SEScalarFraction*          m_VolumeFractionIntracellularWater;
	SEScalarFraction*          m_VolumeFractionNeutralLipids;
	SEScalarFraction*          m_VolumeFractionNeutralPhospholipids;

	std::vector<SECircuitNodeSubstanceQuantity*> m_SubstanceQuantities;
};