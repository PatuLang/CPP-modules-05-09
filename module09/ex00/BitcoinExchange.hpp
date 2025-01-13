/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:14 by plang             #+#    #+#             */
/*   Updated: 2025/01/13 19:05:53 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <sstream>
# include <ctime>
# include <fstream>
#include <iomanip>
#include <regex>
#include <limits.h>


class BitcoinExchange
{
	private:
		std::map<int, float>		m_dataBase;
		// std::multimap<std::string, float>	m_inputFile;
		
		BitcoinExchange(const BitcoinExchange &);
		const BitcoinExchange &	operator=(const BitcoinExchange &);
		
	public:
		BitcoinExchange();
		~BitcoinExchange();

		void	readInput(const std::string);
		void	calculateExchangeRate(const std::string, const double);
};

#endif