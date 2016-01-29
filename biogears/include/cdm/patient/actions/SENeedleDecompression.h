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
#include "patient/actions/SEPatientAction.h"
CDM_BIND_DECL(NeedleDecompressionData)
#include "bind/enumSide.hxx"
#include "bind/enumOnOff.hxx"

class DLL_DECL SENeedleDecompression : public SEPatientAction
{
public:

	SENeedleDecompression();
	virtual ~SENeedleDecompression();
	SENeedleDecompression(const SENeedleDecompression& other);
	virtual void Copy(const SENeedleDecompression& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual bool IsValid() const;
	virtual bool IsActive() const;
	virtual void SetActive(bool b);

	bool Load(const CDM::NeedleDecompressionData& in);
	std::unique_ptr<CDM::NeedleDecompressionData> Unload() const;
protected:
	void Unload(CDM::NeedleDecompressionData& data) const;
public:

	virtual CDM::enumSide::value GetSide() const;
	virtual void SetSide(CDM::enumSide::value LeftOrRight);
	virtual bool HasSide() const;
	virtual void InvalidateSide();
	
	virtual void ToString(std::ostream &str) const;

protected:
	CDM::enumSide::value m_Side;
	CDM::enumOnOff::value m_State;
	
};    