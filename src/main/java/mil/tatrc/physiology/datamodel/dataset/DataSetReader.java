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

package mil.tatrc.physiology.datamodel.dataset;

import java.io.File;
import java.io.FileInputStream;
import java.util.*;

import org.apache.poi.ss.usermodel.FormulaEvaluator;
import org.apache.poi.xssf.usermodel.XSSFCell;
import org.apache.poi.xssf.usermodel.XSSFRow;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.substance.SESubstanceAnatomyEffect;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.engine.PhysiologyEngineDynamicStabilization;
import mil.tatrc.physiology.datamodel.engine.PhysiologyEngineStabilization;
import mil.tatrc.physiology.datamodel.engine.PhysiologyEngineTimedStabilization;
import mil.tatrc.physiology.datamodel.system.environment.SEEnvironmentalConditions;
import mil.tatrc.physiology.datamodel.patient.*;
import mil.tatrc.physiology.datamodel.patient.nutrition.SENutrition;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;
import mil.tatrc.physiology.datamodel.substance.*;
import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;

public class DataSetReader
{
  private static final String DEFAULT_DIRECTORY = "../data/";
  private static final String DEFAULT_FILE = "BioGears.xlsx";
  private static  FormulaEvaluator evaluator;

  public static void main(String[] args)
  {
    if(args.length<2)
    {
      loadData();
    }
    else
    {
      loadData(args[0], args[1]);
    }
  }

  public static void loadData()
  {
    loadData(DEFAULT_DIRECTORY, DEFAULT_FILE);
  }

  public static void loadData(String directoryName, String fileName)
  {
    try
    {
      // Delete current dir contents
      FileUtils.delete(new File("./substances/"));
      FileUtils.delete(new File("./patients/"));
      FileUtils.delete(new File("./environments/"));
      FileUtils.delete(new File("./nutrition/"));
      FileUtils.delete(new File("./config/"));
      // Ok, let's make them again
      FileUtils.createDirectory("./substances/");
      FileUtils.createDirectory("./patients/");
      FileUtils.createDirectory("./environments/");
      FileUtils.createDirectory("./nutrition/");
      FileUtils.createDirectory("./config/");
    }
    catch(Exception ex)
    {
      Log.error("Unable to clean directories");
      return;
    }
    try
    {   
      File xls = new File(directoryName+"/"+fileName);
      if(!xls.exists())
      {
        Log.error("Could not find xls file "+directoryName+"/"+fileName);
        return;
      }
      FileInputStream xlFile = new FileInputStream(directoryName+"/"+fileName);		
      XSSFWorkbook xlWBook =  new XSSFWorkbook (xlFile);
      evaluator = xlWBook.getCreationHelper().createFormulaEvaluator();

      List<SEPatient> patients = readPatients(xlWBook.getSheet("Patients"));
      for(SEPatient p : patients)
      {
        Log.info("Writing patient : "+p.getName());
        CDMSerializer.writeFile("./patients/"+p.getName()+".xml", p.unload());
      }
      Map<String,SESubstance> substances=readSubstances(xlWBook.getSheet("Substances"));
      for(SESubstance s : substances.values())	
      {
        Log.info("Writing substance : "+s.getName());
        CDMSerializer.writeFile("./substances/"+s.getName()+".xml", s.unload());
      }
      List<SESubstanceCompound> compounds = readCompounds(xlWBook.getSheet("Compounds"), substances);
      for(SESubstanceCompound c : compounds)
      {
        Log.info("Writing compound : "+c.getName());
        CDMSerializer.writeFile("./substances/"+c.getName()+".xml", c.unload());    	
      }
      Map<String,SEEnvironmentalConditions> environments = readEnvironments(xlWBook.getSheet("Environment"), substances);
      for(String name : environments.keySet())
      {
        Log.info("Writing environment : "+name);
        environments.get(name).trim();//Removes zero amount ambient substances
        CDMSerializer.writeFile("./environments/"+name+".xml", environments.get(name).unload());
      }
      Map<String,SENutrition> meals = readNutrition(xlWBook.getSheet("Nutrition"));
      for(String name : meals.keySet())
      {
        Log.info("Writing nutrition : "+name);
        CDMSerializer.writeFile("./nutrition/"+name+".xml", meals.get(name).unload());
      }
      Map<String,PhysiologyEngineStabilization> stabilization = readStabilization(xlWBook.getSheet("Stabilization"));
      for(String name : stabilization.keySet())
      {
        Log.info("Writing stabilization : "+name);
        CDMSerializer.writeFile("./config/"+name+".xml", stabilization.get(name).unload());
      }
      xlWBook.close();
    }
    catch(Exception ex)
    {
      Log.error("Error reading XSSF : "+directoryName+"/"+fileName,ex);
      return;
    }
  }

