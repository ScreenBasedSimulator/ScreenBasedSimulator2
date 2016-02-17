package mil.tatrc.physiology.datamodel.compartment.anesthesia;

import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.AnesthesiaMachineCompartmentsData;
import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachine;
import mil.tatrc.physiology.datamodel.compartment.SECompartment;
import mil.tatrc.physiology.datamodel.compartment.SEGasCompartment;

public class SEAnesthesiaMachineCompartments
{
  protected Map<EnumAnesthesiaMachine,SEGasCompartment<EnumAnesthesiaMachine>> cmpts = new HashMap<EnumAnesthesiaMachine,SEGasCompartment<EnumAnesthesiaMachine>>();
  
  public void clear()
  {
    cmpts.clear();
  }
  
  public void reset()
  {
    for(SECompartment<EnumAnesthesiaMachine> cmpt : cmpts.values())
      cmpt.reset();
  }

  public boolean load(AnesthesiaMachineCompartmentsData in)
  {
    return false;// Not implemented yet
  }
  public AnesthesiaMachineCompartmentsData unload()
  {
    AnesthesiaMachineCompartmentsData to = CDMSerializer.objFactory.createAnesthesiaMachineCompartmentsData();
    unload(to);
    return to;
  }
  protected void unload(AnesthesiaMachineCompartmentsData to)
  {
    // Not implemented yet
  }
  
  public boolean HasCompartment(EnumAnesthesiaMachine component)
  {
    return cmpts.containsKey(component);
  }
  public SEGasCompartment<EnumAnesthesiaMachine> GetCompartment(EnumAnesthesiaMachine component)
  {
    SEGasCompartment<EnumAnesthesiaMachine> cmpt = cmpts.get(component);
    if(cmpt==null)
    {
      cmpt = new SEGasCompartment<EnumAnesthesiaMachine>();
      cmpts.put(component, cmpt);
    }
    return cmpt;
  }
}
