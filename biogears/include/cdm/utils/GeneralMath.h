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
class SECircuitNode;
class SECircuitNodeSubstanceQuantity;
CDM_BIND_DECL(KelmanEquationData)

class DLL_DECL GeneralMath : public Loggable
{
public:
	GeneralMath(Logger *logger);
	~GeneralMath();

	void CalculateMass(const SEScalarVolume& volume, const SEScalarMassPerVolume& concentration, SEScalarMass& mass) const;
	void CalculateConcentration(const SEScalarMass& mass, const SEScalarVolume& volume, SEScalarMassPerVolume& concentration) const;

	void CalculateOsmolarity(const SEScalarAmountPerVolume& sodiumMolarity, const SEScalarAmountPerVolume& glucoseMolarity, const SEScalarAmountPerVolume& ureaMolarity, SEScalarOsmolarity& fluidOsmolarity) const;
	void CalculateOsmolality(const SEScalarAmountPerVolume& sodiumMolarity, const SEScalarAmountPerVolume& glucoseMolarity, const SEScalarAmountPerVolume& ureaMolarity, const SEScalar& specificGravity, SEScalarOsmolality& fluidOsmolality) const;

	void CalculateSpecificGravity(const SEScalarMass& mass, const SEScalarVolume& volume, SEScalar& specificGravity) const;

	void CalculatePartialPressureInLiquid(const SESubstance& substance, const SEScalarMassPerVolume& concentration, SEScalarPressure& partialPressure) const;

	void CalculatePartialPressureInGas(const SEScalarFraction& volumeFraction, const SEScalarPressure& pressure, SEScalarPressure& partialPressure) const;

	static void   Combinations(std::vector<int> maxValues, std::vector<std::vector<int>>& permutations);
	static double PercentDifference(double expected, double calculated);
	static double PercentTolerance(double expected, double calculated, double epsilon = 1e-20);
	static double LinearInterpolator(double x1, double x2, double y1, double y2, double xPrime);
	static double ResistanceFunction(double dbase, double dmin, double dmax, double dx);
};

class DLL_DECL SaturationCalculator : public Loggable
{
protected:
	double m_k1;
	double m_k2;
	double m_k3;
	double m_k4;
	double m_k5;
	double m_k6;
	double m_k7;
	double m_NewtonRaphsonConvergenceValue;
	unsigned int m_NewtonRaphsonMaximumIterations;

public:	
	SaturationCalculator(Logger* logger);
	virtual ~SaturationCalculator();

	bool LoadKelmanData(const CDM::KelmanEquationData& in);
	std::unique_ptr<CDM::KelmanEquationData> UnloadKelmanData() const;

	void   Reset();
	void   SetSubstances(const SESubstance& O2, const SESubstance& CO2, const SESubstance& Hb, const SESubstance& HbO2, const SESubstance& HbO2CO2, const SESubstance& HbCO2, const SESubstance& HCO3);

	double CalculateHbSatFromO2PartialPressure(double partialPressure_mmHg) const;
	double CalculateO2PartialPressureFromHbSat(double HbSaturation, double partialPressure_mmHg) const;	
	void   CalculateOxygenSaturation(SECircuitNode& node) const;
	void   CalculateCarbonDioxideSaturation(SECircuitNode& node) const;

	//For CO2, Bicarbonate and HbCO2 testing
	double CalculateBloodPH(double CO2PartialPressure_mmHg, double BicarbonateConcentration_mmol_Per_L) const;
	double InterpolateBicarbonate(double HbCO2Fraction) const;
	double CalculateHbCO2Saturation(double BloodPH, double CO2PartialPressure_mmHg) const;

	void RedistributeHemoglobin(SECircuitNode& node);
	void GetBoundMasses(SECircuitNode& node, double& boundO2Mass, double& boundCO2Mass);

	GeneralMath& GetGeneralMath(){ return m_math; }
protected:

	bool UpdateQuantitiesBasedOnSaturations(double OxygenSaturation, double CarbonDioxideSaturation) const;

public:
	const SESubstance* m_O2;
	const SESubstance* m_Hb;
	const SESubstance* m_HbO2;
	const SESubstance* m_HbO2CO2;
	const SESubstance* m_CO2;
	const SESubstance* m_HCO3;
	const SESubstance* m_HbCO2;

protected:
	double m_O2_g_Per_mol;
	double m_CO2_g_Per_mol;
	double m_HCO3_g_Per_mol;
	double m_Hb_g_Per_mol;
	double m_HbO2_g_Per_mol;
	double m_HbCO2_g_Per_mol;
	double m_HbO2CO2_g_Per_mol;

	mutable SECircuitNodeSubstanceQuantity* m_subO2Q;
	mutable SECircuitNodeSubstanceQuantity* m_subCO2Q;
	mutable SECircuitNodeSubstanceQuantity* m_subHCO3Q;
	mutable SECircuitNodeSubstanceQuantity* m_subHbQ;
	mutable SECircuitNodeSubstanceQuantity* m_subHbO2Q;
	mutable SECircuitNodeSubstanceQuantity* m_subHbCO2Q;
	mutable SECircuitNodeSubstanceQuantity* m_subHbO2CO2Q;

	GeneralMath m_math;
};


