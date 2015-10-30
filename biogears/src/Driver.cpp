#include "Driver.h"
#include "Connection.h"

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
    std::thread connectionThread([this]() { m_connection();  });
    std::thread engineThread    ([this]() { m_engine();  });

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

int main()
{
    Driver driver;

    driver.Initialize();
    driver.Run();
}
