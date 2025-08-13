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
		PmergeMe(std::vector<unsigned int> &vector);
		PmergeMe(const PmergeMe &);
		~PmergeMe();
	
		void				vectorMergeInsertion();
		std::vector<unsigned int>	getVector() const;
		PmergeMe			&operator=(const PmergeMe &);
	private:
		std::vector<unsigned int>	_vector;

};

static void	printVector(const std::vector<unsigned int> &vector, std::string when, int level)
{
	std::vector<unsigned int>::const_iterator	it = vector.begin();
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
