package mil.tatrc.physiology.biogears.engine;

import java.io.File;
import java.io.IOException;
import java.util.*;

import mil.tatrc.physiology.datamodel.bind.EnumAnatomy;
import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachine;
import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachineEvent;
import mil.tatrc.physiology.datamodel.bind.EnumInhaler;
import mil.tatrc.physiology.datamodel.bind.EnumPatientEvent;
import mil.tatrc.physiology.datamodel.compartment.*;
import mil.tatrc.physiology.datamodel.compartment.anatomy.SEAnatomyCompartments;
import mil.tatrc.physiology.datamodel.compartment.anesthesia.SEAnesthesiaMachineCompartments;
import mil.tatrc.physiology.datamodel.compartment.inhaler.SEInhalerCompartments;
import mil.tatrc.physiology.datamodel.patient.SEPatient;
import mil.tatrc.physiology.datamodel.patient.nutrition.SENutrition;
import mil.tatrc.physiology.datamodel.properties.*;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.TimeUnit;
import mil.tatrc.physiology.datamodel.scenario.datarequests.*;
import mil.tatrc.physiology.datamodel.substance.SESubstance;
import mil.tatrc.physiology.datamodel.substance.SESubstanceCompartmentEffect;
import mil.tatrc.physiology.datamodel.substance.SESubstanceManager;
import mil.tatrc.physiology.datamodel.system.SESystem;
import mil.tatrc.physiology.datamodel.system.environment.*;
import mil.tatrc.physiology.datamodel.system.equipment.anesthesia.*;
import mil.tatrc.physiology.datamodel.system.equipment.electrocardiogram.*;
import mil.tatrc.physiology.datamodel.system.equipment.inhaler.*;
import mil.tatrc.physiology.datamodel.system.physiology.*;
import mil.tatrc.physiology.datamodel.utilities.SEEventHandler;
import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;
import mil.tatrc.physiology.utilities.LogListener;
import mil.tatrc.physiology.utilities.Pair;
import mil.tatrc.physiology.utilities.UnitConverter;

public class BioGears
{
  public SEScalarTime                     timeStep = new SEScalarTime();
  public SEScalarTime                     currentTime = new SEScalarTime();
  
  public SESubstanceManager               substanceManager = new SESubstanceManager();
  public SEPatient                        patient = new SEPatient();
  // Physiology systems
  public SEBloodChemistrySystem           bloodChemistry = new SEBloodChemistrySystem();
  public SECardiovascularSystem           cardiovascular = new SECardiovascularSystem();
  public SEEndocrineSystem                endocrine = new SEEndocrineSystem();
  public SEEnergySystem                   energy = new SEEnergySystem();
  public SEGastrointestinalSystem         gastrointestinal = new SEGastrointestinalSystem();
  public SERenalSystem                    renal = new SERenalSystem();
  public SENervousSystem                  nervous = new SENervousSystem();
  public SERespiratorySystem              respiratory = new SERespiratorySystem();
  public SEDrugSystem                     drug = new SEDrugSystem();
  // Physiology compartments
  public SEAnatomyCompartments            anatomyCompartments = new SEAnatomyCompartments();
  // Environment 
  public SEEnvironment                    environment = new SEEnvironment();
  // Anesthesia
  public SEAnesthesiaMachine              anesthesiaMachine = new SEAnesthesiaMachine();
  public SEAnesthesiaMachineCompartments  anesthesiaMachineCompartments = new SEAnesthesiaMachineCompartments();
  // ECG
  public SEElectroCardioGram              ecg = new SEElectroCardioGram();
  // Inhaler
  public SEInhaler                        inhaler = new SEInhaler();
  public SEInhalerCompartments            inhalerCompartments = new SEInhalerCompartments();
  
  protected CDMUpdatedCallback            cdmCallback;
  protected LogListener                   listener;
  protected SEEventHandler                eventHandler;
  
  protected long nativeObj;
  protected native long nativeAllocate(String logFile);
  protected native void nativeDelete(long nativeObj);
  
  protected List<Pair<SEDataRequest,SEScalar>> dataRequests = new ArrayList<Pair<SEDataRequest,SEScalar>>();  

