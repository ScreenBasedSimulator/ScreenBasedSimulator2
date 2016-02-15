#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(OxygenWallPortPressureLossData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEOxygenWallPortPressureLoss : public SEAnesthesiaMachineAction
{
public:
	SEOxygenWallPortPressureLoss();
	virtual ~SEOxygenWallPortPressureLoss();
	SEOxygenWallPortPressureLoss(const SEOxygenWallPortPressureLoss& other);
	virtual void Copy(const SEOxygenWallPortPressureLoss& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;
	virtual void SetActive(bool b);

	bool Load(const CDM::OxygenWallPortPressureLossData& in);
	std::unique_ptr<CDM::OxygenWallPortPressureLossData> Unload() const;
protected:
	void Unload(CDM::OxygenWallPortPressureLossData& data) const;
public:

	virtual void ToString(std::ostream &str) const;

protected:
	
	CDM::enumOnOff::value m_State;
};  