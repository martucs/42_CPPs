/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:50:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/26 20:17:08 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	E("E", 2);
		Intern		randomdude;
		AForm		*form;
		
		std::cout << std::endl;
		form = randomdude.makeForm("Presidential Pardon", "Marta");
		std::cout << std::endl;
		
		std::cout << E << std::endl;
		std::cout << *form << std::endl;
		
		form->beSigned(E);
		std::cout << "\e[1m" << form->getName() << " form was successfully signed by " << E.getName() << "\e[0m" << std::endl;
		form->execute(E);
		std::cout << std::endl << "\e[1m" << form->getName() << " form was successfully executed by " << E.getName() << "\e[0m" << std::endl << std::endl;
	}
	catch (Intern::NonExistentFormException &e)
	{
		std::cout << std::endl << "\e[1m" << "problems to create form " << "\e[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << std::endl << "\e[1m" << "problems to sign/execute " << "\e[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
