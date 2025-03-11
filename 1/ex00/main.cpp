/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:18:28 by martalop          #+#    #+#             */
/*   Updated: 2025/03/11 18:47:01 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "Zombie.hpp"

int	main(void)
{
	std::string	my_name = "Marta";
	std::string	my_name2 = "lop";
	// locally creating object	
//	Zombie	my_zombie;

//	my_zombie.setName(my_name);
//	my_zombie.announce();

	// malloc'd object
	Zombie	*my_zombie;
	my_zombie = newZombie(my_name);
	my_zombie->announce();
	delete my_zombie;

	std::cout << std::endl;

	// not malloc'd object
	randomChump(my_name2);

	std::cout << std::endl;
	std::cout << "END of program" << std::endl;
	return (0);
}
