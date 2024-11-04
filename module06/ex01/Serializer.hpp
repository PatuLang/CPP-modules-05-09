/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:57 by plang             #+#    #+#             */
/*   Updated: 2024/11/04 15:30:36 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define sERIALIZER_HPP

# include <iostream>
# include <cstdint>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer&);
	public:
		Serializer& operator=(const Serializer&);
		~Serializer();

		uintptr_t	serialize(Data* ptr);
		Data* 		deserialize(uintptr_t raw);
};

#endif