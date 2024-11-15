/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:10 by plang             #+#    #+#             */
/*   Updated: 2024/11/14 12:52:16 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(50000); // smallest is always 0 if the size is 10 000, works fine with 1000, not a deep copy, copys fuck up the other ones, spans get wierd
	
	// sp.addNumber(2147483647);
	// sp.addNumber(-2147483648);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// sp.addNumber(11);
	// sp.addNumber(11);
	// sp.addNumber(11);
	// sp.addNumber(11);
	// sp.addNumber(11);
	// sp.addNumber(11);
	sp.addSpan(-25000, 25000);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
