/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:34 by martalop          #+#    #+#             */
/*   Updated: 2025/04/09 15:47:09 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(0);
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );	
	
	std::cout << a << std::endl;
//	Fixed c(a - b);
//	std::cout << "c = " << c << std::endl;

	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;	
	return (0);
}
