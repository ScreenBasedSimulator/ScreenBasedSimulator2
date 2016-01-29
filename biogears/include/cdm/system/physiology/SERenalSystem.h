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
CDM_BIND_DECL(RenalSystemData)

class DLL_DECL SERenalSystem : public SESystem
{
public:

	SERenalSystem(Logger* logger);
	virtual ~SERenalSystem();

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
	
	bool Load(const CDM::RenalSystemData& in);
	std::unique_ptr<CDM::RenalSystemData> Unload() const;
protected:
	void Unload(CDM::RenalSystemData& data) const;

public:

	virtual bool HasGlomerularFiltrationRate() const;
	virtual SEScalarVolumePerTime& GetGlomerularFiltrationRate();
	virtual double GetGlomerularFiltrationRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasFiltrationFraction() const;
	virtual SEScalarFraction& GetFiltrationFraction();
	virtual double GetFiltrationFraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftAfferentArterioleResistance() const;
	virtual SEScalarFlowResistance& GetLeftAfferentArterioleResistance();
	virtual double GetLeftAfferentArterioleResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftBowmansCapsulesHydrostaticPressure() const;
	virtual SEScalarPressure& GetLeftBowmansCapsulesHydrostaticPressure();
	virtual double GetLeftBowmansCapsulesHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftBowmansCapsulesOsmoticPressure() const;
	virtual SEScalarPressure& GetLeftBowmansCapsulesOsmoticPressure();
	virtual double GetLeftBowmansCapsulesOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftEfferentArterioleResistance() const;
	virtual SEScalarFlowResistance& GetLeftEfferentArterioleResistance();
	virtual double GetLeftEfferentArterioleResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftGlomerularCapillariesHydrostaticPressure() const;
	virtual SEScalarPressure& GetLeftGlomerularCapillariesHydrostaticPressure();
	virtual double GetLeftGlomerularCapillariesHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftGlomerularCapillariesOsmoticPressure() const;
	virtual SEScalarPressure& GetLeftGlomerularCapillariesOsmoticPressure();
	virtual double GetLeftGlomerularCapillariesOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftGlomerularFiltrationCoefficient() const;
	virtual SEScalarVolumePerTimePerPressure& GetLeftGlomerularFiltrationCoefficient();
	virtual double GetLeftGlomerularFiltrationCoefficient(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftGlomerularFiltrationRate() const;
	virtual SEScalarVolumePerTime& GetLeftGlomerularFiltrationRate();
	virtual double GetLeftGlomerularFiltrationRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftGlomerularFiltrationSurfaceArea() const;
	virtual SEScalarArea& GetLeftGlomerularFiltrationSurfaceArea();
	virtual double GetLeftGlomerularFiltrationSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftGlomerularFluidPermeability() const;
	virtual SEScalarVolumePerTimePerPressurePerArea& GetLeftGlomerularFluidPermeability();
	virtual double GetLeftGlomerularFluidPermeability() const;

	virtual bool HasLeftFiltrationFraction() const;
	virtual SEScalarFraction& GetLeftFiltrationFraction();
	virtual double GetLeftFiltrationFraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftNetFiltrationPressure() const;
	virtual SEScalarPressure& GetLeftNetFiltrationPressure();
	virtual double GetLeftNetFiltrationPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftNetReabsorptionPressure() const;
	virtual SEScalarPressure& GetLeftNetReabsorptionPressure();
	virtual double GetLeftNetReabsorptionPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftPeritubularCapillariesHydrostaticPressure() const;
	virtual SEScalarPressure& GetLeftPeritubularCapillariesHydrostaticPressure();
	virtual double GetLeftPeritubularCapillariesHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftPeritubularCapillariesOsmoticPressure() const;
	virtual SEScalarPressure& GetLeftPeritubularCapillariesOsmoticPressure();
	virtual double GetLeftPeritubularCapillariesOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftReabsorptionFiltrationCoefficient() const;
	virtual SEScalarVolumePerTimePerPressure& GetLeftReabsorptionFiltrationCoefficient();
	virtual double GetLeftReabsorptionFiltrationCoefficient(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftReabsorptionRate() const;
	virtual SEScalarVolumePerTime& GetLeftReabsorptionRate();
	virtual double GetLeftReabsorptionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftTubularReabsorptionFiltrationSurfaceArea() const;
	virtual SEScalarArea& GetLeftTubularReabsorptionFiltrationSurfaceArea();
	virtual double GetLeftTubularReabsorptionFiltrationSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftTubularReabsorptionFluidPermeability() const;
	virtual SEScalarVolumePerTimePerPressurePerArea& GetLeftTubularReabsorptionFluidPermeability();
	virtual double GetLeftTubularReabsorptionFluidPermeability() const;

	virtual bool HasLeftTubularHydrostaticPressure() const;
	virtual SEScalarPressure& GetLeftTubularHydrostaticPressure();
	virtual double GetLeftTubularHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasLeftTubularOsmoticPressure() const;
	virtual SEScalarPressure& GetLeftTubularOsmoticPressure();
	virtual double GetLeftTubularOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRenalBloodFlow() const;
	virtual SEScalarVolumePerTime& GetRenalBloodFlow();
	virtual double GetRenalBloodFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRenalPlasmaFlow() const;
	virtual SEScalarVolumePerTime& GetRenalPlasmaFlow();
	virtual double GetRenalPlasmaFlow(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRenalVascularResistance() const;
	virtual SEScalarFlowResistance& GetRenalVascularResistance();
	virtual double GetRenalVascularResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightAfferentArterioleResistance() const;
	virtual SEScalarFlowResistance& GetRightAfferentArterioleResistance();
	virtual double GetRightAfferentArterioleResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightBowmansCapsulesHydrostaticPressure() const;
	virtual SEScalarPressure& GetRightBowmansCapsulesHydrostaticPressure();
	virtual double GetRightBowmansCapsulesHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightBowmansCapsulesOsmoticPressure() const;
	virtual SEScalarPressure& GetRightBowmansCapsulesOsmoticPressure();
	virtual double GetRightBowmansCapsulesOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightEfferentArterioleResistance() const;
	virtual SEScalarFlowResistance& GetRightEfferentArterioleResistance();
	virtual double GetRightEfferentArterioleResistance(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightGlomerularCapillariesHydrostaticPressure() const;
	virtual SEScalarPressure& GetRightGlomerularCapillariesHydrostaticPressure();
	virtual double GetRightGlomerularCapillariesHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightGlomerularCapillariesOsmoticPressure() const;
	virtual SEScalarPressure& GetRightGlomerularCapillariesOsmoticPressure();
	virtual double GetRightGlomerularCapillariesOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightGlomerularFiltrationCoefficient() const;
	virtual SEScalarVolumePerTimePerPressure& GetRightGlomerularFiltrationCoefficient();
	virtual double GetRightGlomerularFiltrationCoefficient(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightGlomerularFiltrationRate() const;
	virtual SEScalarVolumePerTime& GetRightGlomerularFiltrationRate();
	virtual double GetRightGlomerularFiltrationRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightGlomerularFiltrationSurfaceArea() const;
	virtual SEScalarArea& GetRightGlomerularFiltrationSurfaceArea();
	virtual double GetRightGlomerularFiltrationSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightGlomerularFluidPermeability() const;
	virtual SEScalarVolumePerTimePerPressurePerArea& GetRightGlomerularFluidPermeability();
	virtual double GetRightGlomerularFluidPermeability() const;

	virtual bool HasRightFiltrationFraction() const;
	virtual SEScalarFraction& GetRightFiltrationFraction();
	virtual double GetRightFiltrationFraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightNetFiltrationPressure() const;
	virtual SEScalarPressure& GetRightNetFiltrationPressure();
	virtual double GetRightNetFiltrationPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightNetReabsorptionPressure() const;
	virtual SEScalarPressure& GetRightNetReabsorptionPressure();
	virtual double GetRightNetReabsorptionPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightPeritubularCapillariesHydrostaticPressure() const;
	virtual SEScalarPressure& GetRightPeritubularCapillariesHydrostaticPressure();
	virtual double GetRightPeritubularCapillariesHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightPeritubularCapillariesOsmoticPressure() const;
	virtual SEScalarPressure& GetRightPeritubularCapillariesOsmoticPressure();
	virtual double GetRightPeritubularCapillariesOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightReabsorptionFiltrationCoefficient() const;
	virtual SEScalarVolumePerTimePerPressure& GetRightReabsorptionFiltrationCoefficient();
	virtual double GetRightReabsorptionFiltrationCoefficient(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightReabsorptionRate() const;
	virtual SEScalarVolumePerTime& GetRightReabsorptionRate();
	virtual double GetRightReabsorptionRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightTubularReabsorptionFiltrationSurfaceArea() const;
	virtual SEScalarArea& GetRightTubularReabsorptionFiltrationSurfaceArea();
	virtual double GetRightTubularReabsorptionFiltrationSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightTubularReabsorptionFluidPermeability() const;
	virtual SEScalarVolumePerTimePerPressurePerArea& GetRightTubularReabsorptionFluidPermeability();
	virtual double GetRightTubularReabsorptionFluidPermeability() const;

	virtual bool HasRightTubularHydrostaticPressure() const;
	virtual SEScalarPressure& GetRightTubularHydrostaticPressure();
	virtual double GetRightTubularHydrostaticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasRightTubularOsmoticPressure() const;
	virtual SEScalarPressure& GetRightTubularOsmoticPressure();
	virtual double GetRightTubularOsmoticPressure(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasUrinationRate() const;
	virtual SEScalarVolumePerTime& GetUrinationRate();
	virtual double GetUrinationRate(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasUrineOsmolality() const;
	virtual SEScalarOsmolality& GetUrineOsmolality();
	virtual double GetUrineOsmolality(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasUrineOsmolarity() const;
	virtual SEScalarOsmolarity& GetUrineOsmolarity();
	virtual double GetUrineOsmolarity(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasUrineProductionRate() const;
	virtual SEScalarVolumePerTime& GetUrineProductionRate();
	virtual double GetUrineProductionRate(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual bool HasUrineSpecificGravity() const;
	virtual SEScalar& GetUrineSpecificGravity();
	virtual double GetUrineSpecificGravity() const;

	virtual bool HasUrineVolume() const;
	virtual SEScalarVolume& GetUrineVolume();
	virtual double GetUrineVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasUrineUreaNitrogenConcentration() const;
	virtual SEScalarMassPerVolume& GetUrineUreaNitrogenConcentration();
	virtual double GetUrineUreaNitrogenConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	SEScalarVolumePerTime*			  m_GlomerularFiltrationRate; 
	SEScalarFraction*			      m_FiltrationFraction;

	SEScalarFlowResistance*			  m_LeftAfferentArterioleResistance;
	SEScalarPressure*		          m_LeftBowmansCapsulesHydrostaticPressure;
	SEScalarPressure*			      m_LeftBowmansCapsulesOsmoticPressure;
	SEScalarFlowResistance*			  m_LeftEfferentArterioleResistance;
	SEScalarPressure*			      m_LeftGlomerularCapillariesHydrostaticPressure;
	SEScalarPressure*			      m_LeftGlomerularCapillariesOsmoticPressure;
	SEScalarVolumePerTimePerPressure* m_LeftGlomerularFiltrationCoefficient;
	SEScalarVolumePerTime*			  m_LeftGlomerularFiltrationRate;
	SEScalarArea*			          m_LeftGlomerularFiltrationSurfaceArea;
	SEScalarVolumePerTimePerPressurePerArea*	  m_LeftGlomerularFluidPermeability;
	SEScalarFraction*			      m_LeftFiltrationFraction;
	SEScalarPressure*			      m_LeftNetFiltrationPressure;
	SEScalarPressure*			      m_LeftNetReabsorptionPressure;
	SEScalarPressure*			      m_LeftPeritubularCapillariesHydrostaticPressure;
	SEScalarPressure*			      m_LeftPeritubularCapillariesOsmoticPressure;
	SEScalarVolumePerTimePerPressure* m_LeftReabsorptionFiltrationCoefficient;
	SEScalarVolumePerTime*			  m_LeftReabsorptionRate;
	SEScalarArea*			          m_LeftTubularReabsorptionFiltrationSurfaceArea;
	SEScalarVolumePerTimePerPressurePerArea*	  m_LeftTubularReabsorptionFluidPermeability;
	SEScalarPressure*			      m_LeftTubularHydrostaticPressure;
	SEScalarPressure*			      m_LeftTubularOsmoticPressure;

	SEScalarVolumePerTime*			  m_RenalBloodFlow;
	SEScalarVolumePerTime*			  m_RenalPlasmaFlow;
	SEScalarFlowResistance*			  m_RenalVascularResistance;

	SEScalarFlowResistance*			  m_RightAfferentArterioleResistance;
	SEScalarPressure*		          m_RightBowmansCapsulesHydrostaticPressure;
	SEScalarPressure*			      m_RightBowmansCapsulesOsmoticPressure;
	SEScalarFlowResistance*			  m_RightEfferentArterioleResistance;
	SEScalarPressure*			      m_RightGlomerularCapillariesHydrostaticPressure;
	SEScalarPressure*			      m_RightGlomerularCapillariesOsmoticPressure;
	SEScalarVolumePerTimePerPressure* m_RightGlomerularFiltrationCoefficient;
	SEScalarVolumePerTime*			  m_RightGlomerularFiltrationRate;
	SEScalarArea*			          m_RightGlomerularFiltrationSurfaceArea;
	SEScalarVolumePerTimePerPressurePerArea*	  m_RightGlomerularFluidPermeability;
	SEScalarFraction*			      m_RightFiltrationFraction;
	SEScalarPressure*			      m_RightNetFiltrationPressure;
	SEScalarPressure*			      m_RightNetReabsorptionPressure;
	SEScalarPressure*			      m_RightPeritubularCapillariesHydrostaticPressure;
	SEScalarPressure*			      m_RightPeritubularCapillariesOsmoticPressure;
	SEScalarVolumePerTimePerPressure* m_RightReabsorptionFiltrationCoefficient;
	SEScalarVolumePerTime*			  m_RightReabsorptionRate;
	SEScalarArea*			          m_RightTubularReabsorptionFiltrationSurfaceArea;
	SEScalarVolumePerTimePerPressurePerArea*   m_RightTubularReabsorptionFluidPermeability;
	SEScalarPressure*			      m_RightTubularHydrostaticPressure;
	SEScalarPressure*			      m_RightTubularOsmoticPressure;

	SEScalarVolumePerTime*            m_UrinationRate;
	SEScalarOsmolality*			      m_UrineOsmolality;
	SEScalarOsmolarity*			      m_UrineOsmolarity;
	SEScalarVolumePerTime*		      m_UrineProductionRate;
	SEScalar*			              m_UrineSpecificGravity;
	SEScalarVolume*			          m_UrineVolume;
	SEScalarMassPerVolume*		      m_UrineUreaNitrogenConcentration;
};
