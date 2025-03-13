/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:47:10 by martalop          #+#    #+#             */
/*   Updated: 2025/03/13 21:56:24 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	_name = name;
//	std::cout << "creating HumanA: " << name << std::endl;
}

HumanA::~HumanA()
{
//	std::cout << "destroying HumanA" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their "<< _weapon.getType() << std::endl;
}
