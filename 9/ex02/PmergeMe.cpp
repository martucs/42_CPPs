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

std::vector<int>	getJacobsthalInsertionOrder(int numGroups)
{
	std::vector<int> jacobIndices;
	int k = 3;
	// Collect all Jacobsthal indices <= numGroups + 1 (since pend[0] is b2)
	while (getJacobsthalAt(k) <= numGroups + 1) {
		jacobIndices.push_back(getJacobsthalAt(k) - 2); // shift for pend indexing
		++k;
	}

	std::vector<int> order;
	int prev = numGroups; // Start after the last group

	// Go through Jacobsthal indices in reverse (from largest to smallest)
	for (int i = jacobIndices.size() - 1; i >= 0; --i) {
		int idx = jacobIndices[i];
		if (idx >= 0 && idx < numGroups)
			order.push_back(idx);

		// Insert all indices between prev-1 and idx+1 in descending order
		for (int j = prev - 1; j > idx; --j) {
			if (j >= 0 && j < numGroups)
				order.push_back(j);
		}
		prev = idx;
	}
	// After all blocks, insert any remaining indices down to 0 (if not already inserted)
	for (int j = prev - 1; j >= 0; --j) {
		order.push_back(j);
	}
	return order;
}

/*
// Lookup table for Ford-Johnson group order for up to 8 groups
const int fj_group_order[][8] = {
    {}, // 0 groups
    {0}, // 1 group: b2
    {1, 0}, // 2 groups: b3, b2
    {1, 0, 2}, // 3 groups: b3, b2, b4
    {2, 3, 1, 0}, // 4 groups: b5, b4, b3, b2
    {2, 3, 1, 0, 4}, // 5 groups: b5, b4, b3, b2, b6
    {4, 5, 2, 3, 1, 0}, // 6 groups: b7, b6, b5, b4, b3, b2
    {4, 5, 2, 3, 1, 0, 6}, // 7 groups: b7, b6, b5, b4, b3, b2, b8
    {6, 7, 4, 5, 2, 3, 1, 0} // 8 groups: b11, b10, b9, b8, b7, b6, b5, b4
};

std::vector<int> fj_b_to_pend_indexes(int pend_size, int group_size) {
    int num_groups = pend_size / group_size;
    std::vector<int> index_order;
    for (int i = 0; i < num_groups; ++i) {
        int group = fj_group_order[num_groups][i];
        int group_start = group * group_size;
        for (int j = 0; j < group_size; ++j) {
            index_order.push_back(group_start + j);
        }
    }
    // Add any leftover elements
    for (int i = num_groups * group_size; i < pend_size; ++i) {
        index_order.push_back(i);
    }
    return index_order;
}*/


// Generate Jacobsthal numbers up to n (inclusive)
std::vector<int> jacobsthal_up_to(int n) {
    std::vector<int> jacob;
    jacob.push_back(0); // J(0)
    jacob.push_back(1); // J(1)
    while (true) {
        int next = jacob.back() + 2 * jacob[jacob.size() - 2];
        if (next > n)
            break;
        jacob.push_back(next);
    }
    return jacob;
}

// Generate Ford-Johnson insertion order for group representatives
std::vector<int> ford_johnson_representative_indexes(int pend_size, int group_size)
{
    int num_groups = pend_size / group_size;
    std::vector<int> jacob = jacobsthal_up_to(num_groups);

    std::vector<int> order;
    std::vector<bool> used(num_groups, false);

    // Always start with Jacobsthal 3 (b3, which is group 1)
    if (num_groups >= 2) {
        order.push_back(1); // group 1 (b3)
        used[1] = true;
    }
    if (num_groups >= 1) {
        order.push_back(0); // group 0 (b2)
        used[0] = true;
    }

    // Now process further Jacobsthal intervals
    for (int j = 3; j < (int)jacob.size(); ++j) {
        int high = jacob[j];
        int low = jacob[j-1];
        for (int i = high - 1; i >= low; --i) {
            if (i < num_groups && !used[i]) {
                order.push_back(i);
                used[i] = true;
            }
        }
    }
    // Insert remaining groups in reverse order
    for (int i = num_groups - 1; i >= 0; --i) {
        if (!used[i]) {
            order.push_back(i);
            used[i] = true;
        }
    }

    // Convert group indexes to representative indexes in pend
    std::vector<int> rep_indexes;
    for (size_t k = 0; k < order.size(); ++k) {
        int last_idx = (order[k] + 1) * group_size - 1;
        rep_indexes.push_back(last_idx);
    }
    return rep_indexes;
}

