/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:36 by martalop          #+#    #+#             */
/*   Updated: 2025/04/13 14:55:41 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class	Brain
{
	public:
		Brain();
		Brain( const Brain& );
		~Brain();
		
		Brain&	operator=( const Brain& );

		std::string	ideas[100];

};

#endif

