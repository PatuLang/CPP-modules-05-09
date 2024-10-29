/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:40 by plang             #+#    #+#             */
/*   Updated: 2024/10/29 09:29:19 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"


int	main(void)
{
	AForm* rrf;
	AForm* ppf;
	AForm* scf;
	// AForm* nothing;
	try
	{
		Intern randomIntern;
		
		rrf = randomIntern.makeForm("Robotomy request", "Eemil");
		ppf = randomIntern.makeForm("Presidential pardon", "Arthur");
		scf = randomIntern.makeForm("Shrubbery creation", "City park");
		// nothing = randomIntern.makeForm("This doesn't exist", "No");

		Bureaucrat Bob("Bob", 1);
		Bureaucrat Tom("Tom", 2);

		std::cout << *rrf << "\n";
		std::cout << *ppf << "\n";
		std::cout << *scf << "\n";

		Tom.signForm(*rrf);
		Bob.executeForm(*rrf);
		Tom.signForm(*ppf);
		Bob.executeForm(*ppf);
		Tom.signForm(*scf);
		Bob.executeForm(*scf);

		delete rrf;
		delete ppf;
		delete scf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		
		delete rrf;
		delete ppf;
		delete scf;
	}
	return 0;
}
