/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 14:21:05 by martalop          #+#    #+#             */
/*   Updated: 2025/03/16 17:11:31 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	filenameCheck(char	*filename)
{
	std::fstream	inFile;
	const char		*new_filename;

	new_filename = "copy.txt";
	inFile.open(filename, std::fstream::in);
	if (inFile.fail())
	{
		std::cout << "error opening file" << std::endl;
		return (1);
	}
	else
		std::cout << "file opened succesfully" << std::endl;
	
	std::ofstream	newFile(new_filename);
	newFile << inFile.rdbuf();

	inFile.close();
	newFile.close();
	return (0);
}



int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage:\n./executable filename string1 string2" << std::endl;
		return (1);
	}
	filenameCheck(argv[1]);
	// 1. check if filename is valid
	// 2. create new file
	// 3. copy content of filename in the new file
	// 4. replace every occurrence of s1 with s2 in the new file

	return (0);
}
