/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:36 by martalop          #+#    #+#             */
/*   Updated: 2025/04/20 16:51:13 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal
{
	public:
		Animal();
		Animal( std::string );
		Animal( const Animal& );
		virtual ~Animal();
		
		Animal&	operator=( const Animal& );

		virtual void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};
// hacer makeSound() virtual nos obliga a ponerlo
// en el destructor también (por -Werror)
// es como medida de seguridad porque cuando tengamos memoria
// dinamica en una clase derivada de Animal,
// queremos que llame tambien al destructor de
// esa clase derivada y luego al nuestro,
// no solo al destructor de Animal
//
// lo testeamos con Okto quitando las flags
// y solo se llamaba al destructor de Animal
// cuando destruiamos un objeto Cat

#endif

