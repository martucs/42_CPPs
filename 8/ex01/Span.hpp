/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 16:02:00 by martalop          #+#    #+#             */
/*   Updated: 2025/05/14 16:03:23 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <exception>

class	Span
{
	public:
		Span(unsigned int N);
		Span(const Span&);
		~Span();

		void		addNumber(int);
		void		addMultNumbers();
		int		shortestSpan();
		int		longestSpan();

		unsigned int	getSize() const;
		int		getElement(unsigned int pos) const;
		Span		&operator=(const Span&);
		
		class FullSpan : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

		class NotEnoughSpanInfo : public std::exception
		{
			public:
			virtual const char* what() const throw();
		};

	private:
		Span();
		unsigned int	_size;
		int		_it;
		int		*_elements;

};
std::ostream&	operator<<(std::ostream&, const Span&);

#endif
