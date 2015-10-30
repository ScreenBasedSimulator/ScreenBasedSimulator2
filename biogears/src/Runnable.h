#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <mutex>

class Runnable
{
public:
    void SetRunning(bool running);
    bool Running() const;

    virtual void operator()() = 0;

private:
    bool m_running = true;
    mutable std::mutex m_mutex;
};

#endif
