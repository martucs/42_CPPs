/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:57:04 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 15:43:14 by martalop         ###   ########.fr       */
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
	std::cout << "Cat -> brain, idea[0] = " << kitcat.getBrain()->getIdea(0) << std::endl;
//	std::cout << "Animal Cat ptr -> brain, idea[0] = " << cat2->getBrain()->getIdea(0) << std::endl;
	std::cout << std::endl;
	
	delete cat2;	
	return (0);
}
