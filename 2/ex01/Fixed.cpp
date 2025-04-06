/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/06 22:32:31 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


// CONSTRUCTORS & DESTRUCTOR
Fixed::Fixed()
{
	std::cout << "default constructor says hi" << std::endl;
	_value = 0;
	_fractionalNum = 8;
}

Fixed::Fixed(const int value )
{
	std::cout << "int constructor says hi" << std::endl;
	_value = value;
	_fractionalNum = 8;
}

Fixed::Fixed( const float value )
{
	std::cout << "float constructor says hi" << std::endl;
	_value = (int)value;
	_fractionalNum = 8;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "copy constructor called" << std::endl;
	_value = original._value;
	_fractionalNum = 8;
}

Fixed::~Fixed()
{
	std::cout << "destructor says bye" << std::endl;
}

// MEMBER FUNCTIONS 
float	Fixed::toFloat(void) const
{
	return (_value);
}

int	Fixed::toInt(void) const
{
	return (_value);
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
