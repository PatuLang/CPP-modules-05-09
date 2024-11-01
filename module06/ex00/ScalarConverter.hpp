/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:53 by plang             #+#    #+#             */
/*   Updated: 2024/11/01 13:45:36 by plang            ###   ########.fr       */
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
	public:
		ScalarConverter& operator=(const ScalarConverter&);
		~ScalarConverter();
		
		static void	convert(std::string);
};

// bool	isOnlyF(std::string);
// bool	isOnlyNumbers(std::string);
// int		typeIdentifier(std::string);
// void	isChar(std::string);
// void	isInt(std::string);
// void	isFloat(std::string);
// void	isDouble(std::string);

#endif