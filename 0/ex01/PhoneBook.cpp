/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:54:55 by martalop          #+#    #+#             */
/*   Updated: 2025/03/10 22:33:09 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	index = 0;
}

PhoneBook::~PhoneBook(void){
}

int	safe_getline(std::string *info);

// GETTERS
Contact	PhoneBook::GetContact(int index)
{
	return (_contact[index]);
}

// OTHERS
void	PhoneBook::CopyContact(Contact tmp, Contact *real)
{
	real->setName(tmp.getName());
	real->setLastName(tmp.getLastName());
	real->setNickname(tmp.getNickname());
	real->setNumber(tmp.getNumber());
	real->setSecret(tmp.getSecret());
}

long	isValidNumber(std::string input, long *num)
{
	for (int i = 0; input[i]; i++) 
	{
		if (i >= 12)
		{
			std::cout << "\n-Invalid number-" << std::endl;
			std::cout << "(more than 12 digits)" << std::endl;
			std::cout << "--------------------------\nContact creation failed :(\n--------------------------\n";
			return (0);
		}
        if (input[i] >= '0' && input[i] <= '9') 
			*num = *num * 10 + (input[i] - '0');
		else
		{
			std::cout << "\n-Invalid number-" << std::endl;
			std::cout << "--------------------------\nContact creation failed :(\n--------------------------\n";
			return (0);
		}
	}
	return (1);
}

int	PhoneBook::FillContact(void)
{	
	std::string	input;
	Contact		tmp_cont;
	long		num;

	num = 0;	
	if (index >= 8)
		index = index - 8 * (index / 8);
	std::cout << std::endl;
	std::cout << "Fill contact info" << std::endl;
	std::cout << "--------------------------" << std::endl;
//	std::cout << "Index: " << index << std::endl;
	std::cout << "First name: ";
	if (!safe_getline(&input))
		return (1);
	tmp_cont.setName(input);
	std::cout << "Last name: ";
	if (!safe_getline(&input))
		return (1);
	tmp_cont.setLastName(input);
	std::cout << "Nickname: ";
	if (!safe_getline(&input))
		return (1);
	tmp_cont.setNickname(input);
	std::cout << "Phone number: ";
	if (!safe_getline(&input))
		return (1);
	if (isValidNumber(input, &num))
		tmp_cont.setNumber(num);
	else 
		return (2);
	std::cout << "Darkest secret: ";
	if (!safe_getline(&input))
		return (1);
	tmp_cont.setSecret(input);
	if (tmp_cont.isFull())
	{
		CopyContact(tmp_cont, &_contact[index]);
		std::cout << "--------------------------\nContact succesfully added!\n--------------------------\n";
		index++;
	}
	else
	{
		std::cout << "\n-Empty fields-" << std::endl;
		std::cout << "--------------------------\nContact creation failed :(\n--------------------------\n";
		return (2);
	}
	return (0);
}

static void	printContact(Contact contact)
{
	std::cout << "First name: " << contact.getName() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nickname: " << contact.getNickname() << std::endl;
	std::cout << "Phone number: " << contact.getNumber() << std::endl;
	std::cout << "Darkest secret: " << contact.getSecret() << std::endl;
}

static void	printContactFormatted(Contact contact)
{
	if (contact.getName().size() >= 10)
		std::cout << contact.getName().substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << contact.getName() << "|";
	if (contact.getLastName().size() >= 10)
		std::cout << contact.getLastName().substr(0, 9) << "." << "|";
	else
		std::cout << std::setw(10) << contact.getLastName() << "|";
	if (contact.getNickname().size() >= 10)
		std::cout << contact.getNickname().substr(0, 9) << "." << "|" << std::endl;
	else
		std::cout << std::setw(10) << contact.getNickname() << "|" << std::endl;
}

static int	parseIndex(std::string input)
{
	int	index;
	long unsigned int	i;

	index = 0;
	i = -1;
	while (input[++i])
	{
        if (input[i] >= '0' && input[i] <= '9')
            index = index * 10 + (input[i] - '0');
		else
			break ;
	}
	if (i < input.size() || index <= 0 || index >= 9)
	{
		std::cout << "invalid index" << std::endl;
		return (-1);
	}
	return (index);
}

int	PhoneBook::PrintBook(void)
{
	int index;
	std::string input;

	// TABLE
	std::cout << std::endl;
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name"  << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "  ---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << std::setw(10) << i + 1 << "|";
		printContactFormatted(GetContact(i));
	}
	std::cout << std::endl;

	// SPECIFIC CONTACT INFO
	std::cout << "Index: ";
	if (!safe_getline(&input))
		return (1);
	std::cout << "--------------------------" << std::endl;
	index = parseIndex(input);
	if (index != -1)
	{
		if (GetContact(index - 1).isFull())
			printContact(GetContact(index - 1));
		else
			std::cout << "empty contact" << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
	return (0);
}

