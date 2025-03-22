/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:40:40 by martalop          #+#    #+#             */
/*   Updated: 2025/03/22 23:27:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		class Weapon&	_weapon;
		std::string		_name;

	public:
		HumanA(std::string, Weapon&);
		~HumanA();

		void		attack( void );
};

#endif

// if I had declared the class Weapon without the reference, like this:
//		class Weapon	_weapon;
// in the main() example, when changing the weapon sent to HumanA bob("bob", club),
// we would not see a change after changing the weapon.type
// (club.setType("some other club"))
// we would see the change locally in the club variable, but not in the bob variable
// not when doing a bob.attack()


