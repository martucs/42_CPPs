/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:34:40 by martalop          #+#    #+#             */
/*   Updated: 2025/05/07 22:02:39 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &a, T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T	min(const T a, const T b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template <typename T>
T	max(const T a, const T b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif
