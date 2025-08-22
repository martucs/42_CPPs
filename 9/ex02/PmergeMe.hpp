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
		void				sortElements(std::vector<unsigned int> &vector, int &groupSize);
		void				sequenceInsertions(std::vector<unsigned int> &vector, int &groupSize, int recursionLevel);
		std::vector<unsigned int>	getVector() const;
		PmergeMe			&operator=(const PmergeMe &);
	private:
		std::vector<unsigned int>	_vector;

};

static void printVector(const std::vector<unsigned int> &vector, const std::string &when, int groupSize)
{
    std::cout << when << ": ";

    int n = static_cast<int>(vector.size());
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
			std::cout << vector[i];
			if (i < n - 1)
			std::cout << ", ";
		}
		break;
	}
        // If remaining elements are fewer than groupSize, print them without brackets
        if (remaining < groupSize)
        {
            for (int j = 0; j < remaining; ++j, ++i)
            {
                std::cout << vector[i];
                if (j < remaining - 1)
                    std::cout << ", ";
            }
        }
        else
        {
            // Print a full group with brackets
            std::cout << "\x1B[1m[" << "\x1B[0m";
            for (int j = 0; j < groupSize; ++j, ++i)
            {
                if (j == groupSize - 1)
                    std::cout << color << vector[i] << colorReset; // Last element in group: print in red
                else
                    std::cout << vector[i];
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

#endif