  public BioGears()
  {
    this.nativeObj=0;
    this.reset();
    
    // We need to copy engine files from user.dir to user.home because on mac
    // The working directory can the home directory depending on how you kick off the app
    // At that point, BioGears will not be able to find the files it needs
    // So we temporarily copy them, we will remove them when things are cleaned up
    try
    {
      FileUtils.copy(new File(System.getProperty("user.dir")  + "/config/"),
          new File(System.getProperty("user.home") + "/config/"));

      FileUtils.copy(new File(System.getProperty("user.dir")  + "/ecg/"),
          new File(System.getProperty("user.home") + "/ecg/"));

      FileUtils.copy(new File(System.getProperty("user.dir")  + "/patients/"),
          new File(System.getProperty("user.home") + "/patients/"));

      FileUtils.copy(new File(System.getProperty("user.dir")  + "/environments/"),
          new File(System.getProperty("user.home") + "/environments/"));

      FileUtils.copy(new File(System.getProperty("user.dir")  + "/xsd/"),
          new File(System.getProperty("user.home") + "/xsd/"));

      FileUtils.copy(new File(System.getProperty("user.dir")  + "/BioGearsConfiguration.xml"),
          new File(System.getProperty("user.home") + "/BioGearsConfiguration.xml"));
    }
    catch (IOException ex)
    {
      Log.warn("Could not copy BioGears files to user.home, BioGears may not execute propertly",ex);
    }
    
    List<String> files = FileUtils.findFiles(System.getProperty("user.dir"), "BioGearsEngineJNI", true);
    if(files.size()!=1)// Attempt to load and hope for the best...    
      System.loadLibrary("BioGearsEngineJNI");
    else
      System.load(files.get(0));

    UnitConverter.initialize(System.getProperty("user.dir"));
  }

  public void finalize()
  {
    this.cleanUp();
  }

  public void reset()
  {
    currentTime.invalidate();
    substanceManager.loadSubstanceDirectory();
    patient.reset();
    bloodChemistry.reset();
    cardiovascular.reset();
    endocrine.reset();
    energy.reset();
    gastrointestinal.reset();
    renal.reset();
    nervous.reset();
    respiratory.reset();
    drug.reset();
    anatomyCompartments.reset();
    environment.reset();
    anesthesiaMachine.reset();
    anesthesiaMachineCompartments.reset();
    ecg.reset();
    inhaler.reset();
    inhalerCompartments.reset();
    cdmCallback=null;
    listener = null;
    eventHandler = null;
  }

  public void cleanUp()
  {
    this.reset();
    if(this.nativeObj!=0)
    {
      nativeDelete(this.nativeObj);
      this.nativeObj=0;
    }
    this.listener = null;
    FileUtils.delete(new File(System.getProperty("user.home") + "/config/"));
    FileUtils.delete(new File(System.getProperty("user.home") + "/ecg/"));
    FileUtils.delete(new File(System.getProperty("user.home") + "/patients/"));
    FileUtils.delete(new File(System.getProperty("user.home") + "/environments/"));
    FileUtils.delete(new File(System.getProperty("user.home") + "/xsd/"));
    FileUtils.delete(new File(System.getProperty("user.home") + "/BioGearsConfiguration.xml"));
  }

  public void setListener(LogListener listener)
  {
    this.listener = listener;
  }
  
  public void setEventHandler(SEEventHandler handler)
  {
    eventHandler = handler;
  }
  /** 
   * C++ will call this method
   * @param type 0 = patient, 1 = anesthesia machine
   * @param event enumeration index
   * @param active if it's on or off
   */
  protected void handleEvent(int type, int event, boolean active, double time_s)
  {
    switch(type)
    {
      case 0:
        if(eventHandler!=null)
          eventHandler.handlePatientEvent(EnumPatientEvent.values()[event],active,new SEScalarTime(time_s,TimeUnit.s));
        this.patient.setEvent(EnumPatientEvent.values()[event],active);
        break;
      case 1:
        if(eventHandler!=null)
          eventHandler.handleAnesthesiaMachineEvent(EnumAnesthesiaMachineEvent.values()[event],active,new SEScalarTime(time_s,TimeUnit.s));
        this.anesthesiaMachine.setEvent(EnumAnesthesiaMachineEvent.values()[event],active);
        break;
      default:
          Log.error("Unsupported event type "+type);
    }
  }
  
  public List<Pair<SEDataRequest,SEScalar>> getDataRequestPairs()
  {
    return Collections.unmodifiableList(this.dataRequests);
  }
  
