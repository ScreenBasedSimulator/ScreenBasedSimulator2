#pragma once
#include "scenario/SECondition.h"
CDM_BIND_DECL(EnvironmentConditionData)

class DLL_DECL SEEnvironmentCondition : public SECondition
{
public:

	SEEnvironmentCondition();
	virtual ~SEEnvironmentCondition();
	SEEnvironmentCondition(const SEEnvironmentCondition& other);
	virtual void Copy(const SEEnvironmentCondition& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::EnvironmentConditionData& in);
	std::unique_ptr<CDM::EnvironmentConditionData> Unload() const;
protected:
	void Unload(CDM::EnvironmentConditionData& data) const;
public:
	virtual void ToString(std::ostream &str) const = 0;
};  
