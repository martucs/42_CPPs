/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:01:20 by martalop          #+#    #+#             */
/*   Updated: 2025/05/19 20:33:00 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>
#include <vector>
#include <climits>
#include <cstdlib>

// addRange() TEST
/*int	main()
{
	Span	secondSpan(10000);
	std::vector<int>	vector1;
	
	vector1.assign(5000, 100);

	secondSpan.addRange(vector1.begin(), vector1.end());
	std::cout << secondSpan << std::endl;

	std::list<int>	numbers;
	
	numbers.assign(5000, 42);

	secondSpan.addRange(numbers.begin(), numbers.end());
	std::cout << secondSpan << std::endl;
//	try 
//	{
//		secondSpan.addRange(numbers.begin(), numbers.end());
//	}
//	catch (std::exception &e)
//	{
//		std::cout << "Exception: " <<  e.what() << std::endl;
//	}
	return (0);
}*/

// Exceptions TEST
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
		std::cout << "longest span = " << sp.longestSpan() << std::endl;
		std::cout << "shortest span = " << sp.shortestSpan() << std::endl;
	}
	catch (Span::NotEnoughSpanInfo &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	return (0);
}*/

// main TEST
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
		//sp.addNumber(1);
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
}
