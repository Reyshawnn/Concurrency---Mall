#include "Base.h"

void BaseStore::AddRev(int money)
{
	m_rev += money;
}

int BaseStore::GetRev() const
{
	return m_rev;
}