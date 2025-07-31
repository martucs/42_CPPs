#include "PmergeMe.hpp"

void	printVector(const std::vector<int> &vector, std::string when)
{
	std::vector<int>::const_iterator	it = vector.begin();

	std::cout << when << ": ";
	for (; it != vector.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

bool	isValidInput (std::vector<int> &vector)
{
	std::vector<int>::iterator	it = vector.begin();
	for (;it != vector.end(); it++)
	{
		if (*it < 0 )
			return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	PmergeMe	mergeSort;

	if (argc < 2)
	{
		std::cout << "Usage: ./PmergeMe num1 num2 num3 (etc)" << std::endl;
		return (1);
	}
	// store args
	std::vector<int>	vector;
	for (int i = 1; argv[i] ; i++)
		vector.push_back(atoi(argv[i]));
	// check args
	if (!isValidInput(vector))
	{
		std::cerr << "Error: only positive integers accepted\n";
		return (1);
	}
	printVector(vector, "Before");
	// merge-sort
	
	printVector(vector, "After");
	return (0);
}
