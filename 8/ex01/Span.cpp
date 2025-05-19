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
#include <vector>
#include <algorithm>

Span::Span()
{
	//std::cout << "Span constructor called" << std::endl;
}

Span::Span(unsigned int N)
{
	//std::cout << "Span complete constructor called" << std::endl;
	_size = N;
	_filled = 0;
	_elements = new int [N];
	for (unsigned int i = 0; i < _size; i++)
		_elements[i] = 0;
}

Span::Span(const Span& var)
{
	//std::cout << "Span copy constructor called" << std::endl;
	_elements = NULL;
	*this = var;
}

Span::~Span()
{
	//std::cout << "Span destructor called" << std::endl;
	delete[] _elements;
}

unsigned int	Span::getSize(void) const
{
	return (_size);
}
unsigned int	Span::getFilledNum(void) const
{
	return (_filled);
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
	
	if (_filled <= 1)
		throw NotEnoughSpanInfo();
	unsigned int	i = 0;
	Span		copy = *this;

	std::sort(copy._elements, copy._elements + copy._filled);
	while ( i < copy._filled - 1)
	{
		span = std::abs(copy._elements[i] - copy._elements[i + 1]);
		if (span < shortestSpan)
			shortestSpan = span; 
		i++;
	}
	return (shortestSpan);
}

int	Span::longestSpan(void)
{
	if (_filled <= 1)
		throw NotEnoughSpanInfo();

	int	*max = std::max_element(this->_elements, this->_elements + this->_filled);
	int	*min = std::min_element(this->_elements, this->_elements + this->_filled);

	return (std::abs(*max - *min));
}

void	Span::addNumber(int num)
{
	if (_filled < _size)
	{
		_elements[_filled] = num;
		_filled++;
	}
	else
		throw FullSpan();
}

Span&	Span::operator=(const Span& var)
{
	//std::cout << "copy operator called" << std::endl;
	if (this != &var)
	{
		if (_elements)
			delete[] _elements;
		_elements = new int [var._size];
		for (unsigned int i = 0; i < var._filled && i < var._size; i++)
			_elements[i] = var._elements[i];
		_size = var._size;
		_filled = var._filled;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Span& var)
{
	os << "- Span size = " << var.getSize() << std::endl;
	os << "- Elements: " << std::endl;
	for (unsigned int i = 0; i < var.getFilledNum(); i++)
	{
		os << "[" << i << "] = " << var.getElement(i) << std::endl;
	}
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
