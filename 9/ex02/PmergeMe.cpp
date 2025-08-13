#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe()
{
}
PmergeMe::PmergeMe(std::vector<unsigned int> &vector)
{
	_vector = vector;
}
PmergeMe::PmergeMe(const PmergeMe &var)
{
	(void)var;
}

PmergeMe::~PmergeMe()
{
}

std::vector<unsigned int>	PmergeMe::getVector() const
{
	return (_vector);
}

std::vector<std::pair<int, int> >	makePairs(std::vector<unsigned int> input)
{
	std::vector<std::pair<int, int> >	pairVector;
	std::vector<unsigned int>::iterator		it = input.begin();

	size_t i = 0;
	while (i < input.size() / 2 )
	{
		pairVector.push_back(std::make_pair(*it, *(it + 1)));
		it += 2;
		i++;
	}
	return (pairVector);
}

void	sortElements(std::vector<unsigned int> &vector, int groupSize)
{
	// como vamos a mirar en grupos de elementos, iteramos hasta que podamos ver 2 grupos
	// si hay numeros sueltos o se acaba el vector, salimos del bucle
	if (vector.size() < (size_t)groupSize)
	{
		std::cout << "stopping recursion at groupsize " << groupSize << std::endl;
		return ;
	}
	for (int i = 0; i + 2 * groupSize - 1 < (int)vector.size(); i += 2 * groupSize)
	{
		int firstGroupStart = i;
		int secondGroupStart = i + groupSize;

		int firstGroupLast = firstGroupStart + groupSize - 1;
		int secondGroupLast = secondGroupStart + groupSize - 1;

		if (vector[firstGroupLast] > vector[secondGroupLast])
		{
			// Swap de todos los numeros que forman cada elemento
			for (int j = 0; j < groupSize; ++j)
				std::swap(vector[firstGroupStart + j], vector[secondGroupStart + j]);
		}
	}
	sortElements(vector, groupSize * 2);
}

void	PmergeMe::vectorMergeInsertion()
{
	/*std::size_t	elementSize = 1;
	int		recursionLevel = 0;

	for (int i = 0; i < recursionLevel; ++i) 
	{
		elementSize *= 2;
	}*/
	sortElements(_vector, 1);
	printVector(_vector, "after sortingg", 1);

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
