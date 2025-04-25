/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:41:20 by martalop          #+#    #+#             */
/*   Updated: 2025/04/25 14:23:42 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define  SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string );
		ShrubberyCreationForm( const ShrubberyCreationForm& );
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm&	operator=( const ShrubberyCreationForm& );
		
		virtual void	beSigned(Bureaucrat&);
		virtual void	execute(Bureaucrat const& executor) const;
		std::string		getTarget(void);

	private:
		std::string	_target;
};

#endif
