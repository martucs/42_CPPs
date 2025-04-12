/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:01:33 by martalop          #+#    #+#             */
/*   Updated: 2025/04/12 20:29:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat: public Animal
{
	public:
		Cat();
		Cat( std::string );
		Cat( const Cat& );
		~Cat();
		
		Cat&	operator=( const Cat& );
		void	makeSound(void) const;
};

#endif
