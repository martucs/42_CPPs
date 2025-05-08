#ifndef ARRAY_TPP
#define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	std::cout << "Array constructor called" << std::endl;
	_array = new T[2];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array complete constructor called" << std::endl;
	_array = new T[n];
}

template <typename T>
Array<T>::Array(Array &var)
{
	std::cout << "Array copy constructor called" << std::endl;
	_array = new T[var.size()];
	*this = var;
}

template <typename T>
Array<T>::~Array()
{	
	std::cout << "Array destructor called" << std::endl;
	delete _array;
}

template <typename T>
T&	Array<T>::operator=(const T& var)
{
	if (this != &var)
	{
		int i = 0;

		while (i < var.size())
		{
			_array[i] = var._array[i];
			i++;
		}
	}
	return (*this);
}

#endif
