/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 18:05:14 by martalop          #+#    #+#             */
/*   Updated: 2025/05/05 20:14:45 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <climits>
#include <cfloat>

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

void	ScalarConverter::convertToChar(const std::string &input, t_inputType &type)
{
	double	res = 0;
	char	char_res;
	
	if (type == CHAR)
	{
		char_res = static_cast<char>(input[0]);
		std::cout << "Char: \'" << char_res << "\'";
	}
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

bool	isSafeInt(const std::string &input)
{
	long int	res;
	
	if (input.length() > 11)
		return (false);
	res = std::atol(input.c_str());
	if (res > INT_MAX || res < INT_MIN)
		return (false);
	return (true);
}

void	ScalarConverter::convertToInt(const std::string &input, t_inputType &type)
{
	if (type == CHAR)
	{
		char	char_res = static_cast<char>(input[0]);
		std::cout << "Int: " << static_cast<int>(char_res);
	}
	else if (type != LITERAL && isSafeInt(input))
		std::cout << "Int: " << std::atoi(input.c_str());
	else
		std::cout << "Int: impossible";
	std::cout << std::endl;
}

bool	isSafeFloat(const std::string &input)
{
	double	res;
	
	res = std::atof(input.c_str());
	if (res > FLT_MAX || res < -FLT_MAX)
		return (false);
	return (true);
}

void	ScalarConverter::convertToFloat(const std::string &input, t_inputType &type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed); // fixed hace que siempre muestre el mismo valor que haya establecido de precision
	if (type == CHAR)
	{
		char	char_res = static_cast<char>(input[0]);
		std::cout << "Float: " << static_cast<float>(char_res) << "f";
	}
	else if (type == LITERAL || isSafeFloat(input))
		std::cout << "Float: " << static_cast<float>(std::atof(input.c_str())) << "f";
	else
		std::cout << "Float: impossible";
	std::cout << std::endl;
}

bool	isSafeDouble(const std::string &input)
{
	long double	res;
	
	res = std::atof(input.c_str());
	if (res > DBL_MAX || res < -DBL_MAX)
		return (false);
	return (true);
}

void	ScalarConverter::convertToDouble(const std::string &input, t_inputType &type)
{
	if (type == CHAR)
	{
		char	char_res = static_cast<char>(input[0]);
		std::cout << "Double: " << static_cast<double>(char_res);
	}
	else if (type == LITERAL || isSafeDouble(input))
		std::cout << "Double: " << std::atof(input.c_str());
	else
		std::cout << "Double: impossible";
	std::cout << std::endl;
}

bool	isInt(const std::string &input)
{
	long unsigned int	i;

	i = 0;
	while (i < input.length())
	{
		if ((i == 0 && (input.at(0) != '+' &&  input.at(0) != '-'))
			&& !std::isdigit(input[0]))
			break;
		if (i != 0 && !std::isdigit(input[i]))
			break;
		i++;
	}
	if (i == input.length())
		return (true);
	return (false);
}

bool	isFloat(const std::string &input)
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

bool	isChar(const std::string &input)
{
	if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
		return (true);
	return (false);
}

bool	isLiteral(const std::string &input)
{
	if (input == "-inf" || input == "+inf" || input == "-inff"
		|| input == "+inff" || input == "nan" || input == "nanf")
		return (true);
	return (false);
}

bool	isDouble(const std::string &input)
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
		if (input[i] == '.' && (point || (input[i -1] && (input[i -1] == '-' || input[i -1] == '+')))) 
			flag = 1;
		if (input[i] == '.' && !point && i != input.length() - 1)
			point = 1;
	}
	if (!flag && point)
		return (true);
	return (false);
}

t_inputType	ScalarConverter::getType(const std::string &input)
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

void	ScalarConverter::convert(const std::string &input)
{
	t_inputType	type;

	type = getType(input); 
	if (type == NDEF)
	{
		std::cout << "Error: Undefined type when expecting char/int/float/double" << std::endl;
		return ;
	}
	convertToChar(input, type);
	convertToInt(input, type);
	convertToFloat(input, type);
	convertToDouble(input, type);
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& var)
{
	std::cout << "copy operator called" << std::endl;
	if (this != &var)
		return (*this);
	return (*this);
}
