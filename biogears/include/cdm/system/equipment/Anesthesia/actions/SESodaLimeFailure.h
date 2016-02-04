#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(SodaLimeFailureData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SESodaLimeFailure : public SEAnesthesiaMachineAction
{
public:

	SESodaLimeFailure();
	virtual ~SESodaLimeFailure();
	SESodaLimeFailure(const SESodaLimeFailure& other);
	virtual void Copy(const SESodaLimeFailure& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::SodaLimeFailureData& in);
	std::unique_ptr<CDM::SodaLimeFailureData> Unload() const;
protected:
	void Unload(CDM::SodaLimeFailureData& data) const;
public:
	
	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  