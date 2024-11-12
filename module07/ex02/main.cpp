/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:15 by plang             #+#    #+#             */
/*   Updated: 2024/11/12 17:20:35 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	try
	{
		Array<std::string> xArrObj(6);
		std::string word[] = {"Hello", "from", "the", "other", "side"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(xArrObj.size()), sizeof(word)/sizeof(word[0])); i++)
			xArrObj[i] = word[i];
		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		Array<std::string> yArrObj;
		yArrObj = xArrObj;
		std::string morewords[] = {"What", "is", "your", "name"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(yArrObj.size()), sizeof(morewords)/sizeof(morewords[0])); i++)
			yArrObj[i] = morewords[i];
		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";

		xArrObj[4] = "world";
		std::cout << "\n";

		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<const char *> xArrObj(5);
		const char * word[] = {"Hello", "from", "the", "other", "side"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(xArrObj.size()), sizeof(word)/sizeof(word[0])); i++)
			xArrObj[i] = word[i];
		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		Array<const char *> yArrObj;
		yArrObj = xArrObj;
		const char * morewords[] = {"What", "is", "your", "name"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(yArrObj.size()), sizeof(morewords)/sizeof(morewords[0])); i++)
			yArrObj[i] = morewords[i];
		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";

		xArrObj[4] = "world";
		std::cout << "\n";

		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<int> xArrObj(7);
		int numbers[] = {1, 2, 2147483647, 4, 5, 6, 7, 8, 40};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(xArrObj.size()), sizeof(numbers)/sizeof(numbers[0])); i++)
			xArrObj[i] = numbers[i];
		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		Array<int> yArrObj(xArrObj);
		int morenumbers[] = {100, 200, 300, 400, 500, 500, 600};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(yArrObj.size()), sizeof(morenumbers)/sizeof(morenumbers[0])); i++)
			yArrObj[i] = morenumbers[i];
		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";

		xArrObj[4] = 10;
		std::cout << "\n";

		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<double> xArrObj(10);
		double numbers[] = {1.9, 2.9, 3.9, 4.9, 5.9, 6.9, 7.9};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(xArrObj.size()), sizeof(numbers)/sizeof(numbers[0])); i++)
			xArrObj[i] = numbers[i];
		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		Array<double> yArrObj(xArrObj);
		double morenumbers[] = {10.9, 20.9, 30.9, 40.9, 50.9, 60.9, 70.9};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(yArrObj.size()), sizeof(morenumbers)/sizeof(morenumbers[0])); i++)
			yArrObj[i] = morenumbers[i];
		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";

		xArrObj[4] = 10.95959;
		std::cout << "\n";

		for (unsigned int i = 0; i < xArrObj.size(); i++)
			std::cout << xArrObj[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < yArrObj.size(); i++)
			std::cout << yArrObj[i] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
