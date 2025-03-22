/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:06:21 by martalop          #+#    #+#             */
/*   Updated: 2025/03/21 18:31:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <string>
#include <iostream>

int	main()
{
	Harl	harl;
	Harl	harl2;
	
	std::cout << "harl complains in DEBUG level:" << std::endl;
	harl.complain("DEBUG");
	
	std::cout << std::endl;

	std::cout << "harl2 complains in ERROR level:" << std::endl;
	harl2.complain("ERROR");
	return (0);
}


//	void(Harl::*test)(void);

//	test = &Harl::info;
//	(harl.*test)();

// aqui estamos creando un puntero de funcion (llamdo 'test') que devuelve void y recibe void y que recibe un objeto Harl, porque la funcion a la que vamos a igualar este puntero es una funcion declarada dentro de la clase Harl.

