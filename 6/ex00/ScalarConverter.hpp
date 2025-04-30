/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:38:19 by martalop          #+#    #+#             */
/*   Updated: 2025/04/27 20:39:50 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
//# include <string>

typedef enum e_inputType
{
	CHAR,	// 0
	INT,	// 1
	FLOAT,	// 2
	DOUBLE,	// 3
	NDEF,	// 4
} t_inputType;

class	ScalarConverter
{
	public:
		ScalarConverter( const ScalarConverter& );
		~ScalarConverter();
		
		ScalarConverter&	operator=( const ScalarConverter& );
		
		static void	convert(const std::string input);
		//t_inputType	getType(const std::string input);
	private:
		ScalarConverter();
		

};

std::ostream&	operator<<(std::ostream&, const ScalarConverter&);

#endif
