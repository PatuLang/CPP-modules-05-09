/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:46 by plang             #+#    #+#             */
/*   Updated: 2024/11/05 11:15:47 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void)
{
	Data 		*pointer = nullptr;
	uintptr_t	serializedPtr = 0;;
	pointer = new Data;

	std::cout << "Original: " << pointer << "\n";
	serializedPtr = Serializer::serialize(pointer);
	std::cout << "Serialized: " << serializedPtr << "\n";
	pointer = Serializer::deserialize(serializedPtr);
	std::cout << "Deserialized: " << pointer << "\n";
	
	delete pointer;
	return 0;
}
