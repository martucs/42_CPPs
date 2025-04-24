/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:06:33 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 21:40:30 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class	AForm
{
	public:
		AForm();
		AForm( const std::string, int signGrade, int execGrade);
		AForm( const AForm& );
		~AForm();
		
		AForm&	operator=( const AForm& );

		std::string		getName(void) const;
		int				getSignStatus(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;
		void			setSignStatus(bool);

		virtual void	beSigned(Bureaucrat&) = 0;
		virtual void	execute(Bureaucrat const& executor) const = 0;
		
		class FormNotSignedException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};		
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

std::ostream&	operator<<(std::ostream&, const AForm&);

#endif
