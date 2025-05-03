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
#include <cstdlib>
#include <climits>

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

void	convertToChar(std::string input, t_inputType type)
{
	double	res = 0;
	
	if (type == CHAR)
		std::cout << "Char: \'" << input[0] << "\'";
	if (type == INT || type == FLOAT || type == DOUBLE)
	{
		if (type == INT)
			res = std::atoi(input.c_str());
		else
			res = std::atof(input.c_str());
		if (res >= 0 && res <= 255 && std::isprint(res))
			std::cout << "Char: \'" << static_cast<unsigned char>(res) << "\'";
		else
			std::cout << "Char: non displayable";
	}
	if (type == LITERAL)
		std::cout << "Char: impossible";
	std::cout << std::endl;
}

void	convertToInt(std::string input, t_inputType type)
{
	long int	res;
	int	flag;
	
	flag = 0;
	if (input.length() > 10)
		flag = 1;
	res = std::atol(input.c_str());
	std::cout << "Int MIN =  " << INT_MIN << std::endl;
	std::cout << "Int MAX =  " << INT_MAX << std::endl;
	std::cout << std::endl;
	std::cout << "res = " << res << std::endl;
	if (res > INT_MAX || res < INT_MIN)
		flag = 1;
	if (type == INT && !flag)
		std::cout << "Int: " << static_cast<int>(res);
	else
		std::cout << "Int: impossible";
	std::cout << std::endl;

}

void	convertToFloat(std::string input, t_inputType type)
{
	(void)input;
	(void) type;
 	std::cout << "converting input to float..." << std::endl;
}

void	convertToDouble(std::string input, t_inputType type)
{
	(void)input;
	(void) type;
 	std::cout << "converting input to double..." << std::endl;
}


bool	isInt(const std::string input)
{
	long unsigned int	i;

	i = 0;
	while (i < input.length())
	{
		if ((i == 0 && (input.at(0) != '+' &&  input.at(0) != '-'))
			&& !std::isdigit(input[0]))
		{
			std::cout << "I entered break 1" << std::endl;
			break;
		}
		if (i != 0 && !std::isdigit(input[i]))
		{
			std::cout << "I entered break 2" << std::endl;
			break;
		}
		i++;
	}
	if (i == input.length())
		return (true);
	return (false);
}

bool	isFloat(const std::string input)
{
	int			point;
	long unsigned int	i;
	int			flag;

	flag = 0;
	point = 0;
	for (i = 0; i < input.length(); i++)
	{
		if ((i == 0 && (input.at(0) != '+' &&  input.at(0) != '-'))
			&& !std::isdigit(input[0]))
			flag = 1;
		if (i != input.length() - 1 && i != 0 && !std::isdigit(input[i]) && input[i] != '.')
			flag = 1;
		if (input[i] == '.' && ( point || (input[i +1] && input[i +1] == 'f') 
					|| (input[i - 1] && !std::isdigit(input[i - 1]))))
			flag = 1;
		if (input[i] == '.' && !point)
			point = 1;
	}
	if (!flag)
	{
		if (input[input.length() - 1] == 'f')
			return (true);
	}
	return (false);
}

bool	isChar(const std::string input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (true);
	return (false);
}

bool	isLiteral(const std::string input)
{
	if (input == "-inf" || input == "+inf" || input == "-inff"
			|| input == "+inff" || input == "nan")
		return (true);
	return (false);
}

bool	isDouble(const std::string input)
{
	int			point;
	long unsigned int	i;
	int			flag;

	flag = 0;
	point = 0;
	for (i = 0; i < input.length(); i++)
	{
		if ((i == 0 && (input.at(0) != '+' &&  input.at(0) != '-'))
			&& !std::isdigit(input[0]))
			flag = 1;
		if (i != 0 && !std::isdigit(input[i]) && input[i] != '.')
			flag = 1;
		if (input[i] == '.' && point ) 
			flag = 1;
		if (input[i] == '.' && !point && i != input.length() - 1)
			point = 1;
	}
	if (!flag && point)
		return (true);
	return (false);
}

t_inputType	getType(const std::string input)
{
	if (input.empty())
		return (NDEF);
	if (isChar(input))
		return (CHAR);
	if (isLiteral(input))
		return (LITERAL);
	if (isInt(input))
		return (INT);
	if (isFloat(input))
		return (FLOAT);
	if (input.find('f') == std::string::npos && isDouble(input))
		return (DOUBLE);
	return (NDEF);
}

void	ScalarConverter::convert(const std::string input)
{
	t_inputType	type;

	std::cout << "I want to convert: " << input << std::endl;
	type = getType(input); 
	std::cout << "Type = " << type << std::endl;

	if (type == NDEF)
	{
		std::cout << "Error: Undefined type when expecting int/float/double" << std::endl;
		return ;
	}
	std::cout << std::endl;

	convertToChar(input, type);
	convertToInt(input, type);
	convertToFloat(input, type);
	convertToDouble(input, type);
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
