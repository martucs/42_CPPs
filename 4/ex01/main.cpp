/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:57:04 by martalop          #+#    #+#             */
/*   Updated: 2025/04/17 18:19:21 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

// DEEP COPY TEST
/*int main()
{
	Cat*	cat1 = new Cat();
	Cat*	cat2 = new Cat();

	std::cout << std::endl;
	cat1->getBrain()->setIdea("this idea is brand-new!", 0);
	std::cout << "cat1 idea[0] = " << cat1->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;

	*cat2 = *cat1;
	std::cout << std::endl;
	
	delete cat1;
	
	std::cout << std::endl;
	std::cout << "cat2 idea[0] = " << cat2->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	delete cat2;
	return (0);
}*/

int	main()
{
	int		i;
	Animal	*animalArray[4];

	i = 0;
	while (i < 2)
		animalArray[i++] = new Dog();
	while (i < 4)
		animalArray[i++] = new Cat();
	
	std::cout << std::endl;
	animalArray[0]->makeSound();
	animalArray[1]->makeSound();
	animalArray[2]->makeSound();
	animalArray[3]->makeSound();
	std::cout << std::endl;
	
	i = 0;
	while (i < 4)
		delete animalArray[i++];
	return (0);
}

// 	OJO PIOJO!
// 	Si hubiera hubiera hecho animalArray = Dog(), (sin 'new'), tendriamos problemas de:
// 	Object Slicing:
// When you do animalArray[0] = Dog();, a Dog object is created, but it is assigned to an Animal object in the array.
// This results in object slicing: only the Animal part of the Dog object is copied into the array. The Dog-specific behavior (like the overridden makeSound() method) is lost.
// When you call animalArray[0].makeSound(), it invokes the makeSound() method of the Animal class, not the Dog class. Therefore, the output is "Some generic animal sound" instead of "Woof!".

