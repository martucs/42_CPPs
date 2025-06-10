/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:37:27 by martalop          #+#    #+#             */
/*   Updated: 2025/05/29 18:44:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <climits>

bool	readFile(char *	filename, std::fstream& inFile)
{
	inFile.open(filename, std::ios_base::in); 
	if (inFile.fail())
		return (0);
	inFile.close();
	return (1);
}

void	printDataMap(std::map<std::string, float> dataMap)
{
	std::map<std::string, float>::iterator	it;
	it = dataMap.begin();
	while (it != dataMap.end())
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
}

std::map<std::string, float>*	storeDataBase(void)
{
	std::fstream			dataFile;
	std::map<std::string, float>	*dataMap;
	std::string			buffer;
	std::string			key;
	std::string			value;

	std::cout.setf(std::ios::fixed); 
	std::cout.precision(2);
	
	dataMap = new std::map<std::string, float>;

	dataFile.open("./data.csv", std::ios_base::in);
	std::getline(dataFile, buffer);
	buffer.clear();
	while (true)
	{
		std::getline(dataFile, buffer);
		if (dataFile.eof())
			break;
		std::string::size_type	pos;
		
		pos = buffer.find(',', 0);
		key = buffer.substr(0, pos);
		value = buffer.substr(pos + 1, buffer.npos);
	//	std::cout << "buffer = " << value << std::endl;
	//	std::cout << "atof = " << std::atof(value.c_str()) << std::endl;
		dataMap->insert(std::pair<std::string, float>(key, std::atof(value.c_str())));	
		buffer.clear();
	}
//	printDataMap(*dataMap);
	std::cout << "finished reading file" << std::endl;
	return (dataMap);
}

bool	isPositiveInt(const std::string &input)
{
	long unsigned int	i;
	int			point;
	long int	int_res;
	double		float_res;
	
	int_res = std::atol(input.c_str());
	float_res = std::atof(input.c_str());
	if (input.length() > 11 || int_res > 1000 || float_res > 1000)
		return (false);
	i = 0;
	point = 0;
	while (i < input.length())
	{
		if (input[i] == '.')
			point = 1;
		if (!std::isdigit(input[i]) && input[i] != '.')
			break;
		i++;
	}
	if (i != input.length())
		return (false);
	return (true);
}

bool	isPositiveDouble(const std::string &input)
{
	int			point;
	long unsigned int	i;
	int			flag;

	flag = 0;
	point = 0;
	for (i = 0; i < input.length(); i++)
	{
		if (i == 0 && !std::isdigit(input[0]))
			flag = 1;
		if (i != 0 && !std::isdigit(input[i]) && input[i] != '.')
			flag = 1;
		if (input[i] == '.' && (point || (input[i -1] && input[i -1] == '+'))) 
			flag = 1;
		if (input[i] == '.' && !point && i != input.length() - 1)
			point = 1;
	}
	if (!flag && point)
		return (true);
	return (false);
}
bool	checkValueFormat(std::string value, std::map<std::string, float> dataBase)
{
	(void)dataBase;
	
	if (!isPositiveInt(value))
		return (false);
	return (true);
}

void	calculatePrice(std::string inFileName, std::map<std::string, float>& dataBase)
{
	(void)dataBase;
	std::fstream	inFile;
	std::string	buffer;
	std::string	date;
	std::string	value;

	inFile.open(inFileName.c_str(), std::ios_base::in);
	std::getline(inFile, buffer);
	buffer.clear();
	while (true)
	{
		std::getline(inFile, buffer);
		if (inFile.eof())
			break;
		std::string::size_type	pos;
		
		pos = buffer.find(" | ", 0);
		if (pos != buffer.npos)
		{
			date = buffer.substr(0, pos);
			value = buffer.substr(pos + 3, buffer.npos);
			std::cout << "date = \'" << date << "\', value = \'" << value << "\'" << std::endl;
		}
		else
		{
			std::cout << "invalid format" << std::endl;
			continue;
		}
		// checkDateFormat(date, dataBase)
		if (!checkValueFormat(value, dataBase))
			std::cout << "invalid value format" << std::endl;
		
		// std::cout << multiplyvalue(date, value, dataBase) << std::endl;
		buffer.clear();
	}
}

int	main(int argc, char **argv)
{
	std::fstream			inFile;
	std::map<std::string, float>	*dataBase;

	if (argc != 2)
	{
		std::cout << "Usage: ./btc infile.txt" << std::endl;
		return (1);
	}
	dataBase = storeDataBase();
	if (!readFile(argv[1], inFile))	
	{
		std::cout << "Error: failed to open file" << std::endl;
		return (1);
	}
	calculatePrice(argv[1], *dataBase);
	delete dataBase;
	return (0);
}

// INFO: PROGRAM HAS TO:
	// 1. store database in "./data.csv" in a std::map
	// 2. open file 'argv[1]'
		// if not possible -> "error: could not open file" 
	// 3. store info ?
	// 4. check that file is in correct format
		// error if invalid date 
		// error if negative value
		// error if num is bigger than int
		// error if there is no num or date
	// 5. multiply value * exchange rate 
	// 6. show result (date -> value = result)
