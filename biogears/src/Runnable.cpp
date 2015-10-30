#include "Runnable.h"

void Runnable::SetRunning(bool running)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_running = running;
}

bool Runnable::Running() const
{
    std::lock_guard<std::mutex> lock(m_mutex);

    return m_running;
}
