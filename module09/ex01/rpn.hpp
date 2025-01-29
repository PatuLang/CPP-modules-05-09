
#ifndef RP_HPP
# define RP_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <limits.h>

enum operators
{
	PLUS = 43,
	MINUS = 45,
	MULTIPLICATION = 42,
	DIVISION = 47
};

class RPN
{
	private:
		std::stack<std::string>	m_input;
		std::string				validChars = "0123456789";
		std::string				validOps = "+-*/";
		
		RPN(const RPN &);
		const RPN &	operator=(const RPN &);
		RPN();

	public:
		RPN(char *argv);
		~RPN();

		std::stack<std::string>	splitRPN(std::string);
		void					checkInput();
		int						checkOverflow(int, int, operators);
		void					calculateInput(std::string);
		operators				identifyOperator(std::string);
};

#endif