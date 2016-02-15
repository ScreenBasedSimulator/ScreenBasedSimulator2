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

/*
 *        THIS MATERIAL MAY BE REPRODUCED BY OR FOR THE U.S. GOVERNMENT
 *  PURSUANT TO THE COPYRIGHT LICENSE UNDER THE CLAUSE AT DFARS 252.227-7013.
 *  COPYRIGHT (C) 2006, APPLIED RESEARCH ASSOCIATES, INC., ALL RIGHTS RESERVED.
 */
package mil.tatrc.physiology.datamodel.properties;

import java.util.Arrays;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.SEEqualOptions;
import mil.tatrc.physiology.datamodel.bind.FunctionData;
import mil.tatrc.physiology.datamodel.exceptions.InvalidUnitException;
import mil.tatrc.physiology.utilities.DoubleUtils;
import mil.tatrc.physiology.utilities.StringUtils;
import mil.tatrc.physiology.utilities.UnitConverter;

/**
 * @author abray
 */
public class SEFunction
{
  protected double[] abscissa;
  protected double[] ordinate;
  protected String   abscissaUnit;
  protected String   ordinateUnit;

  public SEFunction()
  {
    super();
    invalidate();
  }
  
  public static double[] toArray(List<Double> in)
  {
  	double[] d = new double[in.size()];
  	for(int i=0; i<in.size(); i++)
  		d[i]=in.get(i);
  	return d;
  }
  
  /**
   * List will be cleared internally
   * @param to
   * @param dAry
   */
  public static void toList(List<Double>to, double[] dAry)
  {
  	to.clear();
  	if(dAry!=null)
  	{
  	  for(double d : dAry)
  	    to.add(d);
  	}
  }

  public boolean set(SEFunction ary)
  {
  	if(!ary.isValid())
  		return false;
    this.abscissaUnit = ary.abscissaUnit;
    this.abscissa = Arrays.copyOf(ary.abscissa,ary.abscissa.length);
    this.ordinateUnit = ary.ordinateUnit;
    this.ordinate = Arrays.copyOf(ary.ordinate,ary.ordinate.length);
    return true;
  }
  
  public static synchronized boolean equals(double[] from, double[] to)
  {
    return equals(from, "", to, "", null);
  }
  public static synchronized boolean equals(double[] from, double[] to, SEEqualOptions options)
  {
    return equals(from, "", to, "", options);
  }
  public static synchronized boolean equals(double[] from, double[] to, SEEqualOptions options, String name)
  {
    return equals(from, "", to, "", options, name);
  }
  public static synchronized boolean equals(double[] from, String fromUnits, double[] to, String toUnits, SEEqualOptions options)
  {
    return equals(from, fromUnits, to, toUnits, options, null);
  }
  public static synchronized boolean equals(double[] from, String fromUnits, double[] to, String toUnits, SEEqualOptions options, String name)
  {
    if (from == to)
      return true;
    if (from == null || to == null)
      return false;

    if (name == null)
      name = "SEArray";

    if (from == null || to == null)
    {
      if (options != null)
        options.track(name, from, to);
      return false;
    }

    boolean equals = true;
    boolean forceReturn = true;
    if (options != null)
    {
      options.pushTrack(name);
      forceReturn = options.returnOnFirstDiff;
    }

    if (from.length != to.length)
    {
      if (options != null)
      {
        options.track("length", from.length, to.length);
        options.trackToMap();
      }
      return false;
    }

    if (!UnitConverter.isCompatibleWithUnit(fromUnits, toUnits))
    {
      if (options != null)
      {
        options.track("units incompatible", fromUnits, toUnits);
        options.trackToMap();
      }
      return false;
    }

    for (int i = 0; i < to.length; i++)
    {
      if (!DoubleUtils.equals(from[i], fromUnits, to[i], toUnits, options))
      {
        if (options != null)
          options.track("Array[" + i + "]", from[i], fromUnits, to[i], toUnits);
        if (forceReturn)
          return false;
        equals = false;
      }
    }

    if (options != null)
      options.trackToMap();
    return equals;
  }
  
  public int hashCode()
  {
  	int code=1;
    if(!this.isValid())
    	return 1;
    code += this.abscissa.hashCode();
    code += this.ordinate.hashCode();
    code += this.abscissaUnit.hashCode();
    code += this.ordinateUnit.hashCode();
    return code;
  }

