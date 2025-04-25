/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:51:47 by martalop          #+#    #+#             */
/*   Updated: 2025/04/25 18:59:58 by martalop         ###   ########.fr       */
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
	std::cout << "*No issues creating bureaucrat " << _name << "*" << std::endl;
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
	std::cout << "*No issues incrementing grade*" << std::endl;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Trying to decrement " << _name << "'s grade" << std::endl;
	if ((_grade + 1) > 150)
		throw GradeTooLowException();
	_grade += 1;
	std::cout << "*No issues decrementing grade*" << std::endl;
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try 
	{
		form.execute(*this);
		std::cout << std::endl << "\e[1m" << _name 
				<< " executed \"" << form.getName() << "\" form \e[0m" << std::endl;
	}
	catch ( std::exception &e)
	{
		std::cout << std::endl << "\e[1m" << _name 
			<< " couldn’t execute \"" << form.getName() 
			<< "\" form because -> " << "\e[0m" << e.what() << std::endl;
	}
}

void	Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << std::endl << "\e[1m" << _name 
				<< " signed \"" << form.getName() << "\" form \e[0m" << std::endl;
	}
	catch ( AForm::GradeTooLowException &e)
	{
		std::cout << std::endl << "\e[1m" << _name 
			<< " couldn’t sign \"" << form.getName() 
			<< "\" form because -> " << "\e[0m" << e.what() << std::endl;
	}
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
	return ("Custom BUREAUCRAT exception: Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Custom BUREAUCRAT exception: Grade is too low!");
}
