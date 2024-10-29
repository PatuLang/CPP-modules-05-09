/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:51 by plang             #+#    #+#             */
/*   Updated: 2024/10/29 16:47:35 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter&)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void	ScalarConverter::convert(std::string input)
{
	try
	{
		int	convertedInt;
		std::cout << "Trying string to int\n";
		convertedInt = std::stoi(input);
		std::cout << convertedInt << "\n";
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << "Impossible" << '\n';
		std::cerr << e.what() << '\n';
	}
	try
	{
		float	convertedFloat;
		std::cout << "Trying string to float\n";
		convertedFloat = std::stof(input);
		std::cout << std::fixed << std::setprecision(1);
		std::cout << convertedFloat << "f\n";
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		double	convertedDouble;
		std::cout << "Trying string to double\n";
		convertedDouble = std::stod(input);
		std::cout << std::fixed << std::setprecision(1);
		std::cout << convertedDouble << "\n";
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
}

const char* ScalarConverter::CustomException::what() const noexcept
{
	return "hahaha!";
}
