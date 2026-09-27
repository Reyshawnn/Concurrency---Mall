#pragma once
#include <iostream>
#include <random>
#include <queue>
#include "Data.h"
#include "Buffet.h"

class Generator
{
public:
	void Generate();
	void Dispatch(FootLocker& ft, AMC& amc, Buffet& buffet);

private:
	std::uniform_int_distribution<int> m_choiceRange{ 0, 2 };
	std::uniform_int_distribution<int> m_shoePriceRange{ 100,400 };
	std::uniform_int_distribution<float> m_sizeRange{ 9.5,12.0 };

	std::uniform_int_distribution<float> m_moviePriceRange{ 20,30 };
	std::uniform_int_distribution<int> m_foodPriceRange{ 100,400 };

	std::queue<Customer> m_globalQueue{};
	std::mt19937 m_mt{};
};

