package mil.tatrc.physiology.biogears.validation;

import java.util.Arrays;

import mil.tatrc.physiology.utilities.Log;

public class SystemValidation extends ValdiationTool
{
  public SystemValidation()
  {
    DEST_DIRECTORY = "./validation/";
    DEFAULT_DIRECTORY = "../docs/validation/";
    DEFAULT_FILE = "SystemValidationData.xlsx";
    TABLE_TYPE = "System";
  }
  public static void main(String[] args)
  {
    Log.setFileName("ValidationTool.log");
    Log.info("Running with agrs : "+Arrays.toString(args));
    SystemValidation me = new SystemValidation();
    if(args.length!=3)
    {
      me.loadData("Local","MSVC","x86");
    }
    else
    {      
      me.loadData(args[0], args[1], args[2]);
    }
  }

}
