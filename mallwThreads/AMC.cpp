#include "AMC.h"
void AMC::AcceptCustomer(const Customer& customer)
{
    if (m_customers.size() >= 20)
    {
        m_waitingQueue.push(customer);
        return;
    }

    m_customers.push(customer);
}


Customer AMC::GetNextCustomer() const
{
    return m_customers.front();
}

void AMC::ServeCustomer()
{

    while (!m_shutDown)
    {
        std::unique_lock lock{ m_customerLock }; 
        m_condition.wait(lock, [&] {
            return QueueReady();
            });

        Customer customer{ GetNextCustomer() }; 

        m_customers.pop(); 

        m_customerLock.unlock();

        AddRev(customer.m_requestMovie.m_price);

        if (m_customers.empty())
        {
            ToggleReady();
        }


        if (GetRev() < 1000)
        {
            continue;
        }
        else
        {
            ConsultOwner();
        }
    }
}

void AMC::FillQueue() // func for bouncer thread
{
    while (!m_shutDown)
    {
        if (m_customers.empty() && !QueueReady())
        {
            std::lock_guard<std::mutex> lock(m_customerLock);
            for (int i{}; i < 10; i++)
            {
                m_customers.push(m_waitingQueue.front());
                m_waitingQueue.pop();
            }
            ToggleReady();

        }
        m_condition.notify_one();
    }



}