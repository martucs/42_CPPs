/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:58:31 by martalop          #+#    #+#             */
/*   Updated: 2025/04/09 22:13:56 by martalop         ###   ########.fr       */
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

std::string	ClapTrap::getName(void)
{
	return (_name);
}

int	ClapTrap::getHitPoints(void)
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints(void)
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage(void)
{
	return (_attackDamage);
}

void	ClapTrap::setHitPoints(int hitPoints)
{
	_hitPoints = hitPoints;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energyPoints != 0)
	{
		std::cout << "ClapTrap " << _name << " attacks " << target
		   	<< ", causing 1 points of damage!" << std::endl;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " is out of energy" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_attackDamage = _energyPoints - amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints != 0)
	{
		_hitPoints += amount;
		_energyPoints--;
	}
	else
		std::cout << "ClapTrap " << _name << " cannot be repaired :(" << std::endl;
}
