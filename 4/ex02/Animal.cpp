/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:51:47 by martalop          #+#    #+#             */
/*   Updated: 2025/04/13 18:16:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
	_type = "Random Animal";
}

Animal::Animal(const Animal& var)
{
	std::cout << "Animal constructor called" << std::endl;
	*this = var;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "making random animal sound..." << std::endl;
}

Animal&	Animal::operator=(const Animal& var)
{
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &var)
		_type = var._type;
	return (*this);
}
