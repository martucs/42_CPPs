/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 14:53:10 by martalop          #+#    #+#             */
/*   Updated: 2025/04/17 18:36:20 by martalop         ###   ########.fr       */
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
	if (index >= 0 && index <= 99)
		_ideas[index] = str;
	else
		std::cerr << "oops! non valid idea number sent to: setIdea()" << std::endl;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index <= 99)
		return (_ideas[index]);
	else
		return ("oops! non valid idea number");
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
