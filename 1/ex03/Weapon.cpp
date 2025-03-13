/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 21:13:07 by martalop          #+#    #+#             */
/*   Updated: 2025/03/13 17:34:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

Weapon::Weapon(std::string weaponName)
{
	setType(weaponName);
//	std::cout << "creating " << weaponName << " Weapon" << std::endl;
}

Weapon::~Weapon()
{
//	std::cout << "destroying Weapon" << std::endl;
}

void	Weapon::setType(const std::string type)
{
	_type = type;
}

const std::string&	Weapon::getType(void)
{
	const std::string	&type_ref = _type;
	return (type_ref);
}


