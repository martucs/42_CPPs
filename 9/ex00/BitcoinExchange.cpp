/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:24:00 by martalop          #+#    #+#             */
/*   Updated: 2025/06/12 19:24:02 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <algorithm>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const std::string dataPath)
{
	std::fstream	dataFile;
	std::string	buffer;
	std::string	key;
	std::string	value;
	
	// Open file
	dataFile.open(dataPath.c_str(), std::ios_base::in); 
	if (dataFile.fail())
		throw std::runtime_error("Error: could not open database file");
//	std::cout.setf(std::ios::fixed); 
//	std::cout.precision(2);
	// Read file
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
		// Store in std::map (line by line)
		_dataBase.insert(std::pair<std::string, float>(key, std::atof(value.c_str())));	
		buffer.clear();
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& var)
{
	*this = var;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& var)
{
	if (this != &var)
	{
		_dataBase.clear();
		_dataBase.insert(var._dataBase.begin(), var._dataBase.end());
	}
	return (*this);
}

void	BitcoinExchange::printDataBase(void)
{
	std::map<std::string, float>::iterator	it;

	it = _dataBase.begin();
	while (it != _dataBase.end())
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
}

float	BitcoinExchange::multiplyValue(const std::string date, const std::string value)
{
	return (_dataBase[date] * std::atof(value.c_str()));
}

std::string	BitcoinExchange::closestDate(const std::string fileDate)
{
	std::map<std::string, float>::iterator	it;
	
	it = _dataBase.find(fileDate); 
	if (it != _dataBase.end())
	{
		return (fileDate); // exact date found
	}
//	else if (fileDate < _dataBase.begin()->first)
//		return (NULL); // date is too low
	else
	{
		it = _dataBase.upper_bound(fileDate); // first bigger than filedate
		it--;
		return (it->first);
	}
}

int	isInvalidNum(const std::string &value)
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
			return (5);
	}
	year = std::atoi(date.substr(0, 4).c_str());
	if (year > 2022 || year < 2009)
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

bool	BitcoinExchange::checkValidity(std::string date, std::string value)
{
	int	res = 0;

	res = isInvalidDate(date);
	if (res != 0)
	{
		std::cout << "Error: invalid date";
		if (res == 1)
			std::cout << " -> date too long/not properly separated" << std::endl;
		if (res == 2)
			std::cout << " -> invalid year" << std::endl;
		if (res == 3)
			std::cout << " -> invalid month" << std::endl;
		if (res == 4)
			std::cout << " -> invalid day" << std::endl;
		if (res == 5)
			std::cout << " -> non-digit found" << std::endl;
		return (false);
	}
	res = isInvalidNum(value);
	if (res != 0)
	{
		std::cout << "Error: invalid value";
		if (res == 1)
			std::cout << " -> num is too big (from 0 to 100 allowed)" << std::endl;
		if (res == 2)
			std::cout << " -> num is not postive int/float" << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::calculatePrice(const std::string inputFileName)
{
	std::fstream	inFile;
	std::string	buffer;
	std::string	date;
	std::string	value;

	inFile.open(inputFileName.c_str(), std::ios_base::in);
	if (inFile.fail())
		throw std::runtime_error("Error: could not open input file");
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
		std::cout << date << " -> " << value << " = " << multiplyValue(closestDate(date), value) << std::endl;
		buffer.clear();
	}
}

