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
class SESubstance;
CDM_BIND_DECL(CircuitNodeSubstanceQuantityData)

class DLL_DECL SECircuitNodeSubstanceQuantity : public Loggable
{
public:

	SECircuitNodeSubstanceQuantity(SESubstance& substance);
	virtual ~SECircuitNodeSubstanceQuantity();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::CircuitNodeSubstanceQuantityData& in);
	std::unique_ptr<CDM::CircuitNodeSubstanceQuantityData> Unload();
protected:
	void Unload(CDM::CircuitNodeSubstanceQuantityData& data);
public:

	virtual bool HasMass();
	virtual SEScalarMass* GetMass();

	virtual bool HasNextMass();
	virtual SEScalarMass* GetNextMass();

	virtual bool HasConcentration();
	virtual SEScalarMassPerVolume* GetConcentration();

	virtual bool HasNextConcentration();
	virtual SEScalarMassPerVolume* GetNextConcentration();

	virtual bool HasVolume();
	virtual SEScalarVolume* GetVolume();

	virtual bool HasNextVolume();
	virtual SEScalarVolume* GetNextVolume();

	virtual bool HasVolumeFraction();
	virtual SEScalarFraction* GetVolumeFraction();

	virtual bool HasNextVolumeFraction();
	virtual SEScalarFraction* GetNextVolumeFraction();

	virtual bool HasPartialPressure();
	virtual SEScalarPressure* GetPartialPressure();

	virtual bool HasNextPartialPressure();
	virtual SEScalarPressure* GetNextPartialPressure();

	virtual bool HasSaturation();
	virtual SEScalarFraction* GetSaturation();

	virtual bool HasNextSaturation();
	virtual SEScalarFraction* GetNextSaturation();

	virtual bool HasKidneyClearanceFactor();
	virtual SEScalarFraction* GetKidneyClearanceFactor();	

	virtual bool HasLiverClearanceFactor();
	virtual SEScalarFraction* GetLiverClearanceFactor();	

	virtual bool HasMetabolicFactor();
	virtual SEScalar* GetMetabolicFactor();	

	virtual SESubstance* GetSubstance();

protected:

	SEScalarMass*          m_Mass;
	SEScalarMass*          m_NextMass;	
	SEScalarMassPerVolume* m_Concentration;
	SEScalarMassPerVolume* m_NextConcentration;
	SEScalarVolume*        m_Volume;
	SEScalarVolume*        m_NextVolume;
	SEScalarFraction*      m_VolumeFraction;
	SEScalarFraction*      m_NextVolumeFraction;
	SEScalarPressure*      m_PartialPressure;
	SEScalarPressure*      m_NextPartialPressure;
	SEScalarFraction*      m_Saturation;	
	SEScalarFraction*      m_NextSaturation;
	SEScalarFraction*      m_KidneyClearanceFactor;
	SEScalarFraction*      m_LiverClearanceFactor;
	SEScalar*              m_MetabolicFactor;

	SESubstance*           m_Substance;// dtor does not delete
};