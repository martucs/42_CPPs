#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &var)
{
	(void)var;
}

PmergeMe::~PmergeMe()
{
}

std::vector<std::pair<int, int> >	makePairs(std::vector<int> input)
{
	std::vector<std::pair<int, int> >	pairVector;
	std::vector<int>::iterator		it = input.begin();

	size_t i = 0;
	while (i < input.size() / 2 )
	{
		pairVector.push_back(std::make_pair(*it, *(it + 1)));
		it += 2;
		i++;
	}
	return (pairVector);
}

void	printPairVector(std::vector<std::pair<int, int> > pairVector, std::string info)
{
	std::cout << info << std::endl;
	for (size_t i = 0; i < pairVector.size(); i++)
	{
		std::cout << "(" << pairVector[i].first << ", " << pairVector[i].second << ")\n";
	}
}

void	sortPairs(std::vector<std::pair<int, int> > &pairVector)
{
	for (size_t i = 0; i < pairVector.size(); i++)
	{
		if (pairVector[i].first > pairVector[i].second)
			std::swap(pairVector[i].first, pairVector[i].second);
	}
}

void	PmergeMe::calculate(std::vector<int> &input)
{
	std::vector<std::pair<int, int> >	pairVector;

	if (input.size() <= 2)
		return ;
	pairVector = makePairs(input);
	printPairVector(pairVector, "Before sorting");
	
	std::cout << std::endl;
	sortPairs(pairVector);
	printPairVector(pairVector, "After sorting");

//	calculate(pairVector);
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &var)
{
	(void)var;
/*	if (this != &var)
	{
	}*/
	return (*this);
}	
