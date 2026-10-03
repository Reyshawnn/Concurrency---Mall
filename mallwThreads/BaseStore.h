#pragma once
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "Data.h"




struct Owner;


class BaseStore
{
public:
	virtual void ServeCustomer() = 0;
	virtual void AcceptCustomer(const Customer& customer,int maxSize);
	virtual void FillQueue();
	Customer GetNextCustomer() const;
	int GetRev() const;
	void ConsultOwner(); //Make a Owner Class
	void AddRev(int money);
	void setOwner(Owner& owner);
	void setMutex(std::mutex& ownerMutex);
	void PayOwner();
	bool QueueReady();
	void ToggleReady();
	void InitThreads();

	virtual ~BaseStore() = default;


protected:
	std::mutex* m_ownerMutex;
	std::queue<Customer> m_customers;
	std::queue<Customer> m_waitingQueue;
	std::condition_variable m_condition;
	std::mutex m_customerLock;



private:
	bool m_ready;
	bool m_shutDown;
	int m_rev;
	Owner* m_owner;
	
	
	
	
	

};

