#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(AnesthesiaMachineConfigurationData)
class SEAnesthesiaMachine;
class SESubstanceManager;

class DLL_DECL SEAnesthesiaMachineConfiguration : public SEAnesthesiaMachineAction
{
public:

	SEAnesthesiaMachineConfiguration(SESubstanceManager& substances);
	virtual ~SEAnesthesiaMachineConfiguration();
	SEAnesthesiaMachineConfiguration(const SEAnesthesiaMachineConfiguration& other);
	virtual void Copy(const SEAnesthesiaMachineConfiguration& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;

	bool Load(const CDM::AnesthesiaMachineConfigurationData& in);
	std::unique_ptr<CDM::AnesthesiaMachineConfigurationData> Unload() const;

protected:
	void Unload(CDM::AnesthesiaMachineConfigurationData& data) const;
public:

	bool HasConfiguration() const;
	SEAnesthesiaMachine& GetConfiguration();
	const SEAnesthesiaMachine* GetConfiguration() const;

	virtual std::string GetConfigurationFile() const;
	virtual void SetConfigurationFile(const std::string& fileName);
	virtual bool HasConfigurationFile() const;
	virtual void InvalidateConfigurationFile();

	virtual void ToString(std::ostream &str) const;

protected:
	SESubstanceManager&  m_Substances;

	std::string          m_ConfigurationFile;
	SEAnesthesiaMachine* m_Configuration;
};