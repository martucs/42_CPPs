/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:50:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/23 19:57:57 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat	b("Bob", 15);
		Form		e("English Certificate", 15, 1);
	
		std::cout << std::endl;	
		std::cout << b << std::endl;
		std::cout << e << std::endl;
		b.decrementGrade();
		b.signForm(e);
		std::cout << std::endl;	
		std::cout << e << std::endl;
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
