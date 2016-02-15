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

package mil.tatrc.physiology.datamodel.patient;

import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.utilities.Log;

public class SEPatient
{
	protected String                    name;
	protected EnumGender                gender;
	protected SEScalarTime              age;
	protected SEScalarMass              weight;
	protected SEScalarLength            height;

  protected SEScalarPower             basalMetabolicRate;
	protected SEScalarFraction		      bodyFatFraction;
	protected SEScalarLength            carinaToTeethDistance;
	protected SEScalarPressure		      centralControllerCO2PressureSetPoint;
  protected SEScalarPressure          diastolicArterialPressureBaseline;
	protected SEScalarVolume            expiratoryReserveVolume;
	protected SEScalarVolume            functionalResidualCapacity;
	protected SEScalarFrequency         heartRateBaseline;
	protected SEScalarFrequency         heartRateMaximum;
	protected SEScalarFrequency         heartRateMinimum;
  protected SEScalarVolume            inspiratoryCapacity;
  protected SEScalarVolume            inspiratoryReserveVolume;
  protected SEScalarFlowElastance     leftHeartElastanceMaximum;
  protected SEScalarFlowElastance     leftHeartElastanceMinimum;
	protected SEScalarPressure          meanArterialPressureBaseline;
	protected SEScalarPressure		      peripheralControllerCO2PressureSetPoint;
  protected SEScalarVolumePerTime     pulmonaryVentilationRateMaximum;
  protected SEScalarVolume            residualVolume;
	protected SEScalarFrequency         respirationRateBaseline;
  protected SEScalarFlowElastance     rightHeartElastanceMaximum;
  protected SEScalarFlowElastance     rightHeartElastanceMinimum;
  protected SEScalarFraction          rightLungRatio;
  protected SEScalarArea              skinSurfaceArea;
  protected SEScalarPressure          systolicArterialPressureBaseline;
	protected SEScalarVolume            tidalVolumeBaseline;
	protected SEScalarVolume            totalLungCapacity;
	protected SEScalarVolume            totalBloodVolumeBaseline;
  protected SEScalarVolume            vitalCapacity;
  
  protected Map<EnumPatientEvent,Boolean> events = new HashMap<EnumPatientEvent,Boolean>();
	
	public SEPatient()
	{
		
	}
	
	public void reset()
	{
		this.name=null;
		this.gender=null;
		if(this.age!=null)
			this.age.invalidate();
		if(this.weight!=null)
			this.weight.invalidate();
		if(this.height!=null)
			this.height.invalidate();
		
		if(basalMetabolicRate != null)
      this.basalMetabolicRate.invalidate();
		if(bodyFatFraction != null)
      this.bodyFatFraction.invalidate();
		if(carinaToTeethDistance != null)
      this.carinaToTeethDistance.invalidate();
		if(centralControllerCO2PressureSetPoint != null)
      this.centralControllerCO2PressureSetPoint.invalidate();
		if(diastolicArterialPressureBaseline != null)
      this.diastolicArterialPressureBaseline.invalidate();
		if(expiratoryReserveVolume != null)
      this.expiratoryReserveVolume.invalidate();
		if(functionalResidualCapacity != null)
      this.functionalResidualCapacity.invalidate();
		if(heartRateBaseline != null)
      this.heartRateBaseline.invalidate();
		if(heartRateMaximum != null)
      this.heartRateMaximum.invalidate();
		if(heartRateMinimum != null)
      this.heartRateMinimum.invalidate();
		if(inspiratoryCapacity != null)
      this.inspiratoryCapacity.invalidate();
		if(inspiratoryReserveVolume != null)
      this.inspiratoryReserveVolume.invalidate();
		if(leftHeartElastanceMaximum != null)
      this.leftHeartElastanceMaximum.invalidate();
		if(leftHeartElastanceMinimum != null)
      this.leftHeartElastanceMinimum.invalidate();
		if(meanArterialPressureBaseline != null)
      this.meanArterialPressureBaseline.invalidate();
		if(peripheralControllerCO2PressureSetPoint != null)
      this.peripheralControllerCO2PressureSetPoint.invalidate();
		if(pulmonaryVentilationRateMaximum != null)
      this.pulmonaryVentilationRateMaximum.invalidate();
		if(residualVolume != null)
      this.residualVolume.invalidate();
		if(respirationRateBaseline != null)
      this.respirationRateBaseline.invalidate();
		if(rightHeartElastanceMaximum != null)
      this.rightHeartElastanceMaximum.invalidate();
		if(rightHeartElastanceMinimum != null)
      this.rightHeartElastanceMinimum.invalidate();
		if(rightLungRatio != null)
      this.rightLungRatio.invalidate();
		if(skinSurfaceArea != null)
      this.skinSurfaceArea.invalidate();
		if(systolicArterialPressureBaseline != null)
      this.systolicArterialPressureBaseline.invalidate();
		if(tidalVolumeBaseline != null)
      this.tidalVolumeBaseline.invalidate();
		if(totalLungCapacity != null)
      this.totalLungCapacity.invalidate();
		if(totalBloodVolumeBaseline != null)
      this.totalBloodVolumeBaseline.invalidate();
		if(vitalCapacity != null)
      this.vitalCapacity.invalidate();
		
		events.clear();
	}
	
