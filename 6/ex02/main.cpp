/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:52:09 by martalop          #+#    #+#             */
/*   Updated: 2025/05/06 13:52:20 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void	identify(Base &p)
{
	try
	{
		A	&ARef = dynamic_cast<A&>(p);
		(void)ARef;
		std::cout << "Object created is of type A" << std::endl; 
	}
	catch (std::exception &e){}
	try
	{
		B	&BRef = dynamic_cast<B&>(p);
		(void)BRef;
		std::cout << "Object created is of type B" << std::endl; 
	}
	catch (std::exception &e){}
	try
	{
		C	&CRef = dynamic_cast<C&>(p);
		(void)CRef;
		std::cout << "Object created is of type C" << std::endl; 
	}
	catch (std::exception &e){}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Object created is of type A" << std::endl; 
	if (dynamic_cast<B*>(p))
		std::cout << "Object created is of type B" << std::endl; 
	if (dynamic_cast<C*>(p))
		std::cout << "Object created is of type C" << std::endl; 
}

Base	*generate(void)
{
	Base	*randomClass;
	float	randomRatio;

	srand((unsigned int)time(NULL));
	randomRatio = rand() / (float)RAND_MAX;
	if (randomRatio < 0.33)
		randomClass = new A;
	else if (randomRatio < 0.66)
		randomClass = new B;
	else
		randomClass = new C;
	return (randomClass);
}

int	main()
{
	Base	*base;

	base = generate();
	identify(base);
	identify(*base);
	delete base;
	return (0);
}
