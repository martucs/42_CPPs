/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:51:47 by martalop          #+#    #+#             */
/*   Updated: 2025/04/23 13:21:09 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Random Bureaucrat")
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	_grade = 150;
}

Bureaucrat::Bureaucrat(const std::string name, int grade ): _name(name)
{
	std::cout << "Bureaucrat complete constructor called" << std::endl;
	if (grade <= 0)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "No issues creating bureaucrat " << _name << std::endl;
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

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Trying to increment " << _name << "'s grade" << std::endl;
	if ((_grade - 1) <= 0)
		throw GradeTooHighException();
	_grade -= 1;
	std::cout << "No issues incrementing grade" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement " << _name << "'s grade" << std::endl;
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade += 1;
	std::cout << "No issues decrementing grade" << std::endl;
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
	std::cout << "copy operator called" << std::endl;
	if (this != &var)
		_grade = var._grade;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& var)
{
	os << var.getName() << ", bureaucrat grade " << var.getGrade() << std::endl;
	return (os);
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Custom exception: Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Custom exception: Grade is too low!");
}
