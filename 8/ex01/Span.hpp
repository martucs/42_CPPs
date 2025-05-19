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
		int		shortestSpan();
		int		longestSpan();
		unsigned int	getSize() const;
		int		getElement(unsigned int pos) const;
		unsigned int	getFilledNum() const;
		Span		&operator=(const Span&);
		
		template <typename Iterator>
		void		addRange(Iterator beg_it, Iterator end_it);

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
		unsigned int	_filled;
		int		*_elements;

};
std::ostream&	operator<<(std::ostream&, const Span&);

template <typename Iterator>
void	Span::addRange(Iterator beg_it, Iterator end_it)
{
	if (std::distance(beg_it, end_it) + this->_filled > this->_size)
		throw std::overflow_error("Range doesn't fit in Span!");
	while (beg_it != end_it)
	{
		addNumber(*beg_it);
		beg_it++;
	}
}

#endif
