#pragma once
#include "BaseStore.h"
#include <vector>





class AMC : public BaseStore
{
public:
    AMC()
        :m_filmPlaying{},
        m_snackbar{}
    {

    }


    void ServeCustomer() override;
    
 
    




private:
   
    std::vector<Movie>m_filmPlaying{};
    std::vector<Snack> m_snackbar{};
  
   
};

