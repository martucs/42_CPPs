/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:36 by martalop          #+#    #+#             */
/*   Updated: 2025/04/16 21:04:36 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class	Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat( std::string );
		Bureaucrat( const Bureaucrat& );
		~Bureaucrat();
		
		Bureaucrat&	operator=( const Bureaucrat& );

		std::string		getName(void) const;
		int				getGrade(void) const;

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);
#endif

