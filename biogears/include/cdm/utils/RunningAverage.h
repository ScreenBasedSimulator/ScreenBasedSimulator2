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

class DLL_DECL RunningAverage
{
public:
	
	RunningAverage(unsigned int sampleCount, double init);

	/** Reset Counter info */
	void Reset();
	/** Reset Counter info to a specific init value*/
	void Reset(double toValue);
	/** Add value to Sample list and return the new average */
	double Sample(double d);
	/** Return the average value */
	double Value();
	
protected:

	std::vector<double> m_Samples;
	unsigned int        m_NextIndex;
	double              m_Sum;
	double              m_Init;
};
