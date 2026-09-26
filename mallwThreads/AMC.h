#pragma once
#include "Data.h"
#include <vector>
#include "Base.h"
#include <thread>
#include <mutex>

class AMC : public BaseStore
{
public:
    AMC()
        :m_filmPlaying{},
        m_snackbar{},
        m_customers{}
        
    {

    }


    

    void PrintFilms() const
    {
        for (auto& film : m_filmPlaying)
        {
            std::cout << film << "\n";
        }
    }

    void PrintSnacks() const
    {
        for (auto& snack : m_snackbar)
        {
            std::cout << snack << "\n";
        }
    }

    void PrintCustomers() const
    {
        for (auto& customer : m_customers)
        {
            std::cout << customer << "\n";
        }
    }

    void printFilm(size_t index) const
    {
        std::cout << m_filmPlaying.at(index);
    }

    void AcceptCustomer(const Customer& customer)
    {
        m_customers.push_back(customer);
    }




private:
    std::thread m_theatreThread;
    std::vector<Movie>m_filmPlaying{};
    std::vector<Snack> m_snackbar{};
    std::vector<Customer>m_customers{};
    std::mutex m_customerLock;
};

