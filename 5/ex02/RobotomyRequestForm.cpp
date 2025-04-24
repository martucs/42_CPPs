/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:47:17 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 16:14:44 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy AForm", 75, 45)
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	setSignStatus(false);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy AForm", 72, 45)
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	setSignStatus(false);
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& var): AForm(var)
{
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

void	RobotomyRequestForm::beSigned(Bureaucrat var)
{
	if (var.getGrade() > getSignGrade())
		throw GradeTooLowException();
	this->setSignStatus(true);
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& var)
{
	std::cout << "Robotomy Request Form copy assignment operator" << std::endl;
	if (this != &var)
	{
		setSignStatus(var.getSignStatus());
	}
	return (*this);
}
