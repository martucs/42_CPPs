/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:44:44 by martalop          #+#    #+#             */
/*   Updated: 2025/03/25 16:11:32 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	Weapon club = Weapon("crude spiked club");
	
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("other type of club");
	bob.attack();

	std::cout << std::endl;

	Weapon club2 = Weapon("crude spiked club");
	
	HumanB jim("Jim");
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("other type of club");
	jim.attack();
	return (0);
}
