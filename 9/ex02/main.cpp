#include "PmergeMe.hpp"

int testingFormula(int n)
{
	int sum = 0;
	for (int k = 1; k <= n; ++k)
	{
		double value = (3.0 / 4.0) * k;
		sum += static_cast<int>(ceil(log2(value)));
	}
	return (sum);
}

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

bool isSortedAscending(const std::vector<unsigned int>& vec)
{
	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (vec[i] < vec[i - 1])
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
	
	printVector(vector, "Before", 1);
	std::cout << std::endl;

	// merge-insert sort
	PmergeMe	mergeInsertSort(vector);
	mergeInsertSort.vectorMergeInsertion();
	
	if (!isSortedAscending(mergeInsertSort.getVector()))
	{
		std::cout << "something went wrong, vector is not sorted!\n";
		return (1);
	}

	std::cout << std::endl;
	printVector(mergeInsertSort.getVector(), "After", 1);
	std::cout << std::endl;
	std::cout << "Vector is sorted! :) \n";
	return (0);
}