void	PmergeMe::sequenceInsertions(std::vector<unsigned int> &vector, int &groupSize, int recursionLevel)
{
	(void)recursionLevel;
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
	std::cout << "\ngroupSize = " << groupSize << std::endl;
	if (groupSize < 1 )
		return ;
	if (vector.size() < (size_t)groupSize * 2)
	{
		groupSize = groupSize / 2;
		recursionLevel -= 1;
		std::cout << "nothing to be done in this level, entering recursion\n";
		sequenceInsertions(vector, groupSize, recursionLevel);
		return ;
	}
	printVector(vector, "sequence", groupSize);
	std::cout << std::endl;
	std::vector<unsigned int> main; 
	std::vector<unsigned int> pend; 
	std::vector<unsigned int> aMainIndexes; 
	std::vector<unsigned int> nonParticipating; 

	int n = static_cast<int>(vector.size());
	int lastPosition = -1;


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

		bool hasAGroup = (aStart + groupSize - 1 < n);
		// Copy all a's (second group)
		int j;
		for (j = 0; j < groupSize; ++j)
		{
			if (aStart + groupSize > n)
			{
				std::cout << "I enter break\n";
				if (i != 0)
					aMainIndexes.push_back(main.size() - 1);
				break;
			}
			std::cout << "adding " << vector[aStart + j] << " to main\n";
			main.push_back(vector[aStart + j]);
		}
		if (j < groupSize)
		{
			lastPosition = i + (groupSize - j * 2) - 1;
			break;
		}
		if (i != 0)
		{
			if (hasAGroup)
				aMainIndexes.push_back(main.size() - 1); // last element of the just-inserted a group
			else
				aMainIndexes.push_back(main.size() - 1); // last element in main (no a group)
		}
		lastPosition = i + (groupSize * 2) - 1;
		std::cout << " --- next " << groupSize * 2 << " numbers ---\n";
	}
	std::cout << "exited loop\n";
	if (lastPosition + 1 < n)
	{
		for (int i = lastPosition + 1; i < n; ++i)
		{
			std::cout << "adding leftover " << vector[i] << " to non part\n";
			nonParticipating.push_back(vector[i]);
		}
	}

	std::cout << "\nBEFORE INSERTION" << std::endl;
	printVector(main, "main", groupSize);
	printVector(pend, "pend", groupSize);
	printVector(nonParticipating, "non part", groupSize);
	printVector(aMainIndexes, "a's main indexes for b's in pend", 1);

	// DO INSERTION
	// 1. find insertion order with jacobsthal sequence
	// 2. binary insert each element until hemos acabdo de recorrer el pend
/*	int	insertedElements = 1; // b1 already in main
	int	jacobsthalPos = 3;
	int	elementInsertionPos = (getJacobsthalAt(jacobsthalPos) * groupSize - (insertedElements * groupSize)) - 1;
	for (size_t i = 0; i < pend.size() / groupSize; i++)
	{
		elementInsertionPos = (getJacobsthalAt(jacobsthalPos) * groupSize - (insertedElements * groupSize)) - 1;
		std::cout << "Jacobsthal ->" << getJacobsthalAt(jacobsthalPos) << std::endl;
		std::cout << "should insert elements in pend in pos ->" << elementInsertionPos << std::endl;
		while (elementInsertionPos >= pend.size())
		{
			elementInsertionPos--;
		}
		if (jacobsthalPos > pend.size())
		//if (getJacobsthalAt(jacobsthalPos) - 1 > pend.size())
			//

		jacobsthalPos++;
		//elementInsertionPos -= groupSize;
		insertedElements++;
	}*/

	std::cout  << std::endl;
	if (pend.size())
	{
		std::vector<int> order = ford_johnson_representative_indexes(pend.size(), groupSize);
		for (size_t i = 0; i < order.size(); ++i)
		{
			std::cout << order[i];
			if (i != order.size() - 1)
				std::cout << ", ";
		}
	}
	std::cout  << std::endl;

	std::cout << "\nAFTER INSERTION" << std::endl;
	printVector(main, "main", groupSize);
	printVector(pend, "pend", groupSize);
	printVector(nonParticipating, "non part", groupSize);
	printVector(aMainIndexes, "a's main indexes for b's in pend", 1);
	
	std::cout  << std::endl;
	// ADD leftover elements to main
	if (lastPosition + 1 < n)
	{
		for (int i = lastPosition + 1; i < n; ++i)
		{
			std::cout << "adding leftover " << vector[i] << " to main\n";
			main.push_back(vector[i]);
			nonParticipating.push_back(vector[i]);
		}
	}

	
	groupSize /= 2;
	recursionLevel -= 1;
	sequenceInsertions(main, groupSize, recursionLevel);
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