  protected static List<SEPatient> readPatients(XSSFSheet xlSheet)
  {
    String property,value,unit;
    List<SEPatient> patients = new ArrayList<SEPatient>();
    try
    {
      int rows = xlSheet.getPhysicalNumberOfRows();		  
      for (int r = 0; r < rows; r++) 
      {
        XSSFRow row = xlSheet.getRow(r);
        if (row == null) 
          continue;
        int cells = row.getPhysicalNumberOfCells();
        if(r==0)
        {// Allocate the number of patients we have
          for(int i=1;i<cells;i++)
            patients.add(new SEPatient());
        }
        property = row.getCell(0).getStringCellValue();
        if(property==null||property.isEmpty())
          continue;
        Log.info("Processing Patient Field : "+property);
        for (int c = 1; c < cells; c++) 
        {
          String cellValue=null;
          XSSFCell cell = row.getCell(c);
          switch(cell.getCellType())
          {
            case XSSFCell.CELL_TYPE_NUMERIC:
              cellValue = Double.toString(cell.getNumericCellValue());
              break;
            case XSSFCell.CELL_TYPE_STRING:
              cellValue = cell.getStringCellValue();
              break;
          }
          if(cellValue==null||cellValue.isEmpty())
            continue;
          int split = cellValue.indexOf(" ");
          // Pull The Value
          if(split==-1)
          {
            value=cellValue;
            unit="";
          }
          else
          {
            value = cellValue.substring(0,split);
            unit  = cellValue.substring(split+1);
          }
          if(value.equals("INF"))
            value = "Infinity";
          if(!setProperty(patients.get(c-1),property,value,unit))
          {
            Log.error("Error pulling"+property+" from "+cellValue);
            break;
          }
        }
      }
    }
    catch(Exception ex)
    {
      Log.error("Error reading XLS",ex);
      return null;
    }
    return patients;
  }

