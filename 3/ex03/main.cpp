/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:57:57 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 22:48:12 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	d("Ice");

	std::cout << std::endl;
	d.ClapTrap::printStatus();
	d.attack("someonee");
	d.takeDamage(4);
	d.beRepaired(3);
	std::cout << std::endl;
	d.whoAmI();
	d.printStatus();
	std::cout << std::endl;
	return (0);
}
