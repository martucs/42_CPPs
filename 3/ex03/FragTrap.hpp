/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:40:48 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 22:31:34 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : virtual public ClapTrap 
{
	public:
		FragTrap( );
		FragTrap( std::string );
		FragTrap( const FragTrap& );
		~FragTrap();
		
		FragTrap&	operator=( const FragTrap& );

		void	attack( const std::string& target );
		void	highFivesGuys(void);
};

#endif
