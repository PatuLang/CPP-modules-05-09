/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:54:25 by plang             #+#    #+#             */
/*   Updated: 2024/11/13 18:32:44 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <algorithm>
# include <set>
# include <limits>

class Span
{
	private:
		unsigned int	N;
		std::multiset<int>	numbers;
	public:
		Span();
		Span(unsigned int);
		Span(const Span&);
		Span& operator=(const Span&);
		~Span();

		void			addNumber(int);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addSpan(int, int);
};

#endif
