#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>

PmergeMe::PmergeMe()
{
	_vecComparisons = 0;
	_deqComparisons = 0;
}

PmergeMe::PmergeMe(std::vector<unsigned int> &vector)
{
	_vector = vector;
	_vecComparisons = 0;
	_deqComparisons = 0;
}

PmergeMe::PmergeMe(std::deque<unsigned int> &deque)
{
	_deque = deque;
	_vecComparisons = 0;
	_deqComparisons = 0;
}

PmergeMe::PmergeMe(const PmergeMe &var)
{
	*this = var;
}

PmergeMe::~PmergeMe()
{
}

std::vector<unsigned int>&	PmergeMe::getVector()
{
	return (_vector);
}

std::deque<unsigned int>&	PmergeMe::getDeque()
{
	return (_deque);
}

int	PmergeMe::getVectorComparisons() const
{
	return (_vecComparisons);
}

int	PmergeMe::getDequeComparisons() const
{
	return (_deqComparisons);
}

void	PmergeMe::vectorMergeInsertion()
{
	int elementSize = 1;
	sortVecElements(_vector, elementSize);
	DEBUG_PRINT_CONTAINER(_vector, "after sortingg", 1);
	DEBUG_PRINT(std::endl);
	vecSequenceInsertions(_vector, elementSize);
}

void	PmergeMe::dequeMergeInsertion()
{
	int elementSize = 1;
	sortDeqElements(_deque, elementSize);
        DEBUG_PRINT_CONTAINER(_deque, "after sortingg", 1);
	DEBUG_PRINT(std::endl);
	deqSequenceInsertions(_deque, elementSize);
}

void	PmergeMe::sortVecElements(std::vector<unsigned int> &vector, int &groupSize)
{
	if (vector.size() < (size_t)groupSize)
	{
		DEBUG_PRINT( "stopping recursion after groupsize " << groupSize / 2 << std::endl);
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
		_vecComparisons++;
	}
	groupSize *= 2;
	sortVecElements(vector, groupSize);
}

void	PmergeMe::sortDeqElements(std::deque<unsigned int> &deque, int &groupSize)
{
	if (deque.size() < (size_t)groupSize)
	{
		DEBUG_PRINT( "stopping recursion after groupsize " << groupSize / 2 << std::endl);
		groupSize = groupSize / 2;
		return ;
	}
	for (int i = 0; i + 2 * groupSize - 1 < (int)deque.size(); i += 2 * groupSize)
	{
		int firstGroupStart = i;
		int secondGroupStart = i + groupSize;

		int firstGroupLast = firstGroupStart + groupSize - 1;
		int secondGroupLast = secondGroupStart + groupSize - 1;

		if (deque[firstGroupLast] > deque[secondGroupLast])
		{
			for (int j = 0; j < groupSize; ++j)
				std::swap(deque[firstGroupStart + j], deque[secondGroupStart + j]);
		}
		_deqComparisons++;
	}
	groupSize *= 2;
	sortDeqElements(deque, groupSize);
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
    return (jn);
}

// Returns the insertion order of group indices for Ford-Johnson
std::vector<unsigned int> vecFord_johnson_group_order(int num_groups)
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

