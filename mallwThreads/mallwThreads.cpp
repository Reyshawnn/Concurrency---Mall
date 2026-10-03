// jobsysV1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <typeinfo>
#include <functional>
#include <utility>
#include "Data.h"
#include "Generator.h"
#include "BaseStore.h"
#include "FootLocker.h"
#include "AMC.h"
#include "Buffet.h"

//Mall example 
/*
Each store has to run concurrently and has its own items and procedures regarding them
*/






int main()
{
    Generator gen{};
    AMC movieTheatre{};
    FootLocker shoeVendor{};
    Buffet buff{};

    gen.Generate();
    gen.Dispatch(shoeVendor,movieTheatre,buff);

    //Threads for AMC
    std::thread AMcashierThread(&BaseStore::ServeCustomer,&movieTheatre);
    std::thread AMbouncerThread(&BaseStore::FillQueue, &movieTheatre);

    //Threads for FootLocker
    std::thread FLcashierThread(&BaseStore::ServeCustomer, &shoeVendor);
    std::thread FLbouncerThread(&BaseStore::FillQueue, &shoeVendor);

    AMcashierThread.join();
    AMbouncerThread.join();

    FLcashierThread.join();
    FLbouncerThread.join();

    


}

