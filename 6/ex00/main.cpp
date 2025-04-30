/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 20:37:05 by martalop          #+#    #+#             */
/*   Updated: 2025/04/30 17:46:34 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

/*int main()
{
  int a = 10;
  char c = 'a';
  
  (void)c;
  // Pass at compile time, 
  // may fail at run time
  int* q = (int*)&a;
  int* p = std::static_cast<int*>(&a);
  std::cout << &a << "   " << a << std::endl;
  return (0);
}*/

int	main(int argc, char **argv)
{
	std::string	test = "test";

	if (argc >= 2)
	{
		std::cout << "I received: " << argv[1] << std::endl;
		ScalarConverter::convert(argv[1]);
	}
	return (0);
}
