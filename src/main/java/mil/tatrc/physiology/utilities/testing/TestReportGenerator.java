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

/**
 * 
 */
package mil.tatrc.physiology.utilities.testing;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.InputStream;
import java.net.InetAddress;
import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.utilities.*;

/**
 * @author abray
 *
 * Reads a provided config file to run
 * the specified UnitTestSuite with the provided arguments
 * Will write out reports and email a summary of the reports
 */
public class TestReportGenerator extends TestReport
{  
  protected enum Mode {BUILD_REPORTS,SUMMARIZE_REPORTS}
  protected String reportDir = "./";
  protected String emailSubject=null;
  protected String emailSender=null;
  protected String emailSMTP=null;
  protected String[] emailRecipients=null;
  protected Map<String,TestReport> reports=new HashMap<String,TestReport>();
  protected boolean writeFiles=true;
  protected String configFile;
  protected static int revisionNum = 0;
  
  public void writeFiles(boolean b)
  {
    this.writeFiles=b;
  }
  
  public void setConfigFile(String cfgFile)
  {
    this.configFile=cfgFile;
    String rptFile=cfgFile.replaceAll(".config", ".xml");
    String[] dirs = rptFile.split("[/\\\\]");
    rptFile = dirs[dirs.length-1];
    this.setFileName(rptFile);
  }
  
  public TestReportData unload()
  {
    Set<String> marks = new HashSet<String>();
    TestReportData testReport = CDMSerializer.objFactory.createTestReportData();
    for(TestReport rpt : reports.values())
    {
      for(TestSuite suite : rpt.testSuites)
      {
        testReport.getTestSuite().add(suite.unload());
      }
    }   
    return testReport;
  }
  
  /**
   * @param args
   * args[0] = The config file of the 
   */
  public static void main(String[] args)
  { 
    int error=0;
    TestReportGenerator generator = new TestReportGenerator();
    
    if (args.length < 1)
    {
      TestReport errRpt = new TestReport();
      errRpt.createErrorSuite("Error: Must provide a config file");
      generator.reports.put("Error",errRpt);
      error=1;
    }
    else
    {
      int inputRev=0;
      if(args.length>=2)
    	  inputRev=Integer.parseInt(args[1]);
      if(inputRev!=0)
      {
    	  revisionNum = inputRev;
      }
      try
      {
        generator.setConfigFile(args[0]);
        boolean streamprops=true;
        if(!streamprops)
          generator.run(args[0]);
        else
        {     
          String str = FileUtils.readFile(args[0]);
          InputStream is = new ByteArrayInputStream(str.getBytes());
          OrderedProperties props = new OrderedProperties();
          props.load(is);
          if(!generator.run(props))
          {
        	  TestReport errRpt = new TestReport();
              errRpt.createErrorSuite("Error : Something is wrong with "+args[0]+" check the log");
              generator.reports.put("Error",errRpt);
              error=1;
          }
        }
        //generator.write();
      } 
      catch(Exception ex)
      {
        Log.error(ex);
        TestReport errRpt = new TestReport();
        errRpt.createErrorSuite("Error : " + ex.getMessage());
        generator.reports.put("Error",errRpt);
        error=1;
      }

    }
    System.exit(error);
  }
  
  public boolean run(String propsFile)
  {
    try
    {
      this.setConfigFile(propsFile);
      OrderedProperties props = new OrderedProperties();
      props.load(propsFile);
      return run(props);
    } 
    catch(Exception ex)
    {
      Log.error(ex);
      TestReport errRpt = new TestReport();
      errRpt.createErrorSuite("Error : " + ex.getMessage());
      reports.put("Error",errRpt);
      summarizeReports();
      return false;
    }
  }
  
