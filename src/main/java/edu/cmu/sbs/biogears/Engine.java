package edu.cmu.sbs.biogears;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import mil.tatrc.physiology.biogears.engine.BioGearsEngine;
import mil.tatrc.physiology.datamodel.bind.EnumAnatomy;
import mil.tatrc.physiology.datamodel.bind.EnumAnesthesiaMachineEvent;
import mil.tatrc.physiology.datamodel.bind.EnumGender;
import mil.tatrc.physiology.datamodel.bind.EnumPatientEvent;
import mil.tatrc.physiology.datamodel.patient.SEPatient;
import mil.tatrc.physiology.datamodel.patient.actions.SEHemorrhage;
import mil.tatrc.physiology.datamodel.patient.assessments.SECompleteBloodCount;
import mil.tatrc.physiology.datamodel.patient.conditions.ChronicAnemia;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.FrequencyUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.LengthUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.MassUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.PressureUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.TimeUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.VolumePerTimeUnit;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.VolumeUnit;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;
import mil.tatrc.physiology.datamodel.scenario.conditions.SECondition;
import mil.tatrc.physiology.datamodel.scenario.datarequests.SEDataRequest;
import mil.tatrc.physiology.datamodel.scenario.datarequests.SEPhysiologySystemDataRequest;
import mil.tatrc.physiology.datamodel.utilities.SEEventHandler;
import mil.tatrc.physiology.utilities.Log;
import mil.tatrc.physiology.utilities.LogListener;

public class Engine {
	protected static class BioGearsListener extends LogListener
	{
		protected BioGearsListener()
		{
			super();
			listen(false);
		}    
		public void handleDebug(String msg) { Log.debug(msg); }
		public void handleInfo(String msg)  { Log.info(msg); }
		public void handleWarn(String msg)  { Log.warn(msg); }
		public void handleError(String msg) { Log.error(msg); }
		public void handleFatal(String msg) { Log.fatal(msg); }
	}
	protected static class BioGearsEventHandler implements SEEventHandler
	{

		public void handlePatientEvent(EnumPatientEvent type, boolean active, SEScalarTime time)
		{
			if(type == EnumPatientEvent.START_OF_CARDIAC_CYCLE && active)
				Log.info("Patient started a new heart beat at time "+time);    
		}

