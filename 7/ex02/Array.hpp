/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:34:20 by martalop          #+#    #+#             */
/*   Updated: 2025/05/08 13:34:45 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP


#include <iostream>

template <typename T>
class	Array
{
	public:
		Array();
		Array(unsigned int n);
		Array(Array &var);
		~Array();
		
		// member functions
		int	size(void);

		// operators
		int&	operator[](int);
		T&	operator=(const T&);
	
	private:
		// atributes
		T	*_array;
};

#include "Array.tpp"

#endif
