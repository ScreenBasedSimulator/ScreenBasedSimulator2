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
#include "system/equipment/ElectroCardioGram/SEElectroCardioGram.h"
#include "bind/enumHeartRhythm.hxx"
class Serializer;

class DLL_DECL SEElectroCardioGramInterpolator : public SEElectroCardioGram
{
public:

	SEElectroCardioGramInterpolator(Logger* logger);
	virtual ~SEElectroCardioGramInterpolator();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	virtual void CalculateWaveform();

	virtual bool HasRhythm(CDM::enumHeartRhythm::value rhythm);	
	virtual bool StartNewCycle(CDM::enumHeartRhythm::value rhythm);
	virtual bool LoadWaveform(const std::string& file, Serializer& serializer, const SEScalarTime* timeStep = nullptr);

protected:

	std::map<CDM::enumHeartRhythm, std::vector<unsigned int>> m_WaveformIndexs;
	std::map<CDM::enumHeartRhythm, SEFunctionTimeVsElectricPotential*> m_Waveforms;
};