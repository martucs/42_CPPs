/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:55:39 by martalop          #+#    #+#             */
/*   Updated: 2025/05/19 21:08:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>

int	main()
{
	std::stack<int>	realStack;

	realStack.push(12);
	std::cout << realStack.top() << std::endl;
	std::cout << std::endl;

	MutantStack mstack;
	
	mstack.push(10);
	std::cout << mstack.top() << std::endl;
	return (0);
}
