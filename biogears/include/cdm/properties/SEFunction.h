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
#include "properties/SEProperty.h"
#include "utils/unitconversion/UCCommon.h"

CDM_BIND_DECL(FunctionData)

class DLL_DECL SEFunction : public SEProperty
{
public:

	SEFunction();
	virtual ~SEFunction();

	virtual void Clear(); //clear memory

	bool Load(const CDM::FunctionData& in);
	std::unique_ptr<CDM::FunctionData> Unload();
protected:
	void Unload(CDM::FunctionData& data) const;

public:
	virtual bool							      IsValid() const;
	virtual void							      Invalidate();

	virtual unsigned int					      Length();
	
	virtual double                                GetAbscissaValue(unsigned int index, const std::shared_ptr<CCompoundUnit>& unit);
	virtual std::vector<double>*			      GetAbscissa();			
	virtual void 			                      GetAbscissa(std::vector<double>&, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void							      SetAbscissa(std::vector<double>* abscissa, const std::shared_ptr<CCompoundUnit>& unit);	
	virtual const std::shared_ptr<CCompoundUnit>& GetAbscissaUnit();
	virtual bool                                  IsValidAbscissaUnit(const std::shared_ptr<CCompoundUnit>& unit);

	virtual double                                GetOrdinateValue(unsigned int index, const std::shared_ptr<CCompoundUnit>& unit);
	virtual std::vector<double>*			      GetOrdinate();
	virtual void			                      GetOrdinate(std::vector<double>&, const std::shared_ptr<CCompoundUnit>& unit);
	virtual void							      SetOrdinate(std::vector<double>* ordinate, const std::shared_ptr<CCompoundUnit>& unit);	
	virtual const std::shared_ptr<CCompoundUnit>& GetOrdinateUnit();
	virtual bool                                  IsValidOrdinateUnit(const std::shared_ptr<CCompoundUnit>& unit);
	
protected:

	virtual const std::shared_ptr<CCompoundUnit>& GetAbscissaCompoundUnit(const std::string& unit);
	virtual const std::shared_ptr<CCompoundUnit>& GetOrdinateCompoundUnit(const std::string& unit);

	std::vector<double>* m_Abscissa;
	std::vector<double>* m_Ordinate;
	std::shared_ptr<CCompoundUnit> m_AbscissaUnit;
	std::shared_ptr<CCompoundUnit> m_OrdinateUnit;

};