  public boolean loadData(Object data) throws ClassCastException
  {
    if (data instanceof FunctionData)
      return load((FunctionData) data);
    else if (data instanceof SEFunction)
      return set((SEFunction) data);
    return false;
  }

  public boolean load(FunctionData in)
  {
  	if(!isValidAbscissaUnit(in.getAbscissaUnit()))
  		return false;
  	if(!isValidOrdinateUnit(in.getOrdinateUnit()))
  		return false;
    this.abscissaUnit=in.getAbscissaUnit();
    this.abscissa=SEFunction.toArray(in.getAbscissa());
    
    this.ordinateUnit=in.getOrdinateUnit();
    this.ordinate=SEFunction.toArray(in.getOrdinate());
    return this.isValid();
  }

  public Object unloadData()
  {
    return unload();
  }
  
  public FunctionData unload()
  {
    if(!this.isValid())
      return null;
    FunctionData to = CDMSerializer.objFactory.createFunctionData();
    unload(to);
    return to;
  }

  protected void unload(FunctionData to)
  {
    to.setAbscissaUnit(this.abscissaUnit);
    SEFunction.toList(to.getAbscissa(),this.abscissa);
    
    to.setOrdinateUnit(this.ordinateUnit);
    SEFunction.toList(to.getOrdinate(),this.ordinate);
  }
  
  public boolean isValid()
  {
    if(this.abscissa.length==0||this.ordinate.length==0)
      return false;
    if(!isValidAbscissaUnit(this.abscissaUnit))
    	return false;
    if(!isValidOrdinateUnit(this.ordinateUnit))
    	return false;
    return true;
  }
  
  public boolean isValidAbscissaUnit(String unit)
  {
  	return true;
  }
  
  public boolean isValidOrdinateUnit(String unit)
  {
  	return true;
  }
  
  public void invalidate()
  {
    this.abscissa = new double[0];
    this.ordinate = new double[0];
    this.abscissaUnit="";
    this.ordinateUnit="";
  }

  public boolean equals(Object to)
  {
    if ((to == null) || !(to instanceof SEFunction))
    {
      return false;
    }

    return SEFunction.equals(this, (SEFunction) to, null);
  }

  public boolean equals(SEFunction to, SEEqualOptions options)
  {
    return SEFunction.equals(this, to, options);
  }

  public static boolean equals(SEFunction from, SEFunction to)
  {
    return SEFunction.equals(from, to, null);
  }
  
  public static boolean equals(SEFunction from, SEFunction to, SEEqualOptions options)
  {
    return equals(from, to, options, null);
  }

  public static boolean equals(SEFunction from, SEFunction to, SEEqualOptions options, String name)
  {
    if (from == to)
      return true;
    if (to == null && from != null && !from.isValid())
      return true;
    if (from == null && to != null && !to.isValid())
      return true;

    boolean forceReturn = true;
    if (options != null)
    {
      if (name == null)
        name = "SEFunction";
      options.pushTrack(name);
      forceReturn = options.returnOnFirstDiff;
    }

    if (from == null || to == null)
    {
      if (options != null)
      {
        options.track(name, from, to);
        options.trackToMap();
      }
      return false;
    }
    if (!from.isValid() && !to.isValid())
    {
    	if(options != null)
        options.trackToMap();
      return true;
    }
    if((from.isValid()&&!to.isValid())||(!from.isValid()&&to.isValid()))
    {
      if(options!=null)
      {
        options.trackInvalid(name.toString(),from,to);
        options.trackToMap();
      }
     return false; 
    }

    boolean equals = true;
    if (!SEFunction.equals(from.abscissa, from.abscissaUnit, to.abscissa, to.abscissaUnit, options, "abscissa"))
    {
      if (forceReturn)
      {
        if(options!=null)
          options.trackToMap();
        return false;
      }
      equals = false;
    }

    if (!SEFunction.equals(from.ordinate, from.ordinateUnit, to.ordinate, to.ordinateUnit, options, "ordinate"))
    {
      if (forceReturn)
      {
        if(options!=null)
          options.trackToMap();
        return false;
      }
      equals = false;
    }

    if (options != null)
      options.trackToMap();
    return equals;
  }
  
