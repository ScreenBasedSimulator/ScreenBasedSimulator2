#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(VaporizerFailureData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEVaporizerFailure : public SEAnesthesiaMachineAction
{
public:

	SEVaporizerFailure();
	virtual ~SEVaporizerFailure();
	SEVaporizerFailure(const SEVaporizerFailure& other);
	virtual void Copy(const SEVaporizerFailure& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::VaporizerFailureData& in);
	std::unique_ptr<CDM::VaporizerFailureData> Unload() const;
protected:
	void Unload(CDM::VaporizerFailureData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  