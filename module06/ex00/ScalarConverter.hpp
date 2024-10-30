/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:53 by plang             #+#    #+#             */
/*   Updated: 2024/10/30 14:56:57 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter& operator=(const ScalarConverter&);
	public:
		~ScalarConverter();
		
		static void	convert(std::string);
};

bool	isOnlyNumbers(std::string);
int		typeIdentifier(std::string);
void	isChar(std::string);
void	isInt(std::string);
void	isFloat(std::string);
void	isDouble(std::string);

#endif