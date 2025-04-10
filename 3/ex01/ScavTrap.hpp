/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:41:42 by martalop          #+#    #+#             */
/*   Updated: 2025/04/11 20:31:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>

class ScavTrap : public ClapTrap 
{
	public:
		ScavTrap( );
		ScavTrap( std::string );
		ScavTrap( const ScavTrap& );
		~ScavTrap();
		
		ScavTrap&	operator=( const ScavTrap& );

		void	attack( const std::string& target );
		void	guardGate( void );

};

#endif
