/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:47:10 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 22:06:02 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
	_name = name;
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their "<< _weapon.getType() << std::endl;
}
