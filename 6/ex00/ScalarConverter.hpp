/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:38:19 by martalop          #+#    #+#             */
/*   Updated: 2025/05/03 20:22:21 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
//# include <string>

typedef enum e_inputType
{
	NDEF,	// 0
	CHAR,	// 1
	INT,	// 2
	FLOAT,	// 3
	DOUBLE,	// 4
	LITERAL,// 5
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
