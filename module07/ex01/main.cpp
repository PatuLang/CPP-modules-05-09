/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:16:36 by plang             #+#    #+#             */
/*   Updated: 2024/11/07 16:00:58 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main(void)
{
	int			arrSize;
	int 		intArray[] = {1, 2, 3, 4, 5};
	const char 	*strArray[] = {"Hello", "world", "dlrow", "olleH"};
	char		charArray[] = {'a', 'b', 'c', 'd'};

	arrSize = sizeof(intArray) / sizeof(intArray[0]);
	::iter(intArray, arrSize, ::printArray<int>);
	std::cout << "\n";

	arrSize = sizeof(strArray) / sizeof(strArray[0]);
	::iter(strArray, arrSize, ::printArray<const char*>);
	std::cout << "\n";
	
	arrSize = sizeof(charArray) / sizeof(charArray[0]);
	::iter(charArray, arrSize, ::printArray<char>);
	std::cout << "\n";

	return 0;
}
