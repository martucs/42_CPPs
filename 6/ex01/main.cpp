/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:13:11 by martalop          #+#    #+#             */
/*   Updated: 2025/05/06 16:48:26 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void	initData(Data &var, const std::string name, int age)
{
	var.name = name;
	var.age = age;
}

void	printData(Data &var)
{
	std::cout << "Person Data " << &var << ":" << std::endl;
	std::cout << "- Name: " << var.name << std::endl;
	std::cout << "- Age: " << var.age << std::endl;
}

int	main()
{
	Data		*person;
	Data		*deserialized_person;
	uintptr_t	serialized_person;

	person = new Data;
	
	initData(*person, "Marta", 20098);
	printData(*person);

	serialized_person = Serializer::serialize(person);

	std::cout << std::endl;
	std::cout << "serialized_person = " << serialized_person << std::endl;
	std::cout << std::endl;
	
	deserialized_person = Serializer::deserialize(serialized_person);
	//deserialized_person->age = 10;
	printData(*deserialized_person);
	printData(*person);
	delete person;
	return (0);
}
