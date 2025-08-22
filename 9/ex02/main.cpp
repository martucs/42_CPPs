#include "PmergeMe.hpp"

#include <cmath>

int testingFormula(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

std::vector<int>	getJacobsthalNums(int amount)
{
	std::vector<int>	JacobNums;
	int			i = 0;
	int			prevJacob = 1;
	int			prevprevJacob = 1;

	for (; i < amount; i++)
	{
		int res = prevJacob + (2 * prevprevJacob);
		prevprevJacob = prevJacob;
		prevJacob = res;
		JacobNums.push_back(res);
	}
	return (JacobNums);
}

int	binarySearch(const std::vector<unsigned int> vector, unsigned int target)
{
	int size = vector.size();
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (vector[mid] == target)
			return (mid);
		else if (vector[mid] < target)
			left = mid + 1;  // search right half
		else
			right = mid - 1; // search left half
	}
	return (-1);
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

bool isSortedAscending(const std::vector<unsigned int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false; // Not in ascending order
        }
    }
    return true; // All elements are in order
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
	
//	std::vector<int> JNums = getJacobsthalNums(19);
//	int Jacobstal = getJacobsthalAt(3);
//	std::cout << "Jacobsthal at 3 = " << Jacobstal << std::endl;
//	printVector(JNums, "Jacobsthal numbers", 1);
	return (0);
}

// binary search test
/*int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	std::vector<unsigned int>	vector;

	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(4);
	vector.push_back(10);
	vector.push_back(16);
	vector.push_back(40);
	vector.push_back(100);

	int Jacobstal = getJacobsthalAt(3);
	(void)Jacobstal;

	printVector(vector, "vector", 1);
	int searchNumber = 3;
	std::cout << "searching for number " << searchNumber << std::endl;
	std::cout << "binary search res = " << binarySearch(vector, searchNumber) << std::endl;
	return (0);
}*/