		public void handleAnesthesiaMachineEvent(EnumAnesthesiaMachineEvent type, boolean active, SEScalarTime time)
		{

		}

	}
	 public static void main(String[] args) {

		  System.out.println( System.getProperty("java.library.path"));

	   // Create a BioGears Engine
	   BioGearsEngine bge = new BioGearsEngine();// The engine log will be named based the provided string + ".log" 
	   
	   // I am going to create a listener that will get any log messages (Info, Warnings, Errors, Fatal Errors)
	   // that come from the engine. The default listener will just put them into the log file
	   // If you want to do custom logic that occurs when the engine throws an error (or any other message type), just create a class just like this one
	   bge.setListener(new BioGearsListener());
	   
	   // I want to know when ever the patient and anesthesia machine(if used) enters and exits a particular state
	   bge.setEventHandler(new BioGearsEventHandler());
	   
	   // I am going to make my own patient, you can alternatively simply refer to a patient file on disk if you would like
	   // It is just a copy of the standard xml (as it was when I wrote this, if it's different as you are reading this)
	   SEPatient patient = new SEPatient();
	   patient.setName("Standard");
	   patient.setGender(EnumGender.MALE);
	   patient.getAge().setValue(44,TimeUnit.yr);
	   patient.getWeight().setValue(170,MassUnit.kg);
	   patient.getHeight().setValue(71,LengthUnit.in);
	   patient.getBodyFatFraction().setValue(0.18);
	   patient.getCarinaToTeethDistance().setValue(22,LengthUnit.mm);
	   patient.getHeartRateBaseline().setValue(72,FrequencyUnit.Per_min);
	   patient.getMeanArterialPressureBaseline().setValue(87,PressureUnit.mmHg);
	   patient.getRespirationRateBaseline().setValue(16,FrequencyUnit.Per_min);
	   patient.getRightLungRatio().setValue(0.55);
	   patient.getTotalBloodVolumeBaseline().setValue(5000,VolumeUnit.mL);
	   
	   // Here are the data I want back from the engine
	   // The CDM objects on the bge object will be updated 
	   // at the end of AdvanceTime calls (which are blocking)
	   List<SEDataRequest> dataRequests = new ArrayList<SEDataRequest>();
	   SEPhysiologySystemDataRequest hr = new SEPhysiologySystemDataRequest();
	   hr.setName("HeartRate");
	   hr.setUnit(FrequencyUnit.Per_min.toString());
	   dataRequests.add(hr);
	   SEPhysiologySystemDataRequest rr = new SEPhysiologySystemDataRequest();
	   rr.setName("RespirationRate");
	   rr.setUnit(FrequencyUnit.Per_min.toString());
	   dataRequests.add(rr);
	   SEPhysiologySystemDataRequest tlv = new SEPhysiologySystemDataRequest();    
	   tlv.setName("TotalLungVolume");
	   tlv.setUnit(VolumeUnit.mL.toString());
	   dataRequests.add(tlv);
	   SEPhysiologySystemDataRequest bv = new SEPhysiologySystemDataRequest();    
	   bv.setName("BloodVolume");
	   bv.setUnit(VolumeUnit.mL.toString());
	   dataRequests.add(bv);
	   
	   // If I wanted to make set a condition on the patient
	   // Note that while you can have multiple conditions on a patient
	   // It is more than likely not tested and the engine may or may not converge
	   List<SECondition> conditions = new ArrayList<SECondition>();
	   ChronicAnemia anemia = new ChronicAnemia();// One of these days I will prefix these with SE...
	   anemia.getReductionFactor().setValue(0.3);
	   
	   // Allocate an engine
	   bge.initializeEngine("./Scenarios/HowToDynamicEngine.log", patient, null/*or pass in our conditions list*/, dataRequests);
	   // example of specifying a patient file, you would still need to provide a list of SECondition objects as well as SEDataRequest objects
	   //bge.initializeEngine("./patient/Standard.xml", null, dataRequests);
	   
	   SEScalarTime time = new SEScalarTime(1, TimeUnit.s);
	   
	   // Now we can start telling the engine what to do
	   // All the same concepts apply from the C++ HowTo files, so look there if you want to see more examples
	   
	   bge.advanceTime(); // Advance one engine time step
	   // The CDM objects contained in bge will be automatically updated after this method returns
	   // NOTE ONLY THE CDM PROPERTIES ASSOCIATED WITH THE DATA REQUESTS PROVIDED IN initializeEngine WILL BE UPDATED
	   // it would be pretty slow to push EVERYTHING from the engine into Java if you are not using it all.
	   // This is just a limitation of the Java interface, let me know if you think we can push everything or have some other idea for pushing..
	   // SO this does mean that you have to know up front everything you are going to use from the engine, there may be ways to make it more
	   // dynamic it getting data back from the engine, but at this time, I am not going to support that, not that it cannot be done, again let's talk if you want it...
	   
	   Log.info("Heart Rate " + bge.cardiovascular.getHeartRate());
	   Log.info("Respiration Rate " + bge.respiratory.getRespirationRate());
	   Log.info("Total Lung Volume " + bge.respiratory.getTotalLungVolume());
	   Log.info("Blood Volume " + bge.cardiovascular.getBloodVolume());    
	   
	   // Let's get an assessment from the engine
	   // Assessments can involve extra calculation to generate the data necessary for the specified assessment
	   SECompleteBloodCount cbc = new SECompleteBloodCount();
	   bge.getPatientAssessment(cbc);
	   Log.info("Red Blood Count "+cbc.getRedBloodCellCount());
	   Log.info("White Blood Count "+cbc.getWhiteBloodCellCount());
	   
	   // You can check if the patient is in a specific state/event
	   if(!bge.patient.isEventActive(EnumPatientEvent.CARDIAC_ARREST))
	     Log.info("CODE BLUE!");
	   
	   bge.advanceTime(time); // Simulate one second
	   // Again, the CDM is updated after this call
	   
	   Log.info("Heart Rate " + bge.cardiovascular.getHeartRate());
	   Log.info("Respiration Rate " + bge.respiratory.getRespirationRate());
	   Log.info("Total Lung Volume " + bge.respiratory.getTotalLungVolume());   
	   Log.info("Blood Volume " + bge.cardiovascular.getBloodVolume());      
	   
	   // Let's do something to the patient, you can either send actions over one at a time, or pass in a List<SEAction>
	   SEHemorrhage h = new SEHemorrhage();
	   h.setCompartment(EnumAnatomy.RIGHT_LEG);
	   h.getRate().setValue(2.5,VolumePerTimeUnit.mL_Per_s);
	   bge.processAction(h);
	   // Note CDM is not updated after this call, you have to advance some time

	   time.setValue(2.0,TimeUnit.min);
	   bge.advanceTime(time); // Simulate one second
	   // Again, the CDM is updated after this call
	   
	   Log.info("Heart Rate " + bge.cardiovascular.getHeartRate());
	   Log.info("Respiration Rate " + bge.respiratory.getRespirationRate());
	   Log.info("Total Lung Volume " + bge.respiratory.getTotalLungVolume());     
	   Log.info("Blood Volume " + bge.cardiovascular.getBloodVolume());    
	   
	   // Be nice to your memory and deallocate the native memory associated with this engine if you are done with it
	   bge.cleanUp();
	   // Note you can now run a static (scenario) or another dynamic engine with the bge object, it will allocate and manage a new C++ engine 
	 }
}
