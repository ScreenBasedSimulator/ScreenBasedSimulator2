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

package mil.tatrc.physiology.datamodel.scenario;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.engine.PhysiologyEngineConfiguration;
import mil.tatrc.physiology.datamodel.scenario.actions.SEAction;
import mil.tatrc.physiology.datamodel.scenario.conditions.SECondition;
import mil.tatrc.physiology.datamodel.scenario.datarequests.*;
import mil.tatrc.physiology.datamodel.substance.SESubstance;
import mil.tatrc.physiology.datamodel.substance.SESubstanceManager;
import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;

public class SEScenario 
{
	public static void main(String[] args)
	{
		String searchDir;
		if(args.length==0)
			searchDir="../verification/Scenarios";
		else
			searchDir=args[0];
		List<String> files=FileUtils.findFiles(searchDir, ".xml", true);
		for(String file : files)
		{
			if(CDMSerializer.readFile(file)==null)
				Log.error("Unable to read file "+file);
		}
	}
	
	protected String                        name;
	protected String                        description;
  protected PhysiologyEngineConfiguration config;
	protected String                        patientFile;
	protected List<SECondition>             conditions;
	protected List<SEAction>                actions;
	protected List<SEDataRequest>           requestedData;
	protected double                        samplesPerSecond=0;
	
	protected SESubstanceManager substances;
	
	public SEScenario(SESubstanceManager substances)
	{
		this.name = "";
		this.description = "";
		this.config = null;
		this.patientFile = "";
		
		this.substances = substances; 
		
		this.conditions = new ArrayList<SECondition>();
		this.actions = new ArrayList<SEAction>();
		this.requestedData = new ArrayList<SEDataRequest>();
	}
	
	public void reset() 
	{
		name = "";
		description = "";
		patientFile = "";
		if(config!=null)
		  config.reset();
		conditions.clear();
		actions.clear();		
		requestedData.clear();	
	}
	
	public void clear() 
	{
	  config.clear();
		conditions.clear();
		actions.clear();		
		requestedData.clear();
	}
	
	public boolean load(ScenarioData in)
	{
		reset();
		
		this.name = in.getName();
		this.description = in.getDescription();
		if(in.getConfiguration()!=null)
		  getConfiguration().load(in.getConfiguration());
		this.patientFile = in.getPatientFile();
		if(in.getSamplesPerSecond()!=null)
			this.samplesPerSecond = in.getSamplesPerSecond();
		
		// Data Requests
		try
		{
			for (DataRequestData dataRequestData : in.getDataRequest())
			{
				String className = dataRequestData.getClass().getName().replaceAll("bind.", "scenario.datarequests.SE");
				className = className.substring(0, className.lastIndexOf("Data"));
				Class<?> klass = Class.forName(className);
				
				Object instance = null;
                for(Constructor<?> ctor : klass.getConstructors())
                {
                    Class<?>[] params = ctor.getParameterTypes();
                    if(params.length>0)
                    {
                        if(params[0].isAssignableFrom(SESubstance.class))
                        {
                            Method m=dataRequestData.getClass().getMethod("getSubstance");
                            String subName = (String)m.invoke(dataRequestData);
                            instance=ctor.newInstance(substances.getSubstance(subName));
                        }
                    }
                }
                if(instance==null)
                    instance = klass.newInstance();
				
				// Find the right "load" method
				Method loadMethod = null;
				for (Method m : klass.getMethods())
					if  (m.getName().equals("load"))
					{
						loadMethod = m;
						break;
					}
				
				if (loadMethod.getParameterTypes().length == 2)
					loadMethod.invoke(instance, dataRequestData, this.substances);
				else
					loadMethod.invoke(instance, dataRequestData);
				
				this.requestedData.add((SEDataRequest) instance);
			}
		}
		catch (Exception e)
		{
			Log.error("Unsupported Data Request received in scenario file", e);
		}
		
		// Conditions
		try
		{
			for (ConditionData conditionData : in.getCondition())
			{		
				SECondition c = SECondition.bind2CDM(conditionData, this.substances);
				if(c==null)
				{
					Log.error("Unable to load action "+conditionData.getClass().getName());
					return false;
				}
				else
					this.conditions.add(c);
			}
		}
		catch (Exception e)
		{
			Log.fatal("Unsupported Action type found in scenario file", e);
				}
		// Actions
		try
		{
			for (ActionData actionData : in.getAction())
			{		
				SEAction a = SEAction.bind2CDM(actionData,this.substances);
				if(a==null)
				{
					Log.error("Unable to load action "+actionData.getClass().getName());
					return false;
				}
				else
					this.actions.add(a);
			}
		}
		catch (Exception e)
		{
			Log.fatal("Unsupported Action type found in scenario file", e);
		}
		
		return isValid();
	}
	
	public ScenarioData unload()
	{
		ScenarioData data = CDMSerializer.objFactory.createScenarioData();
		unload(data);
		return data;
	}
	
	protected void unload(ScenarioData data)
	{
		if(!isValid())
		{
			Log.error("Scenario Invalid, cannot unload to a valid jaxb object");
			return;
		}
		data.setName(this.name);
		data.setDescription(this.description);
		if(hasConfiguration())
		  data.setConfiguration(config.unload());
		data.setPatientFile(this.patientFile);
		if(this.samplesPerSecond>0)
			data.setSamplesPerSecond(this.samplesPerSecond);
		for(SEDataRequest dr : this.requestedData)
			data.getDataRequest().add(dr.unload());
		for(SECondition c : this.conditions)
			data.getCondition().add(c.unload());
		for(SEAction a : this.actions)
			data.getAction().add(a.unload());
	}
	
	public boolean isValid()
	{
		if (!hasPatientFile())
			return false;
		if (actions.size() == 0)
			return false;
		return true;
	}

	public String getName()
	{
		return name;
	}
	public void setName(String name)
	{
		this.name = name;
	}
	public boolean hasName()
	{
		return name.isEmpty() ? false : true;
	}
	public void invalidateName()
	{
		name = "";
	}
	
	public String getDescription()
	{
		return description;
	}
	public void setDescription(String description)
	{
		this.description = description;
	}
	public boolean hasDescription()
	{
		return description.isEmpty() ? false : true;
	}
	public void invalidateDescription()
	{
		description = "";
	}
	
	public boolean hasConfiguration()
  {
    return config!=null;
  }
  public PhysiologyEngineConfiguration getConfiguration()
  {
    if(this.config==null)
      this.config=new PhysiologyEngineConfiguration();
    return this.config;
  }

	public String getPatientFile()
	{
		return patientFile;
	}
	public void setPatientFile(String patientFile)
	{
		this.patientFile = patientFile;
	}
	public boolean hasPatientFile()
	{
		return patientFile.isEmpty() ? false : true;
	}
	public void invalidatePatientFile()
	{
		patientFile = "";
	}
	
	public void setSamplesPerSecond(double d)
	{
		this.samplesPerSecond=d;
	}
	public double getSamplesPerSecond()
	{
		return this.samplesPerSecond;
	}
	
	public List<SECondition> getConditions() 
	{
		return conditions;
	}
	
	/*
	 * Actions
	 */
	public List<SEAction> getActions() 
	{
		return actions;
	}
	
	/*
	 * Requested Data
	 */
	public List<SEDataRequest> getRequestedData() 
	{
		return requestedData;
	}
	
	/*
	 * Substances
	 */
	public SESubstanceManager getSubstanceManager()
	{
		return this.substances;
	}
}
