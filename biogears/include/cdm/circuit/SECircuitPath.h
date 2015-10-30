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
class SECircuitNode;
CDM_BIND_DECL(CircuitPathData)
#include "bind/enumOpenClosed.hxx"
#include "bind/enumCircuitModelType.hxx"

class SECircuitPath;
class DLL_DECL SECircuitCompartmentPaths
{
public:
	std::vector<SECircuitPath*> m_IncomingPaths;
	std::vector<SECircuitPath*> m_OutgoingPaths;
	std::vector<SECircuitPath*> m_InternalPaths;
	std::vector<SECircuitPath*> m_AllPaths;
};

class SECircuitCalculator;
class SEInterCircuitConnection;
class DLL_DECL SECircuitPath : public Loggable
{
friend SECircuit;
friend SECircuitCalculator; 
friend SEInterCircuitConnection;
public:

	SECircuitPath(SECircuitNode& sourceNode, SECircuitNode& targetNode);
	virtual ~SECircuitPath();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::CircuitPathData& in);
	std::unique_ptr<CDM::CircuitPathData> Unload();

	void SetInterCircuitConnection(SEInterCircuitConnection* InterCircuitConnection);
	SEInterCircuitConnection* GetInterCircuitConnection();

protected:
	void Unload(CDM::CircuitPathData& data);

	//////////////////////
	// Resistance Types //
	//////////////////////

	virtual bool HasResistance(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetResistance(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextResistance(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextResistance(CDM::enumCircuitModelType::value Type);

	virtual bool HasResistanceBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetResistanceBaseline(CDM::enumCircuitModelType::value Type);

	///////////////////////
	// Capacitance Types //
	///////////////////////

	virtual bool HasCapacitance(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetCapacitance(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextCapacitance(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextCapacitance(CDM::enumCircuitModelType::value Type);

	virtual bool HasCapacitanceBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetCapacitanceBaseline(CDM::enumCircuitModelType::value Type);

	//////////////////////
	// Inductance Types //
	//////////////////////

	virtual bool HasInductance(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetInductance(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextInductance(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextInductance(CDM::enumCircuitModelType::value Type);

	virtual bool HasInductanceBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetInductanceBaseline(CDM::enumCircuitModelType::value Type);

	////////////////
	// Flux Types //
	////////////////
	
	virtual bool HasFlux(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetFlux(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextFlux(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextFlux(CDM::enumCircuitModelType::value Type);

	virtual bool HasFluxBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetFluxBaseline(CDM::enumCircuitModelType::value Type);

	virtual bool HasFluxSource(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetFluxSource(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextFluxSource(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextFluxSource(CDM::enumCircuitModelType::value Type);

	virtual bool HasFluxSourceBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetFluxSourceBaseline(CDM::enumCircuitModelType::value Type);

	/////////////////////
	// Potential Types //
	/////////////////////

	virtual bool HasPotentialSource(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetPotentialSource(CDM::enumCircuitModelType::value Type);

	virtual bool HasNextPotentialSource(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetNextPotentialSource(CDM::enumCircuitModelType::value Type);

	virtual bool HasPotentialSourceBaseline(CDM::enumCircuitModelType::value Type);
	virtual SEScalar* GetPotentialSourceBaseline(CDM::enumCircuitModelType::value Type);

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
	virtual void SetID(unsigned int ID);
	virtual bool HasID();
	virtual void InvalidateID();

	virtual std::string GetName();
	virtual void SetName(const std::string& name);
	virtual bool HasName();
	virtual void InvalidateName();

	virtual void SetTransportSubstancesAcrossPath(bool);
	virtual bool GetTransportSubstancesAcrossPath();

	virtual void SetIsInterConnectedPath(bool);
	virtual bool GetIsInterConnectedPath();

	virtual SECircuitNode* GetSourceNode();	

	virtual SECircuitNode* GetTargetNode();	

	virtual CDM::enumOpenClosed::value GetSwitch();
	virtual void SetSwitch(CDM::enumOpenClosed::value state);
	virtual bool HasSwitch();
	virtual void InvalidateSwitch();

	virtual CDM::enumOpenClosed::value GetNextSwitch();
	virtual void SetNextSwitch(CDM::enumOpenClosed::value state);
	virtual bool HasNextSwitch();
	virtual void InvalidateNextSwitch();

	virtual CDM::enumOpenClosed::value GetValve();
	virtual void SetValve(CDM::enumOpenClosed::value state);
	virtual bool HasValve();
	virtual void InvalidateValve();

	virtual CDM::enumOpenClosed::value GetNextValve();
	virtual void SetNextValve(CDM::enumOpenClosed::value state);
	virtual bool HasNextValve();
	virtual void InvalidateNextValve();

	virtual CDM::enumOpenClosed::value GetPolarizedState();
	virtual void SetPolarizedState(CDM::enumOpenClosed::value state);
	virtual bool HasPolarizedState();
	virtual void InvalidatePolarizedState();

	virtual CDM::enumOpenClosed::value GetNextPolarizedState();
	virtual void SetNextPolarizedState(CDM::enumOpenClosed::value state);
	virtual bool HasNextPolarizedState();
	virtual void InvalidateNextPolarizedState();

	//////////////////////
	// Resistance Types //
	//////////////////////

	virtual bool HasFlowResistance();
	virtual SEScalarFlowResistance* GetFlowResistance();
	virtual bool HasNextFlowResistance();
	virtual SEScalarFlowResistance* GetNextFlowResistance();
	virtual bool HasFlowResistanceBaseline();
	virtual SEScalarFlowResistance* GetFlowResistanceBaseline();	

	virtual bool HasHeatResistance();
	virtual SEScalarHeatResistance* GetHeatResistance();
	virtual bool HasNextHeatResistance();
	virtual SEScalarHeatResistance* GetNextHeatResistance();
	virtual bool HasHeatResistanceBaseline();
	virtual SEScalarHeatResistance* GetHeatResistanceBaseline();

	virtual bool HasElectricResistance();
	virtual SEScalarElectricResistance* GetElectricResistance();
	virtual bool HasNextElectricResistance();
	virtual SEScalarElectricResistance* GetNextElectricResistance();
	virtual bool HasElectricResistanceBaseline();
	virtual SEScalarElectricResistance* GetElectricResistanceBaseline();

	///////////////////////
	// Capacitance Types //
	///////////////////////

	virtual bool HasFlowCompliance();
	virtual SEScalarFlowCompliance* GetFlowCompliance();
	virtual bool HasNextFlowCompliance();
	virtual SEScalarFlowCompliance* GetNextFlowCompliance();
	virtual bool HasFlowComplianceBaseline();
	virtual SEScalarFlowCompliance* GetFlowComplianceBaseline();

	virtual bool HasHeatCapacitance();
	virtual SEScalarHeatCapacitance* GetHeatCapacitance();
	virtual bool HasNextHeatCapacitance();
	virtual SEScalarHeatCapacitance* GetNextHeatCapacitance();
	virtual bool HasHeatCapacitanceBaseline();
	virtual SEScalarHeatCapacitance* GetHeatCapacitanceBaseline();

	virtual bool HasElectricCapacitance();
	virtual SEScalarElectricCapacitance* GetElectricCapacitance();
	virtual bool HasNextElectricCapacitance();
	virtual SEScalarElectricCapacitance* GetNextElectricCapacitance();
	virtual bool HasElectricCapacitanceBaseline();
	virtual SEScalarElectricCapacitance* GetElectricCapacitanceBaseline();

	//////////////////////
	// Inductance Types //
	//////////////////////

	virtual bool HasFlowInertance();
	virtual SEScalarFlowInertance* GetFlowInertance();
	virtual bool HasNextFlowInertance();
	virtual SEScalarFlowInertance* GetNextFlowInertance();
	virtual bool HasFlowInertanceBaseline();
	virtual SEScalarFlowInertance* GetFlowInertanceBaseline();

	virtual bool HasHeatInductance();
	virtual SEScalarHeatInductance* GetHeatInductance();
	virtual bool HasNextHeatInductance();
	virtual SEScalarHeatInductance* GetNextHeatInductance();
	virtual bool HasHeatInductanceBaseline();
	virtual SEScalarHeatInductance* GetHeatInductanceBaseline();

	virtual bool HasElectricInductance();
	virtual SEScalarElectricInductance* GetElectricInductance();
	virtual bool HasNextElectricInductance();
	virtual SEScalarElectricInductance* GetNextElectricInductance();
	virtual bool HasElectricInductanceBaseline();
	virtual SEScalarElectricInductance* GetElectricInductanceBaseline();

	////////////////
	// Flux Types //
	////////////////

	virtual bool HasFlow();
	virtual SEScalarVolumePerTime* GetFlow();
	virtual bool HasNextFlow();
	virtual SEScalarVolumePerTime* GetNextFlow();
	virtual bool HasFlowBaseline();
	virtual SEScalarVolumePerTime* GetFlowBaseline();
	virtual bool HasFlowSource();
	virtual SEScalarVolumePerTime* GetFlowSource();
	virtual bool HasNextFlowSource();
	virtual SEScalarVolumePerTime* GetNextFlowSource();
	virtual bool HasFlowSourceBaseline();
	virtual SEScalarVolumePerTime* GetFlowSourceBaseline();

	virtual bool HasHeatTransferRate();
	virtual SEScalarPower* GetHeatTransferRate();
	virtual bool HasNextHeatTransferRate();
	virtual SEScalarPower* GetNextHeatTransferRate();
	virtual bool HasHeatTransferRateBaseline();
	virtual SEScalarPower* GetHeatTransferRateBaseline();
	virtual bool HasHeatSource();
	virtual SEScalarPower* GetHeatSource();
	virtual bool HasNextHeatSource();
	virtual SEScalarPower* GetNextHeatSource();
	virtual bool HasHeatSourceBaseline();
	virtual SEScalarPower* GetHeatSourceBaseline();

	virtual bool HasElectricCurrent();
	virtual SEScalarElectricCurrent* GetElectricCurrent();
	virtual bool HasNextElectricCurrent();
	virtual SEScalarElectricCurrent* GetNextElectricCurrent();
	virtual bool HasElectricCurrentBaseline();
	virtual SEScalarElectricCurrent* GetElectricCurrentBaseline();
	virtual bool HasElectricCurrentSource();
	virtual SEScalarElectricCurrent* GetElectricCurrentSource();
	virtual bool HasNextElectricCurrentSource();
	virtual SEScalarElectricCurrent* GetNextElectricCurrentSource();
	virtual bool HasElectricCurrentSourceBaseline();
	virtual SEScalarElectricCurrent* GetElectricCurrentSourceBaseline();

	/////////////////////
	// Potential Types //
	/////////////////////

	virtual bool HasPressureSource();
	virtual SEScalarPressure* GetPressureSource();
	virtual bool HasNextPressureSource();
	virtual SEScalarPressure* GetNextPressureSource();
	virtual bool HasPressureSourceBaseline();
	virtual SEScalarPressure* GetPressureSourceBaseline();

	virtual bool HasTemperatureSource();
	virtual SEScalarTemperature* GetTemperatureSource();
	virtual bool HasNextTemperatureSource();
	virtual SEScalarTemperature* GetNextTemperatureSource();
	virtual bool HasTemperatureSourceBaseline();
	virtual SEScalarTemperature* GetTemperatureSourceBaseline();

	virtual bool HasElectricVoltageSource();
	virtual SEScalarElectricPotential* GetElectricVoltageSource();
	virtual bool HasNextElectricVoltageSource();
	virtual SEScalarElectricPotential* GetNextElectricVoltageSource();
	virtual bool HasElectricVoltageSourceBaseline();
	virtual SEScalarElectricPotential* GetElectricVoltageSourceBaseline();

	////////////////////
	// Quantity Types //
	////////////////////

	virtual bool HasVolume();
	virtual SEScalarVolume* GetVolume();
	virtual bool HasNextVolume();
	virtual SEScalarVolume* GetNextVolume();
	virtual bool HasUnStressedVolume();
	virtual SEScalarVolume* GetUnStressedVolume();
	virtual bool HasVolumeBaseline();
	virtual SEScalarVolume* GetVolumeBaseline();

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

	//////////
	// Misc //
	//////////

	bool HasValidElements(CDM::enumCircuitModelType::value modelType);
	int  NumberOfElements(CDM::enumCircuitModelType::value modelType);
	int  NumberOfNextElements(CDM::enumCircuitModelType::value modelType);

protected:
	bool                         m_TransportSubstancesAcrossPath;
	bool                         m_IsInterConnectedPath;
	unsigned int                 m_ID;
	std::string                  m_Name;
	SECircuitNode*               m_SourceNode;
	SECircuitNode*               m_TargetNode;	
	/////////////////////////    
	// Valves and Switches //    
	/////////////////////////    
	CDM::enumOpenClosed::value   m_Switch;
	CDM::enumOpenClosed::value   m_NextSwitch;
	CDM::enumOpenClosed::value   m_Valve;
	CDM::enumOpenClosed::value   m_NextValve;
	CDM::enumOpenClosed::value   m_PolarizedState;
	CDM::enumOpenClosed::value   m_NextPolarizedState;
	/////////////////////
	// Resistance Types//
	/////////////////////	

	SEScalarFlowResistance*      m_FlowResistance;
	SEScalarFlowResistance*      m_NextFlowResistance;
	SEScalarFlowResistance*      m_FlowResistanceBaseline;
								 
	SEScalarHeatResistance*	     m_HeatResistance;
	SEScalarHeatResistance*	     m_NextHeatResistance;
	SEScalarHeatResistance*	     m_HeatResistanceBaseline;
								 
	SEScalarElectricResistance*  m_ElectricResistance;	
	SEScalarElectricResistance*  m_NextElectricResistance;
	SEScalarElectricResistance*  m_ElectricResistanceBaseline;	
	///////////////////////
	// Capacitance Types //
	///////////////////////	
	SEScalarFlowCompliance*      m_FlowCompliance;
	SEScalarFlowCompliance*      m_NextFlowCompliance;
	SEScalarFlowCompliance*      m_FlowComplianceBaseline;
							     
	SEScalarHeatCapacitance*     m_HeatCapacitance;
	SEScalarHeatCapacitance*     m_NextHeatCapacitance;
	SEScalarHeatCapacitance*     m_HeatCapacitanceBaseline;

	SEScalarElectricCapacitance* m_ElectricCapacitance;	
	SEScalarElectricCapacitance* m_NextElectricCapacitance;
	SEScalarElectricCapacitance* m_ElectricCapacitanceBaseline;
	//////////////////////
	// Inductance Types //
	//////////////////////
	SEScalarFlowInertance*       m_FlowInertance;
	SEScalarFlowInertance*       m_NextFlowInertance;
	SEScalarFlowInertance*       m_FlowInertanceBaseline;

	SEScalarHeatInductance*		 m_HeatInductance;
	SEScalarHeatInductance*		 m_NextHeatInductance;
	SEScalarHeatInductance*		 m_HeatInductanceBaseline;

	SEScalarElectricInductance*  m_ElectricInductance;
	SEScalarElectricInductance*  m_NextElectricInductance;
	SEScalarElectricInductance*  m_ElectricInductanceBaseline;
	////////////////
	// Flux Types //
	////////////////
	SEScalarVolumePerTime*       m_Flow;
	SEScalarVolumePerTime*       m_NextFlow;
	SEScalarVolumePerTime*       m_FlowBaseline;
	SEScalarVolumePerTime*       m_FlowSource;
	SEScalarVolumePerTime*       m_NextFlowSource;
	SEScalarVolumePerTime*       m_FlowSourceBaseline;
							     
	SEScalarPower*			     m_HeatTransferRate;
	SEScalarPower*			     m_NextHeatTransferRate;	
	SEScalarPower*			     m_HeatTransferRateBaseline;
	SEScalarPower*			     m_HeatSource;
	SEScalarPower*			     m_NextHeatSource;
	SEScalarPower*			     m_HeatSourceBaseline;
							     
	SEScalarElectricCurrent*     m_ElectricCurrent;
	SEScalarElectricCurrent*     m_NextElectricCurrent;
	SEScalarElectricCurrent*     m_ElectricCurrentBaseline;
	SEScalarElectricCurrent*     m_ElectricCurrentSource;
	SEScalarElectricCurrent*     m_NextElectricCurrentSource;
	SEScalarElectricCurrent*     m_ElectricCurrentSourceBaseline;
	/////////////////////
	// Potential Types //
	/////////////////////
	SEScalarPressure*            m_PressureSource;
	SEScalarPressure*            m_NextPressureSource;
	SEScalarPressure*            m_PressureSourceBaseline;
							     
	SEScalarTemperature*	     m_TemperatureSource;
	SEScalarTemperature*	     m_NextTemperatureSource;
	SEScalarTemperature*	     m_TemperatureSourceBaseline;
							     
	SEScalarElectricPotential*   m_ElectricVoltageSource;
	SEScalarElectricPotential*   m_NextElectricVoltageSource;
	SEScalarElectricPotential*   m_ElectricVoltageSourceBaseline;
	////////////////////
	// Quantity Types //
	////////////////////
	SEScalarVolume*              m_Volume;
	SEScalarVolume*              m_NextVolume;
	SEScalarVolume*              m_VolumeBaseline;
	SEScalarVolume*              m_UnStressedVolume;
							     
	SEScalarEnergy*			     m_Heat;
	SEScalarEnergy*			     m_NextHeat;
	SEScalarEnergy*			     m_HeatBaseline;
							     
	SEScalarElectricCharge*      m_ElectricCharge;
	SEScalarElectricCharge*      m_NextElectricCharge;
	SEScalarElectricCharge*      m_ElectricChargeBaseline;

	SEInterCircuitConnection*	 m_InterCircuitConnection;
};