  protected void updateCDM(double time_s, double[] data)
  {
    int i=0;
    currentTime.setValue(time_s,TimeUnit.s);    
    for(Pair<SEDataRequest,SEScalar> e : dataRequests)
    {
      e.getR().setValue(data[i++],e.getL().getUnit());
    }
    if(this.cdmCallback!=null)
      cdmCallback.update(time_s);
  }
  
  /**
   * You can provided a data request with out a unit
   * And the engine will update the request with what
   * ever it calculated the requested value in.
   * The method will be called to inform us what 
   * unit the data given to updateCDM. If the data 
   * request had a unit specified in the first place,
   * this will be the same, but if no unit was specified
   * in the data request, this information is needed
   * when putting the received value into is associated scalar.
   * @param units
   */
  protected void setCDMHeadings(String[] units)
  {
    int i=0;
    for(Pair<SEDataRequest,SEScalar> e : dataRequests)
    {
      // Rip out the units from the headings
      String unit = units[i++];
      int idx = unit.indexOf('(');
      if(idx > -1)
      {
        unit = unit.substring(idx+1, unit.length()-1);
        unit = unit.replace("_", " ");
        e.getL().setUnit(unit);
      }
      else
        e.getL().setUnit("");// Unitless
    }
  }
  
  // Process all the data requests, and map them to CDM scalars
  protected boolean requestData(List<SEDataRequest> drs)
  {
    // Gather our systems up into a list to make things easier
    List<SESystem> systems = new ArrayList<SESystem>();
    systems.add(bloodChemistry);
    systems.add(cardiovascular);
    systems.add(endocrine);
    systems.add(energy);
    systems.add(gastrointestinal);
    systems.add(renal);
    systems.add(nervous);
    systems.add(respiratory);
    systems.add(drug);
    systems.add(energy);
    
    List<SESystem> equipment = new ArrayList<SESystem>();
    equipment.add(anesthesiaMachine);
    equipment.add(ecg);
    equipment.add(inhaler);
    
    for(SEDataRequest dr : drs)
    {
      if(dr instanceof SEPhysiologySystemDataRequest)
      {
        SEScalar scalar = null;
        for (SESystem sys : systems)
        {
          scalar = SEScalar.getScalar(sys,dr.getName());
          if (scalar != null)
          {
            dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
            break;
          }

          if (sys instanceof SEGastrointestinalSystem && dr.getName().startsWith("Stomach"))
          {
            String scalarNameWithoutStomach = dr.getName().substring(7);
            SENutrition nutrition = ((SEGastrointestinalSystem)sys).getNutrientsInStomach();

            scalar = SEScalar.getScalar(nutrition, scalarNameWithoutStomach);
            if (scalar != null)
            {
              dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
              break;
            }
          }
        }
        if(scalar!=null)
          continue;
        Log.error("Unable to find system property " + dr.getName());
        return false;
      }
      else if(dr instanceof SEAnatomyCompartmentDataRequest)
      {
        SEAnatomyCompartmentDataRequest adr = (SEAnatomyCompartmentDataRequest)dr;
        SECompartment<EnumAnatomy> cmpt = anatomyCompartments.GetCompartment(adr.getCompartment(), adr.getType());
        if(adr.hasSubstance())
        {
          switch(adr.getType())
          {
            case CHYME:
              dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(((SELiquidCompartment<EnumAnatomy>)cmpt).getSubstanceQuantity(adr.getSubstance()), dr.getName())));
              continue;
            case PULMONARY:
              dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(((SEGasCompartment<EnumAnatomy>)cmpt).getSubstanceQuantity(adr.getSubstance()), dr.getName())));
              continue;
            case TISSUE:
              dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(((SETissueCompartment<EnumAnatomy>)cmpt).getSubstanceQuantity(adr.getSubstance()), dr.getName())));
              continue;
            case URINE:
              dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(((SELiquidCompartment<EnumAnatomy>)cmpt).getSubstanceQuantity(adr.getSubstance()), dr.getName())));
              continue;
            case VASCULAR:
              dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(((SELiquidCompartment<EnumAnatomy>)cmpt).getSubstanceQuantity(adr.getSubstance()), dr.getName())));
              continue;
             default:
               Log.error("Unsupported substance data request for a compartment type " + adr.getType());
          }
        }
        else
        {
          dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(cmpt, dr.getName())));
          continue;
        }
        Log.error("Unable to find anatomy property " + dr.getName());
        return false;
      }
      else if(dr instanceof SEPatientDataRequest)
      {
        String name = dr.getName();
        if(dr.getName().startsWith("Patient"))
          name = dr.getName().substring(7);
        SEScalar scalar = SEScalar.getScalar(this.patient, name);
        if (scalar != null)
        {
          dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
          continue;
        }
        Log.error("Unable to find patient property " + dr.getName());
        return false;
      }
      else if(dr instanceof SESubstanceDataRequest)
      {
        SESubstanceDataRequest sdr = (SESubstanceDataRequest)dr;
        SESubstance sub = this.substanceManager.getSubstance(sdr.getSubstance().getName());
        if(sdr.hasCompartment())
        {
          SESubstanceCompartmentEffect subFX = sub.getAnatomyEffect(sdr.getCompartment());
          SEScalar scalar = SEScalar.getScalar(subFX, dr.getName());
          if (scalar != null)
          {
            dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
            continue;
          }
        }
        else
        {
          SEScalar scalar = SEScalar.getScalar(sub, dr.getName());
          if (scalar != null)
          {
            dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
            continue;
          }
        }
        Log.error("Unable to find substance property " + dr.getName());
        return false;
      }
      else if(dr instanceof SEEquipmentSystemDataRequest)
      {
        SEScalar scalar = null;
        for(SESystem equip : equipment)
        {
          scalar = SEScalar.getScalar(equip, dr.getName());
          if (scalar != null)
          {
            dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
            break;
          }
        }
        if(scalar!=null)
          continue;
        Log.error("Unable to find equipment property " + dr.getName());
        return false;
      }
      else if(dr instanceof SEAnesthesiaMachineCompartmentDataRequest)
      {
        SEAnesthesiaMachineCompartmentDataRequest adr = (SEAnesthesiaMachineCompartmentDataRequest)dr;
        SEGasCompartment<EnumAnesthesiaMachine> cmpt = this.anesthesiaMachineCompartments.GetCompartment(adr.getCompartment());
        if(adr.hasSubstance())
        {
          dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(cmpt.getSubstanceQuantity(adr.getSubstance()), dr.getName())));
          continue;
        }
        else
        {
          SEScalar scalar = SEScalar.getScalar(cmpt, dr.getName());
          if (scalar != null)
          {
            dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
            continue;
          }
        }
        Log.error("Unable to find anesthesia machine compartment property " + dr.getName());
        return false;
      }
      else if(dr instanceof SEInhalerCompartmentDataRequest)
      {
        SEInhalerCompartmentDataRequest idr = (SEInhalerCompartmentDataRequest)dr;
        SEGasCompartment<EnumInhaler> cmpt = this.inhalerCompartments.GetCompartment(idr.getCompartment());
        if(idr.hasSubstance())
        {
          dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,SEScalar.getScalar(cmpt.getSubstanceQuantity(idr.getSubstance()), dr.getName())));
          continue;
        }
        else
        {
          SEScalar scalar = SEScalar.getScalar(cmpt, dr.getName());
          if (scalar != null)
          {
            dataRequests.add(new Pair<SEDataRequest,SEScalar>(dr,scalar));
            continue;
          }
        }
        Log.error("Unable to find inhaler compartment property " + dr.getName());
        return false;
      }
      else
      {
        Log.error("Unsupported data request type");
        return false;
      }
    }
    
    // Make sure nothing is mapped to null
    for(Pair<SEDataRequest,SEScalar> p : dataRequests)
    {
      if(p.getL()==null || p.getR()==null)
      {
        Log.error("We have an invalid data request pair");
        return false;
      }
    }
    return true;
  }
  
//TODO I could make origin, the Scenario/engine name we are running
 protected void LogDebug(String msg, String origin)
 {
   if(this.listener!=null)
     this.listener.handleDebug(msg, origin);
 }
 protected void LogInfo(String msg, String origin)
 {
   if(this.listener!=null)
     this.listener.handleInfo(msg, origin);
 }
 protected void LogWarning(String msg, String origin)
 {
   if(this.listener!=null)
     this.listener.handleWarn(msg, origin);
 }
 protected void LogError(String msg, String origin)
 {
   if(this.listener!=null)
     this.listener.handleError(msg, origin);
 }
 protected void LogFatal(String msg, String origin)
 {
   if(this.listener!=null)
     this.listener.handleFatal(msg, origin);
 }
}
