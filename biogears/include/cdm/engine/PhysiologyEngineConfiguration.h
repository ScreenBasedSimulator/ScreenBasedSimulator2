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
class Serializer;
class PhysiologyEngineStabilization;
#include "utils/GeneralMath.h"

CDM_BIND_DECL(PhysiologyEngineConfigurationData)

class DLL_DECL PhysiologyEngineConfiguration : public Loggable
{
public:

	PhysiologyEngineConfiguration(const Serializer& serlializer);
	virtual ~PhysiologyEngineConfiguration();

	virtual void Reset();
	virtual void Clear();
	virtual void Merge(const PhysiologyEngineConfiguration& from);

	virtual bool Load(const CDM::PhysiologyEngineConfigurationData& in);
	std::unique_ptr<CDM::PhysiologyEngineConfigurationData> Unload() const;
protected:
	void Unload(CDM::PhysiologyEngineConfigurationData& data) const;
public:
	virtual bool LoadConfigurationFile(const std::string& configFile);

	virtual bool HasTimeStep() const;
	virtual SEScalarTime& GetTimeStep();
	virtual double GetTimeStep(const std::shared_ptr<CCompoundUnit>& unit) const;

	virtual bool HasStabilizationCriteriaFile() const;
	virtual std::string GetStabilizationCriteriaFile() const;
	virtual void SetStabilizationCriteriaFile(const std::string& stabilizationFile);
	virtual void InvalidateStabilizationCriteriaFile();

	virtual bool HasStabilizationCriteria() const;
	virtual PhysiologyEngineStabilization* GetStabilizationCriteria();
	virtual const PhysiologyEngineStabilization* GetStabilizationCriteria() const;
	virtual void SetStabilizationCriteria(PhysiologyEngineStabilization& stabilization);
	virtual void InvalidateStabilizationCriteria();

	virtual bool HasECGDataFile() const ;
	virtual std::string GetECGDataFile() const;
	virtual void SetECGDataFile(const std::string& ecgDataFile);
	virtual void InvalidateECGDataFile();

	virtual SaturationCalculator& GetSaturationCalculator();
	virtual const SaturationCalculator& GetSaturationCalculator() const;

protected:

	const Serializer&              m_Serializer;

	SEScalarTime*				   m_TimeStep;
	PhysiologyEngineStabilization* m_StabilizationCriteria;
	std::string                    m_StabilizationCriteriaFile;	
	std::string                    m_ECGDataFile;

	SaturationCalculator           m_SaturationCalculator;
};