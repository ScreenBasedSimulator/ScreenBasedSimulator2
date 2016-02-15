#pragma once
#include "../SEEnvironmentalConditions.h"
#include "SEEnvironmentCondition.h"
CDM_BIND_DECL(InitialEnvironmentData)

class DLL_DECL SEInitialEnvironment : public SEEnvironmentCondition
{
public:

	SEInitialEnvironment(SESubstanceManager& substances);
	virtual ~SEInitialEnvironment();
	SEInitialEnvironment(const SEInitialEnvironment& other);
	virtual void Copy(const SEInitialEnvironment& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::InitialEnvironmentData& in);
	std::unique_ptr<CDM::InitialEnvironmentData> Unload() const;

protected:
	void Unload(CDM::InitialEnvironmentData& data) const;
public:
	virtual std::string GetName() const{ return "InitialEnvironment"; }

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
