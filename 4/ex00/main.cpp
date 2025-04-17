/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:57:04 by martalop          #+#    #+#             */
/*   Updated: 2025/04/17 17:56:36 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// WRONG CLASS TEST
/*int	main()
{
	WrongCat			kitty;
	const WrongAnimal*	meta = new WrongAnimal();
	const WrongAnimal*	newCat = new WrongCat();
	const WrongAnimal*	w_cat = &kitty;
	const WrongCat*		lastCat = new WrongCat();
	
	std::cout << std::endl;
	
	meta->makeSound();
	newCat->makeSound();
	w_cat->makeSound(); 
	kitty.makeSound();
	lastCat->makeSound();

	std::cout << std::endl;

	delete meta;
	delete newCat;
	delete lastCat;
	return (0);
}*/

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << std::endl;
	
	std::cout << "Dog _type = " << j->getType() << " " << std::endl;
	std::cout << "Cat _type = " << i->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound(); //will output the cat sound!
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	return (0);
}
