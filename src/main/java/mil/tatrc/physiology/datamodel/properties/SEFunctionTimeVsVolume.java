/**
 * 
 */
package mil.tatrc.physiology.datamodel.properties;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.FunctionTimeVsVolumeData;
import mil.tatrc.physiology.datamodel.exceptions.InvalidUnitException;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.TimeUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.VolumeUnit;


/**
 * @author abray
 */
public class SEFunctionTimeVsVolume extends SEFunction
{
  public SEFunctionTimeVsVolume()
  {
    super();
  }
    
  public FunctionTimeVsVolumeData unload()
  {
    if(!isValid())
      return null;
    FunctionTimeVsVolumeData to = CDMSerializer.objFactory.createFunctionTimeVsVolumeData();
    unload(to);
    return to;
  }

  public boolean isValidAbscissaUnit(String unit)
  {
    if(TimeUnit.validUnit(unit))
      return true;
    if(VolumeUnit.validUnit(unit))
      return true;
    return false;
  }
  
  public boolean isValidOrdinateUnit(String unit)
  {
    return TimeUnit.validUnit(unit);
  }
  
  public String getVolumeUnit()
  {
    return this.abscissaUnit;
  }
  
  public String getTimeUnit()
  {
    return this.ordinateUnit;
  }

  public double[] getVolume(String unit)
  {
    if(!isValidAbscissaUnit(unit))
      throw new InvalidUnitException(unit, "Volume");
    return getAbscissa(unit);
  }
  
  public String getVolumeString(String unit)
  {
    if(!isValidAbscissaUnit(unit))
      throw new InvalidUnitException(unit, "Volume");
    return getAbscissaString(unit);
  }
  
  public void setVolume(double[] data, String unit)
  {
    if(!isValidAbscissaUnit(unit))
      throw new InvalidUnitException(unit, "Volume");
    setAbscissa(data, unit);
  }
  
  public void setVolume(String data, String unit)
  {
    if(!isValidAbscissaUnit(unit))
      throw new InvalidUnitException(unit, "Volume");
    setAbscissa(data, unit);
  }
  
  /**
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public double[] getVolume(VolumeUnit unit)
  {
    return getAbscissa(unit.toString());
  }
  
  /**
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public String getVolumeString(VolumeUnit unit)
  {
    return getAbscissaString(unit.toString());
  }
  
  /**
   * @param data
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public void setVolume(double[] data, VolumeUnit unit)
  {
    setAbscissa(data, unit.toString());
  }
  
  /**
   * @param data
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public void setVolume(String data, VolumeUnit unit)
  {
    setAbscissa(data, unit.toString());
  }
  
  public double[] getTime(String unit)
  {
    if(!isValidOrdinateUnit(unit))
      throw new InvalidUnitException(unit, "Time");
    return getOrdinate(unit);
  }
  
  public String getTimeString(String unit)
  {
    if(!isValidOrdinateUnit(unit))
      throw new InvalidUnitException(unit, "Time");
    return getOrdinateString(unit);
  }
  
  public void setTime(double[] data, String unit)
  {
    if(!isValidOrdinateUnit(unit))
      throw new InvalidUnitException(unit, "Time");
    setOrdinate(data, unit);
  }
  
  public void setTime(String data, String unit)
  {
    if(!isValidOrdinateUnit(unit))
      throw new InvalidUnitException(unit, "Time");
    setOrdinate(data, unit);
  }
  
  /**
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public double[] getTime(TimeUnit unit)
  {
    return getOrdinate(unit.toString());
  }
  
  /**
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public String getTimeString(TimeUnit unit)
  {
    return getOrdinateString(unit.toString());
  }
  
  /**
   * @param data
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public void setTime(double[] data, TimeUnit unit)
  {
    setOrdinate(data, unit.toString());
  }
  
  /**
   * @param data
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention to set units as a String
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public void setTime(String data, TimeUnit unit)
  {
    setOrdinate(data, unit.toString());
  }
}
