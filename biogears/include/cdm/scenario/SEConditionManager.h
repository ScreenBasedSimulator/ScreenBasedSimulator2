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
class SECondition;
class SEChronicAnemia;
class SEChronicArrhythmia;
class SEChronicBradycardia;
class SEChronicTachycardia;
class SEChronicHeartFailure;
class SEChronicObstructivePulmonaryDisease;
class SEChronicVentricularSystolicDysfunction;
class SEChronicPulmonaryShunt;
class SEChronicRenalStenosis;
class SEDehydration;
class SEFasting;
class SEConsumeMeal;
class SELobarPneumonia;
class SEPericardialEffusionCondition;
class SEInitialEnvironment;


class DLL_DECL SEConditionManager : public Loggable
{
public:

	SEConditionManager(Logger* logger);
	~SEConditionManager();

	void Clear();
	void Reset();

	bool ProcessCondition(const SECondition& condition);

	bool HasConditions() const;
	const std::vector<SECondition*>& GetConditions() const;	

	// Not too many conditions, so just have one manager
	// If we start getting alot, I will make patient/environment/equipment condition managers, like the action managers

	// Patient Conditions

	bool HasChronicAnemia() const;
	SEChronicAnemia* GetChronicAnemia() const;

	bool HasChronicArrhythmia() const;
	bool HasChronicBradycardia() const;
	SEChronicBradycardia* GetChronicBradycardia() const;
	bool HasChronicTachycardia() const;
	SEChronicTachycardia* GetChronicTachycardia() const;

	bool HasChronicObstructivePulmonaryDisease() const;
	SEChronicObstructivePulmonaryDisease* GetChronicObstructivePulmonaryDisease() const;

	bool HasChronicHeartFailure() const;
	bool HasChronicVentricularSystolicDysfunction() const;
	SEChronicVentricularSystolicDysfunction* GetChronicVentricularSystolicDysfunction() const;

	bool HasChronicPulmonaryShunt() const;
	SEChronicPulmonaryShunt* GetChronicPulmonaryShunt() const;

	bool HasChronicRenalStenosis() const;
	SEChronicRenalStenosis* GetChronicRenalStenosis() const;

	bool HasDehydration() const;
	SEDehydration* GetDehydration() const;

	bool HasConsumeMeal() const;
	SEConsumeMeal* GetConsumeMeal() const;

	bool HasLobarPneumonia() const;
	SELobarPneumonia* GetLobarPneumonia() const;

	bool HasPericardialEffusion() const;
	SEPericardialEffusionCondition* GetPericardialEffusion() const;

	// Environment Conditions

	bool HasInitialEnvironment() const;
	SEInitialEnvironment* GetInitialEnvironment() const;
	

protected:

	SEChronicAnemia*                      m_Anemia;
	SEChronicArrhythmia*                  m_Arrhythmia;
	SEChronicObstructivePulmonaryDisease* m_COPD;
	SEChronicHeartFailure*                m_HeartFailure;
	SEChronicPulmonaryShunt*              m_PulmonaryShunt;
	SEChronicRenalStenosis*               m_RenalStenosis;
	SEDehydration*                        m_Dehydration;
	SEConsumeMeal*                        m_ConsumeMeal;
	SELobarPneumonia*                     m_LobarPneumonia;
	SEPericardialEffusionCondition*       m_PericardialEffusion;

	SEInitialEnvironment*                 m_InitialEnvironment;

	std::vector<SECondition*>             m_Conditions;
	std::stringstream m_ss;
};