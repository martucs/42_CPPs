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
	return (dataMap);
}

bool	isValidNum(const std::string &value)
{
	int		point;
	long int	int_res;
	double		float_res;
	
	int_res = std::atol(value.c_str());
	float_res = std::atof(value.c_str());
	if (value.length() > 11 || int_res > 1000 || float_res > 1000)
		return (false);
	point = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.' && !point && i != value.length() - 1)
			point = 1;
		if ((!std::isdigit(value[i]) && !point) || 
			(!std::isdigit(value[i]) && value[i] != '.'))
			return (false);
	}
	return (true);
}

bool	isValidDate(const std::string &date)
{
	(void)date;
	int	year;
	int	month;
	int	day;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	year = std::atoi(date.substr(0, 4).c_str());
//	std::cout << "year = " << year <<std::endl;
	if (year > 2025)
		return (false);
	month = std::atoi(date.substr(5, 2).c_str());
//	std::cout << "month = " << month <<std::endl;
	if (month > 12 || month < 01)
		return (false);
	day = std::atoi(date.substr(8, 2).c_str());
//	std::cout << "day = " << day <<std::endl;
	if (day > 31 || day < 1)
		return (false);
	return (true);
}

/*bool	checkValueFormat(std::string value, std::map<std::string, float> dataBase)
{
	(void)dataBase;
	
	if (!isValidNum(value))
		return (false);
	return (true);
}*/

std::string	closestDate(const std::string date, std::map<std::string, float> &dataBase)
{
	std::map<std::string, float>::iterator	it;
	
	it = dataBase.find(date); 
	if (it != dataBase.end())
	{
	//	std::cout << "exact date found" << std::endl;
		return (date);
	}
	else
	{
	//	std::cout << "not exact date found" << std::endl;
		it = dataBase.begin();
	//	for (it != dataBase.end(); it++)
	//	{

	//	}
	}
	return (date);
}

float	multiplyValue(const std::string date, const std::string value, std::map<std::string, float>& dataBase)
{
	std::cout << "database value = " << dataBase[date] << std::endl;
	return (dataBase[date] * std::atof(value.c_str()));
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
		// checkFormat(date, dataBase)
		if (!isValidDate(date))
			std::cout << "invalid date" << std::endl;
		if (!isValidNum(value))
			std::cout << "invalid value" << std::endl;
		std::cout << std::endl;
	//	std::cout << multiplyValue(closestDate(date, dataBase), value, dataBase) << std::endl;
//		std::cout << date << " -> " << value << " = " 
//			<< multiplyValue(closestDate(date, dataBase), value, dataBase) << std::endl;
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
