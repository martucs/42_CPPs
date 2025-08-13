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

int	binarySearch(unsigned int target, std::vector<unsigned int> vector)
{
	int size = vector.size();
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (vector[mid] == target)
			return mid;
		else if (vector[mid] < target)
			left = mid + 1;  // search right half
		else
			right = mid - 1; // search left half
	}
	return (left);
}

int	getJacobsthalAt(int index)
{
	if (index == 0) 
		return (0);
	if (index == 1)
		return (1);
	int j0 = 0, j1 = 1, jn;
	for (int i = 2; i <= index; ++i) 
	{
		jn = j1 + 2 * j0;
		j0 = j1;
		j1 = jn;
	}
	return (jn);
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

	std::cout << std::endl;
	printVector(vector, "After", 1);
	
/*	std::vector<int> JNums = getJacobsthalNums(19);
	int Jacobstal = getJacobsthalAt(3);
	std::cout << "Jacobsthal at 3 = " << Jacobstal << std::endl;
	printVector(JNums, "Jacobsthal numbers", 1);*/
	return (0);
}
