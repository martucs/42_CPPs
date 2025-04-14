/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:44:02 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 22:44:31 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): FragTrap(), ScavTrap()
{
	std::cout << "DIAMOND constructor says hi!" << std::endl;
	_name = "DiamondTrapName";
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "Diamond using Fragtrap hitpoints, = " << FragTrap::_hitPoints << std::endl;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap( const DiamondTrap &var): FragTrap(var), ScavTrap(var)
{
	std::cout << "DIAMOND copy constructor says hi!" << std::endl;
	*this = var;
}

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name)
{
	std::cout << "DIAMOND string constructor says hi!" << std::endl;
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DIAMOND destructor says bye!" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "WHO AM I?" << std::endl;
	std::cout << "ClapTrap name = " << ClapTrap::_name << std::endl;
	std::cout << "DiamondTrap name = " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& var)
{
	if (this != &var)
	{
		_name = var._name;
		FragTrap::_hitPoints = var.FragTrap::_hitPoints;
		ScavTrap::_energyPoints = var.ScavTrap::_energyPoints;
		FragTrap::_attackDamage = var.FragTrap::_attackDamage;
	}
	return (*this);	
}
