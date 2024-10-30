/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:51 by plang             #+#    #+#             */
/*   Updated: 2024/10/30 15:15:03 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

bool	isOnlyNumbers(std::string input)
{
	for(char c: input)
	{
		if (!std::isdigit(c))
			return false;
	}
	return true;
}

int	typeIdentifier(std::string input)
{
	std::cout << "Identifier\n";
	if (input.empty())
		return 5;
	if (input[0] == '\'' && (std::isalpha(input[1]) || std::isprint(input[1])) && input[2] == '\'')
		return 1;
	else if (input.back() == 'f')
		return 2;
	else if (input.find('.') != std::string::npos)
		return 3;
	else if (((input[0] == '-' || input[0] == '+') && input.length() > 1) || isOnlyNumbers(input) == true)
		return 4;
	else
		return 5;
}

void	isChar(std::string input)
{
	(void)input;
	std::cout << "Char\n";
}

void	isInt(std::string input)
{
	(void)input;
	std::cout << "Int\n";
}

void	isFloat(std::string input)
{
	(void)input;
	std::cout << "Float\n";
}

void	isDouble(std::string input)
{
	(void)input;
	std::cout << "Double\n";
}

void	ScalarConverter::convert(std::string input)
{
	// identify type - switch or turnery
	// or just a checker for each specific traits of each types: ' ', . , f, +and- --> maybe more?

	// try catch box for invalid arguments, no need for custom exceptions. Can just write ther right message in the catch box.

	// static_cast<to_what_type>(from_object);

	// multiple functions for each: char, int, float, double?
	// one big 
	
	switch(typeIdentifier(input))
	{
		case 1:
		{
			isChar(input);
			return ;
		}
		case 2:
		{
			isFloat(input);
			return ;
		}
		case 3:
		{
			isDouble(input);
			return ;
		}
		case 4:
		{
			isInt(input);
			return ;
		}
		case 5:
		{
			std::cout << "ERROR\n";
			return ;
		}
	}
}


	// try
	// {
	// 	int	convertedInt;
	// 	std::cout << "Trying string to int\n";
	// 	convertedInt = std::stoi(input);
	// 	std::cout << convertedInt << "\n";
	// }
	// catch(const std::invalid_argument& e)
	// {
	// 	std::cerr << "Impossible" << '\n';
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	float	convertedFloat;
	// 	std::cout << "Trying string to float\n";
	// 	convertedFloat = std::stof(input);
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << convertedFloat << "f\n";
	// }
	// catch(const std::invalid_argument& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	double	convertedDouble;
	// 	std::cout << "Trying string to double\n";
	// 	convertedDouble = std::stod(input);
	// 	std::cout << std::fixed << std::setprecision(1);
	// 	std::cout << convertedDouble << "\n";
	// }
	// catch(const std::invalid_argument& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	