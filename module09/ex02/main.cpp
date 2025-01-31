/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:29 by plang             #+#    #+#             */
/*   Updated: 2025/01/31 17:46:02 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Error: Argument count is invalid" << std::endl;
		return 1;
	}
	try
	{
		PmergeMe obj(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exiting after error occurred" << std::endl;
	}
	return 0;
}
