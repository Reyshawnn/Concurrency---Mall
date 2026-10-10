#include "AMC.h"
void AMC::ServeCustomer()
{

    while (!m_shutDown)
    {
        std::unique_lock lock{ m_customerLock };
        m_condition.wait(lock, [&] {
            return QueueReady() || m_shutDown;
            });

        Customer customer{ GetNextCustomer() };

        m_customers.pop();

        if (m_customers.empty() && QueueReady())
        {
            ToggleReady(); //Toggle m_ready to false to trigger bouncer thread queue fill
        }

        lock.unlock();

        AddRev(customer.m_requestMovie.m_price);


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

