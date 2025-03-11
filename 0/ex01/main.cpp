/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 20:02:10 by martalop          #+#    #+#             */
/*   Updated: 2025/03/10 22:34:28 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iomanip>					
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	safe_getline(std::string *info)
{
	std::getline(std::cin, *info);
	if (std::cin.eof())
	{
		std::cerr << std::endl << std::endl;
		std::cerr << "-Forced exit-" << std::endl;
		return (0);
	}
	return (1);
}

int	execute_commands(void)
{
	PhoneBook	book;
	std::string input;

	while (1)
	{
		std::cout << "> ";
		if (!safe_getline(&input))
			return (1);
		if (input.find("ADD") != std::string::npos && input.size() == 3)
		{
			if (book.FillContact() == 1)
				return (1);
		}
		if (input.find("SEARCH") != std::string::npos && input.size() == 6)
		{
			if (book.PrintBook() == 1)
				return (1);
		}
		if (input.find("EXIT") != std::string::npos && input.size() == 4)
			break ;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	static_cast<void>(argv);

	if (argc > 1)
	{
		std::cerr << "This program does not acccept arguments" << std::endl;
		return (1);
	}
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	if (execute_commands() == 1)
		return (1);
	return (0);
}
