/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plang <plang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:05:40 by plang             #+#    #+#             */
/*   Updated: 2024/10/24 18:20:38 by plang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

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
		FPA.signForm(bob);
		FPA.beSigned(jac);
		FPA.signForm(jac);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
