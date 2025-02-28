/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:32 by plang             #+#    #+#             */
/*   Updated: 2025/02/28 19:18:12 by plang            ###   ########.fr       */
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
	auto parseStart = std::chrono::high_resolution_clock::now();
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
		if (token.empty())
			continue ;
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
	auto parseStop = std::chrono::high_resolution_clock::now();
	m_parseTime = parseStop - parseStart;
}

PmergeMe::PmergeMe(const PmergeMe &other) : m_vector(other.m_vector), m_deque(other.m_deque)\
, m_vecStart(other.m_vecStart), m_vecStop(other.m_vecStop), m_deqStart(other.m_deqStart), m_deqStop(other.m_deqStop)
{
}

const PmergeMe&	PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		m_vector = other.m_vector;
		m_deque = other.m_deque;
		m_vecStart = other.m_vecStart;
		m_vecStop = other.m_vecStop;
		m_deqStart = other.m_deqStart;
		m_deqStop = other.m_deqStop;
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

std::deque<int> &	PmergeMe::getDeque()
{
	return m_deque;
}

/*
PRINTERS
*/

void	PmergeMe::vecPrint()
{
	for(auto &x : m_vector)
		std::cout << x << " ";
	std::cout << std::endl;
}

void	PmergeMe::vecPrintTruncated()
{
	if (m_vector.size() > 30)
	{
		for (int i = 0; i < 10; i++)
        	std::cout << m_vector.at(i) << " ";
		std::cout << "[...]";
		std::cout << std::endl;
	}
	else
	{
		for(auto &x : m_vector)
			std::cout << x << " ";
		std::cout << std::endl;
	}
}

void	PmergeMe::deqPrint()
{
	for(auto &x : m_deque)
		std::cout << x << " ";
	std::cout << std::endl;
}

void	PmergeMe::deqPrintTruncated()
{
	if (m_deque.size() > 30)
	{
		for (int i = 0; i < 10; i++)
        	std::cout << m_deque.at(i) << " ";
		std::cout << "[...]";
		std::cout << std::endl;
	}
	else
	{
		for(auto &x : m_deque)
			std::cout << x << " ";
		std::cout << std::endl;
	}
}

/*
TIME FUNCTIONS
*/

void	PmergeMe::startVecTime()
{
	m_vecStart = std::chrono::high_resolution_clock::now();
}

void	PmergeMe::startDeqTime()
{
	m_deqStart = std::chrono::high_resolution_clock::now();
}

/*
SORTING FUNCTIONS : VECTOR
*/

void	PmergeMe::theVector()
{
	startVecTime();

	std::cout << "Before: ";
	vecPrintTruncated();
	// vecPrint();
	
	vecSort(getVector());

	std::cout << "After: ";
	vecPrintTruncated();
	// vecPrint();

	std::chrono::duration<double> vecElapsed = m_vecStop - m_vecStart;
	std::cout << "Time to process a range of " << m_vector.size() << " elements with std::vector<int> : " << std::fixed << std::setprecision(6) << m_parseTime.count() + vecElapsed.count() << " µs" << std::endl;
}

void	PmergeMe::vecJacobsthalInsertion(std::vector<int> &main, std::vector<int> &pending)
{
	std::vector<int>	jacobsthalSequence;

	jacobsthalSequence.push_back(0);
	jacobsthalSequence.push_back(1);
	for (size_t i = 2; ; i++)
	{
		size_t	sequenceNbr = jacobsthalSequence.at(i - 1) + 2 * jacobsthalSequence.at(i - 2);
		if (sequenceNbr >= pending.size())
			break ;
		jacobsthalSequence.push_back(sequenceNbr);
	}
	for (size_t i = 2; i < jacobsthalSequence.size() && i < pending.size(); i++)
	{
		if ((size_t)jacobsthalSequence.at(i) >= pending.size())
			break ;
		size_t	num = pending.at(jacobsthalSequence.at(i));
		auto pos = std::lower_bound(main.begin(), main.end(), num);
		main.insert(pos, num);
	}
	for (size_t i = 0; i < pending.size(); i++)
	{
		if(std::find(main.begin(), main.end(), pending.at(i)) != main.end())
			continue ;
		size_t	num = pending.at(i);
		auto pos = std::lower_bound(main.begin(), main.end(), num); 
		main.insert(pos, num);
	}
}