	public boolean load(PatientData data)
	{
		this.reset();
		if(data.getName()!=null)
			this.setName(data.getName());
		if(data.getGender()!=null)
			this.setGender(data.getGender());
		if(data.getAge()!=null)
			this.getAge().load(data.getAge());
		if(data.getWeight()!=null)
			this.getWeight().load(data.getWeight());
		if(data.getHeight()!=null)
			this.getHeight().load(data.getHeight());
		
		if(data.getBasalMetabolicRate() != null)
      this.getBasalMetabolicRate().load(data.getBasalMetabolicRate());
    if(data.getBodyFatFraction()!=null)
			this.getBodyFatFraction().load(data.getBodyFatFraction());
		if(data.getCarinaToTeethDistance()!=null)
			this.getCarinaToTeethDistance().load(data.getCarinaToTeethDistance());
		if(data.getCentralControllerCO2PressureSetPoint()!=null)
			this.getCentralControllerCO2PressureSetPoint().load(data.getCentralControllerCO2PressureSetPoint());
		if(data.getDiastolicArterialPressureBaseline()!=null)
      this.getDiastolicArterialPressureBaseline().load(data.getDiastolicArterialPressureBaseline());
    if(data.getExpiratoryReserveVolume()!=null)
			this.getExpiratoryReserveVolume().load(data.getExpiratoryReserveVolume());
		if(data.getFunctionalResidualCapacity()!=null)
			this.getFunctionalResidualCapacity().load(data.getFunctionalResidualCapacity());
		if(data.getHeartRateBaseline()!=null)
      this.getHeartRateBaseline().load(data.getHeartRateBaseline());
		if(data.getHeartRateMaximum()!=null)
			this.getHeartRateMaximum().load(data.getHeartRateMaximum());
		if(data.getHeartRateMinimum()!=null)
			this.getHeartRateMinimum().load(data.getHeartRateMinimum());
		if(data.getInspiratoryCapacity()!=null)
			this.getInspiratoryCapacity().load(data.getInspiratoryCapacity());
		if(data.getInspiratoryReserveVolume()!=null)
			this.getInspiratoryReserveVolume().load(data.getInspiratoryReserveVolume());
		if(data.getLeftHeartElastanceMaximum()!=null)
      this.getLeftHeartElastanceMaximum().load(data.getLeftHeartElastanceMaximum());
		if(data.getLeftHeartElastanceMinimum()!=null)
      this.getLeftHeartElastanceMinimum().load(data.getLeftHeartElastanceMinimum());
		if(data.getMeanArterialPressureBaseline()!=null)
			this.getMeanArterialPressureBaseline().load(data.getMeanArterialPressureBaseline());
    if(data.getPeripheralControllerCO2PressureSetPoint()!=null)
			this.getPeripheralControllerCO2PressureSetPoint().load(data.getPeripheralControllerCO2PressureSetPoint());
    if(data.getPulmonaryVentilationRateMaximum()!=null)
      this.getPulmonaryVentilationRateMaximum().load(data.getPulmonaryVentilationRateMaximum());
    if(data.getResidualVolume()!=null)
      this.getResidualVolume().load(data.getResidualVolume());
    if(data.getRespirationRateBaseline()!=null)
      this.getRespirationRateBaseline().load(data.getRespirationRateBaseline());
    if(data.getRightHeartElastanceMaximum()!=null)
      this.getRightHeartElastanceMaximum().load(data.getRightHeartElastanceMaximum());
    if(data.getRightHeartElastanceMinimum()!=null)
      this.getRightHeartElastanceMinimum().load(data.getRightHeartElastanceMinimum());
    if(data.getRightLungRatio()!=null)
			this.getRightLungRatio().load(data.getRightLungRatio());
    if(data.getSkinSurfaceArea()!=null)
      this.getSkinSurfaceArea().load(data.getSkinSurfaceArea());
    if(data.getSystolicArterialPressureBaseline()!=null)
      this.getSystolicArterialPressureBaseline().load(data.getSystolicArterialPressureBaseline());
    if(data.getTidalVolumeBaseline()!=null)
      this.getTidalVolumeBaseline().load(data.getTidalVolumeBaseline());
    if(data.getTotalBloodVolumeBaseline()!=null)
      this.getTotalBloodVolumeBaseline().load(data.getTotalBloodVolumeBaseline());
    if(data.getTotalLungCapacity()!=null)
			this.getTotalLungCapacity().load(data.getTotalLungCapacity());
		if(data.getTotalBloodVolumeBaseline()!=null)
			this.getTotalBloodVolumeBaseline().load(data.getTotalBloodVolumeBaseline());
		if(data.getVitalCapacity()!=null)
      this.getVitalCapacity().load(data.getVitalCapacity());
    
		return true;
	}
	
