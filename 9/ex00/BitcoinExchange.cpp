/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:24:00 by martalop          #+#    #+#             */
/*   Updated: 2025/06/12 19:24:02 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

BitcoinExchange::BitcoinExchange()
{
	//std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& var)
{
	//std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = var;
}

BitcoinExchange::~BitcoinExchange()
{
	//std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& var)
{
	//std::cout << "copy operator called" << std::endl;
	if (this != &var)
	{
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& os, const BitcoinExchange& var)
{
	(void)var;
	return (os);
}
