/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:52:13 by martalop          #+#    #+#             */
/*   Updated: 2025/03/12 16:05:02 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	int		i;
	Zombie	*horde;
	
	i = 0;
	horde = new Zombie[N];
	if (!horde)
		return (NULL);
	// de esta manera solo hay un puntero (horde) y la direccion de memoria del primer zombie es = a la de horde
	// para acceder a informacion de cualquiera de los objetos zombie nos movemos con '.' porque NO son punteros
	// solo podemos hacer '->' con el primer zombie
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}

int	main(void)
{
	std::string	name = "blue";
	Zombie	*horde;
	int		i;

	i = 0;
	horde = zombieHorde(5, name);
	if (!horde)
	{
		std::cerr << "new error" << std::endl;
		return (1);
	}
	while (i < 5)
	{
		horde[i].announce();
		i++;
	}
	delete[] horde;
	return (0);
}
