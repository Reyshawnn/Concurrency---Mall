#pragma once
#include "Data.h"
#include <queue>
#include <thread>

class BaseStore
{
public:
	virtual void ServeCustomer() = 0;
	static void AcceptCustomer(const Customer& customer);
	int GetRev() const;
	void ConsultOwner(Owner& owner); //Make a Owner Class
	void AddRev(int money);

private:
	int m_rev;
	std::thread m_cashierThread;
	std::thread m_bouncerThread;
	
	

};

