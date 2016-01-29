#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(InspiratoryValveObstructionData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEInspiratoryValveObstruction : public SEAnesthesiaMachineAction
{
public:

	SEInspiratoryValveObstruction();
	virtual ~SEInspiratoryValveObstruction();
	SEInspiratoryValveObstruction(const SEInspiratoryValveObstruction& other);
	virtual void Copy(const SEInspiratoryValveObstruction& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::InspiratoryValveObstructionData& in);
	std::unique_ptr<CDM::InspiratoryValveObstructionData> Unload() const;
protected:
	void Unload(CDM::InspiratoryValveObstructionData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  