/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 21:25:22 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 21:41:30 by martalop         ###   ########.fr       */
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
	while (i < N)
	{
		horde[i].setName(name);
		i++;
	}
	return (horde);
}

	// Zombie	*horde;
	// horde = new Zombie[N];
	//
	// de esta manera solo hay un puntero (horde) y la direccion de memoria del primer zombie es = a la de horde
	// (horde[i] = horde)
	// para acceder a informacion de cualquiera de los objetos zombie nos movemos con '.' porque NO son punteros
	// solo podemos hacer '->' con el primer zombie
