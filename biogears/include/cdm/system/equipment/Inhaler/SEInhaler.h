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
#include "system/SESystem.h"
CDM_BIND_DECL(InhalerData)
#include "bind/enumOnOff.hxx"
class Serializer; 
class SESubstance;
class SESubstanceManager;
class SEInhalerConfiguration;

class DLL_DECL SEInhaler : public SESystem
{
protected:

public:

	SEInhaler(SESubstanceManager& substances);
	virtual ~SEInhaler();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	void Copy(const SEInhaler& from);
	void Merge(const SEInhaler& from);

	/** @name GetScalar
	*   @brief - A reflextion type call that will return the Scalar associated
	*            with the string. ex. GetScalar("Hematocrit") will return the
	*            SEScalarPercent object associated with Hematocrit
	*   @details - Note this is an expensive call as it will string compare many times
	*              This is best used, and intended for, you to dynamically prepopulate
	*              a mapping data structure that will help access what you need
	*/
	virtual const SEScalar* GetScalar(const std::string& name);

	bool Load(const CDM::InhalerData& in);
	std::unique_ptr<CDM::InhalerData> Unload() const;
protected:
	void Unload(CDM::InhalerData& data) const;
public:

	/** @name LoadFile
	*   @brief Clear and set contents to this file
	*/
	bool LoadFile(const std::string& file, const Serializer& serlializer);

	/** @name StateChange
	*   @brief - This method is called when ever there is a state change
	*            Specically a new file has been loaded, configuration action, or the system reset
	*            Engine specific methodology can then update their logic.
	*/
	virtual void StateChange(){};
	void ProcessConfiguration(const SEInhalerConfiguration& config);

	virtual CDM::enumOnOff::value GetState() const;
	virtual void SetState(CDM::enumOnOff::value name);
	virtual bool HasState() const;
	virtual void InvalidateState();

	virtual bool HasMeteredDose() const;
	virtual SEScalarMass& GetMeteredDose();
	virtual double GetMeteredDose(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasNozzleLoss() const;
	virtual SEScalarFraction& GetNozzleLoss();
	virtual double GetNozzleLoss(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSpacerVolume() const;
	virtual SEScalarVolume& GetSpacerVolume();
	virtual double GetSpacerVolume(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasSubstance() const;
	virtual void SetSubstance(const SESubstance* sub);
	virtual SESubstance* GetSubstance() const;

protected:

	std::stringstream	  m_ss;

	CDM::enumOnOff::value m_State;
	SEScalarMass*         m_MeteredDose;
	SEScalarFraction*     m_NozzleLoss;
	SEScalarVolume*       m_SpacerVolume;
	const SESubstance*    m_Substance;

	SESubstanceManager&   m_Substances;
};
