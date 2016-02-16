package mil.tatrc.physiology.biogears.validation;

import java.io.PrintWriter;
import java.util.Arrays;

import mil.tatrc.physiology.biogears.validation.ValdiationTool.ValidationRow;
import mil.tatrc.physiology.datamodel.patient.SEPatient;
import mil.tatrc.physiology.utilities.Log;

public class PatientValidation extends ValdiationTool
{
  public PatientValidation()
  {
    DEST_DIRECTORY = "./validation/";
    DEFAULT_DIRECTORY = "../docs/validation/";
    DEFAULT_FILE = "PatientValidationData.xlsx";
    TABLE_TYPE = "Patient";
    HEADER_PREPEND = "Patient";
  }
  public static void main(String[] args)
  {
    Log.setFileName("ValidationTool.log");
    Log.info("Running with agrs : "+Arrays.toString(args));
    PatientValidation me = new PatientValidation();
    if(args.length!=3)
    {
      me.loadData("Local","MSVC","x86");
    }
    else
    {      
      me.loadData(args[0], args[1], args[2]);
    }
  }
  
  public void CustomMarkdown(String sheetName, String destinationDirectory, Object o)
  {
    SEPatient p = null;
    if(o instanceof SEPatient)
      p = (SEPatient)o;
    if(p==null)
    {
      Log.error("CustomeMarkdown must provide an SEPatient");
      return;
    }
    
    PrintWriter writer=null;
    try
    {
      // Create file and start the table
      writer = new PrintWriter(destinationDirectory+"/"+sheetName+"Description.md", "UTF-8");
      
      writer.println("### "+p.getName());
      writer.println("|Property Name                |Value     ");
      writer.println("|---                          |---       ");
      writer.println("|Gender                       |"+patient.getGender().value());
      writer.println("|Age                          |"+patient.getAge());
      writer.println("|Weight                       |"+patient.getWeight());
      writer.println("|Height                       |"+patient.getHeight());
      writer.println("|BodyFatFraction              |"+patient.getBodyFatFraction());
      writer.println("|CarinaToTeethDistance        |"+patient.getCarinaToTeethDistance());
      writer.close();
    }
    catch(Exception ex)
    {
      Log.error("Error writing validation table for "+sheetName,ex);
      writer.close();
    }
  }

}
