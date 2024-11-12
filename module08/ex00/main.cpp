/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:54:52 by plang             #+#    #+#             */
/*   Updated: 2024/11/12 16:50:19 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	try
	{
		std::cout << "std::vector ----->\n";

		std::vector<int>container;
		for (int i = 0; i < 100; i++)
			container.push_back(i);
		easyfind(container, 101);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nstd::list ----->\n";

		std::list<int>container;
		for (int i = 0; i < 100; i++)
			container.push_back(i);
		easyfind(container, 33);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "\nstd::deque ----->\n";

		std::deque<int>container;
		for (int i = 0; i < 100; i++)
			container.push_back(i);
		easyfind(container, 69);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
