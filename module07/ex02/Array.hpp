/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:18 by plang             #+#    #+#             */
/*   Updated: 2024/11/08 14:57:43 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private:
		T				*arrPtr;
		unsigned int	n;
	public:
		Array();
		Array(unsigned int);
		Array(const Array<T>&);
		Array<T>& operator=(const Array<T>&);
		~Array();

		T& operator[](unsigned int);
		T& operator[](unsigned int) const;
		unsigned int size() const;
};

# include "Array.tpp"
#endif
