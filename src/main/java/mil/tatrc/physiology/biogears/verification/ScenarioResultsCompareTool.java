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

package mil.tatrc.physiology.biogears.verification;

import java.awt.Color;
import java.io.*;
import java.util.*;

import org.jfree.data.xy.XYSeries;

import mil.tatrc.physiology.datamodel.SEEqualOptions;
import mil.tatrc.physiology.utilities.*;

/**
 * @author abray
 *
 */
public class ScenarioResultsCompareTool extends TestReport
{
  protected double limit=3.0;
  protected boolean reportDifferences=false;
  protected List<String> exclude = new ArrayList<String>();
  
  protected boolean zipFiles=false;
  protected boolean createCSV=false;//TODO No option for this, until it's wanted again
  protected String  expectedLogFileName;
  
  public static void main(String[] args) throws IOException, InterruptedException
  {
    if(args.length<2)
    {
      if(args.length==1&&args[0].equals("default"))
      {
        args = new String[10];
        args[0] = "./Scenario1Results_1.txt";// Expected
        args[1] = "./Scenario1Results_1.txt";// Computed   
        args[2] = "2.0";// Percent Difference Allowed        
        args[3] = "0";// Start Comparing at time (in seconds)
        args[4] = "false";// Report Differences in the error report, turn off if you are expecting a LOT of error
        args[5] = "./testing/report";// Comparison Results Destination  
        args[6] = "FALSE"; //to zip or not to zip
        args[7] = "BODY_ART"; // Do not verify
        args[8] = "BODY_ECG"; // Do not verify
      }
      else
      {
        Log.fatal("Expected inputs : [expected results file path] [computed results file path] [percentDifference] [time to start comparing at] [track differences] [output folder] [zip results]");
        return;
      }
    }

    ScenarioResultsCompareTool t = new ScenarioResultsCompareTool();
    
    File expected = new File(args[0]);
    if(!expected.exists())
    {
    	Log.error("Expected file does not exist "+args[0]);
    	return;
    }
    File computed = new File(args[1]);
    if(!computed.exists())
    {
    	Log.error("Computed file does not exist "+args[1]);
    	return;
    }
    t.name = computed.getName().substring(0,computed.getName().length()-4);
    
    // The Format of Log file to look for
    t.expectedLogFileName = computed.getAbsolutePath().replace("Results_1", "Log");
    if(!(new File(t.expectedLogFileName).exists()))
    		t.expectedLogFileName = "";
    
    // Tolerance Limit
    if(args.length>2)
      t.limit=Double.parseDouble(args[2]);
    
    // Report the differences
    t.reportDifferences = false;
    if(args.length>4&&args[4]!=null&&args[4].equalsIgnoreCase("true"))
      t.reportDifferences = true;
     
    // Where to put results
    if(args.length>5)
    	t.reportDir = args[5]+"/"+t.name+"/";
    else 
    	t.reportDir = "./compare_results/"+t.name+"/";
    FileUtils.delete(t.reportDir);
    Thread.sleep(1000);
    FileUtils.createDirectory(t.reportDir);
    t.setFileName(t.name+"Report");
    
    // Should we zip
    if(args.length>6)
    	t.zipFiles = args[6].equalsIgnoreCase("true");

    for(int i=7; i<args.length; i++)
    {
      t.exclude.add(args[i]);
      Log.info("Not verifying : " + args[i]);
    }
    
    Log.info("Verifying "+args[0]);
    t.compare(args[0],args[1]);
    t.write();
  }

