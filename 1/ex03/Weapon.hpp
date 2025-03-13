/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 20:36:19 by martalop          #+#    #+#             */
/*   Updated: 2025/03/13 17:30:56 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

class Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(std::string);
		~Weapon();

		const std::string&	getType(void); // returns a const reference to type
		void				setType(const std::string type);
};

#endif
