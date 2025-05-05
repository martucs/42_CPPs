/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:08:39 by martalop          #+#    #+#             */
/*   Updated: 2025/05/05 20:49:56 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& var)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = var;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	bla;
	(void)ptr;

	bla = static_cast<uintptr_t>(ptr->age);
	return (bla);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*bla;
	(void)raw;
	
	bla = new Data;
	return (bla);
}

Serializer&	Serializer::operator=(const Serializer& var)
{
	std::cout << "copy operator called" << std::endl;
	if (this != &var)
		return (*this);
	return (*this);
}



