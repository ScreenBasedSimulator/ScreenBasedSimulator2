package mil.tatrc.physiology.biogears.verification;

import java.io.*;
import java.util.*;

import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;
import mil.tatrc.physiology.utilities.OrderedProperties;
import mil.tatrc.physiology.utilities.TimingProfile;

public class Summary
{
  private String m_configFile;

  private String m_subject;
  private String m_sender;
  private String m_smtp;
  private ArrayList<String> m_recipients;
  private String m_reportDirectory;
  private double m_percentDifference;

  private String m_commitHash;
  private String m_environment;

  private LinkedHashMap<String, String> m_scenarios;

  public Summary(String configFile, String commitHash, String environment)
  {
    m_scenarios = new LinkedHashMap<String, String>();

    m_configFile = configFile;
    m_commitHash = commitHash;
    m_environment = environment;

    ParseConfigFile(m_configFile);
  }

  private void ParseConfigFile(String configFile)
  {
    try
    {
      BufferedReader br = new BufferedReader(new FileReader(configFile));

      String line;
      while ((line = br.readLine()) != null)
      {
        if (line.length() == 0 || line.startsWith("#"))
        {
          continue;
        }

        if (line.indexOf('=') != -1)
        {                    
          String keyValue[] = ParseKeyValue(line);

          if (keyValue[0].equals("subject"))
          {
            m_subject = keyValue[1];
          }
          else if (keyValue[0].equals("sender"))
          {
            m_sender = keyValue[1];
          }
          else if (keyValue[0].equals("smtp"))
          {
            m_smtp = keyValue[1];
          }
          else if (keyValue[0].equals("recipients"))
          {
            m_recipients = ParseRecipients(keyValue[1]);
          }
          else if (keyValue[0].equals("reportDir"))
          {
            m_reportDirectory = keyValue[1];
          }
          else if (keyValue[0].equals("percentDifference"))
          {
            m_percentDifference = Double.parseDouble(keyValue[1]);
          }    
          else if(keyValue[0].equals("timeStart"))
          {
            continue;//depricated
          }
          else
          {
            if (keyValue[0].charAt(0) != '*' &&
                keyValue[0].charAt(0) != '-')
            {
              m_scenarios.put(keyValue[0], keyValue[1]);
            }
          }
        }
      }

      br.close();
    }
    catch (IOException e)
    {
    }
  }

  private String[] ParseKeyValue(String line)
  {
    return new String[]{ line.substring(0, line.indexOf('=')), line.substring(line.indexOf("=") + 1) };
  }

  private ArrayList<String> ParseRecipients(String recipients)
  {        
    return new ArrayList<String>(Arrays.asList(recipients.split("\\s*,\\s*")));
  }
  
  public class ScenarioPool
  {
    protected LinkedHashMap<String, String> m_scenarios=new LinkedHashMap<String, String>();
    
    public ScenarioPool(LinkedHashMap<String, String> scenarios)
    {
      m_scenarios.putAll(scenarios);
    }
    
    public synchronized Map.Entry<String, String> getNextScenario()
    {
      if(m_scenarios.isEmpty())
        return null;
      
      Map.Entry<String, String> next = m_scenarios.entrySet().iterator().next();
      m_scenarios.remove(next.getKey());
      return next;
    }
    public boolean isEmpty()
    {
      return m_scenarios.isEmpty();
    }
  }

  public void CompareScenarios()
  {
    if(m_scenarios.isEmpty())
      return;//Nothing to do
    ScenarioPool scenarios = new ScenarioPool(m_scenarios);
    int cores = Runtime.getRuntime().availableProcessors();
    if(cores > 1)
    {
      if(cores <= 4)
        cores = 2;
      else if(cores <= 8)
        cores = 4;
      else if(cores <= 16)
        cores = 12;
      else 
        cores -= 3;
    }
    if(cores > m_scenarios.size())
      cores = m_scenarios.size();
    cores=1;
    
    if(cores == 1)
    {
      ScenarioResultsCompareThread t = new ScenarioResultsCompareThread(scenarios,m_percentDifference);
      t.run();
    }
    else
    {
      List<Thread> threads = new ArrayList<Thread>();
      for(int i=0; i<cores; i++)
      {
        Thread t = new Thread(new ScenarioResultsCompareThread(scenarios,m_percentDifference));
        t.start();
        threads.add(t);     
      }
      // wait for threads to finish processing all the scenarios
      try
      {
        boolean run=false;
        do
        {
          run=false;
          Thread.sleep(1000);
          /*
        if(!scenarios.isEmpty())
        {
          run=true;
          continue;
        }*/
          for(Thread t : threads)
          {
            if(t.isAlive())
            {            
              run=true;
              break;
            }
          }
        }while(run);
      }
      catch(InterruptedException ex)
      {
        Log.error(ex);
      }
    }
  }
  
  public void GenerateReports()
  {
    TestReportGenerator generator = new TestReportGenerator();
    generator.setFileName("ReportingReport");
    generator.setCommitHash(m_commitHash);
    generator.setEnvironment(m_environment);
    generator.writeFiles(false);

    try
    {    
      String str = FileUtils.readFile(m_configFile);
      InputStream is = new ByteArrayInputStream(str.getBytes());
      OrderedProperties props = new OrderedProperties();
      props.load(is);

      OrderedProperties newProps = new OrderedProperties();

      Set<String> keySet = props.keySet();
      for(String key : keySet)
      {
        String value = props.get(key);
        if (value.endsWith(".xml"))
        {
          String[] split = value.split("/");

          String type = split[0];
          String name = split[1].substring(0, split[1].length() - 4);

          String resultsReport = "./Scenarios/" + type + "/" + name + "Results/" + name + "ResultsReport.xml";
          newProps.put(key, resultsReport);
        }
        else if (key == null || key.equals("") || key.charAt(0) == '@')
        {
          // ignore
        }
        else
        {
          newProps.put(key, value);
        }
      }

      if(!generator.run(newProps))
      {
        TestReport errRpt = new TestReport();
        errRpt.createErrorSuite("Error : Something is wrong with "+m_configFile+" check the log");
        generator.reports.put("Error",errRpt);
      }
      else
      {
        File configFile = new File(m_configFile);
        configFile.delete();
      }
    } 
    catch(Exception ex)
    {
      Log.error(ex);
      TestReport errRpt = new TestReport();
      errRpt.createErrorSuite("Error : " + ex.getMessage());
      generator.reports.put("Error",errRpt);
    }
    generator.write();    
  }

  public static void main(String[] args)
  {    
    Log.setFileName("VerificationComparison.log");
    Summary summary = new Summary(args[0], args[1], args[3]);

    if (args.length > 2)
    {
      if (args[2].equals("summarize"))
      {
        TimingProfile.start("summarize");
        summary.CompareScenarios();
        Log.info("Completed Summarizing, it took "+TimingProfile.profile("summarize"));
      }
      else if (args[2].equals("report"))
      {
        summary.GenerateReports();
      }
    }
  }
}