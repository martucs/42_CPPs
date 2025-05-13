/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:34:20 by martalop          #+#    #+#             */
/*   Updated: 2025/05/08 13:34:45 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &var);
		~Array();
		
		// member functions
		unsigned int	size(void) const;

		// operators
		Array&	operator=(const Array<T>&);
		T&	operator[](int) const;
	
	private:
		// atributes
		T		*_array;
		unsigned int	_size;
};

// INFO: CONSTRUCTORES & DESTRUCTORES
template <typename T>
Array<T>::Array()
{
	std::cout << "Array constructor called" << std::endl;
	_array = NULL;
	_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << "Array complete constructor called" << std::endl;
	if (n > 100000)
		throw std::overflow_error("Invalid array size");
	_array = new T[n];
	_size = n;
}

template <typename T>
Array<T>::Array(const Array &var)
{
	std::cout << "Array copy constructor called" << std::endl;
	_array = NULL;
	_size = 0;
	*this = var;

}

template <typename T>
Array<T>::~Array()
{	
	std::cout << "Array destructor called" << std::endl;
	delete[] _array;
}

// INFO: FUNCIONES MIEMBRO
template <typename T>
unsigned int	Array<T>::size(void) const
{
	return _size;
}

// INFO: OPERADORES
template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& var)
{
	if (this != &var)
	{
		if (_array)
			delete[] _array;
		_array = new T[var.size()];
		for (unsigned int i = 0; i < var.size(); i++)
			_array[i] = var._array[i];
		_size = var._size;
	}
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](int index) const
{
	if (index >= static_cast<int>(_size) || index < 0)
		throw (std::runtime_error("Array index is out of bounds!"));
	return (_array[index]);
}

#endif
