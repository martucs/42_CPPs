/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:50:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/23 13:27:02 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("Bob", 2);
		Bureaucrat	c;

		std::cout << std::endl;
		std::cout << c << std::endl;
	
		b.incrementGrade();
		std::cout << b << std::endl;
		c.decrementGrade();
		std::cout << c << std::endl;
		
		c = b;
		std::cout << c << std::endl;
		throw 20;
	}
	catch (std::exception& e)
	{
		std::cout << std::endl << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "default exception was caught " << std::endl;
	}
	return (0);
}
