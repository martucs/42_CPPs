/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:05:14 by martalop          #+#    #+#             */
/*   Updated: 2025/04/30 15:34:29 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter constructor called" << std::endl;
}
// INFO: El constructor está en privado, así que no será instanciable

ScalarConverter::ScalarConverter(const ScalarConverter& var)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = var;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

void	convertToChar(std::string input)
{
	(void)input;
	std::cout << "converting input to char..." << std::endl;
}

t_inputType	getType(const std::string input)
{
	if (std::isalpha(input[0]))
		return (CHAR);
	return (NDEF);
}

void	ScalarConverter::convert(const std::string input)
{
	t_inputType	type;

	std::cout << "I want to convert: " << input << std::endl;
	type = getType(input); 
	std::cout << "Type = " << type << std::endl;
	
	// si es char
	/*if (type == CHAR)
	{
	}*/
	// si es int
	// si es float
	// si es double

	// PRINT
	// - char
		//convertToChar(input);
	// - int
	// - float
	// - double
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& var)
{
	std::cout << "copy operator called" << std::endl;
	if (this != &var)
	{
		return (*this);
	}
	return (*this);
}
