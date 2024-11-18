/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:54:20 by plang             #+#    #+#             */
/*   Updated: 2024/11/18 15:54:23 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


int	main(void)
{
	MutantStack<int> 			intStack, copyStack;

	for (int i = 0; i < 25; i+=3)
		intStack.push(i);

	copyStack = intStack;

	MutantStack<int>::iterator it = intStack.begin();
	MutantStack<int>::iterator ite = intStack.end();
	// while (it != ite)
	// {
	// 	std::cout << intStack.top() << std::endl;
	// 	intStack.pop();
	// } // shared memory??? segfaults on next loop if we .pop()
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	// const_iterator, try to assign to show the const feature
	for(auto index = copyStack.begin(); index != copyStack.end(); ++index)
		std::cout << *index << std::endl;

	MutantStack<std::string>	stringStack;
	MutantStack<const char *>	cStringStack;
}

// int main()
// {
// 	MutantStack<int> mstack, teststack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << "Top: " << mstack.top() << std::endl;

// 	std::cout << "Popped last pushed(top) object" << std::endl;
// 	mstack.pop();

// 	std::cout << "Size: " << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(15);
// 	mstack.push(25);
// 	mstack.push(35);
// 	mstack.push(54);
// 	mstack.push(57);
// 	mstack.push(737);


// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	// *it = 99;

// // 	++it;
// // 	--it;

// 	std::cout << "While loop about to happen" << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}

// 	teststack = mstack;
// 	std::stack<int> s(mstack);

// 	std::cout << std::endl;
// 	for (auto in = teststack.begin(); in != teststack.end(); in++)
// 	{
// 		std::cout << *in << std::endl;
// 	}
// 	std::cout << std::endl;
// 	// mstack.top();
// 	// mstack.emplace();
// 	// mstack.empty();
// 	// mstack.pop();
// 	// mstack.size();
// 	// mstack.swap(s);
// 	// mstack.c.
// 	// s.c.

// 	while (!s.empty())
// 	{
// 		std::cout << "Top: " << s.top() << std::endl;
// 		s.pop();
// 	}

// 	return 0;
// }

// #include <list>
// int main()
// {
// 	std::list<int> mstack;

// 	mstack.push_back(5);
// 	mstack.push_back(17);

// 	std::cout << "Top: " << mstack.back() << std::endl;

// 	std::cout << "Popped last pushed(top) object" << std::endl;
// 	mstack.pop_back();

// 	std::cout << "Size: " << mstack.size() << std::endl;

// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(15);
// 	mstack.push_back(25);
// 	mstack.push_back(35);
// 	mstack.push_back(54);
// 	mstack.push_back(57);
// 	mstack.push_back(737);

// 	mstack.push_back(0);

// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();

// 	// ++it;
// 	// --it;

// 	std::cout << "While loop about to happen" << std::endl;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}

// 	std::list<int> s(mstack);
// 	while (!s.empty())
// 	{
// 		std::cout << "Top: " << s.back() << std::endl;
// 		s.pop_back();
// 	}

// 	return 0;
// }
