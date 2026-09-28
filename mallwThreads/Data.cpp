#include "Data.h"
#include "FootLocker.h"
#include "AMC.h"
#include "Buffet.h"
void Customer::ChooseStore(FootLocker & foot, AMC & amc, Buffet & buffet)
{
    switch (m_choice)
    {
    case CustomerChoice::Footlocker:
        foot.AcceptCustomer(*this);
        break;

    case CustomerChoice::AMC:
        amc.AcceptCustomer(*this);
        break;

    case CustomerChoice::Buffet:
        buffet.AcceptCustomer(*this);
        break;

    }
}

std::ostream& operator<<(std::ostream& out, const Snack& snack)
{
    out << "Name: " << snack.m_name << " Price: " << snack.m_price;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Movie& movie)
{
    out << "Name: " << movie.m_name << " Length of Movie (minutes): " << movie.m_minutes << " Price of Movie: " << movie.m_price;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Shoe& shoe)
{
    out << "Brand: " << shoe.m_brand << " Name: " << shoe.m_name << " size: " << shoe.m_size << " Price: " << shoe.m_price;
    return out;
}

std::ostream& operator<<(std::ostream& out, const Customer& customer)
{
    out << "Name: " << customer.m_name << " Age: " << customer.m_age;
    return out;
}

void Owner::TakeCut(int money)
{
    m_rev += money;
}