  protected static boolean setProperty(SEPatient patient,
      String property,
      String value,
      String unit)
  {
    if(property.equals("Name"))
    {  		
      patient.setName(value);
      return true;
    }
    if(property.equals("Gender"))
    {
      patient.setGender(EnumGender.fromValue(value));
      return true;
    }
    if(property.equals("Age"))
    {
      patient.getAge().setValue(Double.parseDouble(value),unit);
      return true;
    }  	
    if(property.equals("Weight"))
    {
      patient.getWeight().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("Height"))
    {
      patient.getHeight().setValue(Double.parseDouble(value),unit);
      return true;
    }

    if(property.equals("BasalMetabolicRate"))
    {
      patient.getBasalMetabolicRate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("BodyFatFraction"))
    {
      patient.getBodyFatFraction().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("CarinaToTeethDistance"))
    {
      patient.getCarinaToTeethDistance().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("CentralControllerCO2PressureSetPoint"))
    {
      patient.getCentralControllerCO2PressureSetPoint().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("DiastolicArterialPressureBaseline"))
    {
      patient.getDiastolicArterialPressureBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("ExpiratoryReserveVolume"))
    {
      patient.getExpiratoryReserveVolume().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("FunctionalResidualCapacity"))
    {
      patient.getFunctionalResidualCapacity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("HeartRateBaseline"))
    {
      if(unit.equals("bpm"))
        unit = "1/min";
      patient.getHeartRateBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("HeartRateMaximum"))
    {
      if(unit.equals("bpm"))
        unit = "1/min";
      patient.getHeartRateMaximum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("HeartRateMinimum"))
    {
      if(unit.equals("bpm"))
        unit = "1/min";
      patient.getHeartRateMinimum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("InspiratoryCapacity"))
    {
      patient.getInspiratoryCapacity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("InspiratoryReserveVolume"))
    {
      patient.getInspiratoryReserveVolume().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("LeftHeartElastanceMaximum"))
    {
      patient.getLeftHeartElastanceMaximum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("LeftHeartElastanceMinimum"))
    {
      patient.getLeftHeartElastanceMinimum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("MeanArterialPressureBaseline"))
    {
      patient.getMeanArterialPressureBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("PeripheralControllerCO2PressureSetPoint"))
    {
      patient.getPeripheralControllerCO2PressureSetPoint().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("PulmonaryVentilationRateMaximum"))
    {
      patient.getPulmonaryVentilationRateMaximum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("ResidualVolume"))
    {
      patient.getResidualVolume().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RespirationRateBaseline"))
    {
      if(unit.equals("bpm"))
        unit = "1/min";
      patient.getRespirationRateBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RightHeartElastanceMaximum"))
    {
      patient.getRightHeartElastanceMaximum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RightHeartElastanceMinimum"))
    {
      patient.getRightHeartElastanceMinimum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RightLungRatio"))
    {
      patient.getRightLungRatio().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("SkinSurfaceArea"))
    {
      patient.getSkinSurfaceArea().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("SystolicArterialPressureBaseline"))
    {
      patient.getSystolicArterialPressureBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("TidalVolumeBaseline"))
    {
      patient.getTidalVolumeBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("TotalBloodVolumeBaseline"))
    {
      patient.getTotalBloodVolumeBaseline().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("TotalLungCapacity"))
    {
      patient.getTotalLungCapacity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("VitalCapacity"))
    {
      patient.getVitalCapacity().setValue(Double.parseDouble(value),unit);
      return true;
    }

    throw new RuntimeException("Not a valid patient property " + property);
  }

  protected static Map<String,SESubstance> readSubstances(XSSFSheet xlSheet)
  {
    EnumAnatomy currCmpt=null;
    String property,value,unit;
    SESubstance substance=null;
    SESubstanceAnatomyEffect afx=null;
    List<SESubstance> substances = new ArrayList<SESubstance>();
    Set<Integer> skipColumns = new HashSet<Integer>();
    
    try
    {
      int rows = xlSheet.getPhysicalNumberOfRows();		  
      for (int r = 0; r < rows; r++) 
      {
        XSSFRow row = xlSheet.getRow(r);
        if (row == null) 
          continue;
        int cells = row.getPhysicalNumberOfCells();
        if(r==0)
        {
          for (int c = 1; c < cells; c++) 
          {
            property = row.getCell(c).getStringCellValue().trim();
            if(property.equals("Reference Value")||property.equals("Reference Source")||property.equals("Notes/Page"))
              skipColumns.add(c);
          }
        }        
        property = row.getCell(0).getStringCellValue().trim();
        if(property==null||property.isEmpty())
          continue;
        Log.info("Processing Substance Field : "+property);
        if(property.indexOf("Compartment Effects")>-1)
        {
          if(property.indexOf("Myocardium")>-1)
            currCmpt=EnumAnatomy.MYOCARDIUM;
          else if(property.indexOf("Fat")>-1)
            currCmpt=EnumAnatomy.FAT;
          else if(property.indexOf("Kidneys")>-1)
            currCmpt=EnumAnatomy.KIDNEYS;
          else if(property.indexOf("Brain")>-1)
            currCmpt=EnumAnatomy.BRAIN;
          else if(property.indexOf("Muscle")>-1)
            currCmpt=EnumAnatomy.MUSCLE;
          else if(property.indexOf("Skin")>-1)
            currCmpt=EnumAnatomy.SKIN;
          else if(property.indexOf("Bone")>-1)
            currCmpt=EnumAnatomy.BONE;
          else if(property.indexOf("Gut")>-1)
            currCmpt=EnumAnatomy.GUT;
          else if(property.indexOf("Splanchnic")>-1)
            currCmpt=EnumAnatomy.SPLANCHNIC;
          else if(property.indexOf("Spleen")>-1)
            currCmpt=EnumAnatomy.SPLEEN;
          else if(property.indexOf("Large Intestine")>-1)
            currCmpt=EnumAnatomy.LARGE_INTESTINE;
          else if(property.indexOf("Small Intestine")>-1)
            currCmpt=EnumAnatomy.SMALL_INTESTINE;
          else if(property.indexOf("Liver")>-1)
            currCmpt=EnumAnatomy.LIVER;
          else if(property.indexOf("Right Lung")>-1)
            currCmpt=EnumAnatomy.RIGHT_LUNG;
          else if(property.indexOf("Left Lung")>-1)
            currCmpt=EnumAnatomy.LEFT_LUNG;
          else
          {
            Log.error("Unsupported Anatomy Compartment : "+property);
            break;
          }					
        }
        int s=-1;
        for (int c = 1; c < cells; c++) 
        {
          if(skipColumns.contains(c))
            continue;
          s++;
          String cellValue=null;
          XSSFCell cell = row.getCell(c);
          switch(cell.getCellType())
          {
            case XSSFCell.CELL_TYPE_NUMERIC:
              cellValue = Double.toString(cell.getNumericCellValue());
              break;
            case XSSFCell.CELL_TYPE_STRING:
              cellValue = cell.getStringCellValue();
              break;
            case XSSFCell.CELL_TYPE_FORMULA:
              switch(evaluator.evaluateFormulaCell(cell))
              {
                case XSSFCell.CELL_TYPE_NUMERIC:
                  cellValue = Double.toString(cell.getNumericCellValue());
                  break;
                case XSSFCell.CELL_TYPE_STRING:
                  cellValue = cell.getStringCellValue();
                  break;
              }               
          }
          if(cellValue==null)
            continue;
          cellValue=cellValue.trim();
          if(cellValue.isEmpty())
            continue;
          if(property.equals("Name"))
          {
            substance = new SESubstance();
            substances.add(substance);
          }

          int split = cellValue.indexOf(" ");
          // Pull The Value
          if(split==-1)
          {
            value=cellValue;
            unit="";
          }
          else
          {
            value = cellValue.substring(0,split);
            unit  = cellValue.substring(split+1);
          }
          if(value.equals("INF"))
            value = "Infinity";
          substance=substances.get(c-(3*s)-1);

          if(currCmpt==null)
            afx=null;
          else
            afx=substance.getAnatomyEffect(currCmpt);							
          if(!setProperty(substance,afx,property,value,unit))
          {
            Log.error("Error pulling"+property+" from "+cellValue);
            break;
          }
        }
      }
    }
    catch(Exception ex)
    {
      Log.error("Error reading XLS",ex);
      return null;
    }		
    Map<String,SESubstance> map = new HashMap<String,SESubstance>();
    for(SESubstance sub : substances)
      map.put(sub.getName(), sub);
    return map;
  }

  protected static boolean setProperty(SESubstance substance,
      SESubstanceCompartmentEffect fx,
      String property,
      String value,
      String unit)
  {
    if(property.equals("Name"))
    {
      substance.setName(value);
      return true;
    }
    if(property.equals("State"))
    {
      substance.setState(EnumSubstanceState.fromValue(value));
      return true;
    }
    if(property.equals("Density"))
    {
      substance.getDensity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("MolarMass"))
    {
      substance.getMolarMass().setValue(Double.parseDouble(value),unit);
      return true;
    }
    // Liquid-ish
    // Aerosolization
    if(property.equals("DropletDensity"))
    {
      substance.getAerosolization().getDropletDensity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("DropletDiameter"))
    {
      substance.getAerosolization().getDropletDiameter().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("MassInBody"))
    {
      substance.getMassInBody().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("PlasmaConcentration"))
    {
      substance.getPlasmaConcentration().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RemainingSystemicMassCleared"))
    {
      substance.getRemainingSystemicMassCleared().setValue(Double.parseDouble(value),unit);
      return true;
    }
    
    // Gas-ish
    if(property.equals("AlveolarTransfer"))
    {
      substance.getAlveolarTransfer().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("DiffusingCapacity"))
    {
      substance.getDiffusingCapacity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("EndTidalConcentration"))
    {
      substance.getEndTidalConcentration().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RelativeDiffusionCoefficient"))
    {
      substance.getRelativeDiffusionCoefficient().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("SolubilityCoefficient"))
    {
      substance.getSolubilityCoefficient().setValue(Double.parseDouble(value),unit);
      return true;
    }
    
    // Clearance
    if(property.equals("FractionExcretedInFeces"))
    {
      substance.getClearance().getFractionExcretedInFeces().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("FractionExcretedInUrine"))
    {
      substance.getClearance().getFractionExcretedInUrine().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("FractionMetabolizedInGut"))
    {
      substance.getClearance().getFractionMetabolizedInGut().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("IntrinsicClearance"))
    {
      substance.getClearance().getIntrinsicClearance().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("FractionUnboundInPlasma"))
    {
      double d = Double.parseDouble(value);
      if(substance.hasPK() && substance.getPK().hasFractionUnboundInPlasma() && substance.getPK().getFractionUnboundInPlasma().getValue()!=d)
      {
        Log.fatal("Different values for FractionUnboundInPlasma, values must be consistent");
        System.exit(1);
      }
      substance.getPK().getFractionUnboundInPlasma().setValue(Double.parseDouble(value),unit);
      
      if(substance.hasClearance() && substance.getClearance().hasFractionUnboundInPlasma() && substance.getClearance().getFractionUnboundInPlasma().getValue()!=d)
      {
        Log.fatal("Different values for FractionUnboundInPlasma, values must be consistent");
        System.exit(1);
      }
      substance.getClearance().getFractionUnboundInPlasma().setValue(Double.parseDouble(value),unit);
      return true; 
    }
    // Renal Dynamics
    if(property.equals("Clearance")||property.equals("RenalClearance"))
    {
      double d = Double.parseDouble(value);
      if(substance.hasClearance() && substance.getClearance().hasRenalClearance() && substance.getClearance().getRenalClearance().getValue(unit)!=d)
      {
        Log.fatal("Different values for RenalClearance, values must be consistent");
        System.exit(1);
      }
      substance.getClearance().getRenalClearance().setValue(d,unit);
      return true;
    }
    if(property.equals("ChargeInBlood"))
    {
      substance.getClearance().setChargeInBlood(EnumCharge.fromValue(value));
      return true;
    }
    if(property.equals("ReabsorptionRatio"))
    {
      substance.getClearance().getRenalReabsorptionRatio().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("TransportMaximum"))
    {
      substance.getClearance().getRenalTransportMaximum().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("FiltrationRate"))
    {
      substance.getClearance().getRenalFiltrationRate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("ReabsorptionRate"))
    {
      substance.getClearance().getRenalReabsorptionRate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("ExcretionRate"))
    {
      substance.getClearance().getRenalExcretionRate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("GlomerularFilterability"))
    {
      substance.getClearance().getGlomerularFilterability().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("SystemicClearance"))
    {
      substance.getClearance().getSystemicClearance().setValue(Double.parseDouble(value),unit);
      return true;
    }
    
    // Pharmacokinetics
    if(property.equals("AcidDissociationConstant"))
    {
      substance.getPK().getAcidDissociationConstant().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("BindingProtein"))
    {
      substance.getPK().setBindingProtein(EnumSubstanceBindingProtein.fromValue(value));
      return true;
    }
    if(property.equals("BloodPlasmaRatio"))
    {
      substance.getPK().getBloodPlasmaRatio().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("IonicState"))
    {
      substance.getPK().setIonicState(EnumSubstanceIonicState.fromValue(value));
      return true;
    }
    if(property.equals("LogP"))
    {
      substance.getPK().getLogP().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("OralAbsorptionRateConstant"))
    {
      substance.getPK().getOralAbsorptionRateConstant().setValue(Double.parseDouble(value),unit);
      return true;
    }
    
    // Pharmacodynamics
    if(property.equals("Bronchodilation"))
    {
      substance.getPD().getBronchodilation().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("DiastolicPressureModifier"))
    {
      substance.getPD().getDiastolicPressureModifier().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("EC50"))
    {
      substance.getPD().getEC50().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("HeartRateModifier"))
    {
      substance.getPD().getHeartRateModifier().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("NeuromuscularBlock"))
    {
      substance.getPD().getNeuromuscularBlock().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("PupilState"))
    {
      substance.getPD().setPupilState(EnumPupilState.fromValue(value));
      return true;
    }
    if(property.equals("RespirationRateModifier"))
    {
      substance.getPD().getRespirationRateModifier().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("Sedation"))
    {
      substance.getPD().getSedation().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("SystolicPressureModifier"))
    {
      substance.getPD().getSystolicPressureModifier().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("TidalVolumeModifier"))
    {
      substance.getPD().getTidalVolumeModifier().setValue(Double.parseDouble(value),unit);
      return true;
    }
    
   
    // Compartment Effects
    if(property.equals("MassCleared"))
    {
      fx.getMassCleared().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("PartitionCoefficient"))
    {
      fx.getPartitionCoefficient().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("PermeabilitySurfaceAreaProduct"))
    {
      fx.getPermeabilitySurfaceAreaProduct().setValue(Double.parseDouble(value),unit);
      return true;
    }
    
    throw new RuntimeException("Not a valid substance property " + property);
  }

  protected static List<SESubstanceCompound> readCompounds(XSSFSheet xlSheet, Map<String,SESubstance> substances)
  {
    String property,value,unit;
    SESubstance s;
    SESubstanceCompound compound=null;
    SESubstanceCompoundComponent component=null;		
    List<SESubstanceCompound> compounds = new ArrayList<SESubstanceCompound>();
    try
    {
      int rows = xlSheet.getPhysicalNumberOfRows();		  
      for (int r = 0; r < rows; r++) 
      {
        XSSFRow row = xlSheet.getRow(r);
        if (row == null) 
          continue;
        int cells = row.getPhysicalNumberOfCells();
        if(r==0)
        {// Allocate the number of patients we have
          for(int i=1;i<cells;i++)
            compounds.add(new SESubstanceCompound());
        }
        property = row.getCell(0).getStringCellValue();
        if(property==null||property.isEmpty())
          continue;
        Log.info("Processing Patient Field : "+property);
        if(property.equals("Data Type"))
          continue;// Only one type at this point
        for (int c = 1; c < cells; c++) 
        {
          String cellValue=null;
          XSSFCell cell = row.getCell(c);
          switch(cell.getCellType())
          {
            case XSSFCell.CELL_TYPE_NUMERIC:
              cellValue = Double.toString(cell.getNumericCellValue());
              break;
            case XSSFCell.CELL_TYPE_STRING:
              cellValue = cell.getStringCellValue();
              break;
          }
          if(cellValue==null||cellValue.isEmpty())
            continue;
          int split = cellValue.indexOf(" ");
          // Pull The Value
          if(split==-1)
          {
            value=cellValue;
            unit="";
          }
          else
          {
            value = cellValue.substring(0,split);
            unit  = cellValue.substring(split+1);
          }
          compound=compounds.get(c-1);
          if(property.equals("Compound Name"))
          {
            compound.setName(value);
            continue;
          }
          if(property.equals("Component Name"))
          {
            s = substances.get(value);
            component = compound.getComponent(s);
            continue;
          }
          if(!setProperty(component,property,value,unit))
          {
            Log.error("Error setting property");
            break;
          }
        }
      }
    }
    catch(Exception ex)
    {
      Log.error("Error reading XLS",ex);
      return null;
    }
    return compounds;			
  }

  protected static boolean setProperty(SESubstanceCompoundComponent component,
      String property,
      String value,
      String unit)
  {
    if(property.equals("Concentration"))
    {
      component.getConcentration().setValue(Double.parseDouble(value),unit);
      return true;
    }
    throw new RuntimeException("Not a valid compound component property " + property);
  }

  protected static Map<String,SEEnvironmentalConditions> readEnvironments(XSSFSheet xlSheet, Map<String,SESubstance> substances)
  {
    String property,value,unit;
    SESubstance substance=null;
    SEEnvironmentalConditions environment;
    SESubstanceFraction subFrac=null;
    Map<String,SEEnvironmentalConditions> map = new HashMap<String,SEEnvironmentalConditions>();		
    List<SEEnvironmentalConditions> environments = new ArrayList<SEEnvironmentalConditions>();
    try
    {
      int rows = xlSheet.getPhysicalNumberOfRows();		  
      for (int r = 0; r < rows; r++) 
      {
        XSSFRow row = xlSheet.getRow(r);
        if (row == null) 
          continue;
        int cells = row.getPhysicalNumberOfCells();
        if(r==0)
        {// Allocate the number of environments we have
          for(int i=1;i<cells;i++)
            environments.add(new SEEnvironmentalConditions());
        }
        property = row.getCell(0).getStringCellValue();
        if(property==null||property.isEmpty())
          continue;
        if(property.equals("AmbientSubstanceData"))
          continue;
        Log.info("Processing Environment Field : "+property);
        for (int c = 1; c < cells; c++) 
        {
          String cellValue=null;
          XSSFCell cell = row.getCell(c);
          switch(cell.getCellType())
          {
            case XSSFCell.CELL_TYPE_NUMERIC:
              cellValue = Double.toString(cell.getNumericCellValue());
              break;
            case XSSFCell.CELL_TYPE_STRING:
              cellValue = cell.getStringCellValue();
              break;
          }
          if(cellValue==null||cellValue.isEmpty())
            continue;
          int split = cellValue.indexOf(" ");
          // Pull The Value
          if(split==-1)
          {
            value=cellValue;
            unit="";
          }
          else
          {
            value = cellValue.substring(0,split);
            unit  = cellValue.substring(split+1);
          }
          environment = environments.get(c-1);
          if(property.equals("Name"))
          {
            map.put(cellValue, environment);
            continue;
          }
          if(property.equals("Substance"))
          {// NOTE THIS ASSUMES THAT A ROW IS ALL ASSOCIATED WITH THE SAME SUBSTANCE        	  
            substance = substances.get(value);
            continue;
          }
          if(substance==null)
            subFrac=null;
          else
            subFrac=environment.getAmbientSubstance(substance, null);
          if(!setProperty(environment,subFrac,property,value,unit))
          {
            Log.error("Error pulling"+property+" from "+cellValue);
            break;
          }
        }
      }
    }
    catch(Exception ex)
    {
      Log.error("Error reading XLS",ex);
      return null;
    }		
    return map;
  }

  protected static boolean setProperty(SEEnvironmentalConditions env, SESubstanceFraction subFrac,
      String property,
      String value,
      String unit)
  {

    if(property.equals("SurroundingType"))
    {
      env.setSurroundingType(EnumSurroundingType.fromValue(value));
      return true;
    }
    if(property.equals("AirDensity"))
    {
      env.getAirDensity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("AirVelocity"))
    {
      env.getAirVelocity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("AmbientTemperature"))
    {

      env.getAmbientTemperature().setValue(Double.parseDouble(value),covTempUnit(unit));
      return true;
    }
    if(property.equals("AtmosphericPressure"))
    {
      env.getAtmosphericPressure().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("ClothingResistance"))
    {
      env.getClothingResistance().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("Emissivity"))
    {
      env.getEmissivity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("MeanRadiantTemperature"))
    {
      env.getMeanRadiantTemperature().setValue(Double.parseDouble(value),covTempUnit(unit));
      return true;
    }
    if(property.equals("RelativeHumidity"))
    {
      env.getRelativeHumidity().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("RespirationAmbientTemperature"))
    {
      env.getRespirationAmbientTemperature().setValue(Double.parseDouble(value),covTempUnit(unit));
      return true;
    }		
    // Substance Fraction
    if(property.equals("FractionAmount"))
    {
      subFrac.getFractionAmount().setValue(Double.parseDouble(value),unit);
      return true;
    }
    throw new RuntimeException("Not a valid environment property " + property);
  }

  protected static Map<String,SENutrition> readNutrition(XSSFSheet xlSheet)
  {
    String property,value,unit;
    SENutrition meal;
    Map<String,SENutrition> map = new HashMap<String,SENutrition>();		
    List<SENutrition> meals = new ArrayList<SENutrition>();
    try
    {
      int rows = xlSheet.getPhysicalNumberOfRows();		  
      for (int r = 0; r < rows; r++) 
      {
        XSSFRow row = xlSheet.getRow(r);
        if (row == null) 
          continue;
        int cells = row.getPhysicalNumberOfCells();
        if(r==0)
        {// Allocate the number of environments we have
          for(int i=1;i<cells;i++)
            meals.add(new SENutrition());
        }
        property = row.getCell(0).getStringCellValue();
        if(property==null||property.isEmpty())
          continue;
        Log.info("Processing Nutrition Field : "+property);
        for (int c = 1; c < cells; c++) 
        {
          String cellValue=null;
          XSSFCell cell = row.getCell(c);
          switch(cell.getCellType())
          {
            case XSSFCell.CELL_TYPE_NUMERIC:
              cellValue = Double.toString(cell.getNumericCellValue());
              break;
            case XSSFCell.CELL_TYPE_STRING:
              cellValue = cell.getStringCellValue();
              break;
          }
          if(cellValue==null||cellValue.isEmpty())
            continue;
          int split = cellValue.indexOf(" ");
          // Pull The Value
          if(split==-1)
          {
            value=cellValue;
            unit="";
          }
          else
          {
            value = cellValue.substring(0,split);
            unit  = cellValue.substring(split+1);
          }
          meal = meals.get(c-1);
          if(property.equals("Name"))
          {
            map.put(cellValue, meal);
            continue;
          }					
          if(!setProperty(meal,property,value,unit))
          {
            Log.error("Error pulling"+property+" from "+cellValue);
            break;
          }
        }
      }
    }
    catch(Exception ex)
    {
      Log.error("Error reading XLS",ex);
      return null;
    }		
    return map;
  }

  protected static boolean setProperty(SENutrition meal,
      String property,
      String value,
      String unit)
  {
    if(property.equals("Carbohydrate"))
    {
      meal.getCarbohydrate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("CarbohydrateDigestionRate"))
    {
      meal.getCarbohydrateDigestionRate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("Fat"))
    {
      meal.getFat().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("FatDigestionRate"))
    {
      meal.getFatDigestionRate().setValue(Double.parseDouble(value),unit);
      return true;
    }
    if(property.equals("Protein"))
    {

      meal.getProtein().setValue(Double.parseDouble(value),covTempUnit(unit));
      return true;
    }
    if(property.equals("ProteinDigestionRate"))
    {
      meal.getProteinDigestionRate().setValue(Double.parseDouble(value),covTempUnit(unit));
      return true;
    }
    if(property.equals("Sodium"))
    {
      meal.getSodium().setValue(Double.parseDouble(value),unit);
      return true;
    }    
    if(property.equals("Calcium"))
    {
      meal.getCalcium().setValue(Double.parseDouble(value),unit);
      return true;
    }  
    if(property.equals("Water"))
    {
      meal.getWater().setValue(Double.parseDouble(value),unit);
      return true;
    }		   
    throw new RuntimeException("Not a valid environment property " + property);
  }

  protected static Map<String,PhysiologyEngineStabilization> readStabilization(XSSFSheet xlSheet)
  {
    int split;
    // Fields are expected data we must have
    Set<String> fields = new HashSet<String>();
    fields.add("Criteria");
    fields.add("ConvergenceTime");
    fields.add("MinimumReactionTime");
    fields.add("MinimumReactionTime");
    fields.add("MaxAllowedStabilizationTime");
    fields.add("TimedStabilizationLength");
    String property,value,unit,cellValue;
    PhysiologyEngineTimedStabilization timed = new PhysiologyEngineTimedStabilization();
    PhysiologyEngineDynamicStabilization dynamic = new PhysiologyEngineDynamicStabilization();
    Map<String,PhysiologyEngineStabilization> map = new HashMap<String,PhysiologyEngineStabilization>();
    map.put("TimedStabilization",timed);
    map.put("DynamicStabilization",dynamic);
    SEScalarTime time=null;
    PhysiologyEngineDynamicStabilization.Criteria criteria=null;
    try
    {
      int rows = xlSheet.getPhysicalNumberOfRows();     
      for (int r = 0; r < rows; r++) 
      {
        XSSFRow row = xlSheet.getRow(r);
        if (row == null) 
          continue;
        property = row.getCell(0).getStringCellValue();
        if(property==null||property.isEmpty())
          continue;
        if(!fields.contains(property))
        {
          if(property.equals("Resting"))
          {
            criteria=dynamic.getRestingStabilizationCriteria();
            time=timed.getRestingStabilizationTime();
          }
          else if(property.equals("Feedback"))
          {
            criteria=dynamic.getFeedbackStabilizationCriteria();
            time=timed.getFeedbackStabilizationTime();
          }
          else
          {
            criteria=dynamic.createCondition(property);
            time=timed.createCondition(property);
          }
          continue;
        }         
        else if(property.equals("Criteria"))
        {
          criteria.createProperty(row.getCell(1).getNumericCellValue(),row.getCell(2).getStringCellValue());
        }
        else if(property.equals("ConvergenceTime"))
        {
          cellValue = row.getCell(1).getStringCellValue();
          split = cellValue.indexOf(" ");           
          value = cellValue.substring(0,split);
          unit  = cellValue.substring(split+1);        
          criteria.convergenceTime.setValue(Double.parseDouble(value),unit);
        }
        else if(property.equals("MinimumReactionTime"))
        {
          cellValue = row.getCell(1).getStringCellValue();
          split = cellValue.indexOf(" ");           
          value = cellValue.substring(0,split);
          unit  = cellValue.substring(split+1);        
          criteria.minimumReactionTime.setValue(Double.parseDouble(value),unit);
        }
        else if(property.equals("MaxAllowedStabilizationTime"))
        {
          cellValue = row.getCell(1).getStringCellValue();
          split = cellValue.indexOf(" ");           
          value = cellValue.substring(0,split);
          unit  = cellValue.substring(split+1);        
          criteria.maximumAllowedStabilizationTime.setValue(Double.parseDouble(value),unit);
        }
        else if(property.equals("TimedStabilizationLength"))
        {
          cellValue = row.getCell(1).getStringCellValue();
          split = cellValue.indexOf(" ");           
          value = cellValue.substring(0,split);
          unit  = cellValue.substring(split+1);        
          time.setValue(Double.parseDouble(value),unit);
        }
      }
    }
    catch(Exception ex)
    {
      Log.error("Error reading XLS",ex);
      return null;
    }   
    return map;
  }

  private static String covTempUnit(String unit)
  {
    if(unit.equals("C"))
      return "degC";
    if(unit.equals("F"))
      return "degF";
    if(unit.equals("R"))
      return "degR";
    return unit;
  }
}
