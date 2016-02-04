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

#include "substance/SESubstance.h"

class SECircuit;
typedef std::map<std::string, double> ProbeMap;
typedef std::map<std::string, double>::iterator ProbeMapItr;
typedef std::map<std::string, std::vector<double>*> TrackMap;
typedef std::map<std::string, std::vector<double>*>::iterator TrackMapItr;

class DLL_DECL DataTrack : public Loggable
{
public:
	DataTrack();
	DataTrack(Logger *m_Log);
	~DataTrack();

	void Clear();
	void Reset();

	std::vector<std::string>*  GetHeadings();

	void Probe(const std::string& name, double value, int i);
	void Probe(const std::string& name, double value);
	void Probe(SECircuit* circuit);
	double GetProbe(const std::string& name);
	ProbeMap* GetProbes();

	void Track(const std::string& name, double time, double value);	
	void Track(double time, SECircuit* circuit);
	void Track(double time, SECircuit* circuit, const std::vector<SESubstance*>* vSubstances);

	// Reads the entire file and stores contents into memory, returns the column headings
	std::vector<std::string> ReadTrackFromFile(const char* fileName);
	// Only Reads the column headings and returns them
	// Holds onto the file handle for streaming line by line
	std::vector<std::string> StreamDataFromFile(const char* fileName);

	// Reads a line from the file and returns the time associated with the time
	double StreamDataFromFile(std::vector<std::string>* headings);

	// Get a specific track value at a specific time
	double GetTrack(const std::string& name, double time);

	// Get the entire list of values for a track label
	std::vector<double>* GetTrack(const std::string& name);

	// Get all the times
	std::vector<double>* GetTimes();

	// Creates the file and writes the headers to that file
	void CreateFile(const char* fileName, std::ofstream& newFile);// TODO C++11
	// Write all the track to a file
	void WriteTrackToFile(const char* fileName);
	// Writes data from the provided headings to the file, in the order things were tracked
	void StreamTrackToFile(std::ofstream& file);
	// Writes prob values to file in the order things were tracked
	void StreamProbesToFile(double time, std::ofstream& file);

protected:
	TrackMap m_Track;
	ProbeMap m_Probe;

	double                            m_LastTime = -1.0;
	std::vector<double>               m_Time;
	std::vector<std::string>          m_HeadingOrder;

	std::ifstream m_FileStream;
};
