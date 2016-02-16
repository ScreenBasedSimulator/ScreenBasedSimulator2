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

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import mil.tatrc.physiology.utilities.Log;

/**
 * @author abray
 *
 */
public class ScenarioResult
{
  // The file
  protected String          resultsFile;
  protected List<String>    headers;
  List<Double>              rowDoubles = new ArrayList<Double>();

  public ScenarioResult(String resultsFile) throws FileNotFoundException
  {
  	this.resultsFile = resultsFile;
  	this.headers = new ArrayList<String>();
  	
  	String[] headers;
  	FileInputStream fStream = new FileInputStream(resultsFile);
  	DataInputStream in = new DataInputStream(fStream);
  	BufferedReader buff = new BufferedReader(new InputStreamReader(in));
  	try
  	{
  		headers=readNextLine(buff);
  		for(int i=0; i<headers.length; i++)
  		{
  			this.headers.add(headers[i]);
  		}
  	}
  	catch(Exception ex)
  	{
  		Log.error("Error reading next line",ex);
  	}
  	try
    {
      if(in!=null)
        in.close();
    }
    catch(Exception ex)
    {
      Log.error("Unable to close file");
    }
  };
  
  public List<String> getHeaders() 
  {
  	return Collections.unmodifiableList(this.headers);
  }
  
  /**
   * Reads data in and only stores the header column into memory
   * @return
   */
  public boolean readHeader(String header, List<Double> data)
  {
  	int idx=this.headers.indexOf(header);
  	if(idx==-1)
  	{
  		Log.error(header+" is not a valid header from results file");
  		return false;
  	}
  	FileInputStream fStream;
  	DataInputStream in;
  	BufferedReader buff;
  	try
  	{// Read/Ignore the header
  		fStream = new FileInputStream(resultsFile);
  		in = new DataInputStream(fStream);
  		buff = new BufferedReader(new InputStreamReader(in));
  		buff.readLine();
    }catch(Exception ex){Log.error(ex);return false;}
  	
  	double d;
  	boolean noZero=false;
  	if(header.indexOf("PlasmaConcentration")>-1)
  	  noZero=true;
  	data.clear();
  	while(parseLine(buff))
    {
  	  d=this.rowDoubles.get(idx);
  	  if(noZero&&d<=0)
  	    d=Double.NaN;
    	data.add(d);
    }
  	this.rowDoubles.clear();
  	try
    {
      if(in!=null)
        in.close();
    }
    catch(Exception ex)
    {
      Log.error("Unable to close file");
    }
  	return true;
  }
  

  /**
   * This will load the entire contents into memory
   * @param filePath
   * @throws FileNotFoundException
   */
  public Map<String,List<Double>> readAll() 
  {
  	Map<String,List<Double>>results=new HashMap<String,List<Double>>();
  	List<Double> list=null;
  	FileInputStream fStream;
  	DataInputStream in;
  	BufferedReader buff;
  	try
  	{// Read/Ignore the header
  		fStream = new FileInputStream(resultsFile);
  		in = new DataInputStream(fStream);
  		buff = new BufferedReader(new InputStreamReader(in));
  		buff.readLine();
    }catch(Exception ex){Log.error(ex);return null;}
  	
  	int h;
  	double d;
    while(parseLine(buff))
    {
    	h=0;
    	for(String header : this.headers)
    	{
    		list=results.get(header);
    		if(list==null)
    		{
    			list=new ArrayList<Double>();
    			results.put(header, list);
    		}
    		d=this.rowDoubles.get(h++);
    		if(d<=0&&header.indexOf("PlasmaConcentration")>-1)
    		  d=Double.NaN;
    		list.add(d);
    	}
    }
    this.rowDoubles.clear();
    try
    {
      if(in!=null)
        in.close();
    }
    catch(Exception ex)
    {
      Log.error("Unable to close file");
    }
    return results;
  }

  protected String[] readNextLine(BufferedReader buff) throws IOException
  {
    String[] row;
    String aLine=null;
    aLine = buff.readLine();
    if(aLine==null)
      return null;
    String aLine2 = aLine.replaceAll("\\s+", " ");
    row=aLine2.split(" ");
    if(!this.headers.isEmpty()&&this.headers.size()!=row.length)
    {
      Log.error("Did not find the expected number of results on line");
    }  
    return row;
  }
  
  protected boolean parseLine(BufferedReader buff)
  {
  	this.rowDoubles.clear();
  	double data;
  	String[] rowData;
  
  	try
  	{
  		rowData=readNextLine(buff);
  	}
  	catch(Exception ex)
  	{
  		Log.error("Error reading next line",ex);
  		return false;
  	}
  	if(rowData==null)
  		return false;
  	for(int r=0; r<rowData.length; r++)
  	{
  		try
  		{
  			data = Double.parseDouble(rowData[r]);
  		}
  		catch(NumberFormatException ex)
  		{
  			if(rowData[r].indexOf("IND")>-1||
               rowData[r].indexOf("INF")>-1||
               rowData[r].indexOf("NAN")>-1||
               rowData[r].indexOf("nan")>-1)
  			{
  				data = Double.NaN;    	  	
  			}
  			else
  			{
  				Log.error("Error reading input on line " + this.headers.get(r));
  				throw new RuntimeException("Error reading in data: non doubles detected");
  			}
  		}      	
  		this.rowDoubles.add(data);    	  
  	}
  	return true;
  }

}
