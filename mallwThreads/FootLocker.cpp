#include "FootLocker.h"
void FootLocker::ServeCustomer()
{
    while (!m_shutDown)
    {
        std::unique_lock lock{ m_customerLock }; //cashier waiting till the queue has at least 10 customers
        m_condition.wait(lock, [&] {
            return QueueReady();
            });

        Customer customer{ GetNextCustomer() }; //Add move semantics to the customer

        m_customers.pop(); //add a pop function

        m_customerLock.unlock();

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

  

void FootLocker::PrintShoe(size_t index) const
{
    std::cout << m_shoes.at(index);
}

Customer FootLocker::GetNextCustomer() const
{
    return m_customers.front();
}

void FootLocker::PrintShoes() const
{
    for (auto& shoes : m_shoes)
    {
        std::cout << shoes << "\n";
    }
}

void FootLocker::FillQueue() // func for bouncer thread
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

 void FootLocker::AcceptCustomer(const Customer& customer)
{
     if (m_customers.size() >= 20)
     {
         m_waitingQueue.push(customer);
         return;
     }

    m_customers.push(customer);
}

void FootLocker::RemoveCustomer()
{
    m_customers.pop();
}