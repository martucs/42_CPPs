/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:55:34 by martalop          #+#    #+#             */
/*   Updated: 2025/04/06 22:34:56 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

std::ostream&	operator<<(std::ostream os, const Fixed &var)
{
	std::ostream 	&osRef = os;
	(void)var;
	std::cout << "i'm in << operator function" << std::endl;
	return (osRef);
}

int	main(void)
{
	Fixed a;
	return (0);
}
