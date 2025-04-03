/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:34 by martalop          #+#    #+#             */
/*   Updated: 2025/04/03 17:26:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main()
{
	Fixed	num;
	Fixed	num2;

	num.setRawBits(20);
	std::cout << "num value = " << num.getRawBits() << std::endl;
	std::cout << "num2 value = " << num2.getRawBits() << std::endl;
	num2 = num;
	std::cout << "AFTER" << std::endl;
	std::cout << "num value = " << num.getRawBits() << std::endl;
	std::cout << "num2 value = " << num2.getRawBits() << std::endl;
	
	Fixed	num3;
	
	Fixed	num4(num3);
	num3.setRawBits(20);

	std::cout << "num3 value = " << num3.getRawBits() << std::endl;
	std::cout << "num4 value = " << num4.getRawBits() << std::endl;
	return (0);
}

