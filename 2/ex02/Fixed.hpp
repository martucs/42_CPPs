/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:48:38 by martalop          #+#    #+#             */
/*   Updated: 2025/04/09 15:54:35 by martalop         ###   ########.fr       */
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
		
		//assignment
		Fixed&	operator=(const Fixed&);
		//comparison
		bool	operator>(const Fixed&) const;
		bool	operator<(const Fixed&) const;
		bool	operator>=(const Fixed&) const;
		bool	operator<=(const Fixed&) const;
		bool	operator==(const Fixed&) const;
		bool	operator!=(const Fixed&) const;
		//arithmetic
		Fixed	operator+(const Fixed&) const; 
		Fixed	operator-(const Fixed&) const;
		Fixed	operator*(const Fixed&) const;
		Fixed	operator/(const Fixed&) const;
		//increment/decrement
		Fixed	operator++(void);
		Fixed	operator--(void);
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		int					toInt( void ) const;
		float				toFloat ( void ) const;
		int					getRawBits( void ) const;
		void				setRawBits( int const );
		static Fixed&		min( Fixed&, Fixed& );
		static Fixed&		max( Fixed&, Fixed& );
		static const Fixed&	min( const Fixed&, const Fixed& );
		static const Fixed&	max( const Fixed&, const Fixed& );
	
	private:
		int					_value;
		static const int	_fractionalNum = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

#endif
