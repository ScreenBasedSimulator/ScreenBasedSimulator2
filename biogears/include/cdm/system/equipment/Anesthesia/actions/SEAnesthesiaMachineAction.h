#pragma once
#include "scenario/SEAction.h"
CDM_BIND_DECL(AnesthesiaMachineActionData)

class DLL_DECL SEAnesthesiaMachineAction : public SEAction
{
public:

	SEAnesthesiaMachineAction();
	virtual ~SEAnesthesiaMachineAction();
	SEAnesthesiaMachineAction(const SEAnesthesiaMachineAction& other);
	virtual void Copy(const SEAnesthesiaMachineAction& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::AnesthesiaMachineActionData& in);
	std::unique_ptr<CDM::AnesthesiaMachineActionData> Unload() const;

protected:
	void Unload(CDM::AnesthesiaMachineActionData& data) const;
public:
	virtual void ToString(std::ostream &str) const = 0;
};  