/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:18:51 by martalop          #+#    #+#             */
/*   Updated: 2025/04/23 17:07:44 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Random Form"), _requiredSignGrade(150), _requiredExecGrade(150)
{
	std::cout << "Form constructor called" << std::endl;
	_signStatus = false;
}

Form::Form(const std::string name, int signGrade, int execGrade ): _name(name), _requiredSignGrade(signGrade), _requiredExecGrade(execGrade)
{
	std::cout << "Form complete constructor called" << std::endl;
	if (signGrade <= 0 || execGrade <= 0)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signStatus = false;
	std::cout << "*No issues creating Form " << _name << "*" << std::endl;
}

Form::Form(const Form& var): _name(var._name), _requiredSignGrade(var._requiredSignGrade), _requiredExecGrade(var._requiredExecGrade)
{
	std::cout << "Form constructor called" << std::endl;
	*this = var;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

int	Form::getSignGrade(void) const
{
	return (_requiredSignGrade);
}

int	Form::getExecGrade(void) const
{
	return (_requiredExecGrade);
}

int	Form::getSignStatus(void) const
{
	return (_signStatus);
}

std::string	Form::getName(void) const
{
	return (_name);
}

void	Form::beSigned(Bureaucrat var)
{
	if (var.getGrade() > _requiredSignGrade)
		throw GradeTooLowException();
	_signStatus = true;
}

Form&	Form::operator=(const Form& var)
{
	if (this != &var)
		_signStatus = var._signStatus;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const Form& var)
{
	os << var.getName() << " Form:" << std::endl;
	if (var.getSignStatus())
		os << "- Status: signed" << std::endl;
	else
		os << "- Status: unsigned" << std::endl;
	os << "- Requiered signature grade: " << var.getSignGrade() << std::endl;
	os << "- Requiered execution grade: " << var.getExecGrade() << std::endl;
	return (os);
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Custom FORM exception: Grade is too high!");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Custom FORM exception: Grade is too low!");
}

