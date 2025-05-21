#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

class MutantStack : public std::stack<int>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& );
		~MutantStack();
		
		MutantStack&	operator=(const MutantStack&);
};

#endif
