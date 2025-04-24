/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:44:44 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 16:05:12 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon AForm", 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	setSignStatus(false);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon AForm", 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	setSignStatus(false);
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& var): AForm(var)
{
	std::cout << "Presidential Pardon Form copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon Form destructor called" << std::endl;
}

void	PresidentialPardonForm::beSigned(Bureaucrat var)
{
	if (var.getGrade() > getSignGrade())
		throw GradeTooLowException();
	this->setSignStatus(true);
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& var)
{
	std::cout << "Presidential Pardon Form copy assignment operator" << std::endl;
	if (this != &var)
	{
		setSignStatus(var.getSignStatus());
	}
	return (*this);
}

