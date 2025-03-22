/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:18:28 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 21:04:12 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	// locally creating object	
	Zombie	another_zombie;

	another_zombie.setName("Rita");
	another_zombie.announce();

	std::cout << std::endl;

	// malloc'd object
	Zombie	*my_zombie;
	my_zombie = newZombie("Marta");
	my_zombie->announce();
	delete my_zombie;

	std::cout << std::endl;

	// not malloc'd object
	randomChump("Ana");

	std::cout << std::endl;
	std::cout << "END of program" << std::endl;
	return (0);
}
