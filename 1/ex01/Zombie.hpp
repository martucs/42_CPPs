/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 13:39:14 by martalop          #+#    #+#             */
/*   Updated: 2025/03/11 18:28:01 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
	private:
		std::string		_name;

	public:
		Zombie();
		~Zombie();

		std::string	getName( void );
		void		setName( std::string name);
		void		announce( void );
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
