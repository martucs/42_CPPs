/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:34:40 by martalop          #+#    #+#             */
/*   Updated: 2025/05/07 22:59:46 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

/*void	randomFunc(T var)
{
	std::cout << "I only do stupid shit" << std::endl;
}*/

template <typename T>
void	print(T var)
{
	std::cout << var << std::endl;
}

template <typename T>
void	iter(T *array, unsigned int length, void(*print)(T))
{
	unsigned int	i = 0;

	while (i < length)
	{
		print(array[i]);
		i++;
	}
}

#endif
