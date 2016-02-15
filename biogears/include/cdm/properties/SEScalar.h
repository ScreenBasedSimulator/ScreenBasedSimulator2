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
#include "properties/SEProperty.h"
#include "utils/unitconversion/UCCommon.h"

CDM_BIND_DECL(ScalarData)

#define zerolimit 1e-10

class DLL_DECL SEScalar : public SEProperty
{
protected:
	double m_value;
	std::shared_ptr<CCompoundUnit> m_unit;

	bool   m_upperBounded;
	bool   m_lowerBounded;
	double m_upperBound;
	double m_lowerBound;	

	std::shared_ptr<CCompoundUnit> m_boundUnit;
	bool   m_isnan;
	bool   m_isinf;
	
public:
	SEScalar();
	virtual ~SEScalar();

	void Load(const CDM::ScalarData& in);
	std::unique_ptr<CDM::ScalarData> Unload() const;

	/// Removes all data (bounds too)
	virtual void Clear();

protected:
	void Unload(CDM::ScalarData& s) const;

public:

	/**
	 * Copies ONLY the value and unit
	 * ONLY if the provided scalar is valid.
	 * Bounds are not copied, but they are enforced
	 */
	virtual bool Set(const SEScalar& s);
	virtual bool Set(const SEScalar* s); // Utility

	/**
	 * Copies the entire contents (bounds too)
	 * of the provided scalar to this.
	 * Even if s is invalid.
	 */
	virtual void Copy(const SEScalar& s);

	virtual bool IsValid() const;
	virtual bool IsInfinity() const { return m_isinf; }

	/**
	 Sets the value to NaN and removes the unit
	 Note that this does not affect bounds
	*/
	virtual void Invalidate();

	virtual bool IsValidUnit(const std::string& unit) const;
	virtual bool IsValidUnit(const std::shared_ptr<CCompoundUnit>& unit) const;
	virtual bool IsZero(double limit=zerolimit) const;
	virtual bool IsZero(const std::string& unit, double limit = zerolimit) const;
	virtual bool IsZero(const std::shared_ptr<CCompoundUnit>& unit, double limit = zerolimit) const;
	virtual bool IsPositive() const;
	virtual bool IsNegative() const;

	static bool IsZero(double value, double limit);
	static bool IsValue(double target, double value);

	virtual double GetValue(const std::string& unit=unitless) const;
	virtual double GetValue(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	virtual const std::shared_ptr<CCompoundUnit>& GetUnit() const;
	virtual const std::shared_ptr<CCompoundUnit>& GetCompoundUnit(const std::string& unit) const;

	virtual void SetValue(double d,const std::string& unit=unitless);
	virtual void SetValue(double d,const std::shared_ptr<CCompoundUnit>& unit);
	
	virtual void Increment(const SEScalar* s);
	virtual void Increment(const SEScalar& s);
	virtual double IncrementValue(double d, const std::string& unit = unitless);
	virtual double IncrementValue(double d, const std::shared_ptr<CCompoundUnit>& unit);

	virtual void Average(int cnt);
	
	virtual void BoundUpper(double upper, const std::string& boundUnit=unitless);
	virtual void BoundUpper(double upper, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void BoundUpper(SEScalar* s);

	virtual void BoundLower(double lower, const std::string& boundUnit=unitless);
	virtual void BoundLower(double lower, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void BoundLower(SEScalar* s);

	virtual void Bound(double lower, double upper, const std::string& boundUnit=unitless);
	virtual void Bound(double lower, double upper, const std::shared_ptr<CCompoundUnit>& unit);

	virtual bool Equals(const SEScalar& to) const;

	virtual void ToString(std::ostream &str) const;

	static double dNaN();
	static unsigned long long int NaN;
	static const std::string unitless;
	static std::shared_ptr<CCompoundUnit> nullUnit;
};

inline std::ostream& operator<< (std::ostream& out, const SEScalar* s)
{
	if (s==nullptr)
		out << SEScalar::NaN << std::flush;
	else
		(*s).ToString(out);
	return out;
}
inline std::ostream& operator<< (std::ostream& out, const SEScalar& s) 
{
    s.ToString(out);
    return out;
}

DLL_DECL double Convert(double d,const std::shared_ptr<CCompoundUnit>& from, const std::shared_ptr<CCompoundUnit>& to);
DLL_DECL bool   CompatibleUnits(const std::shared_ptr<CCompoundUnit>& u1, const std::shared_ptr<CCompoundUnit>& u2);
