/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:05 by martalop          #+#    #+#             */
/*   Updated: 2025/03/14 19:41:44 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	filenameCheck(char	*filename)
{
	std::fstream	inFile;

	inFile.open(filename, std::fstream::in);
	if (inFile.fail())
	{
		std::cout << "error opening file" << std::endl;
		return (1);
	}
	else
		std::cout << "file opened succesfully" << std::endl;
//	std::cout << (char) inFile.get();
//	std::cout << inFile.rdbuf();
	
	const char	*new_filename;
//	const char	*s_replace;
	
//	s_replace = ".replace";

//	new_filename = filename + s_replace;

	new_filename = "hola.txt";
	std::ofstream	new_file(new_filename);

	new_file << inFile.rdbuf();

	inFile.close();
	return (0);
}
// creamos un stream que va a ser como un fd de lectura, que se mueve cada vez que hacemos un read



int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage:\n./executable filename string1 string2" << std::endl;
		return (1);
	}
	// 1. check if filename is valid
	filenameCheck(argv[1]);
	// 2. create new file
//	createFile(argv[1]);
	// 3. copy content of filename in the new file
	// 4. replace every occurrence of s1 with s2 in the new file

	return (0);
}
