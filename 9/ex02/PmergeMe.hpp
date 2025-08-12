#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <cmath>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();
	
		void		vectorMergeInsertion(std::vector<int> &input);
		PmergeMe	&operator=(const PmergeMe &);
	private:

};

static void	printVector(const std::vector<int> &vector, std::string when, int level)
{
	std::vector<int>::const_iterator	it = vector.begin();
	(void)level;

	std::cout << when << ": ";
	for (int i = 0; it != vector.end(); it++)
	{
//		if (i == groupNumber - 1)
//		{
//			groupNumber += groupNumber;
//			std::cout << "\033[34m" << *it << "\033[0m, ";
//		}
//		else
		if (it + 1 == vector.end())
			std::cout<< *it;
		else
			std::cout<< *it << ", ";
		i++;
	}
	std::cout << std::endl;
}

#endif
