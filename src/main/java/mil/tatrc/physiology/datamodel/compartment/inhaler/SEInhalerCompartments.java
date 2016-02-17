package mil.tatrc.physiology.datamodel.compartment.inhaler;

import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.InhalerCompartmentsData;
import mil.tatrc.physiology.datamodel.bind.EnumInhaler;
import mil.tatrc.physiology.datamodel.compartment.SECompartment;
import mil.tatrc.physiology.datamodel.compartment.SEGasCompartment;

public class SEInhalerCompartments
{
  protected Map<EnumInhaler,SEGasCompartment<EnumInhaler>> cmpts = new HashMap<EnumInhaler,SEGasCompartment<EnumInhaler>>();
  
  public void clear()
  {
    cmpts.clear();
  }
  
  public void reset()
  {
    for(SECompartment<EnumInhaler> cmpt : cmpts.values())
      cmpt.reset();
  }

  public boolean load(InhalerCompartmentsData in)
  {
    return false;// Not implemented yet
  }
  public InhalerCompartmentsData unload()
  {
    InhalerCompartmentsData to = CDMSerializer.objFactory.createInhalerCompartmentsData();
    unload(to);
    return to;
  }
  protected void unload(InhalerCompartmentsData to)
  {
    // Not implemented yet
  }
  
  public boolean HasCompartment(EnumInhaler component)
  {
    return cmpts.containsKey(component);
  }
  public SEGasCompartment<EnumInhaler> GetCompartment(EnumInhaler component)
  {
    SEGasCompartment<EnumInhaler> cmpt = cmpts.get(component);
    if(cmpt==null)
    {
      cmpt = new SEGasCompartment<EnumInhaler>();
      cmpts.put(component, cmpt);
    }
    return cmpt;
  }
}
