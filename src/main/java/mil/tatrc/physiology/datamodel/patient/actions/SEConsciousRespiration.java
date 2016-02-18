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

package mil.tatrc.physiology.datamodel.patient.actions;

import java.util.ArrayList;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.substance.SESubstanceFraction;

public class SEConsciousRespiration extends SEPatientAction
{
	protected List<SEConsciousRespirationCommand> commands;
	
	public SEConsciousRespiration()
	{
		commands = new ArrayList<SEConsciousRespirationCommand>();
	}
	
	public void copy(SEConsciousRespiration other)
	{
		if (this == other)
			return;
		
		if (other.commands != null)
	    {
			commands.clear();
		    for (SEConsciousRespirationCommand command : other.commands)
		    {
		        commands.add(command.getCopy());
		    }
	    }
	}	
	
	public void reset()
	{
		commands.clear();
	}
	
	public boolean load(ConsciousRespirationData in)
	{
		commands.clear();
	    for (ConsciousRespirationCommandData data : in.getCommand())
	    {
	    	if (data instanceof BreathHoldData)
	    	{
	    		SEConsciousRespirationCommand command = new SEBreathHold();
	    		((SEBreathHold)command).load((BreathHoldData)data);
	    		commands.add(command);
	    	}
	    	else if (data instanceof ForcedExhaleData)
	    	{
	    		SEConsciousRespirationCommand command = new SEForcedExhale();
	    		((SEForcedExhale)command).load((ForcedExhaleData)data);
	    		commands.add(command);
	    	}
	    	else if (data instanceof ForcedInhaleData)
	    	{
	    		SEConsciousRespirationCommand command = new SEForcedInhale();
	    		((SEForcedInhale)command).load((ForcedInhaleData)data);
	    		commands.add(command);
	    	}
	    	else if (data instanceof UseInhalerData)
	    	{
	    		SEConsciousRespirationCommand command = new SEUseInhaler();
	    		((SEUseInhaler)command).load((UseInhalerData)data);
	    		commands.add(command);
	    	}
	    }
	    
		return true;
	}
	
	public ConsciousRespirationData unload()
	{
		ConsciousRespirationData data = CDMSerializer.objFactory.createConsciousRespirationData();
		unload(data);
		
		return data;
	}
	
	protected void unload(ConsciousRespirationData data)
	{
		for (SEConsciousRespirationCommand command : commands)
		{
			if (command instanceof SEBreathHold)
			{
				data.getCommand().add(((SEBreathHold)command).unload());
			}
			else if (command instanceof SEForcedExhale)
	    	{
				data.getCommand().add(((SEForcedExhale)command).unload());
	    	}
	    	else if (command instanceof SEForcedInhale)
	    	{
	    		data.getCommand().add(((SEForcedInhale)command).unload());
	    	}
	    	else if (command instanceof SEUseInhaler)
	    	{
	    		data.getCommand().add(((SEUseInhaler)command).unload());
	    	}
		}
	}
	
	public boolean hasCommands()
	{
		return commands != null && !commands.isEmpty();
	}
	public List<SEConsciousRespirationCommand> getCommands()
	{
		return commands;
	}
	
	public String toString()
	{
		String str = new String();
		
		for (SEConsciousRespirationCommand command : commands)
		{
			str += command.toString();
		}
		
		return str;
	}
}