	public PatientData unload()
	{
		PatientData to = CDMSerializer.objFactory.createPatientData();
		unload(to);
		return to;
	}
	
	protected void unload(PatientData to)
	{
		if(hasName())
			to.setName(this.name);
		if(hasGender())
			to.setGender(this.gender);
		if(hasAge())
			to.setAge(this.age.unload());
		if(hasWeight())
			to.setWeight(this.weight.unload());
		if(hasHeight())
			to.setHeight(this.height.unload());
		
		if(hasBasalMetabolicRate())
		  to.setBasalMetabolicRate(basalMetabolicRate.unload());
    if(hasBodyFatFraction())
			to.setBodyFatFraction(this.bodyFatFraction.unload());
		if(hasCarinaToTeethDistance())
			to.setCarinaToTeethDistance(this.carinaToTeethDistance.unload());
		if(hasCentralControllerCO2PressureSetPoint())
			to.setCentralControllerCO2PressureSetPoint(this.centralControllerCO2PressureSetPoint.unload());
		if(hasDiastolicArterialPressureBaseline())
			to.setDiastolicArterialPressureBaseline(this.diastolicArterialPressureBaseline.unload());	
		if(hasExpiratoryReserveVolume())
			to.setExpiratoryReserveVolume(this.expiratoryReserveVolume.unload());	
		if(hasFunctionalResidualCapacity())
			to.setFunctionalResidualCapacity(this.functionalResidualCapacity.unload());
		if(hasHeartRateBaseline())
      to.setHeartRateBaseline(this.heartRateBaseline.unload());
		if(hasHeartRateMaximum())
			to.setHeartRateMaximum(this.heartRateMaximum.unload());
		if(hasHeartRateMinimum())
			to.setHeartRateMinimum(this.heartRateMinimum.unload());
		if(hasInspiratoryCapacity())
			to.setInspiratoryCapacity(this.inspiratoryCapacity.unload());
		if(hasInspiratoryReserveVolume())
			to.setInspiratoryReserveVolume(this.inspiratoryReserveVolume.unload());
		if(hasLeftHeartElastanceMaximum())
			to.setLeftHeartElastanceMaximum(this.leftHeartElastanceMaximum.unload());
		if(hasLeftHeartElastanceMinimum())
			to.setLeftHeartElastanceMinimum(this.leftHeartElastanceMinimum.unload());
		if(hasMeanArterialPressureBaseline())
			to.setMeanArterialPressureBaseline(this.meanArterialPressureBaseline.unload());
		if(hasPeripheralControllerCO2PressureSetPoint())
			to.setPeripheralControllerCO2PressureSetPoint(this.peripheralControllerCO2PressureSetPoint.unload());
		if(hasPulmonaryVentilationRateMaximum())
      to.setPulmonaryVentilationRateMaximum(this.pulmonaryVentilationRateMaximum.unload());
    if(hasRespirationRateBaseline())
			to.setRespirationRateBaseline(this.respirationRateBaseline.unload());
    if(hasRightHeartElastanceMaximum())
      to.setRightHeartElastanceMaximum(this.rightHeartElastanceMaximum.unload());
    if(hasRightHeartElastanceMinimum())
      to.setRightHeartElastanceMinimum(this.rightHeartElastanceMinimum.unload());
    if(hasRightLungRatio())
			to.setRightLungRatio(this.rightLungRatio.unload());
    if(hasSkinSurfaceArea())
      to.setSkinSurfaceArea(this.skinSurfaceArea.unload());
    if(hasSystolicArterialPressureBaseline())
      to.setSystolicArterialPressureBaseline(this.systolicArterialPressureBaseline.unload());
    if(hasTidalVolumeBaseline())
			to.setTidalVolumeBaseline(this.tidalVolumeBaseline.unload());
    if(hasTotalLungCapacity())
      to.setTotalLungCapacity(this.totalLungCapacity.unload());
    if(hasTotalBloodVolumeBaseline())
			to.setTotalBloodVolumeBaseline(this.totalBloodVolumeBaseline.unload());
    if(hasVitalCapacity())
      to.setVitalCapacity(this.vitalCapacity.unload());
	}
	
