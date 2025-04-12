/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:57:04 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 22:50:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// WRONG CLASS TEST
/*int	main()
{
	WrongCat	kitty;
	const WrongAnimal* meta = new WrongAnimal();
	const WrongAnimal* w_cat = &kitty;
	
	std::cout << std::endl;
	
	meta->makeSound();
	w_cat->makeSound(); 
	kitty.makeSound();

	std::cout << std::endl;

	delete meta;
	return (0);
}*/

int	main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
//	const Dog* j = new Dog();
//	const Cat* i = new Cat();
	
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
