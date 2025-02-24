/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:32 by plang             #+#    #+#             */
/*   Updated: 2025/02/24 18:34:38 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
CONSTRUCTORS & DESTRUCTOR
*/

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(int argc, char **argv)
{
	std::stringstream	argStream;

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
			if (*i == '-' && *i - 1 != ' ')
			{
				std::cerr << "Error: invalid input => " << token << std::endl;
				throw std::runtime_error("Error");
			}
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
				std::cerr << "Error: (" << token << ") is not a positive integer" << std::endl;
				throw ;
			}
		}
		if (token == "-" || token == "+")
		{
			std::cerr << "Error: invalid input => " << token << std::endl;
			throw std::runtime_error("Error");
		}
		if (std::find(m_vector.begin(), m_vector.end(), number) != m_vector.end())
		{
			std::cerr << "Error: (" << number << ") <= is a duplicate number" << std::endl;
			throw std::runtime_error("Error");
		}
		m_vector.push_back(number);
		m_deque.push_back(number);
	}
	std::string validOgInput = argStream.str();
	std::cout << "Valid input: => " << validOgInput << std::endl;
	std::cout << "\n\nPrinting containers\n\n";
	std::cout << "\nVector\n\n";
	for(auto &x : m_vector)
		std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "\nDeque\n\n";
	for(auto &x : m_deque)
		std::cout << x << " ";
	std::cout << std::endl;
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

/*
GETTERS
*/

std::vector<int> &	PmergeMe::getVector()
{
	return m_vector;
}

std::vector<int>	PmergeMe::getSortedVector()
{
	return m_sortedVector;
}

std::deque<int> &	PmergeMe::getDeque()
{
	return m_deque;
}

std::deque<int>	PmergeMe::getSortedDeque()
{
	return m_sortedDeque;
}

/*
SORTING FUNCTIONS
*/

void	PmergeMe::jacobsthalInsertionVector(std::vector<int> &losers, std::vector<int> &winners)
{
	std::vector<int>	jacobsthalSequence;

	jacobsthalSequence.push_back(0);
	jacobsthalSequence.push_back(1);
	for (size_t i = 2; i <= winners.size(); i++)
	{
		size_t	sequenceNbr = jacobsthalSequence.at(i - 1) + 2 * jacobsthalSequence.at(i - 2);
		if (sequenceNbr < winners.size())
			jacobsthalSequence.push_back(sequenceNbr);
	}
	std::cout << "\njaqe\n\n";
	for(auto &x : jacobsthalSequence)
		std::cout << x << " ";
	for (size_t i = 0; i < jacobsthalSequence.size() && i < winners.size(); i++)
	{
		// if ((size_t)jacobsthalSequence.at(i) >= winners.size())
		// 	break ;
		size_t	num = winners.at(jacobsthalSequence.at(i));
		auto pos = std::lower_bound(losers.begin(), losers.end(), num); 
		losers.insert(pos, num);
	}
	// for (size_t i = 0; i < winners.size(); i++)
	// {
	// 	if(std::find(losers.begin(), losers.end(), winners.at(i)) != losers.end())
	// 		continue ;
	// 	size_t	num = winners.at(i);
	// 	auto pos = std::lower_bound(losers.begin(), losers.end(), num); 
	// 	losers.insert(pos, num);
	// }
}

void	PmergeMe::sortVector(std::vector<int> &vec)
{
	if (vec.size() == 1)
		return ;

	std::vector<int>					winners;
	std::vector<int>					losers;
	size_t	i = 0;

	while (i + 1 < vec.size())
	{
		if (vec.at(i) < vec.at(i + 1))
		{
			winners.push_back(vec.at(i));
			losers.push_back(vec.at(i + 1));
		}
		else
		{
			winners.push_back(vec.at(i + 1));
			losers.push_back(vec.at(i));
		}
		i += 2;
	}
	if (vec.size() % 2 != 0)
		losers.push_back(vec.at(vec.size() - 1));

	sortVector(losers);
	jacobsthalInsertionVector(losers, winners);

	std::cout << "\nwinner\n\n";
	for(auto &x : winners)
		std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "\nloser\n\n";
	for(auto &x : losers)
		std::cout << x << " ";
	std::cout << std::endl;

	vec = losers;
}
