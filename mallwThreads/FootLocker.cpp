#include "FootLocker.h" 

void FootLocker::PrintShoe(size_t index) const
{
    std::cout << m_shoes.at(index);
}


void FootLocker::PrintShoes() const
{
    for (auto& shoes : m_shoes)
    {
        std::cout << shoes << "\n";
    }
}


void FootLocker::ServeCustomer()
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

        AddRev(customer.m_requestShoe.m_price);

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

