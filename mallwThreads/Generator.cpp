#include "Generator.h"
void Generator::Generate() //maybe overhaul this with a huge pool of shoes and movies to pick from
{
	for (int i{}; i < 200; i++)
	{
		Customer customer{};
		customer.m_choice = CustomerChoice{ m_choiceRange(m_mt) };

		switch (customer.m_choice)
		{
		case CustomerChoice::Footlocker:
			customer.SetShoe(Shoe{ m_sizeRange(m_mt),m_shoePriceRange(m_mt),"Air","Jordan" });
			m_globalQueue.push(customer);
			break;

		case CustomerChoice::AMC:
			customer.SetMovie(Movie{ m_moviePriceRange(m_mt),120,"n/a" });
			m_globalQueue.push(customer);
			break;

		case CustomerChoice::Buffet:
			customer.SetSnack(Snack{ m_foodPriceRange(m_mt) });
			m_globalQueue.push(customer);
			break;


		}

	}
}

void Generator::Dispatch(FootLocker& fl, AMC& amc,Buffet& buffet)
{
	while (!m_globalQueue.empty())
	{
		switch (m_globalQueue.front().m_choice)
		{
		case CustomerChoice::Footlocker:
			fl.AcceptCustomer(m_globalQueue.front());
			m_globalQueue.pop();
			break;

		case CustomerChoice::AMC:
			amc.AcceptCustomer(m_globalQueue.front());
			m_globalQueue.pop();
			break;

		case CustomerChoice::Buffet:
			buffet.AcceptCustomer(m_globalQueue.front());
			m_globalQueue.pop();
			break;

		}
	}
}
