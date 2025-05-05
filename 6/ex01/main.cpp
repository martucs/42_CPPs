/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:13:11 by martalop          #+#    #+#             */
/*   Updated: 2025/05/05 20:51:51 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

// initData()

void	printData(Data &var)
{
	std::cout << "DATA struct:" << std::endl;
	std::cout << "- Name: " << var.name << std::endl;
	std::cout << "- Age: " << var.age << std::endl;
}

int	main()
{
	Data	*random;
	uintptr_t	res;

	random = new Data;
	random->name = "Marta";
	random->age = 25;

	printData(*random);

	res = Serializer::serialize(random);
	std::cout << res << std::endl;
	return (0);
}