  /**
   * @param args
   */
  public void compare(String expectedFilePath, String computedFilePath)
  {    
    // Create the Test Case
    TestSuite suite = new TestSuite();
    suite.setName(this.name);
    this.addSuite(suite);
    suite.startCase(this.name);
    // Set up the Compare Options
    SEEqualOptions opts = suite.getCaseEqualOptions();
    opts.setPercentDifference(this.limit);
    opts.trackError(true);
    opts.trackDifferences(false);
    //opts.truncateMantissasTo(5);
    
    ScenarioResult expectedResults;
    ScenarioResult computedResults;
    try
    {
    	expectedResults = new ScenarioResult(expectedFilePath);
    	computedResults = new ScenarioResult(computedFilePath);
    }
    catch(IOException ex)
    {
      Log.error("Unable to read input files",ex);
      suite.endCase();
      return;
    }
    
    ScenarioPlotTool plot = new ScenarioPlotTool();
    List<Double> errorData=null;
    List<Double> residualData=null;
    List<String> expectedHeaders = expectedResults.getHeaders();
    List<String> computedHeaders = computedResults.getHeaders();
    List<Double> expectedData=new ArrayList<Double>();
    List<Double> computedData=new ArrayList<Double>();

    if(expectedHeaders.size()!=computedHeaders.size())
    {
    	Log.warn("Number of results is different, expected "+expectedHeaders.size()+" but computed is "+computedHeaders.size());
    }
    
    for(String header : expectedHeaders)
    {
      if(!computedHeaders.contains(header))
      {
    	  if(this.exclude.contains(header))
    		  Log.info(header+" is in baseline but not in computed resultes, it will not be compared (or throw an error) as it was explicitly excluded from comparison");
    	  else
    		  Log.error("Computed results did not provide expected result '"+header);
      }       
    }
    
    boolean readAll=true;
    Map<String,List<Double>> allExpected=null;
    Map<String,List<Double>> allComputed=null;
    if(readAll)
    {
      allExpected = expectedResults.readAll();
      allComputed = computedResults.readAll();      
    }
    
    int totalErrors=0;
    int computedErrors;
    List<Double> expectedTime;
    List<Double> computedTime;
    if(!readAll)
    {
      expectedTime = new ArrayList<Double>();
      computedTime = new ArrayList<Double>();
      // Confirm the times are the same
      expectedResults.readHeader("Time(s)",expectedTime);
      computedResults.readHeader("Time(s)",computedTime);
    }
    else
    {
      expectedTime = allExpected.get("Time(s)");
      computedTime = allComputed.get("Time(s)");
    }
    
    boolean compare=true;
    boolean graph=true;
    boolean graphErrors=false;
    if(graphErrors)
    {
       errorData = new ArrayList<Double>();
       residualData = new ArrayList<Double>();
    }
    totalErrors += compare("Time(s)",null,expectedTime,computedTime,opts,null,null);// don't need to track diffs in time
    if(totalErrors>0)
    {
      compare=false;
      Log.error("Times do not match, not comparing, but will plot");
    }
    allExpected.remove("Time(s)");
    allComputed.remove("Time(s)");
    // Create an XYSeries and reuse it
   
    // Compare the rest
    for(String header : expectedHeaders)
    {
    	if("Time(s)".equals(header))
    		continue;
    	if(exclude.contains(header))
    		continue;
    	if(!computedHeaders.contains(header))
    		continue;
    	// Clear out the last runs data;
    	expectedData.clear();
    	computedData.clear();
    	if(errorData!=null)
    	  errorData.clear();
    	if(residualData!=null)
    	  residualData.clear();
    	System.gc();
    	
    	if(!readAll)
    	{
      	expectedResults.readHeader(header,expectedData);
      	computedResults.readHeader(header,computedData);
    	}
    	else
    	{
    	  expectedData = allExpected.get(header);
    	  computedData = allComputed.get(header);
    	  allExpected.remove(header);// Take it out of the map
        allComputed.remove(header);// Take it out of the map
    	}
    	try
    	{
    	  if(compare)
    	    computedErrors=compare(header,expectedTime,expectedData,computedData,opts,errorData,residualData);
    	  else
    	    computedErrors=0;
    	}
    	catch(Exception ex)
    	{
    	  
    	  Log.error("Unable to compare header " + header, ex);
    	  continue;
    	}

    	if(graph)
    	{
    	  try
    	  {    	   
    	    plot.createGraph
    	    (    	       
    	        this.reportDir,
    	        computedErrors>0?Color.red:Color.green,
    	            header+"vsTime",// Title
    	            "Time(s)",// X Axis
    	            header,// Y Axis
    	            plot.createTruncatedXYSeries("Expected", expectedTime, expectedData),
    	            plot.createTruncatedXYSeries("Computed", computedTime, computedData)
    	        );

    	    if(createCSV)
    	      createCompareCSV(this.reportDir+"/"+header+"vsTime", expectedTime, expectedData, computedData);

    	    if(graphErrors && computedErrors>0)
    	    {
    	      plot.createGraph
    	      (
    	          this.reportDir,
    	          Color.white,
    	          header+"vsTime-Error",// Title
    	          "Time(s)",// X Axis
    	          header+" Error ["+this.limit+"% Difference]",// Y Axis
    	          plot.createTruncatedXYSeries("Error", expectedTime, errorData)
    	          );
    	      
    	      plot.createGraph
    	      (
    	          this.reportDir,
                Color.white,
    	          header+"vsTime-Residual",// Title
    	          "Time(s)",// X Axis
    	          header+" Residual [computed - expected]",// Y Axis
    	          plot.createTruncatedXYSeries("Residual", expectedTime, residualData)
    	          );
    	    }

    	    if(createCSV)
    	      createCSV(this.reportDir+"/"+header+"Error", expectedTime, errorData);
    	  }
    	  catch(Exception ex)
    	  {
    	    Log.error("Unable to create graph for " + header, ex);
    	  }
    	}
    	
    	totalErrors+=computedErrors;
    }
    
    if(graph)
    {
      // Graph anything that was not in the expected data as well
      for(String header : computedHeaders)
      {
        if(expectedHeaders.contains(header))
          continue;

        try
        {
          computedData = allComputed.get(header);          
          allComputed.remove(header);// Take it out of the map
          plot.createGraph
          (
              this.reportDir,
              Color.white,
              header+"vsTime",// Title
              "Time(s)",// X Axis
              header,// Y Axis
              plot.createTruncatedXYSeries("Computed", computedTime, computedData)
              );      
        }
        catch(Exception ex)
        {
          Log.error("Unable to create graph for " + header, ex);
        }
      }
    }

    if(totalErrors>0)
      Log.error(totalErrors+" errors found");
    if(suite.caseFailed())
      Log.error(computedFilePath +" Comparison failed!!");
    else
      Log.info(computedFilePath + " Comparison SUCCESS!!");
        
    if(this.zipFiles)
    {
	    //generate list of files
    	List<String> zipFileList = new ArrayList<String>();
    	generateZipFileList(this.reportDir,zipFileList);
	    // TODO Look for a log file - FileName up to Report_1 + Log.txt
	    if(!this.expectedLogFileName.isEmpty())
	      zipFileList.add(this.expectedLogFileName);
	    zipFileList.add(computedFilePath);
	    
	    //zip files
	    //delete old zip
	    FileUtils.delete(this.reportDir+"/"+this.name+".zip");
	    createZipFile(this.reportDir+"/"+this.name, zipFileList);
    }
    
    suite.endCase();
  }
  
