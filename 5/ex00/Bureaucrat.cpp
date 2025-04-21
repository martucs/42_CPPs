/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:51:47 by martalop          #+#    #+#             */
/*   Updated: 2025/04/17 19:05:00 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Random Bureaucrat")
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	_grade = 1;
}

Bureaucrat::Bureaucrat(const std::string name, int grade )
{
	std::cout << "Bureaucrat complete constructor called" << std::endl;
	_name = name;
	_grade = grade;
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

void	Bureaucrat::incrementGrade(unsigned int amount)
{
	_grade -= amount;
}

void	Bureaucrat::decrementGrade(unsigned int amount)
{
	_grade += amount;
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

const std::string	Bureaucrat::getName(void) const
{
	return (_name);
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& var)
{
	if (this != &var)
	{
		_name = var._name;
		_grade = var._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& var)
{
	os << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return (os);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade is too High!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade is too low!");
}