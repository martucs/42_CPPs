/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:35:29 by martalop          #+#    #+#             */
/*   Updated: 2025/05/12 16:35:57 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm> // para std::find

template <typename T>
int	easyfind(T& container, int intVar)
{
	typename T::iterator	it = std::find(container.begin(), container.end(), intVar);
	
	if (it != container.end())
	{
		std::cout << "- Number " << intVar << " found! -" << std::endl;
		return (std::distance(container.begin(), it));
		
	}
	std::cout << "- Number " << intVar << " NOT found! -" << std::endl;
	return (-1);
}

#endif
