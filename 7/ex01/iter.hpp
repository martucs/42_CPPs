/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:34:40 by martalop          #+#    #+#             */
/*   Updated: 2025/05/08 13:28:47 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	print(T var)
{
	std::cout << var << std::endl;
}

template <typename T, typename Func>
void	iter(T *array, unsigned int length, Func function)
{
	unsigned int	i = 0;

	while (i < length)
	{
		function(array[i]);
		i++;
	}
}

// INFO: 
//	tmb podria haber hecho:
//	
//	template <typename T>
//	void	iter(T *array, unsigned int length, void (*func)(T))
//
//	de esta manera no es necesario enviar la funcion con el tipo de dato que
//	recibe como parametro. El main podria ser:
//	
//	::iter(num_arr, 4, ::print);
//	::iter(str_arr, 4, ::print);
//
//	en vez de como es ahora:
//	::iter(num_arr, 4, ::print<int>);
//	::iter(str_arr, 4, ::print<std::string>);

//	me obliga a poner el tipo que tendra el parametro porque ::print
//	recibe una variable de tipo T, no definida hasta que entremos en ::inter
 
#endif
