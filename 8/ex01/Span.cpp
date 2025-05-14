/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:05:04 by martalop          #+#    #+#             */
/*   Updated: 2025/05/14 16:05:51 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>

Span::Span()
{
	std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
	std::cout << "Span complete constructor called" << std::endl;
	_it = 0;
	_size = N;
	_elements = new int [N];
	for (unsigned int i = 0; i < _size; i++)
		_elements[i] = 0;
}

Span::Span(const Span& var)
{
	std::cout << "Span copy constructor called" << std::endl;
	*this = var;
}

Span::~Span()
{
	std::cout << "Span destructor called" << std::endl;
	delete[] _elements;
}


unsigned int	Span::getSize(void) const
{
	return (_size);
}

int	Span::getElement(unsigned int pos) const
{
	if (pos < _size)
		return (_elements[pos]);
	return (-1);
}

int	Span::shortestSpan(void)
{
	int	shortestSpan = INT_MAX;
	int	span = 0;
	unsigned int i= 0;
	
	if (_it <= 1)
		throw NotEnoughSpanInfo();
	while ( i < _size)
	{
		if (i != _size - 1)
			span = abs(_elements[i] - _elements[i + 1]);
		if (span < shortestSpan)
			shortestSpan = span; 
		i++;
	}
	return (shortestSpan);
}

int	Span::longestSpan(void)
{
	int	longestSpan = INT_MIN;
	int	span = 0;
	unsigned int i= 0;
	
	if (_it <= 1)
		throw NotEnoughSpanInfo();
	while ( i < _size)
	{
		if (i != _size - 1)
			span = abs(_elements[i] - _elements[i + 1]);
		if (span > longestSpan)
			longestSpan = span; 
		i++;
	}
	return (longestSpan);
}

void	Span::addNumber(int num)
{
	if (static_cast<unsigned int>(_it) < _size)
	{
		_elements[_it] = num;
		_it++;
	}
	else
		throw FullSpan();
}

Span&	Span::operator=(const Span& var)
{
	std::cout << "copy operator called" << std::endl;
	if (this != &var)
	{
		for (unsigned int i = 0; i < var._size; i++)
			_elements[i] = var._elements[i];
		_size = var._size;
		_it = var._it;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Span& var)
{
	os << "- Span size = " << var.getSize() << std::endl;
	os << "- Elements: " << std::endl;
	for (unsigned int i = 0; i < var.getSize(); i++)
		os << "[" << i << "] = " << var.getElement(i) << std::endl;
	return (os);
}

const char	*Span::FullSpan::what(void) const throw()
{
	return ("Span is full!");
}

const char	*Span::NotEnoughSpanInfo::what(void) const throw()
{
	return ("Span isn't full enough!");
}
