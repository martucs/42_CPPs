/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:50:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/25 15:47:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	try
	{
		Bureaucrat	C("C", 5);
		//PresidentialPardonForm	h("Marta");
		RobotomyRequestForm	h("Marta");
		//ShrubberyCreationForm	h("Marta");

		std::cout << std::endl;
		std::cout << C;
		std::cout << h;
		std::cout << "- Target = " << h.getTarget() << std::endl << std::endl;
		h.beSigned(C);
		try
		{
			h.execute(C);
			h.execute(C);
			h.execute(C);
			h.execute(C);
		}
		catch (std::exception &e) 
		{
			std::cout << std::endl;
			std::cout << "\e[1mproblems to execute\e[0m" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	catch (std::exception &e) 
	{
		std::cout << std::endl;
		std::cout << "\e[1mproblems to sign\e[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
