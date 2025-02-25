/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:40 by plang             #+#    #+#             */
/*   Updated: 2025/02/25 14:10:09 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat tom;	
		std::cout << tom << "\n";

		Bureaucrat jac("jac", 150);	
		std::cout << jac << "\n";
		jac.incrementGrade();
		std::cout << jac << "\n";
		
		Bureaucrat bob("bob", 1);	
		std::cout << bob << "\n";
		bob.decrementGrade();
		std::cout << bob << "\n";

		Bureaucrat dom("dom", -1);	
		std::cout << dom << "\n";
		dom.decrementGrade();
		std::cout << dom << "\n";

		Bureaucrat bill("bill", 151);	
		std::cout << bill << "\n";
		bill.decrementGrade();
		std::cout << bill << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
