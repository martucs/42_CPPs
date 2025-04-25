/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:50:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/25 20:00:54 by martalop         ###   ########.fr       */
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
		Bureaucrat	C("C", 150);
    	//PresidentialPardonForm	h("marta");
		//RobotomyRequestForm	h("marta");
		ShrubberyCreationForm	h("marta");

		std::cout << std::endl;
		std::cout << C;
		std::cout << h;
		std::cout << "- Target = " << h.getTarget() << std::endl;
		C.signForm(h);
	//	h.beSigned(C);
	//	std::cout << std::endl << "\e[1m" << h.getName() << " form was successfully signed by " << C.getName() << "\e[0m" << std::endl;
		try
		{
			C.executeForm(h);
			//h.execute(C);
			//std::cout << std::endl << "\e[1m" << h.getName() << " form was successfully executed by " << C.getName() << "\e[0m" << std::endl;
		}
		catch (AForm::GradeTooLowException &e) 
		{
			std::cout << std::endl;
			std::cout << "\e[1mproblems to execute\e[0m" << std::endl;
			std::cout << e.what() << std::endl;
		}
		catch (AForm::FormNotSignedException &e)  // Quitar firma para que entre aqui
		{
			std::cout << std::endl;
			std::cout << "\e[1mproblems to execute\e[0m" << std::endl;
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	catch (AForm::GradeTooLowException &e) 
	{
		std::cout << std::endl;
		std::cout << "\e[1mproblems to sign\e[0m" << std::endl;
		std::cout << e.what() << std::endl;
	}
	return (0);
}
