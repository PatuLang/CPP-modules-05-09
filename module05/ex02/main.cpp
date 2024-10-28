/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:40 by plang             #+#    #+#             */
/*   Updated: 2024/10/28 15:01:30 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int	main(void)
{
	try
	{
		Bureaucrat Bob("Bob", 1);
		Bureaucrat Tom("Tom", 2);
		Bureaucrat Dom(Tom);
		std::cout << Dom << '\n';
		PresidentialPardonForm one("Sauli");
		RobotomyRequestForm two("Rob_robot");
		ShrubberyCreationForm three("City_park");
		std::cout << one << "\n";
		std::cout << two << "\n";
		std::cout << three << "\n";
		Tom.signForm(one);
		Bob.executeForm(one);
		Tom.signForm(two);
		Bob.executeForm(two);
		Tom.signForm(three);
		Bob.executeForm(three);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
