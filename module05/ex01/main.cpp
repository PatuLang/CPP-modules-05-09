/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:40 by plang             #+#    #+#             */
/*   Updated: 2024/10/25 11:19:16 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	jac("jac", 150);
		Bureaucrat	bob("bob", 1);
		std::cout << jac << "\n";
		std::cout << bob << "\n";

		Form	FPA("studentBenefits", 1, 1);
		std::cout << FPA << "\n";
		FPA.beSigned(bob);
		bob.signForm(FPA);
		FPA.beSigned(jac);
		jac.signForm(FPA);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
