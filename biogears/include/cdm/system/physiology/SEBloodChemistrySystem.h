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
CDM_BIND_DECL(BloodChemistrySystemData)
/**
 * @brief @copydoc BloodChemistry
 * @details @copydetails BloodChemistry
 *
 * @nosubgrouping
 */
class DLL_DECL SEBloodChemistrySystem : public SESystem
{
public:

	SEBloodChemistrySystem(Logger* logger);
	virtual ~SEBloodChemistrySystem();

	/// Resets all values to be invalid
	virtual void Reset();
	/// Deletes all member variables
	virtual void Clear();

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	/** @name Serialization
	*   @brief Serializing data to and from bind classes
	*   @{*/
	/// Reset and set data value to bind values
	bool Load(const CDM::BloodChemistrySystemData& in);
	/// Create and push all data values to a bind class
	std::unique_ptr<CDM::BloodChemistrySystemData> Unload() const;
protected:
	/// Push this data to bind class
	void Unload(CDM::BloodChemistrySystemData& data) const;
	//@}
public:

	/** @name BloodDensity
	*  @brief @copybrief BloodChemistryBloodDensity
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasBloodDensity() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetBloodDensity();
	virtual double GetBloodDensity(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name BloodPH
	*  @brief @copybrief BloodChemistryBloodPH
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasBloodPH() const;
	/// Get member class, allocate if nullptr
	virtual SEScalar& GetBloodPH();
	virtual double GetBloodPH() const;
	//@}

	/** @name BloodSpecificHeat
	*  @brief @copybrief BloodChemistryBloodSpecificHeat
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasBloodSpecificHeat() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarHeatCapacitancePerMass& GetBloodSpecificHeat();
	virtual double GetBloodSpecificHeat(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name CarbonDioxideSaturation
	*  @brief @copybrief BloodChemistryCarbonDioxideSaturation
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasCarbonDioxideSaturation() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarFraction& GetCarbonDioxideSaturation();
	virtual double GetCarbonDioxideSaturation() const;
	//@}

	/** @name ExtracellularFluidVolume
	*  @brief @copybrief BloodChemistryExtracellularFluidVolume
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasExtracellularFluidVolume() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarVolume& GetExtracellularFluidVolume();
	virtual double GetExtracellularFluidVolume(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name ExtravascularFluidVolume
	*  @brief @copybrief BloodChemistryExtravascularFluidVolume
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasExtravascularFluidVolume() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarVolume& GetExtravascularFluidVolume();
	virtual double GetExtravascularFluidVolume(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name Hematocrit
	*  @brief @copybrief BloodChemistryHematocrit
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasHematocrit() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarFraction& GetHematocrit();
	virtual double GetHematocrit() const;
	//@}

	/** @name HemoglobinContent
	*  @brief @copybrief BloodChemistryHemoglobinContent
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasHemoglobinContent() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMass& GetHemoglobinContent();
	virtual double GetHemoglobinContent(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name IntracellularFluidVolume
	*  @brief @copybrief BloodChemistryIntracellularFluidVolume
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasIntracellularFluidVolume() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarVolume& GetIntracellularFluidVolume();
	virtual double GetIntracellularFluidVolume(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name IntracellularFluidPH
	*  @brief @copybrief BloodChemistryIntracellularFluidPH
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasIntracellularFluidPH() const;
	/// Get member class, allocate if nullptr
	virtual SEScalar& GetIntracellularFluidPH();
	virtual double GetIntracellularFluidPH() const;
	//@}

	/** @name OxygenSaturation
	 *  @brief @copybrief BloodChemistryOxygenSaturation
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasOxygenSaturation() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarFraction& GetOxygenSaturation();
	virtual double GetOxygenSaturation() const;
	//@}

	/** @name PlasmaVolume
	*  @brief @copybrief BloodChemistryPlasmaVolume
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasPlasmaVolume() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarVolume& GetPlasmaVolume();
	virtual double GetPlasmaVolume(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name RedBloodCellCount
	 *  @brief @copybrief BloodChemistryRedBloodCellCount
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasRedBloodCellCount() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarAmountPerVolume& GetRedBloodCellCount();
	virtual double GetRedBloodCellCount(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name ShuntFraction
	 *  @brief @copybrief BloodChemistryShuntFraction
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasShuntFraction() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarFraction& GetShuntFraction();
	virtual double GetShuntFraction() const;
	//@}

	/** @name VolumeFractionNeutralPhospholipidInPlasma
	*  @brief @copybrief BloodChemistryVolumeFractionNeutralPhospholipidInPlasma
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasVolumeFractionNeutralPhospholipidInPlasma() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarFraction& GetVolumeFractionNeutralPhospholipidInPlasma();
	virtual double GetVolumeFractionNeutralPhospholipidInPlasma() const;
	//@}

	/** @name VolumeFractionNeutralLipidInPlasma
	*  @brief @copybrief BloodChemistryVolumeFractionNeutralLipidInPlasma
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasVolumeFractionNeutralLipidInPlasma() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarFraction& GetVolumeFractionNeutralLipidInPlasma();
	virtual double GetVolumeFractionNeutralLipidInPlasma() const;
	//@}

	/** @name WhiteBloodCellCount
	*  @brief @copybrief BloodChemistryWhiteBloodCellCount
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasWhiteBloodCellCount() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarAmountPerVolume& GetWhiteBloodCellCount();
	virtual double GetWhiteBloodCellCount(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}


	/** @name AlbuminConcentration
	*  @brief @copybrief BloodChemistryAlbuminConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasAlbuminConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetAlbuminConcentration();
	virtual double GetAlbuminConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name BicarbonateConcentration
	 *  @brief @copybrief BloodChemistryBicarbonateConcentration
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasBicarbonateConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetBicarbonateConcentration();
	virtual double GetBicarbonateConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name BloodUreaNitrogenConcentration
	*  @brief @copybrief BloodChemistryBloodUreaNitrogenConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasBloodUreaNitrogenConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetBloodUreaNitrogenConcentration();
	virtual double GetBloodUreaNitrogenConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name CalciumConcentration
	 *  @brief @copybrief BloodChemistryCalciumConcentration
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasCalciumConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetCalciumConcentration();
	virtual double GetCalciumConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name CreatinineConcentration
	*  @brief @copybrief BloodChemistryCreatinineConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasCreatinineConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetCreatinineConcentration();
	virtual double GetCreatinineConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name GlobulinConcentration
	*  @brief @copybrief BloodChemistryGlobulinConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasGlobulinConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetGlobulinConcentration();
	virtual double GetGlobulinConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name GlucoseConcentration
	*  @brief @copybrief BloodChemistryGlucoseConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasGlucoseConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetGlucoseConcentration();
	virtual double GetGlucoseConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name HemoglobinConcentration
	*  @brief @copybrief BloodChemistryHemoglobinConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasHemoglobinConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetHemoglobinConcentration();
	virtual double GetHemoglobinConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name InsulinConcentration
	*  @brief @copybrief BloodChemistryInsulinoncentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasInsulinConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetInsulinConcentration();
	virtual double GetInsulinConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name KetoneConcentration
	*  @brief @copybrief BloodChemistryKetoneConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasKetoneConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetKetoneConcentration();
	virtual double GetKetoneConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name LactateConcentrationConcentration
	*  @brief @copybrief BloodChemistryLactateConcentrationConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasLactateConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetLactateConcentration();
	virtual double GetLactateConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name SodiumConcentration
	 *  @brief @copybrief BloodChemistrySodiumConcentration
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasSodiumConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetSodiumConcentration();
	virtual double GetSodiumConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name TotalProteinConcentration
	*  @brief @copybrief BloodChemistryTotalProteinConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasTotalProteinConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetTotalProteinConcentration();
	virtual double GetTotalProteinConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name TristearinConcentration
	*  @brief @copybrief BloodChemistryTristearinConcentration
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasTristearinConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetTristearinConcentration();
	virtual double GetTristearinConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name UreaNitrogenConcentration
	 *  @brief @copybrief BloodChemistryUreaNitrogenConcentration
	 *  @{*/
	/// %Test if member has been allocated
	virtual bool HasUreaConcentration() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarMassPerVolume& GetUreaConcentration();
	virtual double GetUreaConcentration(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name ArterialCarbonDioxidePressure
	*  @brief @copybrief BloodChemistryArterialCarbonDioxidePressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasArterialCarbonDioxidePressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetArterialCarbonDioxidePressure();
	virtual double GetArterialCarbonDioxidePressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name ArterialOxygenPressure
	*  @brief @copybrief BloodChemistryArterialOxygenPressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasArterialOxygenPressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetArterialOxygenPressure();
	virtual double GetArterialOxygenPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name PulmonaryArterialCarbonDioxidePressure
	*  @brief @copybrief BloodChemistryPulmonaryArterialCarbonDioxidePressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasPulmonaryArterialCarbonDioxidePressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetPulmonaryArterialCarbonDioxidePressure();
	virtual double GetPulmonaryArterialCarbonDioxidePressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name PulmonaryArterialOxygenPressure
	*  @brief @copybrief BloodChemistryPulmonaryArterialOxygenPressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasPulmonaryArterialOxygenPressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetPulmonaryArterialOxygenPressure();
	virtual double GetPulmonaryArterialOxygenPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name PulmonaryVenousCarbonDioxidePressure
	*  @brief @copybrief BloodChemistryPulmonaryVenousCarbonDioxidePressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasPulmonaryVenousCarbonDioxidePressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetPulmonaryVenousCarbonDioxidePressure();
	virtual double GetPulmonaryVenousCarbonDioxidePressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name PulmonaryVenousOxygenPressure
	*  @brief @copybrief BloodChemistryPulmonaryVenousOxygenPressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasPulmonaryVenousOxygenPressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetPulmonaryVenousOxygenPressure();
	virtual double GetPulmonaryVenousOxygenPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	/** @name VenousCarbonDioxidePressure
	*  @brief @copybrief BloodChemistryVenousCarbonDioxidePressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasVenousCarbonDioxidePressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetVenousCarbonDioxidePressure();
	virtual double GetVenousCarbonDioxidePressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}
	/** @name VenousOxygenPressure
	*  @brief @copybrief BloodChemistryVenousOxygenPressure
	*  @{*/
	/// %Test if member has been allocated
	virtual bool HasVenousOxygenPressure() const;
	/// Get member class, allocate if nullptr
	virtual SEScalarPressure& GetVenousOxygenPressure();
	virtual double GetVenousOxygenPressure(const std::shared_ptr<CCompoundUnit>& unit) const;
	//@}

	virtual bool HasArterialBicarbonateCO2Fraction() const;
	virtual SEScalarFraction& GetArterialBicarbonateCO2Fraction();
	virtual double GetArterialBicarbonateCO2Fraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasArterialCarbaminohemoglobinCO2Fraction() const;
	virtual SEScalarFraction& GetArterialCarbaminohemoglobinCO2Fraction();
	virtual double GetArterialCarbaminohemoglobinCO2Fraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasArterialFreeFloatingCO2Fraction() const;
	virtual SEScalarFraction& GetArterialFreeFloatingCO2Fraction();
	virtual double GetArterialFreeFloatingCO2Fraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVenousBicarbonateCO2Fraction() const;
	virtual SEScalarFraction& GetVenousBicarbonateCO2Fraction();
	virtual double GetVenousBicarbonateCO2Fraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVenousCarbaminohemoglobinCO2Fraction() const;
	virtual SEScalarFraction& GetVenousCarbaminohemoglobinCO2Fraction();
	virtual double GetVenousCarbaminohemoglobinCO2Fraction(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasVenousFreeFloatingCO2Fraction() const;
	virtual SEScalarFraction& GetVenousFreeFloatingCO2Fraction();
	virtual double GetVenousFreeFloatingCO2Fraction(const std::shared_ptr<CCompoundUnit>& unit) const;

protected:

	SEScalarMassPerVolume*	        m_BloodDensity;
	SEScalar*                       m_BloodPH;
	SEScalarHeatCapacitancePerMass* m_BloodSpecificHeat;
	SEScalarFraction*               m_CarbonDioxideSaturation;
	SEScalarVolume*                 m_ExtracellularFluidVolume;//planned
	SEScalarVolume*                 m_ExtravascularFluidVolume;//planned
	SEScalarFraction*               m_Hematocrit;
	SEScalarMass*                   m_HemoglobinContent;
	SEScalarVolume*                 m_IntracellularFluidVolume;//planned
	SEScalar*                       m_IntracellularFluidPH;
	SEScalarFraction*               m_OxygenSaturation;
	SEScalarVolume*                 m_PlasmaVolume;
	SEScalarAmountPerVolume*        m_RedBloodCellCount;
	SEScalarFraction*               m_ShuntFraction;
	SEScalarFraction*               m_VolumeFractionNeutralPhospholipidInPlasma;
	SEScalarFraction*               m_VolumeFractionNeutralLipidInPlasma;
	SEScalarAmountPerVolume*        m_WhiteBloodCellCount;

	SEScalarMassPerVolume*          m_AlbuminConcentration;
	SEScalarMassPerVolume*          m_BicarbonateConcentration;//
	SEScalarMassPerVolume*          m_BloodUreaNitrogenConcentration;
	SEScalarMassPerVolume*          m_CalciumConcentration;//
	SEScalarMassPerVolume*          m_CreatinineConcentration;//
	SEScalarMassPerVolume*	        m_GlobulinConcentration;//
	SEScalarMassPerVolume*	        m_GlucoseConcentration;//
	SEScalarMassPerVolume*          m_HemoglobinConcentration;//
	SEScalarMassPerVolume*	        m_InsulinConcentration;//
	SEScalarMassPerVolume*	        m_KetoneConcentration;//
	SEScalarMassPerVolume*	        m_LactateConcentration;
	SEScalarMassPerVolume*          m_SodiumConcentration;//
	SEScalarMassPerVolume*          m_TotalProteinConcentration;
	SEScalarMassPerVolume*          m_TristearinConcentration;
	SEScalarMassPerVolume*          m_UreaConcentration;

	SEScalarPressure*		        m_ArterialCarbonDioxidePressure;//i calc'd uu
	SEScalarPressure*		        m_ArterialOxygenPressure;//i calc'd uu
	SEScalarPressure*		        m_PulmonaryArterialCarbonDioxidePressure;//i calc'd uu
	SEScalarPressure*		        m_PulmonaryArterialOxygenPressure;//i calc'd uu
	SEScalarPressure*		        m_PulmonaryVenousCarbonDioxidePressure;//i calc'd uu
	SEScalarPressure*		        m_PulmonaryVenousOxygenPressure;//i calc'd uu
	SEScalarPressure*		        m_VenousCarbonDioxidePressure;//i calc'd uu
	SEScalarPressure*		        m_VenousOxygenPressure;//i calc'd uu

	//CO2 Fractions
	SEScalarFraction*				m_ArterialBicarbonateCO2Fraction;
	SEScalarFraction*				m_ArterialCarbaminohemoglobinCO2Fraction;
	SEScalarFraction*				m_ArterialFreeFloatingCO2Fraction;
	SEScalarFraction*				m_VenousBicarbonateCO2Fraction;
	SEScalarFraction*				m_VenousCarbaminohemoglobinCO2Fraction;
	SEScalarFraction*				m_VenousFreeFloatingCO2Fraction;
	
};