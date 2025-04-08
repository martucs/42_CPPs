/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:48:38 by martalop          #+#    #+#             */
/*   Updated: 2025/04/07 19:17:24 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed( const int );
		Fixed( const float );
		Fixed( const Fixed& );
		~Fixed();
		
		void	operator=(const Fixed&);
		
		int		toInt( void ) const;
		float	toFloat ( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const );
	
	private:
		int					_value;
		static const int	_fractionalNum = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
