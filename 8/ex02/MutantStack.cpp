#include "MutantStack.hpp"

MutantStack::MutantStack()
{
}

MutantStack::MutantStack(const MutantStack& var)
{
	*this = var;
}

MutantStack::~MutantStack()
{
}

MutantStack&	MutantStack::operator=(const MutantStack& var)
{
	if (this != &var)
	{
	}
	return (*this);
}
