#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(ExpiratoryValveObstructionData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEExpiratoryValveObstruction : public SEAnesthesiaMachineAction
{
public:

	SEExpiratoryValveObstruction();
	virtual ~SEExpiratoryValveObstruction();
	SEExpiratoryValveObstruction(const SEExpiratoryValveObstruction& other);
	virtual void Copy(const SEExpiratoryValveObstruction& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::ExpiratoryValveObstructionData& in);
	std::unique_ptr<CDM::ExpiratoryValveObstructionData> Unload() const;
protected:
	void Unload(CDM::ExpiratoryValveObstructionData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  