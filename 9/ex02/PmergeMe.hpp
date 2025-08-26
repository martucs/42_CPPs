#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <cmath>

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(x) do { std::cout << x; } while (0)
#else
    #define DEBUG_PRINT(x) do {} while (0)
#endif

#ifdef DEBUG_MODE
    #define DEBUG_PRINT_VECTOR(vec, when, groupSize) printVector(_vector, when, groupSize)
    #define DEBUG_PRINT_DEQUE(deq, when, groupSize) printDeque(_deque, when, groupSize)
#else
    #define DEBUG_PRINT_VECTOR(vec, when, groupSize) do {} while (0)
    #define DEBUG_PRINT_DEQUE(deq, when, groupSize) do {} while (0)

#endif

#ifdef DEBUG_MODE
    #define DEBUG_PRINT_VECGROUP(vec, start, groupSize, name) printGroupInVector(vec, start, groupSize, name)
    #define DEBUG_PRINT_DEQGROUP(vec, start, groupSize, name) printGroupInDeque(_deque, start, groupSize, name)
#else
    #define DEBUG_PRINT_VECGROUP(vec, start, groupSize, name) do {} while (0)
    #define DEBUG_PRINT_DEQGROUP(dec, start, groupSize, name) do {} while (0)
#endif

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(std::vector<unsigned int> &vector);
		PmergeMe(std::deque<unsigned int> &deque);
		PmergeMe(const PmergeMe &);
		~PmergeMe();
	
		void				vectorMergeInsertion();
		void				sortVecElements(std::vector<unsigned int> &vector, int &groupSize);
		void				vecSequenceInsertions(std::vector<unsigned int> &vector, int groupSize);

		void				dequeMergeInsertion();
		void				sortDeqElements(std::deque<unsigned int> &deque, int &groupSize);
		void				deqSequenceInsertions(std::deque<unsigned int> &deque, int groupSize);

		std::vector<unsigned int>&	getVector();
		int				getVectorComparisons() const;
		std::deque<unsigned int>&	getDeque();
		int				getDequeComparisons() const;

		int				binaryInsertion(std::vector<unsigned int>& main, const std::vector<unsigned int>& pend, int orderIndex, int groupSize, int upperBound);
		int				deqBinaryInsertion(std::deque<unsigned int>& main, const std::deque<unsigned int>& pend, int orderIndex, int groupSize, int upperBound);
		int				compareVecGroups(const std::vector<unsigned int>& main, int mainGroupIdx, const std::vector<unsigned int>& pend, int pendGroupStart, int groupSize);
		int				compareDeqGroups(const std::deque<unsigned int>& main, int mainGroupIdx, const std::deque<unsigned int>& pend, int pendGroupStart, int groupSize);

		void				performVecInsertions(std::vector<unsigned int> &main, std::vector<unsigned int> &pend, std::vector<unsigned int> &aMainIndexes, int groupSize);
		void				performDeqInsertions(std::deque<unsigned int> &main, std::deque<unsigned int> &pend, std::deque<unsigned int> &aMainIndexes, int groupSize);
		PmergeMe			&operator=(const PmergeMe &);
	private:
		std::vector<unsigned int>	_vector;
		std::deque<unsigned int>	_deque;
		int				_vecComparisons;
		int				_deqComparisons;
};

void printVector(const std::vector<unsigned int>& vector, const std::string& when, int groupSize);
void printDeque(const std::deque<unsigned int>& deque, const std::string &when, int groupSize);

#endif
