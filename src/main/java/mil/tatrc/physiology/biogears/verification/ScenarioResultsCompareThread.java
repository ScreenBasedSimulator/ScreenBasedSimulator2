package mil.tatrc.physiology.biogears.verification;

import java.io.File;
import java.io.IOException;
import java.util.Map;

import mil.tatrc.physiology.biogears.verification.Summary.ScenarioPool;
import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;
import mil.tatrc.physiology.utilities.TimingProfile;

public class ScenarioResultsCompareThread implements Runnable
{
  protected ScenarioPool m_pool;
  protected double       m_percentDifference;
  
  
  public ScenarioResultsCompareThread(ScenarioPool p, double percentDifference)
  {
    m_pool = p;
    m_percentDifference = percentDifference;
  }

  public void run()
  {
    while(true)
    {
      Map.Entry<String, String> entry = m_pool.getNextScenario();
      if(entry==null)
        return;

      TimingProfile.start("compare");
      String expectedResultsPath = new String(entry.getValue());
      expectedResultsPath = expectedResultsPath.substring(0, expectedResultsPath.length() - 4);
      String path = expectedResultsPath.substring(0, expectedResultsPath.lastIndexOf('/'));
      String name = expectedResultsPath.substring(expectedResultsPath.lastIndexOf('/') + 1);
      expectedResultsPath = "../verification/Scenarios/" + path + "/Current Baseline/" + name + "Results.txt";

      String computedResultsPath = new String(entry.getValue());
      computedResultsPath = computedResultsPath.substring(0, computedResultsPath.length() - 4);
      computedResultsPath = "./Scenarios/" + computedResultsPath + "Results.txt";

      CompareResult(expectedResultsPath,computedResultsPath);
      System.gc();
      Log.info("Finished verifying "+computedResultsPath+", it took "+TimingProfile.profile("compare")+"s");
    }
  }
  
  public void CompareResult(String expectedResultsPath, String computedResultsPath)
  {
    String path = computedResultsPath.substring(0, computedResultsPath.lastIndexOf('/'));
   
    ScenarioPlotTool plot = new ScenarioPlotTool();
    ScenarioResultsCompareTool t = new ScenarioResultsCompareTool();

    File computed = new File(computedResultsPath);
    if(!computed.exists())
    {
      Log.error("Computed file does not exist "+computedResultsPath);
      return;
    }
    // We have computed data, so create names
    t.name = computed.getName().substring(0,computed.getName().length()-4);
    t.limit = m_percentDifference;
    t.reportDifferences = false;
    t.reportDir = path + "/" + t.name + "/";
    t.zipFiles = false;
    t.setFileName(t.name+"Report");
   
    FileUtils.delete(t.reportDir);
    try {
      Thread.sleep(1000);
    } catch (InterruptedException e) {
      Log.error("Unable to remove directory "+t.reportDir,e);
    }

    try {
      FileUtils.createDirectory(t.reportDir);
    } catch (IOException e) {
      Log.error("Unable to create directory "+t.reportDir,e);
    }

    File expected = new File(expectedResultsPath);
    if(!expected.exists())
    {
      Log.warn("Expected file does not exist "+expectedResultsPath+" plotting computed data by itself");
      plot.graphResults(computedResultsPath,t.reportDir);     
      return;
    }   

    // The Format of Log file to look for
    t.expectedLogFileName = computed.getAbsolutePath().replace("Results_1", "Log");
    if(!(new File(t.expectedLogFileName).exists()))
      t.expectedLogFileName = "";
    
    Log.info("Verifying/Plotting "+computedResultsPath);
    t.compare(expectedResultsPath,computedResultsPath);
    t.write();
  }
  
  
}
