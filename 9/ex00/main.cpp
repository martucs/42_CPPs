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
//	checkFormat(inFile);
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
