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

#include "PhysiologyEngineStabilization.h"
#include "bind/enumAnatomy.hxx"
#include "bind/enumCompartmentType.hxx"

class SEDataRequest;
class CCompoundUnit; 
class SESubstance;
class PhysiologyEngineDynamicStabilizationCriteria;

class DLL_DECL PropertyConvergence
{
	friend PhysiologyEngineDynamicStabilizationCriteria;	
protected:
	PropertyConvergence(SEDataRequest* dr);// Yes, I will delete it
public:
	virtual ~PropertyConvergence();

	bool Test(double time_s);

	double GetPercentError() const;
	double GetLastPercentError() const;
	double GetLastErrorTime_s() const;
	SEDataRequest& GetDataRequest() const;
	void SetScalar(const SEScalar& scalar);
	bool IsOptional() const;
	void SetOptional(bool b);

protected:
	
	const SEScalar* m_Property;
	SEDataRequest*  m_DataRequest;//Could be ptr to derived types

	bool            m_Optional;
	double          m_Target;
	double          m_Error;
	double          m_LastError;
	double          m_LastErrorTime_s;
};

class PhysiologyEngineDynamicStabilization;
CDM_BIND_DECL(PhysiologyEngineDynamicStabilizationCriteriaData)
class DLL_DECL PhysiologyEngineDynamicStabilizationCriteria : public Loggable
{
	friend PhysiologyEngineDynamicStabilization;
public:

	PhysiologyEngineDynamicStabilizationCriteria(Logger* logger);
	virtual ~PhysiologyEngineDynamicStabilizationCriteria();

	void Reset();
	void Clear();

	bool Load(const CDM::PhysiologyEngineDynamicStabilizationCriteriaData& in);
	std::unique_ptr<CDM::PhysiologyEngineDynamicStabilizationCriteriaData> Unload() const;
protected:
	void Unload(CDM::PhysiologyEngineDynamicStabilizationCriteriaData& data) const;
public:

	std::string GetName() const;
	void SetName(const std::string& name);
	bool HasName() const;
	void InvalidateName();

	bool HasConvergenceTime() const;
	SEScalarTime& GetConvergenceTime();
	virtual double GetConvergenceTime(const std::shared_ptr<CCompoundUnit>& unit) const;

	bool HasMinimumReactionTime() const;
	SEScalarTime& GetMinimumReactionTime();
	virtual double GetMinimumReactionTime(const std::shared_ptr<CCompoundUnit>& unit) const;

	bool HasMaximumAllowedStabilizationTime() const;
	SEScalarTime& GetMaximumAllowedStabilizationTime();
	virtual double GetMaximumAllowedStabilizationTime(const std::shared_ptr<CCompoundUnit>& unit) const;
	
	const std::vector<PropertyConvergence*>& GetPropertyConvergence() const;
	PropertyConvergence& CreateSystemPropertyConvergence(double percentError, const std::string& name);
	PropertyConvergence& CreateAnatomyPropertyConvergence(double percentError, CDM::enumAnatomy::value cmpt, CDM::enumCompartmentType::value type, std::string& name);
	PropertyConvergence& CreateAnatomySubstancePropertyConvergence(double percentError, CDM::enumAnatomy::value cmpt, CDM::enumCompartmentType::value type, const SESubstance& substance, const std::string& name);

protected:
	std::string          m_Name;
	SEScalarTime*        m_ConvergenceTime;
	SEScalarTime*        m_MinimumReactionTime;
	SEScalarTime*        m_MaximumAllowedStabilizationTime;

	std::vector<PropertyConvergence*> m_PropertyConvergence;

};

class DLL_DECL PhysiologyEngineDynamicStabilizer : public Loggable
{
public:
	PhysiologyEngineDynamicStabilizer(double timeStep_s, const PhysiologyEngineDynamicStabilizationCriteria& criteria);
	virtual ~PhysiologyEngineDynamicStabilizer(){};

	void Converge();
	bool HasConverged(){ return m_converged; }
	bool HasConvergedOptional(){ return m_convergedOptional; }
	bool HasExceededTime(){ return m_exceededTime; }

protected:

	bool   m_converged;
	bool   m_convergedOptional;
	bool   m_exceededTime;
	bool   m_hasOptionalProperties;
	double m_dT_s;
	double m_totTime_s;// Total time we have been converging
	double m_covTime_s;// Convergence Window Length
	double m_minTime_s;// Minimum amount of time to run before testing
	double m_maxTime_s;// Maximum amount of time to run before we quit
	double m_passTime_s;
	double m_optsPassTime_s;

	const std::vector<PropertyConvergence*>& m_properties;
};

CDM_BIND_DECL(PhysiologyEngineDynamicStabilizationData)
class DLL_DECL PhysiologyEngineDynamicStabilization : public PhysiologyEngineStabilization
{
public:
	PhysiologyEngineDynamicStabilization(Logger* logger);
	virtual ~PhysiologyEngineDynamicStabilization();

	void Reset();
	void Clear();

	bool Load(const CDM::PhysiologyEngineDynamicStabilizationData& in);
	std::unique_ptr<CDM::PhysiologyEngineDynamicStabilizationData> Unload() const;
protected:
	void Unload(CDM::PhysiologyEngineDynamicStabilizationData& data) const;
public:

	bool StabilizeRestingState(PhysiologyEngine& engine);
	bool StabilizeFeedbackState(PhysiologyEngine& engine);
	bool StabilizeConditions(PhysiologyEngine& engine, const std::vector<const SECondition*>& conditions);

	PhysiologyEngineDynamicStabilizationCriteria& GetRestingCriteria();
	const PhysiologyEngineDynamicStabilizationCriteria& GetRestingCriteria() const;

	bool HasFeedbackCriteria() const;
	PhysiologyEngineDynamicStabilizationCriteria& GetFeedbackCriteria();
	const PhysiologyEngineDynamicStabilizationCriteria* GetFeedbackCriteria() const;

	void RemoveConditionCriteria(const std::string& name);
	void AddConditionCriteria(PhysiologyEngineDynamicStabilizationCriteria& criteria);
	const std::vector<PhysiologyEngineDynamicStabilizationCriteria*>& GetConditionCriteria() const;
	PhysiologyEngineDynamicStabilizationCriteria* GetConditionCriteria(const std::string& name) const;

protected:

	bool Stabilize(PhysiologyEngine& engine, const PhysiologyEngineDynamicStabilizationCriteria& criteria);

	PhysiologyEngineDynamicStabilizationCriteria m_RestingCriteria;
	PhysiologyEngineDynamicStabilizationCriteria* m_FeedbackCriteria;
	std::vector<PhysiologyEngineDynamicStabilizationCriteria*> m_ConditionCriteria;

	bool Merge();
	PhysiologyEngineDynamicStabilizationCriteria m_MergedConditions;
	std::vector<PhysiologyEngineDynamicStabilizationCriteria*> m_ActiveConditions;
};
