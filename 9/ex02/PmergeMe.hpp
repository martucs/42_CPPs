#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <cstdlib>
# include <cmath>

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(x) do { std::cout << x; } while (0)
#else
    #define DEBUG_PRINT(x) do {} while (0)
#endif

#ifdef DEBUG_MODE
    #define DEBUG_PRINT_VECTOR(vec, when, groupSize) printVector(vec, when, groupSize)
#else
    #define DEBUG_PRINT_VECTOR(vec, when, groupSize) do {} while (0)
#endif

#ifdef DEBUG_MODE
    #define DEBUG_PRINT_GROUP(vec, start, groupSize, name) printGroupInVector(vec, start, groupSize, name)
#else
    #define DEBUG_PRINT_GROUP(vec, start, groupSize, name) do {} while (0)
#endif

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(std::vector<unsigned int> &vector);
		PmergeMe(const PmergeMe &);
		~PmergeMe();
	
		void				vectorMergeInsertion();
		void				sortElements(std::vector<unsigned int> &vector, int &groupSize);
		void				sequenceInsertions(std::vector<unsigned int> &vector, int groupSize);
		std::vector<unsigned int>	getVector() const;
		PmergeMe			&operator=(const PmergeMe &);
	private:
		std::vector<unsigned int>	_vector;

};

void printVector(const std::vector<unsigned int>& vector, const std::string& when, int groupSize);


#endif
