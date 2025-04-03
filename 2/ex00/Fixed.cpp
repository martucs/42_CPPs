/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/03 17:23:29 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "constructor says hi" << std::endl;
	_value = 10;
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

int	Fixed::getRawBits(void)
{
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	(void)raw;
	_value = raw;
}

void	Fixed::operator=(const Fixed &num)
{
	this->setRawBits(num._value);
}
//operator=
