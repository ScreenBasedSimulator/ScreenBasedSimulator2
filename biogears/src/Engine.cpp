#include "Engine.h"

#include "properties/SEScalarTime.h"
#include "properties/SEScalarForce.h"
#include "properties/SEScalarPressure.h"
#include "patient/actions/SEChestCompressionForce.h"
#include "system/physiology/SECardiovascularSystem.h"
#include "system/physiology/SEBloodChemistrySystem.h"
#include "system/physiology/SERespiratorySystem.h"
#include "patient/actions/SEAirwayObstruction.h"
#include "properties/SEScalarFraction.h"
#include "properties/SEScalarFrequency.h"
#include "properties/SEScalarMassPerVolume.h"
#include "properties/SEScalarPressure.h"
#include "properties/SEScalarTemperature.h"
#include "properties/SEScalarTime.h"
#include "properties/SEScalarVolume.h"
#include "properties/SEScalarVolumePerTime.h"
#include "properties/SEFunctionTimeVsVolume.h"
#include "engine/PhysiologyEngineTrack.h"
#include "scenario/SEPhysiologySystemDataRequest.h"
#include <chrono>
#include <thread>
#include <cstring>
#include "substance/SESubstanceManager.h"
#include "patient/actions/SESubstanceBolus.h"
#include "system/equipment/Anesthesia/SEAnesthesiaMachine.h"
#include "system/equipment/Anesthesia/SEAnesthesiaMachineOxygenBottle.h"
#include "system/equipment/Anesthesia/actions/SEAnesthesiaMachineConfiguration.h"

Engine::Engine(Driver * pDriver)
{
    m_pDriver = pDriver;
}
void Engine::Initialize()
{
    m_engine = CreateBioGearsEngine("CPR.log");
    if (!m_engine->InitializeEngine("Standard.xml"))
    {
        std::cerr << "Unable to initialize engine\n";
    }

    m_dt = m_engine->GetTimeStep(SEScalarTime::s) * 1000.0;
    m_pAnesthesiaMachineConfig = new SEAnesthesiaMachineConfiguration(m_engine->GetSubstanceManager());

    SEAnesthesiaMachine& config = m_pAnesthesiaMachineConfig->GetConfiguration();
    config.SetState(CDM::enumOnOff::Off); //changed it to Off at the beginning
    config.GetInletFlow().SetValue(2.0, SEScalarVolumePerTime::L_Per_min);
    config.GetInspiratoryExpiratoryRatio().SetValue(.5);
    config.GetOxygenFraction().SetValue(0.21); //0.21 in the air
    config.SetOxygenSource(CDM::enumAnesthesiaMachineOxygenSource::Wall);
    config.GetPositiveEndExpiredPressure().SetValue(0.0, SEScalarPressure::cmH2O);
    config.SetPrimaryGas(CDM::enumAnesthesiaMachinePrimaryGas::Nitrogen);
    config.GetReliefValvePressure().SetValue(20.0, SEScalarPressure::cmH2O);
    config.GetRespiratoryRate().SetValue(12, SEScalarFrequency::Per_min);
    config.GetVentilatorPressure().SetValue(0.0, SEScalarPressure::cmH2O);
    config.SetVentilatorMask(CDM::enumOnOff::On);
    config.GetOxygenBottleOne().GetVolume().SetValue(660.0, SEScalarVolume::L);
    config.GetOxygenBottleTwo().GetVolume().SetValue(660.0, SEScalarVolume::L);
}

crow::json::wvalue Engine::GetPatientStatus() {
    crow::json::wvalue status;
    /* heartrate      |66.03         |double value round to two decimal places
     * resprate       |75.48         |double value round to two decimal places
     * systolicbp     |37.99         |double value round to two decimal places
     * diastolicbp    |120.91        |double value round to two decimal places
     * oxygen         |93.60         |double value round to two decimal places
     */
    status["heart_rate"] = m_engine->GetCardiovascularSystem()->GetHeartRate(SEScalarFrequency::Per_min);
    status["oxygen_saturation"] = m_engine->GetBloodChemistrySystem()->GetOxygenSaturation();
    status["systolic_arterial_pressure"] = m_engine->GetCardiovascularSystem()->GetSystolicArterialPressure(SEScalarPressure::mmHg);
    status["diastolic_arterialPressure"] = m_engine->GetCardiovascularSystem()->GetDiastolicArterialPressure(SEScalarPressure::mmHg);
    status["respiration_rate"] = m_engine->GetRespiratorySystem()->GetRespirationRate(SEScalarFrequency::Per_min);
    status["hash"] = "abcdefg";
    
    return status;
}

