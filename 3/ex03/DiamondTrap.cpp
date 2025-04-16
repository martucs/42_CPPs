/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:44:02 by martalop          #+#    #+#             */
/*   Updated: 2025/04/16 19:58:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() 
{
	std::cout << "DIAMOND constructor says hi!" << std::endl;
	this->_name = "DiamondTrapName";
	ClapTrap::_name = _name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << " F attackDamage = " << FragTrap::_attackDamage << std::endl;
	std::cout << " F attackDamage = " << &(FragTrap::_attackDamage) << std::endl;
	std::cout << " S attackDamage = " << ScavTrap::_attackDamage << std::endl;
	std::cout << " S attackDamage = " << &(ScavTrap::_attackDamage) << std::endl;
	std::cout << "this-> attackDamage = " << this->_attackDamage << std::endl;
	std::cout << "this-> attackDamage = " << &this->_attackDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name )
{
	std::cout << "DIAMOND string constructor says hi!" << std::endl;
	_name = name;
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout <<  ScavTrap::_energyPoints << " & " << this->_energyPoints << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap &var): ClapTrap(var), FragTrap(var), ScavTrap(var)
{
	std::cout << "DIAMOND copy constructor says hi!" << std::endl;
	*this = var;
}


DiamondTrap::~DiamondTrap()
{
	std::cout << "DIAMOND destructor says bye!" << std::endl;
}


/*int	DiamondTrap::getAttackDamage(void)
{
	std::cout << "DIAMOND gettatckdmahe ->" << std::endl;
	return (_attackDamage);
}*/


void	DiamondTrap::attack(const std::string& target)
{
	
	std::cout << "this-> attackDamage = " << this->_attackDamage << std::endl;
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
		_hitPoints = var.FragTrap::_hitPoints;
		_energyPoints = var.ScavTrap::_energyPoints;
		_attackDamage = var.FragTrap::_attackDamage;
	}
	return (*this);	
}
