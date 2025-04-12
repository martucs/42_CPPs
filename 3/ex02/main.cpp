/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:57:57 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 19:11:00 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	Son("Mike");

	Son.printStatus();
	Son.attack("Ellie");
	Son.attack("Mark");
	Son.takeDamage(4);
	Son.beRepaired(3);
	Son.highFivesGuys();
	Son.printStatus();
	return (0);
}
