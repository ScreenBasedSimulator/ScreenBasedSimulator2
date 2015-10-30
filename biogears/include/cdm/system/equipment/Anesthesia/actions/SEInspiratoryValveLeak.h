#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(InspiratoryValveLeakData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEInspiratoryValveLeak : public SEAnesthesiaMachineAction
{
public:

	SEInspiratoryValveLeak();
	virtual ~SEInspiratoryValveLeak();
	SEInspiratoryValveLeak(const SEInspiratoryValveLeak& other);
	virtual void Copy(const SEInspiratoryValveLeak& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::InspiratoryValveLeakData& in);
	std::unique_ptr<CDM::InspiratoryValveLeakData> Unload() const;
protected:
	void Unload(CDM::InspiratoryValveLeakData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  