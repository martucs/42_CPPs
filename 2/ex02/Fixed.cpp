/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/08 20:36:14 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdio> 

// CONSTRUCTORS & DESTRUCTOR
Fixed::Fixed()
{
	_value = 0;
}

Fixed::Fixed(const int value )
{
	_value = value << _fractionalNum;
}

Fixed::Fixed( const float value )
{
	_value = roundf(value * (1 << _fractionalNum));
}

Fixed::Fixed(const Fixed &original)
{
	*this = original;
}

Fixed::~Fixed()
{
}

// MEMBER FUNCTIONS 
float	Fixed::toFloat(void) const
{
	return ((float)_value / ((float)(1 << _fractionalNum)));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionalNum);
}

Fixed&	Fixed::min(Fixed &one, Fixed &two)
{
	if (one < two)
		return (one);
	return (two);
}

/*Fixed&	Fixed::min(const Fixed &one, const Fixed &two)
{
	if (one < two)
		return (one);
	return (two);
}*/

Fixed&	Fixed::max(Fixed &one, Fixed &two)
{
	if (one > two)
		return (one);
	return (two);
}

/*Fixed&	Fixed::max(const Fixed &one, const Fixed &two)
{
	if (one < two)
		return (one);
	return (two);
}*/

// GETTER & SETTER
int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

// OPERATORS 
Fixed&	Fixed::operator=(const Fixed &var)
{
	if (this != &var)
		this->setRawBits(var._value);
	return (*this);
}

bool	Fixed::operator>(const Fixed &var)
{
	if (_value > var.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &var)
{
	if (_value < var.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &var)
{
	if (_value > var.getRawBits() || _value == var.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &var)
{
	if (_value < var.getRawBits() || _value == var.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &var)
{
	if (_value == var.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &var)
{
	if (_value != var.getRawBits())
		return (true);
	return (false);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &var)
{
	os << var.toFloat();
	return (os);
}
