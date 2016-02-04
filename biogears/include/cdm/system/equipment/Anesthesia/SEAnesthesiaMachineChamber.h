/**************************************************************************************
Copyright 2015 Applied Research Associates, Inc.
Licensed under the Apache License, Version 2.0 (the "License"); you may not use
this file except in compliance with the License. You may obtain a copy of the License
at:
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software distributed under
the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
CONDITIONS OF ANY KIND, either express or implied. See the License for the
specific language governing permissions and limitations under the License.
**************************************************************************************/

#pragma once
class SESubstance;
class SESubstanceManager;
class SEAnesthesiaMachine;
CDM_BIND_DECL(AnesthesiaMachineChamberData)
#include "bind/enumOnOff.hxx"

class DLL_DECL SEAnesthesiaMachineChamber : Loggable
{
protected:
	friend SEAnesthesiaMachine;
public:

	SEAnesthesiaMachineChamber(Logger* logger);
	virtual ~SEAnesthesiaMachineChamber();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	void Copy(const SEAnesthesiaMachineChamber& from);
	void Merge(const SEAnesthesiaMachineChamber& from);

	bool Load(const CDM::AnesthesiaMachineChamberData& in, SESubstanceManager& subMgr);
	std::unique_ptr<CDM::AnesthesiaMachineChamberData> Unload() const;
protected:
	void Unload(CDM::AnesthesiaMachineChamberData& data) const;

public:

	virtual CDM::enumOnOff::value GetState() const;
	virtual void SetState(CDM::enumOnOff::value name);
	virtual bool HasState() const;
	virtual void InvalidateState();

	virtual bool HasSubstanceFraction() const;
	virtual SEScalarFraction& GetSubstanceFraction();
	virtual double GetSubstanceFraction() const;

	virtual bool HasSubstance() const;
	virtual SESubstance* GetSubstance() const;
	virtual void SetSubstance(const SESubstance& substance);
	virtual void RemoveSubstance();

	virtual void ToString(std::ostream &str) const;

protected:

	CDM::enumOnOff::value m_State;
	const SESubstance*    m_Substance;
	SEScalarFraction*     m_SubstanceFraction;

};
