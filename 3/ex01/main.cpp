/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:57:57 by martalop          #+#    #+#             */
/*   Updated: 2025/04/11 20:32:53 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	Lara("Lara");

	Lara.printStatus();

	Lara.attack("someone");
	Lara.takeDamage(10);
	Lara.beRepaired(2);	

	Lara.guardGate();
	
	Lara.printStatus();
	return (0);
}
