#pragma once
#include "BaseStore.h"
#include <vector>




class FootLocker : public BaseStore
{
public:
    FootLocker()
        :m_shoes{}
        
    {

    }

    
    void PrintShoe(size_t index) const;
    void PrintShoes() const;
    void RemoveCustomer();
    void ServeCustomer() override;
    
   


private:
    std::vector<Shoe>m_shoes{};
  
   



};

