/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:57:57 by martalop          #+#    #+#             */
/*   Updated: 2025/04/16 19:32:25 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap	d;

	std::cout << std::endl;
	d.printStatus();
	std::cout << " d. attckmg  = " << d.getAttackDamage() << std::endl;
	d.attack("someonee");
	d.takeDamage(4);
	d.beRepaired(3);
	std::cout << std::endl;
	d.whoAmI();
	d.highFivesGuys();
	d.printStatus();
	std::cout << std::endl;
	return (0);
}
