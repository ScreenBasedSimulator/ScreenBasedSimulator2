#include "Driver.h"
#include "Connection.h"
#include "crow_all.h"
#include <thread>
#include <sstream>

Driver::Driver()
    : m_connection(this)
{
}

void Driver::Initialize()
{
    m_engine.Initialize();
}

void Driver::Run()
{
    std::thread engineThread    ([this]() { m_engine();  });
    std::thread connectionThread([this]() { m_connection();  });
    m_connection.SetRunning(false);
    //m_engine.SetRunning(false);

    connectionThread.join();
    engineThread.join();
}

void Driver::HandleMessage(const std::string& message)
{
    double value = 0.0;
    
    std::istringstream iss(message);

    std::cout<<"received the string value"<<std::endl;
    if (iss >> value)
    {
        std::cout<<"received the double value"<<std::endl;
        m_engine.SetPressure(value);
    }
}

crow::json::wvalue Driver::GetPatientStatus()
{
    return m_engine.GetPatientStatus();
}

int main()
{
    Driver driver;
    

    std::cout<<"HELLO HERE!!!"<<std::endl;
    driver.Initialize();
    driver.Run();
}
