/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:27:13 by martalop          #+#    #+#             */
/*   Updated: 2025/04/14 22:19:05 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap( );
		DiamondTrap( std::string );
		DiamondTrap( const DiamondTrap& );
		~DiamondTrap();
		
		DiamondTrap&	operator=( const DiamondTrap& );

		void	whoAmI(void);
		void	attack(const std::string& target);

	private:
		std::string	_name;

};

#endif
