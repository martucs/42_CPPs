/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:34:00 by martalop          #+#    #+#             */
/*   Updated: 2025/05/07 23:00:07 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main( void )
{
	int	num_arr[4];

	num_arr[0] = 0;	
	num_arr[1] = 1;	
	num_arr[2] = 2;	
	num_arr[3] = 3;	
	
	std::string	str_arr[4];

	str_arr[0] = "hi";	
	str_arr[1] = "how";	
	str_arr[2] = "you";	
	str_arr[3] = "doinn";	

	::iter(num_arr, 4, ::print<int>);
	std::cout << std::endl;
	::iter(str_arr, 4, ::print<std::string>);

	std::cout << std::endl;
	int	tab[] = {0, 1, 2, 3, 4};

	::iter(tab, 5, ::print<int>);
	return (0);
}
