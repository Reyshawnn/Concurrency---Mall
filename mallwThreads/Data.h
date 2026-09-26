#pragma once
#include <iostream>
#include "FootLocker.h"
#include "AMC.h"


enum class CustomerState
{
    active,
    done,
};


enum class CustomerChoice
{
    Footlocker,
    AMC,
    Buffet,
};


struct Snack
{
    float m_price{};
    std::string m_name{};
    
  
    friend std::ostream& operator<<(std::ostream& out, const Snack& snack);
};

 

struct Movie
{
    int m_minutes{};
    float m_price{};
    std::string m_name{};
    
     
    friend std::ostream& operator<<(std::ostream& out, const Movie& movie);
};


struct Shoe
{
    float m_size{};
    int m_price{};
    std::string m_name{};
    std::string m_brand{};
    
    friend std::ostream& operator<<(std::ostream& out, const Shoe& shoe);
};



struct Customer
{
    int m_age{};
    CustomerState m_state;
    CustomerChoice m_choice;
    std::string m_name{};
    Movie m_requestMovie{};
    Snack m_requestSnack{};
    Shoe m_requestShoe{};
    
    

    void SetShoe(Shoe&& shoe)
    {
        m_requestShoe = shoe;
    }

    void SetMovie(Movie&& movie)
    {
        m_requestMovie = movie;
    }

    void SetSnack(Snack&& snack)
    {
        m_requestSnack = snack;
    }


    void ChooseStore(FootLocker& foot,AMC& amc)
    {
        switch (m_choice)
        {
        case CustomerChoice::Footlocker:
            foot.AcceptCustomer(*this);
            break;

        case CustomerChoice::AMC:
            amc.AcceptCustomer(*this);
            break;
            
        }
    }



    friend std::ostream& operator<<(std::ostream& out, const Customer& customer);

    
};

struct Owner
{
    int m_rev;
    void TakeCut();

};

