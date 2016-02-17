package mil.tatrc.physiology.datamodel.engine;

import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineTimedStabilizationData;
import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineTimedConditionStabilizationData;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;

public class PhysiologyEngineTimedStabilization extends PhysiologyEngineStabilization
{
  protected SEScalarTime restingStabilizationTime;
  protected SEScalarTime feedbackStabilizationTime;
  protected Map<String,SEScalarTime> conditionStabilizationTimes;
  
  public PhysiologyEngineTimedStabilization()
  {
    super();
    this.conditionStabilizationTimes=new HashMap<String,SEScalarTime>();
  }
  
  public void reset()
  {
    super.reset();
    this.restingStabilizationTime=null;
    this.feedbackStabilizationTime=null;
    if(this.conditionStabilizationTimes!=null)
      this.conditionStabilizationTimes.clear();
  }
  
  public boolean load(PhysiologyEngineTimedStabilizationData in) 
  {
    super.load(in);
    getRestingStabilizationTime().load(in.getRestingStabilizationTime());
    if(in.getFeedbackStabilizationTime()!=null)
      getFeedbackStabilizationTime().load(in.getFeedbackStabilizationTime());
    for(PhysiologyEngineTimedConditionStabilizationData c : in.getConditionStabilization())
    {
      SEScalarTime stabilizationTime = this.createCondition(c.getName());
      stabilizationTime.load(c.getTime());     
    }
    return true;
  }
  
  public PhysiologyEngineTimedStabilizationData unload()
  {
    PhysiologyEngineTimedStabilizationData to = CDMSerializer.objFactory.createPhysiologyEngineTimedStabilizationData();
    unload(to);
    return to;
  }
  
  protected void unload(PhysiologyEngineTimedStabilizationData data)
  {
    super.unload(data);
    if(this.hasRestingStabilizationTime())
      data.setRestingStabilizationTime(getRestingStabilizationTime().unload());
    if(this.hasFeedbackStabilizationTime())
      data.setFeedbackStabilizationTime(getFeedbackStabilizationTime().unload());
    for(String name : this.conditionStabilizationTimes.keySet())
    {
      PhysiologyEngineTimedConditionStabilizationData c = CDMSerializer.objFactory.createPhysiologyEngineTimedConditionStabilizationData();
      c.setName(name);
      c.setTime(this.conditionStabilizationTimes.get(name).unload());
      data.getConditionStabilization().add(c);
    }
  }
  
  public boolean hasRestingStabilizationTime()
  {
    return restingStabilizationTime == null ? false : restingStabilizationTime.isValid();
  }
  public SEScalarTime getRestingStabilizationTime()
  {
    if (restingStabilizationTime == null)
      restingStabilizationTime = new SEScalarTime();
    return restingStabilizationTime;
  }
  
  public boolean hasFeedbackStabilizationTime()
  {
    return feedbackStabilizationTime == null ? false : feedbackStabilizationTime.isValid();
  }
  public SEScalarTime getFeedbackStabilizationTime()
  {
    if (feedbackStabilizationTime == null)
      feedbackStabilizationTime = new SEScalarTime();
    return feedbackStabilizationTime;
  }
  
  public SEScalarTime createCondition(String type)
  {
    SEScalarTime stabilizationTime = new SEScalarTime();
    this.conditionStabilizationTimes.put(type, stabilizationTime);
    return stabilizationTime;
  }
  public boolean hasCondition(String type)
  {
    return this.conditionStabilizationTimes.containsKey(type);
  }
  public SEScalarTime getCondition(String type)
  {
    return this.conditionStabilizationTimes.get(type);
  }
}
