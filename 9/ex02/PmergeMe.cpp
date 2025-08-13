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

void	PmergeMe::sortElements(std::vector<unsigned int> &vector, int &groupSize)
{
	if (vector.size() < (size_t)groupSize)
	{
		std::cout << "stopping recursion after groupsize " << groupSize / 2 << std::endl;
		groupSize = groupSize / 2;
		return ;
	}
	// como vamos a mirar en grupos de elementos, iteramos hasta que podamos ver 2 grupos
	// si hay numeros sueltos o se acaba el vector, salimos del bucle
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
	groupSize *= 2;
	sortElements(vector, groupSize);
}

void	PmergeMe::sequenceInsertions(std::vector<unsigned int> &vector, int &groupSize, int recursionLevel)
{
	(void)vector;
	(void)recursionLevel;
	(void)groupSize;
	// name each element and their bound element (b1 - a1)
	// create main chain
	// create pend chain (victor no los quita del pend despues de insertarlos en la main)
	// create non-participating chain
	// find insertion order with Jacobsthal nums
	// insertion loop 
		// binary insert each element (with its bound element) in the main
		// update numero de elementos insertados (b1 lo he instertado yo ya al principio, siempre cuenta)
		// eso es = num de elementos insertados * groupSize
		// luego hay que moverse ese numero de posiciones para ir al siguiente numero a insertar, a veces hacia el inicio del main, a veces hacia el final 
	// 
	std::cout << "groupSize = " << groupSize << std::endl;
	if (vector.size() < (size_t)groupSize * 2)
	{
		groupSize = groupSize / 2;
		recursionLevel -= 1;
		std::cout << "nothing to be done in this level, entering recursion\n";
		sequenceInsertions(vector, groupSize, recursionLevel);
		return ;
	}
	std::vector<unsigned int> main; 
	std::vector<unsigned int> pend; 
	std::vector<unsigned int> aMainIndexes; 
	std::vector<unsigned int> nonParticipating; 

	int n = static_cast<int>(vector.size());

	for (int i = 0; i + groupSize - 1 < n; i += groupSize * 2)
	{
		int bStart = i;
		int aStart = i + groupSize;

		if (i == 0) // automatically copy b1 to main
		{
			for (int j = 0; j < groupSize; ++j)
			{
				std::cout << "adding " << vector[bStart + j] << " to main\n";
				main.push_back(vector[bStart + j]);
			}
		}
		// Copy all b's (first group)
		for (int j = 0; i != 0 && j < groupSize; ++j)
		{
			std::cout << "adding " << vector[bStart + j] << " to pend\n";
			pend.push_back(vector[bStart + j]);
		}

		if (i != 0)
			aMainIndexes.push_back(main.size()); // aun no hemos añadido las a's al main, solo hay b1, asi que el final del main es el inicio de la proxima a que se va a insertar, que es lo que nos queremos guardar
		// Copy all a's (second group)
		for (int j = 0; j < groupSize; ++j)
		{
			std::cout << "adding " << vector[aStart + j] << " to main\n";
			main.push_back(vector[aStart + j]);
		}
		std::cout << " --- next " << groupSize * 2 << " numbers ---\n";
	}

	// Handle leftover elements that don't form a full pair of groups
	int leftover = n % (2 * groupSize);
	if (leftover > 0)
	{
		int start = n - leftover;
		// These leftover elements don't have pairs, so add them to main
		for (int i = start; i < n; ++i)
		{
			std::cout << "adding " << vector[i] << " to main\n";
			main.push_back(vector[i]);
		}
	}
	printVector(main, "main", 1);
	printVector(pend, "pend", 1);
	printVector(aMainIndexes, "a's main indexes for b's in pend", 1);
	printVector(nonParticipating, "non part", 1);

}

void	PmergeMe::vectorMergeInsertion()
{
	/*std::size_t	elementSize = 1;
	int		recursionLevel = 0;

	for (int i = 0; i < recursionLevel; ++i) 
	{
		elementSize *= 2;
	}*/
	int elementSize = 1;
	sortElements(_vector, elementSize);
	printVector(_vector, "after sortingg", 1);

	int recursionLevel = log2(elementSize) + 1;
	std::cout << "\ngroup size = " << elementSize << std::endl;
	std::cout << "recursion level = " << recursionLevel << std::endl;

//	elementSize = 2;
//	recursionLevel = 3;
	sequenceInsertions(_vector, elementSize, recursionLevel);
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &var)
{
	(void)var;
/*	if (this != &var)
	{
	}*/
	return (*this);
}	
