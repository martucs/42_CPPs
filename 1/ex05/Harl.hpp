/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:06:51 by martalop          #+#    #+#             */
/*   Updated: 2025/03/21 14:48:33 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		Harl();
		~Harl();
		std::string	levels[4];
		
		void(Harl::*levelFunctions[4])(void);
	

		void		setLevels( void);
		void		complain( std::string level );
};

#endif
