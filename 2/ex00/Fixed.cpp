/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/09 17:45:00 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "constructor says hi" << std::endl;
	_value = 0;
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

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

Fixed&	Fixed::operator=(const Fixed &num)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &num)
		this->setRawBits(num._value);
	return (*this);
}
