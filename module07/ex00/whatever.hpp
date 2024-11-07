/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:06:03 by plang             #+#    #+#             */
/*   Updated: 2024/11/07 14:41:57 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

// swap  function template
template<typename T>
void	swap(T &argOne, T &argtTwo)
{
	T temp;
	temp = argOne;
	argOne = argtTwo;
	argtTwo = temp;
}

// min function template
template<typename T>
T	min(T argOne, T argtTwo)
{
	T min;
	min = (argOne < argtTwo) ? argOne : argtTwo;
	return min;
}

// max function template
template<typename T>
T	max(T argOne, T argtTwo)
{
	T max;
	max = (argOne > argtTwo) ? argOne : argtTwo;
	return max;
}

#endif