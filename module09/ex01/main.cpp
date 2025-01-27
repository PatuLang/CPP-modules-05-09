/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:11:20 by plang             #+#    #+#             */
/*   Updated: 2025/01/27 18:28:13 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// <stack>
#include "RPN.hpp"

int	main (int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: argument mising, supply one string of a reverse polish notation" << std::endl;
		return 1;
	}
	else if (argc == 2)
	{
		try
		{
			RPN test(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			return 1;
		}
	}
	else
	{
		std::cerr << "Error: too many arguments, supply one string of a reverse polish notation" << std::endl;
		return 1;
	}
	return 0;
}