  public static void createZipFile(String outputLocation, List<String> files)
  {
		  String[] fileArray = new String[files.size()];

		  int j = 0;
		  for(String file : files)
			  fileArray[j++] = file;
		  
		  System.out.println("Zipping: " + outputLocation);
		  FileUtils.zipFiles(fileArray, outputLocation);
		  
		  System.out.println("Deleting: " + outputLocation);
		  FileUtils.deleteFiles(fileArray);
		  fileArray.toString();
  }
  
  protected void generateZipFileList(String folder, List<String> zipFileList)
  {
  	File directory = new File(folder);

	  if(directory.isFile())
		  zipFileList.add(directory.getAbsoluteFile().toString());
	  else
	  {
		  String[] subItems = directory.list();
		  for(String filename : subItems)
		  {
			  generateZipFileList(folder + '\\' + filename,zipFileList);
		  }
	  }
  }
  
  public static void createCompareCSV(String title, List<Double> time, List<Double> expected, List<Double> computed)
  {
	  
	  Iterator<Double> timeData = time.iterator();
	  Iterator<Double> expectedData = expected.iterator();
	  Iterator<Double> computedData = computed.iterator();
	  
	  FileWriter out = null;
	  BufferedWriter writer = null;
	  
	  try
	  {
		  out = new FileWriter(StringUtils.removeParens(title) +".csv");
		  writer = new BufferedWriter(out);
		  writer.write("Time, Expected, Computed");
		  writer.newLine();
	  }
	  catch(IOException e)
	  {
		  e.printStackTrace();
	  }
	  
	  while(timeData.hasNext())
	  {  
		  try
		  {
			  if(expectedData.hasNext()&&computedData.hasNext()){
				  writer.write(timeData.next() + "," + expectedData.next() + "," + computedData.next());
			  }else if(expectedData.hasNext()){
				  writer.write(timeData.next() + "," + expectedData.next() + ",");
			  }else if(computedData.hasNext()){
				  writer.write(timeData.next() + "," + ","+ computedData.next());
			  }
			  writer.newLine();
			  
		  }
		  catch(IOException e)
		  {
			  e.printStackTrace();
		  }
	  }  
	  
	  if (out != null) 
	  {
		   try 
		   {
			   out.close();
		   } 
		   catch (IOException e) 
		   {
			   e.printStackTrace();
		   }
	   } 
  }
  
