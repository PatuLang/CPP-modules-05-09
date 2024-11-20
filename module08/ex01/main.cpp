/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:08:10 by plang             #+#    #+#             */
/*   Updated: 2024/11/20 15:45:41 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		Span sp(100);
		Span fp(sp);

		sp.addNumber(2147483647);
		sp.addNumber(-2147483648);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(350);
		sp.addNumber(-383);
		sp.addNumber(848);
		sp.addNumber(58);
		sp.addNumber(11000);
		sp.addNumber(89383);
		sp.addNumber(0);
		sp.addSpan(-25000, 25000);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		fp.addNumber(0);
		fp.addNumber(10);
		std::cout << fp.shortestSpan() << std::endl;
		std::cout << fp.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
