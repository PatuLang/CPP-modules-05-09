/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:52 by plang             #+#    #+#             */
/*   Updated: 2024/11/05 11:07:29 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

	Serializer::Serializer()
	{
	}

	Serializer::Serializer(const Serializer&)
	{
	}

	Serializer& Serializer::operator=(const Serializer &other)
	{
		(void)other;
		return *this;
	}

	Serializer::~Serializer()
	{
	}

	uintptr_t	Serializer::serialize(Data* ptr)
	{
		if (ptr == nullptr)
			return 0;
		uintptr_t	serializedPtr = 0;
		serializedPtr = reinterpret_cast<uintptr_t>(ptr);
		return serializedPtr;
	}
	
	Data*	Serializer::deserialize(uintptr_t raw)
	{
		if (raw == 0)
			return nullptr;
		Data *ptr = nullptr;
		ptr = reinterpret_cast<Data*>(raw);
		return ptr;
	}
	