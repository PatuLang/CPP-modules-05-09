/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:16:36 by plang             #+#    #+#             */
/*   Updated: 2024/11/12 17:16:05 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int			arrSize;
	int 		intArray[] = {1, 2, 3, 4, 5};
	std::string	strArray[] = {"Hello", "world", "dlrow", "olleH"};
	char		charArray[] = {'a', 'b', 'c', 'd'};
	const int 	cintArray[] = {10, 20, 30, 40, 50};

	arrSize = sizeof(intArray) / sizeof(intArray[0]);
	::iter(intArray, arrSize, ::printArray<int>);
	std::cout << "\n";

	arrSize = sizeof(strArray) / sizeof(strArray[0]);
	::iter(strArray, arrSize, ::printArray<std::string>);
	std::cout << "\n";
	
	arrSize = sizeof(charArray) / sizeof(charArray[0]);
	::iter(charArray, arrSize, ::printArray<char>);
	std::cout << "\n";
	
	arrSize = sizeof(cintArray) / sizeof(cintArray[0]);
	::iter(cintArray, arrSize, ::printArray<const int>);
	std::cout << "\n";

	return 0;
}
