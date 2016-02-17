package mil.tatrc.physiology.datamodel.patient.nutrition;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.MealData;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;

public class SEMeal extends SENutrition
{
	protected SEScalarTime	elapsedTime;
	
	public SEMeal()
	{		
	  super();
		this.elapsedTime=null;
	}
	
	public void reset()
	{
	  super.reset();
		if (elapsedTime != null)
		  elapsedTime.invalidate();	
	}
	
	public void copy(SEMeal from)
	{
		super.copy(from);
		if(from.hasElapsedTime())
			this.getElapsedTime().set(from.getElapsedTime());
	}
	
	public boolean load(MealData in)
	{
	  super.load(in);
		if (in.getElapsedTime() != null)
			getElapsedTime().load(in.getElapsedTime());
		return true;
	}
	
	public MealData unload()
	{
	  MealData data = CDMSerializer.objFactory.createMealData();
		unload(data);
		return data;
	}
	
	protected void unload(MealData data)
	{
	  super.unload(data);
		if (elapsedTime != null)
			data.setElapsedTime(elapsedTime.unload());
	}		
	
	public SEScalarTime getElapsedTime()
	{
		if (elapsedTime == null)
		  elapsedTime = new SEScalarTime();
		return elapsedTime;
	}
	public boolean hasElapsedTime()
	{
		return elapsedTime == null ? false : elapsedTime.isValid();
	}
}
