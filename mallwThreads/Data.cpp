#include "Data.h"
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
