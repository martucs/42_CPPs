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

void	sortElements(std::vector<int> &vector, int elementsAmount)
{
//	std::vector<int>::iterator	it = vector.begin();
//	std::vector<int>	sortedVec;
/*	int i = 0;
	while (it != vector.end())
	{
		if ((it + elementsAmount) != vector.end() && *it > *(it + elementsAmount))
		{
			std::cout << "swapping " << *it << " & " << *(it + elementsAmount) << " at pos " << i << std::endl;
//			std::swap(*it, *(it + elementsAmount));
			sortedVec.push_back(*(it + elementsAmount));
			sortedVec.push_back(*it);
//			std::cout << "[" << i << "] = " << *it << std::endl;
//			std::cout << "[" << i + elementsAmount << "] = " << *(it + elementsAmount) << std::endl;
		}
		else
			sortedVec.push_back(*it);
		i++;
		it += elementsAmount;
	}*/
	int n = vector.size();
	int groupSize = elementsAmount;

	for (int i = 0; i + 2 * groupSize - 1 < n; i += 2 * groupSize)
	{
		int firstGroupStart = i;
		int secondGroupStart = i + groupSize;

		int firstGroupLast = firstGroupStart + groupSize - 1;
		int secondGroupLast = secondGroupStart + groupSize - 1;

		// Compare the last elements of each group
		if (vector[firstGroupLast] > vector[secondGroupLast])
		{
			// Swap the entire groups
			for (int j = 0; j < groupSize; ++j)
			{
				std::swap(vector[firstGroupStart + j], vector[secondGroupStart + j]);
			}
		}
	}
}

void	PmergeMe::vectorMergeInsertion(std::vector<int> &input)
{
	std::size_t	elementsAmount = 1;
	int		recursionLevel = 0;

	for (int i = 0; i < recursionLevel; ++i) 
	{
		elementsAmount *= 2;
	}
	std::cout << "elements amount = " << elementsAmount << std::endl;
	if (input.size() < elementsAmount)
	{
		std::cout << "\nstopping recursion!\n";
		return ;
	}
	sortElements(input, elementsAmount);
	printVector(input, "After sorting", 1);
	elementsAmount *=2;
	std::cout << std::endl;

	std::cout << "elements amount = " << elementsAmount << std::endl;
	sortElements(input, elementsAmount);
	printVector(input, "After sorting 2nd time", 1);	
	elementsAmount *=2;
	std::cout << std::endl;
	
	std::cout << "elements amount = " << elementsAmount << std::endl;
	sortElements(input, elementsAmount);
	printVector(input, "After sorting 3rd time", 1);


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
