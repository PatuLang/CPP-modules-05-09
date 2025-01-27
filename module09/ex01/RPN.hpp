/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:26 by plang             #+#    #+#             */
/*   Updated: 2025/01/27 18:02:00 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <deque>
# include <string>

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
		std::deque<std::string>	m_input;
		std::string				validChars = "0123456789";
		std::string				validOps = "+-*/";
		
		RPN(const RPN &);
		const RPN &	operator=(const RPN &);
		RPN();

	public:
		RPN(char *argv);
		~RPN();

		std::deque<std::string>	splitRPN(std::string);
		void					checkInput();
		void					calculateInput(std::string);
		operators				identifyOperator(std::string);
};

#endif