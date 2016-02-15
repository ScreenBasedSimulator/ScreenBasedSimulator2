package mil.tatrc.physiology.datamodel.compartment.anatomy;

import java.util.*;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.*;
import mil.tatrc.physiology.datamodel.compartment.*;

public class SEAnatomyCompartments
{
  protected Map<EnumAnatomy,SELiquidCompartment<EnumAnatomy>>  chyme=new HashMap<EnumAnatomy,SELiquidCompartment<EnumAnatomy>>();
  protected Map<EnumAnatomy,SEGasCompartment<EnumAnatomy>>     pulmonary=new HashMap<EnumAnatomy,SEGasCompartment<EnumAnatomy>>();
  protected Map<EnumAnatomy,SEThermalCompartment<EnumAnatomy>> temperature=new HashMap<EnumAnatomy,SEThermalCompartment<EnumAnatomy>>();
  protected Map<EnumAnatomy,SETissueCompartment<EnumAnatomy>>  tissue=new HashMap<EnumAnatomy,SETissueCompartment<EnumAnatomy>>();
  protected Map<EnumAnatomy,SELiquidCompartment<EnumAnatomy>>  urine=new HashMap<EnumAnatomy,SELiquidCompartment<EnumAnatomy>>();
  protected Map<EnumAnatomy,SELiquidCompartment<EnumAnatomy>>  vascular=new HashMap<EnumAnatomy,SELiquidCompartment<EnumAnatomy>>();
  
  public void clear()
  {
    chyme.clear();
    pulmonary.clear();
    temperature.clear();
    tissue.clear();
    urine.clear();
    vascular.clear();
  }
  
  public void reset()
  {
    for(SECompartment<EnumAnatomy> cmpt : chyme.values())
      cmpt.reset();
    for(SECompartment<EnumAnatomy> cmpt : pulmonary.values())
      cmpt.reset();
    for(SECompartment<EnumAnatomy> cmpt : temperature.values())
      cmpt.reset();
    for(SECompartment<EnumAnatomy> cmpt : tissue.values())
      cmpt.reset();
    for(SECompartment<EnumAnatomy> cmpt : urine.values())
      cmpt.reset();
    for(SECompartment<EnumAnatomy> cmpt : vascular.values())
      cmpt.reset();
  }

  public boolean load(AnatomyCompartmentsData in)
  {
    return false;// Not implemented yet
  }
  public AnatomyCompartmentsData unload()
  {
    AnatomyCompartmentsData to = CDMSerializer.objFactory.createAnatomyCompartmentsData();
    unload(to);
    return to;
  }
  protected void unload(AnatomyCompartmentsData to)
  {
    // Not implemented yet
  }

  public SECompartment<EnumAnatomy> GetCompartment(EnumAnatomy anatomy, EnumCompartmentType type)
  {
    switch(type)
    {
      case CHYME:
        return GetChymeCompartment(anatomy);
      case PULMONARY:
        return GetPulmonaryCompartment(anatomy);
      case TEMPERATURE:
        return GetTemperatureCompartment(anatomy);
      case TISSUE:
        return GetTissueCompartment(anatomy);
      case URINE:
        return GetUrineCompartment(anatomy);
      case VASCULAR:
        return GetVascularCompartment(anatomy);
    }
    return null;
  }

  public boolean HasChymeCompartment(EnumAnatomy anatomy)
  {
    return chyme.containsKey(anatomy);
  }
  public SELiquidCompartment<EnumAnatomy> GetChymeCompartment(EnumAnatomy anatomy)
  {
    SELiquidCompartment<EnumAnatomy> cmpt = chyme.get(anatomy);
    if(cmpt==null)
    {
      cmpt = new SELiquidCompartment<EnumAnatomy>();
      chyme.put(anatomy, cmpt);
    }
    return cmpt;
  }
  
  
  public boolean HasPulmonaryCompartment(EnumAnatomy anatomy)
  {
    return pulmonary.containsKey(anatomy);
  }
  public SEGasCompartment<EnumAnatomy> GetPulmonaryCompartment(EnumAnatomy anatomy)
  {
    SEGasCompartment<EnumAnatomy> cmpt = pulmonary.get(anatomy);
    if(cmpt==null)
    {
      cmpt = new SEGasCompartment<EnumAnatomy>();
      pulmonary.put(anatomy, cmpt);
    }
    return cmpt;
  }

  public boolean HasTemperatureCompartment(EnumAnatomy anatomy)
  {
    return temperature.containsKey(anatomy);
  }
  public SEThermalCompartment<EnumAnatomy> GetTemperatureCompartment(EnumAnatomy anatomy)
  {
    SEThermalCompartment<EnumAnatomy> cmpt = temperature.get(anatomy);
    if(cmpt==null)
    {
      cmpt = new SEThermalCompartment<EnumAnatomy>();
      temperature.put(anatomy, cmpt);
    }
    return cmpt;
  }

  public boolean HasTissueCompartment(EnumAnatomy anatomy)
  {
    return tissue.containsKey(anatomy);
  }
  public SETissueCompartment<EnumAnatomy> GetTissueCompartment(EnumAnatomy anatomy)
  {
    SETissueCompartment<EnumAnatomy> cmpt = tissue.get(anatomy);
    if(cmpt==null)
    {
      cmpt = new SETissueCompartment<EnumAnatomy>();
      tissue.put(anatomy, cmpt);
    }
    return cmpt;
  }

  public boolean HasUrineCompartment(EnumAnatomy anatomy)
  {
    return urine.containsKey(anatomy);
  }
  public SELiquidCompartment<EnumAnatomy> GetUrineCompartment(EnumAnatomy anatomy)
  {
    SELiquidCompartment<EnumAnatomy> cmpt = urine.get(anatomy);
    if(cmpt==null)
    {
      cmpt = new SELiquidCompartment<EnumAnatomy>();
      urine.put(anatomy, cmpt);
    }
    return cmpt;
  }

  public boolean HasVascularCompartment(EnumAnatomy anatomy)
  {
    return vascular.containsKey(anatomy);
  }
  public SELiquidCompartment<EnumAnatomy> GetVascularCompartment(EnumAnatomy anatomy)
  {
    SELiquidCompartment<EnumAnatomy> cmpt = vascular.get(anatomy);
    if(cmpt==null)
    {
      cmpt = new SELiquidCompartment<EnumAnatomy>();
      vascular.put(anatomy, cmpt);
    }
    return cmpt;
  }
}
