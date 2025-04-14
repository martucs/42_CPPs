/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:57:04 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 15:20:17 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main()
{
//	Animal	randomAnimal;
	Cat		kitcat;
	Dog		dogg;
	Animal	*cat2 = new Cat();

	std::cout << std::endl;
//	randomAnimal.makeSound();
	kitcat.makeSound();
	dogg.makeSound();
	cat2->makeSound();
	std::cout << std::endl;
	
	delete cat2;	
	return (0);
}
