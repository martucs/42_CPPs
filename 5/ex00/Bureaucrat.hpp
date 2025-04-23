/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:50:36 by martalop          #+#    #+#             */
/*   Updated: 2025/04/23 13:07:32 by martalop         ###   ########.fr       */
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
		Bureaucrat( const std::string, int );
		Bureaucrat( const Bureaucrat& );
		~Bureaucrat();
		
		Bureaucrat&	operator=( const Bureaucrat& );

		std::string		getName(void) const;
		int				getGrade(void) const;
		void			incrementGrade(void);
		void			decrementGrade(void);

		class GradeTooLowException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream&	operator<<(std::ostream&, const Bureaucrat&);

#endif
