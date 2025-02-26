/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:11 by plang             #+#    #+#             */
/*   Updated: 2025/02/26 11:15:30 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		dateInNumber = std::stoi(timeStamp.substr(0, 4)) * 10000 + \
			std::stoi(timeStamp.substr(5, 2)) * 100 + \
			std::stoi(timeStamp.substr(8, 2));
		rate = line.substr(comma + 1, line.size());
		if (std::regex_match(rate, regexRate) == false)
			throw std::runtime_error("Error: database has been tampered with");
		m_dataBase.emplace(dateInNumber, std::stod(rate));
	}
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
		try
		{
			calculateExchangeRate(timeStamp, doubleValue);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			continue ;
		}
		
	}
}

void	BitcoinExchange::calculateExchangeRate(const std::string inputTimestamp, const double value)
{
	double result = 0;
	int year = std::stoi(inputTimestamp.substr(0, 4));
	int	month = std::stoi(inputTimestamp.substr(5, 2));
	int	day = std::stoi(inputTimestamp.substr(8, 2));
	int	dateInNumber = year * 10000 + month * 100 + day;

	if (validateDate(year, month, day) == false)
		throw std::runtime_error("Error: date is not valid");
	if (dateInNumber > getCurrentTime())
		throw std::runtime_error("Error: we can not look into the future");
	if (dateInNumber > std::prev(m_dataBase.end())->first)
	{
		result = std::prev(m_dataBase.end())->second * value;
		std::cout << std::fixed << std::setprecision(1) << "(" << std::prev(m_dataBase.end())->first << ")-> " << inputTimestamp << " => " << value << " = " << result << std::endl;
	}
	else if (dateInNumber < m_dataBase.begin()->first)
		throw std::runtime_error("Error: bitcoin was not a thing according to the database");
	else if (m_dataBase.find(dateInNumber) != m_dataBase.end())
	{
		result = m_dataBase.find(dateInNumber)->second * value;
		std::cout << std::fixed << std::setprecision(1) << inputTimestamp << " => " << value << " = " << result << std::endl;
	}
	else 
	{
		int	closestMatch = 0;
		for (auto iter = m_dataBase.begin(); iter != m_dataBase.end(); iter++)
		{
			if (iter->first < dateInNumber)
			{
				closestMatch = iter->first;
			}
		}
		if (closestMatch == std::prev(m_dataBase.end())->first)
		{
			result = std::prev(m_dataBase.end())->second * value;
			std::cout << std::fixed << std::setprecision(1) << "(" << std::prev(m_dataBase.end())->first << ")-> " << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
		else if (closestMatch == m_dataBase.begin()->first)
		{
			result = m_dataBase.begin()->second * value;
			std::cout << std::fixed << std::setprecision(1) << "(" << m_dataBase.begin()->first << ")-> " << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
		else
		{
			result = m_dataBase.upper_bound(closestMatch)->second * value;
			std::cout << std::fixed << std::setprecision(1) << "(" << m_dataBase.lower_bound(closestMatch)->first << ")-> " << inputTimestamp << " => " << value << " = " << result << std::endl;
		}
	}
}

int	BitcoinExchange::getCurrentTime()
{
	time_t	now = time(0);
	tm*		timeinfo = localtime(&now);
	char	timestamp[20];

	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d", timeinfo);
	std::string stdString(timestamp);
	int	dateInNumber = std::stoi(stdString.substr(0, 4)) * 10000 + \
		std::stoi(stdString.substr(5, 2)) * 100 + \
		std::stoi(stdString.substr(8, 2));
	return dateInNumber;
}

bool	BitcoinExchange::validateLeapYear(int year)
{
	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		return true;
	else
		return false;
}

bool	BitcoinExchange::validateDate(int year, int month, int day)
{
	if (day <= 31 && (month == JANUARY\
		|| month == MARCH || month == MAY\
		|| month == JULY || month == AUGUST \
		|| month == OCTOBER || month == DECEMBER))
		return true;
	else if (day <= 30 && (month == APRIL || month == JUNE\
		|| month == SEPTEMBER || month == NOVEMBER ))
		return true;
	else if (month == FEBRUARY)
	{
		if (validateLeapYear(year) == true && day <= 29)
			return true;
		else if (day <= 28)
			return true;
		else
			return false;
	}
	else
		return false;
}
