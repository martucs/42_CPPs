/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:42:45 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 19:17:29 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FRAG constructor says hi!" << std::endl;
	_name = "Fragname";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap( const FragTrap &var): ClapTrap(var)
{
	std::cout << "FRAG copy constructor says hi!" << std::endl;
	*this = var;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << "FRAG string constructor says hi!" << std::endl;
	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FRAG destructor says bye!" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (_energyPoints != 0 && _hitPoints > 0)
	{
		std::cout << "FragTrap " << _name << " attacks " << target
		   	<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints -= 1;
	}
	else if (_hitPoints <= 0)
		std::cout << "FragTrap " << _name << " cannot attack, it ran out of hit points!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " cannot attack, it ran out of energy!" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "You're doing great! Take a high-five from " << _name << " ;)" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& var)
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
