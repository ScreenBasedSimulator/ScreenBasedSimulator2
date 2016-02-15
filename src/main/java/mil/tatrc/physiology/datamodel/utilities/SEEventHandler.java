package mil.tatrc.physiology.datamodel.utilities;

import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachineEvent;
import mil.tatrc.physiology.datamodel.bind.EnumPatientEvent;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;

public interface SEEventHandler
{
  public void handlePatientEvent(EnumPatientEvent type, boolean active, SEScalarTime time);
  public void handleAnesthesiaMachineEvent(EnumAnesthesiaMachineEvent type, boolean active, SEScalarTime time);
}
