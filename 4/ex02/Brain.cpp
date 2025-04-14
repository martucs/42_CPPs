/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:53:10 by martalop          #+#    #+#             */
/*   Updated: 2025/04/13 20:21:40 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
	std::ostringstream s;
	std::cout << "Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		s << i;
		_ideas[i] = "Idea " + s.str();
		s.str("");
	}
	s.clear();
}

Brain::Brain(const Brain& var)
{
	std::cout << "Brain constructor called" << std::endl;
	*this = var;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

void	Brain::setIdea(std::string str, int index)
{
	_ideas[index] = str;
}

std::string	Brain::getIdea(int index) const
{
	return (_ideas[index]);
}

Brain&	Brain::operator=(const Brain& var)
{
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &var)
	{
		for (int i = 0; i < 100; i++)
			_ideas[i] = var._ideas[i];
	}
	return (*this);
}
