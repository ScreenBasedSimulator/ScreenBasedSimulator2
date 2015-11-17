#ifndef ENGINE_H
#define ENGINE_H
#include <mutex>
#include <curl/curl.h>
#include "Runnable.h"
#include "BioGearsPhysiologyEngine.h"
#include "Driver.h"

class Driver;

class Engine : public Runnable
{
public:
    virtual void operator()() override;
    Engine(Driver* pDriver);
    void Initialize();
    void SetPressure(double pressure);
    void BolusDrug(std::string drugName, double concentration, double dose);
    void AnesthesiaMachine(double oxygenFraction);
    crow::json::wvalue GetPatientStatus();

private:
    std::unique_ptr<PhysiologyEngine> m_engine;
    Driver * m_pDriver;
    double m_dt = 0.0;

    double m_pressure = -1.0;
    bool m_newPressure = false;
    mutable std::mutex m_pressureMutex;
};

#endif
