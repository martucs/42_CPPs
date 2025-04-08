/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:34 by martalop          #+#    #+#             */
/*   Updated: 2025/04/07 18:01:20 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

std::ostream&	operator<<(std::ostream &os, const Fixed &var)
{
	(void)var;
	// imprimir como si fuera float
	os << "i'm in << operator function" << std::endl;
	os << var.toFloat();
	return (os);
}

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f);
	Fixed const d( b );
	
	a = Fixed( 1234.4321f );
	std::cout << a << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}
