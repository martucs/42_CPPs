/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:37:47 by martalop          #+#    #+#             */
/*   Updated: 2025/04/24 16:03:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target);
		PresidentialPardonForm( const PresidentialPardonForm& );
		~PresidentialPardonForm();
		
		PresidentialPardonForm&	operator=( const PresidentialPardonForm& );
		
		virtual void	beSigned(Bureaucrat);

	private:
		std::string	_target;
};

#endif
