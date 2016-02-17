package mil.tatrc.physiology.biogears.engine;

public abstract class CDMUpdatedCallback
{
  protected double callbackFrequency_s;
  public CDMUpdatedCallback(double updateFrequency_s)
  {
    callbackFrequency_s = updateFrequency_s;
  }
  
  public abstract void update(double time_s);
}
