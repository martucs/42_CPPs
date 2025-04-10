/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:41:00 by martalop          #+#    #+#             */
/*   Updated: 2025/04/10 21:06:55 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "default SCAV constructor says hi!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap &var): ClapTrap(var)
{
	std::cout << "copy SCAV constructor says hi!" << std::endl;
	*this = var;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << "string SCAV constructor says hi!" << std::endl;
	(void)name;
}

ScavTrap::~ScavTrap(): ClapTrap()
{
	std::cout << "SCAV destructor says bye!" << std::endl;
}

void	ScavTrap::attack(const std::string &target): ClapTrap
{
	if (_energyPoints != 0 && _hitPoints > 0)
	{
		std::cout << "ScavTrap " << _name << " attacks " << target
		   	<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " cannot attack, it ran out of hit points!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " cannot attack, it ran out of energy!" << std::endl;
}

void	ScavTrap::guardGate(void): ClapTrap
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& var): ClapTrap
{
	if (this != &var)
	{
		_name = var._name;
		_hitPoints = var._hitPoints;
		_energyPoints = var._energyPoints;
		_attackDamage = var._attackDamage;
	}
	return (*this);
}
