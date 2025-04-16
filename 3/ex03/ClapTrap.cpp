/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:58:31 by martalop          #+#    #+#             */
/*   Updated: 2025/04/16 19:38:26 by martalop         ###   ########.fr       */
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

void	ClapTrap::setHitPoints(unsigned int amount)
{
	_hitPoints = amount;
}

void	ClapTrap::setEnergyPoints(unsigned int amount)
{
	_energyPoints = amount;
}

void	ClapTrap::setAttackDamage(unsigned int amount)
{
	_attackDamage = amount;
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (_hitPoints);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (_energyPoints);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (_attackDamage);
}

void	ClapTrap::printStatus(void)
{
	std::cout << std::endl << "Claptrap " << this->_name << " STATUS:" << std::endl;
	std::cout << "Hit points = " << this->_hitPoints << std::endl;
	std::cout << "Energy points = " << this->_energyPoints << std::endl;
	std::cout << "Attack damage = " << this->_attackDamage << std::endl << std::endl;
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
