#pragma once
#include <iostream>


enum class CustomerState
{
    active,
    done,
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
    Movie m_requestMovie{};
    Snack m_requestSnack{};
    Shoe m_requestShoe{};
    std::string m_name{};
    CustomerState m_state;

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

    friend std::ostream& operator<<(std::ostream& out, const Customer& customer);

    
};

struct Owner
{
    int m_rev;
    void TakeCut();

};

