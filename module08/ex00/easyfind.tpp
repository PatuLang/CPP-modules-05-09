/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:55:24 by plang             #+#    #+#             */
/*   Updated: 2024/11/13 17:32:46 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<typename T>
void	easyfind(T container, int element)
{
	auto it = std::find(container.begin(), container.end(), element);
	if (it != container.end())
		std::cout << "Found the requested element: " << element << "\n";
	else
		throw std::runtime_error("Requested element was not found");
}
