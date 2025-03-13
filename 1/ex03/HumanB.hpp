/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:44:12 by martalop          #+#    #+#             */
/*   Updated: 2025/03/13 22:30:43 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string		_name;
		class Weapon	*_weapon;

	public:
		HumanB( std::string );
		~HumanB();

		void	attack( void );
		void	setWeapon( Weapon &);
};

#endif

