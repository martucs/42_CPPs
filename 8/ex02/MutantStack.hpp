#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		MutantStack();
		MutantStack(const MutantStack& );
		~MutantStack();
	
	//	typename std::stack<T>::container_type::iterator	begin();
	//	typename std::stack<T>::container_type::iterator	end();
		iterator	begin();
		iterator	end();

		MutantStack&	operator=(const MutantStack&);
};

template <typename T>
MutantStack<T>::MutantStack()
{
//	std::cout << "mutantstack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack& var)
{
	*this = var;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
MutantStack<T>&		MutantStack<T>::operator=(const MutantStack& var)
{
	if (this != &var)
	{
		std::stack<T>::operator=(var);
	}
	return (*this);
}
#endif
