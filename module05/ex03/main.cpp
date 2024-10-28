/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:40 by plang             #+#    #+#             */
/*   Updated: 2024/10/28 18:43:26 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int	main(void)
{
	try
	{
		Intern randomIntern;
		AForm* rrf;
		rrf = randomIntern.makeForm("Robotomy request", "Eemil");
		Bureaucrat Bob("Bob", 1);
		Bureaucrat Tom("Tom", 2);
		Bureaucrat Dom(Tom);
		std::cout << Dom << '\n';
		PresidentialPardonForm one("Sauli");
		// RobotomyRequestForm two("Rob_robot");
		ShrubberyCreationForm three("City_park");
		std::cout << one << "\n";
		std::cout << rrf << "\n";
		std::cout << three << "\n";
		Tom.signForm(one);
		Bob.executeForm(one);
		Tom.signForm(*rrf);
		Bob.executeForm(*rrf);
		Tom.signForm(three);
		Bob.executeForm(three);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
