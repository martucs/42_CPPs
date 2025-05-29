#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
		MutantStack();
		MutantStack(const MutantStack& );
		~MutantStack();
	
		iterator	begin();
		iterator	end();
		const_iterator	begin() const;
		const_iterator	end() const;

		MutantStack&	operator=(const MutantStack&);
};
// INFO:
// typename -> nos permite compilar sin saber aun el tipo de T
// typedef -> nos permite utilizarlo como un tipo, incluso fuera de la clase

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
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename std::stack<T>::container_type::const_iterator	MutantStack<T>::end(void) const
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
