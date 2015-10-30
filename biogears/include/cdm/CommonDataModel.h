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

#if defined (__clang__)
    #define DLL_DECL
    #define STL_DECL
#elif defined(__gnu_linux__)
    #define DLL_DECL __attribute__ ((visibility ("default")))
    #define STL_DECL extern
#else
    #ifdef COMMONDATAMODEL_EXPORTS
	    #define DLL_DECL __declspec(dllexport)
        #define STL_DECL
    #else
	    #define DLL_DECL __declspec(dllimport)
        #define STL_DECL extern
    #endif
#endif

#if (0)
#define DEBUGOUT(x) x
#else
#define DEBUGOUT(x) 
#endif

#define CDM mil::tatrc::physiology::datamodel
//using namespace mil::tatrc::phsyiology::datamodel;
#define CDM_BIND_DECL(type) namespace mil{ namespace tatrc{ namespace physiology{ namespace datamodel { class type; } } } }

#include <memory>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdexcept>

#ifdef _MSC_VER
#include <direct.h>
#else
#include <dirent.h>
#endif

#include <math.h>
#include <vector>
#include <stack>
#include <map>

#if defined(_MSC_VER)
	#include <hash_map>
	using namespace stdext;
#else//if (__GCC__) || (__GNUC__)
	#include <ext/hash_map>
	using namespace __gnu_cxx;

	namespace __gnu_cxx
	{
		using namespace std;

		template<>
		struct hash<string>
		{
			size_t operator()(const string &s) const
			{
				const collate<char>& c = use_facet<collate<char> >(locale::classic());
				return c.hash(s.c_str(), s.c_str() + s.size());
			}
		};
	}
#endif

/*
template class __declspec(dllexport) std::basic_string<char, 
                                                      std::char_traits<char>, 
                                                      std::allocator<char> >;

template class __declspec(dllexport) std::basic_stringstream<char, 
                                                            std::char_traits<char>, 
                                                            std::allocator<char> >;

template class __declspec(dllexport) std::vector<std::string>;
*/

// Disabling the waring about STL classes used have 
// to have a dll interface to be used by clients
// From what I have read STL is compiler dependent
// But since we are releasing source, you can build
// the project neccessary to ensure proper linkage
// If anyone else has opinions on this, let me know
// abray@ara.com
#pragma warning(disable : 4251)
//Utilities

struct CommonDataModelException : public std::runtime_error
{
	CommonDataModelException()
		: std::runtime_error( "Common Data Model Error" ) {}

	CommonDataModelException(const std::string& _Message)
		: std::runtime_error(_Message) {}
};
// Basics
#include "Macros.h"
#include "utils/Logger.h"

class CCompoundUnit;

class SEScalar;
class SEScalarAmount;
class SEScalarAmountPerMass;
class SEScalarAmountPerTime;
class SEScalarAmountPerVolume;
class SEScalarArea;
class SEScalarAreaPerTimePerPressure;
class SEScalarElectricCapacitance;
class SEScalarElectricCharge;
class SEScalarElectricCurrent;
class SEScalarElectricInductance;
class SEScalarElectricPotential;
class SEScalarElectricResistance;
class SEScalarEnergy;
class SEScalarEnergyPerAmount;
class SEScalarEnergyPerMass;
class SEScalarFlowCompliance;
class SEScalarFlowElastance;
class SEScalarFlowInertance;
class SEScalarFlowResistance;
class SEScalarForce;
class SEScalarFraction;
class SEScalarFrequency;
class SEScalarHeatCapacitance;
class SEScalarHeatCapacitancePerMass;
class SEScalarHeatConductance;
class SEScalarHeatConductancePerArea;
class SEScalarHeatResistance;
class SEScalarHeatResistanceArea;
class SEScalarHeatInductance;
class SEScalarInversePressure;
class SEScalarLength;
class SEScalarLengthPerTime;
class SEScalarLengthPerTimePerPressure;
class SEScalarMass;
class SEScalarMassPerAmount;
class SEScalarMassPerMass;
class SEScalarMassPerTime;
class SEScalarMassPerVolume;
class SEScalarOsmolality;
class SEScalarOsmolarity;
class SEScalarPower;
class SEScalarPressure;
class SEScalarPressurePerVolume;
class SEScalarTime;
class SEScalarTemperature;
class SEScalarVolume;
class SEScalarVolumePerPressure;
class SEScalarVolumePerTime;
class SEScalarVolumePerTimePerArea;
class SEScalarVolumePerTimePerPressurePerArea;
class SEScalarVolumePerTimePerMass;
class SEScalarVolumePerTimePerPressure;

class SEFunction;
class SEFunctionTimeVsVolume;
class SEFunctionTimeVsElectricPotential;
