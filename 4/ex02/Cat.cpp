/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:03:00 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 15:27:46 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& var): Animal(var)
{
	std::cout << "Cat constructor called" << std::endl;
	*this = var;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Brain*	Cat::getBrain(void) const
{
	return (_brain);
}

void	Cat::makeSound(void) const
{
	std::cout << "miau miau" << std::endl;
}

Cat&	Cat::operator=(const Cat& var)
{
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &var)
	{
		_type = var._type;
		delete _brain;
		_brain = new Brain;
		*_brain = *var.getBrain();
	}
	return (*this);
}
