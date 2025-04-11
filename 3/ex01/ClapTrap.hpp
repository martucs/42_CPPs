/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 17:58:56 by martalop          #+#    #+#             */
/*   Updated: 2025/04/11 20:37:11 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap( std::string );
		ClapTrap( const ClapTrap& );
		~ClapTrap();
		
		ClapTrap&	operator=( const ClapTrap& );

		void		setName( std::string );
		void		setHitPoints( unsigned int amount );
		void		setEnergyPoints( unsigned int amount );
		void		setAttackDamage( unsigned int amount );
		std::string	getName( void ) const;
		int			getHitPoints( void ) const;
		int			getEnergyPoints( void ) const;
		int			getAttackDamage( void ) const;
		void		printStatus( void );

		void		attack( const std::string& target );
		void		takeDamage( unsigned int amount );
		void		beRepaired( unsigned int amount );

	protected:
		std::string	_name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;
};

#endif
