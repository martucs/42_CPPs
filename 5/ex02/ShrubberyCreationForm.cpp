/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:49:09 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 21:45:26 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("Shrubbery AForm", 145, 137)
{
	std::cout << "Shrubbery Creation Form constructor called" << std::endl;
	setSignStatus(false);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery AForm", 145, 137)
{
	std::cout << "Shrubbery Creation Form constructor called" << std::endl;
	setSignStatus(false);
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& var): AForm(var)
{
	std::cout << "Shrubbery Creation Form copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Creation Form destructor called" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget(void)
{
	return (_target);
}

void	ShrubberyCreationForm::beSigned(Bureaucrat &var)
{
	if (var.getGrade() > getSignGrade())
		throw GradeTooLowException();
	this->setSignStatus(true);
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& var)
{
	std::cout << "Shrubbery Creation Form copy assignment operator" << std::endl;
	if (this != &var)
	{
		setSignStatus(var.getSignStatus());
	}
	return (*this);
}

