/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:32 by plang             #+#    #+#             */
/*   Updated: 2025/01/31 17:56:01 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::stringstream	argStream;
	std::vector<int>	chekedNumbers;

	for (int i = 1; i != argc; i++)
	{
		argStream << argv[i];
		if (i < argc - 1)
			argStream << " ";
	}

	std::string	token;
	char		delim = ' ';
	int			number;
	
	while (getline(argStream, token, delim))
	{
		for (std::string::iterator i = token.begin(); i < token.end(); i++)
		{
			if (*i == ' ' || *i == '-' || *i == '+')
				continue ;
			if (isdigit(*i) == false)
			{
				std::cerr << "Error: invalid input => " << token << std::endl;
				throw std::runtime_error("Error");
			}
			try
			{
				number = std::stoi(token);
				if (number < 0)
					throw std::out_of_range("Error");
			}
			catch(const std::exception& e)
			{
				std::cerr << "Error: (" << token << ") not inside the range of 0 < INT_MAX" << std::endl;
				throw ;
			}
		}
		m_vector.push_back(number);
		m_deque.push_back(number);
	}
	// std::string validOgInput = argStream.str();
	// std::cout << "Valid input: => " << validOgInput << std::endl;
	// std::cout << "\n\nPrinting containers\n\n";
	// std::cout << "\nVector\n\n";
	// for(auto &x : m_vector)
	// 	std::cout << x << std::endl;
	// std::cout << "\nDeque\n\n";
	// for(auto &x : m_deque)
	// 	std::cout << x << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &other) : m_vector(other.m_vector), m_deque(other.m_deque)
{
}

const PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		m_vector = other.m_vector;
		m_deque = other.m_deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}
