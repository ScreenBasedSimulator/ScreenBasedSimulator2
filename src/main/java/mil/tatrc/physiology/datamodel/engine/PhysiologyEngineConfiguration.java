package mil.tatrc.physiology.datamodel.engine;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineConfigurationData;
import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineDynamicStabilizationData;
import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineStabilizationData;
import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineTimedStabilizationData;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;
import mil.tatrc.physiology.utilities.Log;

public class PhysiologyEngineConfiguration
{
  protected String                        ecgDataFile;
  // TODO kelman equation  
  protected PhysiologyEngineStabilization stabilizationCriteria;
  protected String                        stabilizationCriteriaFile;
  protected SEScalarTime                  timeStep;
  
  public PhysiologyEngineConfiguration()
  {
    clear();
  }
  
  public void reset()
  {
    ecgDataFile = "";
    if(stabilizationCriteria!=null)
      this.stabilizationCriteria.reset();
    if(timeStep!=null)
      timeStep.invalidate();
  }
  
  public void clear()
  {
    ecgDataFile = "";
    this.stabilizationCriteria=null;    
    timeStep=null;
  }
  
  public boolean load(PhysiologyEngineConfigurationData in)
  {
    reset();
    if(in.getECGDataFile()!=null)
      this.ecgDataFile = in.getECGDataFile();
    if(in.getStabilizationCriteria()!=null)
    {
      PhysiologyEngineStabilizationData s = in.getStabilizationCriteria();
      if(s instanceof PhysiologyEngineTimedStabilizationData)
        stabilizationCriteria = new PhysiologyEngineTimedStabilization();
      else if(s instanceof PhysiologyEngineDynamicStabilizationData)
        stabilizationCriteria = new PhysiologyEngineDynamicStabilization();
      else
        Log.fatal("Unsupported stabilization critera : " + s.getClass().getName());
      stabilizationCriteria.load(s);
    }
    else if(in.getStabilizationCriteriaFile()!=null)
      this.stabilizationCriteriaFile = in.getStabilizationCriteriaFile();
    if(in.getTimeStep()!=null)
      getTimeStep().load(in.getTimeStep());
    return true;
  }
  
  public PhysiologyEngineConfigurationData unload()
  {
    PhysiologyEngineConfigurationData data = CDMSerializer.objFactory.createPhysiologyEngineConfigurationData();
    unload(data);
    return data;
  }
  
  protected void unload(PhysiologyEngineConfigurationData data)
  {
    if(hasECGDataFile())
      data.setECGDataFile(this.ecgDataFile);
    if(hasStabilizationCriteria())
      data.setStabilizationCriteria(stabilizationCriteria.unload());
    else  if(hasStabilizationCriteriaFile())
      data.setStabilizationCriteriaFile(stabilizationCriteriaFile);
    if(hasTimeStep())
      data.setTimeStep(timeStep.unload());
  }
  
  public boolean hasECGDataFile()
  {
    return !ecgDataFile.isEmpty();
  }
  public String getECGDataFile()
  {
    return ecgDataFile;
  }
  public void setECGDataFile(String filePath)
  {
    ecgDataFile = filePath;
  }
  
  public boolean hasStabilizationCriteria()
  {
    return stabilizationCriteria!=null;
  }
  public PhysiologyEngineStabilization getStabilizationCriteria()
  {
    return stabilizationCriteria;
  }
  public void setStabilizationCriteria(PhysiologyEngineStabilization config)
  {
    stabilizationCriteria = config;
  }
  
  public boolean hasStabilizationCriteriaFile()
  {
    return !stabilizationCriteriaFile.isEmpty();
  }
  public String getStabilizationCriteriaFile()
  {
    return stabilizationCriteriaFile;
  }
  public void setStabilizationCriteriaFile(String file)
  {
    stabilizationCriteriaFile = file;
  }
  
  public boolean hasTimeStep()
  {
    return timeStep!=null && timeStep.isValid();
  }
  public SEScalarTime getTimeStep()
  {
    if(timeStep==null)
      timeStep=new SEScalarTime();
    return timeStep;
  }
}
