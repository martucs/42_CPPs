/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:34:56 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 22:38:09 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	_type = "Random WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& var)
{
	std::cout << "WrongAnimal constructor called" << std::endl;
	*this = var;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "making random WRONG animal sound..." << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& var)
{
	if (this != &var)
		_type = var._type;
	return (*this);
}
