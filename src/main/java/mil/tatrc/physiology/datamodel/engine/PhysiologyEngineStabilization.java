package mil.tatrc.physiology.datamodel.engine;

import mil.tatrc.physiology.datamodel.bind.PhysiologyEngineStabilizationData;

public abstract class PhysiologyEngineStabilization 
{
  protected boolean trackingStabilization;
  
  public PhysiologyEngineStabilization()
  {
    reset();
  }
  
  public void reset()
  {
    this.trackingStabilization=false;
  }
  
  public boolean load(PhysiologyEngineStabilizationData in) 
  {
    reset();
    this.trackingStabilization=in.isTrackingStabilization();
    return true;
  }
  
  public abstract PhysiologyEngineStabilizationData unload();
  
  protected void unload(PhysiologyEngineStabilizationData data)
  {
    data.setTrackingStabilization(this.trackingStabilization);
  }
  
  public boolean isTrackingStabilization()
  {
    return this.trackingStabilization;
  }
  public void TrackStabilization(boolean b)
  {
    this.trackingStabilization=b;
  }
  
}
