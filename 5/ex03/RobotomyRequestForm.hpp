/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:39:41 by martalop          #+#    #+#             */
/*   Updated: 2025/04/27 19:56:32 by martalop         ###   ########.fr       */
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
		
		virtual void	execute(Bureaucrat const& executor) const;
		std::string		getTarget(void);
		void			setTarget(const std::string);

	private:
		std::string	_target;
};

#endif
