/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:22:32 by martalop          #+#    #+#             */
/*   Updated: 2025/03/10 22:05:50 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact::Contact()
{
	_number = 0;
}

Contact::~Contact(){
}

int	Contact::isFull(void)
{
	if (_firstName.empty())
		return (0);
	if (_lastName.empty())
		return (0);
	if (_nickname.empty())
		return (0);
	if (_number == 0)
		return (0);
	if (_secret.empty())
		return (0);
	return (1);
}

// SETTERS 
void	Contact::setName(std::string name)
{
	_firstName = name;
}

void	Contact::setLastName(std::string name)
{
	_lastName = name;
}

void	Contact::setNickname(std::string name)
{
	_nickname = name;
}

void	Contact::setNumber(long num)
{
	_number = num;
}

void	Contact::setSecret(std::string secret)
{
	_secret = secret;
}

// GETTERS
std::string	Contact::getName(void)
{
	return (_firstName);
}

std::string	Contact::getLastName(void)
{
	return (_lastName);
}

std::string	Contact::getNickname(void)
{
	return (_nickname);
}

long	Contact::getNumber(void)
{
	return (_number);
}

std::string	Contact::getSecret(void)
{
	return (_secret);
}
