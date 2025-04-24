/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:18:51 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 15:22:37 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("Random AForm"), _requiredSignGrade(150), _requiredExecGrade(150)
{
	std::cout << "AForm constructor called" << std::endl;
	_signStatus = false;
}

AForm::AForm(const std::string name, int signGrade, int execGrade ): _name(name), _requiredSignGrade(signGrade), _requiredExecGrade(execGrade)
{
	std::cout << "AForm complete constructor called" << std::endl;
	if (signGrade <= 0 || execGrade <= 0)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	_signStatus = false;
	std::cout << "*No issues creating AForm " << _name << "*" << std::endl;
}

AForm::AForm(const AForm& var): _name(var._name), _requiredSignGrade(var._requiredSignGrade), _requiredExecGrade(var._requiredExecGrade)
{
	std::cout << "AForm constructor called" << std::endl;
	*this = var;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

int	AForm::getSignGrade(void) const
{
	return (_requiredSignGrade);
}

int	AForm::getExecGrade(void) const
{
	return (_requiredExecGrade);
}

int	AForm::getSignStatus(void) const
{
	return (_signStatus);
}

std::string	AForm::getName(void) const
{
	return (_name);
}

void	AForm::setSignStatus(bool status)
{
	_signStatus = status;
}

void	AForm::beSigned(Bureaucrat var)
{
	if (var.getGrade() > _requiredSignGrade)
		throw GradeTooLowException();
	_signStatus = true;
}

AForm&	AForm::operator=(const AForm& var)
{
	if (this != &var)
		_signStatus = var._signStatus;
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const AForm& var)
{
	os << var.getName() << " AForm:" << std::endl;
	if (var.getSignStatus())
		os << "- Status: signed" << std::endl;
	else
		os << "- Status: unsigned" << std::endl;
	os << "- Requiered signature grade: " << var.getSignGrade() << std::endl;
	os << "- Requiered execution grade: " << var.getExecGrade() << std::endl;
	return (os);
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("Custom FORM exception: Grade is too high!");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("Custom FORM exception: Grade is too low!");
}

