/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:01:20 by martalop          #+#    #+#             */
/*   Updated: 2025/05/14 16:01:44 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*int	main()
{
	Span sp = Span(5);

	std::cout << std::endl;
	try
	{
		sp.addNumber(1);
	}
	catch (Span::FullSpan &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << std::endl;
	}
	std::cout << sp << std::endl;
	try
	{
		std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
		std::cout << "longest span = " << sp.longestSpan() << std::endl;
	}
	catch (Span::NotEnoughSpanInfo &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}*/

int	main()
{
	Span sp = Span(5);

	std::cout << std::endl;
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	try
	{
		sp.addNumber(1);
	}
	catch (Span::FullSpan &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << std::endl;
	}
	std::cout << sp << std::endl;
	std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "longest span = " << sp.longestSpan() << std::endl;
	std::cout << std::endl;
	return (0);
}
