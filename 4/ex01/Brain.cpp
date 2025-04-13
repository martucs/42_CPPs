/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:53:10 by martalop          #+#    #+#             */
/*   Updated: 2025/04/13 20:06:06 by martalop         ###   ########.fr       */
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
		ideas[i] = "Idea " + s.str();
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

Brain&	Brain::operator=(const Brain& var)
{
	std::cout << "Brain copy assignment operator" << std::endl;
	if (this != &var)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = var.ideas[i];
	}
	return (*this);
}
