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
CDM_BIND_DECL(PatientAssessmentData)
/**
 * @brief
 * Data formed at a level of a clinicians report. 
 * This is high level data, such as a mean or generalized data 
 * value intended to give a genaral overview of the patient (SEPatientAssessment) or other systems
 */
class DLL_DECL SEPatientAssessment : public Loggable
{
public:

	SEPatientAssessment(Logger* logger);
	virtual ~SEPatientAssessment();

	/// Resets all values to be invalid
	virtual void Reset(); 
	/// Deletes all member variables
	virtual void Clear();

	/**
	* @name Serialization
	*
	* @brief Serializing data to and from bind classes
	*/
	//@{
	/// Reset and set data value to bind values
	bool Load(const CDM::PatientAssessmentData& in);
	/// Create and push all data values to a bind class
	std::unique_ptr<CDM::PatientAssessmentData> Unload();
protected:
	/// Push this data to bind class
	void Unload(CDM::PatientAssessmentData& data);
	//@}
public:
	
};  