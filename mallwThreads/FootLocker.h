#pragma once
#include "Data.h"
#include "BaseStore.h"
#include <vector>
#include <queue>
#include <condition_variable>


class FootLocker : public BaseStore
{
public:
    FootLocker()
        :m_shoes{}
        
    {

    }

    void ServeCustomer();
    void PrintShoe(size_t index) const;
    void PrintShoes() const;
    void AcceptCustomer(const Customer& customer);
    void RemoveCustomer();
    void FillQueue();
    Customer GetNextCustomer() const;
   


private:
    bool m_shutDown;
    std::vector<Shoe>m_shoes{};
    std::queue<Customer> m_customers;
    std::queue<Customer> m_waitingQueue;
    std::condition_variable m_condition;
    std::mutex m_customerLock;
   



};

