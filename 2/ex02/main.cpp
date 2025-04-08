/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:34 by martalop          #+#    #+#             */
/*   Updated: 2025/04/08 20:39:52 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a(44);
	Fixed b(4);
//	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );	
	
	std::cout << a << std::endl;
	std::cout << "min is = " << a.min(a, b) << ", max is = " << a.max(a, b) << std::endl;

//	std::cout << ++a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << Fixed::max( a, b ) << std::endl;	
	return (0);
}
