#include "Buffet.h"

void Buffet::ServeCustomer()
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

        AddRev(customer.m_requestSnack.m_price);

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