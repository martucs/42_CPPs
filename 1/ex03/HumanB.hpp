/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:44:12 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 23:40:28 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		class Weapon	*_weapon;
			std::string		_name;

		public:
			HumanB( std::string );
			~HumanB();

		void	attack( void );
		void	setWeapon( Weapon& );
};

#endif

