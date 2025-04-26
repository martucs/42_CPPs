/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:05:15 by martalop          #+#    #+#             */
/*   Updated: 2025/04/26 20:18:12 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
	formNames[0] = "Presidential Pardon";
	formNames[1] = "Robotomy Request";
	formNames[2] = "Shrubbery Creation";
	allFormsPtr[0] = &Intern::makePresidentialForm;
	allFormsPtr[1] = &Intern::makeRobotomyForm;
	allFormsPtr[2] = &Intern::makeShrubberyForm;
}

Intern::Intern(const Intern& var)
{
	std::cout << "Intern constructor called" << std::endl;
	*this = var;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*Intern::makePresidentialForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRobotomyForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::makeShrubberyForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::makeForm(const std::string name, const std::string target)
{
	int		i;
	AForm	*form;

	form = NULL;
	i = 0;
	while (i < 3)
	{
		if (name == formNames[i])
			form = (this->*allFormsPtr[i])(target);
		i++;
	}
	if (!form)
		throw NonExistentFormException();
	return (form);
}

Intern&	Intern::operator=(const Intern& var)
{
	(void)var;
	return (*this);
}

const char	*Intern::NonExistentFormException::what(void) const throw()
{
	return ("Exception: Form doesn't exist!");
}
