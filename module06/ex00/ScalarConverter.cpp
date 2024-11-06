/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:23:51 by plang             #+#    #+#             */
/*   Updated: 2024/11/06 12:13:41 by plang            ###   ########.fr       */
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
	for (unsigned long i = 0; i < input.size(); i++)
	{
		if ((input[0] == '-' || input[0] == '+') && (input.back() != '-' || input.back() != '+')  && i == 0)
			i++;
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
			return false;
	}
	return true;
}

bool	isOnlyF(std::string input)
{
	for (unsigned long i = 0; i < input.size(); i++)
	{
		if ((input[0] == '-' || input[0] == '+') && (input.back() != '-' || input.back() != '+') && i == 0)
			i++;
		if (!std::isdigit(static_cast<unsigned char>(input[i])) && input[i] != 'f' && input[i] != '.')
			return false;
	}
	if (input.find('.') != std::string::npos)
	{
		if (input.rfind('.') != input.find('.'))
			return false;
	}
	return true;
}

bool	isOnlyDot(std::string input)
{
	for (unsigned long i = 0; i < input.size(); i++)
	{
		if ((input[0] == '-' || input[0] == '+') && (input.back() != '-' || input.back() != '+') && i == 0)
			i++;
		if (!std::isdigit(static_cast<unsigned char>(input[i])) && input[i] != '.')
			return false;
	}
	return true;
}

int	typeIdentifier(std::string input)
{
	if (input.empty())
		return 5;
	if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
		return 3;
	if (input == "nanf" || input == "-inff" || input == "+inff" || input == "inff")
		return 2;
	if (input[0] == '\'' && (std::isalpha(static_cast<unsigned char>(input[1])) || std::isprint(static_cast<unsigned char>(input[1]))) && input[2] == '\'')
		return 1;
	else if (input.back() == 'f' && (input.size() - 1) == input.find('f') && input.rfind('f') == input.find('f') && isOnlyF(input) == true)
		return 2;
	else if (input.find('.') != std::string::npos && input.rfind('.') == input.find('.') && input.find('f') == std::string::npos && isOnlyDot(input) == true)
		return 3;
	else if ((((input[0] == '-' || input[0] == '+') && input.length() > 1) && isOnlyNumbers(input) == true) || isOnlyNumbers(input) == true)
		return 4;
	else
		return 5;
}

void	isChar(std::string input)
{
	std::cout << "Char\n";
	try
	{
		char	convertChar;
		convertChar = static_cast<char>(input[1]);
		std::cout << std::fixed << std::setprecision(1) << "char: '" << static_cast<char>(convertChar) << "'\n" << "int: " << static_cast<int>(convertChar) << "\n" << "float: " << static_cast<float>(convertChar) << "f\n" << "double: " << static_cast<double>(convertChar) << "\n";
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	isInt(std::string input)
{
	std::cout << "Int\n";
	int	convertInt;
	try
	{
		convertInt = std::stoi(input);
		if (std::isprint(static_cast<unsigned char>(convertInt)) == false)
			std::cout << std::fixed << std::setprecision(1) << "char: Non displayable\n" << "int: " << static_cast<int>(convertInt) << "\n" << "float: " << static_cast<float>(convertInt) << "f\n" << "double: " << static_cast<double>(convertInt) << "\n";
		else
			std::cout << std::fixed << std::setprecision(1) << "char: '" << static_cast<char>(convertInt) << "'\n" << "int: " << static_cast<int>(convertInt) << "\n" << "float: " << static_cast<float>(convertInt) << "f\n" << "double: " << static_cast<double>(convertInt) << "\n";
	}
	catch(const std::out_of_range& e)
	{
		std::cout << "char: Impossible\n" << "int: Impossible\n" << "float: Impossible\n" << "double: Impossible\n";
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	isFloat(std::string input)
{
	std::cout << "Float\n";
	try
	{
		float	convertFloat;
		convertFloat = std::stof(input);
		if (input == "nanf" || input == "-inff" || input == "+inff" || input == "inff")
			std::cout << std::fixed << "char: Impossible\n"  << "int: Impossible\n" << "float: " << static_cast<float>(convertFloat) << "f\n" << "double: " << static_cast<double>(convertFloat) << "\n";
		else if (((convertFloat < 32 || convertFloat > 127) || std::isprint(static_cast<unsigned char>(convertFloat)) == false) && (convertFloat < static_cast<float>(std::numeric_limits<int>::min()) || convertFloat > static_cast<float>(std::numeric_limits<int>::max())))
			std::cout << std::fixed << "char: Non displayable\n" << "int: Impossible\n" << "float: " << static_cast<float>(convertFloat) << "f\n" << "double: " << static_cast<double>(convertFloat) << "\n";
		else if ((convertFloat < 32 || convertFloat > 127) || std::isprint(static_cast<unsigned char>(convertFloat)) == false)
			std::cout << std::fixed << "char: Non displayable\n" << "int: " << static_cast<int>(convertFloat) << "\n" << "float: " << static_cast<float>(convertFloat) << "f\n" << "double: " << static_cast<double>(convertFloat) << "\n";
		else
			std::cout << std::fixed << "char: '" << static_cast<char>(convertFloat) << "'\n" << "int: " << static_cast<int>(convertFloat) << "\n" << "float: " << static_cast<float>(convertFloat) << "f\n" << "double: " << static_cast<double>(convertFloat) << "\n";
	}
	catch(const std::out_of_range& e)
	{
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	isDouble(std::string input)
{
	std::cout << "Double\n";
	try
	{
		double	convertDouble;
		convertDouble = std::stod(input);
		if (input == "nan" || input == "-inf" || input == "+inf" || input == "inf")
			std::cout << std::fixed << "char: Impossible\n"  << "int: Impossible\n" << "float: " << static_cast<float>(convertDouble) << "f\n" << "double: " << static_cast<double>(convertDouble) << "\n";
		else if (((convertDouble < 32 || convertDouble > 127) || std::isprint(static_cast<unsigned char>(convertDouble)) == false) && (convertDouble < std::numeric_limits<int>::min() || convertDouble > std::numeric_limits<int>::max()))
			std::cout << std::fixed << "char: Non displayable\n" << "int: Impossible\n" << "float: " << static_cast<float>(convertDouble) << "f\n" << "double: " << static_cast<double>(convertDouble) << "\n";
		else if ((convertDouble < 32 || convertDouble > 127) || std::isprint(static_cast<unsigned char>(convertDouble)) == false)
			std::cout << std::fixed << "char: Non displayable\n" << "int: " << static_cast<int>(convertDouble) << "\n" << "float: " << static_cast<float>(convertDouble) << "f\n" << "double: " << static_cast<double>(convertDouble) << "\n";
		else
			std::cout << std::fixed << "char: '" << static_cast<char>(convertDouble) << "'\n" << "int: " << static_cast<int>(convertDouble) << "\n" << "float: " << static_cast<float>(convertDouble) << "f\n" << "double: " << static_cast<double>(convertDouble) << "\n";
	}
	catch(const std::out_of_range& e)
	{
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	ScalarConverter::convert(std::string input)
{	
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
	