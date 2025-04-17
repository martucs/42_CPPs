/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:36 by martalop          #+#    #+#             */
/*   Updated: 2025/04/17 17:31:54 by martalop         ###   ########.fr       */
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
// en el destructor también

#endif

