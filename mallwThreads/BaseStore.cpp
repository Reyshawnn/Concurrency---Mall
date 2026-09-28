#include "BaseStore.h"
#include "Data.h"

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
	int temp{ m_rev * 0.30 };
	m_owner->TakeCut(temp);
	m_rev -= temp;
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
	return ready;
}

void BaseStore::ToggleReady()
{
	if (ready)
	{
		ready = false;
	}
	else
	{
		ready = true;
	}
}
