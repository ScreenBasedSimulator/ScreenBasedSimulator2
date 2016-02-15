package mil.tatrc.physiology.biogears.engine;

import java.util.ArrayList;
import java.util.List;

import mil.tatrc.physiology.datamodel.CDMSerializer;
import mil.tatrc.physiology.datamodel.bind.ActionListData;
import mil.tatrc.physiology.datamodel.bind.CompleteBloodCountData;
import mil.tatrc.physiology.datamodel.bind.ComprehensiveMetabolicPanelData;
import mil.tatrc.physiology.datamodel.bind.ConditionListData;
import mil.tatrc.physiology.datamodel.bind.DataRequestListData;
import mil.tatrc.physiology.datamodel.bind.EnumPatientAssessment;
import mil.tatrc.physiology.datamodel.bind.PulmonaryFunctionTestData;
import mil.tatrc.physiology.datamodel.bind.UrinalysisData;
import mil.tatrc.physiology.datamodel.patient.SEPatient;
import mil.tatrc.physiology.datamodel.patient.assessments.SECompleteBloodCount;
import mil.tatrc.physiology.datamodel.patient.assessments.SEComprehensiveMetabolicPanel;
import mil.tatrc.physiology.datamodel.patient.assessments.SEPatientAssessment;
import mil.tatrc.physiology.datamodel.patient.assessments.SEPulmonaryFunctionTest;
import mil.tatrc.physiology.datamodel.patient.assessments.SEUrinalysis;
import mil.tatrc.physiology.datamodel.properties.CommonUnits.TimeUnit;
import mil.tatrc.physiology.datamodel.properties.SEScalarTime;
import mil.tatrc.physiology.datamodel.scenario.actions.SEAction;
import mil.tatrc.physiology.datamodel.scenario.conditions.SECondition;
import mil.tatrc.physiology.datamodel.scenario.datarequests.SEDataRequest;
import mil.tatrc.physiology.utilities.FileUtils;
import mil.tatrc.physiology.utilities.Log;

public class BioGearsEngine extends BioGears
{
  public BioGearsEngine()
  {
    super();
  }
  
  public void reset()
  {
    super.reset();
    if(this.nativeObj!=0)
      this.nativeReset(this.nativeObj);
  }

  // TODO Set a callback for patient events

  public boolean initializeEngine(String logFile, SEPatient patient, List<SECondition> conditions, List<SEDataRequest> dataRequests)
  {
    if(this.nativeObj != 0)
    {
      Log.error("Engine has already been allocated/initialized, please cleanUp then try again.");
      return false;
    }
    String patientXML = CDMSerializer.serialize(patient.unload());
    if(patientXML == null || patientXML.isEmpty())
    {
      Log.error("Invalid/No patient provided");
      return false;
    }
    String conditionsXML = null;
    if(conditions !=null && !conditions.isEmpty())
    {
      ConditionListData cData = CDMSerializer.objFactory.createConditionListData();
      for(SECondition c : conditions)
        cData.getCondition().add(c.unload());
      conditionsXML = CDMSerializer.serialize(cData);
    }
    String dataRequestsXML = null;
    if(dataRequests !=null && !dataRequests.isEmpty())
    {
      DataRequestListData drData = CDMSerializer.objFactory.createDataRequestListData();
      for(SEDataRequest dr : dataRequests)
        drData.getDataRequest().add(dr.unload());
      dataRequestsXML = CDMSerializer.serialize(drData);
    }
    
    if(dataRequestsXML == null)
    {
      Log.error("Invalid/No data requests provided");
      return false;
    }
    this.requestData(dataRequests);
    this.nativeObj = this.nativeAllocate(logFile);
    return nativeInitializeEngine(this.nativeObj, patientXML, conditionsXML, dataRequestsXML);
  }
  