  public int length()
  {
  	return this.ordinate.length;
  }
  
  public String getAbscissaUnit()
  {
  	return this.abscissaUnit;
  }
  
  public String getOrdinateUnit()
  {
  	return this.ordinateUnit;
  }

  public double[] getAbscissa()
  {
    return this.abscissa;
  }
  
  public double[] getAbscissa(String unit)
  {
  	if(!isValidAbscissaUnit(unit))
  		throw new InvalidUnitException(unit, "Abscissa");
  	if(this.abscissaUnit.equals(unit))
  		return this.abscissa;
  	return UnitConverter.convert(abscissa, abscissaUnit, unit);
  }
  
  public String getAbscissaString()
  {
    return StringUtils.toString(this.abscissa);
  }
  
  public String getAbscissaString(String unit)
  {
  	if(!isValidAbscissaUnit(unit))
  		throw new InvalidUnitException(unit, "Abscissa");
  	if(this.abscissaUnit.equals(unit))
  		return StringUtils.toString(this.abscissa);
  	double[]d=UnitConverter.convert(abscissa, abscissaUnit, unit);
  	return StringUtils.toString(d);
  }
  
  public void setAbscissa(double[] data)
  {
  	if(!isValidAbscissaUnit(""))
  		throw new InvalidUnitException("no unit", "Abscissa");
  	this.abscissa=data;
  	this.abscissaUnit="";
  }
  
  public void setAbscissa(double[] data, String unit)
  {
  	if(!isValidAbscissaUnit(unit))
  		throw new InvalidUnitException(unit, "Abscissa");
  	this.abscissa=data;
  	this.abscissaUnit=unit;
  }

  public void setAbscissa(String data)
  {
  	if(!isValidAbscissaUnit(""))
  		throw new InvalidUnitException("no unit", "Abscissa");
  	this.abscissa=StringUtils.toArray(data);
  	this.abscissaUnit="";
  }
  
  public void setAbscissa(String data, String unit)
  {
  	if(!isValidAbscissaUnit(unit))
  		throw new InvalidUnitException(unit, "Abscissa");
  	this.abscissa=StringUtils.toArray(data);
  	this.abscissaUnit=unit;
  }
  
  public double[] getOrdinate()
  {
    return this.ordinate;
  }
  
  public double[] getOrdinate(String unit)
  {
  	if(!isValidOrdinateUnit(unit))
  		throw new InvalidUnitException(unit, "Ordinate");
  	if(this.ordinateUnit.equals(unit))
  		return this.ordinate;
  	return UnitConverter.convert(ordinate, ordinateUnit, unit);
  }
  
  public String getOrdinateString()
  {
    return StringUtils.toString(this.ordinate);
  }
  
  public String getOrdinateString(String unit)
  {
  	if(!isValidOrdinateUnit(unit))
  		throw new InvalidUnitException(unit, "Ordinate");
  	if(this.ordinateUnit.equals(unit))
  		return StringUtils.toString(this.ordinate);
  	double[]d=UnitConverter.convert(ordinate, ordinateUnit, unit);
  	return StringUtils.toString(d);
  }
  
  public void setOrdinate(double[] data)
  {
  	if(!isValidOrdinateUnit(""))
  		throw new InvalidUnitException("no unit", "Ordiate");
  	this.ordinate=data;
  	this.ordinateUnit="";
  }
  
  public void setOrdinate(double[] data, String unit)
  {
  	if(!isValidOrdinateUnit(unit))
  		throw new InvalidUnitException(unit, "Ordiate");
  	this.ordinate=data;
  	this.ordinateUnit=unit;
  }
  
  public void setOrdinate(String data)
  {
  	if(!isValidOrdinateUnit(""))
  		throw new InvalidUnitException("no unit", "Ordinate");
  	this.ordinate=StringUtils.toArray(data);
  	this.ordinateUnit="";
  }
  
  public void setOrdinate(String data, String unit)
  {
  	if(!isValidOrdinateUnit(unit))
  		throw new InvalidUnitException(unit, "Ordinate");
  	this.ordinate=StringUtils.toArray(data);
  	this.ordinateUnit=unit;
  }
}