void	PmergeMe::vecSort(std::vector<int> &vec)
{
	if (vec.empty())
		throw std::runtime_error("Error: Container is empty");
	if (vec.size() == 1)
		return ;

	std::vector<int>					pending;
	std::vector<int>					main;
	size_t	i = 0;

	while (i + 1 < vec.size())
	{
		if (vec.at(i) < vec.at(i + 1))
		{
			pending.push_back(vec.at(i));
			main.push_back(vec.at(i + 1));
		}
		else
		{
			pending.push_back(vec.at(i + 1));
			main.push_back(vec.at(i));
		}
		i += 2;
	}
	if (vec.size() % 2 != 0)
		main.push_back(vec.at(vec.size() - 1));

	vecSort(main);
	vecJacobsthalInsertion(main, pending);
	
	vec = main;
	m_vecStop = std::chrono::high_resolution_clock::now();
}

/*
SORTING FUNCTIONS : DEQUE
*/

void	PmergeMe::theDeque()
{
	startDeqTime();

	std::cout << "Before: ";
	deqPrintTruncated();
	// deqPrint();
	
	deqSort(getDeque());
	
	std::cout << "After: ";
	deqPrintTruncated();
	// deqPrint();

	std::chrono::duration<double> deqElapsed = m_deqStop - m_deqStart;
	std::cout << "Time to process a range of " << m_deque.size() << " elements with std::deque<int> : " << std::fixed << std::setprecision(6) << m_parseTime.count() + deqElapsed.count() << " µs" << std::endl;
}

void	PmergeMe::deqJacobsthalInsertion(std::deque<int> &main, std::deque<int> &pending)
{
	std::deque<int>	jacobsthalSequence;

	jacobsthalSequence.push_back(0);
	jacobsthalSequence.push_back(1);
	for (size_t i = 2; ; i++)
	{
		size_t	sequenceNbr = jacobsthalSequence.at(i - 1) + 2 * jacobsthalSequence.at(i - 2);
		if (sequenceNbr >= pending.size())
			break ;
		jacobsthalSequence.push_back(sequenceNbr);
	}
	for (size_t i = 2; i < jacobsthalSequence.size() && i < pending.size(); i++)
	{
		if ((size_t)jacobsthalSequence.at(i) >= pending.size())
			break ;
		size_t	num = pending.at(jacobsthalSequence.at(i));
		auto pos = std::lower_bound(main.begin(), main.end(), num);
		main.insert(pos, num);
	}
	for (size_t i = 0; i < pending.size(); i++)
	{
		if(std::find(main.begin(), main.end(), pending.at(i)) != main.end())
			continue ;
		size_t	num = pending.at(i);
		auto pos = std::lower_bound(main.begin(), main.end(), num); 
		main.insert(pos, num);
	}
}

void	PmergeMe::deqSort(std::deque<int> &deq)
{
	if (deq.size() == 1)
		return ;

	std::deque<int>					pending;
	std::deque<int>					main;
	size_t	i = 0;

	while (i + 1 < deq.size())
	{
		if (deq.at(i) < deq.at(i + 1))
		{
			pending.push_back(deq.at(i));
			main.push_back(deq.at(i + 1));
		}
		else
		{
			pending.push_back(deq.at(i + 1));
			main.push_back(deq.at(i));
		}
		i += 2;
	}
	if (deq.size() % 2 != 0)
		main.push_back(deq.at(deq.size() - 1));

	deqSort(main);
	deqJacobsthalInsertion(main, pending);
	
	deq = main;
	m_deqStop = std::chrono::high_resolution_clock::now();
}

void	PmergeMe::isItSorted()
{
	if (std::is_sorted(m_vector.begin(), m_vector.end()))
	{
		std::cout << "The vector is sorted!" << std::endl;
	}
	else
		std::cout << "The vector is NOT sorted!" << std::endl;
		
	if (std::is_sorted(m_vector.begin(), m_vector.end()))
	{
		std::cout << "The deque is sorted!" << std::endl;
	}
	else
		std::cout << "The deque is NOT sorted!" << std::endl;
}
