package edu.cmu.sbs.biogears;

import edu.cmu.sbs.hub.datatype.PatientStatus;
import mil.tatrc.physiology.biogears.engine.BioGearsEngine;
import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachineOxygenSource;
import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachinePrimaryGas;
import mil.tatrc.physiology.datamodel.bind.EnumOnOff;
import mil.tatrc.physiology.datamodel.bind.EnumSubstanceAdministration;
import mil.tatrc.physiology.datamodel.patient.SEPatient;
import mil.tatrc.physiology.datamodel.patient.actions.SESubstanceBolus;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.*;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.TimeUnit;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;
import mil.tatrc.physiology.datamodel.scenario.datarequests.SEDataRequest;
import mil.tatrc.physiology.datamodel.scenario.datarequests.SEPhysiologySystemDataRequest;
import mil.tatrc.physiology.datamodel.substance.SESubstance;
import mil.tatrc.physiology.datamodel.substance.SESubstanceManager;
import mil.tatrc.physiology.datamodel.system.equipment.anesthesia.SEAnesthesiaMachine;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.*;

import static java.util.concurrent.TimeUnit.SECONDS;

public class PatientSimulator {

    private final static SEScalarTime ONE_SECOND = new SEScalarTime(1,
            TimeUnit.s);
    private final static ExecutorService THREAD_POOL = Executors.newFixedThreadPool(1);
    private final static SESubstanceManager SUBSTANCE_MANAGER = new SESubstanceManager();
    public final String patientHash;
    private final ScheduledExecutorService SCHEDULED_EXECUTOR = Executors
            .newScheduledThreadPool(1);
    private final SEAnesthesiaMachine m_anesthesiaMachine = new SEAnesthesiaMachine();
    private Future<BioGearsEngine> m_enginePromise;
    private BioGearsEngine m_engine;

    public PatientSimulator(String patientHash) {

        this.patientHash = patientHash;

        // Allocate an engine
        m_enginePromise = initializeEngine();
        SCHEDULED_EXECUTOR.scheduleAtFixedRate(new Runnable() {
            @Override
            public void run() {
                if (m_enginePromise.isDone()) {
                    m_engine.advanceTime(ONE_SECOND);
                }
            }
        }, 0, 1L, SECONDS);

        m_anesthesiaMachine.setState(EnumOnOff.OFF);
    }

    public boolean isReady() {
        return m_enginePromise.isDone();
    }

    public PatientStatus getStatus() {
        if (m_enginePromise.isDone()) {
//            PatientStatus status = new PatientStatus();
            m_engine.respiratory.getRespirationRate();
        } else {

        }
        return null;
    }

    public void setAnesthesiaMachine(String state)
            throws IllegalStateException {
        if (!m_enginePromise.isDone()) {
            throw new IllegalStateException("Engine is not ready");
        }
        switch (state) {
            case "off":
                m_anesthesiaMachine.setState(EnumOnOff.OFF);
                break;
            case "active":
                m_anesthesiaMachine.setState(EnumOnOff.ON);
                m_anesthesiaMachine.getInletFlow().setValue(5.0, VolumePerTimeUnit.L_Per_min);
                m_anesthesiaMachine.getInspiratoryExpiratoryRatio().setValue(1.0);
                m_anesthesiaMachine.getOxygenFraction().setValue(0.21); //0.21 in the air
                m_anesthesiaMachine.setOxygenSource(EnumAnesthesiaMachineOxygenSource.WALL);
                m_anesthesiaMachine.getPositiveEndExpiredPressure().setValue(1.0, PressureUnit.cmH2O);
                m_anesthesiaMachine.setPrimaryGas(EnumAnesthesiaMachinePrimaryGas.NITROGEN);
                m_anesthesiaMachine.getReliefValvePressure().setValue(20.0, PressureUnit.cmH2O);
                m_anesthesiaMachine.getRespiratoryRate().setValue(18, FrequencyUnit.Per_min);
                m_anesthesiaMachine.getVentilatorPressure().setValue(10.0, PressureUnit.cmH2O);
                m_anesthesiaMachine.setVentilatorMask(EnumOnOff.ON);
                break;
            default:
                throw new IllegalArgumentException("No state: " + state + " for anesthesia machine");
        }
    }

    public void bolusDrug(String drugName, Double dose) {
        SESubstance substance = SUBSTANCE_MANAGER.getSubstance(drugName);

        if (substance != null) {
            // Create a substance bolus action to administer the substance
            SESubstanceBolus bolus = new SESubstanceBolus(substance);
            bolus.getConcentration().setValue(1000, MassPerVolumeUnit.ug_Per_mL);
            bolus.getDose().setValue(dose, VolumeUnit.mL);
            bolus.setAdminRoute(EnumSubstanceAdministration.INTRAVENOUS);
            m_engine.processAction(bolus);
        } else {
            throw new IllegalArgumentException("No such drug:" + drugName);
        }

    }

    private Future<BioGearsEngine> initializeEngine() {
        return THREAD_POOL.submit(new Callable<BioGearsEngine>() {
            @Override
            public BioGearsEngine call() throws Exception {
                System.out.println("Starting Engine1");
                BioGearsEngine bge = new BioGearsEngine();
                bge.setListener(new BioGearsListener());
                System.out.println("Starting Engine2");
                bge.setEventHandler(new BioGearsEventHandler());
                SEPatient patient = new SEPatient();
                System.out.println("Starting Engine3");
                patient.loadPatientFile("patients/Standard.xml");
                System.out.println("Starting Engine4");
                List<SEDataRequest> dataRequests = new ArrayList<SEDataRequest>();
                SEPhysiologySystemDataRequest hr = new SEPhysiologySystemDataRequest();
                hr.setName("HeartRate");
                hr.setUnit(FrequencyUnit.Per_min.toString());
                dataRequests.add(hr);
                SEPhysiologySystemDataRequest rr = new SEPhysiologySystemDataRequest();
                rr.setName("RespirationRate");
                rr.setUnit(FrequencyUnit.Per_min.toString());
                dataRequests.add(rr);
                SEPhysiologySystemDataRequest spo2 = new SEPhysiologySystemDataRequest();
                spo2.setName("OxygenSaturation");
                dataRequests.add(spo2);
                SEPhysiologySystemDataRequest sp = new SEPhysiologySystemDataRequest();
                sp.setName("SystolicArterialPressure");
                sp.setUnit(PressureUnit.mmHg.toString());
                dataRequests.add(sp);
                SEPhysiologySystemDataRequest dp = new SEPhysiologySystemDataRequest();
                dp.setName("DiastolicArterialPressure");
                dp.setUnit(PressureUnit.mmHg.toString());
                dataRequests.add(dp);
                System.out.println("Starting Engine");
                bge.initializeEngine("./BioGears.log", patient, null,
                        dataRequests);
                return bge;
            }
        });
    }
}
