#pragma once
#include "system/environment/actions/SEEnvironmentAction.h"
CDM_BIND_DECL(ActiveHeatingData)

class DLL_DECL SEActiveHeating : public Loggable
{
public:

	SEActiveHeating(Logger* logger);
	virtual ~SEActiveHeating();
	SEActiveHeating(const SEActiveHeating& other);
	virtual void Copy(const SEActiveHeating& other);
	virtual void Merge(const SEActiveHeating& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::ActiveHeatingData& in);
	std::unique_ptr<CDM::ActiveHeatingData> Unload() const;
protected:
	void Unload(CDM::ActiveHeatingData& data) const;

public:

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	virtual bool HasHeatingPower() const;
	virtual SEScalarPower& GetHeatingPower();
	virtual double GetHeatingPower(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasHeatedSurfaceArea() const;
	virtual SEScalarArea& GetHeatedSurfaceArea();
	virtual double GetHeatedSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasHeatedSurfaceAreaFraction() const;
	virtual SEScalarFraction& GetHeatedSurfaceAreaFraction();
	virtual double GetHeatedSurfaceAreaFraction() const;

	virtual void ToString(std::ostream &str) const;

protected:
	SEScalarPower*	       m_HeatingPower;
	SEScalarArea*	       m_HeatedSurfaceArea;
	SEScalarFraction*      m_HeatedSurfaceAreaFraction;
};