/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:05:00 by martalop          #+#    #+#             */
/*   Updated: 2025/04/26 18:47:57 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"


class	Intern
{
	public:
		Intern();
		Intern( const Intern& );
		~Intern();
	
		Intern&	operator=( const Intern& );

		std::string	formNames[3];
		AForm	*(Intern::*allFormsPtr[3])(const std::string target);

		AForm	*makeForm(const std::string name, const std::string target);
		AForm	*makePresidentialForm(const std::string target);
		AForm	*makeRobotomyForm(const std::string target);
		AForm	*makeShrubberyForm(const std::string target);

		class NonExistentFormException : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};		
};

#endif
