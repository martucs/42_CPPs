/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:47:17 by martalop          #+#    #+#             */
/*   Updated: 2025/04/27 19:58:55 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("Robotomy Request", 75, 45)
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	setSignStatus(false);
	_target = "Random target";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("Robotomy Request", 72, 45)
{
	std::cout << "Robotomy Request Form constructor called" << std::endl;
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& var): AForm(var)
{
	std::cout << "Robotomy Request Form copy constructor called" << std::endl;
	*this = var;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Request Form destructor called" << std::endl;
}

void	RobotomyRequestForm::setTarget(const std::string target)
{
	_target = target;
}

std::string	RobotomyRequestForm::getTarget(void)
{
	return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	if (!getSignStatus())
		throw FormNotSignedException(); 
	if (executor.getGrade() > this->getExecGrade()) 
		throw GradeTooLowException();
	std::cout << std::endl << " *** unbearable drilling noises *** " << std::endl;
	//srand((unsigned int)time(NULL));
	if ((rand() / (float)RAND_MAX) < 0.5)
		std::cout << _target << " has been robotomized successfully " << std::endl;
	else
		std::cout << _target << " could not be robotomized :(" << std::endl;
}	

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& var)
{
	std::cout << "Robotomy Request Form copy assignment operator" << std::endl;
	if (this != &var)
	{
		setSignStatus(var.getSignStatus());
		_target = var._target;
	}
	return (*this);
}
