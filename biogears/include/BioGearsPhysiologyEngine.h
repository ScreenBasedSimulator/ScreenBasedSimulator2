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

#include "CommonDataModel.h"

// CDM Features in use
#include "utils/GeneralMath.h"
#include "engine/PhysiologyEngine.h"

#include <memory>

#if defined(__clang__)
	#define BIOGEARS_API
	#define BG_EXT
#elif defined(__gnu_linux__)
	#define BIOGEARS_API __attribute__ ((visibility ("default")))
	#define BG_EXT extern
#else
	#ifdef BIOGEARS_EXPORT
		#define BIOGEARS_API __declspec(dllexport)
		#define BG_EXT
	#else
		#define BIOGEARS_API __declspec(dllimport)
		#define BG_EXT extern
	#endif
#endif

BIOGEARS_API std::unique_ptr<PhysiologyEngine> CreateBioGearsEngine(const std::string& logfile=""); 
BIOGEARS_API std::unique_ptr<PhysiologyEngine> CreateBioGearsEngine(Logger* logger);
