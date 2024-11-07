/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:49:37 by plang             #+#    #+#             */
/*   Updated: 2024/11/07 16:01:23 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	printArray(T arrayContent)
{
	std::cout << arrayContent << " ";
}

template<typename T1, typename T2, typename T3>
void	iter(T1 *array, T2 n, T3 function)
{
	for (int i = 0; i < n; i++)
		function(array[i]);
}

#endif
