#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(TubeCuffLeakData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SETubeCuffLeak : public SEAnesthesiaMachineAction
{
public:

	SETubeCuffLeak();
	virtual ~SETubeCuffLeak();
	SETubeCuffLeak(const SETubeCuffLeak& other);
	virtual void Copy(const SETubeCuffLeak& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::TubeCuffLeakData& in);
	std::unique_ptr<CDM::TubeCuffLeakData> Unload() const;
protected:
	void Unload(CDM::TubeCuffLeakData& data) const;
public:
	
	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  