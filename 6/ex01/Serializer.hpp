/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 18:05:39 by martalop          #+#    #+#             */
/*   Updated: 2025/05/05 20:37:57 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
# include <iostream>

typedef unsigned long uintptr_t;

typedef struct Data_s
{
	std::string	name;
	int		age;
} Data;

class	Serializer
{
	public:
		Serializer( const Serializer& );
		~Serializer();
		
		Serializer&	operator=( const Serializer& );
		
		static uintptr_t	serialize(Data	*ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
};

#endif
