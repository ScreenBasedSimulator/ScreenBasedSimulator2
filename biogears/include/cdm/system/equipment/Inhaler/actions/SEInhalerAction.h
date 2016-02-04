#pragma once
#include "scenario/SEAction.h"
CDM_BIND_DECL(InhalerActionData)

class DLL_DECL SEInhalerAction : public SEAction
{
public:

	SEInhalerAction();
	virtual ~SEInhalerAction();
	SEInhalerAction(const SEInhalerAction& other);
	virtual void Copy(const SEInhalerAction& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::InhalerActionData& in);
	std::unique_ptr<CDM::InhalerActionData> Unload() const;

protected:
	void Unload(CDM::InhalerActionData& data) const;
public:
	virtual void ToString(std::ostream &str) const = 0;
};  