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
 *  COPYRIGHT (C) 2005, APPLIED RESEARCH ASSOCIATES, INC., ALL RIGHTS RESERVED.
 */
package mil.tatrc.physiology.datamodel.properties;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.ScalarVolumePerTimePerMassData;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.VolumePerTimePerMassUnit;

/**
 * @author abray
 * VolumePerTimePerMass Scalar Class, will enVolumePerTimePerMass that units are proper to VolumePerTimePerMasss
 */

public class SEScalarVolumePerTimePerMass extends SEScalar
{
  public SEScalarVolumePerTimePerMass()
  {
    super();
  }
  
  /**
   * @param value
   * @param unit - specific any valid standard unit abbreviation
   * http://www.bipm.org/en/si/ for this quantity type
   */
  public SEScalarVolumePerTimePerMass(double value, String unit)
  {
  	this();
  	this.setValue(value, unit);
  }
  
  /**
   * @param value
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention:(double,string)
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public SEScalarVolumePerTimePerMass(double value, VolumePerTimePerMassUnit unit)
  {
    this();
    this.setValue(value,unit);
  }
  
  /**
   * @param value
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention:(double,string)
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public void setValue(double value, VolumePerTimePerMassUnit unit)
  {
    this.setValue(value,unit.toString());
  }
  
  /**
   * @param value
   * @param unit - enumeration of commonly used units for this type
   * Units are not limited to this set.
   * You can use the other method convention:(double,string)
   * and specify any valid standard unit abbreviation sting for this type
   * Unit Abbreviation Standards: http://www.bipm.org/en/si/
   */
  public double getValue(VolumePerTimePerMassUnit unit)
  {
    return this.getValue(unit.toString());
  }
  
  

  public ScalarVolumePerTimePerMassData unload()
  {
    if(!this.isValid())
      return null;

    ScalarVolumePerTimePerMassData to = CDMSerializer.objFactory.createScalarVolumePerTimePerMassData();
    unload(to);
    return to;
  }

  public boolean validUnit(String unit)
  {
    if(VolumePerTimePerMassUnit.validUnit(unit))
      return true;
    return false;
  }
}
