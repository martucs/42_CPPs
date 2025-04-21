/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:50:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/20 21:56:01 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	b;

	std::cout << std::endl;
	std::cout << b << std::endl;
	try
	{
		//throw std::runtime_error("something happened");
		throw 20;
	}
	catch (std::exception& e)
	{
		std::cout << "I caught: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "default exception was caught " << std::endl;
	}
	std::cout << std::endl;
	return (1);
}
