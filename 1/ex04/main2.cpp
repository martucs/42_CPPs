/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:05 by martalop          #+#    #+#             */
/*   Updated: 2025/03/16 20:46:25 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

// STEP BY STEP
	// 1. check if filename is valid
	// 2. create new file
	// 3. copy content of filename in the new file
	// 4. replace every occurrence of s1 with s2 in the new file
	
int	copyAndModFile(std::string filename, std::string s1, std::string s2)
{
	(void)s2;
	std::fstream	inFile;
	std::ofstream	newFile_w;
	std::fstream	newFile_r;
	
	std::string		line;
	int				res;

	std::string		replace;
	std::string		new_filename;

	replace = ".replace";
	inFile.open(filename.c_str(), std::fstream::in);
	if (inFile.fail())
	{
		std::cout << "error opening file" << std::endl;
		return (0);
	}
	new_filename = filename + replace;
	newFile_w.open(new_filename.c_str());
	newFile_w << inFile.rdbuf();
	inFile.close();
	newFile_w.close();

	newFile_r.open(new_filename.c_str());
	std::getline(newFile_r, line);
	while (true)
	{
		res = -1;
		while ((res = line.find(s1.c_str(), res + 1)) != (int)std::string::npos)
		{
			std::cout << "found \"" << s1 << "\" at line[" << res << "]" << std::endl;
			line.erase(res, s1.length());
			std::cout << "line erased = " << line << std::endl;
			line.insert(res, s2);
			std::cout << "line inserted = " << line << std::endl;
		}
	//	if (line.find(s1) != std::string::npos)
	//		std::cout << "found " << s1 << "\" at line[" << line.find(s1) << "]"<< std::endl;
		std::cout << "I read next line" << std::endl;
		std::getline(newFile_r, line);
		if (newFile_r.eof())
		{
			std::cout << "EOF" << std::endl;
			break ;
		}
	}
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
