/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:23 by plang             #+#    #+#             */
/*   Updated: 2025/01/28 15:59:38 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(char *inputString)
{
	std::string				args(inputString);
	m_input = splitRPN(args);
	checkInput();
	calculateInput(args);
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

const RPN &	RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		m_input = other.m_input;
		validChars = other.validChars;
		validOps = other.validOps;
	}
	return *this;
}

RPN::~RPN()
{
}

operators	RPN::identifyOperator(std::string whatOperator)
{
    if (whatOperator[0] == '+')
		return PLUS;
    if (whatOperator[0] == '-')
		return MINUS;
    if (whatOperator[0] == '*')
		return MULTIPLICATION;
    if (whatOperator[0] == '/')
		return DIVISION;
	throw std::runtime_error("Error: could not identify operator");
}

int	RPN::checkOverflow(int pop2, int pop1, operators op)
{
	int	result = 0;
	switch (op)
	{
		case PLUS:
		{
			if ((pop1 > 0 && pop2 > (INT_MAX - pop1)) || (pop1 < 0 && pop2 < (INT_MIN - pop1)))
				throw std::runtime_error("Error: integer overflow");
			result = pop2 + pop1;
			break;
		}
		case MINUS:
		{
			if ((pop1 < 0 && pop2 > (INT_MAX + pop1)) || (pop1 > 0 && pop2 < (INT_MIN + pop1)))
				throw std::runtime_error("Error: integer overflow");
			result = pop2 - pop1;
			break;
		}
		case MULTIPLICATION:
		{
			if (pop1 != 0 && (pop2 > (INT_MAX / pop1) || pop2 < (INT_MIN / pop1)))
				throw std::runtime_error("Error: integer overflow");
			result = pop2 * pop1;
			break;
		}
		case DIVISION:
		{
			if (pop1 == 0)
				throw std::runtime_error("Error: division by zero");
			if (pop2 == INT_MIN && pop1 == -1)
				throw std::runtime_error("Error: integer overflow");
			result = pop2 / pop1;
			break;
		}
	}
	return result;
}

void	RPN::calculateInput(std::string inputString)
{
	std::stringstream	rpn(inputString);
	std::string			token;
	std::deque<int>		result;

	while (getline(rpn, token, ' '))
	{
		if (!token.empty())
		{
			if (validChars.contains(token))
				result.push_back(std::stoi(token));
			else if (validOps.contains(token))
			{
				if (result.size() < 2)
				{
					throw std::runtime_error("Error: not enough elements in the container to do operation");
				}
				int	pop1 = result.back();
				result.pop_back();
				int	pop2 = result.back();
				result.pop_back();
				
				switch (identifyOperator(token))
				{
					case PLUS:
					{
						result.push_back(checkOverflow(pop2, pop1, PLUS));
						break;
					}
					case MINUS:
					{
						result.push_back(checkOverflow(pop2, pop1, MINUS));
						break;
					}
					case MULTIPLICATION:
					{
						result.push_back(checkOverflow(pop2, pop1, MULTIPLICATION));
						break;
					}
					case DIVISION:
					{
						std::cout << pop1 << " divi " << pop2 << std::endl;
						result.push_back(checkOverflow(pop2, pop1, DIVISION));
						break;
					}
					default:
						break;
				}
			}
		}
	}
	if (result.size() == 0 || result.size() > 1)
		throw std::runtime_error("Error: RPN not valid, container has more then one element");
	std::cout << result.at(0) << std::endl;
}

void	RPN::checkInput()
{
	int numbers = 0;
	int operations = 0;

	for (auto iter = m_input.begin(); iter != m_input.end(); iter++)
	{
		if (iter->size() != 1)
			throw std::runtime_error("Error: string token to long");
		if (validChars.contains(*iter) || validOps.contains(*iter))
		{
			if (validChars.contains(*iter))
				numbers++;
			if (validOps.contains(*iter))
				operations++;
		}
		else
			throw std::runtime_error("Error: unauthorized character found");
	}
	if ((operations + 1) != numbers)
		throw std::runtime_error("Error: not the right amount of numbers and operators to do the calculation");
	if (validOps.contains(m_input.back()) == false)
		throw std::runtime_error("Error: last character is not an operator");
}

std::deque<std::string>	RPN::splitRPN(std::string line)
{
	std::deque<std::string>		tokens;
	std::string					token;
	char						delim = ' ';
	std::stringstream			stream(line);

	while (getline(stream, token, delim))
	{
		if (!token.empty())
			tokens.push_back(token);
	}
	return tokens;
}
