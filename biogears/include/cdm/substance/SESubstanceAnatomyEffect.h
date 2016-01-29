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
#include "substance/SESubstanceCompartmentEffect.h"
#include "bind/enumAnatomy.hxx"
CDM_BIND_DECL(SubstanceAnatomyEffectData)

class DLL_DECL SESubstanceAnatomyEffect : public SESubstanceCompartmentEffect
{
public:

	SESubstanceAnatomyEffect(Logger* logger);
	virtual ~SESubstanceAnatomyEffect();

	virtual void Clear(); //clear memory
	virtual void Reset(); //reset values

	bool Load(const CDM::SubstanceAnatomyEffectData& in);
	std::unique_ptr<CDM::SubstanceAnatomyEffectData> Unload() const;
protected:
	void Unload(CDM::SubstanceAnatomyEffectData& data) const;
public:
	
	virtual CDM::enumAnatomy::value GetAnatomyCompartment() const;
	virtual void SetAnatomyCompartment(CDM::enumAnatomy::value cmpt);
	virtual bool HasAnatomyCompartment() const;
	virtual void InvalidateAnatomyCompartment();

protected:

	CDM::enumAnatomy::value m_AnatomyCompartment;
};