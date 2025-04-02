/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:53:11 by martalop          #+#    #+#             */
/*   Updated: 2025/04/02 22:33:52 by martalop         ###   ########.fr       */
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
	_value = original._value;
}

Fixed::~Fixed()
{
	std::cout << "destructor says bye" << std::endl;
}

int	Fixed::getRawBits(void)
{
	return (0);
}

void	Fixed::setRawBits(int const raw)
{
	(void)raw;
}

//operator=
