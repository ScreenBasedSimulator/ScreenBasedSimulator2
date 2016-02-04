#pragma once
#include "system/environment/actions/SEEnvironmentAction.h"
CDM_BIND_DECL(ActiveCoolingData)

class DLL_DECL SEActiveCooling : public Loggable
{
public:

	SEActiveCooling(Logger* logger);
	virtual ~SEActiveCooling();
	SEActiveCooling(const SEActiveCooling& other);
	virtual void Copy(const SEActiveCooling& other);
	virtual void Merge(const SEActiveCooling& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::ActiveCoolingData& in);
	std::unique_ptr<CDM::ActiveCoolingData> Unload() const;
protected:
	void Unload(CDM::ActiveCoolingData& data) const;

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

	virtual bool HasCoolingPower() const;
	virtual SEScalarPower& GetCoolingPower();
	virtual double GetCoolingPower(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCooledSurfaceArea() const;
	virtual SEScalarArea& GetCooledSurfaceArea();
	virtual double GetCooledSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasCooledSurfaceAreaFraction() const;
	virtual SEScalarFraction& GetCooledSurfaceAreaFraction();
	virtual double GetCooledSurfaceAreaFraction() const;

	virtual void ToString(std::ostream &str) const;

protected:
	SEScalarPower*	       m_CoolingPower;
	SEScalarArea*	       m_CooledSurfaceArea;
	SEScalarFraction*      m_CooledSurfaceAreaFraction;
};