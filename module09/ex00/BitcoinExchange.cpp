/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:11 by plang             #+#    #+#             */
/*   Updated: 2025/01/13 19:39:27 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// default file for webser. test.conf if not supplied by user. cookies. default settings? remove completely? check for all server settings after extraction?


#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream	file("data.csv");
	if (!file.is_open())
	{
		throw std::runtime_error("Error: Opening data.csv file failed");
	}
	std::string	line;
	std::string	timeStamp;
	std::string	rate;
	int			dateInNumber;
	std::regex	regexTimeStamp(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\d|3[0-1])$)");
	std::regex	regexRate(R"(^[0-9]+(\.[0-9]+)?$)");
	while (getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue;
		size_t comma = line.find(",");
		timeStamp = line.substr(0, comma);
		if (std::regex_match(timeStamp, regexTimeStamp) == false)
			throw std::runtime_error("Error: database has been tampered with");
		dateInNumber = std::stoi(timeStamp.substr(0, 4)) * 1000 + \
			std::stoi(timeStamp.substr(5, 7)) * 100 + \
			std::stoi(timeStamp.substr(8, 10));
		rate = line.substr(comma + 1, line.size());
		if (std::regex_match(rate, regexRate) == false)
			throw std::runtime_error("Error: database has been tampered with");
		m_dataBase.emplace(dateInNumber, std::stod(rate));
	}
	std::cout << "Printing data: \n";
	for(auto &line: m_dataBase)
	{
		std::cout << line.first << " -- " << line.second << std::endl;
	}
	std::cout << "Printing data done: \n\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	m_dataBase = other.m_dataBase;
}

const BitcoinExchange &	BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
	{
		m_dataBase = other.m_dataBase;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::readInput(const std::string inputFile)
{
	std::ifstream	file(inputFile);
	if (!file.is_open())
	{
		throw std::runtime_error("Error: Could not open file.");
	}
	size_t		delim;
	std::string	line;
	std::string	timeStamp;
	std::string	value;
	std::regex	regexTimeStamp(R"(^\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\d|3[0-1])$)");
	double		doubleValue;
	while (getline(file, line))
	{
		if (line == "date | value")
			continue;
		delim = line.find("|");
		if (delim == line.npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		timeStamp = line.substr(0, delim - 1);
		value = line.substr(delim + 1, line.size());
		try
		{
			doubleValue = std::stod(value);
		}
		catch(const std::exception& e)
		{
			std::cerr << "Error: bad input => " << line << '\n';
		}
		if (std::regex_match(timeStamp, regexTimeStamp) == false)
		{
			std::cerr << "Error: bad input => " << timeStamp << std::endl;
			continue ;
		}
		if(doubleValue < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if(doubleValue > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		calculateExchangeRate(timeStamp, doubleValue);
	}
}

void	BitcoinExchange::calculateExchangeRate(const std::string inputTimestamp, const double value)
{
	double result = 0;
	std::regex regexYear (R"(^(2009|201[0-9]|202[0-2])-(0[1-9]|1[0-2])-(0[1-9]|[1-2]\d|3[0-1])$)");
	int	dateInNumber = dateInNumber = std::stoi(inputTimestamp.substr(0, 4)) * 1000 + \
		std::stoi(inputTimestamp.substr(5, 7)) * 100 + \
		std::stoi(inputTimestamp.substr(8, 10));

	if (std::regex_match(inputTimestamp, regexYear) == false)
	{
		double year = std::stod(inputTimestamp.substr(0, 4));
		if (year > static_cast<double>(2022))
		{
			result = std::prev(m_dataBase.end())->second * value;
			std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
		else if (year < static_cast<double>(2009))
		{
			result = std::next(m_dataBase.begin())->second * value;
			std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
	}
	else if (m_dataBase.find(dateInNumber) != m_dataBase.end())
	{
		result = m_dataBase.find(dateInNumber)->second * value;
		std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
	}
	else 
	{
		int	difference = std::prev(m_dataBase.end())->first;
		int	closestMatch = 0;
		for (auto iter = std::next(m_dataBase.begin()); iter != m_dataBase.end(); iter++)
		{
			int	absolutValue = std::abs(iter->first - dateInNumber);
			if (absolutValue < difference)
			{
				difference = absolutValue;
				closestMatch = iter->first;
			}
		}
		if (closestMatch == std::prev(m_dataBase.end())->first)
		{
			result = std::prev(m_dataBase.end())->second * value;
			std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
		else if (closestMatch == std::next(m_dataBase.begin())->first)
		{
			result = std::next(m_dataBase.begin())->second * value;
			std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
		else
		{
			result = std::prev(m_dataBase.find(closestMatch))->second * value;
			std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
	}
}
