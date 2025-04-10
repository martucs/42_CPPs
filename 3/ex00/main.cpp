/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:57:57 by martalop          #+#    #+#             */
/*   Updated: 2025/04/10 17:25:30 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Marta("Marta");

	Marta.printStatus();
	Marta.attack("Clappy");
	Marta.printStatus();
	Marta.takeDamage(5);
	Marta.printStatus();
	Marta.attack("kjahs");
	Marta.printStatus();
	Marta.beRepaired(2);
	Marta.printStatus();
	
	ClapTrap	Mar(Marta);
	
	Mar.setName("Mar");	
	Mar.printStatus();
	Marta.takeDamage(15);
	Marta.printStatus();
	Mar.printStatus();
	Marta.attack("noboody");
	return (0);
}
