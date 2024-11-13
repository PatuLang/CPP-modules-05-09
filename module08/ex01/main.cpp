/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:10 by plang             #+#    #+#             */
/*   Updated: 2024/11/13 18:28:02 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span sp = Span(10000);
	
	sp.addNumber(2147483647);
	sp.addNumber(-2147483648);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addNumber(11);
	sp.addSpan(-2147, 2147);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	return 0;
}
