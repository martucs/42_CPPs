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
	*this = var;
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

unsigned int jacobsthal(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    unsigned int j0 = 0;
    unsigned int j1 = 1;
    unsigned int jn = 0;
    for (int i = 2; i <= n; ++i)
    {
        jn = j1 + 2 * j0;
        j0 = j1;
        j1 = jn;
    }
    return jn;
}

// Returns the insertion order of group indices for Ford-Johnson
std::vector<unsigned int> ford_johnson_group_order(int num_groups)
{
    std::vector<unsigned int> order;
    std::vector<bool> used(num_groups, false);

    int prev = 1; // b3 is at index 1
    if (num_groups > 1)
    {
	order.push_back(1); // b3
	used[1] = true;
    }
    if (num_groups > 0)
    {
	order.push_back(0); // b2
	used[0] = true;
    }

    int k = 3;
    while (true)
    {
	int jac = jacobsthal(k);
	int idx = jac - 2;

	if (idx >= num_groups)
	    break;
	if (!used[idx])
	{
	    order.push_back(idx);
	    used[idx] = true;
	}
	for (int i = idx - 1; i > prev; --i)
	{
	    if (!used[i]) {
		order.push_back(i);
		used[i] = true;
	    }
	}
	prev = idx;
	++k;
    }
    // Insert remaining groups in reverse order
    for (int i = num_groups - 1; i >= 0; --i)
    {
	if (!used[i]) {
	    order.push_back(i);
	    used[i] = true;
	}
    }
    return (order);
}

// Converts group order to last indices in pend
std::vector<unsigned int> ford_johnson_representative_indexes(int pend_size, int group_size)
{
	int num_groups = pend_size / group_size;
	std::vector<unsigned int> group_order = ford_johnson_group_order(num_groups);

	std::vector<unsigned int> rep_indexes;
	for (size_t i = 0; i < group_order.size(); ++i)
		rep_indexes.push_back(group_order[i] * group_size + (group_size - 1));
	return (rep_indexes);
}

// Compare two groups in main and pend, return -1 if group1 < group2, 0 if equal, 1 if group1 > group2
int compareGroups(const std::vector<unsigned int>& main, int mainGroupIdx,
                  const std::vector<unsigned int>& pend, int pendGroupStart,
                  int groupSize)
{
    int mainStart = mainGroupIdx * groupSize;
    int pendStart = pendGroupStart;

    unsigned int mainLast = main[mainStart + groupSize - 1];
    unsigned int pendLast = pend[pendStart + groupSize - 1];

   /* std::cout << "  Comparing main group " << mainGroupIdx
              << " (last = " << mainLast << ")"
              << " with pend group starting at " << pendStart
              << " (last = " << pendLast << ")\n";*/

    if (mainLast < pendLast) return -1;
    if (mainLast > pendLast) return 1;
    return 0;
}


void printGroup(const std::vector<unsigned int>& vec, int start, int groupSize, const std::string& name)
{
    std::cout << name << " group: [";
    for (int i = 0; i < groupSize; ++i)
    {
        std::cout << vec[start + i];
        if (i != groupSize - 1)
	    std::cout << ", ";
    }
    std::cout << "]\n";
}

int binaryInsertion(std::vector<unsigned int>& main, const std::vector<unsigned int>& pend, int orderIndex, int groupSize, int upperBound)
{
    // Find the group in pend to insert
    int pendGroupStart = orderIndex - groupSize + 1;

    // Calculate the number of groups in main up to upperBound
  //  int numGroups = upperBound / groupSize;
	int numGroups = (upperBound - groupSize + 1) / groupSize + 1;

    int left = 0;
    int right = numGroups;
    
	std::cout << "\ninserting with orderIndex = " << orderIndex << std::endl;	
	std::cout << "upperbound = " << upperBound << std::endl;	
	std::cout << "Inserting group from pend indices [" << pendGroupStart << " to " << pendGroupStart + groupSize - 1 << "]\n";
    printGroup(pend, pendGroupStart, groupSize, "Pend");
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
  std::cout << "Inserting at main group index: " << left << "\n";
    // Insert the group at position 'left'
    int insertPos = left * groupSize;
    main.insert(main.begin() + left * groupSize, pend.begin() + pendGroupStart, pend.begin() + pendGroupStart + groupSize);
	printVector(main, "main after insertion", groupSize);
    return (insertPos);
}

void	PmergeMe::sequenceInsertions(std::vector<unsigned int> &vector, int &groupSize, int recursionLevel)
{
	// create main chain
	// create pend chain (victor no los quita del pend despues de insertarlos en la main)
	// create non-participating chain
	// find insertion order with Jacobsthal nums
	// insertion loop 
		// binary insert each element (with its bound element) in the main
		// update numero de elementos insertados (b1 lo he instertado yo ya al principio, siempre cuenta)
		// luego hay que moverse ese numero de posiciones para ir al siguiente numero a insertar, a veces hacia el inicio del main, a veces hacia el final 
	        // muy importante keep track del upperbound / posicion de la a para cada b que insertamos (esta posicion cambia cada vez que insertamos un nuevo elemento, osea que se tiene que actualizar!!!) (yo lo hago con aMainIndexes)
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
	std::vector<unsigned int> order;
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

	// 2. binary insert each element until hemos acabdo de recorrer el pend
	size_t	insertedElements = 0; // b1 already in main
	int	i = 0;
	while ( insertedElements < pend.size() / groupSize)
	{
		int bGroupIdx = order[i] / groupSize; // 0 for b2, 1 for b3, etc.
		int pairedAIdx = bGroupIdx;           // a2 for b2, a3 for b3, etc.
		int upperBound = aMainIndexes[pairedAIdx];
//		int upperBound = aMainIndexes[i]; 
		int insertPos = binaryInsertion(main, pend, order[i], groupSize, upperBound);
		std::cout << "aMainIndexes before update: ";
		for(size_t idx = 0; idx < aMainIndexes.size() ; idx++)
			    std::cout << aMainIndexes[idx] << " ";
		std::cout << std::endl;	
		for (size_t j = 0; j < aMainIndexes.size(); ++j)
		{
		    if ((int)aMainIndexes[j] >= insertPos)
		    {
			aMainIndexes[j] += groupSize;
		    }
		}
		insertedElements++;
		i++;
		std::cout << "aMainIndexes after update: ";
		for(size_t idx = 0; idx < aMainIndexes.size() ; idx++)
			    std::cout << aMainIndexes[idx] << " ";
		std::cout << std::endl;
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
	int elementSize = 1;
	sortElements(_vector, elementSize);
	printVector(_vector, "after sortingg", 1);

	int recursionLevel = log2(elementSize) + 1;
	sequenceInsertions(_vector, elementSize, recursionLevel);
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &var)
{
	if (this != &var)
	{
		_vector = var._vector;
	}
	return (*this);
}	
