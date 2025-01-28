/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:14 by plang             #+#    #+#             */
/*   Updated: 2025/01/27 10:28:13 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <sstream>
# include <ctime>
# include <fstream>
# include <iomanip>
# include <regex>
# include <limits.h>

enum monthDays
{
	JANUARY = 1,
	FEBRUARY = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUGUST = 8,
	SEPTEMBER = 9,
	OCTOBER = 10,
	NOVEMBER = 11,
	DECEMBER = 12
};

class BitcoinExchange
{
	private:
		std::map<int, float>		m_dataBase;
		
		BitcoinExchange(const BitcoinExchange &);
		const BitcoinExchange &	operator=(const BitcoinExchange &);
		
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	readInput(const std::string);
		void	calculateExchangeRate(const std::string, const double);
		int		getCurrentTime();
		bool	validateLeapYear(int);
		bool	validateDate(int, int, int);
};

#endif