/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:57:49 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 21:07:17 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "constructor says hi" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "destroying:	" << getName() << std::endl;
}

std::string	Zombie::getName(void)
{
	return (_name);
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
