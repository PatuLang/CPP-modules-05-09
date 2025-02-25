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
	std::stack<int>		result;

	while (getline(rpn, token, ' '))
	{
		if (!token.empty())
		{
			if (validChars.contains(token))
				result.push(std::stoi(token));
			else if (validOps.contains(token))
			{
				if (result.size() < 2)
				{
					throw std::runtime_error("Error: not enough elements in the container to do operation");
				}
				int	pop1 = result.top();
				result.pop();
				int	pop2 = result.top();
				result.pop();
				
				switch (identifyOperator(token))
				{
					case PLUS:
					{
						result.push(checkOverflow(pop2, pop1, PLUS));
						break;
					}
					case MINUS:
					{
						result.push(checkOverflow(pop2, pop1, MINUS));
						break;
					}
					case MULTIPLICATION:
					{
						result.push(checkOverflow(pop2, pop1, MULTIPLICATION));
						break;
					}
					case DIVISION:
					{
						result.push(checkOverflow(pop2, pop1, DIVISION));
						break;
					}
					default:
						break;
				}
			}
		}
	}
	if (result.size() == 0 || result.size() > 1)
		throw std::runtime_error("Error: RPN not valid, container has more or less then one element by the end");
	std::cout << result.top() << std::endl;
}

void	RPN::checkInput()
{
	int numbers = 0;
	int operations = 0;

	if (validOps.contains(m_input.top()) == false)
		throw std::runtime_error("Error: last character is not an operator");

	while (!m_input.empty())
	{
		std::string	token = m_input.top();
		m_input.pop();
		if (token.size() != 1)
			throw std::runtime_error("Error: string token to long");
		if (validChars.contains(token) || validOps.contains(token))
		{
			if (validChars.contains(token))
				numbers++;
			if (validOps.contains(token))
				operations++;
		}
		else
			throw std::runtime_error("Error: unauthorized character found");
	}
	if ((operations + 1) != numbers)
		throw std::runtime_error("Error: not the right amount of numbers and operators to do the calculation");
}

std::stack<std::string>	RPN::splitRPN(std::string line)
{
	std::stack<std::string>		tokens;
	std::string					token;
	char						delim = ' ';
	std::stringstream			stream(line);

	while (getline(stream, token, delim))
	{
		if (!token.empty())
			tokens.push(token);
	}
	return tokens;
}