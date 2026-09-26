#include "FootLocker.h"
void FootLocker::ServeCustomer()
{
    while (!m_shutDown)
    {
        while (m_customers.empty())
        {
            //wait or sleep
        }


        while (!m_customers.empty())
        {

            m_customerLock.lock();

            Customer customer{ GetNextCustomer() }; //Add move semantics to the customer

            m_customers.pop(); //add a pop function

            m_customerLock.unlock();

            Shoe shoe{ customer.m_requestShoe };

            AddRev(shoe.m_price);








        }

        if (GetRev() == 0)
        {
            continue;
        }
        else
        {
            //consult owner
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
    
    

}

void FootLocker::AcceptCustomer(const Customer& customer)
{


    m_customers.push(customer);
}

void FootLocker::RemoveCustomer()
{
    m_customers.pop();
}