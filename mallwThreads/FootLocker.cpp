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
            return QueueReady() || m_shutDown;
            });

       // std::cout << "done waiting " << "\n";

        Customer customer{ GetNextCustomer() };

        m_customers.pop();

        if (m_customers.empty() && QueueReady())
        {
            ToggleReady(); //Toggle m_ready to false to trigger bouncer thread queue fill
        }

        lock.unlock();

        AddRev(customer.m_requestShoe.m_price);

       


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

