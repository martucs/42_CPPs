#include "PmergeMe.hpp"
#include <ctime>

bool	isValidInput (char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		for (int x = 0; argv[i][x]; x++)
		{
			if (!std::isdigit(argv[i][x]))
				return (false);
		}
	}
	return (true);
}

template <typename T>
bool isSortedAscending(T& container)
{
	for (size_t i = 1; i < container.size(); ++i)
	{
		if (container[i] < container[i - 1])
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe num1 num2 num3 (etc)" << std::endl;
		return (1);
	}
	// check args
	if (!isValidInput(argv))
	{
		std::cerr << "Error: only positive integers accepted\n";
		return (1);
	}
	// store args
	std::vector<unsigned int>	vector;
	for (int i = 1; argv[i] ; i++)
		vector.push_back(atoi(argv[i]));
	printVector(vector, "VECTOR\nBefore", 1);

	PmergeMe	vecMergeInsertSort(vector);
	
	// merge-insert sort with vector
	clock_t	vec_start = clock();
	vecMergeInsertSort.vectorMergeInsertion();
	clock_t	vec_end = clock();
	if (!isSortedAscending(vecMergeInsertSort.getVector()))
	{
		std::cout << "something went wrong, vector is not sorted!\n";
		return (1);
	}
	printVector(vecMergeInsertSort.getVector(), "After", 1);
	std::cout << "Vector is sorted! :) \n";
	std::cout << "\nComparisons: " << vecMergeInsertSort.getVectorComparisons() << std::endl;
	double	vec_time = ((vec_end - vec_start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	std::cout << "Time passed: " << vec_time << " ms\n";
	
	std::cout << "--------------------------------------------------\n";

	std::deque<unsigned int>	deque;
	for (int i = 1; argv[i] ; i++)
		deque.push_back(atoi(argv[i]));
	printDeque(deque, "DEQUE\nBefore", 1);

	PmergeMe	deqMergeInsertSort(deque);

	// merge-insert sort with deque
	clock_t	deq_start = clock();
	deqMergeInsertSort.dequeMergeInsertion();
	clock_t	deq_end = clock();
	if (!isSortedAscending(deqMergeInsertSort.getDeque()))
	{
		std::cout << "something went wrong, deque is not sorted!\n";
		return (1);
	}
	printDeque(deqMergeInsertSort.getDeque(), "After", 1);
	std::cout << "Deque is sorted! :) \n";
	std::cout << "\nComparisons: " << deqMergeInsertSort.getDequeComparisons() << std::endl;
	double	deq_time = ((deq_end - deq_start) / static_cast<double>(CLOCKS_PER_SEC)) * 1000;
	std::cout << "Time passed: " << deq_time << " ms\n";
	return (0);
}
