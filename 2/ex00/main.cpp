/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:34 by martalop          #+#    #+#             */
/*   Updated: 2025/04/06 20:31:19 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return (0);
}



/*int	main()
{
	Fixed	num;
	Fixed	num2;

	num.setRawBits(20);
	std::cout << "num value = " << num.getRawBits() << std::endl;
	std::cout << "num2 value = " << num2.getRawBits() << std::endl;
	
	num2 = num;
	std::cout << std::endl;

	std::cout << "num value = " << num.getRawBits() << std::endl;
	std::cout << "num2 value = " << num2.getRawBits() << std::endl;
	
	std::cout << std::endl << "CREATING num3 & num4" << std::endl;
	Fixed	num3;
	Fixed	num4(num3);
	num3.setRawBits(20);

	std::cout << std::endl;
	std::cout << "num3 value = " << num3.getRawBits() << std::endl;
	std::cout << "num4 value = " << num4.getRawBits() << std::endl;
	std::cout << std::endl; 
	return (0);
}*/
