/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:37:05 by martalop          #+#    #+#             */
/*   Updated: 2025/05/04 23:02:46 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"


/*void	basic_tests()
{
	ScalarConverter::convert("a");
	std::cout << std::endl;
	ScalarConverter::convert("aa");
	std::cout << std::endl;
	ScalarConverter::convert("ç");
	std::cout << std::endl;
	ScalarConverter::convert("0");
	std::cout << std::endl;
	ScalarConverter::convert("6");
	std::cout << std::endl;
	ScalarConverter::convert("123");
	std::cout << std::endl;
	ScalarConverter::convert("+123");
	std::cout << std::endl;
	ScalarConverter::convert("-123");
	std::cout << std::endl;
	ScalarConverter::convert(".");
	std::cout << std::endl;
	ScalarConverter::convert("f");
	std::cout << std::endl;
	ScalarConverter::convert(".f");
	std::cout << std::endl;
	ScalarConverter::convert("0.0");
	std::cout << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout << std::endl;
	ScalarConverter::convert("0.f");
	std::cout << std::endl;
	ScalarConverter::convert("0f");
	std::cout << std::endl;
	ScalarConverter::convert("+3123.0f");
	std::cout << std::endl;
	ScalarConverter::convert("-3123.0f");
	std::cout << std::endl;
	ScalarConverter::convert("032.0");
	std::cout << std::endl;
	ScalarConverter::convert("-32.0");
	std::cout << std::endl;
	ScalarConverter::convert("+32.0");
	std::cout << std::endl;
	ScalarConverter::convert("f132.0");
	std::cout << std::endl;
	ScalarConverter::convert("132f0.");
	std::cout << std::endl;
	ScalarConverter::convert("nanf");
	std::cout << std::endl;
	ScalarConverter::convert("nan");
	std::cout << std::endl;
	ScalarConverter::convert("+inf");
	std::cout << std::endl;
	ScalarConverter::convert("-inf");
	std::cout << std::endl;
	ScalarConverter::convert("+inff");
	std::cout << std::endl;
	ScalarConverter::convert("  -inff  ");
	std::cout << std::endl;
	ScalarConverter::convert("2147483647");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483648");
	std::cout << std::endl;
	ScalarConverter::convert("2147483650");
	std::cout << std::endl;
	ScalarConverter::convert("-2147483650");
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (basic_tests(), 0);
	ScalarConverter::convert(argv[1]);
	return 0;
}*/

int	main(int argc, char **argv)
{
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Error: program must receive 1 argument" << std::endl;
	return (0);
}
