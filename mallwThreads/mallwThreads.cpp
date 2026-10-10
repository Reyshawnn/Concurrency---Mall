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
    Owner owner{};
    std::mutex ownerMutex{};

    std::vector<BaseStore*> stores;

    stores.push_back(&movieTheatre);
    stores.push_back(&buff);
    stores.push_back(&shoeVendor);

    stores.at(0)->setType(1);
    stores.at(1)->setType(2);
    stores.at(2)->setType(0);

    for (auto& store : stores)
    {
        store->setOwner(owner);
        store->setMutex(ownerMutex);
    }


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

    
    owner.ReportTransactions();


}

