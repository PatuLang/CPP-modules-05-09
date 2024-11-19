/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:54:20 by plang             #+#    #+#             */
/*   Updated: 2024/11/19 10:36:26 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


int	main(void)
{
	{
		MutantStack<int> 			intStack, copyStack;

		for (int i = 0; i < 25; i+=3)
			intStack.push(i);

		copyStack = intStack;
		std::cout << "\nInt stack ------------" << std::endl;
		while (!intStack.empty())
		{
			std::cout << intStack.top() << std::endl;
			intStack.pop();
		}
		MutantStack<int>	otherStack(copyStack);
		MutantStack<int>::iterator it = otherStack.begin();
		MutantStack<int>::iterator ite = otherStack.end();
		std::cout << "\nOther stack ------------" << std::endl;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}
		std::cout << "\nCopy stack ------------" << std::endl;
		for(auto index = copyStack.begin(); index != copyStack.end(); ++index)
			std::cout << *index << std::endl;

		// MutantStack<int>::const_iterator const_ite = copyStack.begin();
		// *const_ite = 99;
	}
	{
		MutantStack<std::string>	stringStack, swapStack;

		stringStack.push("It's ");
		stringStack.push("long ");
		stringStack.push("way ");
		stringStack.push("to ");
		stringStack.push("the ");
		stringStack.push("top ");
		stringStack.push("if ");
		stringStack.push("you ");
		stringStack.push("want ");
		stringStack.push("to ");
		stringStack.push("rock n roll");

		swapStack.push("only one string");

		std::cout << "\nString stack ------------" << std::endl;
		for (auto iter = stringStack.begin(); iter != stringStack.end(); ++iter)
			std::cout << *iter << std::endl;
			
		std::cout << "\nSwap stack ------------" << std::endl;
		for (auto iter = swapStack.begin(); iter != swapStack.end(); ++iter)
			std::cout << *iter << std::endl;
			
		swapStack.swap(stringStack);
		std::cout << "\nString stack after swap ------------" << std::endl;
		for (auto iter = stringStack.begin(); iter != stringStack.end(); ++iter)
			std::cout << *iter << std::endl;

		std::cout << "\nSwap stack after swap ------------" << std::endl;
		for (auto iter = swapStack.begin(); iter != swapStack.end(); ++iter)
			std::cout << *iter << std::endl;
	}
}
