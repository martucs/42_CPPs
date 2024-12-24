/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:47:14 by martalop          #+#    #+#             */
/*   Updated: 2024/12/24 19:47:25 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

static void	switch_to_upper(char **argv)
{
	for (int x = 1; argv[x]; x++)
	{
		for (int i = 0; argv[x][i]; i++)
		{
			if (argv[x][i] >= 'a' && argv[x][i] <= 'z')
			{
				argv[x][i] = argv[x][i] - 32; 
			}	
		}
		std::cout << argv[x];
	}
	std::cout << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::string str("* LOUD AND UNBEARABLE FEEDBACK NOISE *\n"); 
		std::cout << str;
		return (1);
		// str solo existe dentro de este 'if'
	}
	switch_to_upper(argv);	
	return (0);
}
