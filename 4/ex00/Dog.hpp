/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:01:33 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 20:29:37 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog: public Animal
{
	public:
		Dog();
		Dog( std::string );
		Dog( const Dog& );
		~Dog();
		
		Dog&	operator=( const Dog& );
		void	makeSound(void) const;
};

#endif
