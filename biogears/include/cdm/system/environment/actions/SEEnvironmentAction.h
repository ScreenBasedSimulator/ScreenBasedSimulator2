#pragma once
#include "scenario/SEAction.h"
CDM_BIND_DECL(EnvironmentActionData)

class DLL_DECL SEEnvironmentAction : public SEAction
{
public:

	SEEnvironmentAction();
	virtual ~SEEnvironmentAction();
	SEEnvironmentAction(const SEEnvironmentAction& other);
	virtual void Copy(const SEEnvironmentAction& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::EnvironmentActionData& in);
	std::unique_ptr<CDM::EnvironmentActionData> Unload() const;

protected:
	void Unload(CDM::EnvironmentActionData& data) const;
public:
	virtual void ToString(std::ostream &str) const = 0;
};  