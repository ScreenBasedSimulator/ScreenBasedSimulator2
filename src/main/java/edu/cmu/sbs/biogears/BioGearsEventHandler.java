package edu.cmu.sbs.biogears;

import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachineEvent;
import mil.tatrc.physiology.datamodel.bind.EnumPatientEvent;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;
import mil.tatrc.physiology.datamodel.utilities.SEEventHandler;
import mil.tatrc.physiology.utilities.Log;

public class BioGearsEventHandler implements SEEventHandler {

    @Override
    public void handlePatientEvent(EnumPatientEvent type, boolean active,
            SEScalarTime time) {
        if (type == EnumPatientEvent.START_OF_CARDIAC_CYCLE && active)
            Log.info("Patient started a new heart beat at time " + time);

    }

    @Override
    public void handleAnesthesiaMachineEvent(EnumAnesthesiaMachineEvent type,
            boolean active, SEScalarTime time) {
        // TODO Auto-generated method stub

    }

}
