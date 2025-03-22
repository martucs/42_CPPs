/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:11:27 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 21:56:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

void	changeString( std::string &string )
{
	std::cout << "changing string..." << std::endl;
	string = "BYE BRAIN";
}

int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPtr;
	std::string	&stringRef = string;

	std::cout << "string: " << string << std::endl;
	std:: cout << "string address = " << &string << std::endl << std::endl;
	
	stringPtr = &string;
	std::cout << "stringPtr: " << stringPtr << std::endl;
	std:: cout << "stringPtr address = " << &stringPtr << std::endl << std::endl;
	
	std::cout << "stringRef: " << stringRef << std::endl;
	std:: cout << "stringRef address = " << &stringRef << std::endl << std::endl;
	
	changeString( stringRef );
	std::cout << "string: " << string << std::endl;
	std::cout << "stringPtr dereferenced: " << *stringPtr << std::endl;
	std::cout << "stringRef: " << stringRef << std::endl;
	return (0);
}