  public static void createCSV(String title, List<Double> time, List<Double> error)
  {
	  
	  Iterator<Double> timeData = time.iterator();
	  Iterator<Double> errorData= error.iterator();
	  
	  FileWriter out = null;
	  BufferedWriter writer = null;
	  
	  try
	  {
		  out = new FileWriter(StringUtils.removeParens(title) +".csv");
		  writer = new BufferedWriter(out);
		  writer.write("Time, Error");
		  writer.newLine();
	  }
	  catch(IOException e)
	  {
		  e.printStackTrace();
	  }
	  
	  while(timeData.hasNext()&&errorData.hasNext())
	  {  
		  try
		  {
			  writer.write(timeData.next() + "," + errorData.next() );
			  writer.newLine();			  
		  }
		  catch(IOException e)
		  {
			  e.printStackTrace();
		  }
	  }  
	  
	  if (out != null) 
	  {
		   try 
		   {
			   out.close();
		   } 
		   catch (IOException e) 
		   {
			   e.printStackTrace();
		   }
	   } 
  }
  
  private double eScalar;
  private double cScalar;
  private int compare(String name, List<Double> time, List<Double> expected, List<Double> computed, SEEqualOptions opts, List<Double> errorData,List<Double> residualData)
  {
    int numErrs=0;
    for(int i=0; i<expected.size(); i++)
    {
      if(i>=computed.size())
        return numErrs;// Ran out of computed values
      
      eScalar=expected.get(i);
      cScalar=computed.get(i);
      if(!DoubleUtils.equals(eScalar, cScalar, opts))
      {
        numErrs++;
        if(reportDifferences)
        {
          if(time==null)
            Log.error(name+" does not match expected "+expected.get(i)+", != computed "+computed.get(i)+" ["+opts.getLastError()+"%]","");
          else
            Log.error(name+" @Time "+time.get(i)+": expected "+expected.get(i)+", != computed "+computed.get(i)+" ["+opts.getLastError()+"%]","");
        }
        else if(numErrs==1)
        	Log.error("Compare Failed for "+name);
      }
      if(errorData!=null)
        errorData.add(opts.getLastError());
      if(residualData!=null)
        residualData.add(cScalar - eScalar);//computed - expected
    }
    return numErrs;
  } 
}
