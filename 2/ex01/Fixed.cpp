/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/07 19:32:01 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdio>

// CONSTRUCTORS & DESTRUCTOR
Fixed::Fixed()
{
	std::cout << "default constructor says hi" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value )
{
	std::cout << "int constructor says hi" << std::endl;
	_value = value << _fractionalNum;
}

Fixed::Fixed( const float value )
{
//	float	tmp;

	std::cout << "float constructor says hi" << std::endl;
	printf("\nfloat value = %f\n", value);
	_value = value * (1 << 8);
	printf("\nint value = %d\n", _value);
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "copy constructor called" << std::endl;
	_value = original._value;
}

Fixed::~Fixed()
{
	std::cout << "destructor says bye" << std::endl;
}

// MEMBER FUNCTIONS 
float	Fixed::toFloat(void) const
{
	return (_value / (1 << _fractionalNum));
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractionalNum);
}

// GETTER & SETTER
int	Fixed::getRawBits(void) const
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	(void)raw;
	_value = raw;
}

// OPERATORS 
void	Fixed::operator=(const Fixed &var)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(var._value);
}
