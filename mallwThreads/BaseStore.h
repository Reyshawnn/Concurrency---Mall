#pragma once
#include <thread>
#include <mutex>

struct Customer;
struct Owner;


class BaseStore
{
public:
	virtual void ServeCustomer() = 0;
	virtual void AcceptCustomer(const Customer& customer) = 0;
	int GetRev() const;
	void ConsultOwner(); //Make a Owner Class
	void AddRev(int money);
	void setOwner(Owner& owner);
	void setMutex(std::mutex& ownerMutex);
	void PayOwner();
	bool QueueReady();
	void ToggleReady();

private:
	bool ready;
	int m_rev;
	Owner* m_owner;
	std::mutex* m_ownerMutex;
	std::thread m_cashierThread;
	std::thread m_bouncerThread;
	
	
	

};

