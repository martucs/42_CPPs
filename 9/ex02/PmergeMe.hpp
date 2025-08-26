#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <cmath>

#ifdef DEBUG_MODE
    #define DEBUG_PRINT(x) do { std::cout << x; } while (0)
    #define DEBUG_PRINT_CONTAINER(c, when, groupSize) printContainer(c, when, groupSize)
    #define DEBUG_PRINT_GROUP(c, start, groupSize, name) printGroupInContainer(c, start, groupSize, name)
#else
    #define DEBUG_PRINT(x) do {} while (0)
    #define DEBUG_PRINT_CONTAINER(c, when, groupSize) do {} while (0)
    #define DEBUG_PRINT_GROUP(c, start, groupSize, name) do {} while (0)
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

template <typename Container>
void printContainer(const Container& container, const std::string& when, int groupSize)
{
    std::cout << when << ": ";
    int n = static_cast<int>(container.size());
    int i = 0;
    const std::string color = "\033[31m";
    const std::string colorReset = "\033[0m";

    while (i < n)
    {
        int remaining = n - i;

        if (groupSize == 1)
        {
            for (; i < n; ++i)
            {
                std::cout << container[i];
                if (i < n - 1)
                    std::cout << ", ";
            }
            break;
        }
        if (remaining < groupSize)
        {
            for (int j = 0; j < remaining; ++j, ++i)
            {
                std::cout << container[i];
                if (j < remaining - 1)
                    std::cout << ", ";
            }
        }
        else
        {
            std::cout << "\x1B[1m[" << "\x1B[0m";
            for (int j = 0; j < groupSize; ++j, ++i)
            {
                if (j == groupSize - 1)
                    std::cout << color << container[i] << colorReset;
                else
                    std::cout << container[i];
                if (j < groupSize - 1)
                    std::cout << ", ";
            }
            std::cout << "\x1B[1m]" << "\x1B[0m";
        }
        if (i < n)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

template <typename Container>
void printGroupInContainer(const Container& container, int start, int groupSize, const std::string& name)
{
	std::cout << name << " group: ";

	int n = static_cast<int>(container.size());
	if (start < 0 || start >= n)
	{
		std::cout << "(invalid start index)" << std::endl;
		return;
	}
	int end = std::min(start + groupSize, n);
	const std::string color = "\033[31m";
	const std::string colorReset = "\033[0m";

	std::cout << "\x1B[1m[" << "\x1B[0m";
	for (int i = start; i < end; ++i)
	{
		if (i == end - 1) 
			std::cout << color << container[i] << colorReset;
		else
			std::cout << container[i];

		if (i < end - 1)
			std::cout << ", ";
	}
	std::cout << "\x1B[1m]" << "\x1B[0m" << std::endl;
}

#endif
