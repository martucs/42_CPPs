/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:51:47 by martalop          #+#    #+#             */
/*   Updated: 2025/04/16 21:03:57 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Random Bureaucrat")
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	_grade = 1;
}

Bureaucrat::Bureaucrat(const Bureaucrat& var)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	*this = var;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& var)
{
	if (this != &var)
	{
		_grade = var._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& var)
{
	os << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return (os);
}