	public boolean loadPatientFile(String patientFile)
	{
		Object data = CDMSerializer.readFile(patientFile);
		if (data instanceof PatientData)
			return load((PatientData) data);
		
		Log.error("Patient file could not be read: " + patientFile, "SEPatient.loadPatientFile()");
		return false;
	}
	
	public void setEvent(EnumPatientEvent type, boolean active)
	{
	  this.events.put(type, active);
	}
	public boolean isEventActive(EnumPatientEvent type)
	{
	  if(!this.events.containsKey(type))
	    return false;
	  return this.events.get(type);
	}
	
	public String  getName() { return this.name;}
	public void    setName(String name){this.name=name;}
	public boolean hasName(){return this.name==null?false:true;}
	
	public EnumGender  getGender() { return this.gender;}
	public void        setGender(EnumGender name){this.gender=name;}
	public boolean     hasGender(){return this.gender==null?false:true;}
	
	public SEScalarTime getAge() 
	{ 
		if(this.age==null)
			this.age=new SEScalarTime();
		return this.age;
	}
	public boolean      hasAge() {return this.age==null?false:this.age.isValid();}
	
	public SEScalarMass getWeight() 
	{ 
		if(this.weight==null)
			this.weight=new SEScalarMass();
		return this.weight;
	}
	public boolean      hasWeight() {return this.weight==null?false:this.weight.isValid();}
	
	public SEScalarLength getHeight() 
	{ 
		if(this.height==null)
			this.height=new SEScalarLength();
		return this.height;
	}
	public boolean          hasHeight() {return this.height==null?false:this.height.isValid();}
	
	public boolean hasBasalMetabolicRate()
  {
    return basalMetabolicRate == null ? false : basalMetabolicRate.isValid();
  }
  public SEScalarPower getBasalMetabolicRate()
  {
    if (basalMetabolicRate == null)
      basalMetabolicRate = new SEScalarPower();
    return basalMetabolicRate;
  }
  
	public SEScalarFraction getBodyFatFraction()
	{
		if(this.bodyFatFraction==null)
			this.bodyFatFraction=new SEScalarFraction();
		return this.bodyFatFraction;
	}
	public boolean hasBodyFatFraction() {return this.bodyFatFraction==null?false:this.bodyFatFraction.isValid();}
	
	public SEScalarLength getCarinaToTeethDistance() 
	{ 
		if(this.carinaToTeethDistance==null)
			this.carinaToTeethDistance=new SEScalarLength();
		return this.carinaToTeethDistance;
	}	
	public boolean  hasCarinaToTeethDistance() {return this.carinaToTeethDistance==null?false:this.carinaToTeethDistance.isValid();}
	
	public SEScalarPressure getCentralControllerCO2PressureSetPoint() 
	{ 
		if(this.centralControllerCO2PressureSetPoint==null)
			this.centralControllerCO2PressureSetPoint=new SEScalarPressure();
		return this.centralControllerCO2PressureSetPoint;
	}
	public boolean  hasCentralControllerCO2PressureSetPoint() {return this.centralControllerCO2PressureSetPoint==null?false:this.centralControllerCO2PressureSetPoint.isValid();}
	
	public SEScalarPressure getDiastolicArterialPressureBaseline() 
	{ 
		if(this.diastolicArterialPressureBaseline==null)
			this.diastolicArterialPressureBaseline=new SEScalarPressure();
		return this.diastolicArterialPressureBaseline;
	}
	public boolean  hasDiastolicArterialPressureBaseline() {return this.diastolicArterialPressureBaseline==null?false:this.diastolicArterialPressureBaseline.isValid();}
	
	public SEScalarVolume getExpiratoryReserveVolume() 
	{ 
		if(this.expiratoryReserveVolume==null)
			this.expiratoryReserveVolume=new SEScalarVolume();
		return this.expiratoryReserveVolume;
	}
	public boolean  hasExpiratoryReserveVolume() {return this.expiratoryReserveVolume==null?false:this.expiratoryReserveVolume.isValid();}
	
