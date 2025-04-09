/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 16:48:38 by martalop          #+#    #+#             */
/*   Updated: 2025/04/09 14:05:09 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed&);
		
		Fixed&	operator=(const Fixed&);
		~Fixed();

		int	getRawBits( void ) const;
		void	setRawBits( int const );
	
	private:
		int					_value;
		static const int	_fractionalNum = 8;
};

#endif
