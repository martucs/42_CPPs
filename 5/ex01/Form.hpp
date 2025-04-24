/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:06:33 by martalop          #+#    #+#             */
/*   Updated: 2025/04/23 17:18:24 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	Form
{
	public:
		Form();
		Form( const std::string, int signGrade, int execGrade);
		Form( const Form& );
		~Form();
		
		Form&	operator=( const Form& );

		std::string		getName(void) const;
		int				getSignStatus(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;

		void			beSigned(Bureaucrat);
		
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
		const int			_requiredSignGrade;
		const int			_requiredExecGrade;
		bool				_signStatus;
};

std::ostream&	operator<<(std::ostream&, const Form&);

#endif
