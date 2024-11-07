/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:59:18 by plang             #+#    #+#             */
/*   Updated: 2024/11/07 18:17:10 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{
	private:
		T		*arrPtr;
		size_t	n;
	public:
		Array();
		Array(size_t);
		Array(const Array<T>&);
		Array& operator=(const Array<T>&);
		~Array();

};

template<typename T>
Array<T>::Array()
{

}

template<typename T>
Array<T>::Array(size_t _n)
{
	
}

template<typename T>
Array<T>::Array(const Array<T> &other)
{

}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	
}

template<typename T>
Array<T>::~Array()
{

}

#endif