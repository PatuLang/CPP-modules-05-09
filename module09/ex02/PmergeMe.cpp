/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:32 by plang             #+#    #+#             */
/*   Updated: 2025/02/03 17:11:50 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

void	PmergeMe::sortFordJohnson()
{
	std::vector<int>					winner;
	std::vector<int>					loser;
	size_t	i = 0;

	while (i < m_vector.size())
	{
		if (m_vector.at(i) < m_vector.at(i + 1))
		{
			winner.push_back(m_vector.at(i));
			loser.push_back(m_vector.at(i + 1));
		}
		else
		{
			winner.push_back(m_vector.at(i + 1));
			loser.push_back(m_vector.at(i));
		}
		if (i + 3 == m_vector.size() && m_vector.size() % 2 != 0)
		{
			winner.push_back(m_vector.at(i + 2));
			break ;
		}
		i++;
		i++;
	}
	m_vector.clear();



	std::cout << "\nwinner\n\n";
	for(auto &x : winner)
		std::cout << x << " ";
	std::cout << std::endl;
	std::cout << "\nloser\n\n";
	for(auto &x : loser)
		std::cout << x << " ";
	std::cout << std::endl;



	while (!winner.empty())
	{
		auto minElement = std::min_element(winner.begin(), winner.end());
		m_vector.push_back(*minElement);
		winner.erase(minElement);
	}
	while (!loser.empty())
	{
		auto iter = loser.end();

		winner.begin();
		auto middle = winner.size() / 2;
		winner.end();

		loser.pop_back();
	}
	

	std::cout << "\nVector\n\n";
	for(auto &x : m_vector)
		std::cout << x << " ";
	std::cout << std::endl;
}
