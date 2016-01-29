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
#include "patient/actions/SESubstanceAdministration.h"
class SESubstance;
CDM_BIND_DECL(SubstanceBolusData)
#include "bind/enumSubstanceAdministration.hxx"

class DLL_DECL SESubstanceBolus : public SESubstanceAdministration
{
public:

	SESubstanceBolus(const SESubstance& substance);
	virtual ~SESubstanceBolus();
	SESubstanceBolus(const SESubstanceBolus& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;

	bool Load(const CDM::SubstanceBolusData& in);
	std::unique_ptr<CDM::SubstanceBolusData> Unload() const;
protected:
	void Unload(CDM::SubstanceBolusData& data) const;
public:

	virtual CDM::enumSubstanceAdministration::value GetAdminRoute() const;
	virtual void SetAdminRoute(CDM::enumSubstanceAdministration::value name);
	virtual bool HasAdminRoute() const;
	virtual void InvalidateAdminRoute();

	virtual bool HasConcentration() const;
	virtual SEScalarMassPerVolume& GetConcentration();

	virtual bool HasDose() const;
	virtual SEScalarVolume& GetDose();	

	virtual SESubstance& GetSubstance() const;

	virtual void ToString(std::ostream &str) const;

protected:
	CDM::enumSubstanceAdministration::value m_AdminRoute;
	SEScalarMassPerVolume*                  m_Concentration;
	SEScalarVolume*                         m_Dose;
	const SESubstance&                      m_Substance;
	
};                 