void Engine::operator()()
{
    using Clock = std::chrono::high_resolution_clock;
    
    curl_global_init(CURL_GLOBAL_ALL);
    
    double timeElapsed = 0.0;
    int failureCount = 0; //if it fails to connect for five times, the program is terminated.
    while (Running())
    {
        Clock::time_point start = Clock::now();
        {

            std::lock_guard<std::mutex> lock(m_pressureMutex);
            
        }
        if (timeElapsed > 500.0) {
            timeElapsed = 0;
            /* Now specify the POST data */ 
            crow::json::wvalue status;
            status["heart_rate"] = m_engine->GetCardiovascularSystem()->GetHeartRate(SEScalarFrequency::Per_min);
            status["oxygen_saturation"] = m_engine->GetBloodChemistrySystem()->GetOxygenSaturation();
            status["systolic_arterial_pressure"] = m_engine->GetCardiovascularSystem()->GetSystolicArterialPressure(SEScalarPressure::mmHg);
            status["diastolic_arterialPressure"] = m_engine->GetCardiovascularSystem()->GetDiastolicArterialPressure(SEScalarPressure::mmHg);
            status["respiration_rate"] = m_engine->GetRespiratorySystem()->GetRespirationRate(SEScalarFrequency::Per_min);
            status["hash"] = "abcdefg";
            /* get a curl handle */ 
            CURL * curl = curl_easy_init();

            if (curl) {
                curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:6666/update");
                char* result=strdup(crow::json::dump(status).c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(result));
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, result);
                CURLcode res = curl_easy_perform(curl);
                if(res != CURLE_OK) {
                    fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
                    failureCount++;
                    if (failureCount > 4) exit(1);
                } else {
                    failureCount = 0;
                }

                curl_easy_cleanup(curl);
                free(result);
            }
        }

        m_engine->AdvanceModelTime();

        Clock::time_point stop = Clock::now();

        double executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        if (executionTime < m_dt)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long int>(m_dt - executionTime)));
        }
        timeElapsed += m_dt;
    }
}
void Engine::BolusDrug(std::string drugName, double concentration, double dose)
{

    // std::lock_guard<std::mutex> lock(m_pressureMutex);
    const SESubstance* succs = m_engine->GetSubstanceManager().GetSubstance(drugName);

    // Create a substance bolus action to administer the substance
    SESubstanceBolus bolus(*succs);
    bolus.GetConcentration().SetValue(concentration,SEScalarMassPerVolume::ug_Per_mL);
    bolus.GetDose().SetValue(dose,SEScalarVolume::mL);
    bolus.SetAdminRoute(CDM::enumSubstanceAdministration::Intravenous);
    m_engine->ProcessAction(bolus);
    std::cout << "Giving the patient .\n\n" << drugName << " with " 
    << dose << " dosage and " << concentration << " concentration" <<endl;
}

void Engine::AnesthesiaMachine(double oxygenFraction, bool status){
    // You can set configuration by modifing the configuration class directly
    // Or you can point to an XML with configuration data.
    // Modifying the class will keep any old settings that are not provided in the config
    // Using a xml will set the anesthesia machine to only the property states specified in the file
    SEAnesthesiaMachine& config = m_pAnesthesiaMachineConfig->GetConfiguration();

    if (status == true) {
        config.GetOxygenFraction().SetValue(oxygenFraction); 
        config.SetState(CDM::enumOnOff::On);
        std::cout << "Turning on the Anesthesia Machine and placing mask on patient for spontaneous breathing with machine connection.\n\n";
    } else {
        config.SetState(CDM::enumOnOff::Off);
        std::cout << "Turning off the Anesthesia Machine and removing the mask.\n\n";
    }

    m_engine->ProcessAction(*m_pAnesthesiaMachineConfig);
    
}
void Engine::SetPressure(double pressure)
{
    std::lock_guard<std::mutex> lock(m_pressureMutex);

    m_pressure = pressure;
    std::cout<<"set the pressure"<<std::endl;
    m_newPressure = true;
}
