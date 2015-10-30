#pragma once

#include "SEInhalerAction.h"

CDM_BIND_DECL(InhalerConfigurationData)

class SEInhaler;
class SESubstanceManager;

class DLL_DECL SEInhalerConfiguration : public SEInhalerAction
{
public:

	SEInhalerConfiguration(SESubstanceManager& substances);
	virtual ~SEInhalerConfiguration();
	SEInhalerConfiguration(const SEInhalerConfiguration& other);
	virtual void Copy(const SEInhalerConfiguration& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::InhalerConfigurationData& in);
	std::unique_ptr<CDM::InhalerConfigurationData> Unload() const;

protected:
	void Unload(CDM::InhalerConfigurationData& data) const;
public:

	bool HasConfiguration() const;
	SEInhaler& GetConfiguration();
	const SEInhaler* GetConfiguration() const;

	virtual std::string GetConfigurationFile() const;
	virtual void SetConfigurationFile(const std::string& fileName);
	virtual bool HasConfigurationFile() const;
	virtual void InvalidateConfigurationFile();

	virtual void ToString(std::ostream &str) const;

protected:
	SESubstanceManager&  m_Substances;

	std::string m_ConfigurationFile;
	SEInhaler*  m_Configuration;
};
