/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 21:33:59 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 22:37:25 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class	WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal( std::string );
		WrongAnimal( const WrongAnimal& );
		~WrongAnimal(); 
		
		WrongAnimal&	operator=( const WrongAnimal& );

		void	makeSound(void) const;
		std::string		getType(void) const;

	protected:
		std::string	_type;
};

#endif