  public boolean initializeEngine(String logFile, String patientFile, List<SECondition> conditions, List<SEDataRequest> dataRequests)
  {
    if(this.nativeObj != 0)
    {
      Log.error("Engine has already been allocated/initialized, please cleanUp then try again.");
      return false;
    }
    String patientXML = FileUtils.readFile(patientFile);
    if(patientXML == null || patientXML.isEmpty())
    {
      Log.error("Invalid/No patient provided");
      return false;
    }
    String conditionsXML = null;
    if(conditions !=null && !conditions.isEmpty())
    {
      ConditionListData cData = CDMSerializer.objFactory.createConditionListData();
      for(SECondition c : conditions)
        cData.getCondition().add(c.unload());
      conditionsXML = CDMSerializer.serialize(cData);
    }
    String dataRequestsXML = null;
    if(dataRequests !=null && !dataRequests.isEmpty())
    {
      DataRequestListData drData = CDMSerializer.objFactory.createDataRequestListData();
      for(SEDataRequest dr : dataRequests)
        drData.getDataRequest().add(dr.unload());
      dataRequestsXML = CDMSerializer.serialize(drData);
    }
    if(dataRequestsXML == null)
    {
      Log.error("Invalid/No data requests provided");
      return false;
    }
    this.requestData(dataRequests);
    this.nativeObj = this.nativeAllocate(logFile);
    return nativeInitializeEngine(this.nativeObj, patientXML, conditionsXML, dataRequestsXML);
  }
  
  public void advanceTime()
  {
    nativeAdvanceTimeStep(this.nativeObj);
  }
  
  public void advanceTime(SEScalarTime time)
  {
    nativeAdvanceTime(this.nativeObj, time.getValue(TimeUnit.s));
  }
  
  public void processAction(SEAction action)
  {
    List <SEAction> actions = new ArrayList<SEAction>(); 
    actions.add(action);
    processActions(actions);
  }
  
  public void processActions(List<SEAction> actions)
  {
    if(actions !=null && !actions.isEmpty())
    {
      ActionListData aData = CDMSerializer.objFactory.createActionListData();
      for(SEAction a : actions)
        aData.getAction().add(a.unload());
      String actionsXML = CDMSerializer.serialize(aData);
      nativeProcessActions(this.nativeObj,actionsXML);
    }
  }
  
  public boolean getPatientAssessment(SEPatientAssessment assessment)
  {
    if(assessment instanceof SEPulmonaryFunctionTest)
    {
      String xml = nativeGetAssessment(this.nativeObj, EnumPatientAssessment.PULMONARY_FUNCTION_TEST.ordinal());
      Object obj = CDMSerializer.serialize(xml);
      if(obj instanceof PulmonaryFunctionTestData)
      { 
        return ((SEPulmonaryFunctionTest)assessment).load((PulmonaryFunctionTestData)obj);
      }
      Log.error("XML could not be parsed by SEPulmonaryFunctionTest : "+xml);
      return false;
    }
    
    if(assessment instanceof SECompleteBloodCount)
    {
      String xml = nativeGetAssessment(this.nativeObj, EnumPatientAssessment.COMPLETE_BLOOD_COUNT.ordinal());
      Object obj = CDMSerializer.serialize(xml);
      if(obj instanceof CompleteBloodCountData)
      { 
        return ((SECompleteBloodCount)assessment).load((CompleteBloodCountData)obj);
      }
      Log.error("XML could not be parsed by SECompleteBloodCount : "+xml);
      return false;
    }
    
    if(assessment instanceof SEComprehensiveMetabolicPanel)
    {
      String xml = nativeGetAssessment(this.nativeObj, EnumPatientAssessment.COMPREHENSIVE_METABOLIC_PANEL.ordinal());
      Object obj = CDMSerializer.serialize(xml);
      if(obj instanceof ComprehensiveMetabolicPanelData)
      { 
        return ((SEComprehensiveMetabolicPanel)assessment).load((ComprehensiveMetabolicPanelData)obj);
      }
      Log.error("XML could not be parsed by SEComprehensiveMetabolicPanel : "+xml);
      return false;
    }
    
    if(assessment instanceof SEUrinalysis)
    {
      String xml = nativeGetAssessment(this.nativeObj, EnumPatientAssessment.URINALYSIS.ordinal());
      Object obj = CDMSerializer.serialize(xml);
      if(obj instanceof UrinalysisData)
      { 
        return ((SEUrinalysis)assessment).load((UrinalysisData)obj);        
      }
      Log.error("XML could not be parsed by SEUrinalysis : "+xml);
      return false;
    }
    
    return false;
  }
  
  /**
   * Used for C++ communication for calculation outside of the java language
   * @return - success flag from calculate
   */
  protected native void nativeReset(long nativeObj);
  protected native boolean nativeIsValid(long nativeObj);
  
  protected native boolean nativeInitializeEngine(long nativeObj, String patientXML, String conditionsXML, String dataRequestsXML);
  protected native void nativeAdvanceTimeStep(long nativeObj);
  protected native void nativeAdvanceTime(long nativeObj, double time_s);
  protected native void nativeProcessActions(long nativeObj, String actionsXML);
  protected native String nativeGetAssessment(long nativeObj, int type);
}
