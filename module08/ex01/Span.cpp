/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:54:22 by plang             #+#    #+#             */
/*   Updated: 2024/11/20 16:14:51 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
}

Span::Span(unsigned int _N) : N(_N)
{	
}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers)
{
}

Span&	Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers.operator=(other.numbers);
	}
	return *this;
}

Span::~Span()
{
}

void	Span::addNumber(int nbr)
{
	try
	{
		if (numbers.size() < N)
			numbers.insert(nbr);
		else
			throw std::runtime_error("The container is full");	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}

void	Span::addSpan(int fromThis, int toThat)
{
	try
	{
		if (toThat < fromThis)
			throw std::runtime_error("Range is going in the wrong direction");
		if (((toThat) - (fromThis)) > static_cast<int>(N))
			throw std::runtime_error("This range is too big for the container");
		if (static_cast<int>(((toThat) - (fromThis)) + numbers.size()) > static_cast<int>(N))
			throw std::runtime_error("The container can't fit all the numbers");
		for (int i = fromThis; i <= toThat; i++)
			numbers.insert(i);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

unsigned int	Span::shortestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("The container doesn't have enough numbers to get this information");
	std::multiset<int> sSpan;
	std::adjacent_difference(numbers.begin(), numbers.end(), std::inserter(sSpan, sSpan.begin()));
	std::multiset<int>::iterator min = std::min_element(++sSpan.begin(), sSpan.end());
	return *min;
}

unsigned int	Span::longestSpan()
{
	if (numbers.size() < 2)
		throw std::runtime_error("The container doesn't have enough numbers to get this information");
	auto [min, max] = std::minmax_element(numbers.begin(), numbers.end());
	return (*max - *min);
}
