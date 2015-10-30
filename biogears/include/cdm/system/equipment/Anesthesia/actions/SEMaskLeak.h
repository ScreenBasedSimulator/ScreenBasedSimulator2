#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(MaskLeakData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEMaskLeak : public SEAnesthesiaMachineAction
{
public:

	SEMaskLeak();
	virtual ~SEMaskLeak();
	SEMaskLeak(const SEMaskLeak& other);
	virtual void Copy(const SEMaskLeak& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::MaskLeakData& in);
	std::unique_ptr<CDM::MaskLeakData> Unload() const;
protected:
	void Unload(CDM::MaskLeakData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  