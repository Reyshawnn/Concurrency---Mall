#pragma once
#include "Data.h"
#include "BaseStore.h"
#include <vector>
#include <queue>
#include <condition_variable>
class Buffet : public BaseStore
{

public:

private:
    bool m_shutDown;
    std::vector<Shoe>m_shoes{};
    std::queue<Customer> m_customers;
    std::queue<Customer> m_waitingQueue;
    std::condition_variable condition;
    std::mutex m_customerLock;
};

