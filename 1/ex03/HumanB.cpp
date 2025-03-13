/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:59:10 by martalop          #+#    #+#             */
/*   Updated: 2025/03/13 22:32:29 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB()
{
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void    HumanB::attack(void)                                                              
{
	if (_weapon)
		std::cout << _name << " attacks with their "<< _weapon->getType() << std::endl;
	else
		std::cout << "no weapon, no attack" << std::endl;
}
