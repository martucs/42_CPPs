/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/08 18:50:51 by martalop         ###   ########.fr       */
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
	std::cout << "float constructor says hi" << std::endl;
	_value = roundf(value * (1 << _fractionalNum));
}
// 'roundf' redondea el ultimo decimal a la alta
// es necesario porque si no lo ponemos, al igualar _value(int) a un resultado decimal, redondea el numero a la baja
// por tanto, perdemos parte de la info del decimal

Fixed::Fixed(const Fixed &original)
{
	std::cout << "copy constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed()
{
	std::cout << "destructor says bye" << std::endl;
}

// MEMBER FUNCTIONS 
float	Fixed::toFloat(void) const
{
	return ((float)_value / ((float)(1 << _fractionalNum)));
}
// aqui tambien es necesario castear a float porque si no, perdemos los decimales

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
	_value = raw;
}

// OPERATORS 
Fixed&	Fixed::operator=(const Fixed &var)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &var)
		this->setRawBits(var._value);
	return (*this);
}

std::ostream&	operator<<(std::ostream &os, const Fixed &var)
{
	os << var.toFloat();
	return (os);
}
