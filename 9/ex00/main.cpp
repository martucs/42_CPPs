/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 18:37:27 by martalop          #+#    #+#             */
/*   Updated: 2025/05/29 18:44:16 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc infile.txt" << std::endl;
		return (1);
	}
	try
	{
		BitcoinExchange	exchange("./data.csv");
		
	//	exchange.printDataBase();
		exchange.calculatePrice(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

// INFO: PROGRAM HAS TO:
	// 1. store database in "./data.csv" in a std::map
	// 2. open file 'argv[1]'
		// if not possible -> "error: could not open file" 
	// 3. check that file is in correct format
		// error if invalid date 
		// error if negative value
		// error if num is bigger than int
		// error if there is no num or date
	// 4. multiply value * exchange rate 
	// 5. show result (date -> value = result)
