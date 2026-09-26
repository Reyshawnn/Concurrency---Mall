#pragma once
#include "Data.h"
#include <vector>
#include <queue>
#include "Base.h"
#include <thread>
#include <mutex>


class FootLocker : public BaseStore
{
public:
    FootLocker()
        :m_shoes{}
        
    {

    }

    void ServeCustomer() override;
    void PrintShoe(size_t index) const;
    void PrintShoes() const;
    void AcceptCustomer(const Customer& customer);
    void RemoveCustomer();
    void FillQueue();

    Customer GetNextCustomer() const;
   


private:
    
    std::vector<Shoe>m_shoes{};
    std::queue<Customer> m_customers;
    std::queue<Customer> m_waitingQueue;
    std::mutex m_customerLock;
    bool m_shutDown;
    



};

