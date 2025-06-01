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

bool	readFile(char *	filename)
{
	std::fstream	inFile;

	inFile.open(filename, std::ios_base::in); 
	if (inFile.fail())
	{
		std::cout << "Error: failed to open file" << std::endl;
		return (0);
	}
	return (1);
}

std::map<std::string, float>*	storeDataBase(void)
{
	std::fstream			dataFile;
	std::map<std::string, float>	*dataMap;
	std::string			buffer;

	dataFile.open("./data.csv", std::ios_base::in);
	
	dataMap = new std::map<std::string, float>;

	std::getline(dataFile, buffer);
	buffer.clear();
	while (true)
	{
		std::getline(dataFile, buffer);
		if (dataFile.eof())
			break;
		std::string::size_type	pos;
		
		pos = buffer.find(',', 0);
		dataMap->insert(std::pair<std::string, float>(buffer.substr(0, pos), buffer.substr(pos + 1, buffer.npos)));	
		buffer.clear();
	}
	std::map<std::string, float>::iterator	it;
	it = dataMap->begin();
	while (it != dataMap->end())
	{
		std::cout << it->first << " -> " << it->second << std::endl;
		it++;
	}
	std::cout << "finished reading file" << std::endl;
	return (dataMap);
}

int	main(int argc, char **argv)
{
	// 1. decide how to store database in "./data.csv"
	// 2. open file 'argv[1]'
		// if not possible -> "error: could not open file" 
	// 3. store info
	// 4. compare each date of file with our database
		// error if invalid date 
		// error if negative value
		// error if num is bigger than int
		// error if there is no num or date
	// 5. multiply value * exchange rate 
	// 6. show result (date -> value = result)
	(void)argv;
	if (argc != 2)
	{
		std::cout << "Usage: ./btc infile.txt" << std::endl;
		return (1);
	}
	std::map<std::string, float>	*dataBase;

	dataBase = storeDataBase();
//	info = storeFileInfo(argv[1]);
//	if (!info)
//		return (1);

//	compareData(dataBase);
	delete dataBase;
	return (0);
}
