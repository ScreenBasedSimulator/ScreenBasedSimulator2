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
#include "utils/testing/SETestCase.h"

CDM_BIND_DECL(TestSuite)

class DLL_DECL SETestSuite
{
public:

	SETestSuite();
	virtual ~SETestSuite();

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::TestSuite& in);
	std::unique_ptr<CDM::TestSuite> Unload();
protected:
	void Unload(CDM::TestSuite& data);

public:

	void								SetName(const std::string& Name);												
	std::string							GetName();	

	void								PerformSuite(bool Performed);											
	bool								PerformedSuite();	

	bool								HasDuration();													
	SEScalarTime*						GetDuration();
					
	std::vector<std::string>*			GetRequirements();	

	std::vector<SETestCase*>*			GetTestCases();
	
	int                                 GetNumberOfErrors();

	int									GetNumberOfTests();
								
protected:

	bool m_Performed;
	std::string m_Name;
	std::vector<std::string> m_Requirements;
	std::vector<SETestErrorStatistics*> m_SuiteEqualError;
	std::vector<SETestCase*> m_TestCase;
	SEScalarTime* m_Time;
};