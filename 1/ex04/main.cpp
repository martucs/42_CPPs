/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:05 by martalop          #+#    #+#             */
/*   Updated: 2025/03/17 22:59:04 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	copyAndModFile(std::string filename, std::string s1, std::string s2)
{
	std::fstream	inFile;
	std::ofstream	newFile;
	std::string		line;
	int				res;
	std::string		replace;
	std::string		new_filename;

	replace = ".replace";
	if (s1.empty())
	{
		std::cout << "Error: first string is empty" << std::endl;
		return (0);
	}
	inFile.open(filename.c_str(), std::fstream::in);
	if (inFile.fail())
	{
		std::cout << "error opening file" << std::endl;
		return (0);
	}
	new_filename = filename + replace;
	newFile.open(new_filename.c_str());
	std::getline(inFile, line);
	if (inFile.eof())
	{
		inFile.close();
		newFile.close();
		return (0);
	}
	while (true)
	{
		res = -s2.length();
		line.insert(line.length(), "\n");
		while ((res = line.find(s1.c_str(), res + s2.length())) != (int)std::string::npos)
		{
			line.erase(res, s1.length());
			line.insert(res, s2);
		}
		newFile << line;
		std::getline(inFile, line);
		if (inFile.eof())
			break ;
	}
	inFile.close();
	newFile.close();
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage:\n./executable filename string1 string2" << std::endl;
		return (1);
	}
	if (!copyAndModFile(argv[1], argv[2], argv[3]))
		return (1);
	return (0);
}
