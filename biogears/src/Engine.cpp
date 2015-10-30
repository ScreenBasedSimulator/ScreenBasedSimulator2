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

void Engine::Initialize()
{
    m_engine = CreateBioGearsEngine("CPR.log");
    if (!m_engine->InitializeEngine("Standard.xml"))
    {
        std::cerr << "Unable to initialize engine\n";
    }

    m_dt = m_engine->GetTimeStep(SEScalarTime::s) * 1000.0;
}

void Engine::operator()()
{
    using Clock = std::chrono::high_resolution_clock;
    int count = 0;
    while (Running())
    {
        Clock::time_point start = Clock::now();

        if(count == 100){
            count = 0;
            std::cout << "Tidal Volume : " << m_engine->GetRespiratorySystem()->GetTidalVolume(SEScalarVolume::mL) << SEScalarVolume::mL << "\n";
            std::cout << "Systolic Pressure : " << m_engine->GetCardiovascularSystem()->GetSystolicArterialPressure(SEScalarPressure::mmHg) << SEScalarPressure::mmHg << "\n";
            std::cout << "Diastolic Pressure : " << m_engine->GetCardiovascularSystem()->GetDiastolicArterialPressure(SEScalarPressure::mmHg) << SEScalarPressure::mmHg << "\n";
            std::cout << "Heart Rate : " << m_engine->GetCardiovascularSystem()->GetHeartRate(SEScalarFrequency::Per_min) << SEScalarFrequency::Per_min << "\n";
            std::cout << "Respiration Rate : " << m_engine->GetRespiratorySystem()->GetRespirationRate(SEScalarFrequency::Per_min) << SEScalarFrequency::Per_min << "\n";
            std::cout << "Oxygen Saturation : " << m_engine->GetBloodChemistrySystem()->GetOxygenSaturation() << "\n\n";

        }
        count++;
        {

            std::lock_guard<std::mutex> lock(m_pressureMutex);
            

            if (m_newPressure)
            {
                m_newPressure = false;

                SEChestCompressionForce compression;
                compression.GetForce().SetValue(m_pressure, SEScalarForce::N);
                // std::cout<<"enter the print pressure "
                m_engine->ProcessAction(compression);
                // std::cout << "Arterial Pressure: " << m_engine->GetCardiovascularSystem()->GetArterialPressure(SEScalarPressure::mmHg) << "\n";
                
            }
        }

        m_engine->AdvanceModelTime();

        Clock::time_point stop = Clock::now();

        double executionTime = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
        if (executionTime < m_dt)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<long int>(m_dt - executionTime)));
        }
    }
}

void Engine::SetPressure(double pressure)
{
    std::lock_guard<std::mutex> lock(m_pressureMutex);

    m_pressure = pressure;
    std::cout<<"set the pressure"<<std::endl;
    m_newPressure = true;
}