  public boolean run(OrderedProperties props)
  {    
    Mode mode = null;
    Set<String> keySet = props.keySet();
    for(String key : keySet)
    {
      if(key.equals("subject"))
      {
        this.emailSubject=props.get(key);
        continue;
      }
      if(key.equals("sender"))
      {
        this.emailSender=props.get(key);
        continue;
      }
      if(key.equals("recipients"))
      {
        this.emailRecipients=props.get(key).split(",");
        continue;
      }    
      if(key.equals("smtp"))
      {
        this.emailSMTP=props.get(key);
        continue;
      }
      if(key.equals("reportDir"))
      {
        this.reportDir=props.get(key);
        continue;
      }
      
      if(key.endsWith(".xml"))
      {
        if(mode==null)
          mode = Mode.BUILD_REPORTS;
        if(!mode.equals(Mode.BUILD_REPORTS))
        {
          Log.error("Cannont build reports and summarize reports at the same time");
          return false;
        }

        Object obj;
        String[] args=props.get(key).split(",");
        try
        {
          obj=Class.forName(args[0]).newInstance();
        }
        catch(Exception ex)
        {
          Log.error(ex);
          TestReport report = new TestReport();
          report.setFileName(key);
          report.setReportDestination(reportDir);
          reports.put(key, report);
          report.createErrorSuite(ex.getMessage());
          if(writeFiles)
            report.write();
          continue;
        }
        if(obj instanceof TestSuite)
        {
          TestReport report = new TestReport();
          report.setFileName(key);
          report.setReportDestination(reportDir);
          reports.put(key, report);
          TestSuite testSuite=(TestSuite)obj;
          testSuite.setDatabaseDirectory(this.dbDirectory);
          Log.info("Executing TestSuite "+obj.getClass().getName());
          // Shift Args by 1 and pass them on
          String[] sArgs = new String[args.length-1];
          for(int i=0; i<sArgs.length; i++)
            sArgs[i]=args[i+1];
          if(testSuite.initialize(sArgs))
            report.startSuite(testSuite);
          else
            report.createErrorSuite("Could not init "+key);
          if(writeFiles)
            report.write();
          continue;
        }
        else if(obj instanceof TestReport)
        {
          TestReport rpt = (TestReport)obj;
          rpt.setFileName(key);
          rpt.setReportDestination(this.reportDir);
          reports.put(key, rpt);
          // Shift Args by 1 and pass them on
          String[] sArgs = new String[args.length-1];
          for(int i=0; i<sArgs.length; i++)
            sArgs[i]=args[i+1];
          if(rpt.initialize(sArgs))          
            rpt.run();
          else
            rpt.createErrorSuite("Could not initialize "+key);
          if(writeFiles)
            rpt.write();
          continue;
        }
        else
          Log.error("Unsupported class type of "+obj.getClass().getName());
      }
      else
      {
        if(mode==null)
          mode = Mode.SUMMARIZE_REPORTS;
        if(!mode.equals(Mode.SUMMARIZE_REPORTS))
        {
          Log.error("Cannont build reports and summarize reports at the same time");
          return false;
        }
        String[] args=props.get(key).split(",");        
        addToSummary(this, args[0]);
      }
    }
    // Done processing 
    
    if(mode.equals(Mode.BUILD_REPORTS))
    {
      TestReport summary = summarizeReports();
      summary.setFileName(this.fileName);
      summary.setReportDestination(this.reportDir);
      email(summary);
      if(writeFiles)
        summary.write();
    }
    else if(mode.equals(Mode.SUMMARIZE_REPORTS))
    {
      this.reports.put("Me", this);
      email(this);
      if(writeFiles)
        this.write();
    }
    return true;
  }
  
  public TestReport summarizeReports()
  {
    // Write out and email all the reports we made
    if(writeFiles)
    {
      for(TestReport report : reports.values())
        report.write();
    }
    // Create a summary of all the reports we made
    TestReport summary = new TestReport();
    for(TestReport report : reports.values())
      summary.addSummary(report);
    return summary;
  }
  
  protected void email(TestReport report)
  {
    if(this.emailSubject!=null&&
       this.emailRecipients!=null&&
       this.emailSender!=null&&
       this.emailSMTP!=null)
    {
    	//Get the name of the computer
    	String hostname = "Unknown";
    	try
    	{
    		InetAddress addr = InetAddress.getLocalHost();
    		hostname = addr.getHostName();
    	}
    	catch(Exception ex)
    	{
    		System.out.println("Hostname can not be resolved");
    	}  
    	//Get revision number if found add it to the email and make a copy of the bin
    	String revision= "";
    	if(revisionNum!=0)
    	{
    		revision= " Revision "+revisionNum;
    	}
      // Email out a summary of all the reports we made
      EmailUtil email = new EmailUtil();
      email.setSubject(this.emailSubject + " from "+hostname+revision);
      email.setSender(this.emailSender);
      email.setSMTP(this.emailSMTP);
      for(String recipient : this.emailRecipients)
        email.addRecipient(recipient);
      email.sendHTML(report.toHTML());
    }
    else
      Log.warn("Not sending email since all nessesary email info was not provided");
  }
   
  public boolean addToSummary(TestReport summary, String testReportFile)
  {
    if(!FileUtils.fileExists(testReportFile))
    {
      summary.createErrorSuite("Unable to find file "+testReportFile+" to summarize");
      return false;
    }
    Object o = CDMSerializer.readFile(testReportFile);
    if(o instanceof TestReportData)
    {
      TestSuite s;
      TestReportData summarize = (TestReportData)o;        
      for(TestReportData.TestSuite suite : summarize.getTestSuite())
      {
        s=new TestSuite();
        s.load(suite);
        summary.addSuite(s);
      }
      return true;
    }
    else
    {
      summary.createErrorSuite(testReportFile);
      Log.error("Need file with TestReportData object");
    }
    return false;
  }
  public void run(){}
  
  private static boolean isInt(String str)  
  {  
    try  
    {  
      Integer.parseInt(str);  
    }  
    catch(NumberFormatException nfe)  
    {  
      return false;  
    }  
    return true;  
  }
}
