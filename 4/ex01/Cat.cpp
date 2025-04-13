/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:03:00 by martalop          #+#    #+#             */
/*   Updated: 2025/04/13 20:06:36 by martalop         ###   ########.fr       */
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
// if I had done this in the operator=
//		_brain = var.getBrain();
//	it would be a shallow copy (instead of deep copy)
//	(estariamos copiando la misma dir de memoria)
//	meaning we would get segfault if we had done:
//	Cat	*cat1 =new Cat()
//	Cat	*cat2 =new Cat()
//
//	*cat2 = *cat1;
//	delete cat1;
//
//	cat2->getBrain()->ideas[0] --> SEGFAULT
//	porque intentariamos acceder a la memoria del _brain de cat1, que ya habria sido eliminada
