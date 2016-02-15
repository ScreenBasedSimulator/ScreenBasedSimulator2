#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(VentilatorPressureLossData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEVentilatorPressureLoss : public SEAnesthesiaMachineAction
{
public:

	SEVentilatorPressureLoss();
	virtual ~SEVentilatorPressureLoss();
	SEVentilatorPressureLoss(const SEVentilatorPressureLoss& other);
	virtual void Copy(const SEVentilatorPressureLoss& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::VentilatorPressureLossData& in);
	std::unique_ptr<CDM::VentilatorPressureLossData> Unload() const;
protected:
	void Unload(CDM::VentilatorPressureLossData& data) const;
public:
	
	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  