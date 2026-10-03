#pragma once
#include "Data.h"
#include "BaseStore.h"
#include <vector>
#include <queue>
#include <condition_variable>
class Buffet : public BaseStore
{

public:
    void ServeCustomer() override;




private:
    bool m_shutDown;
    std::vector<Snack>m_snacks{};
    
};

