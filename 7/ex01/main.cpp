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
	str_arr[1] = "my";	
	str_arr[2] = "name";	
	str_arr[3] = "is";	

	::iter(num_arr, 4, ::print);
	std::cout << std::endl;
	::iter(str_arr, 4, ::print);

	return (0);
}
