/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 19:23:52 by martalop          #+#    #+#             */
/*   Updated: 2025/06/12 19:26:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>

class	BitcoinExchange
{
	public:
		BitcoinExchange(const std::string dataPath);
		BitcoinExchange(const BitcoinExchange&);
		~BitcoinExchange();

		BitcoinExchange		&operator=(const BitcoinExchange&);
		void			printDataBase();
		void			calculatePrice(const std::string inputFileName);
		bool			checkValidity(const std::string date, const std::string value);
		float			multiplyValue(const std::string date, const std::string value);
		std::string		closestDate(const std::string fileDate);
	private:
		BitcoinExchange();		
		std::map<std::string, float>	_dataBase;
};

#endif
