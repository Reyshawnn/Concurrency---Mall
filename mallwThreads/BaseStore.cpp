#include "BaseStore.h"


void BaseStore::AddRev(int money)
{
	m_rev += money;
}

int BaseStore::GetRev() const
{
	return m_rev;
}


void BaseStore::PayOwner()
{
	int temp = m_rev * 0.30; //handle int to float conversion
	m_owner->TakeCut(temp);
	m_rev -= temp;
	std::string msg{};

	switch (m_storeType)
	{
	case CustomerChoice::Footlocker:
		msg.append("Footlocker has paid the owner ");
		msg.append(std::to_string(temp));
		msg.append(" dollars");
		m_owner->buyLogs.push_back(msg);
		break;

	case CustomerChoice::AMC:
		msg.append("AMC has paid the owner ");
		msg.append(std::to_string(temp));
		msg.append(" dollars");
		m_owner->buyLogs.push_back(msg);
		break;

	case CustomerChoice::Buffet:
		msg.append("Buffet has paid the owner ");
		msg.append(std::to_string(temp));
		msg.append(" dollars");
		m_owner->buyLogs.push_back(msg);
		break;
	}

}



void BaseStore::ConsultOwner() //Make a Owner Class
{
	if (!m_owner || !m_ownerMutex)
	{
		std::cout << "pointer is null" << "\n";
		return;
	}
	else
	{
		m_ownerMutex->lock();
		PayOwner();
		m_ownerMutex->unlock();

	}
}


void BaseStore::setOwner(Owner& owner)
{
	m_owner = &owner;
}


void BaseStore::setMutex(std::mutex& ownerMutex)
{
	m_ownerMutex = &ownerMutex;
}

bool BaseStore::QueueReady()
{
	return m_ready;
}

void BaseStore::ToggleReady()
{
	if (m_ready)
	{
		m_ready = false;
	}
	else
	{
		m_ready = true;
	}
}


//void BaseStore::ServeCustomer()
//{
//
//    while (!m_shutDown)
//    {
//        std::unique_lock lock{ m_customerLock };
//        m_condition.wait(lock, [&] {
//            return QueueReady();
//            });
//
//        Customer customer{ GetNextCustomer() };
//
//        m_customers.pop();
//
//        m_customerLock.unlock();
//
//        AddRev(customer.m_requestMovie.m_price);
//
//        if (m_customers.empty())
//        {
//            ToggleReady();
//        }
//
//
//        if (GetRev() < 1000)
//        {
//            continue;
//        }
//        else
//        {
//            ConsultOwner();
//        }
//    }
//}
//

void BaseStore::FillQueue() // func for bouncer thread
{
	/*std::cout << m_customers.size() << "\n";
	std::cout << QueueReady() << "\n";
	std::cout << m_waitingQueue.size() << "\n";*/
    while (!m_shutDown)
    {
		{
			std::lock_guard<std::mutex> lock(m_customerLock);
			if (m_customers.empty() && !QueueReady())
			{

				//std::cout << "filling q" << "\n";
				for (int i{}; i < 10; i++)
				{
					if (!m_waitingQueue.empty())
					{
						m_customers.push(m_waitingQueue.front());
						m_waitingQueue.pop();
					}
					else
					{
						std::cout << "out of waiting customers " << "\n";
						m_shutDown = true;
						break;
					}
					
				}
				ToggleReady();
				//std::cout << QueueReady() << "\n";

			}
			else if (m_waitingQueue.empty())
			{
				std::cout << "out of waiting customers " << "\n";
				m_shutDown = true;
			}
			m_condition.notify_one();
		}
        
    }



}

Customer BaseStore::GetNextCustomer() const
{
    return m_customers.front();
}


void BaseStore::AcceptCustomer(const Customer& customer, int maxSize)
{
    if (m_customers.size() == maxSize)
    {
        m_waitingQueue.push(customer);
        return;
    }

    m_customers.push(customer);
}


void BaseStore::setType(int option)
{
	switch (option)
	{
	case 0:
		m_storeType = CustomerChoice::Footlocker;
		break;

	case 1:
		m_storeType = CustomerChoice::AMC;
		break;

	case 2:
		m_storeType = CustomerChoice::Buffet;
		break;
	}

}
