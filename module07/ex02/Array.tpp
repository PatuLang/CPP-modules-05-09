/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:42:19 by plang             #+#    #+#             */
/*   Updated: 2025/03/03 13:33:35 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template<typename T>
Array<T>::Array() : arrPtr(nullptr), n(0)
{
}

template<typename T>
Array<T>::Array(unsigned int _n) : arrPtr(new T[_n]), n(_n)
{
	for (unsigned int i = 0; i < n; i++)
		arrPtr[i] = T();
}

template<typename T>
Array<T>::Array(const Array<T> &other) : arrPtr(new T[other.n]), n(other.n)
{
	for (unsigned int i = 0; i < other.n; i++)
		arrPtr[i] = other.arrPtr[i];
}

template<typename T>
Array<T>::~Array()
{
	delete[] arrPtr;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] arrPtr;
		n = other.n;
		arrPtr = new T[n];
		for (unsigned int i = 0; i < other.n; i++)
		{
			arrPtr[i] = other.arrPtr[i];
		}
	}
	return *this;
}

template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= n)
		throw std::out_of_range("We are not inside the array with this index!");
	return arrPtr[index];
}

template<typename T>
T& Array<T>::operator[](unsigned int index) const
{
	if (index >= n)
		throw std::out_of_range("We are not inside the array with this index!");
	return arrPtr[index];
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return n;
}
