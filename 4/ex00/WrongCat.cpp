/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:03:00 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 22:38:39 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WRONG Cat constructor called" << std::endl;
	_type = "WRONG Cat";
}

WrongCat::WrongCat(const WrongCat& var): WrongAnimal(var)
{
	std::cout << "WRONG Cat constructor called" << std::endl;
	*this = var;
}

WrongCat::~WrongCat()
{
	std::cout << "WRONG Cat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WRONG miau miau" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& var)
{
	if (this != &var)
		_type = var._type;
	return (*this);
}
