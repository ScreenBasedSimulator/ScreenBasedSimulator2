#pragma once
#include "system/environment/actions/SEEnvironmentAction.h"
CDM_BIND_DECL(ThermalApplicationData)
class SEActiveHeating;
class SEActiveCooling;
class SEAppliedTemperature;

class DLL_DECL SEThermalApplication : public SEEnvironmentAction
{
public:

	SEThermalApplication();
	virtual ~SEThermalApplication();
	SEThermalApplication(const SEThermalApplication& other);
	virtual void Copy(const SEThermalApplication& other);
	virtual void Merge(const SEThermalApplication& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::ThermalApplicationData& in);
	std::unique_ptr<CDM::ThermalApplicationData> Unload() const;
protected:
	void Unload(CDM::ThermalApplicationData& data) const;

public:

	virtual bool HasActiveHeating() const;
	virtual SEActiveHeating& GetActiveHeating();
	virtual void RemoveActiveHeating();

	virtual bool HasActiveCooling() const;
	virtual SEActiveCooling& GetActiveCooling();
	virtual void RemoveActiveCooling();

	virtual bool HasAppliedTemperature() const;
	virtual SEAppliedTemperature& GetAppliedTemperature();
	virtual void RemoveAppliedTemperature();

	virtual void ToString(std::ostream &str) const;

protected:
	SEActiveHeating*	   m_ActiveHeating;
	SEActiveCooling*	   m_ActiveCooling;
	SEAppliedTemperature*  m_AppliedTemperature;
};