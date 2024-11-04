/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:52 by plang             #+#    #+#             */
/*   Updated: 2024/11/04 15:37:21 by plang            ###   ########.fr       */
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

	}
	
	Data*	Serializer::deserialize(uintptr_t raw)
	{
		
	}