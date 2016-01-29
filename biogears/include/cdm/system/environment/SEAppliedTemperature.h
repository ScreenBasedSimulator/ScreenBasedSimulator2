#pragma once
#include "system/environment/actions/SEEnvironmentAction.h"
CDM_BIND_DECL(AppliedTemperatureData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEAppliedTemperature : public Loggable
{
public:

	SEAppliedTemperature(Logger* logger);
	virtual ~SEAppliedTemperature();
	SEAppliedTemperature(const SEAppliedTemperature& other);
	virtual void Copy(const SEAppliedTemperature& other);
	virtual void Merge(const SEAppliedTemperature& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::AppliedTemperatureData& in);
	std::unique_ptr<CDM::AppliedTemperatureData> Unload() const;
protected:
	void Unload(CDM::AppliedTemperatureData& data) const;

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

	virtual bool HasAppliedTemperature() const;
	virtual SEScalarTemperature& GetAppliedTemperature();
	virtual double GetAppliedTemperature(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasAppliedSurfaceArea() const;
	virtual SEScalarArea& GetAppliedSurfaceArea();
	virtual double GetAppliedSurfaceArea(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasAppliedSurfaceAreaFraction() const;
	virtual SEScalarFraction& GetAppliedSurfaceAreaFraction();
	virtual double GetAppliedSurfaceAreaFraction() const;

	virtual CDM::enumOnOff::value GetAppliedTemperatureState() const;
	virtual void SetAppliedTemperatureState(CDM::enumOnOff::value onOff);

	virtual void ToString(std::ostream &str) const;

protected:
	
	SEScalarTemperature*   m_AppliedTemperature;
	SEScalarArea*	       m_AppliedSurfaceArea;
	SEScalarFraction*      m_AppliedSurfaceAreaFraction;
	CDM::enumOnOff::value  m_ApplyTemperature;
};