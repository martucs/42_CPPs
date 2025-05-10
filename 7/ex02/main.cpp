/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:34:02 by martalop          #+#    #+#             */
/*   Updated: 2025/05/08 16:18:19 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <complex>

int	main()
{
	try
	{
		Array	<int>			int_arr;
		Array	<std::string>		str_arr(3);
		Array	<std::complex<double> >	dbl_cmplx_arr(10);


		std::cout << std::endl;
		std::cout << "int array size = " << int_arr.size() << std::endl;
		//std::cout << int_arr[1] << std::endl;
		std::cout << "str array size = " << str_arr.size() << std::endl;
		std::cout << "complex array size = " << dbl_cmplx_arr.size() << std::endl;

		std::cout << std::endl;
		str_arr[0] = "hola";
		std::cout << "str[0] = " << str_arr[0] << std::endl;
		
		str_arr[1] = "que";
		std::cout << "str[1] = " << str_arr[1] << std::endl;
		
		str_arr[2] = "tal";
		std::cout << "str[2] = " << str_arr[2] << std::endl;
		std::cout << std::endl;
		
		Array	<std::string>	str_arr_copied(str_arr);
		
		std::cout << "str_arr_copied[2] = " << str_arr_copied[2] << std::endl;
		std::cout << std::endl;
		
		dbl_cmplx_arr[0] = 42;
		std::cout << "complex[0] real = " << dbl_cmplx_arr[0].real() << std::endl;
		std::cout << "complex[0] imaginary = " << dbl_cmplx_arr[0].imag() << std::endl;
		std::cout << std::endl;
		
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Runtime exception: " << e.what() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Other exception happened: " << e.what() << std::endl;
	}
	return (0);
}
