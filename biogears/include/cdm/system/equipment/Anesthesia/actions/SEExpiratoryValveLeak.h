#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(ExpiratoryValveLeakData)

class DLL_DECL SEExpiratoryValveLeak : public SEAnesthesiaMachineAction
{
public:

	SEExpiratoryValveLeak();
	virtual ~SEExpiratoryValveLeak();
	SEExpiratoryValveLeak(const SEExpiratoryValveLeak& other);
	virtual void Copy(const SEExpiratoryValveLeak& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::ExpiratoryValveLeakData& in);
	std::unique_ptr<CDM::ExpiratoryValveLeakData> Unload() const;
protected:
	void Unload(CDM::ExpiratoryValveLeakData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  