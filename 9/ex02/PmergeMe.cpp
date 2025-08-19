#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>

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

/*
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
}*/

// Returns the insertion order of group indices for Ford-Johnson
std::vector<int> ford_johnson_group_order(int num_groups) {
    std::vector<int> order;
    if (num_groups == 0) return order;
    if (num_groups >= 2) order.push_back(1); // group 1 (b3)
    order.push_back(0); // group 0 (b2)
    int k = 2;
    while (true) {
        int idx = (1 << k) - 1; // Jacobsthal numbers: 1, 3, 5, 11, ...
        if (idx >= num_groups) break;
        order.push_back(idx);
        ++k;
    }
    // Fill in the rest in order, skipping already used
    for (int i = 0; i < num_groups; ++i) {
        bool used = false;
        for (size_t j = 0; j < order.size(); ++j) {
            if (order[j] == i) {
                used = true;
                break;
            }
        }
        if (!used) order.push_back(i);
    }
    return order;
}

// Converts group order to last indices in pend
std::vector<int> ford_johnson_representative_indexes(int pend_size, int group_size) {
    int num_groups = pend_size / group_size;
    std::vector<int> group_order = ford_johnson_group_order(num_groups);
    std::vector<int> rep_indexes;
    for (size_t i = 0; i < group_order.size(); ++i) {
        rep_indexes.push_back(group_order[i] * group_size + (group_size - 1));
    }
    return rep_indexes;
}

// Compare two groups in main and pend, return -1 if group1 < group2, 0 if equal, 1 if group1 > group2
int compareGroups(const std::vector<unsigned int>& main, int mainGroupIdx,
                  const std::vector<unsigned int>& pend, int pendGroupStart,
                  int groupSize)
{
    unsigned int mainLast = main[mainGroupIdx * groupSize + groupSize - 1];
    unsigned int pendLast = pend[pendGroupStart + groupSize - 1];

    if (mainLast < pendLast)
        return -1;
    else if (mainLast > pendLast)
        return 1;
    return 0;
}


void binaryInsertion(std::vector<unsigned int>& main, const std::vector<unsigned int>& pend, int orderIndex, int groupSize, int upperBound)
{
    // Find the group in pend to insert
    int pendGroupStart = orderIndex - groupSize + 1;

    // Calculate the number of groups in main up to upperBound
    int numGroups = upperBound / groupSize;

    int left = 0;
    int right = numGroups;

    // Binary search over group indices
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int cmp = compareGroups(main, mid, pend, pendGroupStart, groupSize);
        if (cmp < 0)
            left = mid + 1;
        else
            right = mid;
    }

    // Insert the group at position 'left'
    main.insert(main.begin() + left * groupSize, pend.begin() + pendGroupStart, pend.begin() + pendGroupStart + groupSize);
}

std::vector<int> ford_johnson_group_order2(int num_groups) {
    std::vector<int> order;
    if (num_groups == 0) return order;
    if (num_groups >= 2) order.push_back(1); // group 1 (b3)
    order.push_back(0); // group 0 (b2)
    int k = 2;
    while (true) {
        int idx = (1 << k) - 1; // Jacobsthal numbers: 1, 3, 5, 11, ...
        if (idx >= num_groups) break;
        order.push_back(idx);
        ++k;
    }
    // Fill in the rest in order, skipping already used
    for (int i = 0; i < num_groups; ++i) {
        bool used = false;
        for (size_t j = 0; j < order.size(); ++j) {
            if (order[j] == i) {
                used = true;
                break;
            }
        }
        if (!used) order.push_back(i);
    }
    return order;
}

void	PmergeMe::sequenceInsertions(std::vector<unsigned int> &vector, int &groupSize, int recursionLevel)
{
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
	{
		_vector = vector;
		std::cout << "\nexiting sequence insertions\n";
		return ;
	}
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
	std::cout  << std::endl;
	std::vector<int> order;
	if (pend.size())
	{
		order = ford_johnson_representative_indexes(pend.size(), groupSize);
		std::cout << "insertion \norder = ";
		for (size_t i = 0; i < order.size(); ++i)
		{
			std::cout << order[i];
			if (i != order.size() - 1)
				std::cout << ", ";
		}
	}
	std::cout  << std::endl;

std::vector<int> groupOrder = ford_johnson_group_order(pend.size() / groupSize);
		std::cout << "group \norder = ";
		for (size_t i = 0; i < groupOrder.size(); ++i)
		{
			std::cout << groupOrder[i];
			if (i != groupOrder.size() - 1)
				std::cout << ", ";
		}
		std::cout  << std::endl << std::endl;
std::vector<unsigned int> aMainIndexesOrdered;
for (size_t i = 0; i < groupOrder.size(); ++i) {
    aMainIndexesOrdered.push_back(aMainIndexes[groupOrder[i]]);
}
	printVector(aMainIndexesOrdered, "a's main indexes ORDERED for b's in pend", 1);
//	std::vector<unsigned int> aMainIndexesOrdered;
//	for (size_t i = 0; i < order.size(); ++i) {
//		int groupIdx = (order[i] - (groupSize - 1)) / groupSize;
//		aMainIndexesOrdered.push_back(aMainIndexes[groupIdx]);
//	}

	// 2. binary insert each element until hemos acabdo de recorrer el pend
	size_t	insertedElements = 0; // b1 already in main
	int	i = 0;

	while ( insertedElements < pend.size() / groupSize)
	{
		binaryInsertion(main, pend, order[i], groupSize, aMainIndexesOrdered[i]);
		insertedElements++;
		i++;
	}


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
	if (this != &var)
	{
		_vector = var._vector;
	}
	return (*this);
}	