	public SEScalarVolume getFunctionalResidualCapacity() 
	{ 
		if(this.functionalResidualCapacity==null)
			this.functionalResidualCapacity=new SEScalarVolume();
		return this.functionalResidualCapacity;
	}
	public boolean        hasFunctionalResidualCapacity() {return this.functionalResidualCapacity==null?false:this.functionalResidualCapacity.isValid();}
	
	public SEScalarFrequency getHeartRateBaseline() 
	{ 
		if(this.heartRateBaseline==null)
			this.heartRateBaseline=new SEScalarFrequency();
		return this.heartRateBaseline;
	}
	public boolean           hasHeartRateBaseline() {return this.heartRateBaseline==null?false:this.heartRateBaseline.isValid();}
	
	
	public SEScalarFrequency getHeartRateMaximum() 
	{ 
		if(this.heartRateMaximum==null)
			this.heartRateMaximum=new SEScalarFrequency();
		return this.heartRateMaximum;
	}
	public boolean           hasHeartRateMaximum() {return this.heartRateMaximum==null?false:this.heartRateMaximum.isValid();}
	
	
	public SEScalarFrequency getHeartRateMinimum() 
	{ 
		if(this.heartRateMinimum==null)
			this.heartRateMinimum=new SEScalarFrequency();
		return this.heartRateMinimum;
	}
	public boolean           hasHeartRateMinimum() {return this.heartRateMinimum==null?false:this.heartRateMinimum.isValid();}
	
	public SEScalarVolume getInspiratoryCapacity() 
	{ 
		if(this.inspiratoryCapacity==null)
			this.inspiratoryCapacity=new SEScalarVolume();
		return this.inspiratoryCapacity;
	}
	public boolean               hasInspiratoryCapacity() {return this.inspiratoryCapacity==null?false:this.inspiratoryCapacity.isValid();}
	
	public SEScalarVolume getInspiratoryReserveVolume() 
	{ 
		if(this.inspiratoryReserveVolume==null)
			this.inspiratoryReserveVolume=new SEScalarVolume();
		return this.inspiratoryReserveVolume;
	}
	public boolean                hasInspiratoryReserveVolume() {return this.inspiratoryReserveVolume==null?false:this.inspiratoryReserveVolume.isValid();}
	
	public SEScalarFlowElastance getLeftHeartElastanceMaximum() 
	{ 
		if(this.leftHeartElastanceMaximum==null)
			this.leftHeartElastanceMaximum=new SEScalarFlowElastance();
		return this.leftHeartElastanceMaximum;
	}
	public boolean                hasLeftHeartElastanceMaximum() {return this.leftHeartElastanceMaximum==null?false:this.leftHeartElastanceMaximum.isValid();}
	
	public SEScalarFlowElastance getLeftHeartElastanceMinimum() 
	{ 
		if(this.leftHeartElastanceMinimum==null)
			this.leftHeartElastanceMinimum=new SEScalarFlowElastance();
		return this.leftHeartElastanceMinimum;
	}                             
	public boolean                hasLeftHeartElastanceMinimum() {return this.leftHeartElastanceMinimum==null?false:this.leftHeartElastanceMinimum.isValid();}
	
	public SEScalarPressure getMeanArterialPressureBaseline() 
	{ 
		if(this.meanArterialPressureBaseline==null)
			this.meanArterialPressureBaseline=new SEScalarPressure();
		return this.meanArterialPressureBaseline;
	}
	public boolean          hasMeanArterialPressureBaseline() {return this.meanArterialPressureBaseline==null?false:this.meanArterialPressureBaseline.isValid();}
	
	public SEScalarPressure getPeripheralControllerCO2PressureSetPoint() 
	{ 
	  if(this.peripheralControllerCO2PressureSetPoint==null)
	    this.peripheralControllerCO2PressureSetPoint=new SEScalarPressure();
	  return this.peripheralControllerCO2PressureSetPoint;
	}
	public boolean  hasPeripheralControllerCO2PressureSetPoint() {return this.peripheralControllerCO2PressureSetPoint==null?false:this.peripheralControllerCO2PressureSetPoint.isValid();}

