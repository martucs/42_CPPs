/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:03:00 by martalop          #+#    #+#             */
/*   Updated: 2025/04/20 16:42:42 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

Dog::Dog(const Dog& var): Animal(var)
{
	std::cout << "Dog constructor called" << std::endl;
	_brain = new Brain;
	*this = var;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Brain*	Dog::getBrain(void) const
{
	return (_brain);
}

void	Dog::makeSound(void) const
{
	std::cout << "guau guau" << std::endl;
}

Dog&	Dog::operator=(const Dog& var)
{
	std::cout << "Dog copy assignment operator" << std::endl;
	if (this != &var)
	{
		_type = var._type;
		*_brain = *var.getBrain();
	}
	return (*this);
}
