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

/*bool	readFile(char *	filename, std::fstream& inFile)
{
	inFile.open(filename, std::ios_base::in); 
	if (inFile.fail())
		return (0);
	inFile.close();
	return (1);
}*/

/*void	printDataMap(std::map<std::string, float> dataMap)
{
	std::map<std::string, float>::iterator	it;
	it = dataMap.begin();
	while (it != dataMap.end())
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
}*/

/*std::map<std::string, float>*	storeDataBase(void)
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
		dataMap->insert(std::pair<std::string, float>(key, std::atof(value.c_str())));	
		buffer.clear();
	}
//	printDataMap(*dataMap);
	return (dataMap);
}*/

/*int	isInvalidNum(const std::string &value)
{
	int		point;
	long int	int_res;
	double		float_res;
	
	int_res = std::atol(value.c_str());
	float_res = std::atof(value.c_str());
	if (value.length() > 11 || int_res > 1000 || float_res > 1000)
		return (1);
	point = 0;
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.' && !point && i != value.length() - 1)
			point = 1;
		if ((!std::isdigit(value[i]) && !point) || 
			(!std::isdigit(value[i]) && value[i] != '.'))
			return (2);
	}
	return (0);
}

int	isInvalidDate(const std::string &date)
{
	int	year;
	int	month;
	int	day;

	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (1);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(date[i]))
			return (1);
	}
	year = std::atoi(date.substr(0, 4).c_str());
	if (year > 2025)
		return (2);
	month = std::atoi(date.substr(5, 2).c_str());
	if (month > 12 || month < 1)
		return (3);
	day = std::atoi(date.substr(8, 2).c_str());
	if (day > 31 || day < 1)
		return (4);
	// FEBRERO
	if (month == 2 && (day > 29 || (day > 28 && year % 4 != 0)))
		return (4);
	// MESES QUE NO TERMINAN EN 31
	if (day == 31)
	{
		int	month_30[4] = {4, 6, 9, 11};
		int	*p = std::find(month_30, month_30 + 4, month);
		if (p != month_30 + 4)
			return (4);
	}
	return (0);
}

bool	checkValidity(std::string date, std::string value)
{
	int	res = 0;

	res = isInvalidDate(date);
	if (res != 0)
	{
		std::cout << "Error: invalid date";
		if (res == 1)
			std::cout << " -> date too long or non-digit found" << std::endl;
		if (res == 2)
			std::cout << " -> invalid year" << std::endl;
		if (res == 3)
			std::cout << " -> invalid month" << std::endl;
		if (res == 4)
			std::cout << " -> invalid day" << std::endl;
		return (false);
	}
	res = isInvalidNum(value);
	if (res != 0)
	{
		std::cout << "Error: invalid value";
		if (res == 1)
			std::cout << " -> value too big/too small (from 0 to 100 allowed)" << std::endl;
		if (res == 2)
			std::cout << " -> num is not postive int/float" << std::endl;
		return (false);
	}
	return (true);
}

std::string	closestDate(const std::string date, std::map<std::string, float> &dataBase)
{
	std::map<std::string, float>::iterator	it;
	
	it = dataBase.find(date); 
	if (it != dataBase.end())
		return (date); // exact date found
	else
	{
		it = dataBase.lower_bound(date); // first bigger than date
		it--;
		return (it->first);
	}
}

float	multiplyValue(const std::string date, const std::string value, std::map<std::string, float>& dataBase)
{
	return (dataBase[date] * std::atof(value.c_str()));
}

void	calculatePrice(std::string inFileName, std::map<std::string, float>& dataBase)
{
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
		}
		else
		{
			std::cout << "Error: invalid format" << std::endl;
			continue;
		}
		if (!checkValidity(date, value))
			continue;
		std::cout << date << " -> " << value << " = " 
			<< multiplyValue(closestDate(date, dataBase), value, dataBase) << std::endl;
		buffer.clear();
	}
}*/

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc infile.txt" << std::endl;
		return (1);
	}
//	try
//	{
		BitcoinExchange	exchange("./data.csv");
		
	//	exchange.printDataBase();
		exchange.calculatePrice(argv[1]);
//	}
//	catch (std::exception &e)
//	{
//		std::cout << std::endl << e.what() << std::endl;
//	}
//	if (!readFile(argv[1], inFile))	
//	{
//		std::cout << "Error: failed to open file" << std::endl;
//		return (1);
//	}
//	calculatePrice(argv[1], *dataBase);
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
