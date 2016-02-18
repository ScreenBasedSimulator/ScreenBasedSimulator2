package mil.tatrc.physiology.biogears.engine;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.ScenarioData;
import mil.tatrc.physiology.datamodel.scenario.SEScenario;

/**
 * This is a class that will run a scenario through BioGears
 * and create it's results file. You could easily write your
 * own exec class that does what you want in between actions
 * but this may work for most of your needs.
 * @author abray
 */
public class BioGearsScenarioExec extends BioGears
{
  public void runScenario(String logFile, SEScenario scenario, String resultsFile, CDMUpdatedCallback callback)
  {
    this.requestData(scenario.getRequestedData());
    runScenarioXML(logFile,CDMSerializer.serialize(scenario.unload()),resultsFile,callback);
  }
  
  public void runScenario(String logFile, String scenarioFile, String resultsFile, CDMUpdatedCallback callback)
  {
    SEScenario sce = new SEScenario(this.substanceManager);
    sce.load((ScenarioData) CDMSerializer.readFile(scenarioFile));    
    runScenario(logFile,sce,resultsFile,callback);
  }
  
  protected void runScenarioXML(String logFile, String scenarioXML, String resultsFile, CDMUpdatedCallback callback)
  {
    this.cdmCallback = callback;
    double callbackFreq_s = 0;
    if(callback!=null)
      callbackFreq_s = callback.callbackFrequency_s;   
    this.nativeObj = this.nativeAllocate(logFile);
    this.nativeExecuteScenario(this.nativeObj, scenarioXML, resultsFile, callbackFreq_s);
    this.nativeDelete(this.nativeObj);
    this.nativeObj=0;
    this.cdmCallback = null;
  }
  
  public void cancelScenario()
  {
    if(this.nativeObj!=0)
      this.nativeCancelScenario(this.nativeObj);
  }
  
  protected native void nativeExecuteScenario(long nativeObj, String scenarioXML, String resultsFile, double updateFreq_s);
  protected native void nativeCancelScenario(long nativeObj);
  
}
