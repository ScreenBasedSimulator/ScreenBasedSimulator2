#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(YPieceDisconnectData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEYPieceDisconnect : public SEAnesthesiaMachineAction
{
public:

	SEYPieceDisconnect();
	virtual ~SEYPieceDisconnect();
	SEYPieceDisconnect(const SEYPieceDisconnect& other);
	virtual void Copy(const SEYPieceDisconnect& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::YPieceDisconnectData& in);
	std::unique_ptr<CDM::YPieceDisconnectData> Unload() const;
protected:
	void Unload(CDM::YPieceDisconnectData& data) const;
public:

	virtual bool HasSeverity() const;
	virtual SEScalarFraction& GetSeverity();

	virtual void ToString(std::ostream &str) const;

protected:

	SEScalarFraction*     m_Severity;
};  