#pragma once
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineAction.h"
CDM_BIND_DECL(OxygenTankPressureLossData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEOxygenTankPressureLoss : public SEAnesthesiaMachineAction
{
public:
	SEOxygenTankPressureLoss();
	virtual ~SEOxygenTankPressureLoss();
	SEOxygenTankPressureLoss(const SEOxygenTankPressureLoss& other);
	virtual void Copy(const SEOxygenTankPressureLoss& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;
	virtual void SetActive(bool b);

	bool Load(const CDM::OxygenTankPressureLossData& in);
	std::unique_ptr<CDM::OxygenTankPressureLossData> Unload() const;
protected:
	void Unload(CDM::OxygenTankPressureLossData& data) const;
public:

	virtual void ToString(std::ostream &str) const;

protected:
	
	CDM::enumOnOff::value m_State;
};  