	public SEScalarVolumePerTime getPulmonaryVentilationRateMaximum() 
	{ 
	  if(this.pulmonaryVentilationRateMaximum==null)
	    this.pulmonaryVentilationRateMaximum=new SEScalarVolumePerTime();
	  return this.pulmonaryVentilationRateMaximum;
	}
	public boolean                hasPulmonaryVentilationRateMaximum() {return this.pulmonaryVentilationRateMaximum==null?false:this.pulmonaryVentilationRateMaximum.isValid();}

 public SEScalarVolume getResidualVolume() 
  { 
    if(this.residualVolume==null)
      this.residualVolume=new SEScalarVolume();
    return this.residualVolume;
  }
  public boolean        hasResidualVolume() {return this.residualVolume==null?false:this.residualVolume.isValid();}
	
  public SEScalarFrequency getRespirationRateBaseline() 
  { 
    if(this.respirationRateBaseline==null)
      this.respirationRateBaseline=new SEScalarFrequency();
    return this.respirationRateBaseline;
  }
  public boolean           hasRespirationRateBaseline() {return this.respirationRateBaseline==null?false:this.respirationRateBaseline.isValid();}
  
	public SEScalarFlowElastance getRightHeartElastanceMaximum() 
	{ 
		if(this.rightHeartElastanceMaximum==null)
			this.rightHeartElastanceMaximum=new SEScalarFlowElastance();
		return this.rightHeartElastanceMaximum;
	}
	public boolean        hasRightHeartElastanceMaximum() {return this.rightHeartElastanceMaximum==null?false:this.rightHeartElastanceMaximum.isValid();}
	
	public SEScalarFlowElastance getRightHeartElastanceMinimum() 
	{ 
		if(this.rightHeartElastanceMinimum==null)
			this.rightHeartElastanceMinimum=new SEScalarFlowElastance();
		return this.rightHeartElastanceMinimum;
	}
	public boolean  hasRightHeartElastanceMinimum(){return this.rightHeartElastanceMinimum==null?false:this.rightHeartElastanceMinimum.isValid();}
	
	public SEScalarFraction getRightLungRatio() 
	{ 
		if(this.rightLungRatio==null)
			this.rightLungRatio=new SEScalarFraction();
		return this.rightLungRatio;
	}
	public boolean          hasRightLungRatio() {return this.rightLungRatio==null?false:this.rightLungRatio.isValid();}
	
	public SEScalarArea getSkinSurfaceArea() 
  { 
    if(this.skinSurfaceArea==null)
      this.skinSurfaceArea=new SEScalarArea();
    return this.skinSurfaceArea;
  }
  public boolean          hasSkinSurfaceArea() {return this.skinSurfaceArea==null?false:this.skinSurfaceArea.isValid();}
  
  public SEScalarPressure getSystolicArterialPressureBaseline() 
  { 
    if(this.systolicArterialPressureBaseline==null)
      this.systolicArterialPressureBaseline=new SEScalarPressure();
    return this.systolicArterialPressureBaseline;
  }
  public boolean          hasSystolicArterialPressureBaseline() {return this.systolicArterialPressureBaseline==null?false:this.systolicArterialPressureBaseline.isValid();}  
  
	public SEScalarVolume getTidalVolumeBaseline() 
  { 
    if(this.tidalVolumeBaseline==null)
      this.tidalVolumeBaseline=new SEScalarVolume();
    return this.tidalVolumeBaseline;
  }
  public boolean        hasTidalVolumeBaseline() {return this.tidalVolumeBaseline==null?false:this.tidalVolumeBaseline.isValid();}
  
	public SEScalarVolume getTotalLungCapacity() 
	{ 
		if(this.totalLungCapacity==null)
			this.totalLungCapacity=new SEScalarVolume();
		return this.totalLungCapacity;
	}
	public boolean        hasTotalLungCapacity() {return this.totalLungCapacity==null?false:this.totalLungCapacity.isValid();}
	
	public SEScalarVolume getTotalBloodVolumeBaseline() 
	{ 
		if(this.totalBloodVolumeBaseline==null)
			this.totalBloodVolumeBaseline=new SEScalarVolume();
		return this.totalBloodVolumeBaseline;
	}
	public boolean        hasTotalBloodVolumeBaseline() {return this.totalBloodVolumeBaseline==null?false:this.totalBloodVolumeBaseline.isValid();}	
	
	public SEScalarVolume getVitalCapacity() 
  { 
    if(this.vitalCapacity==null)
      this.vitalCapacity=new SEScalarVolume();
    return this.vitalCapacity;
  }
  public boolean        hasVitalCapacity() {return this.vitalCapacity==null?false:this.vitalCapacity.isValid();} 
  
}
