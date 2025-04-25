/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:39:41 by martalop          #+#    #+#             */
/*   Updated: 2025/04/25 15:41:38 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm( std::string );
		RobotomyRequestForm( const RobotomyRequestForm& );
		~RobotomyRequestForm();
		
		RobotomyRequestForm&	operator=( const RobotomyRequestForm& );
		
		virtual void	beSigned(Bureaucrat&);
		virtual void	execute(Bureaucrat const& executor) const;
		std::string		getTarget(void);

	private:
		std::string	_target;
};

#endif