std::deque<unsigned int> deqFord_johnson_group_order(int num_groups)
{
    std::deque<unsigned int> order;
    std::deque<bool> used(num_groups, false);

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

std::vector<unsigned int> vecInsertionOrder(int pend_size, int group_size)
{
	int num_groups = pend_size / group_size;
	std::vector<unsigned int> group_order = vecFord_johnson_group_order(num_groups);

	std::vector<unsigned int> rep_indexes;
	for (size_t i = 0; i < group_order.size(); ++i)
		rep_indexes.push_back(group_order[i] * group_size + (group_size - 1));
	return (rep_indexes);
}

std::deque<unsigned int> deqInsertionOrder(int pend_size, int group_size)
{
	int num_groups = pend_size / group_size;
	std::deque<unsigned int> group_order = deqFord_johnson_group_order(num_groups);

	std::deque<unsigned int> rep_indexes;
	for (size_t i = 0; i < group_order.size(); ++i)
		rep_indexes.push_back(group_order[i] * group_size + (group_size - 1));
	return (rep_indexes);
}

// Compare two groups in main and pend, return -1 if group1 < group2, 0 if equal, 1 if group1 > group2
int PmergeMe::compareVecGroups(const std::vector<unsigned int>& main, int mainGroupIdx, const std::vector<unsigned int>& pend, int pendGroupStart, int groupSize)
{
    int mainStart = mainGroupIdx * groupSize;
    int pendStart = pendGroupStart;

    unsigned int mainLast = main[mainStart + groupSize - 1];
    unsigned int pendLast = pend[pendStart + groupSize - 1];

   /* std::cout << "  Comparing main group " << mainGroupIdx
              << " (last = " << mainLast << ")"
              << " with pend group starting at " << pendStart
              << " (last = " << pendLast << ")\n";*/

    if (mainLast < pendLast)
    {
	_vecComparisons++;
	return -1;
    }
    if (mainLast > pendLast)
    {
	_vecComparisons++;
	return 1;
    }
    return 0;
}

int PmergeMe::compareDeqGroups(const std::deque<unsigned int>& main, int mainGroupIdx, const std::deque<unsigned int>& pend, int pendGroupStart, int groupSize)
{
    int mainStart = mainGroupIdx * groupSize;
    int pendStart = pendGroupStart;

    unsigned int mainLast = main[mainStart + groupSize - 1];
    unsigned int pendLast = pend[pendStart + groupSize - 1];

    if (mainLast < pendLast)
    {
	_deqComparisons++;
	return -1;
    }
    if (mainLast > pendLast)
    {
	_deqComparisons++;
	return 1;
    }
    return 0;
}

int PmergeMe::binaryInsertion(std::vector<unsigned int>& main, const std::vector<unsigned int>& pend, int orderIndex, int groupSize, int upperBound)
{
    int pendGroupStart = orderIndex - groupSize + 1;
    // Calculate the number of groups in main up to upperBound
    int numGroups = (upperBound - groupSize + 1) / groupSize + 1;
    int left = 0;
    int right = numGroups;

    DEBUG_PRINT("\ninserting with orderIndex = " << orderIndex << std::endl);
    DEBUG_PRINT("upperbound = " << upperBound << std::endl);	
    DEBUG_PRINT("Inserting group from pend indices [" << pendGroupStart << " to " << pendGroupStart + groupSize - 1 << "]\n");
    DEBUG_PRINT_GROUP(pend, pendGroupStart, groupSize, "Pend");
    while (left < right)
    {
	int mid = left + (right - left) / 2;
	int cmp = compareVecGroups(main, mid, pend, pendGroupStart, groupSize);
	if (cmp < 0)
	    left = mid + 1;
	else
	    right = mid;
    }
    DEBUG_PRINT("Inserting at main group index: " << left << "\n");
    // Insert the group at position 'left'

    int insertPos = left * groupSize;
    main.insert(main.begin() + insertPos, pend.begin() + pendGroupStart, pend.begin() + pendGroupStart + groupSize);
    
    DEBUG_PRINT_CONTAINER(main, "main after insertion", groupSize);
    return (insertPos);
}

int PmergeMe::deqBinaryInsertion(std::deque<unsigned int>& main, const std::deque<unsigned int>& pend, int orderIndex, int groupSize, int upperBound)
{
    int pendGroupStart = orderIndex - groupSize + 1;
    int numGroups = (upperBound - groupSize + 1) / groupSize + 1;
    int left = 0;
    int right = numGroups;

    DEBUG_PRINT("\ninserting with orderIndex = " << orderIndex << std::endl);
    DEBUG_PRINT("upperbound = " << upperBound << std::endl);	
    DEBUG_PRINT("Inserting group from pend indices [" << pendGroupStart << " to " << pendGroupStart + groupSize - 1 << "]\n");
    DEBUG_PRINT_GROUP(pend, pendGroupStart, groupSize, "Pend");
    while (left < right)
    {
	int mid = left + (right - left) / 2;
	int cmp = compareDeqGroups(main, mid, pend, pendGroupStart, groupSize);
	if (cmp < 0)
	    left = mid + 1;
	else
	    right = mid;
    }
    DEBUG_PRINT("Inserting at main group index: " << left << "\n");
   
    int insertPos = left * groupSize;
    main.insert(main.begin() + insertPos, pend.begin() + pendGroupStart, pend.begin() + pendGroupStart + groupSize);
    
    DEBUG_PRINT_CONTAINER(main, "main after insertion", groupSize);
    return (insertPos);
}

int fillVecChains(const std::vector<unsigned int> &vector, int groupSize, std::vector<unsigned int> &main, std::vector<unsigned int> &pend, std::vector<unsigned int> &aMainIndexes, std::vector<unsigned int> &nonParticipating)
{
    int n = static_cast<int>(vector.size());
    int lastProcessedIndex = -1;

    for (int i = 0; i + groupSize - 1 < n; i += groupSize * 2)
    {
        int bStart = i;
        int aStart = i + groupSize;

        if (i == 0) // automatically copy b1 to main
        {
            for (int j = 0; j < groupSize; ++j)
            {
                DEBUG_PRINT("adding " << vector[bStart + j] << " to main\n");
                main.push_back(vector[bStart + j]);
            }
        }
        else
        {
            for (int j = 0; j < groupSize; ++j)
            {
                DEBUG_PRINT("adding " << vector[bStart + j] << " to pend\n");
                pend.push_back(vector[bStart + j]);
            }
        }

        bool hasAGroup = (aStart + groupSize - 1 < n);
        int j;
        for (j = 0; j < groupSize; ++j)
        {
            if (aStart + groupSize > n)
            {
                DEBUG_PRINT(std::cout << "I enter break\n");
                if (i != 0)
                    aMainIndexes.push_back(main.size() - 1);
                break;
            }
            DEBUG_PRINT("adding " << vector[aStart + j] << " to main\n");
            main.push_back(vector[aStart + j]);
        }

        if (j < groupSize)
        {
            lastProcessedIndex = i + (groupSize - j * 2) - 1;
            break;
        }
        if (i != 0)
        {
            if (hasAGroup)
                aMainIndexes.push_back(main.size() - 1);
            else
                aMainIndexes.push_back(main.size() - 1);
        }

        lastProcessedIndex = i + (groupSize * 2) - 1;
        DEBUG_PRINT(" --- next " << groupSize * 2 << " numbers ---\n");
    }

    if (lastProcessedIndex + 1 < n)
    {
        for (int i = lastProcessedIndex + 1; i < n; ++i)
        {
            DEBUG_PRINT("adding leftover " << vector[i] << " to non part\n");
            nonParticipating.push_back(vector[i]);
        }
    }
    DEBUG_PRINT("exited loop\n");

    return lastProcessedIndex;
}

void    PmergeMe::performVecInsertions(std::vector<unsigned int> &main, std::vector<unsigned int> &pend, std::vector<unsigned int> &aMainIndexes, int groupSize)
{
    DEBUG_PRINT(std::endl);
    std::vector<unsigned int> order;
    if (!pend.empty())
    {
        order = vecInsertionOrder(pend.size(), groupSize);
        DEBUG_PRINT("insertion order = ");
        for (size_t i = 0; i < order.size(); ++i)
        {
            DEBUG_PRINT(order[i]);
            if (i != order.size() - 1)
                DEBUG_PRINT(", ");
        }
    }
    DEBUG_PRINT(std::endl);

    size_t insertedElements = 0; // b1 already in main
    int i = 0;
    while (insertedElements < pend.size() / groupSize)
    {
        int bGroupIdx = order[i] / groupSize;
        int pairedAIdx = bGroupIdx;
        int upperBound = aMainIndexes[pairedAIdx];

        int insertPos = binaryInsertion(main, pend, order[i], groupSize, upperBound);

        DEBUG_PRINT("aMainIndexes before update: ");
        for (size_t idx = 0; idx < aMainIndexes.size(); ++idx)
            DEBUG_PRINT(aMainIndexes[idx] << " ");
        DEBUG_PRINT(std::endl);

        for (size_t j = 0; j < aMainIndexes.size(); ++j)
        {
            if ((int)aMainIndexes[j] >= insertPos)
                aMainIndexes[j] += groupSize;
        }
        insertedElements++;
        i++;

        DEBUG_PRINT("aMainIndexes after update: ");
        for (size_t idx = 0; idx < aMainIndexes.size(); ++idx)
            DEBUG_PRINT(aMainIndexes[idx] << " ");
        DEBUG_PRINT(std::endl);
    }
}

void    handleLeftovers(const std::vector<unsigned int> &vector, std::vector<unsigned int> &main, std::vector<unsigned int> &nonParticipating, int lastProcessedIndex)
{
    int n = static_cast<int>(vector.size());
    if (lastProcessedIndex + 1 < n)
    {
        for (int i = lastProcessedIndex + 1; i < n; ++i)
        {
            DEBUG_PRINT("adding leftover " << vector[i] << " to main\n");
            main.push_back(vector[i]);
            nonParticipating.push_back(vector[i]);
        }
    }
}

// INFO: Sequence Insertion Logic
    // create main chain
    // create pend chain (no los quitamos del pend despues de insertarlos)
    // create non-participating chain
    // find insertion order with Jacobsthal nums
    // insertion loop 
    // binary insert each element (with its bound element) in the main
    // update numero de elementos insertados (b1 lo he instertado yo ya al principio, siempre cuenta)
    // muy importante keep track del upperbound / posicion de la a para cada b que insertamos (esta posicion cambia cada vez que insertamos un nuevo elemento, osea que se tiene que actualizar!!!) (yo lo hago con aMainIndexes)

void	PmergeMe::vecSequenceInsertions(std::vector<unsigned int> &vector, int groupSize)
{
    DEBUG_PRINT("groupSize = " << groupSize << std::endl);
    if (groupSize < 1)
    {
        _vector = vector;
        DEBUG_PRINT("exiting sequence insertions\n\n");
        return;
    }
    if (vector.size() < static_cast<size_t>(groupSize) * 2)
    {
        DEBUG_PRINT("nothing to be done in this level, entering recursion\n");
        vecSequenceInsertions(vector, groupSize / 2);
        return;
    }

    DEBUG_PRINT_CONTAINER(vector, "sequence", groupSize);
    DEBUG_PRINT(std::endl);

    std::vector<unsigned int> main; 
    std::vector<unsigned int> pend; 
    std::vector<unsigned int> aMainIndexes; 
    std::vector<unsigned int> nonParticipating; 

    int lastProcessedIndex = fillVecChains(vector, groupSize, main, pend, aMainIndexes, nonParticipating);

    DEBUG_PRINT("\nBEFORE INSERTION" << std::endl);
    DEBUG_PRINT_CONTAINER(main, "main", groupSize);
    DEBUG_PRINT_CONTAINER(pend, "pend", groupSize);
    DEBUG_PRINT_CONTAINER(nonParticipating, "non part", groupSize);
    DEBUG_PRINT_CONTAINER(aMainIndexes, "a's main indexes for b's in pend", 1);

    performVecInsertions(main, pend, aMainIndexes, groupSize);

    DEBUG_PRINT("\nAFTER INSERTION" << std::endl);
    DEBUG_PRINT_CONTAINER(main, "main", groupSize);
    DEBUG_PRINT_CONTAINER(pend, "pend/inserted", groupSize);
    DEBUG_PRINT_CONTAINER(nonParticipating, "non part", groupSize);
    DEBUG_PRINT_CONTAINER(aMainIndexes, "a's main indexes for b's in pend", 1);
    DEBUG_PRINT(std::endl);

    handleLeftovers(vector, main, nonParticipating, lastProcessedIndex);
    vecSequenceInsertions(main, groupSize / 2);
}

int fillDeqChains(const std::deque<unsigned int> &deque, int groupSize,
                            std::deque<unsigned int> &main,
                            std::deque<unsigned int> &pend,
                            std::deque<unsigned int> &aMainIndexes,
                            std::deque<unsigned int> &nonParticipating)
{
    int n = static_cast<int>(deque.size());
    int lastProcessedIndex = -1;

    for (int i = 0; i + groupSize - 1 < n; i += groupSize * 2)
    {
        int bStart = i;
        int aStart = i + groupSize;
        if (i == 0) // automatically copy b1 to main
        {
            for (int j = 0; j < groupSize; ++j)
            {
                DEBUG_PRINT("adding " << deque[bStart + j] << " to main\n");
                main.push_back(deque[bStart + j]);
            }
        }
        else
        {
            for (int j = 0; j < groupSize; ++j)
            {
                DEBUG_PRINT("adding " << deque[bStart + j] << " to pend\n");
                pend.push_back(deque[bStart + j]);
            }
        }

        bool hasAGroup = (aStart + groupSize - 1 < n);
        int j;
        for (j = 0; j < groupSize; ++j)
        {
            if (aStart + groupSize > n)
            {
                DEBUG_PRINT(std::cout << "I enter break\n");
                if (i != 0)
                    aMainIndexes.push_back(main.size() - 1);
                break;
            }
            DEBUG_PRINT("adding " << deque[aStart + j] << " to main\n");
            main.push_back(deque[aStart + j]);
        }

        if (j < groupSize)
        {
            lastProcessedIndex = i + (groupSize - j * 2) - 1;
            break;
        }

        if (i != 0)
        {
            if (hasAGroup)
                aMainIndexes.push_back(main.size() - 1);
            else
                aMainIndexes.push_back(main.size() - 1);
        }

        lastProcessedIndex = i + (groupSize * 2) - 1;
        DEBUG_PRINT(" --- next " << groupSize * 2 << " numbers ---\n");
    }

    if (lastProcessedIndex + 1 < n)
    {
        for (int i = lastProcessedIndex + 1; i < n; ++i)
        {
            DEBUG_PRINT("adding leftover " << deque[i] << " to non part\n");
            nonParticipating.push_back(deque[i]);
        }
    }

    DEBUG_PRINT("exited loop\n");
    return lastProcessedIndex;
}

void    PmergeMe::performDeqInsertions(std::deque<unsigned int> &main, std::deque<unsigned int> &pend, std::deque<unsigned int> &aMainIndexes, int groupSize)
{
    DEBUG_PRINT(std::endl);

    std::deque<unsigned int> order;
    if (!pend.empty())
    {
        order = deqInsertionOrder(pend.size(), groupSize);
        DEBUG_PRINT("insertion order = ");
        for (size_t i = 0; i < order.size(); ++i)
        {
            DEBUG_PRINT(order[i]);
            if (i != order.size() - 1)
                DEBUG_PRINT(", ");
        }
    }
    DEBUG_PRINT(std::endl);

    size_t insertedElements = 0; // b1 already in main
    int i = 0;

    while (insertedElements < pend.size() / groupSize)
    {
        int bGroupIdx = order[i] / groupSize;
        int pairedAIdx = bGroupIdx;
        int upperBound = aMainIndexes[pairedAIdx];

        int insertPos = deqBinaryInsertion(main, pend, order[i], groupSize, upperBound);

        DEBUG_PRINT("aMainIndexes before update: ");
        for (size_t idx = 0; idx < aMainIndexes.size(); ++idx)
            DEBUG_PRINT(aMainIndexes[idx] << " ");
        DEBUG_PRINT(std::endl);

        for (size_t j = 0; j < aMainIndexes.size(); ++j)
        {
            if ((int)aMainIndexes[j] >= insertPos)
                aMainIndexes[j] += groupSize;
        }

        insertedElements++;
        i++;

        DEBUG_PRINT("aMainIndexes after update: ");
        for (size_t idx = 0; idx < aMainIndexes.size(); ++idx)
            DEBUG_PRINT(aMainIndexes[idx] << " ");
        DEBUG_PRINT(std::endl);
    }
}

void    handleDeqLeftovers(const std::deque<unsigned int> &deque, std::deque<unsigned int> &main, std::deque<unsigned int> &nonParticipating, int lastProcessedIndex)
{
    int n = static_cast<int>(deque.size());
    if (lastProcessedIndex + 1 < n)
    {
        for (int i = lastProcessedIndex + 1; i < n; ++i)
        {
            DEBUG_PRINT("adding leftover " << deque[i] << " to main\n");
            main.push_back(deque[i]);
            nonParticipating.push_back(deque[i]);
        }
    }
}

void	PmergeMe::deqSequenceInsertions(std::deque<unsigned int> &deque, int groupSize)
{
    DEBUG_PRINT("groupSize = " << groupSize << std::endl);
    if (groupSize < 1)
    {
        _deque = deque;
        DEBUG_PRINT("exiting sequence insertions\n\n");
        return;
    }
    if (deque.size() < static_cast<size_t>(groupSize) * 2)
    {
        DEBUG_PRINT("nothing to be done in this level, entering recursion\n");
        deqSequenceInsertions(deque, groupSize / 2);
        return;
    }
    DEBUG_PRINT_CONTAINER(deque, "sequence", groupSize);
    DEBUG_PRINT(std::endl);

    std::deque<unsigned int> main;
    std::deque<unsigned int> pend;
    std::deque<unsigned int> aMainIndexes;
    std::deque<unsigned int> nonParticipating;

    int lastProcessedIndex = fillDeqChains(deque, groupSize, main, pend, aMainIndexes, nonParticipating);

    DEBUG_PRINT("\nBEFORE INSERTION" << std::endl);
    DEBUG_PRINT_CONTAINER(main, "main", groupSize);
    DEBUG_PRINT_CONTAINER(pend, "pend", groupSize);
    DEBUG_PRINT_CONTAINER(nonParticipating, "non part", groupSize);
    DEBUG_PRINT_CONTAINER(aMainIndexes, "a's main indexes for b's in pend", 1);

    performDeqInsertions(main, pend, aMainIndexes, groupSize);

    DEBUG_PRINT("\nAFTER INSERTION" << std::endl);
    DEBUG_PRINT_CONTAINER(main, "main", groupSize);
    DEBUG_PRINT_CONTAINER(pend, "pend/inserted", groupSize);
    DEBUG_PRINT_CONTAINER(nonParticipating, "non part", groupSize);
    DEBUG_PRINT_CONTAINER(aMainIndexes, "a's main indexes for b's in pend", 1);
    DEBUG_PRINT(std::endl);

    handleDeqLeftovers(deque, main, nonParticipating, lastProcessedIndex);
    deqSequenceInsertions(main, groupSize / 2);
}

PmergeMe&	PmergeMe::operator=(const PmergeMe &var)
{
	if (this != &var)
	{
		_vector = var._vector;
		_deque = var._deque;
		_vecComparisons = var._vecComparisons;
		_deqComparisons = var._deqComparisons;
	}
	return (*this);
}	
