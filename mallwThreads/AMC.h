#pragma once
#include "Data.h"
#include "BaseStore.h"
#include <vector>
#include <queue>
#include <condition_variable>



class AMC : public BaseStore
{
public:
    AMC()
        :m_filmPlaying{},
        m_snackbar{},
        m_customers{}
        
    {

    }


    void ServeCustomer();
    void AcceptCustomer(const Customer& customer);
    void FillQueue();
    Customer GetNextCustomer() const;
    




private:
    bool m_shutDown;
    std::thread m_theatreThread{};
    std::vector<Movie>m_filmPlaying{};
    std::vector<Snack> m_snackbar{};
    std::queue<Customer>m_customers{};
    std::queue<Customer>m_waitingQueue{};
    std::mutex m_customerLock{};
    std::condition_variable m_condition;
};

