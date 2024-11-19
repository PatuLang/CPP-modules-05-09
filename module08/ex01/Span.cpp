/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:54:22 by plang             #+#    #+#             */
/*   Updated: 2024/11/19 12:36:37 by plang            ###   ########.fr       */
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
		if (((toThat) - (fromThis)) > static_cast<int>(N))
			throw std::runtime_error("This range is too big for the container");
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
	unsigned int	shortSpan = 0;
	if (numbers.size() < 2)
		throw std::runtime_error("The container doesn't have enough numbers to get this information");
	shortSpan = std::numeric_limits<unsigned int>::max();
	for (auto iter = numbers.begin(); std::next(iter) != numbers.end(); iter++)
	{
		if (shortSpan > static_cast<unsigned int>(*std::next(iter) - *iter))
			shortSpan = (*std::next(iter) - *iter);
	}
	return shortSpan;
}

unsigned int	Span::longestSpan()
{
	unsigned int	longSpan = 0;
	if (numbers.size() < 2)
		throw std::runtime_error("The container doesn't have enough numbers to get this information");
	longSpan = (*numbers.rbegin() - *numbers.begin());
	return longSpan;
}
