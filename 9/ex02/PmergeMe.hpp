#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &);
		~PmergeMe();
	
		void		calculate(std::vector<int> &input);
		PmergeMe	&operator=(const PmergeMe &);
	private:

};

#endif
