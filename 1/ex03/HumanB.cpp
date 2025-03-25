/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:59:10 by martalop          #+#    #+#             */
/*   Updated: 2025/03/25 16:09:13 by martalop         ###   ########.fr       */
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
// si no recibieramos weapon con referencia, perderiamos la verdadera direccion de memoria
// de weapon, me da un 'heap use after free' al intentar imprimirla desde humanB.attack()
// imagino porque el objeto weapon ya habrá sido destruido por el destructor en cuanto
// sale de setWeapon() e intentamos acceder a esa misma direccion de memoria


void    HumanB::attack(void)                                                              
{
	if (_weapon)
		std::cout << _name << " attacks with their "<< _weapon->getType() << std::endl;
	else
		std::cout << "no weapon, no attack from " << _name << std::endl;
}
