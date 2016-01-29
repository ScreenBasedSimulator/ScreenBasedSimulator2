#pragma once
CDM_BIND_DECL(SubstanceFractionData)
class SESubstance;
class SEEnvironmentalConditions; 
class DLL_DECL SESubstanceFraction : public Loggable
{
protected:
	friend SEEnvironmentalConditions;// So it can add substances to the manager
public:

	SESubstanceFraction(const SESubstance&);
	virtual ~SESubstanceFraction();
	SESubstanceFraction(const SESubstanceFraction& other);

	virtual void Reset(); //reset values
	virtual void Clear(); //clear memory

	bool Load(const CDM::SubstanceFractionData& in);
	std::unique_ptr<CDM::SubstanceFractionData> Unload() const;
protected:
	void Unload(CDM::SubstanceFractionData& data) const;
public:

	virtual bool HasFractionAmount() const;
	virtual SEScalarFraction& GetFractionAmount();
	virtual double GetFractionAmount() const;

	virtual const SESubstance& GetSubstance() const;

protected:

	const SESubstance& m_Substance;
	SEScalarFraction*  m_FractionAmount;
};  