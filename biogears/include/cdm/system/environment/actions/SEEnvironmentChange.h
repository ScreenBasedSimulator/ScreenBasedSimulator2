#pragma once
#include "system/environment/SEEnvironmentalConditions.h"
#include "system/environment/actions/SEEnvironmentAction.h"
CDM_BIND_DECL(EnvironmentChangeData)

class DLL_DECL SEEnvironmentChange : public SEEnvironmentAction
{
public:

	SEEnvironmentChange(SESubstanceManager& substances);
	virtual ~SEEnvironmentChange();
	SEEnvironmentChange(const SEEnvironmentChange& other);
	virtual void Copy(const SEEnvironmentChange& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::EnvironmentChangeData& in);
	std::unique_ptr<CDM::EnvironmentChangeData> Unload() const;

protected:
	void Unload(CDM::EnvironmentChangeData& data) const;
public:
	
	virtual bool HasConditions() const;
	virtual SEEnvironmentalConditions& GetConditions();
	virtual const SEEnvironmentalConditions* GetConditions() const;

	virtual std::string GetConditionsFile() const;
	virtual void SetConditionsFile(const std::string& fileName);
	virtual bool HasConditionsFile() const;
	virtual void InvalidateConditionsFile();
	
	virtual void ToString(std::ostream &str) const;

protected:
	SESubstanceManager&  m_Substances;

	std::string                m_ConditionsFile;
	SEEnvironmentalConditions* m_Conditions;
};  
