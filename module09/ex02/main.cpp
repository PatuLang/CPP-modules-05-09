/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:29 by plang             #+#    #+#             */
/*   Updated: 2025/02/25 15:01:34 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Argument count is invalid" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe obj(argc, argv);
		obj.isItSorted();

		/* VECTOR */
		obj.startVec();

		std::cout << "Before: ";
		obj.vecPrintTruncated();
		// obj.vecPrint();
		
		obj.vecSort(obj.getVector());

		std::cout << "After: ";
		obj.vecPrintTruncated();
		// obj.vecPrint();


		/* DEQUE */

		obj.startDeq();

		std::cout << "Before: ";
		obj.deqPrintTruncated();
		// obj.deqPrint();
		
		obj.deqSort(obj.getDeque());
		
		std::cout << "After: ";
		obj.deqPrintTruncated();
		// obj.deqPrint();

		/* RESULT */

		obj.elapsedTimePrint();
		obj.isItSorted();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << "Exiting after error occurred" << std::endl;
	}
	return 0;
}
