/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:35:04 by martalop          #+#    #+#             */
/*   Updated: 2025/05/14 14:56:54 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>

int	main()
{
	std::list<int>	numbers;
	numbers.assign(4, 42);
	std::list<int>::iterator	num_b_i = numbers.begin();
	std::list<int>::iterator	num_e_i = numbers.end();
	
	while (num_b_i != num_e_i)
	{
		std::cout << *num_b_i << std::endl;
		num_b_i++;
	}
	easyfind(numbers, 1);
	std::cout << std::endl;	
	
	numbers.push_back(1);
	num_b_i = numbers.begin();
	while (num_b_i != num_e_i)
	{
		std::cout << *num_b_i << std::endl;
		num_b_i++;
	}
	easyfind(numbers, 1);
	std::cout << std::endl;	
	
	std::vector<char>	vec;
	vec.assign(5, 'a');
	std::vector<char>::iterator i;

	i = vec.begin();
	while (i != vec.end())
	{
		std::cout << *i << std::endl;
		i++;
	}
	easyfind(vec, 97);
	return (0);
}
