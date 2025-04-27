/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:44:44 by martalop          #+#    #+#             */
/*   Updated: 2025/04/27 19:53:38 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("Presidential Pardon", 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	setSignStatus(false);
	_target = "Random target";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("Presidential Pardon", 25, 5)
{
	std::cout << "Presidential Pardon Form constructor called" << std::endl;
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& var): AForm(var)
{
	std::cout << "Presidential Pardon copy constructor called" << std::endl;
	*this = var;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Pardon destructor called" << std::endl;
}

void	PresidentialPardonForm::setTarget(const std::string target)
{
	_target = target;
}

std::string	PresidentialPardonForm::getTarget(void)
{
	return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	if (!this->getSignStatus())
		throw FormNotSignedException(); 
	if (executor.getGrade() > this->getExecGrade()) 
		throw GradeTooLowException();
	std::cout << std::endl <<  _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}	

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& var)
{
	std::cout << "Presidential Pardon Form copy assignment operator" << std::endl;
	if (this != &var)
	{
		setSignStatus(var.getSignStatus());
		_target = var._target;
	}
	return (*this);
}

