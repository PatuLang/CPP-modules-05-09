/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:15 by plang             #+#    #+#             */
/*   Updated: 2024/11/11 11:51:25 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	try
	{
		Array<std::string> two(6);
		std::string word[] = {"Hello", "from", "the", "other", "side"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(two.size()), sizeof(word)/sizeof(word[0])); i++)
			two[i] = word[i];
		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		Array<std::string> four;
		four = two;
		std::string morewords[] = {"What", "is", "your", "name"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(four.size()), sizeof(morewords)/sizeof(morewords[0])); i++)
			four[i] = morewords[i];
		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";

		two[4] = "world";
		std::cout << "\n";

		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<const char *> two(5);
		const char * word[] = {"Hello", "from", "the", "other", "side"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(two.size()), sizeof(word)/sizeof(word[0])); i++)
			two[i] = word[i];
		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		Array<const char *> four;
		four = two;
		const char * morewords[] = {"What", "is", "your", "name"};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(four.size()), sizeof(morewords)/sizeof(morewords[0])); i++)
			four[i] = morewords[i];
		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";

		two[4] = "world";
		std::cout << "\n";

		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<int> two(7);
		int numbers[] = {1, 2, 2147483647, 4, 5, 6, 7, 8, 40};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(two.size()), sizeof(numbers)/sizeof(numbers[0])); i++)
			two[i] = numbers[i];
		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		Array<int> four(two);
		int morenumbers[] = {100, 200, 300, 400, 500, 500, 600};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(four.size()), sizeof(morenumbers)/sizeof(morenumbers[0])); i++)
			four[i] = morenumbers[i];
		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";

		two[4] = 10;
		std::cout << "\n";

		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";
		std::cout << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Array<double> two(10);
		double numbers[] = {1.9, 2.9, 3.9, 4.9, 5.9, 6.9, 7.9};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(two.size()), sizeof(numbers)/sizeof(numbers[0])); i++)
			two[i] = numbers[i];
		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		Array<double> four(two);
		double morenumbers[] = {10.9, 20.9, 30.9, 40.9, 50.9, 60.9, 70.9};

		for (unsigned int i = 0; i < std::min(static_cast<unsigned long>(four.size()), sizeof(morenumbers)/sizeof(morenumbers[0])); i++)
			four[i] = morenumbers[i];
		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";

		two[4] = 10.95959;
		std::cout << "\n";

		for (unsigned int i = 0; i < two.size(); i++)
			std::cout << two[i] << "\n";
		std::cout << "\n";

		for (unsigned int i = 0; i < four.size(); i++)
			std::cout << four[i] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }
