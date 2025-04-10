/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:58:31 by martalop          #+#    #+#             */
/*   Updated: 2025/04/10 17:03:13 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "default constructor says hi!" << std::endl;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap &var)
{
	std::cout << "copy constructor says hi!" << std::endl;
	*this = var;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "string constructor says hi!" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructor says bye!" << std::endl;
}

void	ClapTrap::setName(std::string name)
{
	_name = name;
}

void	ClapTrap::printStatus(void)
{
//	std::cout << std::endl << "\e[1mClaptrap " << _name << " STATUS:\e[0m" << std::endl; BOLD
	std::cout << std::endl << "Claptrap " << _name << " STATUS:" << std::endl;
	std::cout << "Hit points = " << _hitPoints << std::endl;
	std::cout << "Energy points = " << _energyPoints << std::endl;
	std::cout << "Attack damage = " << _attackDamage << std::endl << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints != 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
		   	<< ", causing " << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot attack, it ran out of hit points!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " cannot attack, it ran out of energy!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_energyPoints != 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " was attacked, losing "
			<< amount << " hit points!" << std::endl;
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << _name << " was attacked, but cannot take any more damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints != 0 && _hitPoints > 0)
	{
		std::cout << "ClapTrap " << _name << " repairs itself, gaining "
			<< amount << " hit points!" << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " cannot repair itself, it ran out of hit points!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " cannot repair itself, it ran out of energy!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& var)
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
