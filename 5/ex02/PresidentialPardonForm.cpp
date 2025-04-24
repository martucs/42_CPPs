/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:44:44 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 23:00:15 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	setSignStatus(false);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	setSignStatus(false);
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& var): AForm(var)
{
	std::cout << "Presidential Pardon copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon destructor called" << std::endl;
}

std::string	PresidentialPardonForm::getTarget(void)
{
	return (_target);
}

void	PresidentialPardonForm::beSigned(Bureaucrat& var)
{
	if (var.getGrade() > getSignGrade())
		throw GradeTooLowException();
	this->setSignStatus(true);
	std::cout << "\e[1m" << getName() << " form was successfully signed by " << var.getName() << "\e[0m" << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	(void)executor;
	if (!getSignStatus())
		throw FormNotSignedException(); 
	if (executor.getGrade() > this->getExecGrade()) 
		throw GradeTooLowException();
	std::cout << "\e[1m" << getName() << " form was successfully executed by " << executor.getName() << "\e[0m" << std::endl;
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

